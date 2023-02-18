/*
 * Created: 07-10-2015
 * Modified: Mon 19 Oct 2015 11:57:20 CEST
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include"vector_view.hpp"
#include<initializer_list>
#include<iosfwd>

namespace Math {

// This is called a forward class declaration
// Need it to declare the Matrix-Vector mixing functions
class Vector;

class Matrix
{
public:

  // Simple internal helper class to store the matrix
  // size in a convenient container with intuitive names
  struct Size
  {
    unsigned rows, cols;
  };

  Matrix();
  Matrix(unsigned size_x, unsigned size_y);
  
  // In C++11 you can call other, previously declared, class constructors
  // from the initialisation list
  Matrix(unsigned size)
    : Matrix(size, size) {}

  Matrix(const Matrix &);
  Matrix(Matrix &&);
  Matrix(const std::initializer_list< std::initializer_list<double> > &);

  ~Matrix()
  {
    clear();
  }

  Matrix& operator=(const Matrix &);
  Matrix& operator=(Matrix &&);

  Matrix& operator+=(const Matrix &);
  Matrix& operator-=(const Matrix &);

  void clear();

  Size size() const
  {
    return mat_size;
  }

  void resize(Size);

  VectorView operator[](unsigned);
  ConstVectorView operator[](unsigned) const;

  double & at(unsigned, unsigned);
  const double at(unsigned, unsigned) const;

  double trace() const;
  const Matrix transpose() const;

private:
  double ** data;
  Size mat_size;

};

const Matrix operator+(const Matrix &, const Matrix &);
const Matrix operator-(const Matrix &, const Matrix &);
const Matrix operator*(const Matrix &, const Matrix &);
const Vector operator*(const Matrix &, const Vector &);

std::ostream& operator<<(std::ostream &, const Matrix &);

} // namespace Math 


#endif /* MATRIX_HPP */
