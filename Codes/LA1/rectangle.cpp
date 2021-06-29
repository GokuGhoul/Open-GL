#include <GL/glut.h>
#include<stdio.h>
void init()
{
  glClearColor(0, 0, 0, 0);
  glMatrixMode(GL_PROJECTION);
}
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.5, 0.6, 0.5);
  glBegin(GL_LINE_LOOP);
  glVertex2f(-0.1, 0.1);
  glVertex2f(0.8, 0.1);
  glVertex2f(0.8, -0.4);
  glVertex2f(-0.1, -0.4);
  glEnd();
  glFlush();
}
void main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Rectangle on black background");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
}
