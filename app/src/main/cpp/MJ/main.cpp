/*
  Copyright (C) 1997-2011 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "StdAfx.h"
#include "MjView.h"

#if defined(__IPHONEOS__) || defined(__ANDROID__)
#define HAVE_OPENGLES
#endif

SDL_Surface* LoadImageEx(const char*path){
	return IMG_Load(path);
}
// FILE* stderr=NULL;
/* Call this instead of exit(), so we can clean up SDL: atexit() is evil. */
/* Adapted from SDL's testspriteminimal.c */
Sprite LoadSprite(const char* file, SDL_Renderer* renderer)
{
	Sprite result;
	result.texture = NULL;
	result.w = 0;
	result.h = 0;

	SDL_Surface* temp;

	/* Load the sprite image */
	temp = LoadImageEx(file);
	if (temp == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", file, SDL_GetError());
		return result;
	}
	result.w = temp->w;
	result.h = temp->h;

	/* Create texture from the image */
	result.texture = SDL_CreateTextureFromSurface(renderer, temp);
	if (!result.texture) {
		fprintf(stderr, "Couldn't create texture: %s\n", SDL_GetError());
		SDL_FreeSurface(temp);
		return result;
	}
	SDL_FreeSurface(temp);

	return result;
}

void draw(SDL_Window* window, SDL_Renderer* renderer, const Sprite sprite)
{
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	SDL_Rect destRect = {w/2 - sprite.w/2, h/2 - sprite.h/2, sprite.w, sprite.h};
	/* Blit the sprite onto the screen */
	SDL_RenderCopy(renderer, sprite.texture, NULL, &destRect);
}
/* Simple program:  Fill a colormap with gray and stripe it down the screen */
bool SetScreenSurface(SDL_Window *window)
{
	int i;
	SDL_Color clr[NUM_COLORS];
	Uint8 *buffer;
	SDL_Surface* screen = SDL_GetWindowSurface(window);
	if ( screen == NULL ) {
		fprintf(stderr, "Couldn't set display mode: %s\n",	SDL_GetError());
		return(false);
	}
	fprintf(stderr, "Screen is in fullscreen mode\n");

	// Set a gray colormap, reverse order from white to black 
	for ( i=0; i<NUM_COLORS; ++i ) {
		clr[i].r = (NUM_COLORS-1)-i * (256 / NUM_COLORS);
		clr[i].g = (NUM_COLORS-1)-i * (256 / NUM_COLORS);
		clr[i].b = (NUM_COLORS-1)-i * (256 / NUM_COLORS);
	}
	SDL_Palette *palette = SDL_AllocPalette(NUM_COLORS);
	if(palette==0)return false;
	if(0!=SDL_SetPaletteColors(palette,clr,0,NUM_COLORS)){
		SDL_FreePalette(palette);
		fprintf(stderr, "Couldn't set SDL_SetPaletteColors mode: %s\n",	SDL_GetError());
		return(false);
	}
	// palette.ncolors = NUM_COLORS;
	// palette.colors = clr;
	// palette.version = ;
    // palette.refcount;
	SDL_SetSurfacePalette(screen, palette);
	SDL_FreePalette(palette);
	// Set the surface pixels and refresh! 
	if ( SDL_LockSurface(screen) < 0 ) {
		fprintf(stderr, "Couldn't lock display surface: %s\n",
							SDL_GetError());
		return(false);
	}
	buffer = (Uint8 *)screen->pixels;
	for ( i=0; i<screen->h; ++i ) {
		memset(buffer,(i*(NUM_COLORS-1))/screen->h, screen->w);
		buffer += screen->pitch;
	}
   SDL_UpdateWindowSurface(window); 
   
//	SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);  
//	SDL_RenderClear(sdlRenderer);  
//	SDL_RenderPresent(sdlRenderer);  
	 return true;
}

int main(int argc, char *argv[])
{
	SDL_Window* window = NULL;
	int width=640,height=480;
    SDL_Event event;

   /* Initialize SDL */
	if ( SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO ) < 0 ) {
		fprintf(stderr, "Couldn't initialize SDL: %s\n",SDL_GetError());
		exit(1);
	}
	if(0==IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG)){
		fprintf(stderr, "Couldn't initialize SDL: %s\n",SDL_GetError());
		exit(1);
	}
	//stderr = fopen("mjlog.txt", "w+");
	//创建窗口
//	window = SDL_CreateWindow("MJSDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_FULLSCREEN|SDL_WINDOW_OPENGL);
	SDL_Renderer *renderer=NULL;
	SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN, &window, &renderer);
	if (NULL == window)
	{
		SDL_Quit();
		return -1;
	}
	//如果你对这些十六进制感到害怕，可以通过调用SDL_PixelFormatEnumToMasks()来找出相应的枚举值  
	// SDL_Surface *screen = SDL_CreateRGBSurface(0, width, height, 32,  
                                        // 0x00FF000,  
                                        // 0x0000FF00,  
                                        // 0x000000FF,  
                                        // 0xFF000000);  
	//SDL_Texture*sdlTexture=SDL_CreateTexture(sdlRenderer,SDL_PIXELFORMAT_ARGB8888,SDL_TEXTUREACCESS_STREAMING,640, 480);
	//if(NULL==sdlTexture)goto EXIT;
	//SDL_UpdateTexture(sdlTexture, NULL, screen->pixels, screen->pitch);  
	//SDL_UpdateTexture(sdlTexture, NULL, myPixels, 640 * sizeof (Uint32));  
	//SDL_RenderClear(sdlRenderer);  
	//SDL_RenderCopy(sdlRenderer, sdlTexture, NULL, NULL);  
	//SDL_RenderPresent(sdlRenderer);  

	//获取窗口表面
	//screen = SDL_GetWindowSurface(window);
//	SetScreenSurface(window);
	/* Draw a gray background */
	Sprite sprite = LoadSprite("enter.jpg", renderer);
	if(sprite.texture == NULL)
		exit(2);
	SDL_SetRenderDrawColor(renderer, 0xA0, 0xA0, 0xA0, 0xFF);
	SDL_RenderClear(renderer);
//	draw(window, renderer, sprite);
	/* Update the screen! */
	SDL_RenderPresent(renderer);
	SDL_Delay(10);

	//if ( screen == NULL ) {
	//	goto EXIT;	//exit(2);
	//}
		
	/* Wait for a keystroke */
	int nTicks = 0;
	CMjView g_cMjView;
	g_cMjView.OnDraw(window);
	while ( !g_cMjView.m_bExit )
	{
		if ( SDL_PollEvent(&event) ) 
		{
			switch (event.type) 
			{
				SDL_Point pnt;
				case SDL_MOUSEMOTION:
					{
						 pnt = {event.motion.x,event.motion.y};
						g_cMjView.OnMouseMove(pnt);
					}
					break;
				case SDL_MOUSEBUTTONDOWN:
					if (event.button.button==SDL_BUTTON_LEFT)
					{
						 pnt = {event.button.x,event.button.y};
						g_cMjView.OnLButtonDown(pnt);
					}
					else if (event.button.button==SDL_BUTTON_RIGHT)
					{
						 pnt = {event.button.x,event.button.y};
						g_cMjView.OnRButtonDown(pnt);
					}
					break;
				case SDL_MOUSEBUTTONUP:
					if (event.button.button==SDL_BUTTON_LEFT)
					{
						 pnt = {event.button.x,event.button.y};
						g_cMjView.OnLButtonUp(pnt);
					}
					break;
				case SDL_KEYDOWN:
					g_cMjView.OnKeyDown(event.key.keysym.sym);
					break;
				case SDL_QUIT:
					g_cMjView.m_bExit = true;
					break;
				default:
					break;
			}
		}

		int nNowTicks = SDL_GetTicks()/100;
		if (nNowTicks!=nTicks)
		{
			nTicks = nNowTicks;
			g_cMjView.OnTimer();
			g_cMjView.OnDraw(window);
		}
	}
	
	
EXIT: 
    // Close and destroy the window
//	fclose(stderr);
	g_cMjView.OnFreeSurface();
	SDL_DestroyWindow(window);

	IMG_Quit();	SDL_Quit();
	
    return 0;
}

/* vi: set ts=4 sw=4 expandtab: */