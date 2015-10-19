#pragma once

#include<initializer_list>
#include<iosfwd>

namespace Math {

class Vector
{
public:
  Vector()
    : data {nullptr},
      vec_size {0} {}

  Vector(unsigned length)
    : data {new double[length]},
      vec_size {length} {}

  Vector(const Vector & copy);
  Vector(Vector &&);
  Vector(const std::initializer_list<double> &);

  ~Vector();

  Vector& operator=(const Vector &);
  Vector& operator=(Vector &&);

  Vector& operator+=(const Vector &);
  Vector& operator-=(const Vector &);

  double& operator[](unsigned index);
  const double& operator[](unsigned index) const;

  unsigned size() const;
  bool empty() const;
  void resize(unsigned);
  void clear();
  
  Vector operator-() const;
  double norm() const;

private:
  double * data;
  unsigned vec_size;
};

const Vector operator+(const Vector &, const Vector &);
const Vector operator-(const Vector &, const Vector &);
std::ostream& operator<<(std::ostream&, const Vector &);

} // namespace Math 
