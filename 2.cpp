#include <GLUT/glut.h>
#include <cstdio>

void display2d(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,0.0);
    glBegin(GL_TRIANGLES);
    glColor3f(1,0.2,0.5);
    glVertex2f(0.0,0.5);
    glVertex2f(-0.5,0.0);
    glVertex2f(0.5,0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.4,0.3,.60);
    glVertex2f(-0.5,0.0);
    glVertex2f(-0.5,-0.9);
    glVertex2f(0.5,-0.9);
    glVertex2f(0.5,0.0);
    glEnd();
    glFlush();
}

void display3d(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,0.0);
    //back
    glBegin(GL_POLYGON);
    glColor3f(0.4,1.4,0.5);
    glVertex3f(1.4,1.2,-0.5);
    glVertex3f(0.2 ,0.2,-0.5);
    glVertex3f(1.2,0.2,-0.5);
    glVertex3f(1.2,1.2,-0.5);
    glEnd();
    //left
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.5);
    glVertex3f(-0.2,0.8,0.5);
    glVertex3f(-0.2,-0.2,0.5);
    glVertex3f(0.2,0.2,-0.5);
    glVertex3f(0.2,1.2,-0.5);
    glEnd();
    //bottom
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.5,0.0);
    glVertex3f(0.2,0.2,-0.5);
    glVertex3f(-0.2,-0.2,0.5);
    glVertex3f(0.8,-0.2,0.5);
    glVertex3f(1.2,0.2,-0.5);
    glEnd();
    //front
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex3f(-0.2,0.8,0.5);
    glVertex3f(-0.2,-0.2,0.5);
    glVertex3f(0.8,-0.2,0.5);
    glVertex3f(0.8,0.8,0.5);
    glEnd();
    //right
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.5);
    glVertex3f(0.8,0.8,0.5);
    glVertex3f(0.8,-0.2,0.5);
    glVertex3f(1.2,0.2,-0.5);
    glVertex3f(1.2,1.2,-0.5);
    glEnd();
    //top
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.5,0.0);
    glVertex3f(0.2,1.2,-0.5);
    glVertex3f(-0.2,0.8,0.5);
    glVertex3f(0.8,0.8,0.5);
    glVertex3f(1.2,1.2,-0.5);
    glEnd();

    glFlush();
}

void init2d(int ch){
    glutInitDisplayMode(GLUT_SINGLE);
    if(ch==1)
        glutCreateWindow("2d Ortho");
    else
        glutCreateWindow("2d Perspective");
    glutDisplayFunc(display2d);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(ch==1)
        gluOrtho2D(-2.0,2.0,-2.0,2.0);
    else
        gluPerspective(90.0,2.0,0.0,0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void init3d(int ch){
    glutInitDisplayMode(GLUT_SINGLE|GLUT_DEPTH);
    if(ch==1)
        glutCreateWindow("3d Ortho");
    else
        glutCreateWindow("3d Perspective");
    glutDisplayFunc(display3d);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(ch==1)
        glOrtho(-2.0,2.0,-2.0,2.0,-2.0,2.0);
    else
        glFrustum(-0.5,0.5,-0.5,0.5,-0.5,0.5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc,char **argv){
    int ch;
    glutInit(&argc,argv);
    cout<<"\nEnter your choice:\n1.2d Ortho\n2.2d Perspective\n3.3d Ortho\n4.3d Perspective\n";
    cin>>ch;
    switch(ch){
        case 1:init2d(1);
            break;
        case 2:init2d(2);
            break;
        case 3:init3d(1);
            break;
        case 4:init3d(2);
            break;
    }
    glutMainLoop();
    return 0;
}
