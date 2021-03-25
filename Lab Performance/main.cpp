#include<windows.h>
#include<GL/glut.h>

void display(){
glClearColor(1.0f,1.0f,1.0f,1.0f);
glClear(GL_COLOR_BUFFER_BIT);

///=============================================================
///Red quads
    glBegin(GL_QUADS);
    glColor3ub(231, 76, 60); ///middle quads
    glVertex2f(-0.8f, 0.2f);
    glVertex2f(-0.8f, 0.0f);
    glVertex2f(-.6f, 0.0f);
    glVertex2f(-0.6f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(231, 76, 60); ///right quads
    glVertex2f(-0.6f, 0.0f);
    glVertex2f(-0.5f, -0.1f);
    glVertex2f(-.5f, 0.05f);
    glVertex2f(-0.6f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(231, 76, 60); ///bottom quads
    glVertex2f(-0.8f, 0.0f);
    glVertex2f(-0.7f, -0.1f);
    glVertex2f(-.5f, -0.1f);
    glVertex2f(-0.6f, 0.0f);
    glEnd();

///==============================================================
///Border
    glPointSize(1.0);
    glLineWidth(1.0);

    glBegin(GL_LINES);
	glColor3ub(247, 249, 249);

	glVertex2f(-0.8f, 0.0f);
    glVertex2f(-.6f, 0.0f);

    glVertex2f(-.6f, 0.0f);
    glVertex2f(-0.6f, 0.2f);

    glVertex2f(-.6f, 0.0f);
    glVertex2f(-0.5f, -0.1f);
    glEnd();
///==============================================================
///Green quads
    glBegin(GL_QUADS);
    glColor3ub(34, 153, 84); ///middle quads
    glVertex2f(-0.4f, 0.2f);
    glVertex2f(-0.4f, 0.0f);
    glVertex2f(-.2f, 0.0f);
    glVertex2f(-0.2f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(34, 153, 84); ///left quads
    glVertex2f(-0.4f, 0.2f);
    glVertex2f(-0.48f, 0.05f);
    glVertex2f(-.48f, -0.1f);
    glVertex2f(-0.4f, 0.0f);
    glEnd();

    glBegin(GL_QUADS); ///bottom quads
    glColor3ub(34, 153, 84);
    glVertex2f(-0.4f, 0.0f);
    glVertex2f(-0.48f, -0.1f);
    glVertex2f(-0.3f, -0.1f);
    glVertex2f(-0.2f, 0.0f);
    glEnd();
///============================================
///Border
    glPointSize(1.0);
    glLineWidth(1.0);

    glBegin(GL_LINES);
	glColor3ub(247, 249, 249);

	glVertex2f(-0.4f, 0.2f);
    glVertex2f(-0.4f, 0.0f);

    glVertex2f(-0.4f, 0.0f);
    glVertex2f(-.2f, 0.0f);

    glVertex2f(-0.4f, 0.0f);
    glVertex2f(-.48f, -0.1f);
    glEnd();

///==============================================================
///Yellow quads
    glBegin(GL_QUADS);
    glColor3ub(244, 208, 63); ///middle quads
    glVertex2f(-0.8f, -0.3f);
    glVertex2f(-0.8f, -0.5f);
    glVertex2f(-.6f, -0.5f);
    glVertex2f(-0.6f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 208, 63); ///top quads
    glVertex2f(-0.8f, -0.3f);
    glVertex2f(-0.7f, -0.15f);
    glVertex2f(-0.5f, -0.15f);
    glVertex2f(-0.6f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 208, 63); ///right quads
    glVertex2f(-0.6f, -0.3f);
    glVertex2f(-0.5f, -0.15f);
    glVertex2f(-.5f, -0.25f);
    glVertex2f(-0.6f, -0.5f);
    glEnd();


///==============================================================
///Border
    glPointSize(1.0);
    glLineWidth(1.0);

    glBegin(GL_LINES);
	glColor3ub(247, 249, 249);

	glVertex2f(-0.8f, -0.3f);
    glVertex2f(-0.6f, -0.3f);

    glVertex2f(-0.6f, -0.3f);
    glVertex2f(-.6f, -0.5f);

    glVertex2f(-0.6f, -0.3f);
    glVertex2f(-0.5f, -0.15f);
    glEnd();
///==============================================================
///Blue quads
    glBegin(GL_QUADS);
    glColor3ub(41, 128, 185); ///middle quads
    glVertex2f(-0.4f, -0.3f);
    glVertex2f(-0.4f, -0.5f);
    glVertex2f(-.2f, -0.5f);
    glVertex2f(-0.2f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(41, 128, 185); ///top quads
    glVertex2f(-0.4f, -0.3f);
    glVertex2f(-0.48f, -0.15f);
    glVertex2f(-0.3f, -0.15f);
    glVertex2f(-0.2f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(41, 128, 185); ///left quads
    glVertex2f(-0.48f, -0.15f);
    glVertex2f(-0.48f, -0.25f);
    glVertex2f(-0.4f, -0.5f);
    glVertex2f(-0.4f, -0.3f);
    glEnd();

///===============================================
///Border
    glPointSize(1.0);
    glLineWidth(1.0);

    glBegin(GL_LINES);
	glColor3ub(247, 249, 249);

	glVertex2f(-0.4f, -0.3f);
    glVertex2f(-0.4f, -0.5f);

    glVertex2f(-0.4f, -0.3f);
    glVertex2f(-0.2f, -0.3f);

    glVertex2f(-0.4f, -0.3f);
    glVertex2f(-0.48f, -0.15f);
    glEnd();

///===============================================
///Second quads
    glBegin(GL_QUADS);
    glColor3ub(142, 68, 173); ///background color
    glVertex2f(-0.1f, 0.2f);
    glVertex2f(-0.1f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.2f);
    glEnd();
///======================================
    glBegin(GL_QUADS);
    glColor3ub(247, 249, 249);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.05f, 0.02f);
    glVertex2f(0.05f, -0.3f);
    glVertex2f(0.0f, -0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(247, 249, 249);
    glVertex2f(0.05f, 0.02f);
    glVertex2f(0.2f, -0.1f);
    glVertex2f(0.2f, -0.15f);
    glVertex2f(0.05f, -0.3f);
    glEnd();
///=======================================
    glBegin(GL_TRIANGLES);
    glColor3ub(142, 68, 173);
    glVertex2f(0.05f, -0.1f);
    glVertex2f(0.05f, -0.2f);
    glVertex2f(0.1, -0.15f);
    glEnd();
///==================================
    glBegin(GL_QUADS);
    glColor3ub(247, 249, 249);
    glVertex2f(0.2f, -0.1f);
    glVertex2f(0.2f, -0.15f);
    glVertex2f(0.35f, -0.4f);
    glVertex2f(0.35f, 0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(247, 249, 249);
    glVertex2f(0.35f, 0.1f);
    glVertex2f(0.4f, 0.08f);
    glVertex2f(0.4f, -0.38f);
    glVertex2f(0.35f, -0.4f);
    glEnd();
///==============================================
    glBegin(GL_TRIANGLES);
    glColor3ub(142, 68, 173);
    glVertex2f(0.35f, -0.05f);
    glVertex2f(0.35f, -0.25f);
    glVertex2f(0.25f, -0.15f);
    glEnd();

///===============================================
     glLoadIdentity();
     glFlush();
}
///===============================================

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(600, 500);
    glutCreateWindow("Image View");
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
