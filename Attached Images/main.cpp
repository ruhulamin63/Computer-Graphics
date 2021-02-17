#include <windows.h>
#include <GL/glut.h>

void Horizontal_line(int x, int y, int sizes, int num){

    for(int a=x, b=y, c=0; c<num; c++, a+=sizes){
        glBegin(GL_POLYGON);

        glVertex2i(a,b);
        glVertex2i(a+sizes, b);
        glVertex2i(a+sizes, b+sizes);
        glVertex2i(a, b+sizes);

        glEnd();
    }
}
//==========================================================
void vertical_line(int x, int y, int sizes, int num){

    for(int a=x, b=y, c=0; c<num; c++, b+=sizes){
        glBegin(GL_POLYGON);

        glVertex2i(a,b);
        glVertex2i(a+sizes, b);
        glVertex2i(a+sizes, b+sizes);
        glVertex2i(a, b+sizes);

        glEnd();
    }
}
//============================================================
void Attached_Images(){
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5.0);

    int sizes=25, blocks=17;
    int x=9*sizes, y=3*sizes;

    glColor3f(0.0,0.0,0.0); //color black
    Horizontal_line(x, y, sizes, blocks);
///*
    x=9*sizes, y=4*sizes;
    blocks;

    for(int a=0; a<=5; a++){
        glColor3f(250.0,250.0,0.0); // color yellow
        Horizontal_line(x, y, sizes, blocks);

        glColor3f(0.0,0.0,0.0); //color black
        Horizontal_line(x-sizes, y, sizes, 1);
        Horizontal_line(x+(blocks*sizes), y, sizes, 1);

        x=x-sizes;
        y=y+sizes;
        blocks +=2;
    }

    x=3*sizes, y=10*sizes;

    for(int a=0; a<7; a++){
        glColor3f(250.0,250.0,0.0); // color yellow
        Horizontal_line(x, y, sizes, 29);

        glColor3f(0.0,0.0,0.0); //color black
        Horizontal_line(x-sizes, y, sizes, 1);

        glColor3f(0.0,0.0,0.0); //color black
        Horizontal_line(x+(29*sizes), y, sizes, 1);

        y +=sizes;
    }

    x=4*sizes, y=17*sizes, blocks=27;

    for(int a=0; a<=5; a++){
        glColor3f(250.0,250.0,0.0); // color yellow
        Horizontal_line(x, y, sizes, blocks);

        glColor3f(0.0,0.0,0.0); //color black
        Horizontal_line(x-sizes, y, sizes, 1);

        Horizontal_line(x+(blocks*sizes), y, sizes, 1);

        y +=sizes;
        x +=sizes;
        blocks -=2;
    }
    x=9*sizes;

    glColor3f(0.0,0.0,0.0); //color black
    Horizontal_line(x, y, sizes, blocks+2);

    x=4*sizes, y=11*sizes;
    blocks=5;

    for(int a=0; a<6; a++){
        vertical_line(x, y, sizes, blocks);

        x +=sizes;
        y -=sizes;
        blocks +=2;
    }

    blocks -=2;
    y +=sizes;
    vertical_line(x, y, sizes, blocks);

    y -=sizes;
    x +=sizes;

    blocks =12;
    vertical_line(x, y, sizes, blocks);

    y=20*sizes;
    vertical_line(x, y, sizes, 1);

    x +=sizes;
    y =7*sizes;
    blocks=9;

    for(int a=0; a<2; a++){
        vertical_line(x, y, sizes, blocks);

        x +=sizes;
        y +=sizes;
        blocks--;
    }
    blocks++;
    vertical_line(x, y, sizes, blocks);

    x +=sizes;
    y -=sizes;
    blocks=14;
    vertical_line(x, y, sizes, blocks);

    x +=sizes;
    y -=(2*sizes);
    blocks=15;
    vertical_line(x, y, sizes, blocks);

    x +=sizes;
    y -=sizes;
    blocks=16;
    vertical_line(x, y, sizes, blocks);

    x +=sizes;
    y +=sizes;
    blocks=15;
    vertical_line(x, y, sizes, blocks);

    x +=sizes;
    y +=(2*sizes);
    blocks=14;
    vertical_line(x, y, sizes, blocks);

    y=6*sizes;
    x=24*sizes;
    blocks=16;

    for(int a=0; a<=6; a++){
        vertical_line(x, y, sizes, blocks);

        x +=sizes;
        y +=sizes;
        blocks -=2;
    }

    y=6*sizes;
    x=23*sizes;
    blocks=16;
    vertical_line(x, y, sizes, blocks);

    y=5*sizes;
    x=22*sizes;
    blocks=12;
    vertical_line(x, y, sizes, blocks);

    y=21*sizes;
    vertical_line(x, y, sizes, 1);

    x -=sizes;
    y -=(14*sizes);
    vertical_line(x, y, sizes, 9);

    x -=sizes;
    y +=sizes;
    vertical_line(x, y, sizes, 9);

//*/
    glFlush();
}
//==========================================================

void myInit(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glLoadIdentity();
    gluOrtho2D(0.0, 900.0, 0.0, 700.0);
}
//===========================================================
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(600, 500);
    glutCreateWindow("Attached Images");
	glutDisplayFunc(Attached_Images);
	myInit();
	glutMainLoop();

	return 0;
}
