//3d Sierpinski Gasket
//For mac

#include <GLUT/glut.h>
#include <iostream>

using namespace std;

GLfloat v[4][3]={
    {-1.0,-1.0,-1.0},
    {1.0,-1.0,-1.0},
    {0.0,1.0,-1.0},
    {0.0,0.0,1.0}
};

GLfloat colors[4][3]={
    {1.0,0.0,0.0},
    {0.0,1.0,0.0},
    {0.0,0.0,1.0},
    {0.0,0.0,0.0}
};

int n;

void triangle(GLfloat* va, GLfloat *vb, GLfloat* vc){
    glVertex3fv(va);
    glVertex3fv(vb);
    glVertex3fv(vc);
}

void tetra(GLfloat* a, GLfloat* b, GLfloat* c, GLfloat* d){
    glColor3fv(colors[0]);
    triangle(a,b,c);
    glColor3fv(colors[1]);
    triangle(a,c,d);
    glColor3fv(colors[2]);
    triangle(a,d,b);
    glColor3fv(colors[3]);
    triangle(b,d,c);
}

void divide_tetra(GLfloat *a, GLfloat* b, GLfloat* c, GLfloat* d, int m){
    GLfloat mid[6][3];
    int j;
    if(m>0)
    {
        for(j=0;j<3;j++){
            mid[0][j] = (a[j]+b[j])/2;
            mid[1][j] = (a[j]+c[j])/2;
            mid[2][j] = (a[j]+d[j])/2;
            mid[3][j] = (b[j]+c[j])/2;
            mid[4][j] = (c[j]+d[j])/2;
            mid[5][j] = (b[j]+d[j])/2;
        }
        divide_tetra(a,mid[0], mid[1], mid[2],m-1);
        divide_tetra(mid[0],b, mid[3], mid[5],m-1);
        divide_tetra(mid[1], mid[3],c, mid[4],m-1);
        divide_tetra(mid[2], mid[4],d, mid[5],m-1);
    }
    else
        tetra(a,b,c,d);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    divide_tetra(v[0],v[1],v[2],v[3],n);
    glEnd();
    glFlush();
}

void myReshape(int w, int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h){
        GLfloat ar =(GLfloat)h/(GLfloat)w;
        glOrtho(-2.0,2.0,-2.0*ar,2.0*ar,-10.0,10.0);
    }else{
        GLfloat ar1 =(GLfloat)w/(GLfloat)h;
        glOrtho(-2.0*ar1,2.0*ar1,-2.0,2.0,-10.0,10.0);
    }
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

int main(int argc,char** argv){
    cout<<"Enter the value of n: ";
    cin>>n;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("3D gasket");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0,1.0,1.0,1.0);
    glutMainLoop();
    return 0;
}
