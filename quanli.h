#ifndef QUANLI_H
#define QUANLI_H
#include "thongke.h"
#include "hangtieudung.h"
#include "thucpham.h"

class quanli
{
    thucpham *tp;
    hangtieudung *htd;
    thongke *h1, *h2;
    int luachon, soloai1, soloai2;
    string ten, ID, loai, hang;
    double gia;

public:
    quanli()
    {
        tp = new thucpham[100];
        htd = new hangtieudung[100];
        h1 = new thongke[100];
        h2 = new thongke[100];
    }
    ~quanli()
    {
        delete[] tp;
        delete[] htd;
        delete[] h1;
        delete[] h2;
    }

private:
    void add_sp();      // them sp
    void del_sp();      // xóa sản phẩm
    void hienthi();     // Hàm hiển thị tất cả thông tin
    void khung_on();    // khung background tren
    void khung_down1(); // khung background duoi
    void khung_down2(); // khung background duoi
    void timkiem();     // Hàm tìm kiếm chung, trong này sẽ có các case để lựa chọn
    void tim_ID();      // tìm theo mã sản phẩm
    void tim_ten();     // tìm theo tên
    void tim_gia();     // tìm theo giá
    void tim_loai();    // tìm theo loại
    void ql_timkiem();  // quay lai ham tim kiem
    void ud_soluong();  // cập nhật số lượng
    void update();      // cập nhật sản phẩm
    void ql_update();   // quay lai ham update
    long long tongGT_kho(); // tinh tong gia tri cua kho
    void check_ID(int);     // ham kiem tra id trung
    void doc_sl();          // ham doc thong tin tat ca san pham
public:
    void menu();
    
};

#endif