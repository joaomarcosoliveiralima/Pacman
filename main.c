#include "Hender.h"
#include "Ghosts.h"
#include "Pacman.h"

///VARIAVEIS OPENGL INTEIRAS///
float MaxX,MinX,MaxY,MinY;
char texture_lab[] = "./texturas/testando.bmp";
float PI = 3.14,r=1.3,t;
int n=0;

void Labirinto();
void setXY(float xCental ,float yCental);

GLint esc_menu = 0;
GLfloat soma_x = 0;
GLfloat soma_y = 0;

///VARIAVEIS TIPO BOOL
bool CONFIRMA=false;
///PROTOTIPOS DAS FUÇÕES///r,b,p,i



void Desenha();
void Inicializa();


void Informacao();
//void movedireito();

void Desenha_esc_menu();
//void Desenha_Abertura();

void TeclasEspeciais(int key,int x,int y);
void DESENHA_TEXTO(float x, float y, char *string);
void AlteraTamanhoJanela(GLsizei w, GLsizei h);
void evento_teclado(unsigned char key,int x,int y);

enum status {dead, scared, normal, poweredUp};

struct player {
	int x, y;						/* x, y position */
	int startX, startY;				/* starting x, y position */
	GLfloat colorf[3];				/* color of player */
	enum status state;				/* status of player */
} Pacman,Ghosts[4];

void atualizar()
{
    system("cls||clear");
    for(x=0;x<LIN;x++)
    {
        for(y=0;y<COL;y++)
        {
            printf("%c",mapGhost[x][y]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
    srand((unsigned)time(NULL));
    glClear(GL_COLOR_BUFFER_BIT);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,685);
    glutInitWindowPosition(150,1);
    glutCreateWindow("PACMAN EM OPENGL");
    glutKeyboardFunc(evento_teclado);
    glutSpecialFunc(TeclasEspeciais);
    Inicializa();
    encontra_pacman();
    glutDisplayFunc(Desenha);
    glutTimerFunc(10,mov_pacman,1);
    glutTimerFunc(10,mov_fantasma,1);
    glutTimerFunc(10,mov_pacman_jogo,1);
    glutTimerFunc(50,mov_ghost_blinky_jogo,1);
    glutTimerFunc(50,mov_ghost_inky_jogo,1);
    glutTimerFunc(50,mov_ghost_pinky_jogo,1);
    glutTimerFunc(50,mov_ghost_clyde_jogo,1);
    glutReshapeFunc(AlteraTamanhoJanela);

    glutMainLoop();
    return 0;
}

void Labirinto()
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     glLineWidth(2);

    	for(y=0; y<LIN;y++){
		for(x=0; x<COL;x++){
			glPushMatrix();
			switch(mapPac[y][x]){
			case '-':
                        setXY(x,y);
                        glBegin (GL_LINE_LOOP);
                            glColor3f (1.0,1.0,1.0);
                            glVertex2f( COMPX+14.3*SCALAX, COMPY+y*SCALAY);
                            glVertex2f( COMPX+16*SCALAX, COMPY+y*SCALAY);
                        glEnd();
                        glFlush();
            break;
			case '*':
                        r = 2.5;
                        setXY(x,y);
                        glBegin( GL_TRIANGLE_FAN);
                            glColor3f(1,1,1);
                            glVertex2f( COMPX+x*SCALAX , COMPY+y*SCALAY);
                            for(n = 0; n <= 10; ++n ) {
                                t=2*PI*(float)n/10;
                                glVertex2f(COMPX+x*SCALAX + sin(t)*r, COMPY+y*SCALAY + cos(t)*r);
                            }
                        glEnd();
                        glFlush();
            break;
			case 'X':
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture (GL_TEXTURE_2D,texture_id[1]);
                        LoadBMP(texture_lab);

                        setXY(x,y);
                        glBegin(GL_QUADS);
                            //glColor3f ( 0.0, 0.0, 1.0);
                            glTexCoord2f(0.0f, 0.0f);  glVertex2f( COMPX+MinX*SCALAX-1.9,COMPY+MaxY*SCALAY+1.5);
                            glTexCoord2f(1.0f, 0.0f);  glVertex2f( COMPX+MinX*SCALAX-1.9,COMPY+MinY*SCALAY-1.5);
                            glTexCoord2f(1.0f, 1.0f);  glVertex2f( COMPX+MaxX*SCALAX+1.7,COMPY+MinY*SCALAY-1.5);
                            glTexCoord2f(0.0f, 1.0f);  glVertex2f( COMPX+MaxX*SCALAX+1.7,COMPY+MaxY*SCALAY+1.5);
                        glEnd();
                        glDisable(GL_TEXTURE_2D);
                        glFlush();
				break;

			    case '.':// Comida PEQUENA
                        setXY(x,y);
                        r = 1.3;
                        glBegin( GL_TRIANGLE_FAN);
                            glColor3f(1,1,1);
                            glVertex2f( COMPX+x*SCALAX , COMPY+y*SCALAY);
                            for( n = 0; n <= 10; ++n ) {
                                t=2*PI*(float)n/10;
                                glVertex2f(COMPX+x*SCALAX + sin(t)*r, COMPY+y*SCALAY + cos(t)*r);
                            }
                        glEnd();
                        glFlush();
				break;
				case 'T':// Comida PEQUENA
                        setXY(x,y);
                        r = 1.3;
                        glBegin( GL_TRIANGLE_FAN);
                            glColor3f(1,1,1);
                            glVertex2f( COMPX+x*SCALAX , COMPY+y*SCALAY);
                            for( n = 0; n <= 10; ++n ) {
                                t=2*PI*(float)n/10;
                                glVertex2f(COMPX+x*SCALAX + sin(t)*r, COMPY+y*SCALAY + cos(t)*r);
                            }
                        glEnd();
                        glFlush();
				break;

                }
            }
            }
}

void desenha_textura(char imageTela[30])
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    printTexture(imageTela);
    glutSwapBuffers();
}
void setXY(float xCental ,float yCental)
{
	x=xCental;
	y=yCental;
    MaxX=x+0.3;
	MinX=x-0.3;
	MaxY=y+0.3;
	MinY=y-0.3;
}


void Informacao()
{
    {
    glColor3f(1,1,1);
    glRasterPos2f(330, 180);
    char* p = (char*) "SCORE :";
    while (*p != '\0')
         {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p++);
         }
    }

    {
    glColor3f(1,1,1);
    glRasterPos2f(330, 150);
    char* p = (char*) "VIDAS :";
    while (*p != '\0')
         {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p++);
         }
    }
}

void Desenha_esc_menu()
{
     glLineWidth(3);
     glBegin(GL_LINE_LOOP);
        glVertex2d(122,98+movery);
        glVertex2d(167,98+movery);
        glVertex2d(167,85+movery);
        glVertex2d(122,85+movery);
    glEnd();
    glFlush();
}

void Desenha()
{
        char imageTela[30]="./texturas/abertura3.bmp";
        DESENHA_TEXTO(330,180,imageTela);
        if(ENTER==0)
        {
            desenha_textura(imageTela);
        }
        switch(ENTER)
        {
         case 1:
         glDisable(GL_TEXTURE_2D);
         glClear(GL_COLOR_BUFFER_BIT);

         char str1[7]= "JOGAR";
         char str2[7]= "AJUDA";
         char str3[7]= "SOBRE";
         char str4[6]= "SAIR";
         char str5[7]= "SCORE";
         char str6[7]= "VIDAS";
         char nomeimag[]="./texturas/Menu.bmp";

         glColor3f(1,1,1);
         glClear(GL_COLOR_BUFFER_BIT);
         glEnable(GL_TEXTURE_2D);
         printTexture(nomeimag);
         glLoadIdentity();

         glColor3f(0,0,1);
         DESENHA_TEXTO(130,90,str1);
         DESENHA_TEXTO(130,75,str2);
         DESENHA_TEXTO(130,60,str3);
         DESENHA_TEXTO(130,45,str4);

         if(esc == 0)
         {
             glColor3f(1.0f,0.0f,0.0f);
             ghost_abertura(0);
             glColor3f(0.0f,1.0f,1.0f);
             ghost_abertura(15);
             glColor3f(1.0f,0.6f,0.0f);
             ghost_abertura(30);
             glColor3f(1.0f,0.0f,1.0f);
             ghost_abertura(45);
         }
         else
         {
             glColor3f(0.0f,0.0f,1.0f);
             ghost_abertura(0);
             glColor3f(0.0f,0.0f,1.0f);
             ghost_abertura(15);
             glColor3f(0.0f,0.0f,1.0f);
             ghost_abertura(30);
             glColor3f(0.0f,0.0f,1.0f);
             ghost_abertura(45);
         }
         Bola_Pacman(215,101);
         Desenha_Pacman_abertura();
         glColor3f(1.0f,1.0f,0.0f);
         Desenha_esc_menu();
         Colisao();
         switch(esc_menu)
         {
             case 1:
	             glColor3f(1,1,1);
                 glClear(GL_COLOR_BUFFER_BIT);
                 glDisable(GL_TEXTURE_2D);
                 Labirinto();
                 glColor3f(1.0f,0.0f,0.0f);
                 ghost_BLINKY(0,0);
                 glColor3f(0.0f,1.0f,1.0f);
                 ghost_INKY(18,-30);
                 glColor3f(1.0f,0.0f,1.0f);
                 ghost_PINKY(0,-30);
                 glColor3f(1.0f,0.6f,0.0f);
                 ghost_CLYDE(-18,-30);
                 Desenha_Pacman();
                 glutPostRedisplay();
                 Desenha_life(VIVO,VIVO);
                 glColor3f(1,1,1);
                 DESENHA_TEXTO(360,180,str5);
                 DESENHA_TEXTO(360,150,str6);


             break;
             case 2:
                  Desenha_ajuda();
             break;
             case 3:
                  Desenha_sobre();
             break;
             case 4:
                 exit(0);
             break;
         }
         glutSwapBuffers();
         break;
    }
}
void DESENHA_TEXTO(float x, float y, char *string)
{
  int len, i;
  glRasterPos2f(x, y);
  len = (int)strlen(string);

  for (i = 0; i < len; i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
  }
}
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}
void evento_teclado(unsigned char key,int x,int y)
{
   // glutFullScreen();
    //glutPostRedisplay();
    if(key==27)
    {
        exit(0);
    }
    if(key==87||key==119)
    {
        movery+=15;
    }
    if(key==83||key==115)
    {
        movery-=15;
    }
    if(key == 13)
    {
        /**direcao_blinky = 0;
        direcao_clyde =0;
        direcao_inky =0;
        direcao_pinky =0;**/
        glDisable(GL_TEXTURE_2D);
        glutFullScreen();
        glutPostRedisplay();
        ENTER += 1;
        if(ENTER!=1)
        {
            if(movery == 0){
               CONFIRMA = true;
               direcao_blinky = rand()%4+1;
               direcao_pinky = rand()%4+1;
               direcao_clyde = rand()%4+1;
               direcao_inky = rand()%4+1;
               esc_menu = 1;}
            if(movery == -15)
                esc_menu = 2;
            if(movery == -30)
                esc_menu = 3;
            if(movery == -45)
                esc_menu = 4;
            ENTER =1;
        }
    }
}
// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{    // Evita a divisao por zero
	if (h == 0)
		h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    if (w <= h)
            glOrtho(0, 250.0f, 0, 250.0f*h/w,-1000,1000);
    else
            glOrtho(0, 250.0f*w/h, 0, 250, -1000, 1000);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void TeclasEspeciais(int key, int x, int y)
{
    glutPostRedisplay();
    if(key == GLUT_KEY_UP)
        {
            if(CONFIRMA){
            Tipo_pacman = VERTICAL_CIMA;
            direcao = 1;}
            movery += 15;
        }
    if(key == GLUT_KEY_DOWN)
        {   if(CONFIRMA){
            Tipo_pacman = VERTICAL_BAIXO;
            direcao = 2;}
            movery -= 15;
        }
    if(key == GLUT_KEY_LEFT)
        {
            if(CONFIRMA){
            Tipo_pacman = HORIZONTAL_ESQUERDO;
            direcao = 3;}
        }
    if(key == GLUT_KEY_RIGHT)
        {
            if(CONFIRMA){
            Tipo_pacman = HORIZONTAL_DIREITO;
            direcao = 4;}
        }
     glutPostRedisplay();
}
