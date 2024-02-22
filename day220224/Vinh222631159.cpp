
#include <bits/stdc++.h>

using namespace std;

class KH {
    private: 
        string ma, ten, dc, sdt;
        int ngaygui, thoigiangui;
        double sotiengui;
    public:
        KH(){};
        KH(string ma, string ten, string dc, string sdt, int ngaygui, double sotiengui, int thoigiangui){
            this->ma = ma;
            this->ten = ten;
            this->dc = dc;
            this->sdt = sdt;
            this->ngaygui = ngaygui;
            this->sotiengui = sotiengui;
            this->thoigiangui = thoigiangui;
        };
        void setMa(string ma){
            this->ma = ma;
        };
        void setTen(string ten){
            this->ten = ten;
        };
        void setDc(string dc){
            this->dc = dc;
        };
        void setSdt(string sdt){
            this->sdt = sdt;
        };
        void setNgaygui(int ngaygui){
            this->ngaygui = ngaygui;
        };
        void setSotiengui(double sotiengui){
            this->sotiengui = sotiengui;
        };
        void setThoigiangui(int thoigiangui){
            this->thoigiangui = thoigiangui;
        };
        string getMa(){
            return this->ma;
        };
        string getTen(){
            return this->ten;
        };
        string getDc(){
            return this->dc;
        };
        string getSdt(){
            return this->sdt;
        };
        int getNgaygui(){
            return this->ngaygui;
        };
        double getSotiengui(){
            return this->sotiengui;
        };
        int getThoigiangui(){
            return this->thoigiangui;
        };
        void nhap(){
            cout << "Vui long nhap ma: ";
            cin >> this->ma;
            cout << "Vui long nhap ten: ";
            cin.ignore();
            getline(cin, this->ten);
            cout << "Vui long nhap dia chi: ";
            getline(cin, this->dc);
            cout << "Vui long nhap so dien thoai: ";
            cin >> this->sdt;
            cout << "Vui long nhap ngay gui: ";
            cin >> this->ngaygui;
            cout << "Vui long nhap so tien gui: ";
            cin >> this->sotiengui;
            cout << "Vui long nhap thoi gian gui: ";
            cin >> this->thoigiangui;
        }
        void xuat(){
            cout << "Ma: " << this->ma << endl;
            cout << "Ten: " << this->ten << endl;
            cout << "Dia chi: " << this->dc << endl;
            cout << "So dien thoai: " << this->sdt << endl;
            cout << "Ngay gui: " << this->ngaygui << endl;
            cout << "So tien gui: " << this->sotiengui << endl;
            cout << "Thoi gian gui: " << this->thoigiangui << endl;
        };
        friend double tienlai(KH obj,int tgg) {
            double tl = 0;
            switch (tgg) {
            case 1:
                tl = 0.03;
                break;
            case 2:
                tl = 0.035;
                break;
            case 3:
                tl = 0.04;
                break;
            case 4:
                tl = 0.05;
                break;
            case 5:
                tl = 0.06;
                break;
            case 6:
                tl = 0.065;
                break;
            case 7:
                tl = 0.07;
                break;
            case 8:
                tl = 0.073;
                break;
            case 9:
                tl = 0.074;
                break;
            case 10:
                tl = 0.075;
                break;
            case 11:
                tl = 0.076;
                break;
            case 12:
                tl = 0.08;
                break;
            }
            return tl*(obj.sotiengui)*(obj.thoigiangui);
        }
};

class Application {
    private:
        vector<KH> list;
        int soKH;
    public:
        Application(){};
        Application(vector<KH> list, int soKH){
            this->list = list;
            this->soKH = soKH;
        };
        Application(int soKH){
            this->soKH = soKH;
        };
        void nhap(){
            cout << "Vui long nhap thong tin cua " << soKH << " khach hang." << endl;
            for (int i = 0; i < soKH; i++) {
                KH t = KH();
                t.nhap();
                list.push_back(t);
            }
        }
        void xuat(){
            for (int i = 0; i < soKH; i++) {
                list[i].xuat();
            }
        }
        friend void find(Application obj, string sdt) {
            bool check = false;
            for (int i = 0; i < obj.soKH; i++) {
                if (obj.list[i].getSdt() == sdt) {
                    cout << "Tim thay khach hang co sdt: " << sdt << endl;
                    obj.list[i].xuat();
                    check = true;
                    break;
                }
            }
            if (!check) {
                cout << "Khong tim thay khach hang co sdt " << sdt << endl; 
            }
        }
        friend vector<KH> KhTT(Application obj) {
            vector<KH> res;
            return res;
        }
};

int main() {

    Application app = Application(1);
    app.nhap();
    app.xuat();
    find(app, "0123");

    return 0;
}