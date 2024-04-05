
#include <bits/stdc++.h>

using namespace std;

class Matrix {

    int n;
    vector<vector<int> > matrix;

    public:
        // Constructor
        Matrix();
        Matrix(int n);
        Matrix(int n, vector<vector<int> > matrix);
        // Operator >>, <<
        friend istream& operator>>(istream& os, Matrix& matrix);
        friend ostream& operator<<(ostream& os, const Matrix& matrix);
        // Friend element max in matrix
        friend int maxElement(const Matrix &matrix);
        // TBC so le nam tren duong cheo chinh
        int sumOddNumberOnMainDiagonal();
};
// Constructor
Matrix::Matrix() {
}
Matrix::Matrix(int n) {
    this->n = n;
    this->matrix = vector<vector<int> >(n, vector<int>(n, 0));
}
Matrix::Matrix(int n, vector<vector<int> > matrix) {
    this->n = n;
    this->matrix = matrix;
}
// Operator >>, <<
istream& operator>>(istream& os, Matrix& matrix) {
    cout << "Nhap kich thuoc ma tran: ";
    os >> matrix.n;
    matrix.matrix = vector<vector<int> >(matrix.n, vector<int>(matrix.n, 0));
    cout << "Nhap cac phan tu cua ma tran: ";
    for (int i = 0; i < matrix.n; i++) {
        for (int j = 0; j < matrix.n; j++) {
            os >> matrix.matrix[i][j];
        }
    }
    return os;
}
ostream& operator<<(ostream& os, const Matrix& matrix) {
    os << "Matrix: " << endl;
    for (int i = 0; i < matrix.n; i++) {
        for (int j = 0; j < matrix.n; j++) {
            os << matrix.matrix[i][j] << " ";
        }
        os << endl;
    }
    return os;
}
// Friend element max in matrix
int maxElement(const Matrix &matrix) {
    int max = matrix.matrix[0][0];
    for (int i = 0; i < matrix.n; i++) {
        for (int j = 0; j < matrix.n; j++) {
            if (matrix.matrix[i][j] > max) {
                max = matrix.matrix[i][j];
            }
        }
    }
    return max;
}
// TBC so le nam tren duong cheo chinh
int Matrix::sumOddNumberOnMainDiagonal() {
    int sum = 0;
    int c = 0;
    for (int i = 0; i < this->n - 1; i++) {
        for (int j = i + 1; j < this-> n; j++) {
            if (this->matrix[i][j] % 2 != 0) {
                sum += this->matrix[i][j];
                c++;
            }
        }
    }
    return c == 0 ? 0 : sum/c;
}
int main() {
    int size = 2; 
    vector<vector<int> > matrix(size, vector<int>(size, 0));
    Matrix A(size, matrix);
    Matrix B;
    cin >> B;
    cout << "Ma tran A: " << endl;
    cout << A;
    cout << "Ma tran B: " << endl;
    cout << B;

    cout << "Phan tu lon nhat trong ma tran B: " << maxElement(B) << endl;
    cout << "Tong phan tu le nam tren duong cheo chinh B: " << B.sumOddNumberOnMainDiagonal() << endl;
    double t = (maxElement(A) + maxElement(B));
    if (t == 0) {
        cout << "Err" << endl;
    } else {
        cout << "Gia tri 23122021/(Max(A) + Max(B)): " << 23122021/t << endl;
    }
    double t1 = (maxElement(A) - maxElement(B)) > 0 
                                        ? sqrt(maxElement(A) - maxElement(B)) : -1;
    cout << "Gia tri sqrt(Max(A) - Max(B)): " << t1 << endl;

    return 0;
}