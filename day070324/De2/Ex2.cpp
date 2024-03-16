
#include <bits/stdc++.h>

using namespace std;

class thising {
    private:
        string sbd, hoten;
        double diem;
        int khuvuc;
    public: 
        thising(){}
        thising(string sbd, string hoten, double diem, int khuvuc) {
            this->sbd = sbd;
            this->hoten = hoten;
            this->diem = diem;
            this->khuvuc = khuvuc;
        }
        friend istream& operator>>(istream& is, thising& t) {
            cout << "Nhap so bao danh: ";
            is.ignore();
            getline(is, t.sbd);
            cout << "Nhap ho ten: ";
            getline(is, t.hoten);
            cout << "Nhap diem: ";
            is >> t.diem;
            cout << "Nhap khu vuc: ";
            is >> t.khuvuc;
            return is;
        }
        friend ostream& operator<<(ostream& os, const thising& t) {
            os << "So bao danh: " << t.sbd << endl;
            os << "Ho ten: " << t.hoten << endl;
            os << "Diem: " << t.diem << endl;
            os << "Khu vuc: " << t.khuvuc << endl;
            return os;
        }
        double getDiem() {
            return diem;
        }
        int getKhuvuc() {
            return khuvuc;
        }
};

class listthisinh {
    private:
        thising *list;
        int n;
    public:
        listthisinh(){}
        listthisinh(int n) {
            this->n = n;
            list = new thising[n];
        }
        ~listthisinh() {
            delete[] list;
        }
        listthisinh(const listthisinh& l) {
            this->n = l.n;
            list = new thising[n];
            for (int i = 0; i < n; i++) {
                list[i] = l.list[i];
            }
        }
        listthisinh& operator=(const listthisinh& l) {
            if (this == &l) {
                return *this;
            }
            this->n = l.n;
            delete[] list;
            list = new thising[n];
            for (int i = 0; i < n; i++) {
                list[i] = l.list[i];
            }
            return *this;
        }
        friend istream& operator>>(istream& is, listthisinh& l) {
            for (int i = 0; i < l.n; i++) {
                cout << "Nhap thong tin thi sinh thu " << i+1 << ": " << endl;
                is >> l.list[i];
            }
            return is;
        }
        friend ostream& operator<<(ostream& os, const listthisinh& l) {
            for (int i = 0; i < l.n; i++) {
                os << "Thi sinh thu " << i+1 << ": " << endl;
                os << l.list[i];
            }
            return os;
        }
        void xuatdiemtrungbinhtheokhuvuc() {
            vector<double> diem(3, 0);
            vector<int> count(3, 0);
            for (int i = 0; i < n; i++) {
                switch (list[i].getKhuvuc()) {
                    case 1:
                        diem[0] += list[i].getDiem();
                        count[0]++;
                        break;
                    case 2:
                        diem[1] += list[i].getDiem();
                        count[1]++;
                        break;
                    case 3:
                        diem[2] += list[i].getDiem();
                        count[2]++;
                        break;
                    default:
                        break;
                }
            }
            cout << "Diem trung binh theo khu vuc: " << endl;
            for (int i = 0; i < 3; i++) {
                if (count[i] == 0) {
                    cout << "Khu vuc " << i+1 << ": " << "Khong co thi sinh" << endl;
                } else {
                    cout << "Khu vuc " << i+1 << ": " << diem[i]/count[i] << endl;
                }
            }
        }
};

int main() {

    listthisinh l(3);
    cin >> l;
    cout << l;
    l.xuatdiemtrungbinhtheokhuvuc();

    return 0;
}


