#include "thongtin.h"

class thongke
{
    class thoigian
    {
    public:
        long ngay, thang, nam;

    };
    thoigian nhap, xuat;                  // thoi gian nhap, xuat hang
    thongtin i;
    long long sl_daban, sl_tonkho;        // số lượng đã bán, tồn kho
    string temp;                          // dung de kiem tra kieu du lieu cua cac bien
    void kiemtra( bool &);                // kiem tra 
public:
    void daban();                         // nhập số lượng đã bán
    long long tonkho(thongtin t);         // số lượng hàng hóa còn lại trong kho
    void nhapvao();                       // thời gian nhập hàng vào
    void xuatdi();                        // thời gian xuất hàng đi
    void hienthi(thongtin i);
    void nhaphd();                        // nhap thong tin
    void ghi(fstream &g);                 // ghi file
    void doc(fstream &d);                 // doc file
    void set_db(long long daban);         // setter so luong da ban
    long long get_db();                   // getter so luong da ban
};