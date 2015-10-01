#pragma once

namespace Math {

class Vector
{
public:
  Vector()
    : data {nullptr},
      size {0} {}

  Vector(unsigned length)
    : data {new double[length]},
      size {length} {}

  Vector(const Vector & copy);
  Vector(Vector &&);

  ~Vector();

  Vector& operator=(const Vector &);

  double& operator[](unsigned index);
  const double& operator[](unsigned index) const;
  unsigned getSize() const;

  void resize(unsigned);

private:
  double * data;
  unsigned size;
};

} // namespace Math 
