#ifndef PACMAN_H_INCLUDED
#define PACMAN_H_INCLUDED
#include "Hender.h"
#include "Level.h"
#include "Load_texture.h"
#include "Texto_game.h"

GLint direcao = 0;
GLint contmap = 0;
int Tipo_pacman = HORIZONTAL_ESQUERDO;
int Tipo_pacman_abertura = HORIZONTAL_DIREITO;
int bola = 1,ENTER = 0,contani=0,homeX,homeY;
GLint movery = 0;
GLfloat movepac = 0;

void moveX(int dir);
void moveY(int dir);
void Colisao();
bool animar();
bool verifica_vitoria();
void encontra_pacman();
void mov_pacman(int passo);
void Bola_Pacman(int x,int y);
void Desenha_Pacman_abertura();
void mov_pacman_jogo(int passo);
void Desenha_life(int LIFE,int LIFE2);
void Desenha_Pacman();


#endif // PACMAN_H_INCLUDED
