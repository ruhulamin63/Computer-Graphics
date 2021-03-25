#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include<iostream>
#include <string>
GLfloat s1 = 0.1f;
GLfloat s2 = 0.1f;
GLfloat sr1 = 0.1f;
GLfloat sr2 = 0.1f;
GLfloat rocketPositionX = 0.0f;
GLfloat rocketPositionY = -0.5f;
GLfloat position1 = 0.0f;
GLfloat position2 = 0.0f;
GLfloat position3 = 0.0f;
GLfloat speed = 0.01f;
GLfloat topx=0.0f,topy=-0.075f;
GLfloat buScX=0.0f,buScY=0.0f,buScz=0.0f,bulletPos=0.0f,bulletSpd=0.0f;
GLfloat buTransX,buTransY,rocketScaleX=1.0f,rocketScaleY=1.0f,rocketScaleZ=1.0;
GLfloat leftobjectY=0.8f, leftMiddleObjectY=0.6f, middleObjectY=0.8f, rightMiddleObjectY=0.6f, rightObjectY=0.8f;
GLfloat leftObjScX=1.0f,leftObjScY=1.0f,leftObjScz=1.0f;
GLfloat leftMidObjScX=1.0f,leftMidObjScY=1.0f,leftMidObjScz=1.0f;
GLfloat MidObjScX=1.0f,MidObjScY=1.0f,MidObjScz=1.0f;
GLfloat rightMidObjScX=1.0f,rightMidObjScY=1.0f,rightMidObjScz=1.0f;
GLfloat rightObjScX=1.0f,rightObjScY=1.0f,rightObjScz=1.0f;
GLfloat bulletHitpos=-0.575f,resetObstacle=0.0f;
char *gameover="",*score="";
int count=0;
void update(int value) {
    if(rocketPositionX<=-0.6f && rocketPositionX>=-0.8f){
            if(leftobjectY<=-0.575f && leftObjScX!=0.0f){
                rocketScaleX=0.0f,rocketScaleY=0.0f,rocketScaleZ=0.0f;
                gameover="Game Over!!";
            }
    }
    if(rocketPositionX<=-0.2f && rocketPositionX>=-0.4f){
            if(leftMiddleObjectY<=-0.575f && leftMidObjScX!=0.0f){
                rocketScaleX=0.0f,rocketScaleY=0.0f,rocketScaleZ=0.0f;
                gameover="Game Over!!";
            }
    }
    if(rocketPositionX<=0.1f && rocketPositionX>=-0.1f){
            if(middleObjectY<=-0.575f && MidObjScX!=0.0f){
                rocketScaleX=0.0f,rocketScaleY=0.0f,rocketScaleZ=0.0f;
                gameover="Game Over!!";
            }
    }
    if(rocketPositionX<=0.4f && rocketPositionX>=0.2f){
            if(rightMiddleObjectY<=-0.575f && rightMidObjScX!=0.0f){
                rocketScaleX=0.0f,rocketScaleY=0.0f,rocketScaleZ=0.0f;
                gameover="Game Over!!";
            }
    }
    if(rocketPositionX<=0.8f && rocketPositionX>=0.6f){
            if(rightObjectY<=-0.575f && rightObjScX!=0.0f){
                rocketScaleX=0.0f,rocketScaleY=0.0f,rocketScaleZ=0.0f;
                gameover="Game Over!!";
            }
    }
    if(buTransX<=-0.6f && buTransX>=-0.8f){
            if(leftobjectY<=bulletHitpos){
                leftObjScX=0.0f,leftObjScY=0.0f,leftObjScz=0.0f;
                //buScX=0.0f, buScY=0.0f, buScz =0.0f;
                count++;
            }
    }
    if(buTransX<=-0.2f && buTransX>=-0.4f){
            if(leftMiddleObjectY<=bulletHitpos){
                leftMidObjScX=0.0f,leftMidObjScY=0.0f,leftMidObjScz=0.0f;
               //buScX=0.0f, buScY=0.0f, buScz =0.0f;
               count++;
            }
    }
    if(buTransX<=0.1f && buTransX>=-0.1f){
            if(middleObjectY<=bulletHitpos){
                MidObjScX=0.0f,MidObjScY=0.0f,MidObjScz=0.0f;
                //buScX=0.0f, buScY=0.0f, buScz =0.0f;
                count++;
            }

    }
    if(buTransX<=0.4f && buTransX>=0.2f){
            if(rightMiddleObjectY<=bulletHitpos){
                rightMidObjScX=0.0f,rightMidObjScY=0.0f,rightMidObjScz=0.0f;
                //buScX=0.0f, buScY=0.0f, buScz =0.0f;
                count++;
            }
    }
    if(buTransX<=0.8f && buTransX>=0.6f){
            if(rightObjectY<=bulletHitpos){
                rightObjScX=0.0f,rightObjScY=0.0f,rightObjScz=0.0f;
                //buScX=0.0f, buScY=0.0f, buScz =0.0f;
                count++;
            }
    }
//std::cout<<count<<std::endl;
//std::cout<<bulletHitpos<<" "<<topy<<" "<<leftobjectY<<std::endl;
//    if(bulletPos<1.7f){
//     resetObstacle+=bulletSpd;
//    }
//    else{
//     resetObstacle=0.0f;
//    }

    if(bulletPos<1.5f){
     bulletPos+=bulletSpd;
     bulletHitpos+=bulletSpd;
    }
    else{
     bulletPos=0.0f,bulletSpd=0.0f,buScX=0.0f,buScY=0.0f,buScz=0.0f;
     bulletHitpos=-0.55f;
    }
    if(leftobjectY<-0.575f){
        leftobjectY=2.1f;
        middleObjectY=2.1f;
        rightObjectY=2.1f;
    }
//    if(leftobjectY==2.05f){
//        leftObjScX=1.0f,leftObjScY=1.0f,leftObjScz=1.0f;
//    }
    if(leftMiddleObjectY<-0.575f){
        leftMiddleObjectY=2.1f;
        rightMiddleObjectY=2.1f;
    }
    if(position1 > 1.0)
        position1 = -1.2f;
    if(position2 < -1.5)
        position2 = 1.2f;
        if(position3 < -1.0)
       position3 = 1.2f;
       position1 += speed;
       position2 -= speed;
       leftobjectY -= speed;
       leftMiddleObjectY -= speed;
       middleObjectY -= speed;
       rightMiddleObjectY -= speed;
       rightObjectY -= speed;
       position3 -= speed;

//       if(resetObstacle>1.7f){
//        leftObjScX=1.0f,leftObjScY=1.0f,leftObjScz=1.0f;
//        leftMidObjScX=1.0f,leftMidObjScY=1.0f,leftMidObjScz=1.0f;
//        MidObjScX=1.0f,MidObjScY=1.0f,MidObjScz=1.0f;
//        rightMidObjScX=1.0f,rightMidObjScY=1.0f,rightMidObjScz=1.0f;
//        rightObjScX=1.0f,rightObjScY=1.0f,rightObjScz=1.0f;
//    }
       glutPostRedisplay();
       glutTimerFunc(35, update, 0);
}
void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
            buTransX=rocketPositionX;
            buTransY=rocketPositionY;
		    buScX=1.0f,buScY=1.0f,buScz=1.0f,bulletSpd=0.02f;
		    resetObstacle=0.0f;
			speed += 0.01f;
		}
	}
	glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {

case 'a':
    if(rocketPositionX>-0.8)
    rocketPositionX -= 0.05f;
    break;
case 'd':
    if(rocketPositionX<0.8)
    rocketPositionX += 0.05f;
    break;
//case 's':
//    if(rocketPositionY>-0.75)
//    rocketPositionY -= 0.05f;
//    break;
//case 'w':
//    if(rocketPositionY<0.99)
//    rocketPositionY += 0.05f;
//    break;
glutPostRedisplay();
}
}

void backgroundStar(){
   glBegin(GL_POINTS);
   glPointSize(10.0);
   glColor3f(0.0f, 1.0f, 1.0f);
   glVertex2f(0.0f, -0.1f);
   glEnd();
}

void bullet(){
   glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.01f,0.0f);
    glVertex2f(0.01f, 0.0f);
    glVertex2f(0.0f, 0.025f);
    glEnd();
}

void createStar()
{
    glScalef(s1,s2,0);
    glColor3d(1,1,1);
    glBegin(GL_POLYGON);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.037f, 0.0f, 0.0f);
        glVertex3f(0.037f, 0.0428f, 0.0f);
        glVertex3f(0.0f, 0.0428f, 0.0f);
	glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(0.0f, 0.0428f, 0.0f);
        glVertex3f(0.0185f, 0.3f, 0.0f);
        glVertex3f(0.037f, 0.0428f, 0.0f);
	glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0185f, -0.27f, 0.0f);
        glVertex3f(0.037f, 0.0f, 0.0f);
	glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0428f, 0.0f);
        glVertex3f(-0.2f, 0.0214f, 0.0f);
	glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(0.037f, 0.0f, 0.0f);
        glVertex3f(0.037f, 0.0428f, 0.0f);
        glVertex3f(0.25f, 0.0214f, 0.0f);
	glEnd();
}

void rocket(){
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.025f,-0.15f);
    glVertex2f(0.025f, -0.15f);
    glVertex2f(topx, topy);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.4f,0.0f);
    glVertex2f(0.035f, -0.4f);
    glVertex2f(0.0f,-0.45f);
    glVertex2f(-0.035f,-0.4f);
    glVertex2f(0.0f,-0.245f);
    glEnd();

    glBegin(GL_QUADS);
    glScalef(sr1,sr2,0);//
    glColor3f(1.0f,1.0f,0.0f);
    glVertex2f(0.015f, -0.35f);
    glVertex2f(0.0f,-0.4f);
    glVertex2f(-0.015f,-0.35f);
    glVertex2f(0.0f,-0.245f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.365f,0.142f,0.142f);
    glVertex2f(0.025f, -0.35f);                 //Right Bottom
    glVertex2f(-0.025f,-0.35f);              //Left Bottom
    glVertex2f(-0.025f,-0.15f);     //Left Top
    glVertex2f(0.025f, -0.15f);              //Right Top
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.045f,-0.195f);
    glVertex2f(-0.025f, -0.195f);
    glVertex2f(-0.025f,-0.16f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.045f,-0.195f);
    glVertex2f(0.025f, -0.195f);
    glVertex2f(0.025f,-0.16f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.045f,-0.35f);
    glVertex2f(-0.025f,-0.35f);
    glVertex2f(-0.025f,-0.275f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.045f,-0.35f);
    glVertex2f(0.025f,-0.35f);
    glVertex2f(0.025f,-0.275f);
    glEnd();
}

void TextPrint( float x, float y, char *st)
{
    int l,i;
    l=strlen( st );
    glColor3f(0.0,1.0,0.7);
    glRasterPos2f( x, y);
    for( i=0; i < l; i++)
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);

    }
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();
glPushMatrix();
glTranslatef(0.0f,bulletPos,0.0f);
glPushMatrix();
//buTransY=rocketPositionY;
glTranslatef(buTransX,buTransY-0.075f, 0.0f);
glScalef(buScX,buScY,buScz);
bullet();
glPopMatrix();
glPopMatrix();
glPushMatrix();
    //drawTextBox();
    glColor3f(1.0,0.0,0.0);
//    TextPrint(-0.1,0.94,"Score : ");
//    TextPrint(0.0,0.94,score+=count);
    TextPrint(-0.05,0.0,gameover);
    glPopMatrix();
   //Star
glPushMatrix();
if(s1==0.1f){
s1+=0.1f;
s2+=0.1f;
}
else if(s1==0.2f){
s1-=0.1f;
s2-=0.1f;
}
glTranslatef(0.2f,-0.2f,0.0f);
createStar();
glPopMatrix();
glPushMatrix();
    glTranslatef(0.0f,0.6f,0.0f);
    createStar();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5f,0.5f,0.0f);
    createStar();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5f,-0.3f,0.0f);
    createStar();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.2f,-0.5f,0.0f);
    createStar();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.7f,-0.35f,0.0f);
    createStar();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5f,-0.8f,0.0f);
    createStar();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.7f,0.7f,0.0f);
    createStar();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4f,-0.6f,0.0f);
    createStar();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.9f,-0.2f,0.0f);
    createStar();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.9f,0.2f,0.0f);
    createStar();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5f,0.3f,0.0f);
    createStar();
    glPopMatrix();
//Star End

glPushMatrix();
glTranslatef(-0.5f,position3+0.9, 0.0f);
   backgroundStar();
glPopMatrix();

glPushMatrix();
glTranslatef(0.5f,position3+0.9, 0.0f);
   backgroundStar();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.3f,position3+0.7, 0.0f);
   backgroundStar();
glPopMatrix();

glPushMatrix();
glTranslatef(0.3f,position3+0.75, 0.0f);
   backgroundStar();
glPopMatrix();

glPushMatrix();
glTranslatef(0.15f,position3+0.3, 0.0f);
   backgroundStar();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.15f,position3+0.3, 0.0f);
   backgroundStar();
glPopMatrix();

glPushMatrix();
glTranslatef(0.3f,position3+1.0, 0.0f);
   backgroundStar();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.1f,position3+1.0, 0.0f);
   backgroundStar();
glPopMatrix();

glPushMatrix();
glTranslatef(0.0f,position3, 0.0f);
   backgroundStar();
glPopMatrix();

glPushMatrix();
glTranslatef(0.4f,position3, 0.0f);
   backgroundStar();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.3f,position3, 0.0f);
   backgroundStar();
glPopMatrix();

glPushMatrix();
glTranslatef(0.3f,position3+0.5, 0.0f);
   backgroundStar();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.5f,position3-0.5, 0.0f);
   backgroundStar();
glPopMatrix();

glPushMatrix();
glTranslatef(0.7f,position3+0.8, 0.0f);
   backgroundStar();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.6f,position3-0.9, 0.0f);
   backgroundStar();
glPopMatrix();

glPushMatrix();
glTranslatef(0.6f,position3-0.9, 0.0f);
   backgroundStar();
glPopMatrix();

//Rocket
glPushMatrix();
glTranslatef(rocketPositionX,rocketPositionY, 0.0f);
glScalef(rocketScaleX,rocketScaleY,rocketScaleZ);
rocket();

glPopMatrix();
//Rocket End

//Rocks
glPushMatrix();
glTranslatef(0.0f,position2,0.0f);
//Middle left object
glPushMatrix();
    glScalef(leftMidObjScX,leftMidObjScY,leftMidObjScz);
   glBegin(GL_QUADS);
    glColor3f(0.5f, 0.0f, 0.5f);
    glVertex2f(-0.2f, 0.6f);                 //Right Bottom
    glVertex2f(-0.4f,0.6f);              //Left Bottom
    glVertex2f(-0.35f,0.7f);     //Left Top
    glVertex2f(-0.25f, 0.7f);              //Right Top
    glEnd();
    glPopMatrix();
//Left side object
glPushMatrix();
    glScalef(leftObjScX,leftObjScY,leftObjScz);
    glBegin(GL_TRIANGLES);
    glColor3f(0.75f, 0.3f, 0.0f);
    glVertex2f(-0.6f, 0.8f);                 //Right Bottom
    glVertex2f(-0.8f,0.8f);
    glVertex2f(-0.7f, 0.9f);              //Right Top
    glEnd();
    glPopMatrix();
//Middle Right object
glPushMatrix();
    glScalef(rightMidObjScX,rightMidObjScY,rightMidObjScz);
   glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 0.5f);
    glVertex2f(0.2f, 0.6f);                 //Right Bottom
    glVertex2f(0.4f,0.6f);              //Left Bottom
    glVertex2f(0.4f,0.7f);     //Left Top
    glVertex2f(0.2f, 0.65f);              //Right Top
    glEnd();
    glPopMatrix();
//Middle object
glPushMatrix();
    glScalef(MidObjScX,MidObjScY,MidObjScz);
   glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex2f(-0.1f, 0.8f);                 //Right Bottom
    glVertex2f(-0.1f,0.85f);              //Left Bottom
    glVertex2f(0.1f,0.95f);     //Left Top
    glVertex2f(0.1f, 0.8f);              //Right Top
    glEnd();
    glPopMatrix();
//Right side object
glPushMatrix();
    glScalef(rightObjScX,rightObjScY,rightObjScz);
   glBegin(GL_QUADS);
    glColor3f(0.75f, 0.9f, 1.0f);
    glVertex2f(0.6f, 0.8f);                 //Right Bottom
    glVertex2f(0.8f,0.8f);              //Left Bottom
    glVertex2f(0.7f,0.9f);     //Left Top
    glVertex2f(0.6f, 0.9f);              //Right Top
    glEnd();
    glPopMatrix();
glPopMatrix();


   glFlush();
}



int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(1600, 820);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("Space Surviving");
   glutDisplayFunc(display);
   init();
   glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);
   glutTimerFunc(1000, update, 0);
   glutMainLoop();
   return 0;
}
