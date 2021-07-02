#include<stdio.h>
#include <GL/glut.h>
#include<math.h>
void init();
void display();
void drawPolygon(int, int, int, int, int, int, int, int);
void drawPolygon(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
  glBegin(GL_LINES);
  glVertex2i(x1, y1);
  glVertex2i(x2, y2);
  glEnd();
  glBegin(GL_LINES);
  glVertex2i(x2, y2);
  glVertex2i(x3, y3);
  glEnd();
  glBegin(GL_LINES);
  glVertex2i(x3, y3);
  glVertex2i(x4, y4);
  glEnd();
  glBegin(GL_LINES);
  glVertex2i(x4, y4);
  glVertex2i(x1, y1);
  glEnd();
  glFlush();
}
void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 0.0);
  glPointSize(2.0);
  GLint x0 = 200; // setting the starting point of square
  GLint y0 = 200;
  GLint x1 = 100; //setting the third point of square
  GLint y1 = 100;
  drawPolygon(x0, y0, x1, y0, x1, y1, x0, y1);
}
void OptionsMenu(GLint selectedOpt)
{
  GLint x0 = 200; // setting the starting point of square
  GLint y0 = 200;
  GLint x1 = 100; //setting the third point of square
  GLint y1 = 100;
  float sh;
  GLint x0_New, x1_New, y0_New, y1_New;
  switch (selectedOpt)
  {
  case 1:
  //Xnew = Xold + Shx x Yold
  //Ynew = Yold
  printf("\nEnter shear parameter for x: ");
  scanf_s("%f", &sh);
  x0_New = x0 + sh * y1;
  x1_New = x1 + sh * y1;
  glColor3f(1.0, 0.0, 1.0);
  glPointSize(2.0);
  drawPolygon(x0_New, y0, x1_New, y0, x1, y1, x0, y1);
  break;
  case 2:
  printf("\nEnter shear parameter for y: ");
  scanf_s("%f", &sh);
  y0_New = y0 + sh * y1;
  y1_New = y1 + sh * y1;
  glColor3f(1.0, 0.0, 0.0);
  glPointSize(2.0);
  drawPolygon(x0, y0_New, x1, y0, x1, y1, x0, y1_New);
  default: break;
  }
}
void init(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}
int main(int argc, char**argv)
{
  glutInit(&argc, argv); //initialize GLUT
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  //initialize display mode
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("Implementation of Shear Algorithm");
  glutDisplayFunc(display);
  glutCreateMenu(OptionsMenu);
  glutAddMenuEntry("Shear about x-axis", 1);
  glutAddMenuEntry("Shear about y-axis ", 2);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  init();
  glutMainLoop();
  return 0;
}
