#include<iostream>
#include <windows.h>
#include <GL/glut.h>
#include<GL/gl.h>
#include<math.h>
#include<vector>
# define PI 3.14159265358979323846
using namespace std;

int pnt_x,pnt_y,choice=0,edge,trans_x,trans_y;
double scale_x,scale_y;
int sharing_x,sharing_y;
double angle_x,angle_y;
char reft_axis,sharing_axis;

vector<int>v1,v2;

///================================================
double round(double d){
    return floor(d+0.5);
}
void drawPolygon(){
    glBegin(GL_POLYGON);
     glColor3f(1.0,0.0,0.0);
///========================================
    for(int i=0; i<edge; i++){
        glVertex2i(v1[i], v2[i]);
    }
    glEnd();
}
///=========================================
void drawPolygonTrans(int x, int y){
    glBegin(GL_POLYGON);
     glColor3f(0.0,1.0,0.0);

    for(int i=0; i<edge; i++){
        glVertex2i(v1[i]+x, v2[i]+y);
    }
    glEnd();
}
///=========================================
void drawPolygonScale(int x, int y){
    glBegin(GL_POLYGON);
     glColor3f(0.0,1.0,0.0);

    for(int i=0; i<edge; i++){
        glVertex2i(round(v1[i]*x), round(v2[i]*y));
    }
    glEnd();
}

///================================================

void drawPolygonRotation(double angle_y){
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);

    for(int i=0; i<edge; i++){
        glVertex2i( round((v1[i]*cos(angle_y)) - (v2[i]*sin(angle_y))), round(v1[i]*sin(angle_y) + v2[i]*cos(angle_y)) );
    }
    glEnd();
}

///==================================================
void drawPolygonMirrorReflection(char reft_a){
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);

    if(reft_a=='x' || reft_a=='X'){
        for(int i=0; i<edge; i++){

            glVertex2i(round(v1[i]), round(v2[i]*(-1)));
        }
    }
    else if(reft_a=='y' || reft_a=='Y'){
        for(int i=0; i<edge; i++){
            glVertex2i(round(v1[i]*(-1)), round(v2[i]));
        }
    }
    glEnd();
}
///===========================================
void drawPolygonSharing(){
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);

    if(sharing_axis=='x' || sharing_axis=='X'){
        if(sharing_axis=='x' || sharing_axis=='X'){
            glVertex2i(v1[0], v2[0]);

            glVertex2i(v1[1]+ sharing_x, v2[1]);
            glVertex2i(v1[2]+ sharing_x, v2[2]);

            glVertex2i(v1[3], v2[3]);
        }
        else if(sharing_axis=='y' || sharing_axis=='Y'){
            glVertex2i(v1[0], v2[0]);
            glVertex2i(v1[1], v2[1]);
        }
    }

    glEnd();
}
///================================================

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);

    if(choice==1){
        drawPolygon();
        drawPolygonTrans(trans_x,trans_y);
    }
    else if(choice==2){
        drawPolygon();
        drawPolygonScale(scale_x,scale_y);
    }
    else if(choice==3){
        drawPolygon();
        drawPolygonRotation(angle_y);
    }

    else if(choice==4){
        drawPolygon();
        drawPolygonMirrorReflection(reft_axis);
    }
    else if(choice==5){
        drawPolygon();
        drawPolygonSharing();
    }
    glFlush();
}
///==========================================================

void myInit(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glLoadIdentity();
    gluOrtho2D(900.0, 0.0, 700.0, 0.0);
}

///===================================================
int main(int argc, char** argv){

    cout<<"Enter your choice...?"<<endl;
        cout<<"1.Translation"<<endl;
        cout<<"2.Scaling"<<endl;
        cout<<"3.Rotation"<<endl;
        cout<<"4.Mirror"<<endl;
        cout<<"5.Sharing"<<endl;
        cout<<"6.Exit"<<endl;

            cin>>choice;

        if(choice==6){
            return 0;
        }

///=================================================================
    cout<<"\n\nFor Polygon...?\n"<<endl;
    cout<<"Enter no of edges = ";
        cin>>edge;

    if(edge>=4){
        for(int i=1; i<=edge; i++){
            cout<<"Enter co-ordinates for vertex "<<i<<" = ";
                cin>>pnt_x>>pnt_y;

                v1.push_back(pnt_x);
                v2.push_back(pnt_y);
        }
    }
    else{
        cout<<"At least 4 number of edge needed...?"<<endl;
    }
///===================================================================

    if(choice==1){
        cout<<"Enter the translation factor X & Y: ";
            cin>>trans_x>>trans_y;
    }
    else if(choice==2){
        cout<<"Enter the rcaling factor X & Y: ";
            cin>>scale_x>>scale_y;
    }
    else if(choice==3){
        cout<<"Enter the rotation factor X & Y: ";
            cin>>angle_x;

            angle_y=angle_x*(3.1416/180);
    }
    else if(choice==4){
        cout<<"Enter the mirror axis: ";
            cin>>reft_axis;
    }
    else if(choice==5){
        cout<<"Enter the sharing factor X or Y: ";
            cin>>sharing_x>>sharing_y;

        if(sharing_axis=='x'||sharing_axis=='X'){
            cout<<"Enter the sharing factor for X = ";
                cin>>sharing_x;
        }
        else{
            cout<<"Enter the sharing factor for Y = ";
                cin>>sharing_y;
        }
    }
///=================================================================

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100,150);
	glutCreateWindow("2D Transformation(Designed By Ruhul Amin)");
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();

	return 0;
}

