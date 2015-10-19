/*
 * Created: 09-10-2015
 * Modified: Mon 19 Oct 2015 12:03:52 CEST
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#include"matrix.hpp"
#include"vector.hpp"
#include<iostream>
#include<ostream>

// Helper functions in an unsigned namespace, makes them "private"
// to the current .cpp file
namespace {

void deleteMatrix(double ** data, unsigned rows)
{
  for (auto i = 0; i < rows; ++i)
    delete [] data[i];

  delete [] data;
}

}

namespace Math {

Matrix::Matrix()
  : data {nullptr},
    mat_size {0,0} {}

Matrix::Matrix(unsigned size_x, unsigned size_y)
  : data {new double*[size_x]},
    mat_size {size_x, size_y}
{
  for (auto i = 0; i < size_x; ++ i)
    data[i] = new double[size_y];
}

Matrix::Matrix(const Matrix & copy)
  : data {new double*[copy.mat_size.rows]},
    mat_size (copy.mat_size)
{
  for (auto i = 0; i < mat_size.rows; ++i) {
    data[i] = new double[mat_size.cols];

    for (auto j = 0; j < mat_size.cols; ++j) {
      data[i][j] = copy.data[i][j];
    }
  }
}

Matrix::Matrix(Matrix && temp)
  : data {temp.data},
    mat_size (temp.mat_size)
{
temp.data = nullptr;
temp.mat_size = {0,0};
}

// This constructor is a bit ugly with the current setup
// Makes it so that you can write Matrix m {{1,2}, {3,4}};
Matrix::Matrix(const std::initializer_list< std::initializer_list<double> > & init_list)
  : data {new double*[init_list.size()]},
    mat_size {static_cast<unsigned>(init_list.size()), static_cast<unsigned>(init_list.begin()->size())}
{
  unsigned i = 0;

  // This is the range based for loop from the lecture on day 5
  for (const auto & vec : init_list) {
    data[i] = new double[vec.size()];

    unsigned j = 0;
    for (const auto & elem : vec) {
      data[i][j] = elem;
      ++j;
    }

    ++i;
  }
}

Matrix& Matrix::operator=(const Matrix & copy)
{
  if (this == &copy)
    return *this;

  clear();

  mat_size = copy.mat_size;
  data = new double*[mat_size.rows];

  for (auto i = 0; i < mat_size.rows; ++i) {
    data[i] = new double[mat_size.cols];

    for (auto j = 0; j < mat_size.cols; ++j) {
      data[i][j] = copy.data[i][j];
    }
  }

  return *this;
}

Matrix& Matrix::operator=(Matrix && temp)
{
  if (this == &temp)
    return *this;

  clear();

  data = temp.data;
  mat_size = temp.mat_size;

  temp.data = nullptr;
  temp.mat_size = {0,0};

  return *this;
}

Matrix& Matrix::operator+=(const Matrix & rhs)
{
  if (mat_size.rows != rhs.mat_size.rows or mat_size.cols != rhs.mat_size.cols) {
    std::cerr << "Cannot add matrices of different sizes" << std::endl;
    return *this;
  }

  for (auto i = 0; i < mat_size.rows; ++i)
    for (auto j = 0; j < mat_size.cols; ++j)
      data[i][j] += rhs.data[i][j];

  return *this;
}

Matrix& Matrix::operator-=(const Matrix & rhs)
{
  if (mat_size.rows != rhs.mat_size.rows or mat_size.cols != rhs.mat_size.cols) {
    std::cerr << "Cannot add matrices of different sizes" << std::endl;
    return *this;
  }

  for (auto i = 0; i < mat_size.rows; ++i)
    for (auto j = 0; j < mat_size.cols; ++j)
      data[i][j] -= rhs.data[i][j];

  return *this;
}

void Matrix::clear()
{
  deleteMatrix(data, mat_size.rows);

  data = nullptr;
  mat_size = {0,0};
}

// Same as with vector, resizes the matrix and keeps as many
// as possible of its previous entries
void Matrix::resize(Size new_mat_size)
{
  auto old_data = data;

  data = new double*[new_mat_size.rows];

  for (auto i = 0; i < new_mat_size.rows; ++i)
    data[i] = new double[new_mat_size.cols];

  for (auto i = 0; i < std::min(mat_size.rows, new_mat_size.rows); ++i) {
    for (auto j = 0; j < std::min(mat_size.cols, new_mat_size.cols); ++j) {
      data[i][j] = old_data[i][j];
    }
  }

  deleteMatrix(old_data, mat_size.rows);
  mat_size = new_mat_size;
}

// To get the mat[i][j] syntax to work we need to return a temporary object
// that itself has a valid []-operator. So mat[i] returns the temporary object,
// which needs a []-operator. We could have returned data[i], but to have more
// control over our memory we return a "VectorView", which is a class we declare
// ourself. We can also give the VectorView similar properties to the Vector class
// wherever appropriate.
VectorView Matrix::operator[](unsigned i)
{
  return VectorView {data[i]};
}

ConstVectorView Matrix::operator[](unsigned i) const
{
  return ConstVectorView {data[i]};
}

// Also have a shorthand for element access, mat.at(i,j)
double & Matrix::at(unsigned i, unsigned j)
{
  return data[i][j];
}

const double Matrix::at(unsigned i, unsigned j) const
{
  return data[i][j];
}

double Matrix::trace() const
{
  auto result = 0.;
  auto size = std::min(mat_size.rows, mat_size.cols);

  for (auto i = 0; i < size; ++i)
    result += data[i][i];

  return result;
}

// Return a new matrix that is the transpose of the current matrix
const Matrix Matrix::transpose() const
{
  auto result = Matrix (mat_size.cols, mat_size.rows);

  for (auto i = 0; i < mat_size.rows; ++i)
    for (auto j = 0; j < mat_size.cols; ++j)
      result.at(j,i) = data[i][j];

  return result;
}

// Again use the copy constructor and += operator of matrix
// to write the + operator without code duplication
const Matrix operator+(const Matrix & lhs, const Matrix & rhs)
{
  auto result = lhs;
  result += rhs;
  return result;
}

const Matrix operator-(const Matrix & lhs, const Matrix & rhs)
{
  auto result = lhs;
  result -= rhs;
  return result;
}

// Matrix multiplication as expected
const Matrix operator*(const Matrix & lhs, const Matrix & rhs)
{
  if (lhs.size().cols != rhs.size().rows) {
    std::cerr << "The matrices are of wrong dimension for multiplication" << std::endl;
    return {};
  }

  auto result = Matrix(lhs.size().rows, rhs.size().cols);

  for (auto i = 0; i < result.size().rows; ++i) {
    for (auto j = 0; j < result.size().cols; ++j) {
      result.at(i,j) = 0;

      for (auto k = 0; k < lhs.size().cols; ++k)
        result.at(i,j) += lhs.at(i,k) * rhs.at(k,j);
    }
  }

  return result;
}

// Assume that all vectors a column vectors for this example
const Vector operator*(const Matrix & lhs, const Vector & rhs)
{
  if (lhs.size().cols != rhs.size()) {
    std::cerr << "The matrix vector pair is of wrong dimensions for multiplication" << std::endl;
    return {};
  }

  auto result = Vector (lhs.size().rows);

  for (auto i = 0; i < result.size(); ++i) {
    result[i] = 0;

    for (auto j = 0; j < lhs.size().cols; ++j)
      result[i] += lhs.at(i,j) * rhs[j];
  }

  return result;
}

// Semi pretty printing, can be made better by checking the number of
// digits in every column
std::ostream& operator<<(std::ostream &os, const Matrix &m)
{
  if (m.size().rows == 0) {
    os << "[[]]";
    return os;
  }

  os << "|";
  for (auto j = 0; j < m.size().cols; ++j)
    os << " " << m.at(0,j);
  os << " |";
  
  for (auto i = 1; i < m.size().rows; ++i) {
    os << "\n|";
    for (auto j = 0; j < m.size().cols; ++j)
      os << " " << m.at(i,j);
    os << " |";
  }

  return os;
}


} // namespace Math 
