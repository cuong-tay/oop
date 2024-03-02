#include <iostream>
using namespace std;

class DayNguyen {
private:
    int n;
    int* arr;

    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }

public:
    DayNguyen() {
        n = 0;
        arr = NULL;
    }

    DayNguyen(int n) {
        this->n = n;
        arr = new int[n];
    } 

    /* DayNguyen(const DayNguyen& other){
        this->n = other.n;
        arr = other.arr;
        for (int i = 0; i < n; ++i) {
            arr[i] = other.arr[i];
        }
    } */

    /* DayNguyen& operator=(const DayNguyen& other) {
        if (this != &other) {
            delete[] arr;
            n = other.n;
            arr = new int[n];
            for (int i = 0; i < n; ++i) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    } */

    ~DayNguyen() {
        delete[] arr;
        // cout << "Xoa day nguyen" << endl;
    }

    void nhap() {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    friend void xuat(const DayNguyen& d) {
        cout << "Day Nguyen: ";
        for (int i = 0; i < d.n; i++) {
            cout << d.arr[i] << " ";
        }
        cout << endl;
    }

    int operator()() {
        int count = 0;
        cout << "Cac so nguyen to trong day: ";
        for (int i = 0; i < n; ++i) {
            if (isPrime(arr[i])) {
                cout << arr[i] << " ";
                count++;
            }
        }
        cout << endl;
        return count;
    }
};

int main() {
    int m;
    cout << "Nhap kich thuoc mang X: " << endl; cin >> m;
    DayNguyen X(m);
    cout << "Nhap gia tri cho mang: " << endl;
    X.nhap();
    xuat(X);

    int n;
    cout << "Nhap kich thuoc mang Y: " << endl; cin >> n;
    DayNguyen Y(n);
    cout << "Nhap gia tri cho mang: " << endl;
    Y.nhap();
    xuat(Y);

    if (X() > Y()) {
        cout << "Day X co nhieu so nguyen to hon day Y" << endl;
    } else if (X() > Y()) {
        cout << "Day Y co nhieu so nguyen to hon day X" << endl;
    }
    else {
        cout << "So luong so nguyen to cua 2 day bang nhau" << endl;
    }

    return 0;
}
