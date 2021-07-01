// Fish
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
void traingle(int x1, int x2, int x3, int y1, int y2, int y3) 
{
glBegin(GL_POLYGON);
glVertex2f(x1, y1);
glVertex2f(x2, y2);
glVertex2f(x3, y3);
glEnd();
}
void draw1(int x, int y, int xc, int yc) 
{
glVertex2f(xc + x, yc + y);
glVertex2f(xc + x, yc - y);
glVertex2f(xc - x, yc - y);
glVertex2f(xc - x, yc + y);
}
void ellipse(int rx, int ry, int xc, int yc)
{
glBegin(GL_POLYGON);
int x = 0, y = ry;
int ry_sq = ry * ry;
int rx_sq = rx * rx;
int P = ry_sq - rx_sq * ry + 0.25 * rx_sq;
while (ry_sq * x < rx_sq * y) 
{
draw1(x, y, xc, yc);
if (P < 0) 
{
P += ry_sq * (2 * x + 3);
}
  else {
      P += ry_sq * (2 * x + 3) + rx_sq * (-2 * y + 2);
      y--;
}
  x++;
}
  P = ry_sq * (x + float(1) / 2) * (x + float(1) / 2) + double(rx_sq) * (y - 1) * (y - 1) - double(rx_sq) * ry_sq;
  while (y >= 0) 
  {
  draw1(x, y, xc, yc);
  if (P >= 0) 
  {
  P += rx_sq * (-2 * y + 3);
  }else {
  P += ry_sq * (2 * x + 2) + rx_sq * (-2 * y + 3);
  x++;
}
  y--;
}
  glEnd();
}
void display() 
{
  glClear(GL_COLOR_BUFFER_BIT);
  //body
  glColor3f(0.0, 0.4, 0.53);
  //ellipse(100, 50, 440, 220);
  ellipse(80, 70, 290, 120);
  traingle(240, 170, 170, 100,170, 40);
  //traingle(440, 220, 220, 150,400, 150);
  //eye
  glColor3f(0.0, 0.0, 0.0);
  circle(5, 360, 140);
  glFlush();
}
void myinit() 
{
  glClearColor(0.0, 0.9, 1.0, 0.0);
  glColor3f(1.0, 0.0, 0.0);
  glPointSize(5.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 699.0, 0.0, 499.0);
}
void main(int argc, char** argv) 
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(700, 500);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("fish");
  glutDisplayFunc(display);
  myinit();
  glutMainLoop();
}
