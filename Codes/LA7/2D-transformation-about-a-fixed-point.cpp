//about fixed point
#include<windows.h>
#include<GL/GLU.h>
#include<GL/glut.h>
void draw()
{ 
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0, 0, 1);
  glBegin(GL_LINE_LOOP);
  glVertex2f(0.1, 0.4);
  glVertex2f(0.7, 0.4);
  glVertex2f(0.4, 0.8);
  glEnd();
  glFlush();
}
void OptionsMenu(GLint selectedOpt)
{
  switch (selectedOpt)
  {
  case 1:
  glLoadIdentity();
  glTranslatef(0.1, 0.4, 0);
  glRotatef(-45, 0, 0, 1);
  glTranslatef(-0.1, -0.4, 0);
  glColor3f(1, 0, 0);
  glBegin(GL_LINE_LOOP);
  glVertex2f(0.1, 0.4);
  glVertex2f(0.7, 0.4);
  glVertex2f(0.4, 0.8);
  glEnd();
  glFlush();
  break;
  case 2:
  glLoadIdentity();
  glTranslatef(0.1, 0.4, 0);
  glScalef(0.5, 0.5, 0);
  glTranslatef(-0.1, -0.4, 0);
  glColor3f(1, 1, 0);
  glBegin(GL_LINE_LOOP);
  glVertex2f(0.1, 0.4);
  glVertex2f(0.7, 0.4);
  glVertex2f(0.4, 0.8);
  glEnd();
  glFlush();
  default: break;
  }
}
void init()
{ 
  glClearColor(0.0, 0.0, 0.0, 0.0); //
// set the drawing color
  glPointSize(1.0);
}
int main(int argC, char *argV[])
{ 
  glutInit(&argC, argV);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Fixed_Point_Rotation");
  glutDisplayFunc(draw);
  glutCreateMenu(OptionsMenu);
  glutAddMenuEntry("Rotate ", 1);
  glutAddMenuEntry("Scale", 2);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  init();
  glutMainLoop();
  return 0;
}
