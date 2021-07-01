//Man

#include<GL/glut.h>
#include<math.h>
void draw(int x, int y, int xc, int yc) 
{
  glVertex2f(xc + x, yc + y);
  glVertex2f(xc + x, yc - y);
  glVertex2f(xc - x, yc - y);
  glVertex2f(xc - x, yc + y);
  glVertex2f(xc + y, yc + x);
  glVertex2f(xc - y, yc + x);
  glVertex2f(xc - y, yc - x);
  glVertex2f(xc + y, yc - x);
}
void circle(int R, int xc, int yc) 
{
  glBegin(GL_POLYGON);
  int x = 0, y = R;
  int P = 3 - 2 * R;
  while (y >= x) 
  {
    draw(x, y, xc, yc);
    if (P < 0) 
  {
    P += 4 * x + 6;
  }
  else
  {
    P += 4 * (x - y) + 10;
    y--;
  }
    x++;
  }
  glEnd();
}
void rect(int x1, int y1, int x2, int y2) 
{
  glBegin(GL_POLYGON);
  glVertex2f(x1, y1);
  glVertex2f(x2, y1);
  glVertex2f(x2, y2);
  glVertex2f(x1, y2);
  glEnd();
}
void arm(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4) 
{
  glBegin(GL_POLYGON);
  glVertex2f(x1, y1);
  glVertex2f(x2, y2);
  glVertex2f(x3, y3);
  glVertex2f(x4, y4);
  glEnd();
}
void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON); //start
  glColor3f(1.0, 0.0, 0.0);
  glVertex2i(80, 70);
  glVertex2i(80, 100);
  glVertex2i(90, 100);
  glVertex2i(90, 70);
  glEnd(); //end
//arms
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glVertex2f(80, 100);
  glVertex2f(50, 80);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(90, 100);
  glVertex2f(120, 80);
  glEnd();
  //legs
  glBegin(GL_LINES);
  glVertex2f(80, 70);
  glVertex2f(70, 50);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(90, 70);
  glVertex2f(100, 50);
  glEnd();
  glColor3f(0.6, 0.5, 0.2);
  circle(10, 85, 110);
  glFlush();
}
void myinit() 
{
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glColor3f(1.0, 0.0, 0.0);
  glPointSize(5.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 300.0, 0.0, 300.0);
}
void main(int argc, char** argv) 
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(700, 600);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Man");
  glutDisplayFunc(display);
  myinit();
  glutMainLoop();
}
