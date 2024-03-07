
#include <bits/stdc++.h>

using namespace std;

class GiayDep {
    private:
        string ma, hang, mau;
        double gia, size;
    public:
        GiayDep(){}
        GiayDep(string ma, string hang, string mau, double gia, double size) {
            this->ma = ma;
            this->hang = hang;
            this->mau = mau;
            this->gia = gia;
            this->size = size;
        }
        void nhap() {
            cin.ignore();
            cout << "Nhap ma: "; getline(cin, ma);
            cout << "Nhap hang: "; getline(cin, hang);
            cout << "Nhap mau: "; getline(cin, mau);
            cout << "Nhap gia: "; cin >> gia;
            cout << "Nhap size: "; cin >> size;
        }
        void xuat() {
            cout << "Ma: " << ma << endl;
            cout << "Hang: " << hang << endl;
            cout << "Mau: " << mau << endl;
            cout << "Gia: " << gia << endl;
            cout << "Size: " << size << endl;
        }
        string getHang() {
            return hang;
        }
        string getMau() {
            return mau;
        }
        double getGia() {
            return gia;
        }
        double getSize() {
            return size;
        }
};

class DanhSachGiayDep {
    private:
        GiayDep *ds;
        int n;
    public:
        DanhSachGiayDep() {
            ds = NULL;
            n = 0;
        }
        DanhSachGiayDep(int n) {
            this->n = n;
            ds = new GiayDep[n];
        }
        DanhSachGiayDep(const DanhSachGiayDep &ds) {
            this->n = ds.n;
            this->ds = new GiayDep[n];
            for (int i = 0; i < n; i++) {
                this->ds[i] = ds.ds[i];
            }
        }
        DanhSachGiayDep &operator=(const DanhSachGiayDep &ds) {
            if (this != &ds) {
                this->n = ds.n;
                delete[] this->ds;
                this->ds = new GiayDep[n];
                for (int i = 0; i < n; i++) {
                    this->ds[i] = ds.ds[i];
                }
            }
            return *this;
        }
        ~DanhSachGiayDep() {
            delete[] ds;
        }
        void nhap() {
            cout << "Nhap so luong giay dep: "; cin >> n;
            ds = new GiayDep[n];
            for (int i = 0; i < n; i++) {
                cout << "Nhap giay dep thu " << i + 1 << endl;
                ds[i].nhap();
            }
        }
        void xuat() {
            cout << "Danh sach giay dep: " << endl;
            for (int i = 0; i < n; i++) {
                cout << "Giay dep thu " << i + 1 << endl;
                ds[i].xuat();
            }
        }
        void find(string hang, string mau, double size, double gia) {
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (ds[i].getHang() == hang 
                    && ds[i].getMau() == mau 
                    && ds[i].getSize() == size 
                    && ds[i].getGia() <= gia) 
                {
                    ds[i].xuat();
                    found = true;
                }
            }
            if (!found) {
                cout << "Khong tim thay giay dep phu hop" << endl;
            }
        }
};

int main() {

    DanhSachGiayDep ds;
    int n;
    bool v = true;
    string hang, mau;
    double size, gia;
    while (v) {
        cout << "Nhap 1 de xem danh sach giay dep" << endl;
        cout << "Nhap 2 de tim kiem giay dep" << endl;
        cout << "Nhap 3 de nhap danh sach giay dep" << endl;
        cout << "Nhap 4 de thoat" << endl;
        cin >> n;
        
        switch (n) {
            case 1:
                ds.xuat();
                break;
            case 2:
                cin.ignore();
                cout << "Nhap hang: "; getline(cin, hang);
                cout << "Nhap mau: "; getline(cin, mau);
                cout << "Nhap size: "; cin >> size;
                cout << "Nhap gia: "; cin >> gia;
                ds.find(hang, mau, size, gia);
                break;
            case 3:
                ds.nhap();
                break;
            case 4:
                v = false;
                break;
            default:
                cout << "Nhap sai, vui long nhap lai" << endl;
                break;
        }
    }

    return 0;
}