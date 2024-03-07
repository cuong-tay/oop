
#include <bits/stdc++.h>

using namespace std;

class Diem {
    private: 
        int x, y;
    public:
        int khoangcachdenO(){
            return sqrt(x*x + y*y);
        }
        friend void xuat(Diem a) {
            cout << a.x << " " << a.y << endl;
        }
        friend void nhap(Diem &a) {
            cin >> a.x >> a.y;
        }
        friend int khoangcachhaidiem(Diem a, Diem b) {
            return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
        }
};

int main(){

    Diem m, n;
    nhap(m);
    nhap(n);
    xuat(m);
    xuat(n);
    cout << khoangcachhaidiem(m, n) << endl;
    
    return 0;
}