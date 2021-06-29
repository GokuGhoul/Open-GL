#include <GL/glut.h>
#include<stdio.h>
void init2D(float r, float g, float b)
{
  glClearColor(r, g, b, 0.0);
  glMatrixMode(GL_PROJECTION)
  gluOrtho2D(0.0, 300.0, 0.0, 300.0);
}
void display(void)
{ 
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 1.0, 1.0);
  glPointSize(10);
  //Size = 10 for point
  //draw a points in 100,100
  glBegin(GL_POINTS);
  glVertex2i(100, 100);
  //drawing point at (100,100)
  glEnd();
  glFlush();//flushing
}
void main(int argc, char *argv[])
{ 
  glutInit(&argc, argv);//initialize GLUT
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(300, 300);
  glutInitWindowPosition(1000, 100);
  glutCreateWindow("points of size 10");
  init2D(0.0, 0.0, 0.0);
  glutDisplayFunc(display);
  glutMainLoop();//routine
}
