#include "accout.h"

void accout::nhap()
{
    cout << "Dang ki tai khoan: \n";
    cout << "Nhap ten dang nhap: " << endl;
    fflush(stdin);
    cin.getline(username, 20);
    cout << "Nhap mat khau: " << endl;
    fflush(stdin);
    cin.getline(password, 20);
    system("cls");
}

