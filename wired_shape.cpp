#include<GL/glut.h>

double rotate_cube_y = 0;
double rotate_cube_x = 0.5;
double rotate_sphere = 0.0;
double rotate_shape = 0.0;

void init(void) {

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);

	gluLookAt(0.0, 0.0, 0.0, 2.1, 2.1, 2.1, 0.0, 1.0, 0.0);
	glEnable(GL_DEPTH_TEST);

	//LIGHT0
	GLfloat light_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 2.0, -2.0, 2.0, 1.0 };
	GLfloat spot_direction[] = { 0.0,0.0, 0.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);


	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
}


void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glShadeModel(GL_SMOOTH);

	glEnable(GL_COLOR_MATERIAL);

	//** Rotating Wire Cube**//
	glPushMatrix();
	glRotatef(rotate_cube_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_cube_y, 0.0, 1.0, 0.0);
	glColor3f(0.75, 0.75, 1.1);
	glutWireCube(1.0);
	glPopMatrix();

	//**Rotating Wire Sphere**
	glPushMatrix();
	glRotatef(rotate_sphere, 0.0, 1.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glColor3f(0.2, 0.6, 1.0);
	glutWireSphere(0.5, 8, 8);
	glPopMatrix();

	//**Rotating octahedron**//
	glPushMatrix();
	glColor3f(0.2, 0.2, 0.13);
	glScalef(0.25, 0.40, 0.25);
	glRotatef(rotate_shape, 0.0, 1.0, 0.0);
	glutSolidOctahedron();
	glPopMatrix();

	glPopMatrix();
	glutSwapBuffers();
	glFlush();
}


void timer(int v) {

	rotate_cube_x -= 0.5;
	rotate_cube_y -= 0.75;
	rotate_sphere += 1.5;
	rotate_shape += -9.0;

	glutPostRedisplay();
	glutTimerFunc(50, timer, 0);
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 200);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutTimerFunc(50, timer, 0);

	glutMainLoop();

	return 0;
}
