//Rotation of Primitive
//For mac

#include <iostream>
#include <cstdlib>
#include <GLUT/glut.h>
#include <cmath>

using namespace std;

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glutSolidTeapot(2.0);
    glFlush();
}

void init(){
    glViewport(0, 0, 500, 500);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-30.0, 30.0, -30.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(0.5, 0.5, 1.0);
    glClearColor(1.0, 1.0, 1.0, 0.0);
}

void myKey(unsigned char key,int x,int y){
    switch(key){
        case 'l'://left
            glTranslatef(-2.0, 0.0, 0.0);
            break;
        case 'r'://right
            glTranslatef(2.0, 0.0, 0.0);
            break;
        case 'u'://up
            glTranslatef(0.0, 2.0, 0.0);
            break;
        case 'd'://down
            glTranslatef(0.0, -2.0, 0.0);
            break;
        case 'i'://increase size
            glScalef(1.5,1.5,1.5);
            break;
        case 'D'://decrease size
            glScalef(-0.5, -0.5, -0.5);
            break;
        case 'R'://rotate right
            glRotatef(10.0,1.0,1.0,0.0);
            break;
        case 'L'://rotate left
            glRotatef(-10.0, 1.0, 0.0, 0.0);
            break;
    }
    glutPostRedisplay();
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutCreateWindow("Transformation with API'S");
    glutDisplayFunc(display);
    glutKeyboardFunc(myKey);
    init();
    glutMainLoop();
    return 0;
}
