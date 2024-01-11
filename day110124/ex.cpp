#include <bits/stdc++.h>

using namespace std;

class node{
public:
    string E, V;
    node *left, *right;
    
    node(string E, string V){
        this->E = E; 
        this->V = V;
        left = right = NULL; 
    }
};

class Dictonary{
public:
    node *add(node *t, string Eng, string Vie){ 
        if (!t){
            return new node(Eng, Vie);
        }
        if (Eng < t->E){
            t->left = add(t->left, Eng, Vie); 
        } else if (Eng > t->E){
            t->right = add(t->right, Eng, Vie);
        }
        return t;
    }
    node *minVal(node *t){ 
        node *temp = t;
        while(temp->left != NULL){
            temp = temp->left;
        }
        return temp;
    }
    node *del(node *t, string Eng, string Vie){  
        if (!t){
            return t;
        }
        if (Eng > t->E){
            t->right = del(t->right, Eng, Vie);
        } else if (Eng < t->E){
            t->left = del(t->left, Eng, Vie);
        } else{ 
            if(t->left == NULL){
                node *temp = t->right;
                delete(t);
                return temp;
            } else if(t->right == NULL){
                node *temp = t->left;
                delete(t);
                return temp;
            }
            node *change = minVal(t->right);
            t->E = change->E;
            t->V = change->V;
            t->right = del(t, change->E, change->V);
        }
        return t;
    }
     void updataVoc(node *t, string Eng, string VieUpdate){
        node *find_voc_change = find(t, Eng);
        if (!find_voc_change){
            t = add(t, Eng, VieUpdate);
        } else {
            find_voc_change->V = VieUpdate;
        }
    }
    node *find(node *t, string Eng){
       if (!t || t->E == Eng){
            return t;
        }
        if (Eng > t->E){
            return find(t->right, Eng);
        } else {
            return find(t->left, Eng);
        }
    }
};
void showData(node *t){
    if (t != NULL){
        showData(t->left);
        cout << "--- " << t->E << ": " <<  t->V << " ---" << endl;
        showData(t->right);
    }
}
void del_ram(node *t){
    if ( t != NULL){
        del_ram(t->left);
        del_ram(t->right);
        delete(t);
    }
}
// App 
void run(){
    Dictonary d;
    node *t = NULL;
    while(true){
        int n;
        cout << "-------------------------------------------------------\n";
        cout << "Nhập 1 để: Thêm một từ mới vào cây \n";
        cout << "Nhập 2 để: Xoá bỏ một từ của từ điển đang lưu trong cây \n";
        cout << "Nhập 3 để: Cập nhập lại nghĩa một từ trong cây \n";
        cout << "Nhập 4 để: In dữ liệu ra màn hình \n";
        cout << "Nhập 5 để: Tìm từ trong cây \n";
        cout << "Nhập 6 để: Thoát \n";
        cout << "-------------------------------------------------------" << endl;
        cout << "Nhập n = "; cin >> n;
        if (n == 1){
            string E, V;
            cout << "Nhập từ tiếng anh: "; cin >> E;
            cout << "Nhập nghĩa từ " << E << ": "; cin.ignore(); getline(cin, V);
            t = d.add(t, E, V);
        } else if (n == 2){
            string E, choose;
            cout << "Nhập từ tiếng Anh cần xoá trong file: "; cin >> E;
            node *temp = d.find(t, E);
            if (temp == NULL){
                cout << "Từ của bạn không có trong từ điểm" << endl;
            } else {
                cout << temp->E << ": " << temp->V << endl;
                cout << "Nhập Y/N, Y để đồng ý xoá từ " << E <<", N để không xoá: "; cin >> choose;
                if (choose == "y" || choose == "Y"){
                    t = d.del(t, E, temp->V);
                    cout << "Hãy check lại dữ liệu của bạn" << endl;
                }else {
                    cout << "---" << endl;
                }
            }
        } else if ( n == 3){
            string E, V;
            cout << "Nhập từ tiếng Anh sửa đổi nghĩa: "; cin >> E;
            cout << "Nhập nghĩa cần sửa đổi: "; cin.ignore(); getline(cin, V);
            d.updataVoc(t, E, V);
        } else if (n == 4){
            cout << "-------------------------------------------------------" << endl;
            showData(t);
            cout << "-------------------------------------------------------" << endl;
        } else if (n == 5){
            string E;
            cout << "Nhập từ tiếng Anh cần tìm: "; cin >> E;
            node *temp = d.find(t, E);
            if (temp){
                cout << temp->E << ": " << temp->V << endl;
            } else {
                cout << "Từ không có trong từ điển." << endl;
            }
        } else if ( n == 6){
            del_ram(t);
            for (int i = 0; i < 6; i++){
                cout << "END"<< endl;
            }
            break;
        } else {
            cout << "--- Vui lòng nhập số từ 1 đến 6 ---" << endl;
        }
    }
}

int main(){

    run();

    return 0;
}