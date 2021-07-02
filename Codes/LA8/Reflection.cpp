#include<windows.h>
#include<GL/GLU.h>
#include<GL/glut.h>
void draw()
{ 
  glColor3f(0, 0, 1);
  glBegin(GL_LINE_LOOP);
  glVertex2f(0.1, 0.1);
  glVertex2f(0.4, 0.1);
  glVertex2f(0.4, 0.4);
  glVertex2f(0.1, 0.4);
  glEnd();
  glFlush();
}
void OptionsMenu(GLint selectedOpt)
{
  switch (selectedOpt)
  {
  case 1: glLoadIdentity();
  glScalef(1, -1, 1);
  glColor3f(1, 1, 0);
  glBegin(GL_LINE_LOOP);
  glVertex2f(0.1, 0.1);
  glVertex2f(0.4, 0.1);
  glVertex2f(0.4, 0.4);
  glVertex2f(0.1, 0.4);
  glEnd();
  glFlush();
  break;
  case 2: glLoadIdentity();
  glScalef(-1, 1, 1);
  glColor3f(1, 0, 0);
  glBegin(GL_LINE_LOOP);
  glVertex2f(0.1, 0.1);
  glVertex2f(0.4, 0.1);
  glVertex2f(0.4, 0.4);
  glVertex2f(0.1, 0.4);
  glEnd();
  glFlush();
  break;
  case 3: glLoadIdentity();
  glScalef(-1, -1, 1);
  glColor3f(0, 1, 0);
  glBegin(GL_LINE_LOOP);
  glVertex2f(0.1, 0.1);
  glVertex2f(0.4, 0.1);
  glVertex2f(0.4, 0.4);
  glVertex2f(0.1, 0.4);
  glEnd();
  glFlush();
  default: break;
  }
}
void init()
{ 
  glClearColor(0.1, 0.1, 0.1, 0.0);
  // set the drawing color
  glPointSize(1.0);
  // set margins
  glMatrixMode(GL_PROJECTION);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1, 1, 1);
  glBegin(GL_LINES);
  glVertex2f(0, 0);
  glVertex2f(5, 0);
  glEnd();
  glColor3f(1, 1, 1);
  glBegin(GL_LINES);
  glVertex2f(0, 0);
  glVertex2f(0, 5);
  glEnd();
  glColor3f(1, 1, 1);
  glBegin(GL_LINES);
  glVertex2f(0, 0);
  glVertex2f(-5, 0);
  glEnd();
  glColor3f(1, 1, 1);
  glBegin(GL_LINES);
  glVertex2f(0, 0);
  glVertex2f(0, -5);
  glEnd();
  glFlush();
}
int main(int argC, char *argV[])
{
  glutInit(&argC, argV);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(800, 800);
  glutCreateWindow("Shear - Reflection");
  glutDisplayFunc(draw);
  glutCreateMenu(OptionsMenu);
  glutAddMenuEntry("reflection about x", 1);
  glutAddMenuEntry("reflection about y", 2);
  glutAddMenuEntry("reflection about origin", 3);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  init();
  glutMainLoop();
  return 0;
}
