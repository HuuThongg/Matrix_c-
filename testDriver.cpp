#include <iostream>
#include "MatrixType.h"
#include <fstream>
using namespace std;

int main()
{
  ofstream outputFile;
  outputFile.open("data.txt");

  MatrixType matrix;
  matrix.SetSize(2, 3);
  int k = 1;
  for (int i = 0; i < 2; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      matrix.StoreItem(k, i, j);
      k++;
    }
  }

  MatrixType matrix2;
  matrix2.SetSize(3, 2);
  k = 7;
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 2; ++j)
    {
      matrix2.StoreItem(k, i, j);
      k++;
    }
  }
  MatrixType matrix3;
  matrix3.SetSize(2, 2);
  matrix.Mult(matrix2, matrix3);
  matrix3.PrintMatrix();

  if (!outputFile.is_open())
  {
    cout << "Error opening file.\n";
  }
  else
  {
    matrix3.Print(outputFile);
  }
  outputFile.close();
  return 0;
}
