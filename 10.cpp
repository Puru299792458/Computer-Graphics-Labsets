//Flood Fill and Scanfill
//For mac

#include <iostream>
#include <cstdlib>
#include <GLUT/glut.h>

using namespace std;

float fgcolor[]={1.0,1.0,0.0};
float bgcolor[]={1.0,1.0,1.0};

void init(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3fv(fgcolor);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

float *getPixelColor(float x,float y){
    float colr[3];
    glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,colr);
    return colr;
}

void setPixelColor(float x,float y){
    glColor3fv(fgcolor);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    glFlush();
}

//ScanFill
void scanFill(){
    float *colr,x,y;
    for(y=140.0;y<340.0;y++){
        for(x=120.0;x<420.0;x++){
            colr=getPixelColor(x,y);
            if(*(colr+0)==bgcolor[0] && *(colr+1)==bgcolor[1] && *(colr+2)==bgcolor[2])
                setPixelColor(x,y);
        }
    }
    return ;
}

void myMouse(int btn,int st,int x,int y){
    if(btn==GLUT_LEFT_BUTTON && st==GLUT_DOWN)
        scanFill();
    else if(btn==GLUT_RIGHT_BUTTON && st==GLUT_DOWN)
        floodFill(121.0,141.0);
}

//FloodFill
void floodFill(float x,float y){
    float *colr;
    colr=getPixelColor(x,y);
    if(*(colr+0)==bgcolor[0] && *(colr+1)==bgcolor[1] && *(colr+2)==bgcolor[2]){
        setPixelColor(x,y);
        floodFill(x+1,y);
        floodFill(x-1,y);
        floodFill(x,y-1);
        floodFill(x,y+1);
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    glVertex2f(120.0,340.0);
    glVertex2f(420.0,340.0);
    glVertex2f(420.0,140.0);
    glVertex2f(120.0,140.0);
    glEnd();
    glFlush();
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutCreateWindow("Open GL");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(myMouse);
    glutMainLoop();
    return 0;
}
