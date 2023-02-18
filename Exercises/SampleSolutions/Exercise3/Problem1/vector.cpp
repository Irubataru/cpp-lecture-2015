/*
 * Created: 30-09-2015
 * Modified: Mon 19 Oct 2015 11:54:20 CEST
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include"vector.hpp"
#include<cmath>
#include<ostream>

namespace Math {

// The copy constructor
Vector::Vector(const Vector & copy)
  : data {new double[copy.vec_size]},
   vec_size {copy.vec_size}
{
  for (auto i = 0; i < vec_size; ++i) {
    data[i] = copy.data[i];
  }
}

// The move constructor
Vector::Vector(Vector && temp)
  : data {temp.data},
    vec_size {temp.vec_size}
{
  temp.data = nullptr;
  temp.vec_size = 0;
}

// Initialiser list constructor
// So that we can write: Vector v1 = {1, 2, 3, 4};
Vector::Vector(const std::initializer_list<double> & init_list)
  : data {new double[init_list.size()]},
    vec_size {static_cast<unsigned>(init_list.size())}
{
  unsigned i = 0;
  for (const auto & init_elem : init_list) {
    data[i] = init_elem;
    ++i;
  }
}

// Destructor
Vector::~Vector()
{
  clear();
}

// Copy assignment operator
Vector& Vector::operator=(const Vector & copy)
{
  // Check for self assignment
  // vec = vec;
  if (this == &copy)
    return *this;

  if (data != nullptr)
    delete [] data;

  vec_size = copy.vec_size;
  data = new double[vec_size];

  for (auto i = 0; i < vec_size; ++i) {
    data[i] = copy.data[i];
  }

  return *this;
}

Vector& Vector::operator=(Vector && temp)
{
  if (this == &temp)
    return *this;

  if (data != nullptr)
    delete [] data;

  data = temp.data;
  vec_size = temp.vec_size;

  temp.data = nullptr;
  temp.vec_size = 0;

  return *this;
}

Vector& Vector::operator+=(const Vector & rhs)
{
  for (auto i = 0; i < size(); ++i)
    data[i] += rhs[i];

  return *this;
}

Vector& Vector::operator-=(const Vector & rhs)
{
  for (auto i = 0; i < size(); ++i)
    data[i] -= rhs[i];

  return *this;
}

double& Vector::operator[](unsigned index)
{
  return data[index];
}

const double& Vector::operator[](unsigned index) const
{
  return data[index];
}

unsigned Vector::size() const
{
  return vec_size;
}

bool Vector::empty() const
{
  return (vec_size == 0);
}

// Resize the vector, keeping the previous entries
void Vector::resize(unsigned new_vec_size)
{
  auto temp_ptr = data;
  data = new double[new_vec_size];

  // Need to check how many elements of the
  // old data to copy over
  if (new_vec_size > vec_size) {
    for (auto i = 0; i < vec_size; ++i) {
      data[i] = temp_ptr[i];
    }
  } else {
    for (auto i = 0; i < new_vec_size; ++i) {
      data[i] = temp_ptr[i];
    }
  }

  delete [] temp_ptr;
  vec_size = new_vec_size;
}

// Small helper function to clean up memory
void Vector::clear()
{
  delete [] data;
  data = nullptr;
  vec_size = 0;
}

Vector Vector::operator-() const
{
  auto result = *this;

  for (auto i = 0; i < vec_size; ++i)
    result[i] *= -1;

  return result;
}

// Calculate the length of the vector
double Vector::norm() const
{
  double the_norm = 0.;

  for (auto i = 0; i < size(); ++i)
    the_norm += data[i]*data[i];

  return std::sqrt(the_norm);
}

// Make use of the copy constructor and += operator
// for vector to easily write standalone arithmetic operators
const Vector operator+(const Vector & lhs, const Vector & rhs)
{
  auto result = lhs;
  result += rhs;
  return result;
}

const Vector operator-(const Vector & lhs, const Vector & rhs)
{
  auto result = lhs;
  result -= rhs;
  return result;
}

// A somewhat inflated printing function to have the
// vector print nicely
std::ostream& operator<<(std::ostream & os, const Vector& v)
{
  if (v.empty()) {
    os << "[]";
    return os;
  }

  os << "[" << v[0];

  for (auto i = 1; i < v.size(); ++i)
    os << ", " << v[i];

  os << "]";

  return os;
}


} // namespace Math 
