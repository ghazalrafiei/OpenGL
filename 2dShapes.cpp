#include <GL/glut.h>

void display();

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(250,90);
    glutCreateWindow("Five 2D Shapes");
    glutDisplayFunc(display);
    glutMainLoop();

return 0;

}


void display(){
    glClearColor(0.0, 0.0 , 0.0 , 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

             /*Triangleس*/
    //diiference between flat and smooth :       
   { 
    glShadeModel(GL_FLAT);
    glBegin(GL_TRIANGLES);
        glColor3f(1.0,0.0,0.0);
        glVertex2f(0.4,0.9);
        glColor3f(0.5,0.5,0.5);
        glVertex2f(0.5,0.6);
        glVertex2f(0.2,0.3);
    glEnd();

    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(1.0,0.0,0.0);
        glVertex2f(0.7,0.9);
        glColor3f(0.5,0.5,0.5);
        glVertex2f(0.8,0.6);
        glVertex2f(0.5,0.3);
    glEnd();
   }
    
            /*Square*/  
    glTranslatef(-0.3, -0.3 , 0.0);
    glBegin(GL_POLYGON);
    GLdouble edge=0.4;
        glColor3f(0.0,0.5,0.5);
        glVertex2f(0.0, 0.0);
        glColor3f(1.0,1.0,1.0);
        glVertex2f(-edge , 0.0);
        glColor3f(0.0,0.5,0.5);
        glVertex2f(-edge, -edge);
        glColor3f(1.0,1.0,1.0);
        glVertex2f(0.0 , -edge);
    glEnd();
    glPopMatrix();
    glLoadIdentity();

    GLdouble min=0.05;
    GLdouble max=0.2;
    
            /*Spinner*/
    glBegin(GL_POLYGON);
        glColor3f(0.91,0.15,0.25);        
        glColor3f(1,1,1);
        glVertex2f(0.0,0.0);
        glColor3f(0.91,0.15,0.25);
        glVertex2f( 0.0 ,  max);
        glVertex2f( min ,  min);

        glVertex2f(0.0 , 0.0);
        glColor3f(0.91,0.15,0.25);
        glVertex2f( max ,  0.0);
        glVertex2f( min , -min);

        glVertex2f(0.0,0.0);
        glColor3f(0.91,0.15,0.25);
        glVertex2f( 0.0 , -max);
        glVertex2f(-min , -min);

        glVertex2f(0.0,0.0);
        glColor3f(0.91,0.15,0.25);
        glVertex2f(-max ,  0.0);
        glVertex2f(-min ,  min);
    glEnd();


    
            /* Star */
    glTranslatef(-0.6 , 0.5 , 0.0);
    glBegin(GL_POLYGON);
        glColor3f(0.9 ,0.9,0.0);
        glVertex2f(0.0 , max);
        glVertex2f(min, min);
        glVertex2f(0,0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(0.0 , 0.0);
        glVertex2f(min,min);
        glVertex2f(max, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(0.0 , 0.0);
        glVertex2f(max , 0.0);
        glVertex2f(min , -min);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(0.0 , 0.0);
        glVertex2f(min , -min);
        glVertex2f(0.0 , -max);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(0.0 , 0.0);
        glVertex2f(0.0 , -max);
        glVertex2f(-min, -min);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(0.0 , 0.0);
        glVertex2f(-min , -min);
        glVertex2f(-max , 0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(0.0 , 0.0);
        glVertex2f(-max , 0);
        glVertex2f(-min, min);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(0.0 , 0.0);
        glVertex2f(-min , min);
        glVertex2f(max, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(0.0 , 0.0);
        glVertex2f(-min , min);
        glVertex2f(0.0, max);
    glEnd();
    glPopMatrix();

            /*Plus*/
    glTranslatef(1.2,-0.9,0.0);
    glBegin(GL_POLYGON);
        max=0.25;
        min=0.04;

        glColor3f(0.4,0.2,0.9);
        glVertex2f(-min , max);
        glVertex2f(min , max);
        glVertex2f(min , -max);
        glVertex2f(-min, -max);
    glEnd();

    glBegin(GL_POLYGON);
        min=0.25;
        max=0.04;

        glColor3f(0.4,0.2,0.9);
        glVertex2f(-min , max);
        glVertex2f(min , max);
        glVertex2f(min , -max);
        glVertex2f(-min, -max);
    glEnd();
    
    
    glFlush();
}
