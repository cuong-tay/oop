
#include <bits/stdc++.h>

using namespace std;

class DayNguyen {
    private:
        int n;
        int* arr;
    public: 
        DayNguyen() {
            n = 0;
            arr = NULL;
        }
        DayNguyen(int n) {
            this->n = n;
            arr = new int[n];
        }   
        ~DayNguyen() {
            delete[] arr;
        }
        DayNguyen(const DayNguyen& a) {
            n = a.n;
            arr = new int[n];
            for (int i = 0; i < n; ++i) {
                arr[i] = a.arr[i];
            }
        }
        DayNguyen& operator=(const DayNguyen& a) {
            if (this == &a) return *this;
            n = a.n;
            delete[] arr;
            arr = new int[n];
            for (int i = 0; i < n; ++i) {
                arr[i] = a.arr[i];
            }
            return *this;
        }
        void nhap() {
            cout << "Nhap cac phan tu cua day: " << endl;
            for (int i = 0; i < n; ++i) {
                cin >> arr[i];
            }
        }
        friend ostream& operator<<(ostream& os, const DayNguyen& a) {
            os << "Cac phan tu cua day: " << endl;
            for (int i = 0; i < a.n; ++i) {
                os << a.arr[i] << " ";
            }
            os << endl;
        }
        void solve() {
            int c = 0;
            vector<int> res;
            for (int i = 1; i < n - 1; i++) {
                if (arr[i] - arr[i - 1] == arr[i + 1] - arr[i]) {
                    c++;
                    res.push_back(i);
                }
            }
            if (c == 0) {
                cout << "Khong co cap so cong nao trong day" << endl;
            } else {
                cout << "So luong cap so cong trong day: " << c << endl;
                cout << "Cac cap so cong trong day: " << endl;
                for (int i = 0; i < res.size(); ++i) {
                    cout << arr[res[i] - 1] << " " << arr[res[i]] << " " << arr[res[i] + 1] << endl;
                }
                cout << endl;
            }
        }
};

int main() {

    int n; 
    cout << "Nhap so phan tu cua day: ";
    cin >> n;
    DayNguyen a(n);
    a.nhap();
    cout << a;
    a.solve();

    return 0;
}