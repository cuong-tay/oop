
#include <bits/stdc++.h>

using namespace std;

class Example {
    private:
        int *data;
        size_t size; 
    public:
        // Constructor - Hàm tạo
        Example() { // Hàm tạo mặc định
            this->size = 0;
            this->data = NULL;
            cout << "Constructor called" << endl;
        }
        Example(size_t s)  { // Hàm tạo có tham số
            this->size = s;
            data = new int[s];
            cout << "Constructor called" << endl;
        }
        // Destructor - Hàm hủy
        ~Example() {
            delete[] data;
            cout << "Destructor called" << endl;
        }
        // Copy Constructor - Hàm sao chép
        Example(Example &e) {
            this->size = e.size;
            this->data = new int[e.size];
            for (size_t i = 0; i < e.size; i++) {
                this->data[i] = e.data[i];
            }
            cout << "Copy Constructor called" << endl;
        }
        // Copy Assignment Operator - Hàm gán sao chép
        Example& operator=(Example &e) {
            if (this != &e) {
                delete[] data;
                this->size = e.size;
                this->data = new int[e.size];
                for (size_t i = 0; i < e.size; i++) {
                    this->data[i] = e.data[i];
                }
            }
            cout << "Copy Assignment Operator called" << endl;
            return *this;
        }
        
        // Show data
        void printData() {
            for (size_t i = 0; i < size; i++) {
                cout << data[i] << " ";
            }
            cout << endl;
        }
        void setData(size_t index, int value) {
            if (index >= 0 && index < size) {
                data[index] = value;
            }
        }
};

int main() {

    Example e1(5);

    for (int i = 0; i < 5; i++) {
        e1.setData(i, i);
    }

    Example e2 = e1;
    Example e3(10);
    e3 = e1;

    cout << "e1: ";
    e1.printData();
    cout << "e2: ";
    e2.printData();
    cout << "e3: ";
    e3.printData();

    return 0;
}