//Moving Car with Menu
//For mac

#include <iostream>
#include <cstdlib>
#include <GLUT/glut.h>
#include <cmath>

using namespace std;

float colors[4][3]={{1.0,0.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{1.0,1.0,0.0}};
int body_color=0;
double s=0.0;//speed variable
double tr=0.0;//rotation with arbitrary axis(tr,tr,tr);
int id;

void car(){
    //car wheels
    glPushMatrix();
    glTranslatef(-0.9,-0.02,-0.2);//move torus to left
    glutSolidTorus(0.01,0.03,25,25);//reder a torus at the center
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.6,-0.02,-0.2);
    glutSolidTorus(0.01,0.03,25,25);
    glPopMatrix();
    //car body
    glColor3fv(colors[body_color]);
    glPushMatrix();
    glTranslatef(-0.75,0.1,-0.3);
    glScalef(2.5,2.0,1.0);
    glutSolidCube(0.1);
    glPopMatrix();
    //Front Mirror
    glColor3f(0.5,0.5,0.5);
    glPushMatrix();
    glTranslatef(-0.6,0.1,-0.4);
    glScalef(0.5,2.0,1.0);
    glutSolidCube(0.1);
    glPopMatrix();
    //back mirror
    glPushMatrix();
    glTranslatef(-0.9,0.1,-0.4);
    glScalef(0.5,2.0,1.0);
    glutSolidCube(0.1);
    glPopMatrix();
    //diggy
    glColor3fv(colors[body_color]);
    glPushMatrix();
    glTranslatef(-0.95,0.1,-0.4);
    glScalef(1.2,2.0,1.0);
    glutSolidCube(0.1);
    glPopMatrix();
    //banet
    glPushMatrix();
    glTranslatef(-0.55,0.1,-0.4);
    glScalef(1.2,2.0,1.0);
    glutSolidCube(0.1);
    glPopMatrix();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(0.4,0.4,0.4);
    glPushMatrix();
    glRotated(20,tr,tr,tr);
    car();
    glPopMatrix();
    //Road
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glTranslated(-1.0, 0.0, 0.2);
    glScalef(4.5,1.2 ,0.0);
    glutSolidCube(1.0);
    glPopMatrix();
    glutSwapBuffers();
    glFlush();
}

void init(){
    glClearColor(1.0,1.0,1.0,0.0);
}

void idle(){
    s =0.001;
    glTranslated(s,0.0,0.0);
    glutPostRedisplay();
}

void mainMenu(int id){
    switch(id){
        case 1://start the car in current direction
            glutIdleFunc(idle);
            break;
        case 2://stop car
            glutIdleFunc(NULL);
            break;
        case 3://Turn left
            tr+=0.01;
            break;
        case 4://Turn right
            tr-=0.01;
            break;
        case 5://increase speed
            if(s==1.01)
                break;
            s+=0.001;
            break;
        case 6://decrease speed
            if(s==0.0)
                break;
            s-=0.0001;
            break;
        case 7:
            exit(0);
    }
    glutPostRedisplay();
}

void colorMenu(int id){
    body_color=id;
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Car Application");
    glutDisplayFunc(display);
    init();
    glEnable(GL_DEPTH_TEST);
    id=glutCreateMenu(colorMenu);
    glutAddMenuEntry("RED",0);
    glutAddMenuEntry("GREEN",1);
    glutAddMenuEntry("BLUE",2);
    glutAddMenuEntry("YELLOW",3);
    glutCreateMenu(mainMenu);
    glutAddMenuEntry("START CAR",1);
    glutAddMenuEntry("STOP CAR",2);
    glutAddMenuEntry("TURN LEFT",3);
    glutAddMenuEntry("TUEN RIGHT",4);
    glutAddMenuEntry("SPEED UP",5);
    glutAddMenuEntry("SPEED DOWN",6);
    glutAddSubMenu("COLORS",id);
    glutAddMenuEntry("QUIT",7);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}
