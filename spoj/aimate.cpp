#include<GL/glut.h>
#include <stdlib.h>
#include<math.h>
#define PI 3.141592653589
#define DEG2RAD(deg) (deg * PI / 180)
GLfloat x=0.01;
GLfloat rad=10.0;
GLfloat pos1=0.0;
GLfloat pos ;
GLfloat cos2=10.0,cos1=100.0;

void init(void)
{
 glClearColor(1.0,1.0,1.0,0.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0.0,300.0,0.0,300.0);

}
 void spe(int key,int a,int x,int y){
 	if(key==GLUT_LEFT_BUTTON){
 		cos1=100.0;
 		cos2=10.0;

 	}
 }
void linedaw()
{  glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0,0.0,0.0);
      
	glBegin(GL_TRIANGLE_FAN);
	  
	for(int i=0 ; i<360 ; i++) {
		 pos=rad * cos(DEG2RAD(i))+cos2;
		glVertex2f(pos, rad * sin(DEG2RAD(i))+100.0);
	}
   glEnd(); 
   
   glColor3f(0.0,1.0,0.0);
   glBegin(GL_TRIANGLE_FAN);
	for(int i=0 ; i<360 ; i++) {
		GLfloat pos1=rad * cos(DEG2RAD(i))+cos1;
		glVertex2f(pos1,rad * sin(DEG2RAD(i))+100.0);
	}
   glEnd(); 
   glFlush();
     
   if(cos2<=100-20){
   	cos2=cos2+x;

   }
   else{
   	cos1=cos1+x;
   }
   
   glutPostRedisplay();
}

int  main(int argc, char**argv)
{

 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(400,400);
 glutInitWindowPosition(0,0);
 glutCreateWindow("Digital Differential Analyzer Algorithm: Programmed by Salha");
 init();
 glutMouseFunc(spe);
 glutDisplayFunc(linedaw);
 
 glutMainLoop();
 return 0;
}