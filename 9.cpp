//Rotaion of Cube about the axis
//For mac

#include <iostream>
#include <GLUT/glut.h>

using namespace std;

double rotate_x=0.0;
double rotate_y=0.0;

void display(){
    //clear Screen and Z buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    //reset transformations
    glLoadIdentity();
    //rotate when user changes rotate_x and rotate_y
    glRotatef(rotate_x,0.5, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 0.5, 0.0);
    //multicolored side-FRONT
    glBegin(GL_POLYGON);
    glColor3f(0.2,0.5,0.8);
    glVertex3f(0.5,0.0,0.5);
    glVertex3f(0.0,0.0,0.5);
    glVertex3f(0.0,0.5,0.5);
    glVertex3f(0.5,0.5,0.5);
    glEnd();
    //White Side-BACK
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(0.0,0.5,0.0);
    glVertex3f(0.5,0.5,0.0);
    glVertex3f(0.5,0.0,0.0);
    glVertex3f(0.0,0.0,0.0);
    glEnd();
    //Purple Side -RIGHT
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex3f(0.5,0.5,0.5);
    glVertex3f(0.5,0.5,0.0);
    glVertex3f(0.5,0.0,0.0);
    glVertex3f(0.5,0.0,0.5);
    glEnd();
    //Green Side-LEFT
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(0.0,0.5,0.5);
    glVertex3f(0.0,0.5,0.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,0.0,0.5);
    glEnd();
    //Blue Side-TOP
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(0.0,0.5,0.5);
    glVertex3f(0.0,0.5,0.0);
    glVertex3f(0.5,0.5,0.0);
    glVertex3f(0.5,0.5,0.5);
    glEnd();
    //Red Side -BOTTOM
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.5,0.0,0.0);
    glVertex3f(0.5,0.0,0.5);
    glVertex3f(0.0,0.0,0.5);
    glEnd();

    glFlush();
    glutSwapBuffers();
}

void myKey(int key,int x,int y){
    if(key==GLUT_KEY_RIGHT)//Right arrow increase rotation by 5
        rotate_y+=5;
    else if(key==GLUT_KEY_LEFT)//Left arrow decrease rotation by 5
        rotate_y-=5;
    else if(key==GLUT_KEY_UP)//Up arrow increase rotation by 5 in upward direction
        rotate_x+=5;
    else if(key==GLUT_KEY_DOWN)//Down arrow increase rotation by 5 in downward direction
        rotate_x-=5;
    glutPostRedisplay();
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Rotating Cube");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutSpecialFunc(myKey);
    glutMainLoop();
    return 0;
}
