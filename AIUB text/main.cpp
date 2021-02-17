#include <windows.h>
#include <GL/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(3.0);
    glLineWidth(3.0);
//==========================================
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.8f, 0.0f);
	glVertex2f(-0.7f, 0.0f); //x,y

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.8f, 0.0f);
	glVertex2f(-0.7f, 0.0f);
//==========================================

    glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.75f, -0.1f);
	glVertex2f(-0.78f, -0.2f); //x,y
	glVertex2f(-0.72f, -0.2f);

    glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.75f, -0.1f);
	glVertex2f(-0.78f, -0.2f); //x,y
	glVertex2f(-0.72f, -0.2f);
//==========================================
    glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.95f, -0.4f);
	glVertex2f(-0.85f, -0.4f); //x,y

    glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.8f, 0.0f);
	glVertex2f(-0.95f, -0.4f); //x,y
	glVertex2f(-0.95f, -0.4f);
	glVertex2f(-0.85f, -0.4f);
//==========================================
    glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.83f, -0.3f);
	glVertex2f(-0.68f, -0.3f);

    glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.85f, -0.4f);
	glVertex2f(-0.83f, -0.3f);
	glVertex2f(-0.83f, -0.3f);
	glVertex2f(-0.68f, -0.3f);
//==========================================
    glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.55f, -0.4f);
	glVertex2f(-0.65f, -0.4f);

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.7f, 0.0f);
	glVertex2f(-0.55f, -0.4f);
	glVertex2f(-0.55f, -0.4f);
	glVertex2f(-0.65f, -0.4f);
	glVertex2f(-0.65f, -0.4f);
	glVertex2f(-0.68f, -0.3f);

//**********************************  AAAAAAAA *********************************

//==========================================
    glBegin(GL_POINTS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(-0.40f, 0.0f);
	glVertex2f(-0.30f, 0.0f);
	glVertex2f(-0.40f, -0.4f);
	glVertex2f(-0.30f, -0.4f);

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.40f, 0.0f);
	glVertex2f(-0.30f, 0.0f);
	glVertex2f(-0.40f, -0.4f);
	glVertex2f(-0.30f, -0.4f);

	glVertex2f(-0.40f, 0.0f);
	glVertex2f(-0.40f, -0.4f);
	glVertex2f(-0.30f, 0.0f);
	glVertex2f(-0.30f, -0.4f);

//******************************** IIIIIII **********************************************

//==========================================
    glBegin(GL_POINTS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(-0.15f, 0.0f);
	glVertex2f(-0.05f, 0.0f);
	glVertex2f(-0.15f, -0.4f);
	glVertex2f(-0.05f, -0.3f);

	glVertex2f(0.05f, 0.0f);
	glVertex2f(0.15f, 0.0f);
	glVertex2f(0.15f, -0.4f);
	glVertex2f(0.05f, -0.3f);

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);

	glVertex2f(-0.15f, 0.0f);
	glVertex2f(-0.05f, 0.0f);

	glVertex2f(0.05f, 0.0f);
	glVertex2f(0.15f, 0.0f);

	glVertex2f(-0.05f, 0.0f);
	glVertex2f(-0.05f, -0.3f);

	glVertex2f(0.05f, 0.0f);
	glVertex2f(0.05f, -0.3f);

	glVertex2f(-0.05f, -0.3f);
	glVertex2f(0.05f, -0.3f);

	glVertex2f(-0.15f, 0.0f);
	glVertex2f(-0.15f, -0.4f);

	glVertex2f(0.15f, 0.0f);
	glVertex2f(0.15f, -0.4f);

	glVertex2f(-0.15f, -0.4f);
	glVertex2f(0.15f, -0.4f);
//*********************************** UUUUUUUUU *****************************************

//==========================================
//==========================================
//==========================================
//==========================================
    glEnd();

	glFlush();  // Render now
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(600, 500);
	glutInitWindowPosition(200, 150);
    glutCreateWindow("Rainbow Flag");
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
