#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <cstdlib>
using namespace std;
double y_max = 100, y_min = 50, x_max = 100, x_min = 50; // Old viewport
double ny_max = 300, ny_min = 200, nx_max = 300, nx_min = 200; // New ViewPort
double t1 = 0.0, t2 = 1.0;
double X1 = 70;
double Y1 = 50;
double X2 = 120;
double Y2 = 120;
double xx1, xx2, yy1, yy2;
void init()
{
  glLoadIdentity();
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0, 500, 0, 500);
  glMatrixMode(GL_MODELVIEW);
}
void draw_lineAndPort(double x1, double y1, double x2, double y2, double y_max, double y_min,
double x_max, double x_min)
{
  glColor3d(1, 0, 0);
  glBegin(GL_LINE_LOOP);
  glVertex2d(x_min, y_min);
  glVertex2d(x_max, y_min);
  glVertex2d(x_max, y_max);
  glVertex2d(x_min, y_max);
  glEnd();
  glColor3d(0, 0, 0);
  glBegin(GL_LINES);
  glVertex2d(x1, y1);
  glVertex2d(x2, y2);
  glEnd();
}
void clipline1(int x1, int y1, int x2, int y2)
{
  int draw = 1;
  float m, m1, m2, m3, m4;
  m = ((float)(y2 - y1)) / (x2 - x1);
  m1 = ((float)(y_min - y1)) / (x_min - x1);
  m2 = ((float)(y_min - y1)) / (x_max - x1);
  m3 = ((float)(y_max - y1)) / (x_max - x1);
  m4 = ((float)(y_max - y1)) / (x_min - x1);
  xx1 = x1; yy1 = y1;
  if (((abs(m) >= m1 && x2 < x1) || (abs(m) > abs(m2) && x2 > x1)) && y1 > y2)
  {if (y2 > y_min)
  {
  xx2 = x2;
  yy2 = y2;
  }
  else
  {
  yy2 = y_min;
  xx2 = x1 + (y_min - y1) / m;
  }
  }
  else if (m > m2 && m < m3 && x2 >= x_max)
  {if (x2 < x_max)
  {
  xx2 = x2;
  yy2 = y2;
  }
  else
  {
  xx2 = x_max;
  yy2 = y1 + (x_max - x1) * m;
  }
  }
  else if ((abs(m) >= m3 && x2 > x1) || (abs(m) > abs(m4) && x2 < x1))
  {if (y2 < y_max)
  {
  xx2 = x2;
  yy2 = y2;
  }
  else
  {
  yy2 = y_max;
  xx2 = x1 + (y_max - y1) / m;
  }}
  else if (m > m4 && m < m1)
  { if (x2 > x_min)
  {
  xx2 = x2;
  yy2 = y2;
  }
  else
  {
  xx2 = x_min;
  yy2 = y1 + (x_min - x1) * m;
  }}
}
void clipline2(int x1, int y1, int x2, int y2)
{ 
  int draw = 1;
  float m, m1, m2, m3, m4;
  m = ((float)(y2 - y1)) / (x2 - x1);
  m1 = ((float)(y_min - y1)) / (x_min - x1);
  m2 = ((float)(y_min - y1)) / (x_max - x1);
  m3 = ((float)(y_max - y1)) / (x_max - x1);
  m4 = ((float)(y_max - y1)) / (x_min - x1);
  if (m > m1 && m < m2)
  {if (y2 > y_min)
  {
  xx1 = x_min;
  yy1 = y1 + m * (x_min - x1);
  xx2 = x2;
  yy2 = y2;
  }
  else
  {
  xx1 = x_min;
  yy1 = y1 + m * (x_min - x1);
  yy2 = y_min;
  xx2 = x1 + (y_min - y1) / m;
  }}
  else if (m > m2 && m < m3)
  {
  if (x2 < x_max)
  {
  xx1 = x_min;
  yy1 = y1 + m * (x_min - x1);
  xx2 = x2;
  yy2 = y2;
  }
  else
  {
  xx1 = x_min;
  yy1 = y1 + m * (x_min - x1); xx2 = x_max;
  yy2 = y1 + (x_max - x1) * m;
  }}
  else if (m > m3 && m < m4)
  {if (y2 < y_max)
  {
  xx1 = x_min;
  yy1 = y1 + m * (x_min - x1);
  xx2 = x2;
  yy2 = y2;
  }
  else
  {
  xx1 = x_min;
  yy1 = y1 + m * (x_min - x1);
  yy2 = y_max;
  xx2 = x1 + (y_max - y1) / m;
  }}}
  void clipline3(int x1, int y1, int x2, int y2)
  { int draw = 1;
  float m, m1, m2, m3, m4, tm1, tm2;
  int flag, t;
  tm1 = ((float)(y_min - y1)) / (x_min - x1);
  tm2 = ((float)(y_max - y_min)) / (x_max - x_min); //diagonal slope
  m = ((float)(y2 - y1)) / (x2 - x1);
  m1 = ((float)(y_min - y1)) / (x_max - x1);
  m2 = ((float)(y_max - y1)) / (x_max - x1);
  m3 = ((float)(y_min - y1)) / (x_min - x1);
  m4 = ((float)(y_max - y1)) / (x_min - x1);
  if (tm1 < tm2)
  {
  flag = 2;
  t = m2;
  m2 = m3;
  m3 = t;
  }
  else
  flag = 1;
  if (m > m1 && m < m2)
  {if (x2 > x_max && y2 > y_min)
  { yy1 = y_min;
  xx1 = x1 + (y_min - y1) / m;
  xx2 = x_max; yy2 = y1 + m * (x_max - x1);
  }
  else if (y2 > y_min && x2 < x_max)
  { yy1 = y_min;
  xx1 = x1 + (y_min - y1) / m;
  yy2 = y2;
  xx2 = x2;
  }}
  else if (m > m2 && m < m3)
  {if (flag == 1)
  {if (y2 >= y_max)
  { yy1 = y_min;
  xx1 = x1 + (y_min - y1) / m;
  xx2 = x1 + (y_max - y1) / m;
  yy2 = y_max; }
  else if (y2 >= y_min)
  {
  yy1 = y_min;
  xx1 = x1 + (y_min - y1) / m;
  xx2 = x2;
  yy2 = y2;
  }}
  else
  {if (x2 >= x_max)
  {
  xx1 = x_min;
  yy1 = y1 + m * (x_min - x1);
  xx2 = x_max;
  yy2 = y1 + m * (x_max - x1);
  }
  else if (x2 >= x_min)
  {
  xx1 = x_min;
  yy1 = y1 + m * (x_min - x1); xx2 = x2;
  yy2 = y2;
  }}}
  else if (m > m3 && m < m4)
  {
  if (y2 >= y_max)
  {
  xx1 = x_min;
  yy1 = y1 + m * (x_min - x1);
  xx2 = x1 + (y_max - y1) / m;
  yy2 = y_max;
  }
else if (y2 >= y_min)
  {
  xx1 = x_min;
  yy1 = y1 + m * (x_min - x1);
  yy2 = y2;
  xx2 = x2;
  }}
}
int first_end_point_region(int x, int y)
{
  if (x >= x_min && x <= x_max && y >= y_min && y <= y_max)
  return 1;
  else if (x < x_min && y >= y_min && y <= y_max)
  return 2;
  else if (x <= x_min && y <= y_min)
  return 3;
  else
  return 0;
}
void nicholl_lee(double x1, double y1, double x2, double y2)
{ 
  int ch = first_end_point_region(x1, y1);
  switch (ch)
  {
    case 1:
    clipline1(x1, y1, x2, y2);
    break;
    case 2:
    clipline2(x1, y1, x2, y2);
    break;
    case 3:
    clipline3(x1, y1, x2, y2);
    break;
  }
  // Scaling to new View port
  double scale_x = (nx_max - nx_min) / (x_max - x_min);
  double scale_y = (ny_max - ny_min) / (y_max - y_min);
  // New coordinates of the points
  // Point 1
  double nx1 = nx_min + (xx1 - x_min) * scale_x;
  double ny1 = ny_min + (yy1 - y_min) * scale_y;
  // Point 2
  double nx2 = nx_min + (xx2 - x_min) * scale_x;
  double ny2 = ny_min + (yy2 - y_min) * scale_y;
  draw_lineAndPort(nx1, ny1, nx2, ny2, ny_max, ny_min, nx_max, nx_min);
}
void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  draw_lineAndPort(X1, Y1, X2, Y2, y_max, y_min, x_max, x_min);
  nicholl_lee(X1, Y1, X2, Y2);
  glFlush();
}
int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Nicholl-Lee");
  glutDisplayFunc(display);
  init();
  glutMainLoop();
  return 0;
}
