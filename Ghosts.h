/*
 * Ghost.h
 *
 *  Created on: 14/01/2016
 *      Author: joao-marcos
 */
#ifndef GHOST_H_
#define GHOST_H_
#include "Hender.h"
#include "Level.h"
#include "Load_texture.h"
#include "Texto_game.h"

int _homeX_blinky,_homeY_blinky,_homeX_inky,_homeY_inky,_homeX_pinky,_homeY_pinky,_homeX_clyde,_homeY_clyde,y,x,esc = 0;

char GHOST[4]={'B','I','P','K'};
GLint direcao_blinky = 0;
GLint direcao_pinky = 0;
GLint direcao_clyde = 0;
GLint direcao_inky = 0;
GLfloat mov_ghost = 0;
GLint direcao_abertura = 1;
GLfloat mov_blinky_x = 0;
GLfloat mov_blinky_y = 0;
GLfloat mov_inky_x = 0;
GLfloat mov_inky_y = 0;
GLfloat mov_pinky_x = 0;
GLfloat mov_pinky_y = 0;
GLfloat mov_clyde_x = 0;
GLfloat mov_clyde_y = 0;

void moveX_ghost_blinky(int _dir,char ghost);
void moveX_ghost_inky(int _dir,char ghost);
void moveX_ghost_pinky(int _dir,char ghost);
void moveX_ghost_clyde(int _dir,char ghost);
void moveY_ghost_blinky(int _dir,char ghost);
void moveY_ghost_inky(int _dir,char ghost);
void moveY_ghost_pinky(int _dir,char ghost);
void moveY_ghost_clyde(int _dir,char ghost);
void encontra_ghost_blinky(char);
void encontra_ghost_inky(char);
void encontra_ghost_pinky(char);
void encontra_ghost_clyde(char);
void mov_ghost_blinky_jogo(int passo);
void mov_ghost_inky_jogo(int passo);
void mov_ghost_pinky_jogo(int passo);
void mov_ghost_clyde_jogo(int passo);
void ghost_BLINKY(int ,int);
void ghost_CLYDE(int ,int);
void ghost_PINKY(int ,int);
void ghost_INKY(int ,int);
void mov_fantasma(int passo);
void ghost_abertura(int soma);




#endif /* GHOST_H_ */
