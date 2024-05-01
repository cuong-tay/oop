#include <iostream>

class DichVu {
private:
    int giuong;
    int chieu;
    int nonglanh;
    int dieuhoa;
    int slhong; 

public:
    DichVu(int giuong = 1, int chieu = 1, int nonglanh = 1, int dieuhoa = 1, int slhong = 0)
        : giuong(giuong), chieu(chieu), nonglanh(nonglanh), dieuhoa(dieuhoa), slhong(slhong) {}

    void setGiuong(int giuong) {
        this->giuong = giuong;
    }

    int getGiuong() {
        return giuong;
    }

    void setChieu(int chieu) {
        this->chieu = chieu;
    }

    int getChieu() {
        return chieu;
    }

    void setNongLanh(int nonglanh) {
        this->nonglanh = nonglanh;
    }

    int getNongLanh() {
        return nonglanh;
    }

    void setDieuHoa(int dieuhoa) {
        this->dieuhoa = dieuhoa;
    }

    int getDieuHoa() {
        return dieuhoa;
    }

    void setSoLuongHong(int slhong) {
        this->slhong = slhong;
    }

    int getSoLuongHong()  {
        return slhong;
    }
};


