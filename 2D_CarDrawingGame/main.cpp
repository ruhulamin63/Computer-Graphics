#include<windows.h>
#include<cstdio>
#include<iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265f

using namespace std;

///==============================================================================
    ///Position view
    GLfloat position=100;
    GLfloat position2 = 100;
    GLfloat position3 = 30;
    GLfloat position4=100;
    GLfloat position5=90;
    GLfloat positionSky=100;
    GLfloat position6=80;

    ///Speed view
    GLfloat speed2 = 0.2; ///cloud speed
    GLfloat speed3 = 0.6; ///bird speed
    GLfloat speed4 = 0.1; ///bird sun and moon
    GLfloat speed5 = 0.1; ///star

///==============================================================================

    ///Game Speed
    int FPS = 10;

    ///Game Track
    int start=0;
    int gv=0;
    int level = 0;

    ///Track Score
    int score = 0;

///==============================================================================

    ///Form move track
    int roadDivTopMost = 0;
    int roadDivTop = 0;
    int roadDivMdl = 0;
    int roadDivBtm = 0;

///==============================================================================

    ///For Car Left / RIGHT
    int main_car = 0 ;

    ///Car Coming
    int car_1 = -30;
    int car_1_Index=0;
    int car_2 =-80;
    int car_2_Index=0;
    int car_3 = -130;
    int car_3_Index=0;

    ///Text font size
    const int font1=(int)GLUT_BITMAP_TIMES_ROMAN_24;
    const int font2=(int)GLUT_BITMAP_HELVETICA_18 ;
    const int font3=(int)GLUT_BITMAP_8_BY_13;
    const int font4=(int)GLUT_BITMAP_TIMES_ROMAN_24;

///==============================================================================

    char s[30];
void renderBitmapString(float x, float y, void *font,const char *string){
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

///==============================================================================

void update2(int value) {

    if(position2 <-100){
        position2 = 100;
    }
    else if(position2 > 100){
        position2 = 0.0 ;
    }
    position2 -= speed2;

	glutPostRedisplay();

	glutTimerFunc(100, update2, 0);
}

///==============================================================================

void update3(int value) {

    if(position3 <-100){
        position3 = 30;
    }
    else if(position3 > 100){
        position3 = 0.0 ;
    }
    position3 -= speed3;

	glutPostRedisplay();

	glutTimerFunc(100, update3, 0);
}

///==============================================================================

void update4(int value) {

    if(position4 <-15){
        position4 = 67;
    }
    else if(position4 >67){
        position4 = 7 ;
    }
    position4 -= speed4;

	glutPostRedisplay();

	glutTimerFunc(100, update4, 0);
}

///==============================================================================

void update5(int value) {

    if(position5 <-67){
        position5 = 15;
    }
    else if(position5 >15){
        position5 = -45 ;
    }
    position5 -= speed4;

	glutPostRedisplay();

	glutTimerFunc(100, update5, 0);
}

///==============================================================================
void updateSky(int value) {

    if(positionSky <-40){
        positionSky = 42;
    }
    else if(positionSky >62){
        positionSky = -20 ;
    }
    positionSky -= speed4;

	glutPostRedisplay();

	glutTimerFunc(100, updateSky, 0);
}

void update6(int value) {

    if(position6 <-67){
        position6 = 15;
    }
    else if(position6 >15){
        position6 = -45 ;
    }
    position6 -= speed5;

	glutPostRedisplay();

	glutTimerFunc(100, update6, 0);
}

///==============================================================================

void DrawCircle(float cx, float cy, float r, int num_segments){

     glBegin(GL_POLYGON);
     //glColor3f(0.4, 0.4, 0.2);

    for (int i = 0; i < num_segments; i++){
        float theta = 2.0f * PI * float(i) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}

///==============================================================================

void DrawHalfCircle(float cx, float cy, float r, int num_segments){

     glBegin(GL_POLYGON);

    ///glColor3f(0.4, 0.4, 0.2);
    for (int i = 0; i <= (num_segments/2); i++){

        float theta = 2.0f * PI * float(i) / float(num_segments);///get the current angle

        float x = r * cosf(theta);///calculate the x component
        float y = r * sinf(theta);///calculate the y component

        glVertex2f(x + cx, y + cy);///output vertex

    }
    glEnd();
}

///==============================================================================

void startGame() {

	glClearColor(0.5f, 0.9f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

///===============================================================================

    glPushMatrix();
    glTranslatef(0.0f,0.0f, 0.0f);

   ///Sky
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f-(positionSky*0.8), 0.7f-(positionSky*0.8));

    glVertex2f(100,100);
    glVertex2f(100,50);
    glVertex2f(0.0,50);
    glVertex2f(0.0,100.0);
    glEnd();
    glPopMatrix();

///==========================================================================
    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);

    ///Sun
    glColor3f(1.0f, 0.7f, 0.1f);
	DrawCircle(20, 85, 10, 1000);
	glPopMatrix();
    glPushMatrix();

///==========================================================================

    glTranslatef(0.0f,-position5, 0.0f);

    ///moon
    glColor3f(1.0f, 1.0f, 0.7f);
	DrawCircle(80, 85, 10, 1000);
	glPopMatrix();

///=========================================================================

	///Bird
    glPushMatrix();
    glTranslatef(position3, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES); //Bird 1
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(90,90);
    glVertex2f(87,93);
    glVertex2f(85,92);
    glEnd();

    glBegin(GL_TRIANGLES); //Bird 1
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(90,90);
    glVertex2f(94.5,91.5);
    glVertex2f(93,93);
    glEnd();

    glBegin(GL_TRIANGLES); //Bird 2
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(75,89);
    glVertex2f(79,91);
    glVertex2f(77,92);
    glEnd();

    glBegin(GL_TRIANGLES); //Bird 2
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(75,89);
    glVertex2f(72,92);
    glVertex2f(70,91);
    glEnd();

    glBegin(GL_TRIANGLES); //Bird 3
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(82.5,85);
    glVertex2f(79.5,88);
    glVertex2f(77,87);
    glEnd();

    glBegin(GL_TRIANGLES); //Bird 3
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(82.5,85);
    glVertex2f(86.5,87);
    glVertex2f(84.5,88);
    glEnd();

    glPopMatrix();


///=======================================================================

    ///star 1
    glPushMatrix();
    glTranslatef(0.0f,-position6, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(15,80);
    glVertex2f(16,81);
    glVertex2f(17,80);
    glVertex2f(16,84);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(16.66,81.5);
    glVertex2f(17.5,82.5);
    glVertex2f(16.33,82.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(15.33,81.5);
    glVertex2f(15.66,82.5);
    glVertex2f(14.5,82.5);
    glEnd();

    ///star 2
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(35,90);
    glVertex2f(36,91);
    glVertex2f(37,90);
    glVertex2f(36,94);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(36.66,91.5);
    glVertex2f(37.5,92.5);
    glVertex2f(36.33,92.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(35.33,91.5);
    glVertex2f(35.66,92.5);
    glVertex2f(34.5,92.5);
    glEnd();

     ///star 3
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(55,75);
    glVertex2f(56,76);
    glVertex2f(57,75);
    glVertex2f(56,79);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(56.66,76.5);
    glVertex2f(57.5,77.5);
    glVertex2f(56.33,77.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(55.33,76.5);
    glVertex2f(55.66,77.5);
    glVertex2f(54.5,77.5);
    glEnd();
    glPopMatrix();

///============================================================
    ///Cloud with motion
    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(50,80 ,10,100);
    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(60, 80,7,100);
    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(40, 80,6,100);

    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(88.5, 90,10,100);
    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(98.5, 90,7,100);
    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(78.5, 90,6,100);

    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(11.5, 90,10,100);
    glColor3f(1.0f, 1.0f, 1.0f);

    DrawCircle(1.5, 90,5,100);
    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(21.5, 90,7.75,100);
    glPopMatrix();

///====================================================================

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(5, 0);
    glVertex2f( 40, 50.0);
    glVertex2f( 0.0, 50.0f);
    glVertex2f(  0.0, 0.0);
    glEnd();

    glTranslatef(0.0f,0.0f, 0.0f);
    glPushMatrix();
    glColor3f(1.0f, 0.7f, 0.1f);
	DrawCircle(50, 50, 10, 1000);
	glPopMatrix();

    ///road color gray
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.54, 0.51);

    glVertex2f(23, 0);
    glVertex2f( 78, 0);
    glVertex2f( 78, 80);
    glVertex2f(23, 80);
    glEnd();

    ///road side grass left
    glBegin(GL_POLYGON);
    //glColor3f(0.001, 0.745, 0.11);
    glColor3f(0.001, 0.745-(positionSky*0.1), 0.11);
    glVertex2f(23, 0);
    glVertex2f( 23, 80);
    glVertex2f( 0, 80);
    glVertex2f(0, 0);
    glEnd();

    ///road side grass right
    glBegin(GL_POLYGON);
    //glColor3f(0.001, 0.745, 0.11);
    glColor3f(0.001, 0.745-(positionSky*0.1), 0.11);

    glVertex2f(78, 0);
    glVertex2f(78, 80);
    glVertex2f(100, 80);
    glVertex2f(100,  0);
    glEnd();

    ///road side border
    glTranslatef(0.0f,0.0f, 0.0f);
    glLineWidth(550);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);

    ///road side border right
    glVertex2f(78,80);
    glVertex2f(78,0);

    ///road side border left
    glVertex2f(23,80);
    glVertex2f(23,0);
    glEnd();

    glPopMatrix();

    ///Tree
   glBegin(GL_POLYGON);
    glColor3f(0.3, 0.0, 0.0);
    glVertex2f(10, 20);
    glVertex2f(12, 20);
    glVertex2f(12, 35);
    glVertex2f(10, 35);
    glEnd();

    glBegin(GL_POLYGON);
    //glColor3f(0.0, 1.0, 0.0);
    glColor3f(0.66, 1.0-(positionSky*0.1), 0.0);
    glVertex2f(6, 35);
    glVertex2f(16, 35);
    glVertex2f(11, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.0, 0.0);
    glVertex2f(90, 20);
    glVertex2f(92, 20);
    glVertex2f(92, 35);
    glVertex2f(90, 35);
    glEnd();

    glBegin(GL_POLYGON);
    //glColor3f(0.0, 1.0, 0.0);
    glColor3f(0.66, 1.0-(positionSky*0.1), 0.0);

    glVertex2f(86, 35);
    glVertex2f(96, 35);
    glVertex2f(91, 50);
    glEnd();

///-----------------------------------------------------------------------------

///Road Middle Border

    ///TOP
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(49,roadDivTop+60);
    glVertex2f(49,roadDivTop+75);
    glVertex2f(51,roadDivTop+75);
    glVertex2f(51,roadDivTop+60);
    glEnd();

    roadDivTop--;
    if(roadDivTop<-75){
        roadDivTop =15;
        score++;
    }

    ///Middle
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(49,roadDivMdl+30);
    glVertex2f(49,roadDivMdl+45);
    glVertex2f(51,roadDivMdl+45);
    glVertex2f(51,roadDivMdl+30);
    glEnd();

    roadDivMdl--;
    if(roadDivMdl<-45){
        roadDivMdl =45;
        score++;
    }

    ///Bottom
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(49,roadDivBtm+0);
    glVertex2f(49,roadDivBtm+15);
    glVertex2f(51,roadDivBtm+15);
    glVertex2f(51,roadDivBtm+0);
    glEnd();

    roadDivBtm--;
    if(roadDivBtm<-15){
        roadDivBtm=75;
        score++;
    }
///================== Update now========================

    glPushMatrix();
    glTranslatef(0.0f,0.0f, 0.0f);

///Hills
    glColor3f(0.4, 0.4, 0.2);
    DrawHalfCircle(10, 80, 10.25, 10); //1
    glColor3f(0.4, 0.4, 0.2);
    DrawHalfCircle(30,80,10.25,10);//2
    glColor3f(0.2, 0.2, .2);
    DrawHalfCircle(50,80,11,10);//3
    glColor3f(0.2, 0.2, .2);
    DrawHalfCircle(70, 80, 10.25, 10);
    glColor3f(0.2, 0.2, .2);
    DrawHalfCircle(90, 80, 10.25, 10);

    glPopMatrix();

///====================================================

    ///Score Board
    glColor3f(0.000, 0.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(80,76);
    glVertex2f(100,76);
    glVertex2f(100,74-8);
    glVertex2f(80,74-8);
    glEnd();

    ///Print Score
    char buffer [50];
    sprintf (buffer, "SCORE: %d", score);
    glColor3f(1.000, 1.000, 0.000);
    renderBitmapString(80.5,73,(void *)font3,buffer);

    ///Speed Print
    char buffer1 [50];
    sprintf (buffer1, "SPEED:%d Km/h", FPS);
    glColor3f(1.000, 1.000, 0.000);
    renderBitmapString(80.5,72-2,(void *)font3,buffer1);

    ///level Print
    if(score % 20 == 0){
        int last = score /20;
        if(last!=level){
            level = score /20;
            FPS=FPS+2;

        }
    }
    char level_buffer [50];
    sprintf (level_buffer, "LEVEL: %d", level);
    glColor3f(1.000, 1.000, 0.000);
    renderBitmapString(80.5,71-4,(void *)font3,level_buffer);


///==================================================================

    glPopMatrix();

///====================================================================

///Main car

    ///Front Tire
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(main_car+27-2,5);
    glVertex2f(main_car+27-2,7);
    glVertex2f(main_car+29+2,7);
    glVertex2f(main_car+29+2,5);
    glEnd();

    ///Back Tire
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(main_car+27-2,1);
    glVertex2f(main_car+27-2,3);
    glVertex2f(main_car+29+2,3);
    glVertex2f(main_car+29+2,1);
    glEnd();

    ///Car Body
    glColor3ub(52, 152, 219);
    glBegin(GL_POLYGON);
    glVertex2f(main_car+26,1);
    glVertex2f(main_car+26,8);
    glVertex2f(main_car+28,10);
    glVertex2f(main_car+30,8);
    glVertex2f(main_car+30,1);
    glEnd();

///===========================================

///Opposite car 1

    ///Font Tire
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(car_1_Index+27-2,car_1+80-4);
    glVertex2f(car_1_Index+27-2,car_1+80-6);
    glVertex2f(car_1_Index+29+2,car_1+80-6);
    glVertex2f(car_1_Index+29+2,car_1+80-4);
    glEnd();

    ///Back Tire
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(car_1_Index+27-2,car_1+80);
    glVertex2f(car_1_Index+27-2,car_1+80-2);
    glVertex2f(car_1_Index+29+2,car_1+80-2);
    glVertex2f(car_1_Index+29+2,car_1+80);
    glEnd();

    ///Car Body
    glColor3f(1.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(car_1_Index+26,car_1+80);
    glVertex2f(car_1_Index+26,car_1+80-7);
    glVertex2f(car_1_Index+28,car_1+80-9);
    glVertex2f(car_1_Index+30,car_1+80-7);
    glVertex2f(car_1_Index+30,car_1+80);
    glEnd();

    car_1--;
    if(car_1<-80){
        car_1=0;
        car_1_Index=main_car;
    }
    ///Kill check car_1
    if((abs(main_car-car_1_Index)<8) && (car_1+80<10)){
            start = 0;
            gv=1;

    }

///===================================================================

///Opposite car 2

    ///Font Tire
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(car_2_Index+27-2,car_2+80-4);
    glVertex2f(car_2_Index+27-2,car_2+80-6);
    glVertex2f(car_2_Index+29+2,car_2+80-6);
    glVertex2f(car_2_Index+29+2,car_2+80-4);
    glEnd();

    ///Back Tire
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(car_2_Index+27-2,car_2+80);
    glVertex2f(car_2_Index+27-2,car_2+80-2);
    glVertex2f(car_2_Index+29+2,car_2+80-2);
    glVertex2f(car_2_Index+29+2,car_2+80);
    glEnd();

    ///Car Body
    glColor3b(162, 36, 207);
    glBegin(GL_POLYGON);
    glVertex2f(car_2_Index+26,car_2+80);
    glVertex2f(car_2_Index+26,car_2+80-7);
    glVertex2f(car_2_Index+28,car_2+80-9);
    glVertex2f(car_2_Index+30,car_2+80-7);
    glVertex2f(car_2_Index+30,car_2+80);
    glEnd();

    car_2--;
    if(car_2<-80){
        car_2=0;
        car_2_Index=main_car;
    }
    ///Kill check car_2
    if((abs(main_car-car_2_Index)<8) && (car_2+80<10)){
            start = 0;
            gv=1;
    }

///=======================================================================

///Opposite car 3

    ///Font Tire
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(car_3_Index+27-2,car_3+80-4);
    glVertex2f(car_3_Index+27-2,car_3+80-6);
    glVertex2f(car_3_Index+29+2,car_3+80-6);
    glVertex2f(car_3_Index+29+2,car_3+80-4);
    glEnd();

    ///Back Tire
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(car_3_Index+27-2,car_3+80);
    glVertex2f(car_3_Index+27-2,car_3+80-2);
    glVertex2f(car_3_Index+29+2,car_3+80-2);
    glVertex2f(car_3_Index+29+2,car_3+80);
    glEnd();

    ///Car Body
    glColor3f(1.000, 0.271, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(car_3_Index+26,car_3+80);
    glVertex2f(car_3_Index+26,car_3+80-7);
    glVertex2f(car_3_Index+28,car_3+80-9);
    glVertex2f(car_3_Index+30,car_3+80-7);
    glVertex2f(car_3_Index+30,car_3+80);
    glEnd();

    car_3--;
    if(car_3<-80){
        car_3=0;
        car_3_Index=main_car;
    }
    ///Kill check car_3
    if((abs(main_car-car_3_Index)<8) && (car_3+80<10)){
            start = 0;
            gv=1;

    }
    glFlush();
}

///====================================================================

void ExitGame(){

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(5, 0);
    glVertex2f( 40, 50.0);
    glVertex2f( 0.0, 50.0f);
    glVertex2f(  0.0, 0.0);
    glEnd();

    ///Save model-view matrix setting
    glPushMatrix();

    glTranslatef(0.0f,0.0f, 0.0f);

    glPushMatrix();
    glColor3f(1.0f, 0.7f, 0.1f);
	DrawCircle(50, 50, 10, 1000);
	glPopMatrix();

    ///road color gray
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.54, 0.51);

    glVertex2f(20, 0);
    glVertex2f( 80, 0);
    glVertex2f( 65, 50);
    glVertex2f(30, 50);
    glEnd();

    ///road side grass left
    glBegin(GL_POLYGON);
    //glColor3f(0.001, 0.745, 0.11);
    glColor3f(0.001, 0.745-(positionSky*0.1), 0.11);
    glVertex2f(20, 0);
    glVertex2f( 35, 50);
    glVertex2f( 0, 50);
    glVertex2f(0, 0);
    glEnd();

    ///road side grass right
    glBegin(GL_POLYGON);
    //glColor3f(0.001, 0.745, 0.11);
    glColor3f(0.001, 0.745-(positionSky*0.1), 0.11);

    glVertex2f(80, 0);
    glVertex2f(65, 50);
    glVertex2f(100, 50);
    glVertex2f(100,  0);
    glEnd();

    ///road side border
    glTranslatef(0.0f,0.0f, 0.0f);

    glLineWidth(550);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);

    ///road side border right
    glVertex2f(65,50);
    glVertex2f(80,0);

    ///road side border left
    glVertex2f(35,50);
    glVertex2f(20,0);
    glEnd();

    /// Restore the model-view matrix
    glPopMatrix();

    ///Tree
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.0, 0.0);
    glVertex2f(10, 20);
    glVertex2f(12, 20);
    glVertex2f(12, 35);
    glVertex2f(10, 35);
    glEnd();

    glBegin(GL_POLYGON);
    //glColor3f(0.0, 1.0, 0.0);
    glColor3f(0.66, 1.0-(positionSky*0.1), 0.0);
    glVertex2f(6, 35);
    glVertex2f(16, 35);
    glVertex2f(11, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.0, 0.0);
    glVertex2f(90, 20);
    glVertex2f(92, 20);
    glVertex2f(92, 35);
    glVertex2f(90, 35);
    glEnd();

    glBegin(GL_POLYGON);
    //glColor3f(0.0, 1.0, 0.0);
    glColor3f(0.66, 1.0-(positionSky*0.1), 0.0);

    glVertex2f(86, 35);
    glVertex2f(96, 35);
    glVertex2f(91, 50);
    glEnd();

///-----------------------------------------------------------------------------

///Road middle boarder

   ///TOP
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(49,35);
    glVertex2f(49,45);
    glVertex2f(51,45);
    glVertex2f(51,35);
    glEnd();

    ///Middle
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(49,20);
    glVertex2f(49,30);
    glVertex2f(51,30);
    glVertex2f(51,20);
    glEnd();

    ///Bottom
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(49,5);
    glVertex2f(49,15);
    glVertex2f(51,15);
    glVertex2f(51,5);
    glEnd();

///================================================================

    glPushMatrix();
    glTranslatef(0.0f,0.0f, 0.0f);

   ///Sky
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f-(positionSky*0.8), 0.7f-(positionSky*0.8));

    glVertex2f(100,100);
    glVertex2f(100,50);
    glVertex2f(0.0,50);
    glVertex2f(0.0,100.0);
    glEnd();
    glPopMatrix();

///==========================================================================
    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);

    ///Sun
    glColor3f(1.0f, 0.7f, 0.1f);
	DrawCircle(20, 85, 10, 1000);
	glPopMatrix();
    glPushMatrix();

///=====================================================================

    glTranslatef(0.0f,-position5, 0.0f);

    ///Moon
    glColor3f(1.0f, 1.0f, 0.7f);
	DrawCircle(80, 85, 10, 1000);
	glPopMatrix();

///===================================================================
	///Bird
    glPushMatrix();
    glTranslatef(position3, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES); //Bird 1
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(90,90);
    glVertex2f(87,93);
    glVertex2f(85,92);
    glEnd();

    glBegin(GL_TRIANGLES); //Bird 1
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(90,90);
    glVertex2f(94.5,91.5);
    glVertex2f(93,93);
    glEnd();

    glBegin(GL_TRIANGLES); //Bird 2
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(75,89);
    glVertex2f(79,91);
    glVertex2f(77,92);
    glEnd();

    glBegin(GL_TRIANGLES); //Bird 2
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(75,89);
    glVertex2f(72,92);
    glVertex2f(70,91);
    glEnd();

    glBegin(GL_TRIANGLES); //Bird 3
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(82.5,85);
    glVertex2f(79.5,88);
    glVertex2f(77,87);
    glEnd();

    glBegin(GL_TRIANGLES); //Bird 3
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(82.5,85);
    glVertex2f(86.5,87);
    glVertex2f(84.5,88);
    glEnd();

    glPopMatrix();

///=======================================================================

    ///star 1
    glPushMatrix();
    glTranslatef(0.0f,-position6, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(15,80);
    glVertex2f(16,81);
    glVertex2f(17,80);
    glVertex2f(16,84);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(16.66,81.5);
    glVertex2f(17.5,82.5);
    glVertex2f(16.33,82.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(15.33,81.5);
    glVertex2f(15.66,82.5);
    glVertex2f(14.5,82.5);
    glEnd();

    ///star 2
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(35,90);
    glVertex2f(36,91);
    glVertex2f(37,90);
    glVertex2f(36,94);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(36.66,91.5);
    glVertex2f(37.5,92.5);
    glVertex2f(36.33,92.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(35.33,91.5);
    glVertex2f(35.66,92.5);
    glVertex2f(34.5,92.5);
    glEnd();

     ///star 3
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(55,75);
    glVertex2f(56,76);
    glVertex2f(57,75);
    glVertex2f(56,79);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(56.66,76.5);
    glVertex2f(57.5,77.5);
    glVertex2f(56.33,77.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(55.33,76.5);
    glVertex2f(55.66,77.5);
    glVertex2f(54.5,77.5);
    glEnd();
    glPopMatrix();


///====================================================================

    ///Cloud with motion
    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(50,80 ,10,100);
    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(60, 80,7,100);
    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(40, 80,6,100);

    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(88.5, 90,10,100);
    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(98.5, 90,7,100);
    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(78.5, 90,6,100);

    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(11.5, 90,10,100);
    glColor3f(1.0f, 1.0f, 1.0f);

    DrawCircle(1.5, 90,5,100);
    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(21.5, 90,7.75,100);
    glPopMatrix();
///====================================================================

///Hills
    glPushMatrix();
    glTranslatef(0.0f,0.0f, 0.0f);

    glColor3f(0.4, 0.4, 0.2);
    DrawHalfCircle(20, 50, 20.25, 8); //1
    glColor3f(0.4, 0.4, 0.2);
    DrawHalfCircle(40,50,20.25,8);//2
    glColor3f(0.2, 0.2, .2);
    DrawHalfCircle(60,50,25,8);//3
    glColor3f(0.2, 0.2, .2);
    DrawHalfCircle(80, 50, 25, 8);

    glPopMatrix();

///====================================================================

    ///Menu Place Holder
    glColor3b(185, 82, 51);
    glBegin(GL_POLYGON);
    glVertex2f(32-4,50+5+10);
    glVertex2f(32+46,50+5+10);
    glVertex2f(32+46,50-15+10);
    glVertex2f(32-4,50-15+10);
    glEnd();

    glColor3f(00, 0, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(32-4,50+5+10);
    glVertex2f(32+46,50+5+10);
    glVertex2f(32+46,50+4+10);
    glVertex2f(32-4,50+4+10);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(32+45,50+5+10);
    glVertex2f(32+46,50+5+10);
    glVertex2f(32+46,50-15+10);
    glVertex2f(32+45,50-15+10);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(32-4,50-14+10);
    glVertex2f(32+46,50-14+10);
    glVertex2f(32+46,50-15+10);
    glVertex2f(32-4,50-15+10);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(32-4,50+5+10);
    glVertex2f(32-5,50+5+10);
    glVertex2f(32-5,50-15+10);
    glVertex2f(32-4,50-15+10);
    glEnd();

///Text Information in First Page
    glColor3f(0.000, 0.000, 0.000);
    renderBitmapString(28,80,(void *)font1," CAR   RACING   GAME ");

    if(gv==1){
        glColor3f(1.000, 0.000, 0.000);
        renderBitmapString(34,80-6,(void *)font1,"GAME OVER");
        glColor3f(1.000, 0.000, 0.000);
        char buffer2 [50];
        sprintf (buffer2, "Your Score is : %d", score);
        renderBitmapString(34,80-10,(void *)font1,buffer2);

        char show_level_buffer [50];
        sprintf (show_level_buffer, "Level: %d", level);
        glColor3f(1.000, 0.000, 0.000);
        renderBitmapString(40,80-14,(void *)font1,show_level_buffer);

    }

    glColor3f(0.000, 1.000, 0.000);
    renderBitmapString(30,50+10,(void *)font2,"Press SPACE to START");
    renderBitmapString(30,50-3+10,(void *)font2,"Press ESC to Exit");

    glColor3f(1.000, 1.000, 1.000);
    renderBitmapString(30,50-6+10,(void *)font3,"Press UP to increase Speed");
    renderBitmapString(30,50-8+10,(void *)font3,"Press DWON to decrease Speed");
    renderBitmapString(30,50-10+10,(void *)font3,"Press RIGHT to turn Right");
    renderBitmapString(30,50-12+10,(void *)font3,"Press LEFT to turn Left");
}

///=====================================================================

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    if(start==1){

        glClearColor(0.000, 0.392, 0.000,1);
        startGame();
    }

    else{
        ExitGame();
    }
    glFlush();

    ///Double buffered - swap the front and back buffers
    glutSwapBuffers();
}

///======================================================================

///Callback handler for special-key event

void spe_key(int key, int x, int y){

        switch (key) {

        case GLUT_KEY_DOWN:
            if(FPS>(10+(level*2)))
                FPS=FPS-2;
                break;

        case GLUT_KEY_UP:
            FPS=FPS+2;
            break;

        case GLUT_KEY_LEFT:
            if(main_car>=0){
                main_car = main_car - (FPS/10);
                if(main_car<0){
                    main_car=-1;
                }
            }
            break;


        case GLUT_KEY_RIGHT:
            if(main_car<=44){
                main_car = main_car + (FPS/10);
                if(main_car>44){
                    main_car = 46;
                }
            }
            break;

            default:
                break;
        }

}

///======================================================================

void processKeys(unsigned char key, int x, int y) {

      switch (key){
        case ' ':

        if(start==0){
            start = 1;
            gv = 0;
            FPS = 10;
            roadDivTopMost = 0;
            roadDivTop = 0;
            roadDivMdl = 0;
            roadDivBtm = 0;
            main_car = 0 ;
            car_1 = -30;
            car_1_Index=0;
            car_2 = -80;
            car_2_Index=0;
            car_3 = -130;
            car_3_Index=0;
            score=0;
            level=0;
        }
         break;
            ///Game Exit operation
            case 27:
                 exit(0);
            default:
                break;
    }
}

void timer(int){
    glutPostRedisplay();    /// Post a re-paint request to activate display()
    glutTimerFunc(1000/FPS,timer,0);
}

///=====================================================================

int main(int argc, char** argv) {
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(700, 600);
	glutCreateWindow("Car Racing For Group Blue");
	gluOrtho2D(0,100,0,100);
	glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(processKeys );

    glutTimerFunc(100, update2, 0);
    glutTimerFunc(100, update3, 0);
    glutTimerFunc(100, update4, 0);
    glutTimerFunc(100, update5, 0);
    glutTimerFunc(100, updateSky, 0);
    glutTimerFunc(100, update6, 0);
    glutTimerFunc(1000,timer,0);

	glutMainLoop(); /// Enter the infinite event-processing loop

	return 0;
}
