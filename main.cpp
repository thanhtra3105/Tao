#include "quanli.h"
#include "accout.h"
// #pragma once
void sign_up()
{
    accout acc;
    fstream w("acc.bin", ios::binary | ios::out);
    if (!w)
    {
        cout << "Khong the mo file!" << endl;
        exit(1);
    }
    // w.clear();
    acc.nhap();
    w.write(reinterpret_cast<const char *>(&acc), sizeof(accout));
    cout << "Dang ki thanh cong !!!\n";
    w.close();
}

void sign_in()
{
    accout acc;
    static int choice, dem = 0, j = 0;
    static string user, password, tim_acc, tim_pass;
    fstream r("acc.bin", ios::binary | ios::in);
    if (!r)
    {
        cout << "Khong the mo file!" << endl;
        exit(1);
    }
tt:
    fflush(stdin);
    cout << "Nhap ten dang nhap: \n";
    cin >> user;
    system("cls");
    cout << "Nhap mat khau: \n";
    fflush(stdin);
    cin >> password;
    system("cls");
    r.read(reinterpret_cast<char *>(&acc), sizeof(accout));

    if (user == acc.username && password == acc.password)
    {
        cout << "\nDang nhap thanh cong! \n";
        cout << "------------------------\n";
    }

    if (user != acc.username || password != acc.password)
    {
        cout << "Sai 3 lan se phai dang ki lai! \n";
        for (int i = j; i < 3; i++)
        {
            j++;
            goto tt;
        }
        cout << "1.Quen mat khau \n";
        cout << "2.Quen ten dang nhap \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            do
            {
                cout << "Nhap ten dang nhap de tim mat khau \n";
                cin >> tim_acc;
                if (tim_acc == acc.username)
                {
                    cout << "Mat khau cua tai khoan( " << acc.username << " )la: " << acc.password << endl;
                    int lc;

                    cout << "Nhap 0 de quay lai.";
                    cin >> lc;
                    if (lc == 0)
                        goto tt;
                }
                else
                {
                    dem++;
                    cout << "Sai 3 lan se dang ki lai \n";
                    cout << "Sai lan thu: " << dem << endl;
                    if (dem == 3)
                    {
                        sign_up();
                        goto tt;
                    }
                }

            } while (true);
            break;
        case 2:
            sign_up();
            break;
        default:
            break;
        }
    }

    r.close();
}

////////////////////////////////////////////////////////////////

int main()
{
    int dem = 0, soloai;
    quanli q;
    int luachon;
dn:
    do
    {
        cout << " ________________________________________\n";
        cout << "|                                        |\n";
        cout << "|-----WELCOME TO STORE MANAGENT PAGE-----|\n";
        cout << "|________________________________________|\n";
        cout << "Nhap lua chon: \n";
        cout << "1. Sign up. \n";
        cout << "2. Sign in. \n";
        cin >> luachon;
        int lc;
        switch (luachon)
        {
        case 1:
            sign_up();
            do
            {
                cout << "Nhap 0 de quay lai \n";
                cin >> lc;
                system("cls");
                if (lc == 0)
                    goto dn;
            } while (!lc);
        case 2:
            sign_in();
            do
            {
                cout << "Nhap 1 de tiep tuc. \n";
                cin >> lc;
                system("cls");
                if (lc == 1)
                    q.menu();
            } while (lc != 1);
            dem = 1;
            break;
        default:
            break;
        }
    } while (dem == 0); 
}

                                             