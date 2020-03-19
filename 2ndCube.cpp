#include<GL/glut.h>

void display();

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(300,100);
    glutCreateWindow("Second Cube");
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}

void display(){

    GLfloat vertices[]={
        0.0,0.0,0.0,
        0.0,0.0,0.5,
        0.0,0.5,0.5,
        0.0,0.5,0.0,
        0.5,0.5,0.0,
        0.5,0.5,0.5,
        0.5,0.0,0.5,
        0.5,0.0,0.0
    };

    GLfloat colors[]={
        0.0,0.1,1.0,
        1.0,0.0,0.0,
        0.0,1.0,0.0,
        1.0,1.0,1.0,
        1.0,0.0,0.0,
        1.0,1.0,1.0,
        1.0,0.0,1.0,
        0.0,1.0,0.5
    };


    glClearColor(0.0, 0.0 , 0.0 , 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt( 0.5,0.5,0.5, 0.65,0.55,0.55 ,0.0,1.0,0.0);
    
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);    

    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);

    glColorPointer(3, GL_FLOAT,0,colors);
    glVertexPointer(3, GL_FLOAT, 0,vertices);
       
       glShadeModel(GL_SMOOTH);

    glBegin(GL_QUADS);//BOTTOM
        glArrayElement(0);
        glArrayElement(3);
        glArrayElement(4);
        glArrayElement(7);
    glEnd();

    glBegin(GL_QUADS);//BACK
        glArrayElement(0);
        glArrayElement(1);
        glArrayElement(6);
        glArrayElement(7);
    glEnd();

    glBegin(GL_QUADS);//RIGHT
        glArrayElement(0);
        glArrayElement(1);
        glArrayElement(2);
        glArrayElement(3);
    glEnd();

    glBegin(GL_QUADS);//LEFT
        glArrayElement(4);
        glArrayElement(5);
        glArrayElement(6);
        glArrayElement(7);
    glEnd();

    glBegin(GL_QUADS);//TOP
        glArrayElement(1);
        glArrayElement(2);
        glArrayElement(5);
        glArrayElement(6);
    glEnd();

    glBegin(GL_QUADS);//FRONT
        glArrayElement(2);
        glArrayElement(3);
        glArrayElement(4);
        glArrayElement(5);
    glEnd();
    
   
    
   
    
   

    glFlush();
}
