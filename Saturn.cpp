#include<GL\glut.h>

double rotate_y = 0;
double rotate_x = 0;

int rotate_light0_y = 0;

void init(void){

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	gluLookAt(0.0, 0.0, 0.0, 2.5, 2.5, 2.5, 0.0, 1.0, 0.0);
}

void display(void){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GLfloat light_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 8.0, 1.0, 1.0, 10.0 };
	GLfloat spot_direction[] = { 0.0 , 0.0 , 0.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	//Moving Light Source by Time
	glPushMatrix();
		glRotated((GLdouble)rotate_light0_y, 0.0, 1.0, 0.0);
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glPopMatrix();
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);


	glPushMatrix();

			//**Sphere**//
	GLfloat amb[] = { 0.3f,0.2f,0.2f,1.0f };
	GLfloat diff[] = { 0.78f,0.74f,0.59f,1.0f };
	GLfloat spec[] = { 0.37f,0.32f,0.24f,1.0f };
	GLfloat shine = 45.0f;

	glPushMatrix();
	
	//Putting Material on Sphere
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);

	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glutSolidSphere(0.35, 50, 50);

			//**Ring**//
	GLfloat amb1[] = { 0.1f,0.10f,0.14f,1.0f };
	GLfloat diff1[] = { 0.13f,0.1f,0.09f,1.0f };
	GLfloat spec1[] = {0.1f, 0.1f, 0.07f, 1.0f};
	GLfloat shine1 = 15.0f;
	
	//Putting Material on Ring
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec1);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine1);

	glRotatef(45 , 1.0, 0.0, 0.0);
	glRotatef(20, 0.0, 1.0, 0.0);
	glutSolidTorus(0.07, 0.65, 2, 100);

	glPopMatrix();
	glutSwapBuffers();
	glFlush();
}


void keyboard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_RIGHT:
		rotate_y += 5;
		break;
	case GLUT_KEY_LEFT:
		rotate_y -= 5;
		break;
	case GLUT_KEY_UP:
		rotate_x += 5;
		break;
	case GLUT_KEY_DOWN:
		rotate_x -= 5;
		break;
	}
	glutPostRedisplay();
}

void timer(int v){

	rotate_light0_y = (rotate_light0_y + 5) % 360;

	glutPostRedisplay();
	glutTimerFunc(100, timer, 0);
}

int main(int argc, char** argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 200);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutTimerFunc(100, timer, 0);
	glutSpecialFunc(keyboard);
	glutMainLoop();

	return 0;
}
