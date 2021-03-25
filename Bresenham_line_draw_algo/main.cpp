#include<windows.h>
#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

int x1,x2,y1,y2;

void display (){

    int dx=x2-x1;
    int dy=y2-y1;

    int pk = (2*dy)-dx;

    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);
    glPointSize(5.0);
    glBegin(GL_POINTS);

    float x=x1,y=y1;

    for(int k=0;k<dx;k++){
        if(pk>0){
            pk = pk+(2*dy)-(2*dx);
            x = x+1;
            y =y+1;
            glVertex2i(x,y);
        }

        else{
            pk = pk+(2*dy);
            x = x+1;
            y =y;
            glVertex2i(x,y);

        }
    }

    glEnd();
    glFlush();

}

void init(void){

    glClearColor (1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}



int main(int argc, char** argv){

    cout<<("Enter the points\n(X1,Y1,X2,Y2):-\n");
        cin>>x1>>y1>>x2>>y2;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Bresenham Line Algorithm");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
