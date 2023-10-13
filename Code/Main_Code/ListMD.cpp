#include "ListMD.h"
#ifndef LISTMD_CPP
#define LISTMD_CPP

ListMD::ListMD(string h){

}

ListMD::ListMD(){
    string Name;
    string ID;
    ifstream file;
    file.open("./Data/ManagermentDepartment.txt");
    while(!file.eof()){
        getline(file,Name,'-');
        file.ignore();
        getline(file,ID,'\n');
        MD temp(Name,ID);
        this->Add(temp);
    }

    file.close();
}

void ListMD::InputData(){
    string Name;
    string ID;
    ifstream file;
    file.open("./Data/ManagermentDepartment.txt");
    while(!file.eof()){
        getline(file,Name,'-');
        file.ignore();
        getline(file,ID,'\n');
        MD temp(Name,ID);
        this->Add(temp);
    }

    file.close();
}

ListMD::~ListMD(){

}

void ListMD::Add(const MD& P1){
    table.addToTable(P1);
}

void ListMD::Delete(const string & ID){
    table.delFromTable(ID);
}

void ListMD::Show(){
    TextColor(3);
    for(int i=1;i<=49;i++){
        cout << "_";
    }cout << endl;
    cout << "|| ID | Ten phong ban";
    for(int i=1;i<=26;i++){
        cout << " ";
    }cout << "||" << endl;
    cout << "||____|";
    for(int i=1;i<=40;i++){
        cout << "_";
    }cout << "||" << endl;
    table.traverseTable();
    TextColor(7);
}

void ListMD::Update(string ID, int choose)
{
    string Name1;
    cout << "\t*****************************" << endl;
    cout << "\tID phong ban: " << ID << endl;
    cout << "\tNhap ten phong ban moi: ";
    getline(cin, Name1);
    cout << "\t*****************************" << endl;
    MD temp = this->Search(ID);
    temp.setMDName(Name1);
    this->Delete(ID);
    this->Add(temp);
    TextColor(2);
    cout << "\t\t\t---------------THONG BAO---------------" << endl;
    cout << "\t\t\t   Thong tin da duoc cap nhap !! " << endl;
    cout << "\t\t\t---------------------------------------" << endl;
    TextColor(3);
    this->Search(ID).Show();
    TextColor(7);
}

void ListMD::OutData(){
    ofstream file;
    file.open("./Data/ManagermentDepartment.txt");
    for(int i=0;i<table.getSize();i++){
        for(int j=0;j<table[i].listLength();j++){
            file << table[i][j].getMDName() << "- ";
            file << table[i][j].getID() << "\n";
        }
    }
    file.close();
}

MD ListMD::Search(string ID){
    return table.findInTable(ID);
}

bool ListMD::Exis(string ID4){
    return table.Exis(ID4);
}

bool ListMD::CheckID(string ID5){
    if(ID5.size() != 2) return false;
    int col = table.hashFunction(ID5);
    if(table[col].findNode(ID5) != -1) return false;
    return true;
}

#endif  //END LISTMD_CPP