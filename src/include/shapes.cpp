struct Position {
  float x;
  float y;
};

struct Size {
  float width;
  float height;
};

/**
 * Color in
 * 
 * @float r Red
 * @float g Green
 * @float b Blue
 */
struct Color {
  float r;
  float g;
  float b;
};

/**
 * Position from where the Object is referenced.
 */
enum Reference {
  bottomLeft  = 0,
  bottomCenter= 1,
  bottomRight = 2,
  centerLeft  = 3,
  center      = 4,
  centerCenter= 4,
  centerRight = 5,
  topLeft     = 6,
  topCenter   = 7,
  topRight    = 8,
};

/**
 * A class repesenting a rectangle
 * 
 * @class Rectangle
 */
class Rectangle {
  public:
    Position position {-1.0f, -1.0f};
    Size size {0.2f, 0.2f};
    Color color { 0.0f, 0.0f, 0.0f};
    float getX2() { return position.x+size.width;  }
    float getY2() { return position.y+size.height; }
};

// position, radius
// position edge (down left)
// position, width, height


void rectangle( Rectangle rect) {
  glColor3f(rect.color.r, rect.color.g, rect.color.b);
  glRectf(rect.position.x,rect.position.y, rect.getX2(), rect.getY2());
}

/**
 * A class representing a circle
 */
class Circle {
  public:
    Reference ref { bottomLeft };
    Position position {0.0f, 0.0f};
    Color color { 0.3f, 0.3f, 0.5f};
    float radius {0.5f};
};

class Grid {
  public:
    float width  {10.0f};
    float height {10.0f};
    float margin {0.00f};
    void rectangleGrid( float x, float y, float isWhite) {
      Rectangle r;
      r.position.x = 2.0f*x/width  -1.0f;
      r.position.y = 2.0f*y/height -1.0f;
      r.size.width  = 2.0f/width;
      r.size.height = 2.0f/height;
      r.color = {isWhite, isWhite, isWhite};
      rectangle(r);
     }
};

/////////////////// FUNCTIONS ///////////////////




void drawCircle (Circle c) {

  int num_segments = 54;
  float cx = -1.0f;
  float cy = -1.0f;
  float r  = c.radius;
  
  if (c.ref == bottomLeft) {
    cx = c.position.x + r;
    cy = c.position.y + r;  
  } else if (c.ref == bottomCenter ) {
    cx = c.position.x;
    cy = c.position.y + r;
  } else if (c.ref == bottomRight ) {
    cx = c.position.x - r;
    cy = c.position.y + r;
  } else if (c.ref == centerLeft ) {
    cx = c.position.x + r;
    cy = c.position.y;
  } else if (c.ref == centerRight ) {
    cx = c.position.x - r;
    cy = c.position.y;
  } else if (c.ref == topLeft ) {
    cx = c.position.x + r;
    cy = c.position.y - r;
  } else if (c.ref == topCenter ) {
    cx = c.position.x;
    cy = c.position.y - r;
  } else if (c.ref == topRight ) {
    cx = c.position.x - r;
    cy = c.position.y - r;
  } else {
    cx = c.position.x;
    cy = c.position.y;
  }
  
  glColor3f(c.color.r, c.color.g, c.color.b);
  glBegin(GL_TRIANGLE_FAN);
    for (int ii = 0; ii < num_segments; ii++)   {
      float theta = 2.0f * M_PI * float(ii) / float(num_segments);//get the current angle 
      float x = r * cosf(theta);//calculate the x component 
      float y = r * sinf(theta);//calculate the y component 
      glVertex2f(x + cx, y + cy);//output vertex 
    }
  glEnd();
}