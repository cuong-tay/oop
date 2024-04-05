
#include <bits/stdc++.h>

using namespace std;

class Person {
    protected:
        string hoTen, ms, gt; // hoTen: họ tên, ms: mã số, gt: giới tính (Nam/Nu)
        int namSinh;

    public:
        // Constructor
        Person();
        Person(string hoTen, string ms, string gt, int namSinh);
        // Operator >>, <<
        friend istream& operator>>(istream& os, Person& person);
        friend ostream& operator<<(ostream& os, const Person& person);
        // Getter and setter
        int getNamSinh() {
            return namSinh;
        }
        string getGioiTinh() {
            return gt;
        }
};
// Constructor
Person::Person() {
}
Person::Person(string hoTen, string ms, string gt, int namSinh) {
    this->hoTen = hoTen;
    this->ms = ms;
    this->gt = gt;
    this->namSinh = namSinh;
}
// Operator >>, <<
istream& operator>>(istream& os, Person& person) {
    cout << "Nhap ho ten: ";
    getline(os, person.hoTen);
    cout << "Nhap ma so: ";
    getline(os, person.ms);
    cout << "Nhap gioi tinh: ";
    getline(os, person.gt);
    cout << "Nhap nam sinh: ";
    os >> person.namSinh;
    os.ignore();
    return os;
}
ostream& operator<<(ostream& os, const Person& person) {
    os << "Ho ten: " << person.hoTen << endl;
    os << "Ma so: " << person.ms << endl;
    os << "Gioi tinh: " << person.gt << endl;
    os << "Nam sinh: " << person.namSinh << endl;
    return os;
}

class Student : public Person {
    protected:
        double tgThamGia;
        int soLanTuongTac;

    public:
        // Constructor
        Student();
        Student(string hoTen, string ms, string gt, int namSinh, double tgThamGia, int soLanTuongTac);
        // Operator >>, <<
        friend istream& operator>>(istream& os, Student& student);
        friend ostream& operator<<(ostream& os, const Student& student);
        // Getter and setter
        int getSoLanTuongTac() {
            return soLanTuongTac;
        }
        int getSogtThamGia() {
            return tgThamGia;
        }
};
// Constructor
Student::Student(): Person() {
}
Student::Student(string hoTen, string ms, string gt, int namSinh, double tgThamGia, int soLanTuongTac)
    : Person(hoTen, ms, gt, namSinh) {
    this->tgThamGia = tgThamGia;
    this->soLanTuongTac = soLanTuongTac;
}
// Operator >>, <<
istream& operator>>(istream& os, Student& student) {
    os >> (Person&)student;
    cout << "Nhap thoi gian tham gia: ";
    os >> student.tgThamGia;
    cout << "Nhap so lan tuong tac: ";
    os >> student.soLanTuongTac;
    os.ignore();
    return os;
}
ostream& operator<<(ostream& os, const Student& student) {
    os << (Person&)student;
    os << "Thoi gian tham gia: " << student.tgThamGia << endl;
    os << "So lan tuong tac: " << student.soLanTuongTac << endl;
    return os;
}

class ListStudent {

    int n;
    vector<Student> list;

    public:
        // Constructor
        ListStudent();
        ListStudent(int n);
        ListStudent(int n, vector<Student> list);
        // Operator >>, <<
        friend istream& operator>>(istream& os, ListStudent& listStudent);
        friend ostream& operator<<(ostream& os, const ListStudent& listStudent);
        // Sinh vien tre tuoi nhat
        Student youngestStudent();
        // Sap xep theo so luong tham du sinh hoat tang dan
        void sortListBySoLanThamGia();
        // Hoc vien nu tuong tac nhieu nhat
        Student mostInteractiveFemaleStudent();
};
// Constructor
ListStudent::ListStudent() {
}
ListStudent::ListStudent(int n) {
    this->n = n;
    this->list = vector<Student>(n);
}
ListStudent::ListStudent(int n, vector<Student> list) {
    this->n = n;
    this->list = list;
}
// Operator >>, <<
istream& operator>>(istream& os, ListStudent& listStudent) {
    cout << "Nhap so luong sinh vien: ";
    os >> listStudent.n;
    os.ignore();
    listStudent.list = vector<Student>(listStudent.n);
    for (int i = 0; i < listStudent.n; i++) {
        cout << "Nhap sinh vien thu " << i + 1 << ":" << endl;
        os >> listStudent.list[i];
    }
    return os;
}
ostream& operator<<(ostream& os, const ListStudent& listStudent) {
    os << "Danh sach sinh vien: " << endl;
    for (int i = 0; i < listStudent.n; i++) {
        os << "Sinh vien thu " << i + 1 << ":" << endl;
        os << listStudent.list[i];
    }
    return os;
}
// Sinh vien tre tuoi nhat
Student ListStudent::youngestStudent() {
    Student youngest = list[0];
    for (int i = 1; i < n; i++) {
        if (list[i].getNamSinh() < youngest.getNamSinh()) {
            youngest = list[i];
        }
    }
    return youngest;
}
// Sap xep theo so luong tham du sinh hoat tang dan
void ListStudent::sortListBySoLanThamGia() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (list[j].getSogtThamGia() < list[j - 1].getSogtThamGia()) {
                swap(list[i], list[j]);
            }
        }
    }
}
// Hoc vien nu tuong tac nhieu nhat
Student ListStudent::mostInteractiveFemaleStudent() {
    Student mostInteractiveFemale = list[0];
    for (int i = 1; i < n; i++) {
        if (list[i].getSoLanTuongTac() > mostInteractiveFemale.getSoLanTuongTac() 
            && (list[i].getGioiTinh() == "Nu" || list[i].getGioiTinh() == "nu")) {
            mostInteractiveFemale = list[i];
        }
    }
    return mostInteractiveFemale;
}
int main() {

    ListStudent listStudent;
    cin >> listStudent;
    cout << listStudent;

    cout << "Danh sach sinh vien sau khi sap xep: " << endl;
    listStudent.sortListBySoLanThamGia();
    cout << listStudent;

    cout << "Sinh vien tre tuoi nhat: " << endl;
    cout << listStudent.youngestStudent();

    cout << "Hoc vien nu tuong tac nhieu nhat: " << endl;
    cout << listStudent.mostInteractiveFemaleStudent();

    return 0;
}