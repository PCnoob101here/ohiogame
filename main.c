//i wanted to make an app made solely by antifurries, thats what this is
#include <stdio.h>
#include <stdlib.h>
#include <glut.h>

char theme[];
char *uidata[12];
/*
1 ver
2 bordrrgb
3 bckrndrgb
4 btn0pnts
5 btn0rgb
6 btn1pnts
7 btn1rgb
8 slidr0pnts
9 slidr0rgb
10 slidr1pnts
11 slidr1rgb
12 comboxpnts
13 comboxrgb
----
amnt mix
r g b cords
*/

void getheme(){
FILE *fl = fopen(theme, "r+");
if(fl = NULL)
{
    return 0;
}
char head = 0;
char step = 0;
while(step == )
{
    fseek(fl, head, SEEK_SET);
    switch(step)
    {
        case 0: head = 1;
                step = 1;
                break;
        case 1: calloc()
    }
}
fclose(fl);
return 0;
}

void scene(){
    glbegin();
    glend();
}

int main()
{
    glutInit(&argc, argv);
    glutCreateWindow("madebyantifurs");
    glutInitWindowSize(CW_USEDEFAULT, CW_USEDEFAULT);
    glutInitWindowPosition(1, 1);
    glutInitDisplayMode(GLUT_RGBA);
    glutMainLoop();
}
