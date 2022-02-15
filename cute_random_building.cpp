#include<GL/glut.h>
#include<iostream>
// TODO: create cmake for this file.
void draw_grid(){
  glBegin(GL_LINES); // BOTTOM
  glColor3f(0.8f, 0.8f, 0.8f);
  for (float i = -1; i < 1; i+=0.05) {
    glVertex2f(-1.f, i);
    glVertex2f(1.f, i);

    glVertex2f(i, -1.f);
    glVertex2f(i, 1.f);
  }
  glEnd();
}
void draw_square(float x, float y, float x_side, float y_side, bool color=false){
  // glTranslatef(-0.3, -0.3, 0.0); //I will exploit it
  glBegin(GL_LINE_LOOP);
    if(color)
      glColor3f(0.0,0.1,1.0);
    else
      glColor3f(0, 0, 0);

    glVertex2f(x+x_side, y+y_side);
    glVertex2f(x+x_side, y-y_side);
    glVertex2f(x-x_side, y-y_side);
    glVertex2f(x-x_side, y+y_side);
  glEnd();
}
void draw_line(float x1, float y1, float x2, float y2){
  glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
  glEnd();
}

void display(){
    glClearColor(1.0, 1.0 , 1.0 , 0);
    glClear(GL_COLOR_BUFFER_BIT);

    draw_grid();

    const float x_side = 0.05;
    const float y_side = 0.05;

    float x_margin = x_side*4;
    float y_margin = y_side*4;

    const int X_shape = 4; //2*x+1 shapes at all
    const int Y_shape = 4;

    float x_axis = 0;
    float y_axis = 0;

    float x_axis_prime = 0;
    float y_axis_prime = 0;


    float dot1,dot2,dot3,dot4;
    for (int y = 1; y<=Y_shape; y++){
      for (int x = 1; x <= X_shape; x++) {

        // First square
        draw_square(x_axis, y_axis, x_side, y_side);
        dot1 = x_axis;
        dot2 = y_axis;
        x_axis += x_margin;
        x_margin += x_side;

        //Second square
        draw_square(x_axis_prime, y_axis_prime, x_side, y_side, true);
        dot3= x_axis_prime;
        dot4= y_axis_prime;
        x_axis_prime=x_axis+ x_side*x;

        draw_line(dot1-x_side,dot2-y_side,dot3-x_side,dot4-y_side);
        draw_line(dot1-x_side,dot2+y_side,dot3-x_side,dot4+y_side);
        draw_line(dot1+x_side,dot2+y_side,dot3+x_side,dot4+y_side);
        draw_line(dot1+x_side,dot2-y_side,dot3+x_side,dot4-y_side);
      }
      y_axis += y_margin;
      y_margin+=y_side;
      x_axis = 0;
      x_margin = x_side*4;

      y_axis_prime=y_axis+y_side*y;
      x_axis_prime = 0;
    }

    
/////////________________________________________________________________________________________________
    x_axis = 0;
    y_axis = 0;
    x_margin = x_side*4;
    y_axis_prime = 0;
    x_axis_prime = 0;
    y_margin = y_side*4;
    for (int y = 1; y<=Y_shape; y++){
      for (int x = 1; x <= X_shape; x++) {

        // First square
        draw_square(x_axis, y_axis, x_side, y_side);
        dot1 = x_axis;
        dot2 = y_axis;
        x_axis += x_margin;
        x_margin += x_side;

        //Second square
        draw_square(x_axis_prime, y_axis_prime, x_side, y_side, true);
        dot3= x_axis_prime;
        dot4= y_axis_prime;
        x_axis_prime=x_axis+ x_side*x;

        draw_line(dot1-x_side,dot2-y_side,dot3-x_side,dot4-y_side);
        draw_line(dot1-x_side,dot2+y_side,dot3-x_side,dot4+y_side);
        draw_line(dot1+x_side,dot2+y_side,dot3+x_side,dot4+y_side);
        draw_line(dot1+x_side,dot2-y_side,dot3+x_side,dot4-y_side);
      }
      y_axis += y_margin;
      y_margin+=y_side;
      x_axis = 0;
      x_margin = x_side*4;

      y_axis_prime=y_axis-y_side*y;
      x_axis_prime = 0;
    }
    
  glPopMatrix(); 
  glFlush();

    
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(900, 900);
  glutInitWindowPosition(250, 90);
  glutCreateWindow("A city from above");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
