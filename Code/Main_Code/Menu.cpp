#include "Process.cpp"

string InputString;

int processInputString(string choose ,int max){
    int count = 0;
    int chooseNum = 0;
    for(int i=0;i<choose.size();i++){
        chooseNum *= 10;
        chooseNum += int(choose[i] - 48);
    }
    // Check again
    while(chooseNum < 1 || chooseNum > max){
        chooseNum = 0;
        TextColor(4);
        cout << "\tLua chon cua ban da sai !!" << endl;
        TextColor(7);
        cout << "\t-> Moi ban nhap lai lua chon cua ban la (1-" << max << ") : ";
        if(count == 0){
            cin.ignore();
            count ++;
        }
        getline(cin,choose);
        for(int i=0;i<choose.size();i++){
            chooseNum *= 10;
            chooseNum += int(choose[i] - 48);
        }
    }
    return chooseNum;
}

void CheckPresentDate(){
    if(PresentDate == 1){
        LE.ResetDay(tinhSoNgayTrongThang(PresentMonth,PresentYear));
    }
}

void Decide(int choose1){
    int c1;
    cout << endl;
    switch (choose1)
    {
        case 1:
        {   
            do{
                system("cls");
                TextColor(14);
                cout << "\t**************************IN DANH SACH**************************" << endl;
                cout << "\t     ======================================================" << endl;
                cout << "\t     ||    1. In danh sach nhan vien                     ||" << endl;
                cout << "\t     ||    2. In danh sach chuc vu                       ||" << endl;
                cout << "\t     ||    3. In danh sach phong ban                     ||" << endl;
                cout << "\t     ||    4. In danh sach luong nhan vien nhan duoc     ||" << endl;
                cout << "\t     ||    5. In danh sach chuc vu cua nhan vien         ||" << endl;
                cout << "\t     ||    6. Thoat                                      ||" << endl;
                cout << "\t     ======================================================" << endl;
                cout << "\t***************************************************************" << endl;
                TextColor(7);
                cout << "\t-> Lua chon cua ban (1-6): ";
                cin >> InputString;
                c1 = processInputString(InputString,6);
                Show(c1);
                if(c1 !=6) system("Pause");
            }while(c1 != 6);
            break;
        }
        case 2:
        {
            do{
                system("cls");
                TextColor(14);
                cout << "\t*************************SAP XEP*************************" << endl;
                cout << "\t               ====Sap xep nhan vien====" << endl;
                cout << "\t               ||   1. Theo MSNV      ||" << endl;
                cout << "\t               ||   2. Theo Luong     ||" << endl;
                cout << "\t               ||   3. Thoat          ||" << endl;
                cout << "\t               =========================" << endl;
                cout << "\t*********************************************************" << endl;
                TextColor(7);
                cout << "\t-> Lua chon cua ban (1-3): ";
                cin >> InputString;
                c1 = processInputString(InputString,3);
                if(c1>=1 && c1<=2) Sort(c1);
            }while(c1 != 3);
            break;
        }
        case 3:
        {
            do{
                system("cls");
                TextColor(14);
                cout << "\t************************XOA************************" << endl;
                cout << "\t           ===========================" << endl;
                cout << "\t           ||   1. Xoa Nhan Vien    ||" << endl;
                cout << "\t           ||   2. Xoa Chuc vu      ||" << endl;
                cout << "\t           ||   3. Xoa Phong Ban    ||" << endl;
                cout << "\t           ||   4. Thoat            ||" << endl;
                cout << "\t           ===========================" << endl;
                cout << "\t***************************************************" << endl;
                TextColor(7);
                cout << "\t-> Lua chon cua ban (1-4): ";
                cin >> InputString;
                c1 = processInputString(InputString,4);
                Delete(c1);
                if(c1!=4) system("Pause");
            }while(c1 !=4);
            break;    
        }
        case 4:
        {   
            do{
                system("cls");
                TextColor(14);
                cout << "\t***********************THEM***********************" << endl;
                cout << "\t          ==============================" << endl;
                cout << "\t          ||    1. Them nhan vien     ||" << endl;
                cout << "\t          ||    2. Them chuc vu       ||" << endl;
                cout << "\t          ||    3. Them phong ban     ||" << endl;
                cout << "\t          ||    4. Thoat              ||" << endl;
                cout << "\t          ==============================" << endl;
                cout << "\t**************************************************" << endl;
                TextColor(7);
                cout << "\t-> Lua chon cua ban (1-4): ";
                cin >> InputString;
                c1 = processInputString(InputString,4);
                Add(c1);
                if(c1!=4) system("Pause");
            }while(c1!=4);
            break;
        }
        case 5:
        {
            do{
                system("cls");
                TextColor(14);
                cout << "\t**************************CHINH SUA**************************" << endl;
                cout << "\t           ===================================" << endl;;
                cout << "\t           ||     1. Chinh sua nhan vien    ||" << endl;
                cout << "\t           ||     2. Chinh sua chuc vu      ||" << endl;
                cout << "\t           ||     3. Chinh sua phong ban    ||" << endl;
                cout << "\t           ||     4. Thoat                  ||" << endl;
                cout << "\t           ===================================" << endl; 
                cout << "\t*************************************************************" << endl;
                TextColor(7);
                cout << "\t-> Lua chon cua ban (1-4): ";
                cin >> InputString;
                c1 = processInputString(InputString,4);
                Update(c1);
                if(c1!=4) system("Pause");
            }while(c1 != 4);
            break;
        }
        case 6:
        {
            do{
                system("cls");
                TextColor(14);
                cout << "\t**************************TIM KIEM**************************" << endl;
                cout << "\t     ===================================================" << endl;
                cout << "\t     ||    1. Tim kiem nhan vien theo ma nhan vien    ||" << endl;
                cout << "\t     ||    2. Tim kiem nhan vien theo chuc vu         ||" << endl;
                cout << "\t     ||    3. Tim kiem nhan vien theo phong ban       ||" << endl;
                cout << "\t     ||    4. Tim kiem chuc vu theo phong ban         ||" << endl;
                cout << "\t     ||    5. Tim kiem chuc vu                        ||" << endl;
                cout << "\t     ||    6. Tim kiem phong ban                      ||" << endl;
                cout << "\t     ||    7. Thoat                                   ||" << endl;
                cout << "\t     ===================================================" << endl;
                cout << "\t************************************************************" << endl;
                TextColor(7);
                cout << "\t-> Lua chon cua ban (1-7): ";
                cin >> InputString;
                c1 = processInputString(InputString,7);
                Search(c1);
                if(c1!=7) system("Pause");
            }while(c1 != 7);
            break;
        }
        case 7:
        {
            do{
                system("cls");
                TextColor(14);
                cout << "\t****************************THONG KE****************************" << endl;
                cout << "\t      ======================================================" << endl;
                cout << "\t      ||    1. In ra thong ke nhan vien theo chuc vu      ||" << endl;
                cout << "\t      ||    2. In ra thong ke nhan vien theo phong ban    ||" << endl;
                cout << "\t      ||    3. In ra thong ke nhan vien cua ca nha hang   ||" << endl;
                cout << "\t      ||    4. In ra tat ca thong ke                      ||" << endl;
                cout << "\t      ||    5. Thoat                                      ||" << endl;
                cout << "\t      ======================================================" << endl;
                cout << "\t****************************************************************" << endl;
                TextColor(7);
                cout << "\t-> Lua chon cua ban (1-5): ";
                cin >> InputString;
                c1 = processInputString(InputString,5);
                Statistic(c1);
                if(c1 !=5) system("Pause");
            }while(c1 != 5);
            break;
        }
        case 8:
        {
            do{
                system("cls");
                TextColor(14);
                cout << "\t************************PHAT & THUONG***********************" << endl;
                cout << "\t            ===============================" << endl;
                cout << "\t            ||    1. Phat                ||" << endl;
                cout << "\t            ||    2. Thuong              ||" << endl;
                cout << "\t            ||    3. Thoat               ||" << endl;
                cout << "\t            ===============================" << endl; 
                TextColor(7);
                cout << "\t-> Lua chon cua ban (1-3): ";
                cin >> InputString;
                c1 = processInputString(InputString,4);
                Fine(c1);
                cout << "\t************************************************************" << endl;
                if(c1!= 3) system("Pause");    
            }while(c1 != 3);
            break;
        }
        case 9:
        {
            do{
                system("cls");
                TextColor(14);
                cout << "\t**********************CHINH SUA NGAY DI LAM**********************" << endl;
                cout << "\t            =======================================" << endl;
                cout << "\t            ||    1. Nhap lai so ngay di lam     ||" << endl;
                cout << "\t            ||    2. Tang them ngay di lam       ||" << endl;
                cout << "\t            ||    3. Giam so ngay di lam         ||" << endl;
                cout << "\t            ||    4. Thoat                       ||" << endl;
                cout << "\t            =======================================" << endl; 
                cout << "\t*****************************************************************" << endl;
                TextColor(7);
                cout << "\t-> Lua chon cua ban (1-4): ";
                cin >> InputString;
                c1 = processInputString(InputString,4);
                EditSalary(c1);
                if(c1!=4) system("Pause");
            }while(c1 != 4);
            break;
        }
        case 10:
        {
            system("cls");
            cout << "\t******************RESET TAI KHOAN MAT KHAU******************" << endl;
            Reset();
            TextColor(2);
            cout << "\t   ======== RESET TAI KHOAN MAT KHAU THANH CONG ========" << endl;
            TextColor(7);
            cout << "\t************************************************************" << endl;
            system("Pause");
        }
    }
}

void Menu(){
    int choose = 20;
    do{    
        system("cls");
        TextColor(9);
        cout << endl;
        cout << "\t==================================================================================================" << endl;
        cout << "\t\t\t\t    QUAN LY NHAN VIEN TRONG NHA HANG " << endl;
        cout << "\t\t\t\t\t\t\t      Da Nang, Ngay " << PresentDate << ", Thang " << PresentMonth << ", Nam " << PresentYear << endl;
        cout << "\t\t\t\t\t\tMENU" << endl;
        TextColor(6);
        cout << "\t\t\t\t==========================================" << endl;
        cout << "\t\t\t\t||     1.  In danh sach                 ||" << endl;
        cout << "\t\t\t\t||     2.  Sap xep                      ||" <<endl;
        cout << "\t\t\t\t||     3.  Xoa                          ||" << endl;
        cout << "\t\t\t\t||     4.  Them                         ||" << endl;
        cout << "\t\t\t\t||     5.  Chinh sua                    ||" << endl;
        cout << "\t\t\t\t||     6.  Tim kiem                     ||" << endl;
        cout << "\t\t\t\t||     7.  In ra bang thong ke          ||" << endl;
        cout << "\t\t\t\t||     8.  Phat va Thuong               ||" << endl;
        cout << "\t\t\t\t||     9.  Chinh sua so ngay di lam     ||" << endl;
        cout << "\t\t\t\t||     10. Doi mat khau                 ||" << endl;
        cout << "\t\t\t\t||     11. Thoat                        ||" << endl;
        cout << "\t\t\t\t==========================================" << endl;
        TextColor(9);
        cout << "\t==================================================================================================" << endl;
        TextColor(7);
        cout << "\t-> Lua chon cua ban la (1-11): ";
        cin >> InputString;
        choose = processInputString(InputString,11);
        Decide(choose);
    }while(choose != 11);
}
