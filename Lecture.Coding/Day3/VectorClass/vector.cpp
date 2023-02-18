/*
 * Created: 30-09-2015
 * Modified: Wed 30 Sep 2015 16:41:54 CEST
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include"vector.hpp"

namespace Math {

Vector::Vector(const Vector & copy)
  : data {new double[copy.size]},
   size {copy.size}
{
  for (auto i = 0; i < size; ++i) {
    data[i] = copy.data[i];
  }
}

Vector::Vector(Vector && temp)
  : data {temp.data},
    size {temp.size}
{
  temp.data = nullptr;
  temp.size = 0;
}

Vector::~Vector()
{
  if (data != nullptr) {
    delete [] data;
  }
}

Vector& Vector::operator=(const Vector & copy)
{
  size = copy.size;
  data = new double[size];

  for (auto i = 0; i < size; ++i) {
    data[i] = copy.data[i];
  }

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

unsigned Vector::getSize() const
{
  return size;
}

void Vector::resize(unsigned new_size)
{
  auto temp_ptr = data;
  data = new double[new_size];

  if (new_size > size) {
    for (auto i = 0; i < size; ++i) {
      data[i] = temp_ptr[i];
    }
  } else {
    for (auto i = 0; i < new_size; ++i) {
      data[i] = temp_ptr[i];
    }
  }

  delete [] temp_ptr;
  size = new_size;
}


} // namespace Math 
