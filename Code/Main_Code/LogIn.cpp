#include "Date.cpp"
#include <string>
#include <fstream>
#include <conio.h>



void GiaoDienDangNhap(){
    system("cls");
    TextColor(6);
    cout << "\t\t\t\t\t  ****************************************************" << endl;
    cout << "\t\t\t\t\t             CHUONG TRINH QUAN LY NHAN VIEN" << endl;
    cout << "\t\t\t\t\t  ****************************************************" << endl;
    cout << endl;
    TextColor(9);
    cout << "\t\t\t\t         _______________________________________________________" << endl;
    cout << "\t\t\t\t         ||                                                   ||" << endl;
    cout << "\t\t\t\t         ||                   TRANG DANG NHAP                 ||" << endl;
    cout << "\t\t\t\t         ||                                                   ||" << endl;
    cout << "\t\t\t\t         ||___________________________________________________||" << endl;
    cout << endl;
    TextColor(7);
}

void GiaoDienKhoiDong(){
    system("cls");
    TextColor(6);
    cout << "\t\t\t\t\t             DO AN CO SO LAP TRINH" << endl;
    TextColor(7);
    cout << "\t\t\t===========================================================================" << endl;
    cout << "\t\t                DE TAI: QUAN LY NHAN VIEN NHA HANG" << endl;
    cout << "\t\t                Giao Vien Huong Dan: ThS.Do Thi Tuyet Hoa" << endl;
    cout << "\t\t                Ho Ten Sinh Vien 1: Nguyen Van Dung            Lop: 21TCLC_Nhat2" << endl;
    cout << "\t\t                Ho Ten Sinh Vien 2: Hoang Nguyen Nhat Minh     Lop: 21TCLC_Nhat2" << endl;
    cout << "\t\t                Nhom: 21NH99" << endl;
    cout << "\t\t\t===========================================================================" << endl;
    system("pause");
}

// Xu ly mat khau va tai khoan

char mk[50];
char realmk[50];
int sizerealmk = 5;
string realtk ;
string tk;
string realPassWord;

int InputPassWord(){
    int size;
    char x = 'l';
    size = 0;
    cout << "\t\tMat khau:  ";
    while ( x != 13) //Ki tu 13 la ki tu Enter.
    {
        x = getch(); // Lay ki tu x tu bo nho dem thong qua ham getch();
        if ( x == 13){ // Neu nhu gap Enter thi thoat vong lap
            break;
        }
        if (mk[0] == '\0'){ // Neu tai mk[0] gap ki tu dung thi thuc hien vong lap
            while (true)
            {
                x = getch(); 
                if (x != 8)
                    break;
            }
        }
        if(x==8)
        {
            if(size != 0)
            {
                mk[size] = '\0';
                size--;
                cout << "\b \b"; 
            }
        }else
        {
            cout << x;
            mk[size] = x;
            size ++;
            cout << "\b \b*";
        }
    }
    return size;
    mk[size] = '\0';
}

void InputUserName(){
    cout << "\t\tTai khoan: ";
    getline(cin,tk);

}

bool CheckPassWord(){
    int size = InputPassWord();
    if(sizerealmk != size)
        return false;
    for(int i=0;i<=sizerealmk;i++){
        if(mk[i] != realmk[i] )
            return false;
    }
    return true;
}

void TakeUserAndPass(){
    int size;
    ifstream file;
    file.open("./Data/Account.txt");
    string trash;
    string FileUser, FilePassWord;
    // Take Data's User and PassWord
    getline(file,trash,':');
    file.ignore();
    getline(file,FileUser,'\n');
    file.ignore();
    getline(file,trash,':');
    file.ignore();
    getline(file,FilePassWord,'\n');
    file.close();

    // assign for password and user
    realPassWord = FilePassWord;
    realtk = FileUser;
    sizerealmk = FilePassWord.size();
    for(int i=0;i<sizerealmk;i++)
        realmk[i] = FilePassWord[i];
}

void OutUserAndPass(){
    ofstream file;
    file.open("./Data/Account.txt");
    file << "Tai khoan : " << realtk << endl;
    file << "Mat khau : " << realPassWord ;
    file.close();
}

void Init()
{
    GiaoDienKhoiDong();
    GiaoDienDangNhap();
    TakeUserAndPass();
    InputUserName();
    //InputPassWord();
    while(!CheckPassWord() || tk != realtk){
        system("cls");
        GiaoDienDangNhap();
        TextColor(4);
        cout << "\n\t\tMat khau hoac tai khoan ban nhap vao khong hop le" << endl;
        TextColor(7);
        InputUserName();
        //InputPassWord();
    }
    cout << endl;
}