
#include<bits/stdc++.h>

using namespace std;

class Laptop {
    string model, hangsx;
    double gia;
    int thoiGianBaoHanh;

    public:
        Laptop() {
            model = "";
            hangsx = "";
            gia = 0;
            thoiGianBaoHanh = 0;
        }
        Laptop(string model, string hangsx, double gia, int thoiGianBaoHanh) {
            this->model = model;
            this->hangsx = hangsx;
            this->gia = gia;
            this->thoiGianBaoHanh = thoiGianBaoHanh;
        }
        double getGia() {
            return gia;
        }
        friend void nhap(Laptop &l) {
            cout << "Nhap model: ";
            cin >> l.model;
            cout << "Nhap hang san xuat: ";
            cin >> l.hangsx;
            cout << "Nhap gia: ";
            cin >> l.gia;
            cout << "Nhap thoi gian bao hanh: ";
            cin >> l.thoiGianBaoHanh;
        }
        friend void xuat(const Laptop &l) {
            cout << "Model: " << l.model << endl;
            cout << "Hang san xuat: " << l.hangsx << endl;
            cout << "Gia: " << l.gia << endl;
            cout << "Thoi gian bao hanh: " << l.thoiGianBaoHanh << endl;
        }
};

class ListLaptop {
    int n;
    Laptop* arr;

    public:
        ListLaptop() {
            n = 0;
            arr = NULL;
        }
        ListLaptop(int n) {
            this->n = n;
            arr = new Laptop[n];
        }
        ListLaptop(const ListLaptop& other) {
            this->n = other.n;
            arr = new Laptop[n];
            for (int i = 0; i < n; ++i) {
                arr[i] = other.arr[i];
            }
        }
        ListLaptop& operator=(const ListLaptop& other) {
            if (this != &other) {
                delete[] arr;
                n = other.n;
                arr = new Laptop[n];
                for (int i = 0; i < n; ++i) {
                    arr[i] = other.arr[i];
                }
            }
            return *this;
        }
        ~ListLaptop() {
            delete[] arr;
        }
        friend void nhap(ListLaptop &l) {
            int n;
            cout << "Nhap so luong laptop: ";
            cin >> n; 
            l = ListLaptop(n);
            for (int i = 0; i < l.n; ++i) {
                cout << "Nhap thong tin laptop thu " << i + 1 << endl;
                nhap((l.arr)[i]);
            }
        }
        friend void xuat(ListLaptop &l) {
            cout << "-----Danh sach " << l.n << " laptop: " << endl;
            sortList(l);
            for (int i = 0; i < l.n; ++i) {
                cout << "Thong tin laptop thu " << i + 1 << endl;
                xuat((l.arr)[i]);
            }
        }
        friend void sortList(ListLaptop &l) {
            for (int i = 0; i < l.n - 1; ++i) {
                for (int j = i + 1; j < l.n; ++j) {
                    if ((l.arr)[i].getGia() > (l.arr)[j].getGia()) {
                        swap((l.arr)[i], (l.arr)[j]);
                    }
                }
            }
        }
        friend void find(const ListLaptop l, double x) {
            for (int i = 0; i < l.n; i++) {
                if ((l.arr)[i].getGia() <= x) {
                    xuat((l.arr)[i]);    
                }
            }
        }
};

int main() {

    ListLaptop l;
    nhap(l);

    xuat(l);
    
    return 0;
}