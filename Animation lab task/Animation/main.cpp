#include<cstdio>
#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

GLfloat position = 0.0f;
GLfloat speed = 0.1f;

void update(int value) {

    if(position <-1.0)
        {
             position = 1.0f;
        }
    else if(position > 1)
    {
        position = - 1.0f ;
    }

    position -= speed;

	glutPostRedisplay();


	glutTimerFunc(100, update, 0);
}

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);
///=========================================
    glPointSize(3.0);
    glLineWidth(3.0);

	glBegin(GL_POINTS);
	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex2f(0.0f, 0.0f); //x,y
	glEnd();
//==========================================
    glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex2f(0.0f, 0.0f);
	glVertex2f(-0.1f, -0.05f);

	glVertex2f(0.0f, 0.0f);
	glVertex2f(-0.05f, -0.1f);

	glVertex2f(-0.1f, -0.05f);
	glVertex2f(-0.1f, -0.1f);

    glVertex2f(-0.05f, -0.1f);
	glVertex2f(-0.1f, -0.1f);
///==================================
    glVertex2f(0.0f, 0.0f);
	glVertex2f(0.1f, -0.05f);

	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.05f, -0.1f);

	glVertex2f(0.1f, -0.05f);
	glVertex2f(0.1f, -0.1f);

    glVertex2f(0.05f, -0.1f);
	glVertex2f(0.1f, -0.1f);
///====================================
    glVertex2f(-0.1f, -0.1f);
	glVertex2f(-0.12f, -0.2f);

    glVertex2f(0.1f, -0.1f);
	glVertex2f(0.12f, -0.2f);
///====================================
    glVertex2f(-0.12, -0.2f);
	glVertex2f(-0.05f, -0.2f);

	glVertex2f(0.12f, -0.2f);
	glVertex2f(0.05f, -0.2f);
///====================================
    glVertex2f(-0.05, -0.2f);
	glVertex2f(-0.07f, -0.3f);

	glVertex2f(0.05f, -0.2f);
	glVertex2f(0.07f, -0.3f);
///=====================================
    glVertex2f(-0.07f, -0.3f);
    glVertex2f(-0.12f, -0.3f);

    glVertex2f(0.07f, -0.3f);
    glVertex2f(0.12f, -0.3f);
///=====================================
    glVertex2f(-0.12f, -0.3f);
    glVertex2f(-0.15f, -0.4f);

    glVertex2f(0.12f, -0.3f);
    glVertex2f(0.15f, -0.4f);
///====================================
    glVertex2f(-0.15f, -0.4f);
    glVertex2f(-0.03f, -0.4f);

    glVertex2f(0.15f, -0.4f);
    glVertex2f(0.03f, -0.4f);
///====================================
    glVertex2f(-0.03f, -0.4f);
    glVertex2f(-0.07f, -0.5f);

    glVertex2f(0.03f, -0.4f);
    glVertex2f(0.07f, -0.5f);
///================================
    glVertex2f(-0.07f, -0.5f);
    glVertex2f(0.07f, -0.5f);
	glEnd();
///================================
    glPopMatrix();
    glFlush();
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{	speed += 0.1f;
			}
if (button == GLUT_RIGHT_BUTTON)
	{speed -= 0.1f;   }
glutPostRedisplay();}


void handleKeypress(unsigned char key, int x, int y){
	switch (key) {
        case 'a':
            speed = 0.0f;
            break;
        case 'w':
            speed = 0.1f;
            break;
        glutPostRedisplay();
	}
}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Keyboard Interaction Animation");
    glutDisplayFunc(display);


    glutTimerFunc(100, update, 0);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);

    glutMainLoop();
    return 0;
}
