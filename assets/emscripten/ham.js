// ----------------------------------------------------------------------------
// General functionality
window.onerror = function(event) {
	var status = document.getElementById('status');
	if (status) {
		status.innerText = "Error! See browser console.";
	}
};

var HamSandwich = (function () {
	var metadata = JSON.parse(document.getElementById('ham-meta').textContent);

	// ------------------------------------------------------------
	// File system syncing
	var FS_IDLE = 0, FS_WORKING = 1, FS_PENDING = 2;
	var fsStatus = FS_WORKING;  // waiting for preInit to run

	function fsCallback(err) {
		if (err) {
			Module.printErr('FS sync error:', err);
		}
		if (fsStatus == FS_PENDING) {
			fsSyncInner();
		} else {
			fsStatus = FS_IDLE;
			Module.setStatus("");
		}
	}

	function fsSyncInner() {
		fsStatus = FS_WORKING;
		Module.setStatus("Saving...");
		FS.syncfs(false, fsCallback);
	}

	function fsSync() {
		if (fsStatus) {
			fsStatus = FS_PENDING;
		} else {
			fsSyncInner();
		}
	}

	function fsInitCallback(err) {
		fsCallback(err);
		InstallerUpload.onFsInit();
	}

	function fsInit() {
		FS.mkdir('/appdata');
		FS.mount(IDBFS, {}, '/appdata');
		FS.mkdir('/installers');
		FS.mount(IDBFS, {}, '/installers');
		FS.syncfs(true, fsInitCallback);
	}

	// ------------------------------------------------------------
	// Module overrides
	function setWindowTitle(text) {
		document.title = text;
		document.getElementById('title').hidden = !text;
		document.getElementById('title').innerText = text;
	}

	return {
		metadata,
		fsSync,
		fsInit,
		setWindowTitle,
	};
})();

// ----------------------------------------------------------------------------
// Installer upload
var InstallerUpload = (function () {
	var details = document.getElementById('installer-upload');
	var table = details.querySelector('table');
	var meta = HamSandwich.metadata.installers;

	function setSpinner(td) {
		var outer = document.createElement('div');
		outer.className = 'spinner';
		var inner = document.createElement('div');
		inner.className = 'loading-pulse';
		outer.appendChild(inner);
		td.innerText = '';
		td.appendChild(outer);
	}

	var status = {};
	details.hidden = true;
	for (let fname in meta) {
		details.hidden = false;

		let statusTd = document.createElement('td');
		setSpinner(statusTd);

		var fnameTd = document.createElement('td');
		var a = document.createElement('a');
		a.href = meta[fname].link;
		a.innerText = fname;
		a.target = '_blank';
		fnameTd.appendChild(a);

		var fileTd = document.createElement('td');
		let fileInput = document.createElement('input');
		fileInput.type = 'file';
		fileInput.addEventListener('change', () => {
			setSpinner(statusTd);
			fileInput.files[0].arrayBuffer().then(buf => {
				FS.writeFile('/installers/' + fname, new Uint8Array(buf));
				checkFsFile(fname, true);
			});
		});
		fileTd.appendChild(fileInput);

		var tr = document.createElement('tr');
		tr.appendChild(statusTd);
		tr.appendChild(fnameTd);
		tr.appendChild(fileTd);
		table.appendChild(tr);

		status[fname] = {
			statusTd,
			fileInput,
			accepted: false,
		};
	}

	function checkFsFile(fname, sync) {
		var buffer;
		try {
			buffer = FS.readFile('/installers/' + fname);
		} catch (e) {
			status[fname].statusTd.innerText = '\u2014';
			details.open = true;
			return;
		}

		// Warning: `crypto.subtle` is only available on HTTPS sites.
		crypto.subtle.digest('SHA-256', buffer).then(hashBuffer => {
			var hexdigest = Array.from(new Uint8Array(hashBuffer)).map(b => b.toString(16).padStart(2, '0')).join('');
			if (hexdigest === meta[fname].sha256sum) {
				status[fname].accepted = true;
				status[fname].statusTd.innerText = 'Ok';
				status[fname].fileInput.disabled = true;
				status[fname].fileInput.hidden = true;
				if (sync) {
					HamSandwich.fsSync();
				}
				Module.removeRunDependency('installer ' + fname);
			} else {
				status[fname].statusTd.innerText = 'Bad';
				details.open = true;
			}
		});
	}

	function preInit() {
		for (var fname in meta) {
			Module.addRunDependency('installer ' + fname);
		}
	}

	function onFsInit() {
		for (var fname in meta) {
			checkFsFile(fname, false);
		}
	}

	return {
		preInit,
		onFsInit,
	}
})();

// ----------------------------------------------------------------------------
// Emscripten imports and exports
var Module = (function() {
	var status = document.getElementById('status');
	var spinner = document.getElementById('spinner');
	var canvas = document.getElementById('canvas');

	var totalDependencies = 0, unsatisfied = 0;
	var hasContext = true;

	document.getElementById('fullscreen')?.addEventListener('click', function() {
		Module.canvas.requestFullscreen();
	});

	document.getElementById('export')?.addEventListener('click', function() {
		function saveAs(file, filename) {
			if (window.navigator.msSaveOrOpenBlob) { // IE10+
				window.navigator.msSaveOrOpenBlob(file, filename);
			} else { // Others
				var a = document.createElement("a"),
						url = URL.createObjectURL(file);
				a.href = url;
				a.download = filename;
				document.body.appendChild(a);
				a.click();
				setTimeout(function() {
					document.body.removeChild(a);
					window.URL.revokeObjectURL(url);
				}, 0);
			}
		}

		function collect(zip, fsPath) {
			var list = FS.readdir(fsPath);
			for (var item of list) {
				if (item == "." || item == "..") continue;
				var fullItem = fsPath + "/" + item;
				if (FS.isDir(FS.stat(fullItem).mode)) {
					collect(zip.folder(item), fullItem);
				} else {
					zip.file(item, FS.readFile(fullItem));
				}
			}
		}

		Module.setStatus("Zipping...");
		var zip = new JSZip();
		collect(zip, '/appdata/' + HamSandwich.metadata.projectName);
		zip.generateAsync({ type: "blob" }).then(function(content) {
			saveAs(content, "HamSandwich Saves.zip");
			Module.setStatus("");
		});
	});

	// As a default initial behavior, pop up an alert when webgl context is lost. To make your
	// application robust, you may want to override this behavior before shipping!
	// See http://www.khronos.org/registry/webgl/specs/latest/1.0/#5.15.2
	canvas.addEventListener('webglcontextlost', function(e) {
		if (hasContext) alert("WebGL context lost. You will need to reload the page.");
		hasContext = false; // only show this debug message once
		e.preventDefault();
	});

	// Only items which Emscripten actually interfaces with should be set here.
	return {
		canvas: canvas,

		print: function(text) {
			if (arguments.length > 1) text = Array.prototype.slice.call(arguments).join(" ");
			console.log(text);
		},
		printErr: function(text) {
			if (arguments.length > 1) text = Array.prototype.slice.call(arguments).join(" ");
			if (!text.startsWith('Preparing... (')) {
				console.warn(text);
			}
		},
		setStatus: function(text) {
			var matches = /^Downloading data\.\.\. \((\d+)\/(\d+)\)$/.exec(text);
			if (matches) {
				var loaded = parseInt(matches[1]), total = parseInt(matches[2]);
				var pct = Math.round(loaded * 1000 / total) / 10;
				text = "Downloading data (" + pct + "%)";
			}

			spinner.hidden = !text;
			status.innerText = text;
		},
		monitorRunDependencies: function(left) {
			totalDependencies += Math.max(0, left - unsatisfied);
			unsatisfied = left;
			Module.setStatus("Preparing... (" + (totalDependencies - left) + "/" + totalDependencies + ")");
		},

		preInit: [
			function() {
				Module.requestFullscreen = function() {
					Module.canvas.requestFullscreen();
				}
				setWindowTitle = HamSandwich.setWindowTitle;
			},
			InstallerUpload.preInit,
			HamSandwich.fsInit,
		],

		postRun: function() {
			document.getElementById('installer-upload').open = false;
		},
	};
})();

Module.setStatus("Downloading...");
window.onerror = function(event) {
	Module.setStatus("Error! See browser console.");
	spinner.hidden = true;
	Module.setStatus = Module.printErr;
};

(function () {
	var tag = document.createElement('script');
	tag.src = HamSandwich.metadata.projectName + '.js';
	document.body.appendChild(tag);
})();