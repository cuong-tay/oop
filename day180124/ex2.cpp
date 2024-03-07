// ma tran

#include <bits/stdc++.h>

using namespace std;


class matrix {
    private:
        int n;
        vector<vector<int> >arr;
    public:
       
        void nhap() {
            cout << "Nhap so hang va so cot cua ma tran: "; cin >> n;
            arr = vector<vector<int> >(n, vector<int>(n));
            cout << "\nNhap cac phan tu cua ma tran: ";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cin >> arr[i][j];
                }
            }
        }
        void xuat() {
            cout << "\nMa tran: " << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }
        matrix operator+(matrix a) {
            matrix temp;
            temp.n = n;
            for (int i = 0; i < n; i++) {
                vector<int> tempArr;
                for (int j = 0; j < n; j++) {
                    tempArr.push_back(arr[i][j] + a.arr[i][j]);
                }
                temp.arr.push_back(tempArr);
            }
            return temp;
        }
};

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif


    matrix a, b;
    a.nhap();
    b.nhap();
    a.xuat();
    b.xuat();

    matrix c = a + b;

    return 0;
}
