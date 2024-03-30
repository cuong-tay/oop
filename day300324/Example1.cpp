
#include <bits/stdc++.h>

using namespace std;

const int YEAR_NOW = 2024;

// Định nghĩa lớp Nguoi
class Nguoi {
protected:
    string id; // Số chứng minh
    string name; // Họ tên
    int yearOfBirth; // Năm sinh
public:
    Nguoi();
    Nguoi(string id, string name, int yearOfBirth);
    void nhap(); // Phương thức nhập
    Nguoi& operator>>(istream& is); // Toán tử nhập (để dễ dàng nhập thông tin cho mảng cấp phát động)
    void xuat(); // Phương thức xuất
    Nguoi& operator<<(ostream& os); // Toán tử xuất (để dễ dàng xuất thông tin cho mảng cấp phát động)
    int getAge() { return YEAR_NOW - yearOfBirth; } // Tính tuổi, giả sử năm hiện tại là 2024
};

Nguoi::Nguoi() {
    id = "";
    name = "";
    yearOfBirth = 0;
}

Nguoi::Nguoi(string id, string name, int yearOfBirth) {
    this->id = id;
    this->name = name;
    this->yearOfBirth = yearOfBirth;
}

void Nguoi::nhap() {
    std::cout << "Nhap so chung minh: ";
    getline(std::cin, id); 
    std::cout << "Nhap ho ten: ";
    getline(std::cin, name); 
    std::cout << "Nhap nam sinh: ";
    std::cin >> yearOfBirth;
    std::cin.ignore(); 
};

Nguoi& Nguoi::operator>>(istream& is) {
    std::cout << "Nhap so chung minh: ";
    getline(is, id);
    std::cout << "Nhap ho ten: ";
    getline(is, name);
    std::cout << "Nhap nam sinh: ";
    is >> yearOfBirth;
    is.ignore();
    return *this;
};

void Nguoi::xuat() {
    std::cout << "So chung minh: " << id << ", Ho ten: " << name << ", Nam sinh: " << yearOfBirth << endl;
}

Nguoi& Nguoi::operator<<(ostream& os) {
    os << "So chung minh: " << id << ", Ho ten: " << name << ", Nam sinh: " << yearOfBirth << endl;
    return *this;
}

// Định nghĩa lớp CT kế thừa từ Nguoi
class CT : public Nguoi {
    int sbt; // Số phút thi đấu
    int sptd; // Số bàn thắng
public:
    CT();
    CT(string id, string name, int yearOfBirth, int sbt, int sptd);
    void nhap(); // Phương thức nhập
    CT& operator>>(istream& is); // Toán tử nhập (để dễ dàng nhập thông tin cho mảng cấp phát động)
    void xuat(); // Phương thức xuất
    CT& operator<<(ostream& os); // Toán tử xuất (để dễ dàng xuất thông tin cho mảng cấp phát động)
    int tinhThuong(); // Phương thức tính thưởng
};

CT::CT(): Nguoi() {
    sbt = 0;
    sptd = 0;
}
CT::CT(string id, string name, int yearOfBirth, int sbt, int sptd) : Nguoi(id, name, yearOfBirth) {
    this->sbt = sbt;
    this->sptd = sptd;
}

void CT::nhap() {
    Nguoi::nhap(); // Gọi phương thức nhập của lớp cha
    std::cout << "Nhap so phut thi dau: ";
    cin >> sbt;
    std::cout << "Nhap so ban thang: ";
    cin >> sptd;
    cin.ignore();
}

CT& CT::operator>>(istream& is) {
    Nguoi::operator>>(is); // Gọi phương thức nhập của lớp cha
    std::cout << "Nhap so phut thi dau: ";
    is >> sbt;
    std::cout << "Nhap so ban thang: ";
    is >> sptd;
    is.ignore();
    return *this;
}

void CT::xuat() {
    Nguoi::xuat(); // Gọi phương thức xuất của lớp cha
    std::cout << "So phut thi dau: " << sbt << ", So ban thang: " << sptd << endl;
}

CT& CT::operator<<(ostream& os) {
    Nguoi::operator<<(os); // Gọi phương thức xuất của lớp cha
    os << "So phut thi dau: " << sbt << ", So ban thang: " << sptd << endl;
    return *this;
}

int CT::tinhThuong() {
    if ((3 <= sbt && sbt < 5) || sptd >= 500) {
        return 50000000; // Thưởng 50 triệu
    } else if (sbt >= 5) {
        return 70000000; // Thưởng 70 triệu
    }
    return 0;
}

class ListCT: public CT {
    CT* listCT;
    int n;
public:
    ListCT();
    ListCT(int n); 
    ~ListCT();
    ListCT& operator>>(istream& is);
    ListCT& operator<<(ostream& os);
    void findYoungest();
    void calculateBonus();
};

ListCT::ListCT() {
    n = 0;
    listCT = new CT[100];
}

ListCT::ListCT(int n) {
    this->n = n;
    listCT = new CT[100];
}
ListCT::~ListCT() {
    delete[] listCT;
}
ListCT& ListCT::operator>>(istream& is) {
    std::cout << "Nhap so luong cau thu: ";
    is >> n;
    is.ignore();
    for (int i = 0; i < n; ++i) {
        std::cout << "Nhap thong tin cho cau thu thu " << i + 1 << ":" << endl;
        listCT[i].nhap();
    }
    return *this;
}
ListCT& ListCT::operator<<(ostream& os) {
    for (int i = 0; i < n; ++i) {
        listCT[i].xuat();
        std::cout << "Tien thuong: " << listCT[i].tinhThuong() << " VND" << endl;
    }
    return *this;
}
void ListCT::findYoungest() {
    int tuoiTreNhat = INT_MAX;
    CT cauThuTreNhat;
    for (int i = 0; i < n; ++i) {
        if (listCT[i].getAge() < tuoiTreNhat) {
            tuoiTreNhat = listCT[i].getAge();
            cauThuTreNhat = listCT[i];
        }
    }
    std::cout << "- Cau thu tre nhat la:\n";
    cauThuTreNhat.xuat();
}
void ListCT::calculateBonus() {
    std::cout << "- Danh sach thuong cua cac cau thu:\n";
    for (int i = 0; i < n; ++i) {
        listCT[i].xuat();
        std::cout << "+ Tien thuong: " << listCT[i].tinhThuong() << " VND" << endl;
    }
}

int main() {
    
    ListCT listCT;

    listCT >> cin;
    listCT.findYoungest();
    listCT.calculateBonus();

    return 0;
}
