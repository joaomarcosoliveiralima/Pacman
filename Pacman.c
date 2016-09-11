#include "Pacman.h"

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
