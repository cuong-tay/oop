
#include <bits/stdc++.h>

using namespace std;

class ptBac2 {
    private:
        double a, b, c;
    public:
        ptBac2() {
            a = b = c = 0;
        }
        ptBac2(double a, double b, double c) {
            this->a = a;
            this->b = b;
            this->c = c;
        }
        friend ostream& operator<<(ostream &os, const ptBac2 &p) {
            os << p.a << "x^2 + " << p.b << "x + " << p.c << " = 0" << endl;
            return os;
        }
        void solve() {
            double delta = b * b - 4 * a * c;
            if (delta < 0) {
                cout << "Phuong trinh vo nghiem" << endl;
            } else if (delta == 0) {
                cout << "Phuong trinh co nghiem kep x1 = x2 = " << -b / (2 * a) << endl;
            } else {
                cout << "Phuong trinh co 2 nghiem phan biet x1 = " << (-b + sqrt(delta)) / (2 * a) 
                << " va x2 = " << (-b - sqrt(delta)) / (2 * a) << endl;
            }
        }
        int songhiem() {
            double delta = b * b - 4 * a * c;
            if (delta < 0) {
                return 0;
            } else if (delta == 0) {
                return 1;
            } else {
                return 2;
            }
        }
};

int main() {

    ptBac2 p1, p2, p3;
    bool v = true;
    int n;
    double a, b, c;
    while (v) {
        cout << "Nhap 1 de nhap pt p1: " << endl;
        cout << "Nhap 2 de nhap pt p2: " << endl;
        cout << "Nhap 3 de nhap pt p3: " << endl;
        cout << "Nhap 4 de hien pt cac pt: " << endl;
        cout << "Nhap 5 nghiem cua cac pt: " << endl;
        cout << "Nhap 6 tong so nghiem cua cac pt: " << endl;
        cout << "Nhap 7 de thoat: " << endl;
        cin >> n;
        switch (n) {
            case 1:
                cout << "Nhap a, b, c: ";
                cin >> a >> b >> c;
                p1 = ptBac2(a, b, c);
                break;
            case 2:
                cout << "Nhap a, b, c: ";
                cin >> a >> b >> c;
                p2 = ptBac2(a, b, c);
                break;
            case 3:
                cout << "Nhap a, b, c: ";
                cin >> a >> b >> c;
                p3 = ptBac2(a, b, c);
                break;
            case 4:
                cout << p1 << p2 << p3;
                break;
            case 5:
                cout << "Nghiem cua p1: " << endl; p1.solve();
                cout << "Nghiem cua p2: " << endl; p2.solve();
                cout << "Nghiem cua p3: " << endl; p3.solve();
                break;
            case 6:
                cout << "Tong so nghiem cua cac pt: " << p1.songhiem() + p2.songhiem() + p3.songhiem() << endl; 
            case 7:
                v = false;
                break;
            default:
                cout << "Nhap sai, nhap lai" << endl;
                break;
        }
    }

    return 0;
}