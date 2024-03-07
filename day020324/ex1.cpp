
#include <bits/stdc++.h>

using namespace std;

class Diem {
    double x, y;
    char *ten;
    public:
        Diem(char ten = 'O', double x = 0, double y = 0) {
            this->x = x;
            this->y = y;
            this->ten = new char;
            *(this->ten) = ten;
        }
        Diem(const Diem& other) {
            this->x = other.x;
            this->y = other.y;
            this->ten = new char;
            *(this->ten) = *(other.ten);
        }
        Diem& operator=(const Diem& other) {
            if (this != &other) {
                x = other.x;
                y = other.y;
                ten = new char;
                *ten = *(other.ten);
            }
            return *this;
        }
        ~Diem() {
            cout << "Huy " << *ten <<  endl;
            if (ten) {
                delete[] ten;
            }
        }
        /* friend void xuat(const Diem &d) {
            cout <<  *d.ten << "(" << d.x << ", " << d.y << ")" << endl;
        } */
        void xuat() {
            cout <<  *ten << "(" << x << ", " << y << ")" << endl;
        }
        friend double tinhKhoangCach(const Diem& other1, const Diem& other2) {
            return sqrt((other1.x - other2.x) * (other1.x - other2.x) + (other1.y - other2.y) * (other1.y - other2.y));
        }
};

int main() {

    Diem A('A', 1, 2);
    Diem B('B', 3, 4);
    Diem C(B);
    /* xuat(A);
    xuat(B);
    xuat(C); */
    A.xuat();
    B.xuat();
    C.xuat();
    cout << tinhKhoangCach(A, B) << endl;
    return 0;
}