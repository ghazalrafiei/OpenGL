#include <GL/glut.h>
#include <cmath>

int sun_r = 0;
int earth_r = 0;
int moon_r = 0, earth_moon_around_sun_r = 0, moon_earth_r = 0;;
int planet2_r = 0;

GLfloat planet2_around_sun = 180;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);

    GLfloat light_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
    GLfloat light_diffuse[] = { 0.7, 0.7, 0.7, 1.0 };
    GLfloat light_specular[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat light_position[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat spot_direction[] = { 0.5,0.5, 0.5 };

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
}

void reshape(int w, int h) {

    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 10.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 35.0, 40.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

}

void display(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_COLOR_MATERIAL);

    //**SYSTEM**//
    glPushMatrix();
    //**SUN**//
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.4);
    glRotatef(GLfloat(sun_r), 0.0, 1.0, 0.0);//sun around its pivot
    glutSolidSphere(5.0, 15, 15);
    glPopMatrix();

    //**EARTH and MOON**//
    glPushMatrix();//earth
    glRotatef((GLfloat)earth_moon_around_sun_r, 0.0, 1.0, 0.0);//moon and earth around sun
    glTranslatef(25.0, 0.0, 0.0);
    glPushMatrix();
    glRotatef((GLfloat)earth_r, 0.0, 1.0, 0.0);//earth around itself
    glColor3f(0.3, 0.8, 0.3);
    glutSolidSphere(3.0, 20, 20);
    glPopMatrix();
    glRotatef((GLfloat)moon_earth_r, 0.0, 1.0, 0.0);//moon around earth
    glPushMatrix();//moon
    glColor3f(0.5, 0.5, 0.5);
    glTranslatef(0.0, 0.0, 5.0);
    glRotatef((GLfloat)moon_r, 0.0, 1.0, 0.0);//moon around itself
    glutSolidSphere(1, 10, 10);
    glPopMatrix();
    glPopMatrix();

    //**PLANET2**//
    glPushMatrix();
    glColor3f(0.2, 0.2, 0.4);
    glTranslatef(20 * cos(planet2_around_sun), 0.0, 8 * sin(planet2_around_sun));//planet2 around sun in ellipsis orbit
    glRotatef((GLfloat)planet2_r, 0.0, 1.0, 0.0);//planet2 around itself
    glutSolidSphere(1.8, 15, 15);
    glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}
void timer(int v) {
    int rotate_degree = 10;

    sun_r = (sun_r - rotate_degree / 3) % 360;

    earth_r = (earth_r + rotate_degree / 3) % 360;

    moon_r = (moon_r + rotate_degree / 3) % 360;
    earth_moon_around_sun_r = (earth_moon_around_sun_r - rotate_degree / 3) % 360;
    moon_earth_r = (moon_earth_r + rotate_degree) % 360;

    planet2_around_sun = (planet2_around_sun + (float)rotate_degree / 80);
    if (planet2_around_sun > 360) planet2_around_sun -= 360.0;

    planet2_r = (planet2_r + rotate_degree) % 360;

    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Arm");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(30, timer, 0);
    glutMainLoop();

    return 0;
}