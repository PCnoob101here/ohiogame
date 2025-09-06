//stuff that would make sense to put as a dll
#include <GL/gl.h>
#include <spristnames.h>

void makdisplists()
{
    GLfloat gameverts[] = {
        ///main fur head
        //hidden vert
        0.0f, -0.3f,
        //up
        -1.4f, 0.01f,
        -1.0f, 0.13f,
        -0.5f, 0.15f,
        -0.3f, 0.16f,
        //down
        1.4f, 0.01f,
        1.0f, 0.13f,
        0.5f, 0.15f,
        0.3f, 0.16f,
        ///2 tiny furs
        -0.28f, 0.16f,
        0.02f, 0.16f,
        0.35f, 0.22f,
        
        ///checkbox
        ///button switch

        };
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, gameverts);
    glNewList(FURRY_HEAD_C, GL_COMPILE);
    //the vibrant colored part of the head
    glDrawArrays();
    //little detail
    glDrawArrays(GL_TRIANGLES, 9, 6);
    glEndList();
    glNewList(FURRY_HEAD_NC, GL_COMPILE);
    //white head part
    glColor3f(1.0f, 1.0f, 1.0f);
    glDrawArrays();
    //nose
    glColor3f(0.0f, 0.0f, 0.0f);
    glDrawArrays(GL_POLYGON);
    glEndList();
    glNewList(CHECKBOX_ON, GL_COMPILE);
    glColor3f(0.0f, 0.2f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(0.06f, 0.06f, -0.1f);
    glVertex3f(-0.06f, 0.06f, -0.1f);
    glVertex3f(-0.06f, -0.06f, -0.1f);
    glVertex3f(0.06f, -0.06f, -0.1f);
    glColor3f(0.0f, 0.4f, 0.0f);
    glVertex3f(-0.05f, -0.05f, 0.05f);
    glVertex3f(0.05f, -0.05f, 0.5f);
    glColor3f(0.0f, 0.9f, 0.0f);
    glVertex3f(0.06f, 0.06f, 0.0f);
    glVertex3f(-0.06f, 0.06f, 0.0f);
    glEnd();
    glEndList();
    glNewList(CHECKBOX_OFF, GL_COMPILE);
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    glVertex3f(0.06f, 0.06f, -0.1f);
    glVertex3f(-0.06f, 0.06f, -0.1f);
    glVertex3f(-0.06f, -0.06f, -0.1f);
    glVertex3f(0.06f, -0.06f, -0.1f);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex3f(-0.05f, -0.05f, 0.05f);
    glVertex3f(0.05f, -0.05f, 0.5f);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex3f(0.06f, 0.06f, 0.0f);
    glVertex3f(-0.06f, 0.06f, 0.0f);
    glEnd();
    glEndList();
    glNewList();
}
