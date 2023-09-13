#include "MatrixType.h"
#include <iostream>
#include <exception>
#include <fstream>
using namespace std;

MatrixType::MatrixType()
{
  MakeEmpty();
}

void MatrixType::MakeEmpty()
{
  numRows = 0;
  numCols = 0;
}

void MatrixType::SetSize(int rowsSize, int colSize)
{
  if (rowsSize < 0 || rowsSize >= MAX_ROWS || colSize < 0 || colSize >= MAX_COLS)
    throw out_of_range("Invalid matrix size.");

  numRows = rowsSize;
  numCols = colSize;
}

void MatrixType::StoreItem(int item, int row, int col)
{

  if (row < 0 || row >= MAX_ROWS || col < 0 || col >= MAX_COLS)
    throw out_of_range("Invalid matrix size.");

  values[row][col] = item;
}

void MatrixType::Add(MatrixType otherOperand, MatrixType &result)
{
  if (!AddSubCompatible(otherOperand))
    throw out_of_range("Invalid matrix size.");

  for (int i = 0; i < numRows; ++i)
  {
    for (int j = 0; j < numCols; ++j)
    {
      result.values[i][j] = values[i][j] + otherOperand.values[i][j];
    }
  }
}

void MatrixType::Sub(MatrixType otherOperand, MatrixType &result)
{
  if (!AddSubCompatible(otherOperand))
    throw out_of_range("Invalid matrix size.");
  for (int i = 0; i < numRows; ++i)
  {
    for (int j = 0; j < numCols; ++j)
    {
      result.values[i][j] = values[i][j] - otherOperand.values[i][j];
    }
  }
}

void MatrixType::Mult(MatrixType otherOperand, MatrixType &result)
{
  if (!MultCompatible(otherOperand))
    throw out_of_range("Invalid matrix size.");
  for (int i = 0; i < numRows; ++i)
  {
    for (int j = 0; j < otherOperand.numCols; ++j)
    {
      for (int k = 0; k < numCols; ++k)
      {
        result.values[i][j] += values[i][k] * otherOperand.values[k][j];
      }
    }
  }
}

void MatrixType::Print(ofstream &outfile)
{
  for (int i = 0; i < numRows; ++i)
  {
    for (int j = 0; j < numCols; ++j)
    {

      outfile << values[i][j] << " ";
    }
    outfile << endl;
  }
}
void MatrixType::PrintMatrix()
{
  for (int i = 0; i < numRows; ++i)
  {
    for (int j = 0; j < numCols; ++j)
    {

      cout << values[i][j] << " ";
    }
    cout << endl;
  }
}

bool MatrixType::AddSubCompatible(MatrixType otherOperand)
{
  return numRows == otherOperand.numRows && numCols == otherOperand.numCols;
}

bool MatrixType::MultCompatible(MatrixType otherOperand)
{
  return numCols == otherOperand.numRows;
}
