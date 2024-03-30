
#include <bits/stdc++.h>

using namespace std;

// Lớp cơ sở Nhân sự
class NS {
protected:
    string hoTen; // Họ tên
    int tuoi; // Tuổi
public:
    NS();
    NS(string hoTen, int tuoi);
    void nhap(); // Phương thức nhập thông tin nhân sự
    void xuat(); // Phương thức xuất thông tin nhân sự
    int getTuoi(); // Trả về tuổi
};

NS::NS() {
    hoTen = "";
    tuoi = 0;
}

NS::NS(string hoTen, int tuoi) {
    this->hoTen = hoTen;
    this->tuoi = tuoi;
}

void NS::nhap() {
    std::cout << "Nhap ho ten: ";
    getline(std::cin, hoTen);
    std::cout << "Nhap tuoi: ";
    std::cin >> tuoi;
    std::cin.ignore(); // Loại bỏ ký tự xuống dòng thừa sau khi nhập số

}

void NS::xuat() {
    std::cout << "Ho ten: " << hoTen << ", Tuoi: " << tuoi << std::endl;
}

int NS::getTuoi() {
    return tuoi;
}
// Lớp Quản lý kế thừa từ Nhân sự
class QL : public NS {
    char chucVu[4]; // Chức vụ
    int ngayCong; // Số ngày công
public:
    void nhap(); // Phương thức nhập thông tin quản lý
    void xuat(); // Phương thức xuất thông tin quản lý
    float tienLuong(); // Phương thức tính tiền lương
};

void QL::nhap() {
    NS::nhap(); // Gọi phương thức nhập của lớp cơ sở
    std::cout << "Nhap chuc vu (GD, TP hoac NV): ";
    std::cin >> chucVu;
    std::cout << "Nhap so ngay cong: ";
    std::cin >> ngayCong;
    std::cin.ignore(); // Loại bỏ ký tự xuống dòng thừa sau khi nhập số
};

void QL::xuat() {
    NS::xuat(); // Gọi phương thức xuất của lớp cơ sở
    std::cout << "Chuc vu: " << chucVu << ", So ngay cong: " << ngayCong << std::endl;
}

float QL::tienLuong() {
    int tienCong;
    if (strcmp(chucVu, "GD") == 0) { // Nếu là Giám đốc
        tienCong = 50000;
    } else if (strcmp(chucVu, "TP") == 0) {
        tienCong = 40000;
    } else { // Nếu là Nhân viên
        tienCong = 30000;
    }
    return ngayCong * tienCong;
}

class ListQL {
    vector<QL> dsQuanLy;
public:
    ListQL();
    ListQL(int n);
    void nhap();
    void xuat();
    void findYoungest();
    void findHighestSalary();
};

ListQL::ListQL() {
    dsQuanLy = vector<QL>();
}
ListQL::ListQL(int n) {
    dsQuanLy = vector<QL>(n);
}

void ListQL::nhap() {
    int n;
    cout << "Nhap so luong nguoi quan ly: ";
    cin >> n;
    cin.ignore(); // Loại bỏ ký tự xuống dòng thừa

    dsQuanLy = vector<QL>(n);
    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin quan ly thu " << i + 1 << ":\n";
        dsQuanLy[i].nhap();
    }
}

void ListQL::xuat() {
    for (int i = 0; i < dsQuanLy.size(); ++i) {
        cout << "Thong tin quan ly thu " << i + 1 << ":\n";
        dsQuanLy[i].xuat();
    }
}

void ListQL::findYoungest() {
    int minTuoi = dsQuanLy[0].getTuoi(); 
    QL quanLyTreNhat = dsQuanLy[0];
    for (int i = 1; i < dsQuanLy.size(); ++i) {
        if (dsQuanLy[i].getTuoi() < minTuoi) { 
            minTuoi = dsQuanLy[i].getTuoi(); 
            quanLyTreNhat = dsQuanLy[i];
        }
    }
    cout << "\n- Nguoi quan ly tre nhat:\n";
    quanLyTreNhat.xuat();
}

void ListQL::findHighestSalary() {
    float maxLuong = dsQuanLy[0].tienLuong();
    QL quanLyLuongCaoNhat = dsQuanLy[0];
    for (int i = 1; i < dsQuanLy.size(); ++i) {
        if (dsQuanLy[i].tienLuong() > maxLuong) {
            maxLuong = dsQuanLy[i].tienLuong();
            quanLyLuongCaoNhat = dsQuanLy[i];
        }
    }
    cout << "\n- Nguoi quan ly co luong cao nhat:\n";
    quanLyLuongCaoNhat.xuat();
    cout << "Luong: " << quanLyLuongCaoNhat.tienLuong() << endl;
}

int main() {
    
    ListQL listQL;
    listQL.nhap();
    listQL.xuat();
    listQL.findYoungest();
    listQL.findHighestSalary();

    return 0;
}
