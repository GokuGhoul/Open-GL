#include <GL/glut.h>
#include<stdio.h>
void init2D(float r, float g, float b)
{
  glClearColor(r, g, b, 0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0, 200.0, 0.0, 200.0);
}
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 1.0, 0.0);
  glBegin(GL_LINES);
  glVertex2i(10, 10);//starting vertex
  glVertex2i(50, 50);//ending vertex
  glEnd();
  glFlush();
}
void main(int argc, char *argv[])
{
  glutInit(&argc, argv);//initialize GLUT
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(250, 250);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Green line");
  init2D(0.0, 0.0, 0.0);
  glutDisplayFunc(display);
  glutMainLoop();
}
