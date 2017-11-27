// Dumpling Warrior Game

//Haritha H AM.EN.U4CSE14030
//Chaithanya H AM.WN.U4CSE14028



#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>

static int wHeight;
static int rotation_angle = 10;
static float panda_x, panda_y;
static float dumpling_x = 40, dumpling_y = 40;
static float eat_offset = 0.04;
static int speed = 10;
static int score;
void IdleFunc();

void init(void) {

	printf("Dumpling Warrior\nLet us start\n");
	glClearColor (0.8, 0.5, 0.8, 1.0);
	glShadeModel (GL_FLAT);
	srand(time(NULL));
	
}


void AteCheck() {        
        
	if( (dumpling_x <= panda_x+eat_offset && dumpling_x>=panda_x-eat_offset) 
        && (dumpling_y<=panda_y+eat_offset && dumpling_y>= panda_y - eat_offset) ) {
                        float new_x = rand()%10;
                        float new_y = rand()%10;
                        int alter = rand()%4;
                        
                        dumpling_x = new_x*10;
                        dumpling_y = new_y*10;
                        
                        if(alter%4==0)
                                dumpling_x = -dumpling_x;
                             
                        if(alter%4==1)
                                dumpling_y = -dumpling_y;
                                
                        score++;
                        printf("Dumplings ate : %d\n",score);
        
                }
}

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glPushMatrix();

	
	// begin
	GLvoid *font_style1 = GLUT_BITMAP_TIMES_ROMAN_24;
	glColor3f(0.0,0.0,0.0);
        glRasterPos3f (-40.0, 140.0, 1.0);
        glutBitmapString(font_style1, "I know I haven't been eating");
	glRasterPos3f (-35.0, 126.0, 1.0);
        glutBitmapString(font_style1, " upto my whole potential!");
        	

	//Sun        
	glPushMatrix();
	glTranslatef(-100,130,0);
	glColor3f(1.0,0.7,0.0);
	glutSolidSphere(10,30,25);	
	glPopMatrix();

	// Tree one
	glPushMatrix();
	glColor3f(0.5,0.5,0.0);	
	glBegin(GL_QUADS);
	glVertex2i(-105,-120);
	glVertex2i(-110,-60);
	glVertex2i(-115,-60);
	glVertex2i(-120,-120);
	glEnd();		
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,1.0,0.1);
	glTranslatef(-95,-60,0);
	glutSolidSphere(10,30,25);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,1.0,0.0);
	glTranslatef(-110,-60,0);
	glutSolidSphere(10,30,25);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,1.0,0.0);
	glTranslatef(-120,-50,0);
	glutSolidSphere(10,30,25);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,1.0,0.0);
	glTranslatef(-110,-40,0);
	glutSolidSphere(10,30,25);
	glPopMatrix();
	glPushMatrix();
	
	glColor3f(0.0,1.0,0.0);
	glTranslatef(-100,-45,0);
	glutSolidSphere(10,30,25);
	glPopMatrix();
	glPushMatrix();

	glColor3f(0.0,1.0,0.0);
	glTranslatef(-105,-35,0);
	glutSolidSphere(10,30,25);
	glPopMatrix();

	//Tree 2

	// Tree one
	glPushMatrix();
	glColor3f(0.5,0.5,0.0);	
	glBegin(GL_QUADS);
	glVertex2i(105,-120);
	glVertex2i(110,-60);
	glVertex2i(115,-60);
	glVertex2i(120,-120);
	glEnd();		
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,1.0,0.1);
	glTranslatef(95,-60,0);
	glutSolidSphere(10,30,25);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,1.0,0.0);
	glTranslatef(110,-60,0);
	glutSolidSphere(10,30,25);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,1.0,0.0);
	glTranslatef(120,-50,0);
	glutSolidSphere(10,30,25);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,1.0,0.0);
	glTranslatef(110,-40,0);
	glutSolidSphere(10,30,25);
	glPopMatrix();
	glPushMatrix();
	
	glColor3f(0.0,1.0,0.0);
	glTranslatef(100,-45,0);
	glutSolidSphere(10,30,25);
	glPopMatrix();
	glPushMatrix();

	glColor3f(0.0,1.0,0.0);
	glTranslatef(105,-35,0);
	glutSolidSphere(10,30,25);
	glPopMatrix();


	//Chinese 
	
	glPushMatrix();
	glColor3f(0.5,0.35,0.0);
	glBegin(GL_QUADS);
	glVertex2i(-10,-120);
	glVertex2i(-10,-40);
	glVertex2i(-15,-40);
	glVertex2i(-15,-120);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2i(10,-120);
	glVertex2i(10,-40);
	glVertex2i(15,-40);
	glVertex2i(15,-120);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2i(-30,-120);
	glVertex2i(-30,-60);
	glVertex2i(-35,-60);
	glVertex2i(-35,-120);
	glEnd();
	
	glBegin(GL_QUADS);
	glVertex2i(30,-120);
	glVertex2i(30,-60);
	glVertex2i(35,-60);
	glVertex2i(35,-120);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2i(35,-70);
	glVertex2i(35,-75);
	glVertex2i(10,-75);
	glVertex2i(10,-70);
	glEnd();
	
	glBegin(GL_QUADS);
	glVertex2i(-35,-70);
	glVertex2i(-35,-75);
	glVertex2i(-10,-75);
	glVertex2i(-10,-70);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2i(10,-55);
	glVertex2i(10,-60);
	glVertex2i(-10,-60);
	glVertex2i(-10,-55);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(-15,-60);
	glVertex2i(-45,-60);
	glVertex2i(-50,-50);
	glVertex2i(-15,-50);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(15,-60);
	glVertex2i(45,-60);
	glVertex2i(50,-50);
	glVertex2i(15,-50);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(25,-40);
	glVertex2i(-25,-40);
	glVertex2i(-35,-20);
	glVertex2i(35,-20);	
	glEnd();
	glPopMatrix();	
	
	//clouds one

	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(-45,90,0);
	glutSolidSphere(6,30,25);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(-55,98,0);
	glutSolidSphere(6,30,25);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(-40,95,0);
	glutSolidSphere(7,30,25);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(-55,90,0);
	glutSolidSphere(7,30,25);
	glPopMatrix();


	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(-50,100,0);
	glutSolidSphere(6,30,25);
	glPopMatrix();

	//cloud two


	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(45,90,0);
	glutSolidSphere(6,30,25);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(55,98,0);
	glutSolidSphere(6,30,25);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(40,95,0);
	glutSolidSphere(7,30,25);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(55,90,0);
	glutSolidSphere(7,30,25);
	glPopMatrix();


	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(50,100,0);
	glutSolidSphere(6,30,25);
	glPopMatrix();

	//cloud three


	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(-100,100,0);
	glutSolidSphere(6,30,25);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(-100,98,0);
	glutSolidSphere(6,30,25);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(-115,95,0);
	glutSolidSphere(7,30,25);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(-105,90,0);
	glutSolidSphere(7,30,25);
	glPopMatrix();


	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(-105,100,0);
	glutSolidSphere(6,30,25);
	glPopMatrix();
	
	
	
	//glPopMatrix();
	IdleFunc();
	glutSwapBuffers();
}

void IdleFunc() {
              
        // dumpling
        
	glPushMatrix();
        glTranslatef(dumpling_x,dumpling_y,0);
	glColor3f(1.0,1.0,0.0);
        glRotatef(rotation_angle,0,1,1);
        glutWireSphere(7,4,10);
        glPopMatrix();
        
        
        
	// Panda

         glPushMatrix();
         glTranslatef(panda_x,panda_y,0);
         //glRotatef(rotation_angle,0,1,1);

		glPushMatrix();

		glColor3f(1.0,1.0,1.0);
		glutSolidSphere(10.0, 10.0, 6.0);

		glColor3f(1.0,1.0,1.0);
		glutSolidSphere(10.0, 10.0, 6.0);

		glColor3f(1.0,1.0,1.0);
		glutSolidSphere(10.0, 10.0, 6.0);			


		glPopMatrix();

		
         glutWireSphere(10,8,10);
         glPopMatrix();
	
         AteCheck();
         
        rotation_angle = (rotation_angle+10) % 360;
        glutSwapBuffers();
}

void keyboard(unsigned char key,int x,int y) {
        
	if(key=='d')
                {
                        panda_x=panda_x+1*speed;
                }
        if(key=='a')
                {
                        panda_x=panda_x-1*speed;
                }
        if(key=='s')
                {
                        panda_y=panda_y-1*speed;
                }
        if(key=='w')
                {
                        panda_y=panda_y+1*speed;
                }
       
                
        glutPostRedisplay();
}

void reshape(int w, int h) {

	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-150.0, 150.0, -150.0, 150.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (900, 900);
	glutInitWindowPosition (50, 50);
	glutCreateWindow ("Dumpling Warrior");
	init ();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
        glutIdleFunc(IdleFunc);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
