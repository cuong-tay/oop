
#include <bits/stdc++.h>

using namespace std;

class dathuc { // ax^n + bx^n-1 + .... + cx^2 + dx;
    private:
        int bac;
        vector<int> arrHs;
    public:
        void nhap() {
            cout << "Nhap bac cua da thuc: "; cin >> bac;
            cout << "Nhap cac he so cua da thuc: ";
            for (int i = 0; i <= bac; i++){
                int temp; cin >> temp;
                arrHs.push_back(temp);
            }
        }

        void xuat() {
            cout << "Da thuc: ";
            for (int i = 0; i <= bac; i++){
                cout << arrHs[i] << "x^" << i << " + ";
            }
            cout << arrHs[bac] << endl;
        }

        dathuc operator+(dathuc a) {
            dathuc temp;
            temp.bac = max(bac, a.bac);
            for (int i = 0; i <= temp.bac; i++) {
                if (i <= bac && i <= a.bac) {
                    temp.arrHs.push_back(arrHs[i] + a.arrHs[i]);
                }
                else if (i <= bac) {
                    temp.arrHs.push_back(arrHs[i]);
                }
                else {
                    temp.arrHs.push_back(a.arrHs[i]);
                }
            }
            return temp;
        }
        dathuc operator-(dathuc a) {
            dathuc temp;
            temp.bac = max(bac, a.bac);
            for (int i = 0; i <= temp.bac; i++) {
                if (i <= bac && i <= a.bac) {
                    temp.arrHs.push_back(arrHs[i] - a.arrHs[i]);
                }
                else if (i <= bac) {
                    temp.arrHs.push_back(arrHs[i]);
                }
                else {
                    temp.arrHs.push_back(-a.arrHs[i]);
                }
            }
            return temp;
        }

        int calculator(int x) {
            int res = 0;
            for (int i = 0; i <= bac; i++) {
                res += arrHs[i] * pow(x, i);
            }
            return res;
        }

        int daoham(int x) {
            int res = 0;
            for (int i = 1; i <= bac; i++) {
                res += arrHs[i] * i * pow(x, i - 1);
            }
            return res;
        }
};  

int solve(dathuc a, dathuc b, int x1, int x2) {

    int t = a.calculator(x1) + a.daoham(x1) 
            + b.calculator(x2) + b.daoham(x2);
    try{
        return 1/t;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }  
}

int main(){

    dathuc a, b;
    a.nhap();
    b.nhap();
    int d1, d2;
    cout << "Nhap gia tri x1: "; cin >> d1;
    cout << "Nhap gia tri x2: "; cin >> d2;

    cout << "Ket qua: " << solve(a, b, d1, d2) << endl;

    return 0;
}