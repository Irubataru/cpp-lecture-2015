/*
 * Created: 28-09-2015
 * Modified: Wed 30 Sep 2015 19:41:49 CEST
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include<iostream>

const std::size_t size = 3;

void matrixAddition(double m1[][size], double m2[][size], double res[][size]);
void matrixMultiplication(double m1[][size], double m2[][size], double res[][size]);

void printMatrix(double m1[][size]);

int main()
{
  double m1[][size] = {
    {1, 2, 3},
    {4, 5, 6},
    {1, 2, 3} };

  double m2[][size] = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1}};

  double res[size][size];

  matrixAddition(m1,m2,res);
  printMatrix(res);

  matrixMultiplication(m1,m2,res);
  printMatrix(res);
}

void matrixAddition(double m1[][size], double m2[][size], double res[][size])
{
  for (auto i = 0; i < size; ++i) {
    for (auto j = 0; j < size; ++j) {
      res[i][j] = m1[i][j] + m2[i][j];
    }
  }
}

void matrixMultiplication(double m1[][size], double m2[][size], double res[][size])
{
  for (auto i = 0; i < size; ++i) {
    for (auto j = 0; j < size; ++j) {
      res[i][j] = 0.;
      for (auto k = 0; k < size; ++k) {
        res[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }
}

void printMatrix(double m1[][size])
{
  for (auto i = 0; i < size; ++i) {
    for (auto j = 0; j < size; ++j) {
      std::cout << m1[i][j] << " ";
    }
    std::cout << "\n";
  }
}

