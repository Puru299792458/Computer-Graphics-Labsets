//Primitives
//For mac

#include <iostream>
#include <cstdlib>
#include <GLUT/glut.h>

using namespace std;

void init(){
    glClearColor(0.0,0.0, 0.0, 0.0);
    //left,right,bottom,top
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
}

void display(){
    int ch;
    cout<<" 1:Points\n 2:Lines\n 3:Lines_Strip\n 4:Line_Loop\n 5:Triangles\n 6:Triangle_Strip\n 7:Tiangle_Fan\n 8:Quad\n 9:Quad_Strip\n 10:Polygon\n";
    cout<<"Enter your choice :";
    cin>>ch;
    switch(ch){
            //Points
        case 1:
            glClear(GL_COLOR_BUFFER_BIT);//Clear the previous buffers
            glPointSize(10.0);
            glBegin(GL_POINTS);
            glColor3f(1.0,0.0, 0.0);
            glVertex2f(1.0,1.0);
            glVertex2f(-1.0, 1.0);
            glVertex2f(-1.0, -1.0);
            glVertex2f(1.0, -1.0);
            glEnd();
            glFlush();
            break;
            //Lines
        case 2:
            glClear(GL_COLOR_BUFFER_BIT);
            glLineWidth(4.0);
            glColor3f(0.0,0.0,1.0);
            glBegin(GL_LINES);
            glVertex2f(1.0, 1.0);
            glVertex2f(-1.0,1.0);
            glVertex2f(-1.0,-1.0);
            glVertex2f(1.0,-1.0);
            glEnd();
            glFlush();
            break;
            //Lines Strip spanning all vertices but not necessarily connected
        case 3:
            glClear(GL_COLOR_BUFFER_BIT);
            glLineWidth(4.0);
            glColor3f(0.0,1.0,0.0);
            glBegin(GL_LINE_STRIP);
            glVertex2f(1.0, 1.0);
            glVertex2f(-1.0,1.0);
            glVertex2f(-1.0,-1.0);
            glVertex2f(1.0,-1.0);
            glEnd();
            glFlush();
            break;
            //Line Loop spanning all vertices and all of them are connected
        case 4:
            glClear(GL_COLOR_BUFFER_BIT);
            glLineWidth(4.0);
            glColor3f(0.0,1.0,1.0);
            glBegin(GL_LINE_LOOP);
            glVertex2f(1.0, 1.0);
            glVertex2f(-1.0,1.0);
            glVertex2f(-1.0,-1.0);
            glVertex2f(1.0,-1.0);
            glEnd();
            glFlush();
            break;
            //Triangles
        case 5:
            glClear(GL_COLOR_BUFFER_BIT);
            glColor3f(1.0,1.0,0.0);
            glBegin(GL_TRIANGLES);
            glVertex2f(0.0, 1.0);
            glVertex2f(-1.0,0.0);
            glVertex2f(1.0,0.0);
            glEnd();
            glFlush();
            break;
            //Traingle Strip
        case 6:
            glClear(GL_COLOR_BUFFER_BIT);
            glColor3f(0.0,1.0,1.0);
            glBegin(GL_TRIANGLE_STRIP);
            glVertex2f(0.0, 1.0);
            glVertex2f(-1.0,0.0);
            glVertex2f(1.0,0.0);
            glVertex2f(1.0,-1.0);
            glEnd();
            glFlush();
            break;
            //Triangle Fan
        case 7:
            glClear(GL_COLOR_BUFFER_BIT);
            glColor3f(0.0,1.0,1.0);
            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(1.0, 1.0);
            glVertex2f(-1.0,1.0);
            glVertex2f(-1.0,-1.0);
            glVertex2f(1.5,-1.5);
            glEnd();
            glFlush();
            break;
            //QUAD
        case 8:
            glClear(GL_COLOR_BUFFER_BIT);
            glColor3f(1.0,1.0,0.0);
            glBegin(GL_QUADS);
            glVertex2f(1.0, 1.0);
            glVertex2f(-1.0,1.0);
            glVertex2f(-1.0,-1.0);
            glVertex2f(1.0,-1.0);
            glEnd();
            glFlush();
            break;
            //QUAD_STRIP
        case 9:
            glClear(GL_COLOR_BUFFER_BIT);
            glColor3f(0.0,1.0,1.0);
            glBegin(GL_QUAD_STRIP);
            glVertex2f(1.0, 1.0);
            glVertex2f(-1.0,1.0);
            glVertex2f(-1.0,-1.0);
            glVertex2f(1.0,-1.0);
            glVertex2f(2.0,0.0);
            glEnd();
            glFlush();
            break;
            //Polygon
        case 10:
            glClear(GL_COLOR_BUFFER_BIT);
            glColor3f(0.0,1.0,1.0);
            glBegin(GL_POLYGON);
            glVertex2f(1.0, 1.0);
            glVertex2f(-1.0,1.0);
            glVertex2f(-1.0,-1.0);
            glVertex2f(1.0,-1.0);
            glEnd();
            glFlush();
            break;
        default:
            exit(0);
    }
}


int main(int argc,char **argv){
    glutInit(&argc,argv);//Interaction between the system window and openGL
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);//Sets the initial Display Mode
    glutInitWindowSize(500, 500);//Siez of the window height and width
    glutInitWindowPosition(0.0, 0.0);//Position of the window screen
    glutCreateWindow("Primitives");//Creates a window with th label primitive
    glutDisplayFunc(display);//Call Back function
    init();
    glutMainLoop();//Loop infinitely until end
    return 0;
}
