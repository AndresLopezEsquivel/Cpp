#include <iostream>

class Shape // Abstract class
{
  // An abstract class:
  // - Is a class that cannot be instantiated.
  // - Is a class that is designed to be a base class.
  // - Is a class that contains at least one pure virtual function.
  public:
  virtual void draw() = 0; // Pure virtual function
  virtual void rotate() = 0; // Pure virtual function
  virtual ~Shape() { std::cout << "Shape destructor" << std::endl; };
};

class OpenShape : public Shape // Abstract class
{
  // OpenShape is an abstract class because it doesn't
  // override the pure virtual functions of the base class Shape
  public:
  virtual ~OpenShape() { std::cout << "OpenShape destructor" << std::endl; };
};

class CloseShape : public Shape // Abstract class
{
  // CloseShape is an abstract class because it doesn't
  // override the pure virtual functions of the base class Shape
  public:
  virtual ~CloseShape() { std::cout << "CloseShape destructor" << std::endl; };
};

class Line : public OpenShape // Concrete class
{
  // A concrete class:
  // - Is a class that can be instantiated.
  // - Is a class that cannot contain pure virtual functions.
  // - Is a class that must override all pure virtual functions of the base class.
  public:
  ~Line() { std::cout << "Line destructor" << std::endl; };
  virtual void draw() override { std::cout << "Drawing a line" << std::endl; };
  virtual void rotate() override { std::cout << "Rotating a line" << std::endl; };
};

class Square : public CloseShape // Concrete class
{
  public:
  ~Square() { std::cout << "Square destructor" << std::endl; };
  virtual void draw() override { std::cout << "Drawing a square" << std::endl; };
  virtual void rotate() override { std::cout << "Rotating a square" << std::endl; };
};

class Circle : public CloseShape // Concrete class
{
  public:
  ~Circle() { std::cout << "Circle destructor" << std::endl; };
  virtual void draw() override { std::cout << "Drawing a circle" << std::endl; };
  virtual void rotate() override { std::cout << "Rotating a circle" << std::endl; };
};

void refresh_screen(const std::vector<Shape*> &shapes)
{
  for(const auto shape : shapes)
  {
    std::cout << std::endl;
    shape->draw();
    shape->rotate();
  }
}

int main()
{
  // Shape shape; // Error: Cannot instantiate an abstract class
  // OpenShape openShape; // Error: Cannot instantiate an abstract class
  // CloseShape closeShape; // Error: Cannot instantiate an abstract class

  // Shape *shape = new Shape(); // Error: Cannot instantiate an abstract class
  // Shape *openShape = new OpenShape(); // Error: Cannot instantiate an abstract class
  // Shape *closeShape = new CloseShape(); // Error: Cannot instantiate an abstract class

  Shape *line = new Line();
  Shape *circle = new Circle();
  Shape *square = new Square();

  std::vector<Shape*> shapes {line, circle};
  refresh_screen(shapes);
  // Output:
  // Drawing a line
  // Rotating a line
  // Drawing a circle
  // Rotating a circle
  std::cout << std::endl << std::endl;
  shapes.push_back(square);
  refresh_screen(shapes);
  // Output:
  // Drawing a line
  // Rotating a line
  // Drawing a circle
  // Rotating a circle
  // Drawing a square
  // Rotating a square
  std::cout << std::endl << std::endl;

  delete line;
  // Output:
  // Line destructor
  // OpenShape destructor
  // Shape destructor
  delete circle;
  // Output:
  // Circle destructor
  // CloseShape destructor
  // Shape destructor
  delete square;
  // Output:
  // Square destructor
  // CloseShape destructor
  // Shape destructor

  return 0;
}
