
#include<bits/stdc++.h>

using namespace std;

class nv{
    private:
        string ma, name, phong, ngayhopdong;
        double hsl;
    public:
        nv(){}
        nv(string ma, string name, string phong, string  ngayhopdong, double hsl){
            this->ma = ma;
            this->name = name;
            this->phong = phong; 
            this->ngayhopdong = ngayhopdong;
            this->hsl = hsl;
        }
        string getma(){
            return ma;
        }
        string getname(){
            return name;
        }
        string getphong(){
            return phong;
        }
        string getnhd(){
            return ngayhopdong;
        }
        double gethsl(){
            return hsl;
        }
        void setma(string ma){
            this->ma = ma;
        }
        void setname(string name){
            this->name = name;
        }
        void setphong(string phong){
            this->phong = phong;
        }
        void setnhd(string nhd){
            ngayhopdong = nhd;
        }
        void sethsl(double hsl){
            this->hsl = hsl;
        }
        void show(){
            cout << "Nhan vien: " << name << ", ma: " << ma << "phong: " << phong << ", ngay hop dong: " << ngayhopdong << endl;
        }
        double luong(){
            return hsl*10000000;
        }
        double bhyt(){
            return luong()*5/100;
        }
        double bhxh(){
            return luong()*10/100;
        }
        double bhtn(){
            return luong()*1/100;
        }
        double thuclinh(){
            return luong() - bhxh() - bhyt() - bhtn();
        }
};

class ql{
    private:
        vector<nv> vt;
        bool compareInterval(nv a, nv b){
            return (a.luong() > b.luong());
        }
    public:
        void themnv(nv a){
            vt.push_back(a);
        }
        void tim(string name){
            bool c = false;
            for (int i = 0; i < vt.size(); i++){
                if (vt[i].getname() == name){
                    c = true;
                    cout << "Ton tai nhan vien: " << name << endl;
                    vt[i].show();
                    break;
                }
            }
            if (!c){
                cout << "Khong ton tai nhan vien" << endl;
            }
        }
        void nhanvienluongmin(){
            nv t = vt[0];
            double l = vt[0].luong();
            for (int i = 1; i < vt.size(); i++){
                if (l > vt[i].luong()){
                    t = vt[i];
                    l = vt[i].luong();
                }
            }
            cout << "Nhap vien luong min la: ";
            t.show();
        }
        void shortluong(){
            sort(vt.begin(), vt.end(), compareInterval);
        }
        void show(){
            cout << "Danh sach nhan vien: " << endl;
            for (int i = 0; i < vt.size(); i++){
                vt[i].show();
            }
        }
};

int main(){



    return 0;
}