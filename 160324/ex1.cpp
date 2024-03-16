
#include <bits/stdc++.h>

using namespace std;

class DoanVien {
    string hoten;
    char *quequan;
    int nam_cao_doan;

    public:
        // Constructor
        DoanVien() {
            hoten = "";
            quequan = new char[100];
            nam_cao_doan = 0;
        }
        DoanVien(string hoten, string quequan, int nam_cao_doan) {
            this->hoten = hoten;
            this->quequan = new char[100]; 
            for (size_t i = 0; i < quequan.length(); i++) {
                this->quequan[i] = quequan[i];
            }
            this->nam_cao_doan = nam_cao_doan;
        }
        // Destructor
        ~DoanVien() {
            delete[] quequan;
        }
        // Nhap xuat
        friend istream &operator>>(istream &is, DoanVien &dv) {
            cout << "Nhap ho ten: ";
            getline(is, dv.hoten);
            string temp;
            cout << "Nhap que quan: ";
            getline(is, temp);
            for (size_t i = 0; i < temp.length(); i++) {
                dv.quequan[i] = temp[i];
            }
            cout << "Nhap nam vao doan: ";
            is >> dv.nam_cao_doan;
            is.ignore();
            return is;
        }
        friend ostream &operator<<(ostream &os, DoanVien &dv) {
            os << endl;
            os << "Ho ten: " << dv.hoten << endl;
            os << "Que quan: " << dv.quequan << endl;
            os << "Nam vao doan: " << dv.nam_cao_doan << endl;
            return os;
        }
        // Copy 
        DoanVien(const DoanVien &dv) {
            hoten = dv.hoten;
            quequan = new char[100];
            for (size_t i = 0; i < strlen(dv.quequan); i++) {
                quequan[i] = dv.quequan[i];
            }
            nam_cao_doan = dv.nam_cao_doan;
        }
        DoanVien &operator=(const DoanVien &dv) {
            hoten = dv.hoten;
            quequan = new char[100];
            for (size_t i = 0; i < strlen(dv.quequan); i++) {
                quequan[i] = dv.quequan[i];
            }
            nam_cao_doan = dv.nam_cao_doan;
            return *this;
        }
        // Compare
        bool operator>=(const DoanVien &dv) {
            return nam_cao_doan >= dv.nam_cao_doan;
        }
};
class DanhSachDoanVien {
    DoanVien *ds;
    int n;
    
        public:
            // Constructor
            DanhSachDoanVien() {
                n = 0;
                ds = new DoanVien[100];
            }
            DanhSachDoanVien(int n) {
                this->n = n;
                ds = new DoanVien[n];
            }
            // Destructor
            ~DanhSachDoanVien() {
                delete[] ds;
            }
            // Nhap xuat
            friend istream &operator>>(istream &is, DanhSachDoanVien &dsdv) {
                cout << "Nhap so luong doan vien: ";
                is >> dsdv.n;
                is.ignore();
                for (size_t i = 0; i < dsdv.n; i++) {
                    cout << "Nhap doan vien thu " << i + 1 << ": " << endl;
                    is >> dsdv.ds[i];
                }
                return is;
            }
            friend ostream &operator<<(ostream &os, DanhSachDoanVien &dsdv) {
                os << "Danh sach doan vien: " << endl;
                for (size_t i = 0; i < dsdv.n; i++) {
                    os << dsdv.ds[i] << endl;
                }
                return os;
            }
            // Sort
            void sort() {
                for (size_t i = 0; i < n - 1; i++) {
                    for (size_t j = i + 1; j < n; j++) {
                        if (ds[i] >= ds[j]) {
                            swap(ds[i], ds[j]);
                        }
                    }
                }
            }
    
};

void ex1_2() {
    DoanVien a("Nguyen Van A", "Ha Noi", 2010);
    DoanVien b;
    cin >> b;
    DoanVien c(b);
    DoanVien d;
    d = a;

    cout << a;
    cout << b;
    cout << c;
    cout << d;
}

void ex1_3_4_5() {
    DanhSachDoanVien a;
    cin >> a;
    cout << a;
    a.sort();
    cout << a;
}

int main() {

    cout << "Chon bai: ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        ex1_2();
        break;
    case 2:
        ex1_3_4_5();
        break;
    default:
        cout << "Bai khong ton tai" << endl;
        break;
    }

    return 0;
}