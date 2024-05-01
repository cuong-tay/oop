#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Nguoi {
private:
    int id;
    string name;
    string sdt;
    string email;

public:
	Nguoi(){
	}
    // Constructor
    Nguoi(int id, string name, string sdt, string email) {
       this-> id = id;
       this-> name = name;
        this->sdt = sdt;
        this->email = email;
    }

    //getter va setter
    int getID() {
        return id;
    }

    void setID(int _id) {
        id = _id;
    }

    string getName() {
        return name;
    }

    void setName(string _name) {
        name = _name;
    }

    string getSDT() {
        return sdt;
    }

    void setSDT(string _sdt) {
        sdt = _sdt;
    }

    string getEmail() {
        return email;
    }

    void setEmail(string _email) {
        this->email = _email;
    }
    //input
    friend istream& operator>>(istream& is, Nguoi& ng) {
        cout << "Nhap ID: ";
        is >> ng.id;
        cout << "Nhap ten: ";
        is.ignore();
        getline(is, ng.name);
        cout << "Nhap SDT: ";
        is >> ng.sdt;
        cout << "Nhap Email: ";
        is >> ng.email;
        return is;
    }
    //output
    friend ostream& operator<<(ostream& os,  Nguoi ng) {
        os << "ID: " << ng.id << " Name: " << ng.name << " SDT: " << ng.sdt << " Email: " << ng.email;
        return os;
    }

};

//class sinh vien
class SinhVien :public Nguoi{
	private:
		int sophong;
	public:
	   //constructor
	   SinhVien(){
	   }	
	   SinhVien(int id, string name, string sdt, string email, int sophong):Nguoi(id, name, sdt, email){
	   	this->sophong=sophong;
	   }
	   //getter setter
	   int getSoPhong(){ return sophong;
	   }
	   void setSoPhong(int so){
	   	this->sophong=so;
	   }
	   
	   // bool kiem tra tien nop
	   bool checkTienNop(){	
	   }
          //input
        friend istream& operator>>(istream& is, Nguoi& ng) {
        cout << "Nhap ID: ";
        is >> ng.id;
        cout << "Nhap ten: ";
        is.ignore();
        getline(is, ng.name);
        cout << "Nhap SDT: ";
        is >> ng.sdt;
        cout << "Nhap Email: ";
        is >> ng.email;
        return is;
             }
          //output
         friend ostream& operator<<(ostream& os,  Nguoi ng) {
        os << "ID: " << ng.id << " Name: " << ng.name << " SDT: " << ng.sdt << " Email: " << ng.email;
        return os;
           }
	
};

//class Bao ve
class BaoVe :public Nguoi{
	private:
		string chucvu;
		int tang;
		int id_toanha;
	public:
	  	 // Constructor
	  	BaoVe(){}
        
		BaoVe(int id, string name, string sdt, string email, string chucvu, int tang, int id_toanha) : Nguoi(id, name, sdt, email) {
                this-> chucvu = chucvu;
                this->  tang = tang;
                this-> id_toanha = id_toanha;
               }
        
              //getter va setter
              string getChucVu(){ return chucvu;
		}
		int getTang(){ return tang;
		}
		int getID_toanha(){ return this->id_toanha;
		}
		void setChucVu(string cv){
			this->chucvu=cv;
		} 
		void setTang(int tang){
			this->tang=tang;
		}
		void setID_Toanha(int id){
			this->id_toanha=id;
		}
         	//input
		friend istream& operator>>(istream& is, BaoVe& bv) {
			 is.ignore();
                  is >> static_cast<Nguoi&>(bv); // Input Nguoi part
                  cout << "Nhap chuc vu: ";
                   getline(is, bv.chucvu);
                     is.ignore();
                 cout << "Nhap tang: ";
                  is >> bv.tang;
                 cout << "Nhap ID toa nha: ";
                    is >> bv.id_toanha;
                      return is;
                    }
		//output
		friend ostream& operator<<(ostream& os, const BaoVe& bv) {
                 os << static_cast<const Nguoi&>(bv) << " Chuc Vu: " << bv.chucvu << " ID Toa nha: " << bv.id_toanha<< " Tang: " << bv.tang<<endl;
                 return os;
		}
		
    
};



