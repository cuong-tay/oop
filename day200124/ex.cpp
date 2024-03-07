#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int age;
    float GPA;

public:
    // Hàm tạo (constructor)
    Student(std::string n, int a, float g) : name(n), age(a), GPA(g) {}

    // Khai báo hàm bạn
    friend void printStudentInfo(const Student& student);

    // Hàm getter để lấy tên sinh viên
    std::string getName() const {
        return name;
    }

    // Hàm in thông tin sinh viên
    void printInfo() const {
        std::cout << "Name: " << name << "\nAge: " << age << "\nGPA: " << GPA << std::endl;
    }
};

// Hàm bạn để in thông tin sinh viên từ bên ngoài lớp
void printStudentInfo(const Student& student) {
    std::cout << "Friend Function:\n";
    std::cout << "Name: " << student.name << "\nAge: " << student.age << "\nGPA: " << student.GPA << std::endl;
}

int main() {
    // Sử dụng lớp Student để tạo đối tượng sinh viên
    Student student1("John Doe", 20, 3.5);

    // Gọi hàm in thông tin từ đối tượng sinh viên
    std::cout << "Student Information:\n";
    student1.printInfo();

    // Gọi hàm bạn để in thông tin sinh viên từ bên ngoài lớp
    printStudentInfo(student1);

    return 0;
}
