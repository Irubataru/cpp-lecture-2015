/*
 * Created: 09-10-2015
 * Modified: Fri 09 Oct 2015 13:06:54 CEST
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#ifndef VECTOR_VIEW_HPP
#define VECTOR_VIEW_HPP

namespace Math {

class VectorView
{
public:
  VectorView(double* the_data)
    : data {the_data} {}

  double& operator[](unsigned i)
  {
    return data[i];
  }

private:
  double * data;

};

class ConstVectorView
{
public:
  ConstVectorView(const double* the_data)
    : data {the_data} {}

  const double operator[](unsigned i) const
  {
    return data[i];
  }

private:
  const double * data;

};

} // namespace Math 


#endif /* VECTOR_VIEW_HPP */
