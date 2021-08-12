#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <iomanip>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

class Matrix {
private:
	int rows;
	int cols;
	vector<vector<int>> matrix;
public:
	Matrix() {
		rows = 0;
		cols = 0;
	}
	Matrix(const int& row, const int& col) {
		Reset(row, col);
	}
	void Reset(const int& new_rows, const int& new_cols) {
		if (new_rows < 0) {
			throw out_of_range("num_rows must be >= 0");
		}
		else if (new_cols < 0) {
			throw out_of_range("num_cols must be >= 0");
		}
		else if (new_rows == 0 || new_cols == 0) {
			rows = cols = 0;
		}
		else {
			rows = new_rows;
			cols = new_cols;
			matrix.assign(rows, vector<int>(cols));
		}
	}
	int At(const int& num_row, const int& num_col) const {
			return matrix.at(num_row).at(num_col);
	}
	int& At(const int& num_row, const int& num_col) {
		return matrix.at(num_row).at(num_col);
	}
	int GetNumRows() const {
		return rows;
	}
	int GetNumColumns() const {
		return cols;
	}
};

bool operator==(const Matrix& lhs, const Matrix& rhs) {
	if (lhs.GetNumColumns() != rhs.GetNumColumns()) {
		return false;
	}
	else if (lhs.GetNumRows() != rhs.GetNumRows()) {
		return false;
	}
	else {
		for (int i = 0; i < lhs.GetNumRows(); i++) {
			for (int j = 0; j < lhs.GetNumColumns(); j++) {
				if (lhs.At(i, j) != rhs.At(i, j)) {
					return false;
				}
			}
		}
		return true;
	}
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
	int rows = lhs.GetNumRows(); int cols = lhs.GetNumColumns();
	Matrix result(rows, cols);
	if (lhs.GetNumRows() == rhs.GetNumRows() && lhs.GetNumColumns() == rhs.GetNumColumns()) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				result.At(i,j) = lhs.At(i, j) + rhs.At(i, j);
			}
		}
		return result;
	}
	else {
		throw invalid_argument("");
	}
}

istream& operator>>(istream& stream, Matrix& matrix) {
	int rows; int cols;
	stream >> rows; stream.ignore(1); stream >> cols;
	matrix = Matrix(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			stream >> matrix.At(i, j);
		//  if (stream.peek() != ' ') {
		//	    throw exception();
		//  }
			stream.ignore(1);
		}
	}
	return stream;
}

ostream& operator<<(ostream& stream, const Matrix& matrix) {
	int rows = matrix.GetNumRows(); int cols = matrix.GetNumColumns();
	stream << rows << " " << cols << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			stream << matrix.At(i, j) << " ";
			if ((j+1) % cols == 0) {
				stream << endl;
			}
		}
	}
	return stream;
}

int main() {
	try {
		Matrix one;
		Matrix two;
		cin >> one >> two;
		cout << one + two << endl;
	}
	catch (exception& ex) {
		cout << ex.what();
	}
	return 0;
}
