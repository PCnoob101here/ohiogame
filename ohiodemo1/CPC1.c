//the crossplatform code
#ifdef WIN_32
#include <gl/gl.h>
#else
#include <GL/gl.h>
#endif
#include "afnames1.h"

GLfloat playerspeed;
GLfloat afPlayerMove[2];
unsigned char *afPlayerData
/*
char hp
4 bit action
4 bit animation frame
float[2] xy position
*/

char afMoveFlags;//tracks key states up left down right escape

unsigned char afNpcCount;
unsigned char *afPassiveNpcData;
/*
char npc id
char npc type
4 bit bahavior mode
4 bit animation frame
float[2] xy position
*/
unsigned char *afActiveNpcData;
/*
char npc id
7 bit npc type
1 bit direction facing (1 is right)
char hp
4 bit action
4 bit animation frame
float[2] xy position
*/

void afMakeDispLists()
{
    GLfloat verts[] = {
    //test cubes
    0.05f, 0.05f,
    0.05f, -0.05f,
    -0.05f, -0.05f,
    -0.05f, 0.05f,
    //furry head main fur
    0.0f, -0.03f,
    -0.05f, -0.02f,
    -0.05f, 0.01f,
    -0.03f, 0.03f,
    -0.025f, 0.04f,
    0.025f, 0.04f,
    //witefluf NOTE:shares coords with main head fur
    -0.02f, -0.026f,
    -0.025f, -0.036,
    0.025f, -0.036,
    0.02f, -0.026f,
    //furear
    0.025f,
    //deodorant
    0.0
    };
    GLbyte afMidGeom[][] =
    {4,8,9},
    {10,11,5},
    {},
    ;
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, verts);
    glNewList(afTestCube,GL_COMPILE);//test cube
    glDrawArrays(GL_QUADS,0,4);
    glEndList();
    glNewList(afFillRender,GL_COMPILE);//take up whole render space
    glRectf(-1.0f,-1.0f,1.0f,1.0f);
    glEndList();
    glNewList(afButton,GL_COMPILE);//ui button off
    //button outline
    glColor3f(0.0f,0.4f,0.0f);
    glRectf(-0.3f,-0.1f,0.3f,0.1f);
    //gradient button part
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.8f,1.0f,0.8f);
    glVertex2f(-0.28f, 0.08f); glVertex2f(0.28f,0.08f);
    glColor3f(0.6f,1.0f,0.6f);
    glVertex2f(-0.28f,0.02f); glVertex2f(0.28f,0.02f);
    glColor3f(0.0f,0.5f,0.0f);
    glVertex2f(-0.28f,-0.02f); glVertex2f(0.28f,-0.02f);
    glColor3f(0.0f,0.2f,0.0f);
    glVertex2f(-0.28f,-0.08f); glVertex2f(0.28f,-0.08f);
    glEnd();
    glEndList();
    glNewList();//ui button off
    glPushMatrix();
    glScalef(0.0f,1.0f,0.0f);
    glCallList();
    glPopMatrix();
    glEndList();
    glEndList();
    glNewList(afInvertX,GL_COMPILE);//start invert on x
    glPushMatrix();
    glScalef(-1.0f,1.0f,1.0f);
    glEndList();
    glNewList(5,GL_COMPILE);//furryhead
    glDrawArrays(GL_TRIANGLE_FAN,4,5);
    glDrawElements(GL_TRIANGLES,3,GL_UNSIGNED_BYTE,afMidGeom[0]);
    glCallList(3);
    glDrawArrays(GL_TRIANGLE_FAN,4,5);
    glPopMatrix();
    //now white part
    glColor3b(1.0f,1.0f,1.0f);
    glDrawElements(GL_TRIANGLES,3,GL_UNSIGNED_BYTE,afMidGeom[1]);
    glDrawArrays(GL_QUADS,10,4);
    glCallList(3);
    glDrawElements(GL_TRIANGLES,3,GL_UNSIGNED_BYTE,afMidGeom[1]);
    glPopMatrix();
    glEndList();
    glNewList(6,GL_COMPILE);//furear
    glDrawArrays(GL_TRIANGLE_FAN,);
    glColor4f(0.0f,0.0f,0.0f,0.5f);
    glDrawArrays(GL_QUAD_STRIP,);
    glDrawArrays(GL_TRIANGLE_FAN);
    glEndList();
    glNewList(,GL_COMPILE);//deodorant spray
    glColor3f(0.8f,0.8f,0.8f);
    glRectf();
    glColor3f(1.0f,1.0f,1.0f);
    glRectf();
    glColor3f(1.0f,0.0f,0.0f);
    glRectf();

    glFinish();
}
void afdeterminedirection()
void afDrawFurry(*void description/*pointer to npcs data*/)//draw furry function
{
    GLfloat color[3];
    //set the furrys color based on noc type
    switch((description + 1) & 127)
    case AF_GREY_FURRY:
    color = (0.65f,0.65f,0.65f);
    break:
    case AF_CYAN_FURRY:
    color = (0.8f, 1.0f,0.8f);
    break:
    case AF_ORANGE_FURRY:
    color = (1.0f,0.6f,0.0f);
    break:
    case AF_PINK_FURRY:
    color = (1.0f,0.8f,0.8f);
    break:
    case AF_GREEN_FURRY:
    color = (0.0f,1.0f,0.0f);
    break:
    //check if furry facing 180 other way
    if((*(description + 1)) & 128)glCallList(afInvertX);
    glColor3fv(color);
    glPushMatrix();
    
    glCallList();
    //nek furry di invert invert gets poped
    if((*(description + 1)) & 128)glCallList(afInvertX); glPopMatrix();
}:

void afRoomSetup()//call to setup level
{

    afActiveNpcData = malloc(afNpcCount * 12);
    unsigned char afNpcsSpawned = 0;
    while(afNpcCount - afNpcsSpawned)//create npcs data
    {

    }
}

void afRoomCleanup()//after level is completed or its context not needed
{
    free(afActiveNpcData);
    afNpcCount = 0;
}
void afCleanUp()//save data when being closed
{

}
void afMainMenu()//render main menu
{
    glColor4f(0.0f,0.0f,0.0f,0.5f);
    glCallList(afRFillRender);
    for()
    {
        glPushMatrix();
        glTranslatef();
        glCallList();
        glPopMatrix();
    }
}

void afDrawGame()
{
    if(afMoveFlags & 1 == 1) *(afPlayerData + 2) = *(afPlayerData + 2) - 0.1f;
    if((afMoveFlags & 2) == 2) *(afPlayerData + 6) = *(afPlayerData + 6) + 0.1f;
    if((afMoveFlags & 4) == 4) *(afPlayerData + 2) = *(afPlayerData + 2) + 0.1f;
    if((afMoveFlags & 8) == 8) *(afPlayerData + 6) = *(afPlayerData + 6) - 0.1f;
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //draw npcs
    for(int npc = afNpcCount; npc > 0; npc - 1)
    {
        
    }
    //check collisions
        
    glPushMatrix();
    glTranslatef(*(afPlayerData + 6),*(afPlayerData + 2), 0.0f);
    //world around player
    glCallList(2);
    glPopMatrix();
    //player model
    glCallList(1);
    //check if esc pressed
    if((afMoveFlags & 16) == 16) afMainMenu();

    glFinish();
}

