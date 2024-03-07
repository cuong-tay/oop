#include<bits/stdc++.h>

using namespace std;

class motorbike {
    private:
        string hangxe, tenxe, sokhung;
        int dungtich;
        double giaxe;
    public:
        // Constructor - Hàm tạo
        motorbike() {
            hangxe = "";
            tenxe = "";
            sokhung = "";
            dungtich = 0;
            giaxe = 0;
        }
        motorbike(string hangxe, string tenxe, string sokhung, int dungtich, double giaxe) {
            this->hangxe = hangxe;
            this->tenxe = tenxe;
            this->sokhung = sokhung;
            this->dungtich = dungtich;
            this->giaxe = giaxe;
        }
        void showData() {
            cout << "Hang xe: " << hangxe << endl;
            cout << "Ten xe: " << tenxe << endl;
            cout << "So khung: " << sokhung << endl;
            cout << "Dung tich: " << dungtich << endl;
            cout << "Gia xe: " << giaxe << endl << endl;
        }
        string getHangxe() {
            return hangxe;
        }
        double getGiaxe() {
            return giaxe;
        }
        int getDungtich() {
            return dungtich;
        }
        string getTenxe() {
            return tenxe;
        }
};

class ListMotorBike {
    private:
        motorbike *list;
        int size;
    public:
        // Constructor - Hàm tạo
        ListMotorBike() {
            size = 0;
            list = NULL;
        }
        ListMotorBike(int s) {
            size = s;
            list = new motorbike[s];
        }
        // Destructor - Hàm hủy
        ~ListMotorBike() {
            delete[] list;
        }
        // Copy Constructor - Hàm sao chép
        ListMotorBike(const ListMotorBike &l) {
            this->size = l.size;
            this->list = new motorbike[l.size];
            for (int i = 0; i < l.size; i++) {
                this->list[i] = l.list[i];
            }
        }
        // Copy Assignment Operator - Hàm gán sao chép
        ListMotorBike& operator=(const ListMotorBike &l) {
            if (this != &l) {
                delete[] list;
                this->size = l.size;
                this->list = new motorbike[l.size];
                for (int i = 0; i < l.size; i++) {
                    this->list[i] = l.list[i];
                }
            }
            return *this;
        }
        void showData() {
            for (int i = 0; i < size; i++) {
                cout << "Motorbike " << i + 1 << endl;
                (list[i]).showData(); 
            }
        }
        motorbike* getList() {
            return list;
        }
        void showByDungTich() {
            vector<int> dungtich;
            vector<double> tonggia; 
            for (int i = 0; i < size; i++) {
                int current_dungtich = list[i].getDungtich();
                auto it = find(dungtich.begin(), dungtich.end(), current_dungtich);
                // Nếu không tìm thấy thêm vào danh sách dungtich
                if (it == dungtich.end()) {
                    dungtich.push_back((list[i]).getDungtich());
                    tonggia.push_back((list[i]).getGiaxe());
                } else { // Nếu tìm thấy cộng dồn vào tổng giá
                    int index = it - dungtich.begin();
                    tonggia[index] += (list[i]).getGiaxe();
                }
            }
            for (int i = 0; i < dungtich.size(); i++) {
                cout << "Dung tich: " << dungtich[i] << " - Tong gia: " << tonggia[i] << endl;
            }
        }
        void timxetheohangduoigia(string hangxe, double gia) {
            for (int i = 0; i < size; i++) {
                if ((list[i]).getHangxe() == hangxe && (list[i]).getGiaxe() <= gia) {
                    (list[i]).showData();
                }
            }
        }
};

void run() {
    
    int n;
    ListMotorBike l;
    bool v = true;
    
    while (v) {
        cout << -- "1. Nhap danh sach xe may" << endl;
        cout << -- "2. Xuat danh sach xe may" << endl;
        cout << -- "3. Hien thi gia xe theo dung tich" << endl;
        cout << -- "4. Tim xe may theo hang xe" << endl;
        cout << -- "5. Thoat" << endl;
        cout << "Chon: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Nhap so luong xe may: ";
                cin >> n;
                l = ListMotorBike(n);
                for (int i = 0; i < n; i++) {
                    string hangxe, tenxe, sokhung;
                    int dungtich;
                    double giaxe;
                    cout << "Nhap thong tin xe may " << i + 1 << endl;
                    cout << "Hang xe: ";
                    cin.ignore();
                    getline(cin, hangxe);
                    cout << "Ten xe: ";
                    getline(cin, tenxe);
                    cout << "So khung: ";
                    getline(cin, sokhung);
                    cout << "Dung tich: ";
                    cin >> dungtich;
                    cout << "Gia xe: ";
                    cin >> giaxe;
                    (l.getList())[i] = motorbike(hangxe, tenxe, sokhung, dungtich, giaxe);
                }
                l.showData();
                break;
            }
            case 2: {
                l.showData();
                break;
            }
            case 3: {
                l.showByDungTich();
                break;
            }
            case 4: {
                string hangxe;
                double gia;
                cout << "Nhap hang xe: ";
                cin.ignore();
                getline(cin, hangxe);
                cout << "Nhap gia: ";
                cin >> gia;
                l.timxetheohangduoigia(hangxe, gia);
                break;
            }
            case 5: {
                v = false;
                break;
            }
            default: {
                cout << "Nhap sai, vui long nhap lai" << endl;
                break;
            }
        }

    }
    
}

int main() {

    run();

    return 0;
}
