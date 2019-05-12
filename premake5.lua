-- premake5.lua
workspace "HamSandwich"
	configurations { "debug", "release" }
	location "build"

function allegro_project(name)
	project(name)
		kind "WindowedApp"
		language "C++"
		architecture "x86"
		targetdir("build/%{cfg.toolset}-%{cfg.buildcfg}/%{prj.name}/")
		objdir("build/%{cfg.toolset}-%{cfg.buildcfg}/%{prj.name}/obj/")

		includedirs { "build/allegro/include/" }
		libdirs { "build/allegro/lib/" }
		linkoptions { "-static-libgcc", "-static-libstdc++" }

		files {
			"source/" .. name .. "/**.h",
			"source/" .. name .. "/**.cpp",
			"source/" .. name .. "/**.rc",
		}

		filter "configurations:debug"
			defines { "_DEBUG" }
			symbols "On"

		filter "configurations:release"
			defines { "NDEBUG" }
			optimize "On"

		filter "system:Windows"
			links { "winmm", "allegro-4.4.2-monolith-mt", "ws2_32", "logg-1.0-mt", "vorbisfile-1.3.2-static-mt", "vorbis-1.3.2-static-mt", "ogg-1.2.1-static-mt" }

		filter {}
end

function removefiles_in(dir, files)
	list = {}
	for i = 1, #files do
		list[i] = dir .. files[i]
	end
	removefiles(list)
end

function icon_file(icon)
	-- Workaround for bug in premake5's gmake2 generator, which does
	-- not count .res (object) files as resources, only .rc (source)
	filter "system:Windows"
		linkoptions { "%{cfg.toolset}-%{cfg.buildcfg}/%{prj.name}/obj/" .. icon .. ".res" }
	filter {}
end

allegro_project "lunatic"
	icon_file "lunatic"
	buildoptions { "-Wall", "-Wextra", "-Wno-unused-parameter" }

allegro_project "supreme"
	icon_file "lunatic"
	buildoptions {
		"-Wall",
		"-Wno-write-strings",
		"-Wno-char-subscripts",
		"-Wno-unused-variable",
		"-Wno-unused-but-set-variable",
	}
	removefiles_in("source/supreme/", {
		"monsterlist.cpp",
		"monsterai1.cpp",
		"monsterai2.cpp",
		"monsterai3.cpp",
		"monsterai4.cpp",
		"textitems.cpp",
		"textrooms.cpp",
		"options.cpp",
		"spcldialog.cpp",
	})

allegro_project "sleepless"
	icon_file "lunatic"
	buildoptions {
		"-Wall",
		"-Wno-write-strings",
		"-Wno-char-subscripts",
		"-Wno-unused-variable",
		"-Wno-unused-but-set-variable",
	}
	removefiles_in("source/sleepless/", {
		"monsterlist.cpp",
		"monsterai1.cpp",
		"monsterai2.cpp",
		"monsterai3.cpp",
		"monsterai4.cpp",
		"monsterhollow.cpp",
		"textitems.cpp",
		"textrooms.cpp",
		"options.cpp",
		"spcldialog.cpp",
		"tally.cpp",
		"worldselect.cpp",
	})