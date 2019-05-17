#include "palettes.h"
#include "ham_mgldraw.h"
#include <algorithm>

void WaterPalette(MGLDraw *mgl)
{
	const RGB* pal = mgl->GetPalette();
	PALETTE pal2;

	for(int i=0; i<8; i++)
		for(int j=0; j<32; j++)
		{
			pal2[i*32+j] = pal[i*32+j];
			pal2[i*32+j].b = (byte) std::min((int) pal2[i*32+j].b + 4*40, 4*63);
		}

	mgl->SetSecondaryPalette(pal2);
}

void LavaPalette(MGLDraw *mgl)
{
	const RGB* pal = mgl->GetPalette();
	PALETTE pal2;

	for(int i=0; i<8; i++)
		for(int j=0; j<32; j++)
		{
			pal2[i*32+j] = pal[i*32+j];
			pal2[i*32+j].r = (byte) std::min((int) pal2[i*32+j].r + 4*40, 4*63);
		}

	mgl->SetSecondaryPalette(pal2);
}

void DumbSidePalette(MGLDraw *mgl)
{
	const RGB* pal = mgl->GetPalette();
	PALETTE pal2;

	for(int i=0; i<8; i++)
		for(int j=0; j<32; j++)
		{
			pal2[i*32+j] = pal[i*32+j];
			pal2[i*32+j].r = (byte) std::min((int) pal2[i*32+j].r + 4*30, 4*63);
			pal2[i*32+j].b = (byte) std::min((int) pal2[i*32+j].b + 4*30, 4*63);
			if(pal2[i*32+j].g > 10*4)
				pal2[i*32+j].g -= 10*4;
			else
				pal2[i*32+j].g = 0;
		}

	mgl->SetSecondaryPalette(pal2);
}

void GreyPalette(MGLDraw* mgl)
{
	const RGB* pal = mgl->GetPalette();
	PALETTE pal2;

	for (int i = 0; i < 256; ++i)
	{
		pal2[i] = pal[i & 31];
	}

	mgl->SetSecondaryPalette(pal2);
}

void DarkPalette(MGLDraw* mgl)
{
	const RGB* pal = mgl->GetPalette();
	PALETTE pal2;

	for (int i = 0; i < 256; ++i)
	{
		pal2[i].r = (byte)(pal[i].r >> 1);
		pal2[i].g = (byte)(pal[i].g >> 1);
		pal2[i].b = (byte)(pal[i].b >> 1);
	}
	pal2[175] = pal[175];
	pal2[255] = pal[255];

	mgl->SetSecondaryPalette(pal2);
}

void CyclePalette(MGLDraw *mgl, int c)
{
	const RGB* pal = mgl->GetPalette();
	PALETTE pal2;

	for (int i = 0; i < 256; ++i)
	{
		pal2[i] = pal[(i + c) % 256];
	}

	mgl->SetSecondaryPalette(pal2);
}