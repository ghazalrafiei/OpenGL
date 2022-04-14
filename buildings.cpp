#include <GL/glut.h>
#include <iostream>

const int X_SHAPES_NO = 3; // 2*x-1 shapes at all
const int Y_SHAPES_NO = 2;

const float X_SIDE = 0.025;
const float Y_SIDE = 0.05;

const bool BLACK_THEME = false;

void draw_grid() {
  glBegin(GL_LINES);
  if (BLACK_THEME)
    glColor3f(0.2f, 0.2f, 0.2f);
  else
    glColor3f(0.8f, 0.8f, 0.8f);
  for (float i = -100 * Y_SIDE; i < 1; i += Y_SIDE) {
    glVertex2f(-1.f, i);
    glVertex2f(1.f, i);

    glVertex2f(i, -1.f);
    glVertex2f(i, 1.f);
  }
  glEnd();
}

void draw_square(float x, float y, float X_SIDE, float Y_SIDE) {
  glBegin(GL_LINE_LOOP);

  if (BLACK_THEME)
    glColor3f(1, 1, 1);
  else
    glColor3f(0, 0, 0);

  glVertex2f(x + X_SIDE, y + Y_SIDE);
  glVertex2f(x + X_SIDE, y - Y_SIDE);
  glVertex2f(x - X_SIDE, y - Y_SIDE);
  glVertex2f(x - X_SIDE, y + Y_SIDE);
  glEnd();
}

void draw_line(float x1, float y1, float x2, float y2) {
  glBegin(GL_LINES);
  if (BLACK_THEME)
    glColor3f(1, 1, 1);
  else
    glColor3f(0, 0, 0);
  glVertex2f(x1, y1);
  glVertex2f(x2, y2);
  glEnd();
}

void draw_quarter(int x_q, int y_q) {

  float x_margin = X_SIDE * 4;
  float y_margin = Y_SIDE * 4;

  float x_axis = 0;
  float y_axis = 0;

  float x_axis_prime = 0;
  float y_axis_prime = 0;

  for (int y = 1; y <= Y_SHAPES_NO; y++) {
    for (int x = 1; x <= X_SHAPES_NO; x++) {
      float dot1, dot2, dot3, dot4;

      // First square
      draw_square(x_axis, y_axis, X_SIDE, Y_SIDE);
      dot1 = x_axis;
      dot2 = y_axis;
      x_axis = x_axis + x_q * x_margin;
      x_margin += X_SIDE;

      // Second square
      draw_square(x_axis_prime, y_axis_prime, X_SIDE, Y_SIDE);
      dot3 = x_axis_prime;
      dot4 = y_axis_prime;
      x_axis_prime = x_axis + X_SIDE * x * x_q;

      draw_line(dot1 - X_SIDE, dot2 - Y_SIDE, dot3 - X_SIDE, dot4 - Y_SIDE);
      draw_line(dot1 - X_SIDE, dot2 + Y_SIDE, dot3 - X_SIDE, dot4 + Y_SIDE);
      draw_line(dot1 + X_SIDE, dot2 + Y_SIDE, dot3 + X_SIDE, dot4 + Y_SIDE);
      draw_line(dot1 + X_SIDE, dot2 - Y_SIDE, dot3 + X_SIDE, dot4 - Y_SIDE);
    }

    y_axis = y_axis + y_q * y_margin;
    y_margin += Y_SIDE;
    x_axis = 0;
    x_margin = X_SIDE * 4;

    y_axis_prime = y_axis + y_q * Y_SIDE * y;
    x_axis_prime = 0;
  }
}

void display() {
  if (BLACK_THEME)
    glClearColor(0.0, 0.0, 0.0, 0);
  else
    glClearColor(1.0, 1.0, 1.0, 0);

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