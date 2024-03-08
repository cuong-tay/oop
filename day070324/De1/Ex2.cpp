
#include <bits/stdc++.h>

using namespace std;

class FMatrix {
    private:
        int n, m;
        double **a;
    public:
        FMatrix(){}
        FMatrix(int n, int m) {
            this->n = n;
            this->m = m;
            a = new double*[n];
            for (int i = 0; i < n; i++) {
                a[i] = new double[m];
            }
        }
        ~FMatrix() {
            for (int i = 0; i < n; i++) {
                delete[] a[i];
            }
            delete[] a;
        }
        friend ostream& operator<<(ostream& os, const FMatrix& f) {
            cout << "Matrix: " << endl;
            for (int i = 0; i < f.n; i++) {
                for (int j = 0; j < f.m; j++) {
                    os << f.a[i][j] << " ";
                }
                os << endl;
            }
            return os;
        }
        friend FMatrix operator+(const FMatrix& a, const FMatrix& b) {
            FMatrix res(a.n, a.m);
            for (int i = 0; i < a.n; i++) {
                for (int j = 0; j < a.m; j++) {
                    res.a[i][j] = a.a[i][j] + b.a[i][j];
                }
            }
            return res;
        }
        friend istream& operator>>(istream& is, FMatrix& f) {
            cout << "Nhap so hang: ";
            is >> f.n;
            cout << "Nhap so cot: ";
            is >> f.m;
            f.a = new double*[f.n];
            for (int i = 0; i < f.n; i++) {
                f.a[i] = new double[f.m];
            }
            for (int i = 0; i < f.n; i++) {
                for (int j = 0; j < f.m; j++) {
                    cout << "Nhap phan tu [" << i << "][" << j << "]: ";
                    is >> f.a[i][j];
                }
            }
            return is;
        }
        friend double tbc(const FMatrix& f) {
            double sum = 0;
            int c = 0;
            for (int i = 0; i < f.n; i++) {
                for (int j = 0; j < f.m; j++) {
                    if (f.a[i][j] > 200 || f.a[i][j] < 10) {
                        c++;
                        sum += f.a[i][j];
                    }
                    
                }
            }
            if ( c == 0) {
                return 0;
            }
            return sum / c;
        }
};

int main() {

    FMatrix a;
    cin >> a;
    cout << a;
    cout << tbc(a) << endl;

    return 0;
}