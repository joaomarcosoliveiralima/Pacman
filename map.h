#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include "Ghost.h"
#include "Level.h"
//#include "Load_texture.h"
#define MatxX 28
#define MatxY 39
#define SCALAX  9
#define SCALAY  7.5
#define COMPX (TAMW  -MatxX*SCALAX)/2
#define COMPY (TAMH -MatxY*SCALAY)/2+5
#define TAMW 400
#define TAMH 300

float MaxX,MinX,MaxY,MinY;
char texture_lab[] = "./texturas/testando.bmp";
float PI = 3.14,r=1.3,t;
int n=0;

void Labirinto();
void setXY(float xCental ,float yCental);



#endif // MAP_H_INCLUDED
