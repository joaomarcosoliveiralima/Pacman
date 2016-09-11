#ifndef HENDER_H_INCLUDED
#define HENDER_H_INCLUDED

#ifndef HENDERS_H_INCLUDED
#define HENDERS_H_INCLUDED

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
///CONSTATES USADAS///
#define HORIZONTAL_DIREITO 1
#define HORIZONTAL_ESQUERDO 2
#define VERTICAL_CIMA 3
#define VERTICAL_BAIXO 4
#define pacman mapPac[homeX][homeY]
#define blinky mapGhost[_homeX_blinky][_homeY_blinky]
#define inky mapGhost[_homeX_inky][_homeY_inky]
#define pinky mapGhost[_homeX_pinky][_homeY_pinky]
#define clyde mapGhost[_homeX_clyde][_homeY_clyde]
#define VIVO 1
#define DEAD 0
#define NULO 0
#define MatxX 28
#define MatxY 39
#define SCALAX  9
#define SCALAY  7.5
#define COMPX (TAMW  -MatxX*SCALAX)/2
#define COMPY (TAMH -MatxY*SCALAY)/2+5
#define TAMW 400
#define TAMH 300
#define LIN 31
#define COL 41

#endif // HENDERS_H_INCLUDED


#endif // HENDER_H_INCLUDED
