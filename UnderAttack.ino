//ThaddeusSM
//03/16/18

//Libraries
#include <Arduboy2.h>
#include <FixedPoints.h>
#include <FixedPointsCommon.h>
#define MAX_GUN_ANGLE 1.1
#define MIN_GUN_ANGLE -1.1
Arduboy2 arduboy;


//Variables
const unsigned char titleScreen[] PROGMEM = { 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x1f, 0xf, 0x8f, 0xc7, 0xc7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf1, 0xf1, 0xf1, 0xe1, 0xc3, 0x87, 0x8f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x8f, 0x87, 0xc3, 0xe1, 0xf1, 0xf1, 0xf1, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xe3, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xc7, 0xc7, 0x8f, 0xf, 0x1f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x1f, 0x3, 0x80, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3, 0x7, 0xf, 0x1f, 0x3f, 0x3f, 0x3, 0x3, 0x3, 0x3, 0x3f, 0x3f, 0x3f, 0x3, 0x3, 0x3, 0x3, 0x3f, 0x3f, 0x3f, 0x3, 0x3, 0x3, 0x3, 0x3f, 0x3f, 0x3f, 0x3, 0x3, 0x3, 0x3, 0x3f, 0x3f, 0x3f, 0x3, 0x3, 0x3, 0x3, 0x3f, 0x3f, 0x1f, 0xf, 0x7, 0x3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x80, 0x3, 0x1f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x7, 0x00, 0xe0, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xe2, 0xe2, 0x6, 0x6, 0xdc, 0xc0, 0x9e, 0x5e, 0xc0, 0xdc, 0xdc, 0x1c, 0xd0, 0x80, 0x1c, 0xc0, 0x9c, 0x9c, 0x9c, 0x1c, 0x1c, 0x9c, 0x9c, 0x9c, 0xc0, 0xdc, 0xdc, 0xdc, 0x1c, 0xdc, 0xdc, 0xc0, 0xde, 0xde, 0xde, 0xde, 0x6, 0x6, 0xe2, 0xe2, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xe0, 0x00, 0x7, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7, 0x00, 0xf0, 0x3c, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x1, 0xf7, 0x6, 0x21, 0xc3, 0xe7, 0xc0, 0xb7, 0x77, 0x64, 0xe9, 0xe7, 0xef, 0xcf, 0x00, 0x00, 0xef, 0xef, 0xef, 0xef, 0xe7, 0xf7, 0xf7, 0xf0, 0xf7, 0xf7, 0xf7, 0x7, 0xb7, 0x1, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0xbf, 0xbf, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf0, 0x00, 0x7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0x9f, 0x9f, 0x8f, 0x87, 0xc7, 0xe1, 0xe0, 0xfc, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0x7f, 0xbf, 0xbf, 0xbf, 0x7f, 0xff, 0x7f, 0x3f, 0xbf, 0x3f, 0x7f, 0x1, 0xff, 0x7f, 0xbf, 0xbf, 0xbf, 0x7f, 0xff, 0x3f, 0x7f, 0xbf, 0xbf, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xa2, 0x3e, 0xbc, 0xb2, 0xae, 0x80, 0xbe, 0xbe, 0xbe, 0x3c, 0x3c, 0x00, 0x5d, 0x00, 0x00, 0x7d, 0x3d, 0xbd, 0xbc, 0x2, 0xb8, 0xbc, 0x80, 0xbc, 0xbe, 0xbe, 0x3e, 0xa2, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xef, 0xef, 0xef, 0xef, 0x00, 0xff, 0xef, 0x1, 0xef, 0xff, 0xef, 0x1, 0xef, 0xff, 0x7f, 0xbf, 0xbf, 0xbf, 0x7f, 0x3f, 0xff, 0x7f, 0xbf, 0xbf, 0xff, 0x1, 0xff, 0x7f, 0xbf, 0xff, 0xff, 0xfc, 0xe0, 0xe1, 0xc7, 0x87, 0x8f, 0x9f, 0x9f, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfb, 0xfb, 0xfb, 0xfb, 0xfc, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xfc, 0xf9, 0xfb, 0xf9, 0xfc, 0xf8, 0xff, 0xfc, 0xfa, 0xfa, 0xfa, 0xfa, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x00, 0x00, 0xf0, 0xf6, 0xf7, 0xf0, 0xf7, 0xf7, 0xf7, 0x7, 0xf7, 0xf7, 0xe7, 0xef, 0x6f, 0x28, 0x43, 0x00, 0x00, 0xcf, 0xcf, 0xcf, 0xef, 0xe0, 0xf7, 0xf7, 0x7, 0xf7, 0xf7, 0xf7, 0xf0, 0xf7, 0xf6, 0xf0, 0x00, 0x00, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xfc, 0xfb, 0xfb, 0xfb, 0xfc, 0xf8, 0xff, 0xfc, 0xfb, 0xfb, 0xff, 0xf8, 0xfe, 0xfd, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xdf, 0xdf, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0x7f, 0xff, 0x3f, 0x9f, 0xdf, 0x9f, 0x3f, 0xff, 0x7f, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x7, 0x3, 0x1, 0x00, 0x00, 0x00, 0x30, 0xb8, 0x3d, 0x9d, 0x9d, 0x81, 0xad, 0xb5, 0x81, 0x38, 0xbd, 0x3d, 0xbc, 0x80, 0xbd, 0xbc, 0xb1, 0xa4, 0x8c, 0x1d, 0xbd, 0xbd, 0x81, 0xbd, 0x3d, 0xbd, 0xbc, 0xbd, 0xbd, 0xbd, 0x81, 0xbd, 0xbd, 0x3d, 0xb8, 0xb0, 0x80, 0x00, 0x00, 0x1, 0x3, 0x7, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0xfd, 0xfd, 0xfe, 0x83, 0xf7, 0xfb, 0xf7, 0xff, 0xc7, 0xab, 0xff, 0xa7, 0xab, 0xdb, 0xff, 0xa7, 0xab, 0xdb, 0xff, 0xff, 0xff, 0xff, 0x80, 0xfb, 0xfb, 0xfb, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf7, 0xf7, 0x7, 0xe0, 0xe7, 0x7, 0xf3, 0x3, 0x73, 0x4, 0xf6, 0xf7, 0xf0, 0x7, 0xf7, 0xf7, 0xf7, 0x7, 0xf7, 0xf7, 0x00, 0xf7, 0xe7, 0xe7, 0x7, 0xd0, 0xd7, 0xb7, 0x7, 0x97, 0xd7, 0xb7, 0x7, 0x27, 0xe0, 0x7, 0xf7, 0xf7, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
};
const unsigned char PROGMEM Gameplay1[] =
{
// width, height,
128, 64,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xff, 0x7f, 0x3e, 0x18, 0x18, 0xf8, 0x1e, 0x1f, 0x3f, 0x7e, 0xf8, 0xf8, 0xf8, 0x3e, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x04, 0xfc, 0x04, 0x04, 0x04, 0x07, 0x04, 0x04, 0x04, 0xfc, 0x04, 0x0f, 0xff, 0xf0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x59, 0xc9, 0x49, 0x49, 0x49, 0x7f, 0x51, 0x51, 0x59, 0xc9, 0x49, 0x49, 0xff, 0xff, 0xa2, 0xa2, 0xff, 0x63, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x10, 0x1f, 0x10, 0x10, 0x10, 0xf0, 0x10, 0x10, 0x10, 0x1f, 0x10, 0x10, 0x1f, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x04, 0xfc, 0x04, 0x04, 0x04, 0x07, 0x04, 0x04, 0x04, 0xfc, 0x04, 0x04, 0x04, 0x05, 0x07, 0x07, 0x0e, 0x1c, 0xfc, 0xf8, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x0c, 0x0f, 0x4c, 0x8c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0f, 0x0c, 0x0c, 0x8c, 0x8c, 0x0c, 0x4c, 0x0c, 0x0e, 0x0f, 0x4f, 0x0f, 0x08, 0x08, 0x08, 0x48, 0x48, 0x48, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x88, 0x48, 0x48, 0x48, 0x48, 0x08, 0x08, 0x08, 0x08, 0x08, 0xc8, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0xc8, 0x88, 0x48, 0x08, 0x08, 0x08, 0x08, 0x08, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x48, 0x48, 0x28, 0x08, 0x08, 0x08, 0x08, 0x08, 0x88, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0xc8, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x48, 0x08, 0x08, 0x08, 0x08, 0x08, 0x88, 0x88, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 
0x00, 0x00, 0x08, 0x18, 0x00, 0x02, 0x03, 0x00, 0x00, 0x00, 0x0c, 0x08, 0x00, 0x20, 0x21, 0x60, 0x00, 0x00, 0x04, 0x03, 0x04, 0x04, 0x00, 0x40, 0x20, 0x00, 0x00, 0x0e, 0x08, 0x06, 0x00, 0x22, 0x60, 0x00, 0x00, 0x02, 0x01, 0x00, 0x00, 0x00, 0x60, 0x20, 0x46, 0x08, 0x09, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x0e, 0x00, 0x40, 0x00, 0x30, 0x0c, 0x40, 0x00, 0x00, 0x02, 0x00, 0x02, 0x00, 0x10, 0x20, 0x28, 0x00, 0x01, 0x04, 0x04, 0x00, 0x00, 0x01, 0x10, 0x50, 0x00, 0x05, 0x04, 0x00, 0x00, 0x1c, 0x30, 0x00, 0x00, 0xe0, 0x00, 0x03, 0x00, 0x00, 0x00, 0x10, 0x10, 0x20, 0x20, 0x40, 0x40, 0x80, 0x84, 0x04, 0x04, 0x00, 0x70, 0x00, 0x03, 0x06, 0x00, 0x60, 0x00, 0x09, 0x01, 0x01, 0x01, 0x00, 0x04, 0x01, 0x21, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0x20, 0x24, 0x06, 0x00, 
};
const unsigned char PROGMEM Explosion[] =
{
// width, height,
16, 16,
0x00, 0x00, 0x20, 0x00, 0x80, 0x90, 0x00, 0x20, 0x80, 0xe0, 0x10, 0x40, 0x20, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x02, 0x08, 0x02, 0x0b, 0x02, 0x05, 0x08, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
};


int gamestate = 0;
const int x1 = 20;
const int y1 = 27;
float gunAngle = 0.0;
const float GAinc = 0.1953125;
int x2;
int y2;
int x3;
int y3;
struct Bullet {
  uint8_t x;
  uint8_t y;
  uint8_t xDelta;
  int8_t yDelta;
  bool active;
};
Bullet bullet = { 32, 32, 1, -1, true};


//Setup Script
void setup() {
  arduboy.begin();
  arduboy.initRandomSeed();
  arduboy.setFrameRate(60);
  arduboy.clear();
}

//Game Code
void loop() {
  if(!arduboy.nextFrame()) {
    return;
  }
  arduboy.pollButtons();
  arduboy.clear();
  switch(gamestate){
    case 0:
    arduboy.drawBitmap(0, 0, titleScreen, 128, 64, WHITE);
    if(arduboy.justPressed(A_BUTTON)) {
      gamestate = 1;
    }
      break;
    case 1:
    arduboy.drawBitmap(0, 0, Gameplay1, 128, 64, WHITE);
    x2 = x1 + cos(gunAngle) * 8;
    y2 = y1 + sin(gunAngle) * 8;
    x3 = x1 + cos(gunAngle) * 100;
    y3 = y1 + sin(gunAngle) * 100;
    arduboy.drawLine(x1, y1, x2, y2, WHITE);
    if(arduboy.justPressed(A_BUTTON)) {
      gamestate = 0;
    }
    if(arduboy.justPressed(UP_BUTTON)) {
      if(gunAngle > MIN_GUN_ANGLE){
        gunAngle = gunAngle - GAinc;
      }
    }
    if(arduboy.justPressed(DOWN_BUTTON)){
      if(gunAngle < MAX_GUN_ANGLE){
         gunAngle = gunAngle + GAinc;
      } 
    }
    if(arduboy.justPressed(B_BUTTON)) {
      if (gunAngle == 0.390625) {
        x3 = x3 - 46;
        y3 = y3 - 20;
      }
      if (gunAngle == -0.390625){
        x3 = x3 - 46;
        y3 = y3 + 20;
      } 
        arduboy.drawLine(x2, y2, x3, y3, WHITE);
        arduboy.drawBitmap(x3 - 8, y3 - 8, Explosion, 16, 16, WHITE);
     }
     if(arduboy.justPressed(RIGHT_BUTTON)) {
      bullet.x += bullet.xDelta;
      bullet.y += bullet.yDelta;
     }
    
        arduboy.setCursor(0, 0);
        arduboy.print(gunAngle);

      break;
    }


   
   arduboy.display();
}
