#include "thongke.h"

void thongke::daban()
{
    bool check;
    do
    {
        check = true;
        fflush(stdin);
        cout << "nhap so luong da xuat: ";
        cin >> temp;
        kiemtra(check);
        if (check == 1)
            sl_daban = stoi(temp);
    } while (check == false || sl_daban > i.get_sl());
}

long long thongke::tonkho(thongtin i)
{
    // cout << "so luong: " << i.get_sl() << endl;
    sl_tonkho = i.get_sl() - sl_daban;
    return sl_tonkho;
}

void thongke::nhapvao()
{
    bool check;
    cout << "___Nhap thoi gian nhap hang___ \n";
    do
    {
        check = true;
        fflush(stdin);
        cout << "Ngay: ";
        cin >> temp;
        kiemtra(check);
        if (check == 1)
            nhap.ngay = stoi(temp);
    } while (check == false || nhap.ngay > 31 || nhap.ngay < 1);

    do
    {
        check = true;
        fflush(stdin);
        cout << "Thang: ";
        cin >> temp;
        kiemtra(check);
        if (check == 1)
            nhap.thang = stoi(temp);
    } while (check == false || nhap.thang > 12 || nhap.thang < 1);

    do
    {
        check = true;
        fflush(stdin);
        cout << "Nam: ";
        cin >> temp;
        kiemtra(check);
        if (check == 1)
            nhap.nam = stoi(temp);
    } while (check == false || nhap.nam > 2023 || nhap.nam < 1);
}

void thongke::xuatdi()
{
    bool check;
    cout << "___Nhap thoi gian xuat hang___ \n";
    do
    {
        check = true;
        fflush(stdin);
        cout << "Ngay: ";
        cin >> temp;
        kiemtra(check);
        if (check == 1)
            xuat.ngay = stoi(temp);
    } while (check == false || xuat.ngay > 31 || xuat.ngay < 1);

    do
    {
        check = true;
        fflush(stdin);
        cout << "Thang: ";
        cin >> temp;
        kiemtra(check);
        if (check == 1)
            xuat.thang = stoi(temp);
    } while (check == false || xuat.thang > 12 || xuat.thang < 1);

    do
    {
        check = true;
        fflush(stdin);
        cout << "Nam: ";
        cin >> temp;
        kiemtra(check);
        if (check == 1)
            xuat.nam = stoi(temp);
    } while (check == false || xuat.nam < 1);
}


void thongke::nhaphd()
{
    sl_daban = 0; // Hang chua xuat nen gan = 0
    xuat.ngay = 0;
    xuat.thang = 0;
    xuat.nam = 0; // Hang chua xuat nen ngay, thang,nam xuat gan bang 0
    nhapvao();    // tgian nhap hang vao
}

void thongke::kiemtra(bool &check)
{
    for (int i = 0; i < temp.size(); i++)
    {
        if (isalpha(temp[i]))
            check = false;
    }
}

void thongke::hienthi(thongtin i)
{
    if (nhap.ngay < 10 && nhap.thang < 10)
    {
        cout << left << setw(15) << sl_daban << setw(15) << left << tonkho(i) << setw(0) << left
             << "0" << nhap.ngay << "/0" << nhap.thang << "/" << setw(9) << left << nhap.nam;
    }
    else if (nhap.ngay < 10 && nhap.thang > 10)
    {
        cout << left << setw(15) << sl_daban << setw(15) << left << tonkho(i) << setw(0) << left
             << "0" << nhap.ngay << "/" << nhap.thang << "/" << setw(9) << left << nhap.nam;
    }
    else if (nhap.ngay > 10 && nhap.thang < 10)
    {
        cout << left << setw(15) << sl_daban << setw(15) << left << tonkho(i) << setw(0) << left
             << nhap.ngay << "/0" << nhap.thang << "/" << setw(9) << left << nhap.nam;
    }
    else
    {
        cout << left << setw(15) << sl_daban << setw(15) << left << tonkho(i) << setw(0) << left
             << nhap.ngay << "/" << nhap.thang << "/" << setw(9) << left << nhap.nam;
    }

    if (xuat.ngay < 10 && xuat.thang < 10)
        cout << "0" << xuat.ngay << "/0" << xuat.thang << "/" << setw(11) << left << xuat.nam;

    else if (xuat.ngay < 10 && xuat.thang > 10)
        cout << "0" << xuat.ngay << "/" << xuat.thang << "/" << setw(11) << left << xuat.nam;

    else if (xuat.ngay > 10 && xuat.thang < 10)
        cout << xuat.ngay << "/0" << xuat.thang << "/" << setw(11) << left << xuat.nam;

    else
        cout << xuat.ngay << "/" << xuat.thang << "/" << setw(11) << left << xuat.nam;

}
void thongke::set_db(long long daban)
{
    sl_daban = daban;
}
long long thongke::get_db()
{
    return sl_daban;
}
void thongke::ghi(fstream &g)
{
    g.write(reinterpret_cast<char *>(&sl_daban), sizeof(long long));
    g.write(reinterpret_cast<char *>(&sl_tonkho), sizeof(long long));
    g.write(reinterpret_cast<char *>(&nhap), sizeof(thoigian));
    g.write(reinterpret_cast<char *>(&xuat), sizeof(thoigian));
}

void thongke::doc(fstream &d)
{
    d.read(reinterpret_cast<char *>(&sl_daban), sizeof(long long));
    d.read(reinterpret_cast<char *>(&sl_tonkho), sizeof(long long));
    d.read(reinterpret_cast<char *>(&nhap), sizeof(thoigian));
    d.read(reinterpret_cast<char *>(&xuat), sizeof(thoigian));
}
