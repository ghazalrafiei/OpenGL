// g++ buildings.cpp -lglut -lGLU -lGL; ./a.out
#include <GL/glut.h>
#include <iostream>

void draw_grid() {
  glBegin(GL_LINES);
  glColor3f(0.2f, 0.2f, 0.2f);
  for (float i = -1; i < 1; i += 0.05) {
    glVertex2f(-1.f, i);
    glVertex2f(1.f, i);

    glVertex2f(i, -1.f);
    glVertex2f(i, 1.f);
  }
  glEnd();
}

void draw_square(float x, float y, float x_side, float y_side) {
  glBegin(GL_LINE_LOOP);

  glColor3f(1, 1, 1);

  glVertex2f(x + x_side, y + y_side);
  glVertex2f(x + x_side, y - y_side);
  glVertex2f(x - x_side, y - y_side);
  glVertex2f(x - x_side, y + y_side);
  glEnd();
}

void draw_line(float x1, float y1, float x2, float y2) {
  glBegin(GL_LINES);
  glColor3f(1, 1, 1);
  glVertex2f(x1, y1);
  glVertex2f(x2, y2);
  glEnd();
}

void draw_quarter(int x_q, int y_q) {
  const float x_side = 0.05;
  const float y_side = 0.05;

  float x_margin = x_side * 4;
  float y_margin = y_side * 4;

  const int X_shape = 6; // 2*x-1 shapes at all
  const int Y_shape = 5;

  float x_axis = 0;
  float y_axis = 0;

  float x_axis_prime = 0;
  float y_axis_prime = 0;

  for (int y = 1; y <= Y_shape; y++) {
    for (int x = 1; x <= X_shape; x++) {
      float dot1, dot2, dot3, dot4;

      // First square
      draw_square(x_axis, y_axis, x_side, y_side);
      dot1 = x_axis;
      dot2 = y_axis;
      x_axis = x_axis + x_q * x_margin;
      x_margin += x_side;

      // Second square
      draw_square(x_axis_prime, y_axis_prime, x_side, y_side);
      dot3 = x_axis_prime;
      dot4 = y_axis_prime;
      x_axis_prime = x_axis + x_side * x * x_q;

      draw_line(dot1 - x_side, dot2 - y_side, dot3 - x_side, dot4 - y_side);
      draw_line(dot1 - x_side, dot2 + y_side, dot3 - x_side, dot4 + y_side);
      draw_line(dot1 + x_side, dot2 + y_side, dot3 + x_side, dot4 + y_side);
      draw_line(dot1 + x_side, dot2 - y_side, dot3 + x_side, dot4 - y_side);
    }

    y_axis = y_axis + y_q * y_margin;
    y_margin += y_side;
    x_axis = 0;
    x_margin = x_side * 4;

    y_axis_prime = y_axis + y_q * y_side * y;
    x_axis_prime = 0;
  }
}

void display() {
  glClearColor(0.0, 0.0, 0.0, 0);
  glClear(GL_COLOR_BUFFER_BIT);

  draw_grid();

  draw_quarter(1, 1);
  draw_quarter(1, -1);
  draw_quarter(-1, 1);
  draw_quarter(-1, -1);

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