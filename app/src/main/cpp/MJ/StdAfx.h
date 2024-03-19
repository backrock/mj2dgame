#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//#ifdef WIN32
//#  include "Resource.h"
//#endif /* WIN32 */

#include "../include/SDL.h"
#include "../include/SDL_image.h"
//#include "mmsystem.h"

#ifdef TEST_VGA16 /* Define this if you want to test VGA 16-color video modes */
#define NUM_COLORS	16
#else
#define NUM_COLORS	256

#define MAX_PATH 1024
#ifndef _WIN32
//typedef struct _tagRECT_{
//    long left,right,top,bottom;
//}RECT;
#define SW_HIDE             0
#define SW_SHOWNORMAL       1
#define SW_NORMAL           1
#define SW_SHOWMINIMIZED    2
#define SW_SHOWMAXIMIZED    3
#define SW_MAXIMIZE         3
#define SW_SHOWNOACTIVATE   4
#define SW_SHOW             5
#define SW_MINIMIZE         6
#define SW_SHOWMINNOACTIVE  7
#define SW_SHOWNA           8
#define SW_RESTORE          9
#define SW_SHOWDEFAULT      10
#define SW_FORCEMINIMIZE    11
#define SW_MAX              11

typedef short BYTE;
#endif

typedef struct Sprite
{
    SDL_Texture* texture;
    Uint16 w;
    Uint16 h;
} Sprite;

#ifndef _LOAD_IMAGE_EX_
#define _LOAD_IMAGE_EX_
#ifdef __cplusplus
extern "C" {
#endif
SDL_Surface* LoadImageEx(const char*path);
#ifdef __cplusplus
}
#endif
#endif

#endif
