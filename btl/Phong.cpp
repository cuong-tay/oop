#include <bits/stdc++.h>

#include "Nguoisvbv.cpp"

using namespace std;


class Phong {
private:
  int soPhong;
	int soToa;
	int loaiPhong;
	int soDien;
	int soNuoc;
	list<SinhVien> dsSV;
	//HopDong a;

public:
  Phong();
  Phong(int soPhong, int soToa, int loaiPhong, int soDien, int soNuoc){
		this->soPhong = soPhong;
		this->soToa = soToa;
		this->loaiPhong = loaiPhong;
		this->soDien = soDien;
	//	this->a = a;
	}
  int getSoPhong(){
  	return soPhong;
  }

  void themSinhVien(SinhVien sinhVien) {
    if (dsSV.size() < loaiPhong) { 
      dsSV.push_back(sinhVien);
      cout << "Sinh vien " << sinhVien.getName() << " da duoc them vao phong " << soPhong << "." << endl;
    } else {
      cout << "Phong " << soPhong << " da day. Khong them duoc sinh vien." << endl;
    }
  }

  void xoaSinhVien(int ID) {
  for (list<SinhVien>::iterator it = dsSV.begin(); it != dsSV.end(); ++it) {
    if (it->getID() == ID) {
      dsSV.erase(it);
      cout << "Sinh vien ID " << ID << " da duoc xoa khoi phong " << soPhong << "." << endl;
      return;
    }
  }

  // If no match is found, inform the user
  cout << "Khong tim thay sinh vien ID " << ID << " trong phong " << soPhong << "." << endl;
}

  void danSachSinhVien() {
    if (dsSV.empty()) {
      cout << "Phong " << soPhong << " hien dang trong." << endl;
    } else {
      cout << "Danh sach sinh vien phong " << soPhong << ":" << endl;
      for (SinhVien sinhVien : dsSV) {
        cout << "    - " << sinhVien.getID() << " - " << sinhVien.getName() << " (" << sinhVien.getSDT() << ")" << endl;
      }
    }
  }

  int getSoLuongSinhVien() const {
    return dsSV.size();
  }


  void hienThiThongTin() {
    cout << "Thong tin phong " << soPhong << ":" << endl;
    cout << "  So toa: " << soToa << endl;
    cout << "  Loai phong: " << loaiPhong << endl;
    cout << "  So o dien: " << soDien << endl;
    cout << "  So voi nuoc: " << soNuoc << endl;
    cout << "  Danh sach sinh vien:" << endl;
    for (SinhVien sinhVien : dsSV) {
      cout << "    - " << sinhVien.getID() << " - " << sinhVien.getName() << " (" << sinhVien.getSDT() << ")" << endl;
    }
  }
};


class ToaNha  {
private:
  int soTang;
  list<Phong> dsPhong;
  string tenToa;

public:
  ToaNha(int soTang, string tenToa) {
    this->soTang = soTang;
    this->tenToa = tenToa;
  }

  void themPhong(Phong phong) {
    dsPhong.push_back(phong);
    cout << "Phong " << phong.getSoPhong() << " da duoc them vao toa nha " << tenToa << "." << endl;
  }

  void xoaPhong(int soPhong) {
    for (list<Phong>::iterator it = dsPhong.begin(); it != dsPhong.end(); ++it) {
      if (it->getSoPhong() == soPhong) {
        dsPhong.erase(it);
        cout << "Phong " << soPhong << " da duoc xoa khoi toa nha " << tenToa << "." << endl;
        return;
      }
    }
    cout << "Khong tim thay phong " << soPhong << " trong toa nha " << tenToa << "." << endl;
  }

  void danSachPhong() {
    if (dsPhong.empty()) {
      cout << "Toa nha " << tenToa << " hien dang trong." << endl;
    } else {
      cout << "Danh sach phong toa nha " << tenToa << ":" << endl;
      for (Phong phong : dsPhong) {
        cout << "  - Phong " << phong.getSoPhong() << ":" << endl;
        phong.hienThiThongTin(); // Hien thi thong tin chi tiet cua phong
      }
    }
  }

  int getSoLuongPhong() const {
    return dsPhong.size();
  }

  string getTenToa() const {
    return tenToa;
  }
};
