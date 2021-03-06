#include <windows.h>
#include <GL/glut.h>

void initGL() {

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
    int bw = 0;
	for (float i = 1.0f;i>=-0.75f;i-=0.25f) {
        for (float j = -1.0f;j<=0.75f;j+=0.25f) {

            glBegin(GL_POLYGON);
            if (bw%2==0)
                glColor3f(0.0f, 0.0f, 0.0f);
            else
                glColor3f(1.0f, 1.0f, 1.0f);
            glVertex2f(j, i);
            glVertex2f(j, i-0.25f);
            glVertex2f(j+0.25f, i-0.25f);
            glVertex2f(j+0.25f, i);
            glEnd();
            bw++;
        }
        bw--;
	}

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Chess Board");
	glutInitWindowSize(320, 320);
	glutDisplayFunc(display);
	initGL();
	glutMainLoop();
	return 0;
}
