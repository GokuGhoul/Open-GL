//Boundary Fill using OpenGL 
#include <GL/glut.h>  
#include<math.h>  
#include<stdio.h>  
int ww = 600, wh = 500;  
float fillCol[3] = { 0.4,1.5,0.0 };  
float borderCol[3] = { 0.0,0.0,0.0 };  
void setPixel(int, int, float[]);  
void getPixel(int, int, float[]);  
void resize(int, int);  
void drawPolygon(int, int, int, int);  
void boundaryFill4(int, int, float[], float[]);  
void display();  
void mouse(int, int, int, int);  
int main(int argc, char** argv)  
{  
  glutInit(&argc, argv);  
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
  glutInitWindowSize(ww, wh);  
  glutInitWindowPosition(500, 50);  
  glutCreateWindow("boundary-Fill");  
  glutDisplayFunc(display);  
  glutMouseFunc(mouse);  
  //calls whenever frame buffer window is resized  
  glutReshapeFunc(resize);  
  glutMainLoop();  
  return 0;  
}  
void setPixel(int pointx, int pointy, float f[3])  
{  
  glBegin(GL_POINTS);  
  glColor3fv(f);  
  glVertex2i(pointx, pointy);  
  glEnd();  
  glFlush();  
}  
void getPixel(int x, int y, float pixels[3])  
{  
  glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, pixels);  
}  
void resize(int w, int h)  
{  
  glMatrixMode(GL_PROJECTION); //set projection parameters  glLoadIdentity();  
  gluOrtho2D(0.0, w, 0.0, h);  
  glutReshapeWindow(ww, wh);  
  glViewport(0.0, 0.0, w, h); 
}  
void drawPolygon(int x1, int y1, int x2, int y2)  
{  
  glColor3f(0.0, 0.0, 0.0);  
  glBegin(GL_LINE_LOOP);  
  glVertex2i(x1, y1);  
  glVertex2i(x1, y2);  
  glVertex2i(x2, y2);  
  glVertex2i(x2, y1);  
  glEnd();  
  glFlush();  
}  
void display()  
{  
  glClearColor(1.0, 1.0, 1.0, 1.0);  
  glClear(GL_COLOR_BUFFER_BIT);  
  //If you modify following values, u should change condition in mouse() also.  drawPolygon(150, 250, 200, 300);  
  glFlush();  
} 
void boundaryFill4(int x, int y, float fillColor[3], float borderColor[3]) { 
float interiorColor[3]; 
getPixel(x, y, interiorColor); 
if (((interiorColor[0] != borderColor[0] && (interiorColor[1]) != borderColor[1] && (interiorColor[2]) != borderColor[2]) && (interiorColor[0] != fillColor[0] && (interiorColor[1]) != fillColor[1] && (interiorColor[2]) != fillColor[2]))) 
{ 
  setPixel(x, y, fillColor); 
  boundaryFill4(x + 1, y, fillColor, borderColor); 
  boundaryFill4(x - 1, y, fillColor, borderColor); 
  boundaryFill4(x, y + 1, fillColor, borderColor); 
  boundaryFill4(x, y - 1, fillColor, borderColor); 
} 
} 
void mouse(int btn, int state, int x, int y) 
  { 
  //This check is based on size of the polygon mentioned in display() function if (((x < 150 || x>200) || (y < 200 || y>250))) 
  printf("Invalid click !!\n"); 
  else 
  if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { 
  int xi = x; 
  int yi = (wh - y); 
  boundaryFill4(xi, yi, fillCol, borderCol); 
  } 
}
