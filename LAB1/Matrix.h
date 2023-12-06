#pragma once

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Matrix
{
public:
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix&);
	~Matrix();
	void show();

	Matrix& operator++ (int);
	Matrix& operator-- (int);

	bool Is_Zero_Matrix();
	bool Is_Square_Matrix();
	bool Is_Upper_Triangular_Matrix();
	bool Is_Lower_Triangular_Matrix();
	bool Is_Symmetric_Matrix();
	bool Is_Diagonal_Matrix();
	bool Is_Identity_Matrix();

	string Type_Definition();
	Matrix Matrix_Transpose();
	Matrix Submatrix_Extraction(int linestart, int linefinish, int columnstart, int columnfinish);
	void Rows_and_Columns_Change(int newcolumns, int newlines);

	int get_columns();
	int get_lines();
	int get_matrix(int lines, int columns);

	void set_matrix(int elem, int line, int column);

private:

	int columns;
	int lines;
	int** matrix;

	void Calculate_Lines();

};

