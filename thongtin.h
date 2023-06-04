#ifndef THONGTIN_H
#define THONGTIN_H
#include "thuvien.h"

class thongtin
{
    string tensp; 
    string ID;
    string loai;
    string hang;        // tên, mã,loại sp, hãng sản xuất
    long long soluong;
    double gia;
    
public:
    thongtin(){}
    void nhap();
    void hienthi();
    long long get_sl() const;
    string get_ten();
    string get_loai();
    void set_gia(double g);
    double get_gia() const;
    string get_ID();
    string get_hang();
    long long get_tongsp() const; // tổng giá trị của 1 sp
    void ghi(fstream &g);
    void doc(fstream &d);
};

#endif