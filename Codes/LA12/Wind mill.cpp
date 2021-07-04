#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#define PI 3.1416
GLint i, j, k;
GLfloat ax = 0, bx = 0, cx = 0, dx = 0, str = 500.0, mn = 500.0;
GLfloat sr = 0.0, sg = 0.749, sb = 1.0;
GLfloat spin = 0.0;
void init(void)
{
  glClearColor(.40, .110, 1.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
}
void circle(GLdouble rad)
{
  GLint points = 50;
  GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
  GLdouble theta = 0.0;
  glBegin(GL_POLYGON);
  {
    for (i = 0; i <= 50; i++, theta += delTheta)
    {
      glVertex2f(rad * cos(theta), rad * sin(theta));
    }
  }
  glEnd();
}
/// *** Windmill_Stand_Model ***///
void Windmill_Stand_Model() 
{
  glColor3f(0.38, 0.41, 0.36);
  glBegin(GL_POLYGON);
  glVertex2i(375, 100);
  glVertex2i(380, 240);
  glVertex2i(384, 240);
  glVertex2i(390, 100);
  glEnd();
}
///*** Windmill_Blades_Model ***///
void Windmill_Blade() 
{
  ///Blade_One
  glPushMatrix();
  glRotatef(spin, 0, 0, 90);
  glBegin(GL_POLYGON);
  glVertex2i(-5, 0);
  glVertex2i(-85, -36);
  glVertex2i(-83, -37);
  glVertex2i(-3, -8);
  glEnd();
  glPopMatrix();
  ///Blade_Two
  glPushMatrix();
  glRotatef(spin, 0, 0, 90);
  glBegin(GL_POLYGON);
  glVertex2i(0, 5);
  glVertex2i(45, 70);
  glVertex2i(50, 73);
  glVertex2i(5, 0);
  glEnd();
  glPopMatrix();
  ///Blade_Three
  glPushMatrix();
  glRotatef(spin, 0, 0, 90);
  glBegin(GL_POLYGON);
  glVertex2i(68, -78);
  glVertex2i(0, 0);
  glVertex2i(5, 5);
  glVertex2i(70, -77);
  glEnd();
  glPopMatrix();
  }
  ///*** Windmill_Final_Model ***///
  void Windmill() {
  ///Windmill_Stand
  glColor3f(0.38, 0.41, 0.36);
  glPushMatrix();
  Windmill_Stand_Model();
  glPopMatrix();
  ///Windmill_Motor
  glColor3f(0.11, 0.23, 0.36);
  glPushMatrix();
  glTranslatef(380, 250, 0);
  circle(10);
  glPopMatrix();
  ///Windmill_Rotary_Blades
  glColor3f(0.11, 0.23, 0.36);
  glPushMatrix();
  glTranslatef(380, 251, 0);
  Windmill_Blade();
  glPopMatrix();
}
/// *** Windmill ***///
void Windmill_One() 
{
  glColor3f(0.11, 0.23, 0.36);
  glPushMatrix();
  glTranslatef(0, -10, 0);
  Windmill();
  glPopMatrix();
}
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 0.0, 1.0);
  Windmill_One();
  glFlush();
}
void move_right() 
{
  spin = spin + .1;
  ax = ax + .05;
  bx = bx + .08;
  cx = cx + .10;
  dx = dx + .15;
  if (cx > 1000) {
  cx = -300;
  }
  if (bx > 1000) {
  bx = -400;
  }
  if (cx > 1000) {
  cx = -400;
  }
  if (dx > 1000) {
  dx = -500;
  }
  glutPostRedisplay();
  }
  void mouse(int key, int state, int x, int y) {
  switch (key)
  {
  case GLUT_LEFT_BUTTON:
  if (state == GLUT_DOWN)
  {
  glutIdleFunc(move_right);
  }
  break;
  case GLUT_MIDDLE_BUTTON:
  case GLUT_RIGHT_BUTTON:
  if (state == GLUT_DOWN)
  {
  glutIdleFunc(NULL);
  }
  break;
  default:
  break;
  }
}
int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(50, 50);
  glutInitWindowSize(1080, 720);
  glutCreateWindow("Windmill");
  init();
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  glutMainLoop();
}
