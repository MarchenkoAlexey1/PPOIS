#include "Matrix.h"

void Matrix::Calculate_Lines() {
	int i = 0;
	string line;
	ifstream file("Real_Matrix.txt");
	if (file.is_open()) {
		while (getline(file, line)) this->lines++;
		this->columns++;
		while (line[i] != '\0') {
			if (line[i] == ' ') {
				this->columns++;
			}
			i++;
		}
	}
	file.close();
}

Matrix::Matrix(int column, int line)
{
	columns = column;
	lines = line;
	matrix = new int* [lines];
	for (int i = 0; i < lines; i++) {
		matrix[i] = new int[columns];
	}
}

Matrix::Matrix(const Matrix&other)
{
	this->lines = other.lines;
	this->columns = other.columns;
	this->matrix = new int* [this->lines];
	for (int i = 0; i < this->lines; i++) {
		this->matrix[i] = new int[this->columns];
	}
	for (int i = 0; i < this->lines; i++) {
		for (int j = 0; j < this->columns; j++) {
			this->matrix[i][j] = other.matrix[i][j];
		}
	}
}

Matrix::Matrix()
{
	int i = 0;
	string line;
	ifstream file("Real_Matrix.txt");
	if (file.is_open()) {

		Calculate_Lines();

		matrix = new int* [lines];
		for (int i = 0; i < lines; i++) {
			matrix[i] = new int[columns];
		}

		for (int i = 0; i < lines; i++) {
			for (int j = 0; j < columns; j++) {
				file >> matrix[i][j];
			}
		}
	}
	file.close();
}

Matrix::~Matrix()
{
	for (int i = 0; i < lines; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

void Matrix::show() {
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < columns; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

Matrix& Matrix::operator++ (int) {
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < columns; j++) {
			matrix[i][j]++;
		}
	}
	return *this;
}
Matrix& Matrix::operator-- (int) {
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < columns; j++) {
			matrix[i][j]--;
		}
	}
	return *this;
}

bool Matrix::Is_Zero_Matrix()
{
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < columns; j++) {
			if (matrix[i][j] != 0) return 0;
		}
	}
	return 1;
}

bool Matrix::Is_Square_Matrix()
{
	if (columns == lines) return 1;
	else return 0;
}

bool Matrix::Is_Upper_Triangular_Matrix()
{
	if (!Is_Square_Matrix()) return 0;
	for (int i = 0; i < lines - 1; i++) {
		for (int j = i + 1; j < columns; j++) {
			if (matrix[j][i] != 0) return 0;
		}
	}
	return 1;
}

bool Matrix::Is_Lower_Triangular_Matrix()
{
	if (!Is_Square_Matrix()) return 0;
	for (int i = 0; i < lines - 1; i++) {
		for (int j = i + 1; j < columns; j++) {
			if (matrix[i][j] != 0) return 0;
		}
	}
	return 1;
}

bool Matrix::Is_Symmetric_Matrix()
{
	if (!Is_Square_Matrix()) return 0;
	for (int i = 0; i < lines - 1; i++) {
		for (int j = i + 1; j < columns; j++) {
			if (matrix[i][j] != matrix[j][i]) return 0;
		}
	}
	return 1;
}

bool Matrix::Is_Diagonal_Matrix()
{
	if (!Is_Symmetric_Matrix()) return 0;
	for (int i = 0; i < lines - 1; i++) {
		for (int j = i + 1; j < columns; j++) {
			if (matrix[i][j] != 0 || matrix[j][i] != 0) return 0;
		}
	}
	return 1;
}

bool Matrix::Is_Identity_Matrix()
{
	if (!Is_Square_Matrix()) return 0;
	for (int i = 0; i < lines; i++) {
		if (matrix[i][i] != 1) return 0;
	}
	return 1;
}

string Matrix::Type_Definition() {
	if (Is_Zero_Matrix()) return "Нулевая";
	if (Is_Square_Matrix()) {
		if (Is_Upper_Triangular_Matrix() == true && Is_Lower_Triangular_Matrix() == false) return "Верхняя треугольная";
		if (Is_Upper_Triangular_Matrix() == false && Is_Lower_Triangular_Matrix() == true) return "Нижняя треугольная";
		if (Is_Symmetric_Matrix()) {
			if (Is_Diagonal_Matrix()) {
				if (Is_Identity_Matrix()) {
					return "Единичная";
				}
				return "Диагональная";
			}
			return "Симметрическая";
		}
		return "Квадратная";
	}
	else return "Прямоугольная";
}

Matrix Matrix::Matrix_Transpose() {
	Matrix tr_matrix(this->columns, this->lines);
	for (int j = 0; j < columns; j++) {
		for (int i = 0; i < lines; i++) {
			tr_matrix.matrix[j][i] = this->matrix[i][j];
		}
	}
	return tr_matrix;
}
Matrix Matrix::Submatrix_Extraction(int linestart, int linefinish, int columnstart, int columnfinish) {
	Matrix Submatrix(columnfinish - columnstart + 1, linefinish - linestart + 1);
	int sublines = 0, subcolumns = 0;
	for (int i = linestart; i <= linefinish; i++) {
		for (int j = columnstart; j <= columnfinish; j++) {
			Submatrix.matrix[sublines][subcolumns] = matrix[i][j];
			subcolumns++;
		}
		subcolumns = 0;
		sublines++;
	}
	return Submatrix;
}
void Matrix::Rows_and_Columns_Change(int newcolumns, int newlines) {
	int** bufermatrix = new int* [newlines];
	for (int i = 0; i < newlines; i++) {
		bufermatrix[i] = new int[newcolumns];
	}
	for (int i = 0; i < lines && i < newlines; i++) {
		for (int j = 0; j < columns && j < newcolumns; j++) {
			bufermatrix[i][j] = matrix[i][j];
		}
	}
	for (int i = 0; i < lines; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	lines = newlines;
	columns = newcolumns;
	matrix = new int* [lines];
	for (int i = 0; i < lines; i++) {
		matrix[i] = new int[columns];
	}

	for (int i = 0; i < newlines; i++) {
		for (int j = 0; j < newcolumns; j++) {
			matrix[i][j] = bufermatrix[i][j];
		}
	}

	for (int i = 0; i < newlines; i++) {
		delete[] bufermatrix[i];
	}
	delete[] bufermatrix;
}

int Matrix::get_columns()
{
	return columns;
}

int Matrix::get_lines()
{
	return lines;
}

int Matrix::get_matrix(int lines, int columns)
{
	return matrix[lines][columns];
}

void Matrix::set_matrix(int elem, int line, int column)
{
	this->matrix[line][column] = elem;
}