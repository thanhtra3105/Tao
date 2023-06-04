#include "thongtin.h"

void thongtin::nhap()
{
    cin.ignore(0);
    fflush(stdin);
    cout << "Nhap ten san pham:      ";
    getline(cin, tensp);
    transform(tensp.begin(), tensp.end(), tensp.begin(), ::toupper);

    fflush(stdin);
    cout << "Nhap ma san pham:       ";
    getline(cin, ID);
    transform(ID.begin(), ID.end(), ID.begin(), ::toupper);

    fflush(stdin);
    cout << "Nhap loai san pham:     ";
    getline(cin, loai);
    transform(loai.begin(), loai.end(), loai.begin(), ::toupper);

    fflush(stdin);
    cout << "Nhap hang cua san pham: ";
    getline(cin, hang);
    transform(hang.begin(), hang.end(), hang.begin(), ::toupper);
    string temp;
    bool check ;
    do
    {
        check = true;
        fflush(stdin);
        cout << "Nhap so luong:          ";
        cin >> temp;
        for (int i = 0; i < temp.size(); i++)
        {
            if (isalpha(temp[i]))
                check = false;
        }
    } while (check == false);
    soluong = stoll(temp);
    do
    {
        check = true;
        fflush(stdin);
        cout << "Nhap gia cua moi san pham(x1000 VND): ";
        cin >> temp;
        for (int i = 0; i < temp.size(); i++)
        {
            if (isalpha(temp[i]))
                check = false;
        }
    } while (check == false);
    gia = stod(temp);
    gia *= 1000;
}

void thongtin::hienthi()
{
    // cout << left<< setw(10) << "TEN" << setw(10) << "ID" << setw(10) << "LOAI" << setw(10) << "HANG" << setw(10) << "SL" << setw(10) << "GIA" << endl;
    cout << "|  " << left << setw(15) << tensp << setw(6) << left << ID << setw(14) << left << loai << left << setw(12) << left << hang
         << setw(10) << left << soluong << setw(15) << left << fixed << setprecision(0) << gia;
}

long long thongtin::get_sl() const
{
    return soluong;
}
void thongtin::set_gia(double g)
{
    gia = g;
}

double thongtin::get_gia() const
{
    return gia;
}

string thongtin::get_ten()
{
    return tensp;
}

string thongtin::get_loai()
{
    return loai;
}

string thongtin::get_ID()
{
    return ID;
}

string thongtin::get_hang()
{
    return hang;
}

long long thongtin::get_tongsp() const
{
    return soluong * gia;
}

void thongtin::ghi(fstream &g)
{

    g.write(reinterpret_cast<const char *>(&soluong), sizeof(soluong));
    g.write(reinterpret_cast<const char *>(&gia), sizeof(gia));

    size_t size = tensp.size();
    g.write(reinterpret_cast<const char *>(&size), sizeof(size));
    g.write(tensp.data(), size);

    size = ID.size();
    g.write(reinterpret_cast<const char *>(&size), sizeof(size));
    g.write(ID.data(), size);

    size = loai.size();
    g.write(reinterpret_cast<const char *>(&size), sizeof(size));
    g.write(loai.data(), size);

    size = hang.size();
    g.write(reinterpret_cast<const char *>(&size), sizeof(size));
    g.write(hang.data(), size);
}

void thongtin::doc(fstream &d)
{

    d.read(reinterpret_cast<char *>(&soluong), sizeof(soluong));
    d.read(reinterpret_cast<char *>(&gia), sizeof(gia));

    size_t size = tensp.size();
    d.read(reinterpret_cast<char *>(&size), sizeof(size));
    char *ten_data = new char[size];           // tạo một mảng ký tự để lưu dữ liệu chuỗi
    std::memcpy(ten_data, tensp.data(), size); // sao chép dữ liệu từ chuỗi sang mảng ký tự
    d.read(ten_data, size);                    // chuyển mảng ký tự vào hàm read
    tensp.assign(ten_data, size);              // gán dữ liệu từ mảng ký tự vào chuỗi
    delete[] ten_data;

    size = ID.size();
    d.read(reinterpret_cast<char *>(&size), sizeof(size));
    char *ID_data = new char[size];        // tạo một mảng ký tự để lưu dữ liệu chuỗi
    std::memcpy(ID_data, ID.data(), size); // sao chép dữ liệu từ chuỗi sang mảng ký tự
    d.read(ID_data, size);                 // chuyển mảng ký tự vào hàm read
    ID.assign(ID_data, size);              // gán dữ liệu từ mảng ký tự vào chuỗi
    delete[] ID_data;

    size = loai.size();
    d.read(reinterpret_cast<char *>(&size), sizeof(size));
    char *loai_data = new char[size];          // tạo một mảng ký tự để lưu dữ liệu chuỗi
    std::memcpy(loai_data, loai.data(), size); // sao chép dữ liệu từ chuỗi sang mảng ký tự
    d.read(loai_data, size);                   // chuyển mảng ký tự vào hàm read
    loai.assign(loai_data, size);              // gán dữ liệu từ mảng ký tự vào chuỗi
    delete[] loai_data;                        // giải phóng mảng ký tự

    size = hang.size();
    d.read(reinterpret_cast<char *>(&size), sizeof(size));
    char *hang_data = new char[size];          // tạo một mảng ký tự để lưu dữ liệu chuỗi
    std::memcpy(hang_data, hang.data(), size); // sao chép dữ liệu từ chuỗi sang mảng ký tự
    d.read(hang_data, size);                   // chuyển mảng ký tự vào hàm read
    hang.assign(hang_data, size);              // gán dữ liệu từ mảng ký tự vào chuỗi
    delete[] hang_data;
}