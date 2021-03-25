#include <windows.h>
#include <GL/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.6f, 0.5f);
    glVertex2f(0.2f, 0.5f);
    glVertex2f(0.2f, 0.4f);
    glVertex2f(-0.6f, 0.4f);
//================================================
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.6f, 0.4f);
    glVertex2f(0.2f, 0.4f);
    glVertex2f(0.2f,  0.3f);
    glVertex2f(-0.6f,  0.3f);
//================================================
    glColor3f(0.0f, .50f, 0.0f);
    glVertex2f(-0.6f, 0.3f);
    glVertex2f(0.2f, 0.3f);
    glVertex2f(0.2f,  0.2f);
    glVertex2f(-0.6f,  0.2f);
//================================================
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.6f, 0.2f);
    glVertex2f(0.2f, 0.2f);
    glVertex2f(0.2f,  0.1f);
    glVertex2f(-0.6f,  0.1f);
//================================================
    glColor3f(0.50f, 0.0f, 0.50f);
    glVertex2f(-0.6f, 0.1f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(0.2f,  0.0f);
    glVertex2f(-0.6f,  0.0f);
//================================================
    glColor3f(0.50f, 0.50f, 0.50f);
    glVertex2f(-0.6f, 0.f);
    glVertex2f(0.2f, 0.f);
    glVertex2f(0.2f,  -0.1f);
    glVertex2f(-0.6f,  -0.1f);
//================================================
    glColor3f(0.50f, 0.50f, 0.10f);
    glVertex2f(-0.6f, -0.1f);
    glVertex2f(0.2f, -0.1f);
    glVertex2f(0.2f,  -0.2f);
    glVertex2f(-0.6f,  -0.2f);

//###################################################
    // flag strict
    glColor3f(0.0f, 0.0f, 0.60f);
    glVertex2f(-0.6f, 0.6f);
    glVertex2f(-0.55f, 0.6f);
    glVertex2f(-0.55f,  -0.7f);
    glVertex2f(-0.6f,  -0.7f);

//###################################################

    glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.60f, -0.7f);
	glVertex2f(-0.60f, -0.8f);
	glVertex2f(-0.50f, -0.8f);
	glVertex2f(-0.50f, -0.7f);

//================================================
    glEnd();

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Rainbow Flag");
	glutInitWindowSize(400, 300);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
