
#include <bits/stdc++.h>

using namespace std;

class Diem {
    string hoten;
    char *sbd;
    float diem;

    public:
        // Constructor
        Diem() {
            hoten = "";
            sbd = new char[100];
            diem = 0;
        }
        Diem(string hoten, string sbd, float diem) {
            this->hoten = hoten;
            this->sbd = new char[100];
            for (size_t i = 0; i < sbd.length(); i++) {
                this->sbd[i] = sbd[i];
            }
            this->diem = diem;
        }
        // Destructor
        ~Diem() {
            delete[] sbd;
        }
        // Nhap xuat
        friend istream &operator>>(istream &is, Diem &d) {
            cout << "Nhap ho ten: ";
            getline(is, d.hoten);
            string temp;
            cout << "Nhap so bao danh: ";
            getline(is, temp);
            for (size_t i = 0; i < temp.length(); i++) {
                d.sbd[i] = temp[i];
            }
            cout << "Nhap diem: ";
            is >> d.diem;
            is.ignore();
            return is;
        }
        friend ostream &operator<<(ostream &os, Diem &d) {
            os << endl;
            os << "Ho ten: " << d.hoten << endl;
            os << "So bao danh: " << d.sbd << endl;
            os << "Diem: " << d.diem << endl;
            return os;
        }
        // Compare
        bool operator>=(Diem &d) {
            return diem >= d.diem;
        }
        // Copy
        Diem(const Diem &d) {
            hoten = d.hoten;
            sbd = new char[100];
            for (size_t i = 0; i < strlen(d.sbd); i++) {
                sbd[i] = d.sbd[i];
            }
            diem = d.diem;
        }
        Diem &operator=(const Diem &d) {
            hoten = d.hoten;
            sbd = new char[100];
            for (size_t i = 0; i < strlen(d.sbd); i++) {
                sbd[i] = d.sbd[i];
            }
            diem = d.diem;
            return *this;
        }
        // Get set
        float getDiem() {
            return diem;
        }
};

class BangDiem {
    Diem *a;
    int n;

    public:
        // Constructor
        BangDiem() {
            n = 0;
            a = new Diem[n];
        }
        BangDiem(int n) {
            this->n = n;
            a = new Diem[n];
        }
        // Destructor
        ~BangDiem() {
            delete[] a;
        }
        // Nhap xuat
        friend istream &operator>>(istream &is, BangDiem &bd) {
            cout << "Nhap so luong thi sinh: ";
            is >> bd.n;
            is.ignore();
            bd.a = new Diem[bd.n];
            for (size_t i = 0; i < bd.n; i++) {
                cout << "Nhap thi sinh thu " << i + 1 << endl;
                is >> bd.a[i];
            }
            return is;
        }
        friend ostream &operator<<(ostream &os, BangDiem &bd) {
            os << endl;
            for (size_t i = 0; i < bd.n; i++) {
                os << "Thi sinh thu " << i + 1 << endl;
                os << bd.a[i];
            }
            return os;
        }
        // Sap xep
        void sort() {
            for (size_t i = 0; i < n - 1; i++) {
                for (size_t j = i + 1; j < n; j++) {
                    if (a[i] >= a[j]) {
                        Diem temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                    }
                }
            }
        }
        // Tim diem A
        friend void findA(BangDiem &bd) {
            int c = 0;
            for (size_t i = 0; i < bd.n; i++) {
                if (bd.a[i].getDiem() >= 8.5) {
                    cout << "Thi sinh co diem A: " << bd.a[i];
                    c++;
                }
            }
            cout << "So thi sinh co diem A: " << c << endl;
        }
};

int main() {

    BangDiem bd;
    cin >> bd;
    cout << bd;
    bd.sort();
    cout << bd;

    findA(bd);

    return 0;
}