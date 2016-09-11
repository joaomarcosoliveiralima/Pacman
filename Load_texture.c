#include "Load_texture.h"

int  LoadBMP(char *filename)
 {
    #define SAIR        {fclose(fp_arquivo); return -1;}
    #define CTOI(C)     (*(int*)&C)

    GLubyte     *image;
    GLubyte     Header[0x54];
    GLuint      DataPos, imageSize;
    GLsizei     Width,Height;


    // Abre o arquivo e efetua a leitura do Header do arquivo BMP
    FILE * fp_arquivo = fopen(filename,"rb");
    if (fp_arquivo==NULL)
        exit(1);
    if (fread(Header,1,0x36,fp_arquivo)!=0x36)
        SAIR;
    if (Header[0]!='B' || Header[1]!='M')
        SAIR;
    if (CTOI(Header[0x1E])!=0)
        SAIR;
    if (CTOI(Header[0x1C])!=24)
        SAIR;

    // Recupera a informa��o dos atributos de
    // altura e largura da imagem

    Width   = CTOI(Header[0x12]);
    Height  = CTOI(Header[0x16]);
    ( CTOI(Header[0x0A]) == 0 ) ? ( DataPos=0x36 ) : ( DataPos = CTOI(Header[0x0A]) );

    imageSize=Width*Height*3;

    // Efetura a Carga da Imagem
    image = (GLubyte *) malloc ( imageSize );
    int retorno;
    retorno = fread(image,1,imageSize,fp_arquivo);

    if (retorno !=imageSize)
     {
        free (image);
        SAIR;
     }

    // Inverte os valores de R e B
    int t, i;

    for ( i = 0; i < imageSize; i += 3 )
     {
        t = image[i];
        image[i] = image[i+2];
        image[i+2] = t;
     }

    // Tratamento da textura para o OpenGL

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);


    // Faz a gera�ao da textura na mem�ria
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Width, Height, 0, GL_RGB, GL_UNSIGNED_BYTE,image);

    fclose (fp_arquivo);
    free (image);
    return 1;
 }

void printTexture(char nomeimag[15])
{
    glEnable (GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D,texture_id[1]);
    LoadBMP (nomeimag);

    glBindTexture ( GL_TEXTURE_2D, texture_id[1] );

    glLineWidth(3);
	glBegin ( GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex2f(0, 0);
		glTexCoord2f(1.0f, 0.0f); glVertex2f( 300, 0);
		glTexCoord2f(1.0f, 1.0f); glVertex2f( 300,290);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(0,290);

	glEnd();
    glDisable(GL_TEXTURE_2D);
    glFlush();
 // Executa os comandos
}

