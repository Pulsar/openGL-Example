/*  demo.c */

// Include openGL libraries
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
// Add math functions
#include <math.h>


#include <ctime>
#include <cstdlib>
#include "include/shapes.cpp"

void setup() {   glClearColor(0.4f, 0.4f, 0.4f, 1.0f); }

bool** randomGrid(unsigned int width=10, unsigned int height=10) {
  srand(time(NULL));
  bool** array = 0;
  array = new bool*[width];

  for (unsigned int w = 0; w < width; w++){
    array[w] = new bool[width];
    for (unsigned int h = 0; h < height; h++) {
      array[w][h] = rand() % 2;
    }  
  }

  return array;
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // rectangleGrid(0,0);
  Grid grid;
  srand(time(NULL));
  bool** array = randomGrid(10,10);
  for (int j = 0; j < grid.height; j++) {
    for (int i = 0; i < grid.width; i++){
      grid.rectangleGrid(float(i),float(j), array[i][j]);
    }  
  }
  glutSwapBuffers();
}
  

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(1920, 0); // Display on second screen :)
  glutCreateWindow("Hello World");

  setup();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}