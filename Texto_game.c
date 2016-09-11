#include "Hender.h"

void Desenha_ajuda()
{
int y1 =180,i;
char ajuda[1500]="Acho que este jogo dispensa comentarios, mas se voce vive\n"
                  "classico do arcade tambem popularizado nos PCs.\n"
                  "Pac-Man foi, com certeza, o jogo mais copiado, mais imitado,\n"
                  "mais popular da historia dos computadores: havia clones de\n"
                  "Pac-Man para para todos os video-games da epoca,\n"
                  "computadores, arcades. Diferentes versoes, todas centradas\n"
                  "na mesma simplicidade:\n"
                  "o personagem principal, o Pac-Man\n"
                  "(o famoso 'come come') deve comer as bolinhas do mapa e\n"
                  "fugir dos fantasmas, que possuem diferentes velocidades.\n"
                  "A mecanica do jogo e simples: o jogador era uma\n"
                  "cabeca redonda com uma boca que se abre e fecha,\n"
                  "posicionado em um labirinto simples repleto de pastilhas e 4\n"
                  "fantasmas que o perseguiam. O objetivo era comer todas as\n"
                  "pastilhas sem ser alcancado pelos fantasmas. Para ajudar Pac-Man,\n"
                  "algumas das bolinhas tornam os fantasmas vulneraveis,\n"
                  "fazendo com que o heroi amarelinho possa comer os fantasmas tambem.\n"
                  "em ritmo progressivo de dificuldade.\n"
                  "O usuario pode mover o pacman usando as teclas de navegacoes 'as setas',\n"
                  "pode-se sair do jogo usando a tecla escape 'esc'.\n";
// Posicao no universo onde o texto sera colocado
    glRasterPos2f(250,y1);
// Exibe caracter a caracter
    for(i=0;i<1500;i++)
        {
            if(ajuda[i]=='\n')
            glRasterPos2f(250,y1-=6);
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13,ajuda[i]);
        }
}
void Desenha_sobre()
{
int y1 =220,i=0;
char sobre[2500]="Pac-Man (conhecido em japones com o nome de Puckman e um jogo eletr�nico criado pela Tohru Iwatani\n"
                "para a empresa Namco ,e sendo distribuido para o mercado estadunidense pela Midway Games.\n"
                "Produzido originalmente para Arcade no inicio dos anos 1980, tornou-se um dos jogos mais populares\n"
                "no momento, tendo versoes para diversos consoles e continuacoes para tantos outros, inclusive na \n"
                "atualidade.Atualmente existem versoes em 3 dimensoes,outras em estilo 'adventure',\n"
                "sempre remontando ao personagem redondo e faminto do jogo original e seus perseguidores fantasmas.\n"
                "historia do jogo:Em 1980, Toru Iwatani ,um designer da Namco, queria inventar um jogo de video\n"
                "diferente dos 'shoot-em-ups ' (tiro-neles),que se assemelhasse a um desenho-animado.\n"
                "A ideia do desenho original ocorreu durante um jantar com amigos, e deve-se a uma pizza sem uma fatia,\n"
                "que fazia lembrar uma boca aberta;assim tem origem uma personagem inspirada em Paku , uma personagem\n"
                "popular no japao conhecido pelo seu apetite. A personagem e jogo tiveram o nome Puck-Man , do termo\n"
                "JaponeRRs paku-paku , que significa a boca de alguem a abrir-se e fechar-se. Em 1980, a Bally comprou\n"
                "os direitos nos Estados Unidos o jogo tornou-se famoso no ano seguinte. No jogo os jogadores\n"
                "controlam puckman, com o objectivo de comer todas as bolas (ou pastilhas) que se encontram espalhadas\n"
                "num labirinto, enquanto evitam quatro fantasmas (os Galaxians ), 'blinky', 'pinky', 'inky' e 'clyde',\n"
                "que se escapam de uma prisao. Em cada canto da area de jogo, estao pastilhas maiores que permitem\n"
                "pac-man cacar os fantasmas,em vez de ser cacado, durante um curto periodo de tempo.\n"
                "O nome foi alterado para Pac-Man , desencorajando a alteracao da letra 'p' por 'f' (um calao na lingua\n"
                "inglesa).O jogo foi um dos mais populares.Pac-Man (serie animada):De 1982 a 1984, a Hannah-Barbera\n"
                "produziu uma serie animada baseada em Pac-Man, que chegou a ser exibida no Brasil pela Bandeirantes\n"
                "em 1987 (programa ZYB Bom) e recentemente, no Sabado Animado pelo SBT . A serie ao ser\n"
                "adaptada para o Brasil, verteu o nome de Pac-Man para 'Comilao' e usa um chapeu referente de\n"
                "'Indiana Jones'.A serie tratava das desventuras de Pac-Man e sua familia (mulher, filho, cao e gato,\n"
                "todos criaturas de forma esferica).\n"
                "Recorde Mundial:\n"
                "Billy Mitchell e o detentor do recorde mundial do Pac-Man.\n"
                "Essa vercao do pacman foi desenvolvida por Joao Marcos Oliveira lima.\n"
                "Academico do curso de engenharia de computacao Na UFGD-FACET\n";
// Posicao no universo onde o texto sera colocado
    glRasterPos2f(250,y1);
// Exibe caracter a caracter
    for(i=0;i<2500;i++)
        {
            if(sobre[i]=='\n')
                glRasterPos2f(250,y1-=8);
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,sobre[i]);
        }
}
