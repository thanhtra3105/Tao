#include "quanli.h"

void quanli::hienthi()
{ 
     doc_sl();
     cout << "SO LOAI THUC PHAM: " << soloai1 << endl;
     cout << "SO LOAI HANG TIEU DUNG: " << soloai2 << endl;
     khung_on();
     if (soloai1 > 0)
     {
         cout << left << setw(15) << "| THUC PHAM";
         for (int i = 0; i < soloai1; i++)
         {
             if (i == 0 and soloai1 == 1)
             {
                 tp[i].hienthi();
                 h1[i].hienthi(tp[i]);
                 cout << setw(12) << left << tp[i].get_tongsp() << "|" << endl;
                 khung_down2();
             }

             else if (i == 0 and soloai1 != 1)
             {
                 tp[i].hienthi();
                 h1[i].hienthi(tp[i]);
                 cout << setw(12) << left << tp[i].get_tongsp() << "|" << endl;
                 khung_down1();
             }

             else if (i >= 1 && i < soloai1 - 1)
             {
                 cout << left << setw(15) << "|";
                 tp[i].hienthi();
                 h1[i].hienthi(tp[i]);
                 cout << setw(12) << left << tp[i].get_tongsp() << "|" << endl;
                 khung_down1();
             }

             else
             {
                 cout << left << setw(15) << "|";
                 tp[i].hienthi();
                 h1[i].hienthi(tp[i]);
                 cout << setw(12) << left << tp[i].get_tongsp() << "|" << endl;
                 khung_down2();
             }
         }
     }
     if (soloai2 > 0)
     {
         cout << left << setw(15) << "| H.TIEU DUNG";
         for (int i = 0; i < soloai2; i++)
         {
             if (i == 0 and soloai2 == 1)
             {
                 htd[i].hienthi();
                 h2[i].hienthi(htd[i]);
                 cout << setw(12) << left << htd[i].get_tongsp() << "|" << endl;
                 khung_down2();
             }

             else if (i == 0 and soloai2 != 1)
             {
                 htd[i].hienthi();
                 h2[i].hienthi(htd[i]);
                 cout << setw(12) << left << htd[i].get_tongsp() << "|" << endl;
                 khung_down1();
             }
             else if (i >= 1 && i < soloai2 - 1)
             {
                 cout << left << setw(15) << "|";
                 htd[i].hienthi();
                 h2[i].hienthi(htd[i]);
                 cout << setw(12) << left << htd[i].get_tongsp() << "|" << endl;
                 khung_down1();
             }

             else
             {
                 cout << left << setw(15) << "|";
                 htd[i].hienthi();
                 h2[i].hienthi(htd[i]);
                 cout << setw(12) << left << htd[i].get_tongsp() << "|" << endl;
                 khung_down2();
             }
         }
     }
     cout << "\n--------------------------------------- \n\n";
     cout << "Tong gia tri trong kho: " << tongGT_kho() << " VND" << endl; 
}

void quanli::khung_on()
{
    cout << " ===================================================================================================================================================================\n";
    cout << left << setw(15) << "|"
         << setw(66) << left << "|" << setw(83) << left << "THONG TIN HANG HOA"
         << "|\n";

    cout << left << setw(15) << "| MAT HANG"
         << "|----------------------------------------------------------------------------------------------------------------------------------------------------|\n";

    cout << left << setw(15) << "|" << left << setw(18) << "|  TEN" << setw(6) << left << "ID" << setw(14) << left << "LOAI" << setw(12) << left << "HANG" << setw(10) << left << "SL NHAP"
         << setw(15) << left << "GIA(VND)" << setw(15) << left << "SL XUAT" << setw(15) << left << "SL TON" << setw(15) << left << "NGAY NHAP" << setw(15) << left
         << "NGAY XUAT" << setw(0) << left << "TONG GT(VND)  |" << endl;
    cout << "|==============|=================================================================="
         << "==================================================================================|\n";
}
void quanli::khung_down1()
{
    cout << left << setw(15) << "|"
         << "|----------------------------------------------------------------------------------------------------------------------------------------------------|\n";
}
void quanli::khung_down2()
{
    cout << "|==============|=================================================================="
         << "==================================================================================|\n";
}

void quanli::doc_sl()
{
    soloai1 = 0;
    soloai2 = 0;
    fstream d1("thucpham.bin", ios::binary | ios::in);
    fstream d2("hangtieudung.bin", ios::binary | ios::in);
    if (!d1 || !d2)
    {
        cout << "Loi mo file!" << endl;
        cout << "LUU Y: CO 2 FILE THUCPHAM VA HANGTIEUDUNG NEN CO THE CHUA CO 1 TRONG 2 FILE\n";
        fstream g1("thucpham.bin", ios::binary | ios::out);
        fstream g2("hangtieudung.bin", ios::binary | ios::out);
        tp[0].ghi(g1);
        htd[0].ghi(g2);
        g1.close();
        g2.close();
        cout << "Hay chay lai chuong trinh!!";
        exit(1);
    }
    else
    {
        while (!d1.eof())
        {
            tp[soloai1].doc(d1);
            h1[soloai1].doc(d1);
            if (!d1.eof())
                soloai1++;
        }
        d1.close();
        // cout << soloai1 << endl;

        while (!d2.eof())
        {
            htd[soloai2].doc(d2);
            h2[soloai2].doc(d2);
            if (!d2.eof())
                soloai2++;
        }
        d2.close();
        // cout << soloai2 << endl;
    }
}

void quanli::add_sp()
{

    doc_sl();
    int *sl = new int;
    int lc;
    fstream g_tp("thucpham.bin", ios::binary | ios::out | ios::app);
    fstream g_htd("hangtieudung.bin", ios::binary | ios::out | ios::app);
    cout << "Chon mat hang can them\n";
    cout << "1. THUC PHAM\n";
    cout << "2. HANG TIEU DUNG\n";
    cin >> lc;
    switch (lc)
    {
    case 1:
        cout << "Nhap so loai san pham can them: ";
        cin >> *sl;
        // cout<<"so loai = "<<soloai<<endl;
        for (int i = soloai1; i < soloai1 + *sl; i++)
        {
            cout << "Nhap thong tin san pham thu:" << i + 1 << endl;
            fflush(stdin);
            tp[i].nhap();
            check_ID(i);
            tp[i].ghi(g_tp);
            h1[i].nhaphd();
            h1[i].ghi(g_tp);
            system("cls");
        }
        break;

    case 2:
        cout << "Nhap so loai san pham can them: ";
        cin >> *sl;
        for (int i = soloai2; i < soloai2 + *sl; i++)
        {
            cout << "Nhap thong tin san pham thu:" << i + 1 << endl;
            fflush(stdin);
            htd[i].nhap();
            check_ID(i);
            htd[i].ghi(g_htd);
            h2[i].nhaphd();
            h2[i].ghi(g_htd);
            system("cls");
        }

        break;
    default:
        break;
    }
    delete sl;
    g_tp.close();
    g_htd.close();
}

void quanli::del_sp()
{
    doc_sl();
    string ma;
    cout << "Nhap ID hang hoa can xoa: " << endl;
    fflush(stdin);
    getline(cin, ma);
    transform(ma.begin(), ma.end(), ma.begin(), ::toupper);
    for (int i = 0; i < soloai1; i++)
    {
        if (ma == tp[i].get_ID())
        {
            cout << "Da xoa " << tp[i].get_ten() << "    ID: " << ma << endl;
            for (int j = i; j < soloai1 - 1; j++)
            {
                {
                    tp[j] = tp[j + 1];
                    h1[j] = h1[j + 1];
                }
            }
            soloai1--;
        }
    }

    for (int i = 0; i < soloai2; i++)
    {
        if (ma == htd[i].get_ID())
        {
            cout << "Da xoa " << htd[i].get_ten() << "    ID: " << ma << endl;
            for (int j = i; j < soloai2 - 1; j++)
            {

                {
                    htd[j] = htd[j + 1];
                    h2[j] = h2[j + 1];
                }
            }
            soloai2--;
        }
    }
    fstream g1("thucpham.bin", ios::binary | ios::out);     // mo file ghi thuc pham
    fstream g2("hangtieudung.bin", ios::binary | ios::out); // mo file ghi hang tieu dung
    if (!g1 || !g2)
    {
        cout << "Loi mo file!\n";
        exit(0);
    }
    for (int i = 0; i < soloai1; i++)
    {
        tp[i].ghi(g1);
        h1[i].ghi(g1);
    }

    for (int i = 0; i < soloai2; i++)
    {
        htd[i].ghi(g2);
        h2[i].ghi(g2);
    }
    g1.close();
    g2.close();
}

void quanli::ud_soluong()
{
    doc_sl();
    string ten, ID;
    long long daban;
    fflush(stdin);
    cout << "Nhap ten san pham can cap nhat: ";
    getline(cin, ten);
    transform(ten.begin(), ten.end(), ten.begin(), ::toupper);
    cout << "Nhap ID san pham can cap nhat: ";
    getline(cin, ID);
    fstream g1("thucpham.bin", ios::binary | ios::out); // Tao file moi de copy file cu vao day
    fstream g2("hangtieudung.bin", ios::binary | ios::out);
    for (int i = 0; i < soloai1; i++)
    {
        if (ten == tp[i].get_ten() && ID == tp[i].get_ID())
        {
            cout << "Nhap so luong da xuat: ";
            cin >> daban;
            h1[i].xuatdi();
            h1[i].set_db(h1[i].get_db() + daban);
        }
        else
        {
            h1[i].set_db(h1[i].get_db());
        }
        tp[i].ghi(g1);
        h1[i].ghi(g1);
    }
    for (int i = 0; i < soloai2; i++)
    {
        if (ten == htd[i].get_ten() && ID == htd[i].get_ID())
        {
            cout << "Nhap so luong da xuat: ";
            cin >> daban;
            h2[i].xuatdi();
            h2[i].set_db(h2[i].get_db() + daban);
        }
        else
        {
            h2[i].set_db(h2[i].get_db());
        }
        htd[i].ghi(g2);
        h2[i].ghi(g2);
    }
    // g.close();
    g1.close();
    g2.close();
}

void quanli::update()
{
    int choice;
    do
    {
        system("cls");
        cout << " -------------------\n";
        cout << "|   Nhap lua chon   |\n";
        cout << " -------------------\n";
        cout << "1.Them hang hoa. \n";
        cout << "2.Xoa hang hoa. \n";
        cout << "3.Cap nhat so luong xuat kho. \n";
        cout << "0.Quay lai.\n";
        fflush(stdin);
        cin >> choice;
        switch (choice)
        {
        case 1:
            add_sp();
            ql_update();
            break;
        case 2:
            del_sp();
            ql_update();
            break;
        case 3:
            ud_soluong();
            ql_update();
            break;
        case 0:
            break;
        }
    } while (choice < 0 || choice > 3);
}

void quanli::ql_update()
{
    int lc;
    do
    {
        cout << "------------------- \n";
        cout << "Nhap 0 de quay lai! " << endl;
        cin >> lc;
        if (lc == 0)
        {
            update();
            break;
        }
        else
            cout << "Khong hop le \n";
    } while (lc != 0);
    system("cls");
}

void quanli::check_ID(int i)
{
    for (int j = 0; j < i; j++)
    {
        while (tp[i].get_ID() == tp[j].get_ID() || tp[i].get_ID() == htd[j].get_ID())
        {
            cout << "Trung ID! Hay nhap lai san pham nay " << endl;
            cout << "Nhap thong tin san pham thu: " << i + 1 << endl;
            fflush(stdin);
            tp[i].nhap();
        }
    }

    for (int j = 0; i < i; j++)
    {
        while (htd[i].get_ID() == htd[j].get_ID() || htd[i].get_ID() == tp[j].get_ID())
        {
            cout << "Trung ID! Hay nhap lai san pham nay " << endl;
            cout << "Nhap thong tin san pham thu: " << i + 1 << endl;
            fflush(stdin);
            htd[i].nhap();
        }
    }
}

long long quanli::tongGT_kho()
{
    long long sum = 0;
    for (size_t i = 0; i < soloai1; i++)
    {
        sum += tp[i].get_tongsp();
    }

    for (size_t i = 0; i < soloai2; i++)
    {
        sum += htd[i].get_tongsp();
    }
    return sum;
}

void quanli::tim_ten()
{
    fflush(stdin);
    cout << "---------Nhap ten hang hoa can tim kiem------" << endl;
    getline(cin, ten);
    transform(ten.begin(), ten.end(), ten.begin(), ::toupper);
    khung_on();
    for (int i = 0; i < soloai1; i++)
    {
        if (ten == tp[i].get_ten())
        {
            cout << left << setw(15) << "| THUC PHAM";
            tp[i].hienthi();
            h1[i].hienthi(tp[i]);
            cout << setw(12) << left << tp[i].get_tongsp() << "|" << endl;
            khung_down2();
        }
    }

    for (int i = 0; i < soloai2; i++)
    {
        if (ten == htd[i].get_ten())
        {
            cout << left << setw(15) << "| H.TIEU DUNG";
            htd[i].hienthi();
            h2[i].hienthi(htd[i]);
            cout << setw(12) << left << htd[i].get_tongsp() << "|" << endl;
            khung_down2();
        }
    }
}

void quanli::tim_ID()
{
    fflush(stdin);
    cin.ignore(0);
    cout << "---------Nhap ID hang hoa can tim kiem------" << endl;
    getline(cin, ID);
    transform(ID.begin(), ID.end(), ID.begin(), ::toupper);
    khung_on();
    for (int i = 0; i < soloai1; i++)
    {
        if (ID == tp[i].get_ID())
        {
            cout << left << setw(15) << "| THUC PHAM";
            tp[i].hienthi();
            h1[i].hienthi(tp[i]);
            cout << setw(12) << left << tp[i].get_tongsp() << "|" << endl;
            khung_down2();
        }
    }
    for (int i = 0; i < soloai2; i++)
    {
        if (ID == htd[i].get_ID())
        {
            cout << left << setw(15) << "| H.TIEU DUNG";
            htd[i].hienthi();
            h2[i].hienthi(htd[i]);
            cout << setw(12) << left << htd[i].get_tongsp() << "|" << endl;
            khung_down2();
        }
    }
}

void quanli::tim_gia()
{

    cout << "---------Nhap gia cua hang hoa can tim kiem------" << endl;
    fflush(stdin);
    cin >> gia;
    khung_on();
    for (int i = 0; i < soloai1; i++)
    {
        if (gia == tp[i].get_gia())
        {
            cout << left << setw(15) << "| THUC PHAM";
            tp[i].hienthi();
            h1[i].hienthi(tp[i]);
            cout << setw(12) << left << tp[i].get_tongsp() << "|" << endl;
            khung_down2();
        }
    }
    for (int i = 0; i < soloai2; i++)
    {
        if (gia == htd[i].get_gia())
        {
            cout << left << setw(15) << "| H.TIEU DUNG";
            htd[i].hienthi();
            h2[i].hienthi(htd[i]);
            cout << setw(12) << left << htd[i].get_tongsp() << "|" << endl;
            khung_down2();
        }
    }
}

void quanli::tim_loai()
{
    cin.ignore();
    cout << "---------nhap loai hang hoa can tim kiem------" << endl;
    fflush(stdin);
    getline(cin, loai);
    transform(loai.begin(), loai.end(), loai.begin(), ::toupper);
    khung_on();
    for (int i = 0; i < soloai1; i++)
    {
        if (loai == tp[i].get_loai())
        {
            cout << left << setw(15) << "| THUC PHAM";
            tp[i].hienthi();
            h1[i].hienthi(tp[i]);
            cout << setw(12) << left << tp[i].get_tongsp() << "|" << endl;
            khung_down2();
        }
    }
    for (int i = 0; i < soloai2; i++)
    {
        if (loai == htd[i].get_loai())
        {
            cout << left << setw(15) << "| H.TIEU DUNG";
            htd[i].hienthi();
            h2[i].hienthi(htd[i]);
            cout << setw(12) << left << htd[i].get_tongsp() << "|" << endl;
            khung_down2();
        }
    }
}
void quanli::timkiem()
{
    doc_sl();
    int choice;
    do
    {
        system("cls");
        cout << " -------------------\n";
        cout << "|   Nhap lua chon   |\n";
        cout << " -------------------\n";
        cout << "1. Tim theo ten \n";
        cout << "2. Tim theo ID \n";
        cout << "3. Tim theo gia \n";
        cout << "4. Tim theo loai \n";
        cout << "0. Quay lai!\n";
        fflush(stdin);
        cin >> choice;
        switch (choice)
        {
        case 1:
            tim_ten();
            ql_timkiem();
            break;
        case 2:
            tim_ID();
            ql_timkiem();
            break;
        case 3:
            tim_gia();
            ql_timkiem();
            break;
        case 4:
            tim_loai();
            ql_timkiem();
            break;
        case 0:
            break;
        }
    } while (choice < 0 || choice > 4);
}

void quanli::ql_timkiem()
{
    int lc;
    do
    {
        cout << "------------------- \n";
        cout << "Nhap 0 de quay lai! " << endl;
        cin >> lc;
        if (lc == 0)
        {
            timkiem();
            break;
        }
        else
            cout << "Khong hop le \n";
    } while (lc != 0);
    system("cls");
}

void quanli::menu()
{
    bool count = true;
    do
    {
        system("cls");
        cout << " ___________________________________\n";
        cout << "|                                   |" << endl;
        cout << "|               MENU                |" << endl;
        cout << "|___________________________________|" << endl;
        cout << "1.Cap nhat hang hoa. \n";
        cout << "2.Hien thi tat ca hang hoa. \n";
        cout << "3.Tim kiem hang hoa. \n";
        cout << "4.Thoat!! \n";
        fflush(stdin);
        cin >> luachon;

        switch (luachon)
        {
        case 1:
            update();
            break;
        case 2:
            hienthi();
            system("pause");
            break;
        case 3:
            timkiem();
            break;
        case 4:
            count = false;
            break;
        default:
            break;
        }
    } while (count == true);
    cout << "Da ket thuc lenh!!!" << endl;
    exit(1);
}