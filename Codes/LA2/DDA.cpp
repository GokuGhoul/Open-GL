#include<GL/glut.h>
#include<math.h>
void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 1.0, 1.0);
  int x0, y0, x1, y1, dx, dy, p, x, y;
  glBegin(GL_POINTS);
  x0 = 0;
  x1 = 400;
  y0 = 250;
  y1 = 100;
  dx = x1 - x0;
  dy = y1 - y0;
  x = x0;
  y = y0;
  p = 2 * dy - dx;
  while (x < x1)
  {
    if (p >= 0)
    {
        glVertex2f(x, y);
        y = y + 1;
        p = p + 2 * dy - 2 * dx;
    }
    else
    {
        glVertex2f(x, y);
        p = p + 2 * dy;
    }
    x = x + 1;
  }
  glEnd();
  glFlush();
}
void myinit()
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glColor3f(0.0, 1.0, 0.0);
  glPointSize(10.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}
void main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("DDA");
  glutDisplayFunc(display);
  myinit();
  glutMainLoop();
}
