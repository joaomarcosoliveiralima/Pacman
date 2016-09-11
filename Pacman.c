#include "Hender.h"
#include "Ghosts.h"


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


void mov_pacman_jogo(int passo)
{
    encontra_pacman();
    switch(direcao)//up
    {
        case 1:
            moveX(1);
            break;
        case 2://down
            moveX(2);
            break;
        case 3://left
            moveY(3);
            break;
        case 4://Right
            moveY(4);
            break;
    }
    glutPostRedisplay();
    glutTimerFunc(50,mov_pacman_jogo,1);
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

void moveX(int dir)
{
    if(dir==1)
    {
    	if(verifica_vitoria())
    	{
    		printf("Parabens vc Ganhou!");
    		exit(0);
    	}
        homeX++;
        if(pacman!='X'&&pacman!='-'&&pacman!='7'){
        	if(pacman == '.')
        		contmap++;
        	else if(pacman == '*')
        		contmap++;
            pacman='C';
            mapPac[homeX-1][homeY]= ' ';
            soma_y+= 7.5;
            Tipo_pacman = VERTICAL_CIMA;
            ///atualizar();
        }
        else
        {
            Tipo_pacman = NULO;
        }
        ///atualizar();
    }
    else if(dir==2)
    {
    	if(verifica_vitoria())
    	{
    		printf("Parabens vc Ganhou!");
    		exit(0);
    	}
        homeX--;
        if(pacman!='X'&&pacman!='-'&&pacman!='7'){
        	if(pacman == '.')
        		contmap++;
        	else if(pacman == '*')
        		contmap++;
            pacman='C';
            mapPac[homeX+1][homeY]=' ';
            soma_y-= 7.5;
            Tipo_pacman = VERTICAL_BAIXO;
            ///atualizar();
        }
        else
        {

            Tipo_pacman = NULO;
        }
        ///atualizar();
    }

}
void moveY(int dir)
{
    if(dir==3)
    {
    	if(verifica_vitoria())
    	{
    		printf("Parabens vc Ganhou!");
    		exit(0);
    	}
        homeY--;
        if(pacman!='X'&&pacman!='-'&&pacman!='7'){
        	if(pacman == '.')
        		contmap++;
        	else if(pacman == '*')
        		contmap++;
            pacman='C';
            mapPac[homeX][homeY+1]= ' ';
            //preenche_a_matriz_com_T();
            soma_x-= 9;
            Tipo_pacman = HORIZONTAL_ESQUERDO;
            ///atualizar();
        }
        else
        {
            Tipo_pacman = NULO;
        }
        ///atualizar();
    }
    else if(dir==4)
    {
    	if(verifica_vitoria())
    	{
    		printf("Parabens vc Ganhou!");
    		exit(0);
    	}
        encontra_pacman();
        homeY++;
        if(pacman!='X'&&pacman!='-'&&pacman!='7'){
        	if(pacman == '.')
        		contmap++;
        	else if(pacman == '*')
        		contmap++;
            pacman='C';
            mapPac[homeX][homeY-1]=' ';
            soma_x+=9.0;
            Tipo_pacman = HORIZONTAL_DIREITO;
            ///atualizar();
        }
        else
        {
            Tipo_pacman = NULO;
        }
        ///atualizar();
    }
}

void encontra_pacman()
{
    for(x=0;x<LIN;x++)
    {
        for(y=0;y<COL;y++)
        {
            if(mapPac[x][y]=='C')
            {
                homeX=x;
                homeY=y;
            }
        }
    }
}

void Desenha_life(int LIFE, int LIFE2)
{

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    float nA=0,sA=0;
	float r=5.5,segments=45;
    float t;
    if(animar())
    {
        nA=-58;
        sA=-32;
    }else
    {
        nA=-65;
        sA=-25;
    }

    glColor3f(LIFE,LIFE,DEAD);
    glBegin( GL_TRIANGLE_FAN );
        glVertex2f(355+x, y+118);
        for( n = nA; n <= segments+sA; ++n ) {
            t=1*M_PI*(float)n/(float)segments;
            glVertex2f(355+x+sin(t)*r, y+118+cos(t)*r);
        }
    glEnd();

    glColor3f(LIFE2,LIFE2,DEAD);
    glBegin( GL_TRIANGLE_FAN );
        glVertex2f(370+x, y+118);
        for( n = nA; n <= segments+sA; ++n ) {
            t=1*M_PI*(float)n/(float)segments;
            glVertex2f(370+x+sin(t)*r, y+118+cos(t)*r);
        }
    glEnd();
    glFlush();
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

void Bola_Pacman(int x,int y)
{
     glTranslatef(x,y,0);
     glColor3f(bola,bola,bola);
     GLfloat angle=0;
     int i=0;
     GLsizei rsize = 1;
     GLfloat circle_points = 100;
     glBegin(GL_POLYGON);
// Desenha o circulo

     for (i = 0; i < circle_points; i++)
     {
        angle = 2*M_PI*i/circle_points;
        glVertex2f(3*cos(angle) + 25, 3*sin(angle) + 30-rsize);
     }
     glEnd();
// Executa os comandos OpenGL
     glFlush();
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
void Desenha_Pacman()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPointSize(7);
    glLineWidth(3);
    float nA=0,sA=0;
	float r=5.0,segments=45;
    float t;

    switch(Tipo_pacman)
    {
        case 0:
            nA=-25;
            sA=25;
          break;
        case 1:
            if(animar())
            {
                nA=-58;
                sA=-32;
            }else
            {
                nA=-65;
                sA=-25;
            }
        break;
       case 2:
            if(animar())
            {
                nA=-10;
                sA=10;
            }else
            {
                nA=-20;
                sA=19;
            }
       break;
       case 3:
           if(animar())
            {
            nA=10;
            sA=35;
            }else
            {
             nA=5;
            sA=45;
            }
       break;
       case 4:
            if(animar())
            {
                nA=55;
                sA=80;
            }else
            {
                nA=48;
                sA=88;
            }
      break;
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1,1,0);
    glBegin(GL_TRIANGLE_FAN);//209
        glVertex2f(209+soma_x,soma_y+61);
        for( n = nA; n <= segments+sA; ++n ) {
            t=1*M_PI*(float)n/(float)segments;
            glVertex2f(soma_x+209+sin(t)*r,soma_y+61+cos(t)*r);
        }
    glEnd();
   // glFlush();
}
bool animar(){
	contani+=1;
	if(contani==32){
		contani=0;
	}
	if (contani<15)
		return true;
	else
		return false;

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
void Colisao ()
{
     if (movery < -45)       {movery=0;}

     if (movery > 0)       {movery=-45;}
     glutPostRedisplay();
}
void mov_pacman(int passo)
{
    Tipo_pacman_abertura = HORIZONTAL_DIREITO;
    bola = 1;
    if(direcao_abertura==1)
    {
        movepac+= 1;
        if(movepac==148) direcao_abertura = 0;

    }
    else
    {
        movepac-= 1;
        if(movepac==-90) direcao_abertura = 1;
        Tipo_pacman_abertura = HORIZONTAL_ESQUERDO;
        bola = 0;

    }
    glutPostRedisplay();
    glutTimerFunc(20,mov_pacman, 1);
}

void Desenha_Pacman_abertura()
{
    float nA,sA,y=123,raio=6,segments=45,t;

     if(Tipo_pacman_abertura==HORIZONTAL_DIREITO)
    {
        if(animar())
        {
            nA=-58;
            sA=-32;
        }else
        {
            nA=-65;
            sA=-25;
        }
    }

    if(Tipo_pacman_abertura==HORIZONTAL_ESQUERDO)
    {
        if(animar())
        {
            nA=-10;
            sA=10;
        }else
        {
            nA=-20;
            sA=19;
        }
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1,1,0);

    glBegin( GL_TRIANGLE_FAN );
        glVertex2f(96+movepac, y+8);
        for( n = nA; n <= segments+sA; ++n ) {
            t=1*M_PI*(float)n/(float)segments;
            glVertex2f(96+movepac+sin(t)*raio, y+8+cos(t)*raio);
        }
    glEnd();
    glFlush();
}
bool verifica_vitoria()
{
	if(contmap == 280)
	{
		return true;
	}
	else
		return false;
}
