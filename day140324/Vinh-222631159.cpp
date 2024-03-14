#include<bits/stdc++.h>
#define int long long

using namespace std;

class BienChe{
private:
    int soNgayLam;
    int HSL;
public:
    BienChe() : soNgayLam(0), HSL(0) {}

    BienChe(int soNgayLam, int HSL) : soNgayLam(soNgayLam), HSL(HSL) {}

    virtual void Nhap() {
        cout << "Nhập số ngày làm: ";
        cin >> soNgayLam;
        cout << "Nhập hệ số lương: ";
        cin >> HSL;
    }

    virtual void Xuat() {
        cout << "Số ngày làm: " << soNgayLam << endl;
        cout << "Hệ số lương: " << HSL << endl;
    }

    void setSoNgayLam(int soNgayLam) { this->soNgayLam = soNgayLam; }
    void setHSL(int HSL) { this->HSL = HSL; }
    int getSoNgayLam() const { return soNgayLam; }
    int getHSL() const { return HSL; }
};

class HopDong {
private:
    int NgayCong;
    int TienCong;
public:
    HopDong() : NgayCong(0), TienCong(0) {}

    HopDong(int NgayCong, int TienCong) : NgayCong(NgayCong), TienCong(TienCong) {}

    virtual void Nhap() {
        cout << "Nhập số ngày công: ";
        cin >> NgayCong;
        cout << "Nhập tiền công: ";
        cin >> TienCong;
    }

    virtual void Xuat() {
        cout << "Số ngày công: " << NgayCong << endl;
        cout << "Tiền công: " << TienCong << endl;
    }

    void setNgayCong(int NgayCong) { this->NgayCong = NgayCong; }
    void setTienCong(int TienCong) { this->TienCong = TienCong; }
    int getNgayCong() const { return NgayCong; }
    int getTienCong() const { return TienCong; }
};

class NhanVien : public BienChe {
private:
    string maNV;
    string hoTen;
    int luong;
public:
    NhanVien() : maNV(""), hoTen(""), luong(0) {}

    NhanVien(string maNV, string hoTen) : maNV(maNV), hoTen(hoTen) {}

    void init_Phucap() {
        if(getSoNgayLam() >= 15) luong += 25000;
        else if(getSoNgayLam() >= 10) luong += 18000;
        else if(getSoNgayLam() >= 5) luong += 7000;
        else luong += 1000;
    }

    void Nhap() {
        cout << "Nhập mã nhân viên: ";
        cin >> maNV; // Giả sử mã NV không chứa khoảng trắng
        cin.ignore();
        cout << "Nhập họ tên nhân viên: ";
        getline(cin, hoTen);
        BienChe::Nhap();
        init_Phucap();
        luong += getHSL() * 1800000;
    }

    void Xuat() {
        cout << "Mã nhân viên: " << maNV << endl;
        cout << "Họ tên nhân viên: " << hoTen << endl;
        BienChe::Xuat();
        cout << "Lương: " << luong << endl; // Thêm thông tin về lương khi xuất
    }

    void setMaNV(const string &maNV) { this->maNV = maNV; }
    void setHoTen(const string &hoTen) { this->hoTen = hoTen; }
    string getMaNV() const { return maNV; }
    string getHoTen() const { return hoTen; }
    int getLuong() const { return luong; }
};

class NhanVienBienChe : public NhanVien {
private:
    vector<NhanVien> listNV; // Bỏ biến soLuongNV vì vector có hàm size() để lấy số lượng
public:
    void Nhap() {
        int soLuongNV;
        cout << "Nhập số lượng nhân viên: ";
        cin >> soLuongNV;
        listNV.reserve(soLuongNV); // Tối ưu bộ nhớ cho vector
        for(int i = 0; i < soLuongNV; i++) {
            NhanVien temp;
            temp.Nhap();
            listNV.push_back(temp);
        }
    }

    void Xuat() {
        cout << "Số lượng nhân viên: " << listNV.size() << endl;
        for(auto &nv : listNV) {
            nv.Xuat();
        }
    }

    void TinhLuongTB() {
        double sum = 0;
        for(auto &nv : listNV) {
            sum += nv.getLuong();
        }
        cout << "Lương trung bình: " << sum / listNV.size() << endl;
    }

    NhanVien TimNVCoMa(const string &maNV) {
        for(auto &nv : listNV) {
            if(nv.getMaNV() == maNV) return nv;
        }
        return NhanVien(); // Trả về NV mặc định nếu không tìm thấy
    }

    void XuatNVCoMa(const string &maNV) {
        NhanVien nv = TimNVCoMa(maNV);
        if(nv.getMaNV().empty()) {
            cout << "Không tìm thấy nhân viên có mã: " << maNV << endl;
        } else {
            nv.Xuat();
        }
    }
};

signed main() {
    NhanVienBienChe a;
    a.Nhap();
    a.Xuat();
    a.TinhLuongTB();
    a.XuatNVCoMa("123");
    return 0;
}
