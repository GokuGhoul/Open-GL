//Black Window
#include<windows.h>
#include<GL/GLU.h>
#include<GL/glut.h>
void display()
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}
//Program to create an empty Widnow
void init() 
{
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(100, 200);
  glutCreateWindow("empty window");
}
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
//************************************************************************
////White Window
#include<windows.h>
#include<GL/GLU.h>
#include<GL/glut.h>
void display()
{
  glClearColor(1.0,1.0, 1.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}
//Program to create an empty Widdow
void init() {
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(100, 200);
  glutCreateWindow("White window");
}
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
//************************************************************************
//Color Window
#include<windows.h>
#include<GL/GLU.h>
#include<GL/glut.h>
void display()
{ 
  glClearColor(0.4, 0.2, 0.1, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}
//Program to create an empty Widdow
void init() 
{ 
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(100, 200);
  glutCreateWindow("Color window");
}
int main(int argc, char **argv)
{ 
  glutInit(&argc, argv);
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
