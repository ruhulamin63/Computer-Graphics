#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#define pi  acos(-1)

void display(){
glClearColor(1.0f,1.0f,1.0f,1.0f);
glClear(GL_COLOR_BUFFER_BIT);

///=====================================================================================================
///SKY
    glBegin(GL_QUADS);
    glColor3ub(0, 153, 255);
    glVertex2f(-1.0, 1.0f);     // top left
    glVertex2f(1.0f, 1.0f);     // top right
    glVertex2f(1.0f, .95f);     // bottom right
    glVertex2f(-1.0f, .95f);    // bottom left
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(26, 163, 255);
    glVertex2f(-1.0, .95f);
    glVertex2f(1.0f, .95f);
    glVertex2f(1.0f, .90f);
    glVertex2f(-1.0f, .90f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(51, 173, 255);
    glVertex2f(-1.0, .90f);
    glVertex2f(1.0f, .90f);
    glVertex2f(1.0f, .85f);
    glVertex2f(-1.0f, .85f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(77, 184, 255);
    glVertex2f(-1.0, .85f);
    glVertex2f(1.0f, .85f);
    glVertex2f(1.0f, .80f);
    glVertex2f(-1.0f, .80f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 194, 255);
    glVertex2f(-1.0, .80f);
    glVertex2f(1.0f, .80f);
    glVertex2f(1.0f, .70f);
    glVertex2f(-1.0f, .70f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 204, 255);
    glVertex2f(-1.0, .70f);
    glVertex2f(1.0f, .70f);
    glVertex2f(1.0f, .60f);
    glVertex2f(-1.0f, .60f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 214, 255);
    glVertex2f(-1.0, .60f);
    glVertex2f(1.0f, .60f);
    glVertex2f(1.0f, .40f);
    glVertex2f(-1.0f, .40f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(179, 224, 255);
    glVertex2f(-1.0, .40f);
    glVertex2f(1.0f, .40f);
    glVertex2f(1.0f, .15f);
    glVertex2f(-1.0f, .15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 235, 255);
    glVertex2f(-1.0, .15f);
    glVertex2f(1.0f, .15f);
    glVertex2f(1.0f, -.15f);
    glVertex2f(-1.0f, -.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 245, 255);
    glVertex2f(-1.0, .15f);
    glVertex2f(1.0f, .15f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();
///=======================================================================================
///GRASS
    glBegin(GL_QUADS);
    glColor3ub(0, 179, 60);
    glVertex2f(-1.0, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -.3f);
    glVertex2f(-1.0f, -.3f);
    glEnd();
///=======================================================================================
///CLOUD
	float x_c,y_c,radius_c,pie_c;
    x_c= -0.55f;
    y_c= 0.8f;
    radius_c =.1f;
    int circle_c = 20;
    pie_c = 2.0f * pi;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(230, 255, 255);
    glVertex2f(x_c, y_c);

    for(int i=0; i<=circle_c;i++){
    glVertex2f(
                x_c + (radius_c * cos(i *  pie_c / circle_c)),
                y_c + (radius_c * sin(i * pie_c / circle_c))
                );
    }
	glEnd();
///=======================================================================================
///SUN
	float x=-0.7f,y=0.7f,sun_radius =.2f;
	int circle = 100;
	float pie_sun = 2.0f * pi;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 209, 26);
    glVertex2f(x, y);

    for(int i=0; i<=circle; i++){
        glVertex2f(x+(sun_radius*cos(i*pie_sun/circle)),
                   y+(sun_radius*sin(i*pie_sun/circle))
                );
    }
	glEnd();

///======================================================================================
///Main Circle for AIUB Dim
	float x_d,y_d,radius_d,pie_d;
	int circle_d = 30;
        x_d=.0f;
        y_d=.0f;
        radius_d =.735f;
        pie_d = 2.0f * pi;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(236, 240, 241);
    glVertex2f(x_d,y_d);
    for(int i=0; i<=circle_d;i++) {
    glVertex2f
			(
                x_d + (radius_d * cos(i * pie_d / circle_d)),
			    y_d + (radius_d * sin(i * pie_d / circle_d))
			);
		}
	glEnd();
///=======================================================================================
 ///Network tower
    glPointSize(3.0);
    glLineWidth(3.0);

    glBegin(GL_LINES);
    glColor3ub(33,47,61);

    glVertex2f(-0.2f, 0.705f);
	glVertex2f(-0.2f, .9f);

    glEnd();

//=======================================================================================
 ///Under_Ground
     glBegin(GL_QUADS);
     glColor3ub(236, 240, 241);
     glVertex2f(-0.35,-0.6);
     glVertex2f(-0.35,-0.8);
     glVertex2f(0.35,-0.8);
     glVertex2f(0.35,-0.6);
     glEnd();
///=======================================================================================
 ///FloorBase

     glBegin(GL_POLYGON);
     glColor3ub(19, 141, 117);
     glVertex2f(-0.536,-0.5);
     glVertex2f(-0.435,-0.59);
     glVertex2f(0.435,-0.59);
     glVertex2f(0.536,-0.5);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3ub(19, 141, 117);
     glVertex2f(-0.67,-0.3);
     glVertex2f(-0.615,-0.4);
     glVertex2f(0.615,-0.4);
     glVertex2f(0.67,-0.3);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3ub(19, 141, 117);
     glVertex2f(-0.734,-0.02);
     glVertex2f(-0.709,-0.19);
     glVertex2f(0.709,-0.19);
     glVertex2f(0.734,-0.02);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3ub(19, 141, 117);
     glVertex2f(-0.728,0.1);
     glVertex2f(-0.706,0.2);
     glVertex2f(0.706,0.2);
     glVertex2f(0.728,0.1);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3ub(19, 141, 117);
     glVertex2f(-0.66,0.32);
     glVertex2f(-0.59,0.44);
     glVertex2f(0.59,0.44);
     glVertex2f(0.66,0.32);
     glEnd();
///========================================================================================

///BD Flag

    glPointSize(8.0);
    glLineWidth(8.0);

    glBegin(GL_LINES);
	glColor3ub(93, 109, 126);

	glVertex2f(0.0f, -0.7f); //Stand for flag
	glVertex2f(0.0f, 0.0f);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(25, 111, 61);

    glVertex2f(0.0f,-0.02f);
    glVertex2f(0.0f,-0.3f);
    glVertex2f(0.5f,-0.3f);
    glVertex2f(0.5f,-0.02f);
    glEnd();

///Red Circle

    float fx=0.25f,fy=-0.15f,flag_radius =.08f;
	int flag_circle = 20;
	float flag_pie = 2.0f * pi;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(231, 76, 60);
    glVertex2f(fx, fy);
    for(int i=0; i<=flag_circle; i++){
        glVertex2f(fx+(flag_radius*cos(i*flag_pie/flag_circle)),
                   fy+(flag_radius*sin(i*flag_pie/flag_circle))
                );
    }
	glEnd();
///===========================================================================================
///Red color flag right side
    glPointSize(8.0);
    glLineWidth(8.0);

    glBegin(GL_LINES);
	glColor3ub(93, 109, 126);

	glVertex2f(0.2f, -0.7f); //Stand for flag
	glVertex2f(0.2f, -0.3f);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(231, 76, 60);

    glVertex2f(0.2f,-0.32f);
    glVertex2f(0.2f,-0.5f);
    glVertex2f(0.5f,-0.5f);
    glVertex2f(0.5f,-0.32f);
    glEnd();
///===========================================================================================
///Orange color flag right side
    glPointSize(8.0);
    glLineWidth(8.0);

    glBegin(GL_LINES);
	glColor3ub(93, 109, 126);

	glVertex2f(0.6f, -0.7f); //Stand for flag
	glVertex2f(0.6f, -0.3f);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(212, 172, 13);

    glVertex2f(0.6f,-0.32f);
    glVertex2f(0.6f,-0.5f);
    glVertex2f(0.9f,-0.5f);
    glVertex2f(0.9f,-0.32f);
    glEnd();
///===========================================================================================
///Green color flag left side
    glPointSize(8.0);
    glLineWidth(8.0);

    glBegin(GL_LINES);
	glColor3ub(93, 109, 126);

	glVertex2f(-0.2f, -0.7f); //Stand for flag
	glVertex2f(-0.2f, -0.3f);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(0, 179, 60);

    glVertex2f(-0.2f,-0.32f);
    glVertex2f(-0.2f,-0.5f);
    glVertex2f(-0.5f,-0.5f);
    glVertex2f(-0.5f,-0.32f);
    glEnd();
///===========================================================================================
///Sky color flag left side
    glPointSize(8.0);
    glLineWidth(8.0);

    glBegin(GL_LINES);
	glColor3ub(93, 109, 126);

	glVertex2f(-0.6f, -0.7f); //Stand for flag
	glVertex2f(-0.6f, -0.3f);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(100, 149, 237);

    glVertex2f(-0.6f,-0.32f);
    glVertex2f(-0.6f,-0.5f);
    glVertex2f(-0.9f,-0.5f);
    glVertex2f(-0.9f,-0.32f);
    glEnd();
///===========================================================================================
 ///Frontier View
     glBegin(GL_POLYGON);
     glColor3ub(44, 62, 80);

     glVertex2f(-1,-0.7);
     glVertex2f(-1,-1);
     glVertex2f(1,-1);
     glVertex2f(1,-0.7);
     glEnd();
//=======================================================================================
///AIUB Text

    glPointSize(8.0);
    glLineWidth(8.0);

    glBegin(GL_LINES);
	glColor3ub(153, 163, 164);

	glVertex2f(-0.7f, -0.75f);
	glVertex2f(-0.8f, -.95f);

    glVertex2f(-0.7f, -0.75f);
	glVertex2f(-0.6f, -.95f);
///=========================================AAAAAAAAA=====================================
    glVertex2f(-0.75f, -0.85f);
	glVertex2f(-0.65f, -.85f);
///=========================================IIIIIIIIIIII==================================
	glVertex2f(-0.3f, -0.75f);
	glVertex2f(-0.3f, -.95f);

	glVertex2f(0.1f, -0.75f);
	glVertex2f(0.1f, -.9f);

	glVertex2f(0.1f, -0.9f);
	glVertex2f(0.13f, -.95f);

	glVertex2f(0.13f, -0.95f);
	glVertex2f(0.20f, -.95f);

	glVertex2f(0.20f, -0.95f);
	glVertex2f(0.23f, -.9f);

	glVertex2f(0.23f, -0.9f);
	glVertex2f(0.23f, -.75f);
///===================================UUUUUUUUUUUUUU========================================
	glVertex2f(0.63f, -0.75f);
	glVertex2f(0.63f, -.95f);

	glVertex2f(0.63f, -0.75f);
	glVertex2f(0.7f, -.75f);

	glVertex2f(0.7f, -0.75f);
	glVertex2f(0.75f, -.8f);

	glVertex2f(0.75f, -0.8f);
	glVertex2f(0.75f, -.85f);

	glVertex2f(0.75f, -0.85f);
	glVertex2f(0.63f, -.85f);

	glVertex2f(0.75f, -0.85f);
	glVertex2f(0.75f, -.9f);

	glVertex2f(0.63f, -0.95f);
    glVertex2f(0.7f, -.95f);

    glVertex2f(0.7f, -0.95f);
    glVertex2f(0.75f, -.9f);

	glEnd();
///=================================BBBBBBBBBBBBBB============================================

     glLoadIdentity();
     glFlush();
}
///=======================================================================================


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(600, 500);
    glutCreateWindow("AIUB View");
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
