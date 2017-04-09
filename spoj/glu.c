#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>

void initialize(){

	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-100.0,100.0,-100.0,100.0);
	glEnd();
	glFlush();
}

void lineSeg(){
	glColor3f(1.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);
		glVertex2i(0.0,-100.0);
		glVertex2i(0.0,100.0); // first line needs two vertex
		glVertex2i(-100.0,0.0);
		glVertex2i(100.0,0.0); // 2nd line another
	glEnd();
	glFlush();
}

void Poly(){
	glColor3f(1.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
		glVertex3f(75.0,25.0,0.0);
		glVertex3f(25.0,25.0,0.0);
		glVertex3f(25.0,75.0,0.0);
		glVertex3f(75.0,75.0,0.0);
	glEnd();
	glFlush();
}

void Transformation(){
	int x;
	glColor3f(1.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	//to draw coordinate axes
	glBegin(GL_LINES);
		glVertex2i(0.0,-100.0);
		glVertex2i(0.0,100.0); // first line needs two vertex
		glVertex2i(-100.0,0.0);
		glVertex2i(100.0,0.0); // 2nd line another
	glEnd();
	//to create a triangle
	float x1=0.0, y1=0.0, x2=10.0, y2=0.0, x3=0.0, y3=10.0;
	glBegin(GL_POLYGON);
		glVertex3f(x1,y1,0.0);
		glVertex3f(x2,y2,0.0);
		glVertex3f(x3,y3,0.0);
	glEnd();
	glFlush();
	printf("Enter the option");
	printf("1.Translation\n2.Rotation\n3.Scaling\n4.Shearing\n");
	scanf("%d",&x);
	switch(x){
		case 1:  //Translation
			 printf("enter the translation distances in x,y\n");
			 float tx,ty;
			 scanf("%f %f",&tx,&ty);
			 float x10=x1+tx;
			 float y10=y1+ty;
			 float x20=x2+tx;
			 float y20=y2+ty;
			 float x30=x3+tx;
			 float y30=y3+ty;
			 glColor3f(0.0,0.0,1.0);
			 glBegin(GL_POLYGON);
				glVertex3f(x10,y10, 0.0);
				glVertex3f(x20,y20, 0.0);
				glVertex3f(x30,y30, 0.0);
			glEnd();
			glFlush();
		       break;
		case 2://Rotation
			printf("enter the rotation angle\n");
			int r;
			scanf("%d",&r);
			float x11=cos(r*(float)3.14/180)*x1-sin(r*(float)3.14/180)*y1;
			float y11=sin(r*(float)3.14/180)*x1+cos(r*(float)3.14/180)*y1;
			float x21=cos(r*(float)3.14/180)*x2-sin(r*(float)3.14/180)*y2;
			float y21=sin(r*(float)3.14/180)*x2+cos(r*(float)3.14/180)*y2;
			float x31=cos(r*(float)3.14/180)*x3-sin(r*(float)3.14/180)*y3;
			float y31=sin(r*(float)3.14/180)*x3+cos(r*(float)3.14/180)*y3;
			glColor3f(0.0,0.0,1.0);
			glBegin(GL_POLYGON);
				glVertex3f(x11,y11, 0.0);
				glVertex3f(x21,y21, 0.0);
				glVertex3f(x31,y31, 0.0);
			glEnd();
			glFlush();
		       break;
		case 3://Scaling
			printf("enter the scaling factor\n");
			float Sx,Sy;
			scanf("%f %f",&Sx,&Sy);
			float x12=x1*Sx;
			float y12=y1*Sy;
			float x22=x2*Sx;
			float y22=y2*Sy;
			float x32=x3*Sx;
			float y32=y3*Sy;
			glColor3f(0.0,0.0,1.0);
			glBegin(GL_POLYGON);
				glVertex3f(x12,y12, 0.0);
				glVertex3f(x22,y22, 0.0);
				glVertex3f(x32,y32, 0.0);
			glEnd();
			glFlush();
		       break;
		case 4://Shearing
			printf("enter the shear factor and reference axis parallel to x-axis\n");
			float Sh,y;
			scanf("%f %f",&Sh,&y);
			float x13=x1+Sh*(y1-y);
			float y13=y1;
			float x23=x2+Sh*(y2-y);
			float y23=y2;
			float x33=x3+Sh*(y3-y);
			float y33=y3;
			glColor3f(0.0,0.0,1.0);
			glBegin(GL_POLYGON);
				glVertex3f(x13,y13, 0.0);
				glVertex3f(x23,y23, 0.0);
				glVertex3f(x33,y33, 0.0);
			glEnd();
			glFlush();
		       break;
		default:printf("invalid option\n");
	}

}

void dda() {
	int X,Y,m,x1,x2,y1,y2;
	printf("enter the starting points");
	scanf("%d %d",&x1,&y1);
	printf("enter the end points");
	scanf("%d %d",&x2,&y2);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POINTS);
	while(x1 != x2 && y1 != y2) {
		X = x2-x1;
		Y = y2-y1;
		m = (int)(round(Y/X));
		if(m>=1){
			x1=x1+1;
			y1=y1+m;
		}
		else{
		   y1 = y1+1;
		   x1 = x1 + ( int)(1.0/m);
		}
		glVertex2i(x1,y1);
	}
	glVertex2i(x2,y2);
	glEnd();
	glColor3f(0.0,1.0,1.0);
	glBegin(GL_LINES);
	glVertex2i(x1,y1);
	glVertex2i(x2,y2);
	glEnd();
	glFlush();
}


void circle(void)
{
    int x,y,p,r,i,xc,yc;
	glColor3f(1.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	//to draw coordinate axes
	glBegin(GL_LINES);
		glVertex2i(0.0,-100.0);
		glVertex2i(0.0,100.0); // first line needs two vertex
		glVertex2i(-100.0,0.0);
		glVertex2i(100.0,0.0); // 2nd line another
	glEnd();
	//to draw circle
    printf("Enter the Centre");
    scanf("%d %d",&xc,&yc);
    printf("Enter the Radius of the circle");
    scanf("%d",&r);
    p = 1-r;
	x=0;
    y=r;
    glVertex2i(x,y);
    glBegin(GL_POINTS);
    while(y>x){
        if(p<0){
            p = p+2*x+3;
			x=x+1;
        }
        else{
            p=p-2*y+2*x+1;
			x=x+1;
			y=y-1;
        }
        glVertex2i(xc+x,yc+y);
	glVertex2i(xc+y,yc+x);
	glVertex2i(xc-y,yc+x);
	glVertex2i(xc-x,yc+y);
	glVertex2i(xc-x,yc-y);
	glVertex2i(xc-y,yc-x);
	glVertex2i(xc+y,yc-x);
	glVertex2i(xc+x,yc-y);

    }
    glEnd();
    glFlush();
}

void Bresenhams(void)
{
    int x0,y0,xf,yf,i=0,p,dx,dy;
    printf("Enter the Starting Points");
    scanf("%d %d",&x0,&y0);
    printf("Enter the End Points");
    scanf("%d %d",&xf,&yf);
    dx=xf-x0;
    dy=yf-x0;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    p = 2*dy-dx;
    glVertex2i(x0,y0);
    glBegin(GL_LINES);
    while(i<(dx-1)){
        if(p<0){
            x0=x0+1;
	    y0=y0;
            p = p+2*dy;
        }
        else{
            x0=x0+1;
            y0=y0+1;
            p=p+2*dy-2*dx;
        }
        glVertex2i(x0,y0);
        i=i+1;
    }
    glEnd();
    glFlush();
}

void ellipse(){
    glColor3f(1.0,0.0,0.0);
    float xc,yc,rx,ry;
    printf("Enter the Centre");
    scanf("%f %f",&xc,&yc);
    printf("enter minor and major axes\n");
    scanf("%f %f",&rx,&ry);
    float rxSq = rx * rx;
    float rySq = ry * ry;
    float x = 0, y = ry, p;
    float px = 0, py = 2 * rxSq * y;
    glBegin(GL_POINTS);
            glVertex2i(x+xc,y+yc);
            glVertex2i(-x+xc,y+yc);
            glVertex2i(-x+xc,-y+yc);
            glVertex2i(x+xc,-y+yc);
        glEnd();
    //region1
    p = rySq - (rxSq * ry) + (0.25 * rxSq);
    while (px < py)
    {
        x++;
        px = px + 2 * rySq;
        if (p < 0)
            p = p + rySq + px;
        else
        {
            y--;
            py = py - 2 * rxSq;
            p = p + rySq + px - py;
        }
        glBegin(GL_POINTS);
            glVertex2i(x+xc,y+yc);
            glVertex2i(-x+xc,y+yc);
            glVertex2i(-x+xc,-y+yc);
            glVertex2i(x+xc,-y+yc);
        glEnd();
    }
    //region2
    p = rySq*(x+0.5)*(x+0.5) + rxSq*(y-1)*(y-1) - rxSq*rySq;
    while (y > 0)
    {
        y--;
        py = py - 2 * rxSq;
        if (p > 0)
            p = p + rxSq - py;
        else
        {
            x++;
            px = px + 2 * rySq;
            p = p + rxSq - py + px;
        }
        glBegin(GL_POINTS);
            glVertex2i(x+xc,y+yc);
            glVertex2i(-x+xc,y+yc);
            glVertex2i(-x+xc,-y+yc);
            glVertex2i(x+xc,-y+yc);
        glEnd();

    }
    glFlush();
}


void createWindow(){
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(500,500);
	glutInitWindowSize(600,600);
	glutCreateWindow("OpenGl Window");
}

int main(int argc, char** argv){
	printf("Creating Window and rendering Stuffs\n");
	glutInit(&argc, argv);
	createWindow();
	initialize();
	//glutDisplayFunc(Poly);
	//glutDisplayFunc(lineSeg);
	//glutDisplayFunc(Bresenhams);
	//glutDisplayFunc(dda);
	//glutDisplayFunc(circle);
	//glutDisplayFunc(ellipse);
	glutDisplayFunc(Transformation);
	glutMainLoop();

	return 0;
}