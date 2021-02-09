#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>

void Display(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(2.3);

    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(0.0f, -1.0f);
    glEnd();

    glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.3f, -0.3f);
	glVertex2f(-0.7f, -0.3f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.5f, -0.6f);
	glVertex2f(-0.7f, -0.3f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.3f, -0.3f);
	glVertex2f(-0.5f, -0.6f);
	glEnd();

    glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.5f, 0.6f);
    glVertex2f(0.3f, 0.3f);
	glVertex2f(0.7f, 0.3f);
    glEnd();

    glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.6f, 0.5f);
	glVertex2f(-0.6f, 0.3f);
	glVertex2f(-0.3f, 0.3f);
	glVertex2f(-0.3f, 0.5f);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.5f, -0.3f);
    glVertex2f(0.4f, -0.5f);
    glVertex2f(0.5f, -0.7f);
    glVertex2f(0.7f, -0.7f);
    glVertex2f(0.8f, -0.5f);
    glVertex2f(0.7f, -0.3f);
    glEnd();

    glFlush();
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Setup");
    glutInitWindowSize(320,320);
    glutDisplayFunc(Display);
    glutMainLoop();

    return 0;
}
