#include<windows.h>
#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

int r,xc,yc;
//==============================================
void plot_point(int x, int y, int xc, int yc){

     glBegin(GL_POINTS);

     glVertex2i(xc+x, yc+y);

     glVertex2i(xc+x, yc-y);

     glVertex2i(xc+y, yc+x);

     glVertex2i(xc+y, yc-x);

     glVertex2i(xc-x, yc-y);

     glVertex2i(xc-y, yc-x);

     glVertex2i(xc-x, yc+y);

     glVertex2i(xc-y, yc+x);
}
//===============================================
void display (){

    int y=r,x=0;

    int pk = 1-r;

    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);
    glPointSize(5.0);
    glBegin(GL_POINTS);

    while(y>=x){
        x++;

        if(pk<0){
            pk +=(2*x)+1;
        }else{
            y--;
            pk +=(2*x)+1-(2*y);

             plot_point(x,y,xc,yc);
        }

    }
    glEnd();
    glFlush();
}

//==============================================
void init(void){

    glClearColor (1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}



int main(int argc, char** argv){

    cout<<("Enter your radius :-\n");
        cin>>r;
    cout<<("Enter your xc & yc point :-\n");
        cin>>xc>>yc;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Bresenham Circle Drawing Algorithm");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
