/*
 * Created: 01-10-2015
 * Modified: Thu 01 Oct 2015 10:37:05 CEST
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include<iostream>
#include<string>
#include<cmath>

class Shape
{
public:
  virtual double area() = 0;

  virtual std::string name() const = 0;
};

double Shape::area()
{
  return 0.;
}

class Rectangle : public Shape
{
public:
  explicit Rectangle (double length = 0., double width = 0.)
    : side_length_x {length},
      side_length_y {width} {}

  virtual double area() override
  {
    return side_length_x * side_length_y;
  }

  virtual std::string name() const override
  {
    return "Rectangle";
  }

private:
 double side_length_x, side_length_y;
};

class Circle : public Shape
{
public:
  explicit Circle(double r = 0)
    : radius {r} {}

  virtual double area() override
  {
    return M_PI * radius * radius;
  }

  virtual std::string name() const override
  {
    return "Circle";
  }

private:
  double radius;
};

void prettyPrint(Shape & shape)
{
  std::cout << shape.name()  << " area: " << shape.area() << std::endl;
}

int main(int, char**)
{
  Rectangle r1 {4, 5};
  prettyPrint(r1);

  Circle c1 {3};
  prettyPrint(c1);
}
