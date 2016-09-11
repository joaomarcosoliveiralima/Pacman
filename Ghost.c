#include "Ghosts.h"


void mov_ghost_blinky_jogo(int passo)
{
    encontra_ghost_blinky(GHOST[0]);
    switch(direcao_blinky)
    {
        case 1://up
            moveX_ghost_blinky(1,GHOST[0]);
            break;
        case 2://down
            moveX_ghost_blinky(2,GHOST[0]);
            break;
        case 3://left
            moveY_ghost_blinky(3,GHOST[0]);
            break;
        case 4://Right
            moveY_ghost_blinky(4,GHOST[0]);
            break;
    }

    glutPostRedisplay();
    glutTimerFunc(50,mov_ghost_blinky_jogo,1);
}
void moveX_ghost_blinky(int _dir,char ghost)
{
    if(_dir==1)
        {
            _homeX_blinky++;
            if(blinky!='X'&&blinky!='T'&&blinky!='I'&&blinky!='P'&&blinky!='K'){

                blinky=ghost;
                mapGhost[_homeX_blinky-1][_homeY_blinky]= ' ';
                mov_blinky_y+= 7.5;
                ///atualizar();
            }
            else
            {
                if(blinky=='T')
                {
                    blinky=ghost;
                    mapGhost[_homeX_blinky-1][_homeY_blinky]= 'T';
                    mov_blinky_y+= 7.5;
                    srand((unsigned)time(NULL));
                    direcao_blinky=rand()%4+1;

                    ///atualizar();
                }
                else if(blinky=='I'||blinky=='P'||blinky=='K')
                {
                    direcao_blinky = rand()%4+1;
                }
                direcao_blinky=0;
                direcao_blinky = rand()%4+1;
                ///atualizar();
            }
        }
        else if(_dir==2)
        {
            _homeX_blinky--;
            if(blinky!='X'&&blinky!='T'&&blinky!='-'&&blinky!='I'&&blinky!='P'&&blinky!='K'){
                blinky=ghost;
                mapGhost[_homeX_blinky+1][_homeY_blinky]=' ';
                mov_blinky_y-= 7.5;
                ///atualizar();
            }
            else
            {
                if(blinky=='T')
                {
                    blinky=ghost;
                    mapGhost[_homeX_blinky+1][_homeY_blinky]='T';
                    mov_blinky_y-= 7.5;
                    srand((unsigned)time(NULL));
                    direcao_blinky=rand()%4+1;

                    ///atualizar();
                }
                else if(blinky=='I'||blinky=='P'||blinky=='K')
                {
                    direcao_blinky = rand()%4+1;
                }
                direcao_blinky=0;
                direcao_blinky = rand()%4+1;
                ///atualizar();
            }
    }
}
void moveY_ghost_blinky(int _dir,char ghost)
{
    if(_dir==3)
    {
        _homeY_blinky--;
        if(blinky!='X'&&blinky!='T'&&blinky!='-'&&blinky!='I'&&blinky!='P'&&blinky!='K'){
            blinky=ghost;
            mapGhost[_homeX_blinky][_homeY_blinky+1]= ' ';
            mov_blinky_x-= 9;
            ///atualizar();
        }
        else
        {
            if(blinky=='T')
            {
                blinky=ghost;
                mapGhost[_homeX_blinky][_homeY_blinky+1]= 'T';
                mov_blinky_x-= 9;
                srand((unsigned)time(NULL));
                direcao_blinky=rand()%4+1;

                ///atualizar();
            }
            else if(blinky=='I'||blinky=='P'||blinky=='K')
            {
                direcao_blinky = rand()%4+1;
            }
            direcao_blinky=0;
            direcao_blinky = rand()%4+1;
            ///atualizar();
        }
    }
    else if(_dir==4)
    {
        _homeY_blinky++;
        if(blinky!='X'&&blinky!='T'&&blinky!='-'&&blinky!='I'&&blinky!='P'&&blinky!='K'){
            blinky=ghost;
            mapGhost[_homeX_blinky][_homeY_blinky-1]=' ';
            mov_blinky_x+=9.0;
            ///atualizar();
        }

        else
        {
            if(blinky=='T')
            {
                blinky=ghost;
                mapGhost[_homeX_blinky][_homeY_blinky-1]='T';
                mov_blinky_x+=9.0;
                srand((unsigned)time(NULL));
                direcao_blinky=rand()%4+1;

                ///atualizar();
            }
            else if(blinky=='I'||blinky=='P'||blinky=='K')
            {
                direcao_blinky = rand()%4+1;
            }
            direcao_blinky=0;
            direcao_blinky = rand()%4+1;
            ///atualizar();
        }
    }
}
void mov_ghost_inky_jogo(int passo)
{
    encontra_ghost_inky(GHOST[1]);
    switch(direcao_inky)//up
    {
        case 1:
            moveX_ghost_inky(1,GHOST[1]);
            break;
        case 2://down
            moveX_ghost_inky(2,GHOST[1]);
            break;
        case 3://left
            moveY_ghost_inky(3,GHOST[1]);
            break;
        case 4://Right
            moveY_ghost_inky(4,GHOST[1]);
            break;
    }

    glutPostRedisplay();
    glutTimerFunc(50,mov_ghost_inky_jogo,1);
    //}
}
void moveX_ghost_inky(int _dir,char ghost)
{
if(_dir==1)
    {
        _homeX_inky++;
        if( inky!='X'&& inky!='T'&& inky!='B'&& inky!='P'&& inky!='K'){

            inky=ghost;
            mapGhost[_homeX_inky-1][_homeY_inky]= ' ';
            mov_inky_y+= 7.5;
            ///atualizar();
        }
        else
        {
            if(inky=='T')
            {
                inky=ghost;
                mapGhost[_homeX_inky-1][_homeY_inky]= 'T';
                mov_inky_y+= 7.5;
                srand((unsigned)time(NULL));
                direcao_inky=rand()%4+1;

                ///atualizar();
            }
            else if(inky=='I'||inky=='P'||inky=='K')
            {
                direcao_inky = rand()%4+1;
            }
            direcao_inky=0;
            direcao_inky = rand()%4+1;
            ///atualizar();
        }
    }
    else if(_dir==2)
    {
        _homeX_inky--;
        if(inky!='X'&&inky!='T'&&inky!='-'&&inky!='B'&&inky!='P'&&inky!='K'){
            inky=ghost;
            mapGhost[_homeX_inky+1][_homeY_inky]=' ';
            mov_inky_y-= 7.5;
            ///atualizar();
        }
        else
        {
            if(inky=='T')
            {
                inky=ghost;
                mapGhost[_homeX_inky+1][_homeY_inky]='T';
                mov_inky_y-= 7.5;
                srand((unsigned)time(NULL));
                direcao_inky=rand()%4+1;

                ///atualizar();
            }
            else if(inky=='B'||inky=='P'||inky=='K')
            {
                direcao_inky = rand()%4+1;
            }
            direcao_inky=0;
            direcao_inky = rand()%4+1;
            ///atualizar();
        }
    }
}
void moveY_ghost_inky(int _dir,char ghost)
{
    if(_dir==3)
    {
        _homeY_inky--;
        if(inky!='X'&&inky!='T'&&inky!='-'&&inky!='B'&&inky!='P'&&inky!='K'){
            inky=ghost;
            mapGhost[_homeX_inky][_homeY_inky+1]= ' ';
            mov_inky_x-= 9;
            ///atualizar();
        }
        else
        {
            if(inky=='T')
            {
                inky=ghost;
                mapGhost[_homeX_inky][_homeY_inky+1]= 'T';
                mov_inky_x-= 9;
                srand((unsigned)time(NULL));
                direcao_inky=rand()%4+1;

                ///atualizar();
            }
            else if(inky=='B'||inky=='P'||inky=='K')
            {
                direcao_inky = rand()%4+1;
            }
            direcao_inky=0;
            direcao_inky = rand()%4+1;
            ///atualizar();
        }
    }
    else if(_dir==4)
    {
        _homeY_inky++;
        if(inky!='X'&&inky!='T'&&inky!='-'&&inky!='B'&&inky!='P'&&inky!='K'){
            inky=ghost;
            mapGhost[_homeX_inky][_homeY_inky-1]=' ';
            mov_inky_x+=9.0;
            ///atualizar();
        }

        else
        {
            if(inky=='T')
            {
                inky=ghost;
                mapGhost[_homeX_inky][_homeY_inky-1]='T';
                mov_inky_x+=9.0;
                srand((unsigned)time(NULL));
                direcao_inky=rand()%4+1;

                ///atualizar();
            }
            else if(inky=='B'||inky=='P'||inky=='K')
            {
                direcao_inky = rand()%4+1;
            }
            direcao_inky=0;
            direcao_inky = rand()%4+1;
            ///atualizar();
        }
    }
}
void mov_ghost_pinky_jogo(int passo)
{
    encontra_ghost_pinky(GHOST[2]);
    switch(direcao_pinky)//up
    {
        case 1:
            moveX_ghost_pinky(1,GHOST[2]);
            break;
        case 2://down
            moveX_ghost_pinky(2,GHOST[2]);
            break;
        case 3://left
            moveY_ghost_pinky(3,GHOST[2]);
            break;
        case 4://Right
            moveY_ghost_pinky(4,GHOST[2]);
            break;
    }

    glutPostRedisplay();
    glutTimerFunc(50,mov_ghost_pinky_jogo,1);
    //}
}
void moveX_ghost_pinky(int _dir,char ghost)
{
if(_dir==1)
    {
        _homeX_pinky++;
        if(pinky!='X'&&pinky!='T'&&pinky!='I'&&pinky!='B'&&pinky!='K'){

            pinky=ghost;
            mapGhost[_homeX_pinky-1][_homeY_pinky]= ' ';
            mov_pinky_y+= 7.5;
            ///atualizar();
        }
        else
        {
            if(pinky=='T')
            {
                pinky=ghost;
                mapGhost[_homeX_pinky-1][_homeY_pinky]= 'T';
                mov_pinky_y+= 7.5;
                srand((unsigned)time(NULL));
                direcao_pinky=rand()%4+1;

                ///atualizar();
            }
            else if(pinky=='I'||pinky=='B'||pinky=='K')
            {
                direcao_pinky = rand()%4+1;
            }
            direcao_pinky=0;
            direcao_pinky = rand()%4+1;
            ///atualizar();
        }
    }
    else if(_dir==2)
    {
        _homeX_pinky--;
        if(pinky!='X'&&pinky!='T'&&pinky!='-'&&pinky!='I'&&pinky!='B'&&pinky!='K'){
            pinky=ghost;
            mapGhost[_homeX_pinky+1][_homeY_pinky]=' ';
            mov_pinky_y-= 7.5;
            ///atualizar();
        }
        else
        {
            if(pinky=='T')
            {
                pinky=ghost;
                mapGhost[_homeX_pinky+1][_homeY_pinky]='T';
                mov_pinky_y-= 7.5;
                srand((unsigned)time(NULL));
                direcao_pinky=rand()%4+1;

                ///atualizar();
            }
            else if(pinky=='I'||pinky=='B'||pinky=='K')
            {
                direcao_pinky = rand()%4+1;
            }
            direcao_pinky=0;
            direcao_pinky = rand()%4+1;
            ///atualizar();
        }
    }
}
void moveY_ghost_pinky(int _dir,char ghost)
{
    if(_dir==3)
    {
        _homeY_pinky--;
        if(pinky!='X'&&pinky!='T'&&pinky!='-'&&pinky!='I'&&pinky!='B'&&pinky!='K'){
            pinky=ghost;
            mapGhost[_homeX_pinky][_homeY_pinky+1]= ' ';
            mov_pinky_x-= 9;
            ///atualizar();
        }
        else
        {
            if(pinky=='T')
            {
                pinky=ghost;
                mapGhost[_homeX_pinky][_homeY_pinky+1]= 'T';
                mov_pinky_x-= 9;
                srand((unsigned)time(NULL));
                direcao_pinky=rand()%4+1;

                ///atualizar();
            }
            else if(pinky=='I'||pinky=='B'||pinky=='K')
            {
                direcao_pinky = rand()%4+1;
            }
            direcao_pinky=0;
            direcao_pinky = rand()%4+1;
            ///atualizar();
        }
    }
    else if(_dir==4)
    {
        _homeY_pinky++;
        if(pinky!='X'&&pinky!='T'&&pinky!='-'&&pinky!='I'&&pinky!='B'&&pinky!='K'){
            pinky=ghost;
            mapGhost[_homeX_pinky][_homeY_pinky-1]=' ';
            mov_pinky_x+=9.0;
            ///atualizar();
        }

        else
        {
            if(pinky=='T')
            {
                pinky=ghost;
                mapGhost[_homeX_pinky][_homeY_pinky-1]='T';
                mov_pinky_x+=9.0;
                srand((unsigned)time(NULL));
                direcao_pinky=rand()%4+1;

                ///atualizar();
            }
            else if(pinky=='I'||pinky=='B'||pinky=='K')
            {
                direcao_pinky = rand()%4+1;
            }
            direcao_pinky=0;
            direcao_pinky = rand()%4+1;
            ///atualizar();
        }
    }
}
void mov_ghost_clyde_jogo(int passo)
{
    encontra_ghost_clyde(GHOST[3]);
    switch(direcao_clyde)//up
    {
        case 1:
            moveX_ghost_clyde(1,GHOST[3]);
            break;
        case 2://down
            moveX_ghost_clyde(2,GHOST[3]);
            break;
        case 3://left
            moveY_ghost_clyde(3,GHOST[3]);
            break;
        case 4://Right
            moveY_ghost_clyde(4,GHOST[3]);
            break;
    }

    glutPostRedisplay();
    glutTimerFunc(50,mov_ghost_clyde_jogo,1);
    //}
}
void moveX_ghost_clyde(int _dir,char ghost)
{
if(_dir==1)
    {
        _homeX_clyde++;
        if(clyde!='X'&&clyde!='T'&&clyde!='I'&&clyde!='P'&&clyde!='B'){

            clyde=ghost;
            mapGhost[_homeX_clyde-1][_homeY_clyde]= ' ';
            mov_clyde_y+= 7.5;
            ///atualizar();
        }
        else
        {
            if(clyde=='T')
            {
                clyde=ghost;
                mapGhost[_homeX_clyde-1][_homeY_clyde]= 'T';
                mov_clyde_y+= 7.5;
                srand((unsigned)time(NULL));
                direcao_clyde=rand()%4+1;

                ///atualizar();
            }
            else if(clyde=='I'||clyde=='P'||clyde=='B')
            {
                direcao_clyde = rand()%4+1;
            }
            direcao_clyde=0;
            direcao_clyde = rand()%4+1;
            ///atualizar();
        }
    }
    else if(_dir==2)
    {
        _homeX_clyde--;
        if(clyde!='X'&&clyde!='T'&&clyde!='-'&&clyde!='I'&&clyde!='P'&&clyde!='B'){
            clyde=ghost;
            mapGhost[_homeX_clyde+1][_homeY_clyde]=' ';
            mov_clyde_y-= 7.5;
            ///atualizar();
        }
        else
        {
            if(clyde=='T')
            {
                clyde=ghost;
                mapGhost[_homeX_clyde+1][_homeY_clyde]='T';
                mov_clyde_y-= 7.5;
                srand((unsigned)time(NULL));
                direcao_clyde=rand()%4+1;

                ///atualizar();
            }
            else if(clyde=='I'||clyde=='P'||clyde=='B')
            {
                direcao_clyde = rand()%4+1;
            }
            direcao_clyde=0;
            direcao_clyde = rand()%4+1;
            ///atualizar();
        }
    }
}
void moveY_ghost_clyde(int _dir,char ghost)
{
    if(_dir==3)
    {
        _homeY_clyde--;
        if(clyde!='X'&&clyde!='T'&&clyde!='-'&&clyde!='I'&&clyde!='P'&&clyde!='B'){
            clyde=ghost;
            mapGhost[_homeX_clyde][_homeY_clyde+1]= ' ';
            mov_clyde_x-= 9;
            ///atualizar();
        }
        else
        {
            if(clyde=='T')
            {
                clyde=ghost;
                mapGhost[_homeX_clyde][_homeY_clyde+1]= 'T';
                mov_clyde_x-= 9;
                srand((unsigned)time(NULL));
                direcao_clyde=rand()%4+1;

                ///atualizar();
            }
            else if(clyde=='I'||clyde=='P'||clyde=='B')
            {
                direcao_clyde = rand()%4+1;
            }
            direcao_clyde=0;
            direcao_clyde = rand()%4+1;
            ///atualizar();
        }
    }
    else if(_dir==4)
    {
        _homeY_clyde++;
        if(clyde!='X'&&clyde!='T'&&clyde!='-'&&clyde!='I'&&clyde!='P'&&clyde!='B'){
            clyde=ghost;
            mapGhost[_homeX_clyde][_homeY_clyde-1]=' ';
            mov_clyde_x+=9.0;
            ///atualizar();
        }

        else
        {
            if(clyde=='T')
            {
                clyde=ghost;
                mapGhost[_homeX_clyde][_homeY_clyde-1]='T';
                mov_clyde_x+=9.0;
                srand((unsigned)time(NULL));
                direcao_clyde=rand()%4+1;

                ///atualizar();
            }
            else if(clyde=='I'||clyde=='P'||clyde=='B')
            {
                direcao_clyde = rand()%4+1;
            }
            direcao_clyde=0;
            direcao_clyde = rand()%4+1;
            ///atualizar();
        }
    }
}
void encontra_ghost_blinky(char ghost)
{
    for(x=0;x<LIN;x++)
    {
        for(y=0;y<COL;y++)
        {
            if(mapGhost[x][y]==ghost)
            {
                _homeX_blinky=x;
                _homeY_blinky=y;
            }
        }
    }
}
void encontra_ghost_inky(char ghost)
{
    for(x=0;x<LIN;x++)
    {
        for(y=0;y<COL;y++)
        {
            if(mapGhost[x][y]==ghost)
            {
                _homeX_inky=x;
                _homeY_inky=y;
            }
        }
    }
}
void encontra_ghost_pinky(char ghost)
{
    for(x=0;x<LIN;x++)
    {
        for(y=0;y<COL;y++)
        {
            if(mapGhost[x][y]==ghost)
            {
                _homeX_pinky=x;
                _homeY_pinky=y;
            }
        }
    }
}
void encontra_ghost_clyde(char ghost)
{
    for(x=0;x<LIN;x++)
    {
        for(y=0;y<COL;y++)
        {
            if(mapGhost[x][y]==ghost)
            {
                _homeX_clyde=x;
                _homeY_clyde=y;
            }
        }
    }
}
void ghost_BLINKY(int X ,int Y)
{
    glPointSize(5);
    glLineWidth(1);

    glBegin(GL_POLYGON);
        glVertex2d(209+mov_blinky_x+X,156+mov_blinky_y+Y);///21
        glVertex2d(206+mov_blinky_x+X,155+mov_blinky_y+Y);
        glVertex2d(204+mov_blinky_x+X,152+mov_blinky_y+Y);
        glVertex2d(204+mov_blinky_x+X,146+mov_blinky_y+Y);
        glVertex2d(207+mov_blinky_x+X,148+mov_blinky_y+Y);
        glVertex2d(209+mov_blinky_x+X,146+mov_blinky_y+Y);
        glVertex2d(211+mov_blinky_x+X,148+mov_blinky_y+Y);///
        glVertex2d(214+mov_blinky_x+X,146+mov_blinky_y+Y);
        glVertex2d(214+mov_blinky_x+X,152+mov_blinky_y+Y);
        glVertex2d(212+mov_blinky_x+X,155+mov_blinky_y+Y);
    glEnd();
    glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex2d(207+mov_blinky_x+X,152+mov_blinky_y+Y);
        glVertex2d(211+mov_blinky_x+X,152+mov_blinky_y+Y);
    glEnd();
    glFlush();

}
void ghost_INKY(int X ,int Y)
{
    glPointSize(5);
    glLineWidth(1);

    glBegin(GL_POLYGON);
        glVertex2d(209+mov_inky_x+X,156+mov_inky_y+Y);///21
        glVertex2d(206+mov_inky_x+X,155+mov_inky_y+Y);
        glVertex2d(204+mov_inky_x+X,152+mov_inky_y+Y);
        glVertex2d(204+mov_inky_x+X,146+mov_inky_y+Y);
        glVertex2d(207+mov_inky_x+X,148+mov_inky_y+Y);
        glVertex2d(209+mov_inky_x+X,146+mov_inky_y+Y);
        glVertex2d(211+mov_inky_x+X,148+mov_inky_y+Y);///
        glVertex2d(214+mov_inky_x+X,146+mov_inky_y+Y);
        glVertex2d(214+mov_inky_x+X,152+mov_inky_y+Y);
        glVertex2d(212+mov_inky_x+X,155+mov_inky_y+Y);
    glEnd();
    glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex2d(207+mov_inky_x+X,152+mov_inky_y+Y);
        glVertex2d(211+mov_inky_x+X,152+mov_inky_y+Y);
    glEnd();
    glFlush();

}
void ghost_PINKY(int X ,int Y)
{
    glPointSize(5);
    glLineWidth(1);

    glBegin(GL_POLYGON);
        glVertex2d(209+mov_pinky_x+X,156+mov_pinky_y+Y);///21
        glVertex2d(206+mov_pinky_x+X,155+mov_pinky_y+Y);
        glVertex2d(204+mov_pinky_x+X,152+mov_pinky_y+Y);
        glVertex2d(204+mov_pinky_x+X,146+mov_pinky_y+Y);
        glVertex2d(207+mov_pinky_x+X,148+mov_pinky_y+Y);
        glVertex2d(209+mov_pinky_x+X,146+mov_pinky_y+Y);
        glVertex2d(211+mov_pinky_x+X,148+mov_pinky_y+Y);///
        glVertex2d(214+mov_pinky_x+X,146+mov_pinky_y+Y);
        glVertex2d(214+mov_pinky_x+X,152+mov_pinky_y+Y);
        glVertex2d(212+mov_pinky_x+X,155+mov_pinky_y+Y);
    glEnd();
    glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex2d(207+mov_pinky_x+X,152+mov_pinky_y+Y);
        glVertex2d(211+mov_pinky_x+X,152+mov_pinky_y+Y);
    glEnd();
    glFlush();

}
void ghost_CLYDE(int X ,int Y)
{
    glPointSize(5);
    glLineWidth(1);

    glBegin(GL_POLYGON);
        glVertex2d(209+mov_clyde_x+X,156+mov_clyde_y+Y);///21
        glVertex2d(206+mov_clyde_x+X,155+mov_clyde_y+Y);
        glVertex2d(204+mov_clyde_x+X,152+mov_clyde_y+Y);
        glVertex2d(204+mov_clyde_x+X,146+mov_clyde_y+Y);
        glVertex2d(207+mov_clyde_x+X,148+mov_clyde_y+Y);
        glVertex2d(209+mov_clyde_x+X,146+mov_clyde_y+Y);
        glVertex2d(211+mov_clyde_x+X,148+mov_clyde_y+Y);///
        glVertex2d(214+mov_clyde_x+X,146+mov_clyde_y+Y);
        glVertex2d(214+mov_clyde_x+X,152+mov_clyde_y+Y);
        glVertex2d(212+mov_clyde_x+X,155+mov_clyde_y+Y);
    glEnd();
    glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex2d(207+mov_clyde_x+X,152+mov_clyde_y+Y);
        glVertex2d(211+mov_clyde_x+X,152+mov_clyde_y+Y);
    glEnd();
    glFlush();

}
void ghost_abertura(int soma)
{
    glPointSize(6);
    glLineWidth(1);
    glBegin(GL_POLYGON);
        glVertex2d(7+soma+mov_ghost,138);
        glVertex2d(2+soma+mov_ghost,137);
        glVertex2d(0+soma+mov_ghost,135);
        glVertex2d(0+soma+mov_ghost,125);
        glVertex2d(3+soma+mov_ghost,128);
        glVertex2d(5+soma+mov_ghost,125);
        glVertex2d(7+soma+mov_ghost,128);
        glVertex2d(9+soma+mov_ghost,125);
        glVertex2d(11+soma+mov_ghost,128);
        glVertex2d(14+soma+mov_ghost,125);
        glVertex2d(14+soma+mov_ghost,125);
        glVertex2d(14+soma+mov_ghost,135);
        glVertex2d(12+soma+mov_ghost,137);
    glEnd();
    glBegin(GL_POINTS);
        glColor3b(0,0,0);
        glVertex2d(4+soma+mov_ghost,133);
        glVertex2d(10+soma+mov_ghost,133);
    glEnd();
    glFlush();
}

void mov_fantasma(int passo)
{
    esc = 0;
    if(direcao_abertura==1)
    {
        mov_ghost+= 1;
        if(mov_ghost==148) direcao_abertura = 0;

    }
    else
    {
        mov_ghost-= 1;
        if(mov_ghost==-90) direcao_abertura = 1;
        esc = 1;
    }
    glutPostRedisplay();
    glutTimerFunc(20,mov_fantasma,1);
}
