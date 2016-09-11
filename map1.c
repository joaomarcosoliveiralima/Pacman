#include "map.h"

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
