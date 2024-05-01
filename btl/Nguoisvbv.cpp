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
        id = id;
        name = name;
        sdt = sdt;
        email = email;
    }

    
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
        chucvu = chucvu;
        tang = tang;
        id_toanha = id_toanha;
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
		
    
};



