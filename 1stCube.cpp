#include<GL/glut.h>

void display();

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(300,100);
    glutCreateWindow("First Cube");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

void display(){
    glClearColor(0.0, 0.0 , 0.0 , 0);
    

    glLoadIdentity();
    gluLookAt( 1.0,1.0,1.0, 0.4,0.4,1.1 ,0.0,1.0,0.0);
    
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    GLfloat e = 0.4;//edge
    glTranslatef(1.0,1.0,0.7);

glBegin(GL_QUADS);//BOTTOM
    glColor3f(1.0f, 1.0f, 0.0f);    
    glNormal3f(0.0,0.0,-1.0);
    glVertex3f( e, -e, -e);
    glNormal3f(0.0,0.0,-1.0);    
    glVertex3f(-e, -e, -e);
    glNormal3f(0.0,0.0,-1.0);
    glVertex3f(-e,  e, -e);
    glNormal3f(0.0,0.0,-1.0);
    glVertex3f( e,  e, -e);
  glEnd();
    
     glBegin(GL_QUADS);//BACK
    glColor3f(1.0f, 0.5f, 0.0f);     
    glNormal3f(0.0,-1.0,0.0);
    glVertex3f( e, -e, -e);
    glNormal3f(0.0,-1.0,0.0);
    glVertex3f(-e, -e, -e);
    glNormal3f(0.0,-1.0,0.0);
    glVertex3f(-e, -e,  e);
    glNormal3f(0.0,-1.0,0.0);
    glVertex3f( e, -e,  e);
  glEnd();


 glBegin(GL_QUADS);//RIGHT
    glColor3f(0.0f, 0.0f, 1.0f);    
    glNormal3f(-1.0,0.0,0.0);
    glVertex3f(-e,  e,  e);
    glNormal3f(-1.0,0.0,0.0);
    glVertex3f(-e,  e, -e);
    glNormal3f(-1.0,0.0,0.0);
    glVertex3f(-e, -e, -e);
    glNormal3f(-1.0,0.0,0.0);
    glVertex3f(-e, -e,  e);
  glEnd();

  glShadeModel(GL_FLAT);
glBegin(GL_QUADS);//LEFT
    glColor3f(1.0f, 0.0f, 1.0f);
    glNormal3f(1.0,0.0,0.0);
    glVertex3f(e, e,-e);
    glNormal3f(1.0,0.0,0.0);
    glVertex3f(e,-e, -e);
    glNormal3f(1.0,0.0,0.0);
    glVertex3f(e,-e, e);
    glNormal3f(1.0,0.0,0.0);
    glVertex3f(e, e, e);
  glEnd();

   glBegin(GL_QUADS);//TOP
    glColor3f(1.0f, 0.0f, 0.0f);    
    glNormal3f(0.0,0.0,1.0);
    glVertex3f( e,  e, e);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-e,  e, e);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-e, -e, e);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f( e, -e, e);
  glEnd();

  glBegin(GL_QUADS); //FRONT     
    glColor3f(0.0f, 1.0f, 0.0f);    
    glNormal3f(0.0,1.0,0.0);
    glVertex3f( e, e, -e);
    glNormal3f(0.0,1.0,0.0);
    glVertex3f(-e, e, -e);
    glNormal3f(0.0,1.0,0.0);
    glVertex3f(-e, e,  e);
    glNormal3f(0.0,1.0,0.0);
    glVertex3f( e, e,  e);
  glEnd();
  
  glPopMatrix();
        

   
    glFlush();




}
