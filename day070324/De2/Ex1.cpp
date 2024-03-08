
#include <bits/stdc++.h>

using namespace std;

class Htron {
    private:
        double x, y;
        double r;
    public:
        Htron(){}
        Htron(double x, double y, double r) {
            this->x = x;
            this->y = y;
            this->r = r;
        }
        friend ostream& operator<<(ostream& os, const Htron& h) {
            os << "Htron: " << endl;
            os << "Toa do tam: (" << h.x << ", " << h.y << ")" << endl;
            os << "Ban kinh: " << h.r << endl;
            return os;
        }
        friend istream& operator>>(istream& is, Htron& h) {
            cout << "Nhap toa do tam: ";
            is >> h.x >> h.y;
            cout << "Nhap ban kinh: ";
            is >> h.r;
            return is;
        }
        double getR() {
            return r;
        }
};

int main() {

    Htron h1, h2, h3;
    cin >> h1 >> h2 >> h3;
    cout << h1 << h2 << h3;

    cout << "Trung binh cong dien tich 3 hinh tron: " << pow((h1.getR() + h2.getR() + h3.getR()), 2)*3.14 / 3 << endl;

    return 0;
}