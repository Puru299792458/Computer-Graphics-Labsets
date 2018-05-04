//Scenery
//For mac

#include <iostream>
#include <GLUT/glut.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


    //-----------------------------------------------Tree---------------------------------------------------------------------
    glColor3f(0.5, 0.35, 0.05);
    glPushMatrix();
    glTranslated(3.0,-1.4,-6);
    glScalef(0.55, 4.0, 0.55);
    glRotatef(320,1.0,0.0,0.0);
    glutSolidTorus(0.2,0.1,50,50);
    glPopMatrix();
    glColor3f(0, 1, 0);
    glPushMatrix();
    glTranslated(3.0,-1.1,-6);
    glRotatef(270,1.0,0.0,0.0);
    glutSolidCone(0.8,0.8,40,30);
    glPopMatrix();
    //-----------------------------------------------Tree---------------------------------------------------------------------

    //-------------------------------------------------Sun--------------------------------------------------------------------
    glColor3d(1.0,0.3,0.0);
    glPushMatrix();
    glTranslated(-0.7,1.0,-6);
    glScalef(2,2,2);
    glutSolidSphere(0.3,50,50);
    glPopMatrix();
    //-------------------------------------------------Sun-------------------------------------------------------------------

    //------------------------------------------------House-------------------------------------------------------------------
    glColor3f(0.5,1.0,0.0);
    glPushMatrix();
    glTranslated(-2.0,-1.5,-5);
    glutSolidCube(0.9);
    glPopMatrix();
    glColor3f(1.0,0.3,0.3);
    glPushMatrix();
    glTranslated(-2.0,-1.1,-5);
    glRotatef(270,1.0,0.0,0.0);
    glutSolidCone(0.8,0.8,40,30);
    glPopMatrix();
    glColor3f(1.0,0.0,1.0);
    glPushMatrix();
    glTranslated(-2.2,-1.8,-6);
    glutSolidTeapot(0.2);
    glPopMatrix();
    //-----------------------------------------------House-------------------------------------------------------------------

    //----------------------------------------------Clouds------------------------------------------------------------------
    glColor3f(0.0,0.5,0.6);
    glPushMatrix();
    glTranslated(1.0,2.3,-6);
    glRotatef(270,1.0,0.0,0.0);
    glutSolidCone(1,1.5,50,50);
    glPopMatrix();
    glPushMatrix();
    glTranslated(2.0,2.5,-6);
    glRotatef(270,1.0,0.0,0.0);
    glutSolidCone(1,1.5,50,50);
    glPopMatrix();
    glPushMatrix();
    glTranslated(3.0,2.3,-6);
    glRotatef(270,1.0,0.0,0.0);
    glutSolidCone(1,1.5,50,50);
    glPopMatrix();
    glPushMatrix();
    glTranslated(4.0,2.5,-6);
    glRotatef(270,1.0,0.0,0.0);
    glutSolidCone(1,1.5,50,50);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.0,2.3,-6);
    glRotatef(270,1.0,0.0,0.0);
    glutSolidCone(1,1.5,50,50);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-1.0,2.5,-6);
    glRotatef(270,1.0,0.0,0.0);
    glutSolidCone(1,1.5,50,50);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-2.0,2.3,-6);
    glRotatef(270,1.0,0.0,0.0);
    glutSolidCone(1,1.5,50,50);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-3.0,2.5,-6);
    glRotatef(270,1.0,0.0,0.0);
    glutSolidCone(1,1.5,50,50);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-4.0,2.3,-6);
    glRotatef(270,1.0,0.0,0.0);
    glutSolidCone(1,1.5,50,50);
    glPopMatrix();
    //-----------------------------------------------Clouds--------------------------------------------------------------

    //-----------------------------------------------Mountains--------------------------------------------------------
    glColor3f(0.5,0.5,0.5);
    glPushMatrix();
    glTranslated(-3.0,0.0,-6);
    glRotatef(270,0.5,0.0,0.0);
    glutSolidCone(1,1.5,50,50);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-1.5,0.0,-6);
    glRotatef(270,0.5,0.0,0.0);
    glutSolidCone(1,1.5,50,50);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.0,0.0,-6);
    glRotatef(270,0.5,0.0,0.0);
    glutSolidCone(1,1.5,50,50);
    glPopMatrix();
    glPushMatrix();
    glTranslated(1.5,0.0,-6);
    glRotatef(270,0.5,0.0,0.0);
    glutSolidCone(1,1.5,50,50);
    glPopMatrix();
    glPushMatrix();
    glTranslated(3.0,0.0,-6);
    glRotatef(270,0.5,0.0,0.0);
    glutSolidCone(1,1.5,50,50);
    glPopMatrix();
    //---------------------------------------------------------Mountains------------------------------------------------


    glutSwapBuffers();
}

void resize(int w,int h){
    const float ar=(float)w/(float)h;
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar,ar,-1.0,1.0,-2.0,2.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(640,500);
    glutInitWindowPosition(0.0,0.0);
    glutCreateWindow("Scenary");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glClearColor(1,1,1,1);
    glutMainLoop();
    return 0;
}
