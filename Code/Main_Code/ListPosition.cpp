#include "ListPosition.h"
#ifndef LISTPOSITION_CPP
#define LISTPOSITION_CPP

ListPosition::ListPosition(string){

}

ListPosition::ListPosition(){
    string ID;
    string Name;
    int A;
    long long M;
    ifstream file;
    file.open("./Data/Position.txt");
    while(!file.eof()){
        getline(file,Name,'-');
        file.ignore();
        getline(file,ID,'-');
        file.ignore();
        file >> A;
        file >> M;
        file.ignore();
        Position temp(A,M,Name,ID);
        this->Add(temp);
    }
    file.close();
}

ListPosition::~ListPosition(){
    
}

void ListPosition::Add(const Position& P1){
    table.addToTable(P1);
}

void ListPosition::Delete(const string & ID){
    table.delFromTable(ID);
}

void ListPosition::ShowWithMD(){
    cout << "||";
    for(int i=1;i<=25;i++)
        cout << " ";
    cout << "THONG TIN CHUC VU";
    for(int i=1;i<=25;i++)
        cout << " ";
    cout << "||" << endl;
    cout << "||";
    for(int i=1;i<=67;i++)
        cout << "_";
    cout << "||" <<endl;
    cout << "|| ID   | Ten chuc vu";
    for(int i=1;i<=13;i++){
        cout << " ";
    }
    cout << "| Phu cap (%) | Luong (nghin/Dong) ||" << endl;
    cout << "||______|_________________________|_____________|____________________||" << endl;
    table.traverseTable();
}

void ListPosition::Show(){
    TextColor(3);
    for(int i=1;i<=71;i++){
        cout << "_";
    }cout << endl;
    cout << "|| ID   | Ten chuc vu";
    for(int i=1;i<=13;i++){
        cout << " ";
    }
    cout << "| Phu cap (%) | Luong (nghin/Dong) ||" << endl;
    cout << "||______|_________________________|_____________|____________________||" << endl;
    table.traverseTable();
    TextColor(7);
}

int ListPosition::Update(string ID,int choose){
    switch (choose)
    {
        case 1:
        {   
            Position temp;
            string Name1;
            cout << "\t*******************************" << endl;
            cout << "\tID : " << ID << endl;
            cout << "\tNhap ten vi tri moi: ";
            cin.ignore();
            getline(cin,Name1);
            cout << "\t*******************************" << endl;
            temp = this->Search(ID);
            temp.setPoName(Name1);
            this->Delete(ID);
            this->Add(temp);
            TextColor(2);
            cout << "\t\t\t---------------THONG BAO---------------" << endl;
            cout << "\t\t\t   Thong tin da duoc cap nhap !! " << endl;
            cout << "\t\t\t---------------------------------------" << endl;
            TextColor(3);
            this->Search(ID).Show();
            TextColor(7);
            break;
        }
        case 2:
        {   
            Position temp;
            long long money;
            cout << "\t*******************************" << endl;
            cout << "\tID : " << ID << endl;
            cout << "\tNhap Luong moi (nghin dong/ngay): ";
            cin >> money;
            cout << "\t*******************************" << endl;
            temp = this->Search(ID);
            temp.setMoney(money);
            this->Delete(ID);
            this->Add(temp);
            TextColor(2);
            cout << "\t\t\t---------------THONG BAO---------------" << endl;
            cout << "\t\t\t   Thong tin da duoc cap nhap !! " << endl;
            cout << "\t\t\t---------------------------------------" << endl;
            TextColor(3);
            this->Search(ID).Show();
            TextColor(7);
            break;
        }
        case 3:
        {   
            Position temp;
            int allowance;
            cout << "*******************************" << endl;
            cout << "ID: " << ID << endl;
            cout << "Nhap phu cap moi (%): ";
            cin >> allowance;
            cout << "*******************************" << endl;
            temp = this->Search(ID);
            temp.setAllowance(allowance);
            this->Delete(ID);
            this->Add(temp);
            TextColor(2);
            cout << "\t\t\t---------------THONG BAO---------------" << endl;
            cout << "\t\t\t   Thong tin da duoc cap nhap !! " << endl;
            cout << "\t\t\t---------------------------------------" << endl;
            TextColor(3);
            this->Search(ID).Show();
            TextColor(7);
            break;
        }
        case 4:
        {   
            Position temp;
            long long money;
            string Name1;
            int allowance;
            cout << "\t*******************************" << endl;
            // Xu ly ID
            cout << "\tID chuc vu: " << ID << endl;
            // Xu ly Name
            cout << "\tNhap ten chuc vu moi: ";
            cin.ignore();
            getline(cin,Name1);
            cout << "\tNhap luong ( nghin dong/ngay ): ";
            cin >> money;
            cout << "\tNhap phu cap (% ): ";
            cin >> allowance;
            cout << "\t*******************************" << endl;
            temp = Position(allowance,money,Name1,ID);
            this->Delete(ID);
            this->Add(temp);
            TextColor(2);
            cout << "\t\t\t---------------THONG BAO---------------" << endl;
            cout << "\t\t\t   Thong tin da duoc cap nhap !! " << endl;
            cout << "\t\t\t---------------------------------------" << endl;
            TextColor(3);
            this->Search(ID).Show();
            TextColor(7);
            break;
        }
        default:
        {
            cout << "--------------Chinh sua thong tin------------" << endl;
            cout << "1.      Sua Name   " << endl;
            cout << "2.   Sua tien luong " << endl;
            cout << "3.     Sua phu cap  " << endl;
            cout << "4.       Sua het " << endl;
            cout << "Lua chon cua ban (1-4): ";
            int choosenew;
            cin >> choosenew;
            cout << "---------------------------------------------" << endl;
            this->Update(ID,choosenew);
            break;
        }
    }
}

void ListPosition::InputData(){
    string ID;
    string Name;
    int A;
    long long M;
    ifstream file;
    file.open("./Data/Position.txt");
    while(!file.eof()){
        getline(file,Name,'-');
        file.ignore();
        getline(file,ID,'-');
        file.ignore();
        file >> A;
        file >> M;
        file.ignore();
        Position temp(A,M,Name,ID);
        this->Add(temp);
    }
    file.close();
}

void ListPosition::OutData(){
    ofstream file;
    file.open("./Data/Position.txt");
    for(int i=0;i<table.getSize();i++){
        for(int j=0;j<table[i].listLength();j++){
            file << table[i][j].getPoName() << "- ";
            file << table[i][j].getID() << "-\t";
            file << table[i][j].getAllowance() << "\t";
            file << table[i][j].getMoney() << "\n";
        }
    }
    file.close();
}

ListPosition ListPosition::SearchByMD(const string & IDMD5){
    ListPosition LP10(" ");
    Position temp;
    for(int i=0;i<table.getSize();i++){
        for(int j=0;j<table[i].listLength();j++){
            if (table[i][j].getIDMD() == IDMD5)
            {   
                temp = table[i][j];
                LP10.Add(temp);
            }
        }
    }
    return LP10;
}

Position ListPosition::Search (string ID){
    return table.findInTable(ID);
}

bool ListPosition::Exis(string ID4){
    return table.Exis(ID4);
}

bool ListPosition::CheckID(string ID5){
    if(ID5.size() != 4) return false;
    int col = this->table.hashFunction(ID5);
    if(table[col].findNode(ID5) != -1) return false;
    return true;
}

int ListPosition::CountByMD(string IDMDP){
    int count =0;
    for(int i=0;i<table.getSize();i++){
        for(int j=0;j<table[i].listLength();j++){
            if (table[i][j].getIDMD() == IDMDP){ 
                count++; 
            }
        }
    }return count;
}

void ListPosition::DeleteByMD(string IDMDP){
    // Tìm ra danh sách tất cả các vị trí có trong phòng ban đó
    ListPosition temp = this->SearchByMD(IDMDP);
    // Tiến hành xoá lần lượt các vị trí có trong danh sách
    for(int i=0;i<temp.table.getSize();i++){
        for(int j=0;j<temp.table[i].listLength();j++){
            this->Delete(temp.table[i][j].getID());
        }
    }
}


#endif //END LISTPOSITION_CPP