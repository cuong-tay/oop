
#include <bits/stdc++.h>

using namespace std;

class ps {
    private:
        double tu, mau;
    public:
        ps(){}
        ps(double tu, double mau) {
            this->tu = tu;
            this->mau = mau;
        }
        friend ostream& operator<<(ostream& os, const ps& p) {
            os << p.tu << "/" << p.mau << endl;
            return os;
        }
        friend ps operator+(const ps& a, const ps& b) {
            ps res;
            res.tu = a.tu * b.mau + b.tu * a.mau;
            res.mau = a.mau * b.mau;
            return res;
        }
        friend istream& operator>>(istream& is, ps& p) {
            cout << "Tu so: ";
            is >> p.tu;
            cout << "Mau so: ";
            is >> p.mau;
            return is;
        }
};

int main() {

    ps p1, p2;
    cin >> p1 >> p2;
    cout << p1 << p2 << endl;
    cout << p1 + p2 << endl;

    return 0;
}