/*
 * Created: 30-09-2015
 * Modified: Wed 30 Sep 2015 12:30:33 CEST
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#include<string>
#include<iostream>

class Coordinate
{
friend void operator<<(std::ostream&,const Coordinate&);
friend std::ostream & operator+(std::ostream&,const Coordinate&);
friend std::ostream & operator==(std::ostream&,const Coordinate&);

public:
  Coordinate() = default;
  Coordinate (double x, double y)
    : x {x},
      y {y} {}

  double norm();

private:
    double x,y;

};

void operator<<(std::ostream & os, const Coordinate & c)
{
  os << "{" << c.x << "," << c.y << "}";
}

std::ostream & operator+(std::ostream & os, const Coordinate & c)
{
  os << "{" << c.x << "," << c.y << "}";
  return os;
}

std::ostream & operator==(std::ostream & os, const Coordinate & c)
{
  os << "{" << c.x << "," << c.y << "}";
  return os;
}

int main(int, char**)
{
  Coordinate c;
  c.norm();

  Coordinate * c_ptr = &c;

  (*c_ptr).norm();
  c_ptr->norm();

  
}
