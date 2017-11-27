#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdlib.h>

static GLfloat move = 0.0, x= 0.0, y= 0.0;

void init(void) {
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(-move,0.0,0.0);
	glTranslatef(120.0,10.0,0.0);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glLineWidth(25);
	glVertex2f(5.0,15.0);
	glVertex2f(30.0,15.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(110.0,10.0,0.0);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0,1.0,0.0);
	glVertex2f(0.0,0.0);
	glVertex2f(2.0,2.0);
	glVertex2f(-2.0,-2.0);	
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(x,move,0.0);
	
	glTranslatef(-120.0,10.0,0.0);
	glutSolidSphere(20.0,20,16);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(x,move,0.0);
	glTranslatef(-120.0,-10.0,0.0);
	glBegin(GL_LINES);
	glLineWidth(25);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(0.0,0.0);
	glVertex2f(0.0,-20.0);
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
}

void spinDisplay(void) {
	if(move <= 110 && move >= -110)
		move = move + 1.0;
	else {
		move = -110;
		x = rand()%400;
	}
	glutPostRedisplay();
}

void reshape(int w, int h) {
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-150.0, 150.0, -150.0, 150.0, -20.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mouse(int button, int state, int x, int y) {
	switch (button) {
		case GLUT_LEFT_BUTTON:
			if (state == GLUT_DOWN)
				glutIdleFunc(spinDisplay);
			break;
		case GLUT_MIDDLE_BUTTON:
			if (state == GLUT_DOWN)
				glutIdleFunc(NULL);
			break;
		default:
			break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (250, 250);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
