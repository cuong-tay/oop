#include<bits/stdc++.h>

#include"DichVu.cpp"
#include"Phong.cpp" 

using namespace std;

class HopDong {
private:
    int id;
    double tienphong;
    double tiennuoc;
    vector<DichVu> ldv;
    string ngayBatDau;
    string ngayKetThuc;

public:
    HopDong(int id, double tienphong, double tiennuoc, string ngayBatDau, string ngayKetThuc)
        : id(id), tienphong(tienphong), tiennuoc(tiennuoc), ngayBatDau(ngayBatDau), ngayKetThuc(ngayKetThuc) {}

    void setId(int id) {
        this->id = id;
    }

    int getId() {
        return id;
    }

    void setTienPhong(double tienphong) {
        this->tienphong = tienphong;
    }

    double getTienPhong() {
        return tienphong;
    }

    void setDichVu(Phong p){
    	DichVu dv = new dv();
    	dv.setGiuong(p.getLoaiPhong());
    	dv.setChieu(p.getLoaiPhong());
    	ldv.push_back(dv);
	}

    vector<DichVu> getDichVu() {
        return dichvu;
    }

    void setNgayBatDau(string ngayBatDau) {
        this->ngayBatDau = ngayBatDau;
    }

    string getNgayBatDau() {
        return ngayBatDau;
    }

    void setNgayKetThuc(string ngayKetThuc) {
        this->ngayKetThuc = ngayKetThuc;
    }

    string getNgayKetThuc() {
        return ngayKetThuc;
    }

    void nhapThongTin() {
        cout << "Nhap ID: ";
        cin >> id;
        cout << "Nhap tien phong: ";
        cin >> tienphong;
        cout << "Nhap tien nuoc: ";
        cin >> tiennuoc;
        cout << "Nhap dich vu: ";
        cin.ignore();
        getline(cin, dichvu);
        cout << "Nhap ngay bat dau (dd/mm/yyyy): ";
        getline(cin, ngayBatDau);
        cout << "Nhap ngay ket thuc (dd/mm/yyyy): ";
        getline(cin, ngayKetThuc);
    }

    void xuatThongTin() {
        cout << "ID: " << id << endl;
        cout << "Tien phong: " << tienphong << endl;
        cout << "Tien nuoc: " << tiennuoc << endl;
        cout << "Dich vu: " << dichvu << endl;
        cout << "Ngay bat dau: " << ngayBatDau << endl;
        cout << "Ngay ket thuc: " << ngayKetThuc << endl;
    }
    
    //chuyen doi string sang date 
	string xoakt(string s) {
	    string result;
	    for (char c : s) {
	        if (c != '/') {
	            result += c;
	        }
	    }
	    return result;
	} 
	
	int chuyenngay(string date) {
	    int day = stoi(date.substr(0, 2));
	    int month = stoi(date.substr(2, 2));
	    int year = stoi(date.substr(4, 4));
	    return year * 10000 + month * 100 + day;
	}
	
	bool sosanhth(){
		string s = xoakt(this->ngayBatDau);
		string ss = xoakt(this->ngayKetThuc);
		int bd = chuyenngay(s);
		int kt = chuyenngay(ss);
		if (kt - bd <= 152) return false;
		return true;
	}

    
};



