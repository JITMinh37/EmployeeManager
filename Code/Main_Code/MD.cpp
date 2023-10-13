#include "MD.h"
#ifndef MD_CPP
#define MD_CPP

MD::MD(string MDName,string MDID){
    this->MDName = MDName;
    this->ID = MDID;
}

MD::MD(const MD& MD1){
    this->MDName = MD1.MDName;
    this->ID = MD1.ID;
}

MD::~MD(){
}

// set Function
void MD::setMDName(string MDName){
    this->MDName = MDName;
}

void MD::setMDID(string MDID){
    this->ID = MDID;
}

// get Function
string MD::getMDName(){
    return this->MDName;
}

string MD::getID(){
    return this->ID;
}

// Function

void MD::ShowWithPosition(){
    for(int i=1;i<=71;i++)
        cout << "_";
    cout << "\n||";
    for(int i=1;i<=24;i++)
        cout << " ";
    cout << "THONG TIN PHONG BAN";
    for(int i=1;i<=24;i++)
        cout << " ";
    cout << "||" << endl;
    cout << "||";
    for(int i=1;i<=71-4;i++)
        cout << "_";
    cout << "||" << endl;
    cout << "|| Ma phong ban : " << this->ID << " | Ten phong ban : " << this->MDName;
    for(int i=1;i<=30 - this->MDName.size();i++)
        cout << " ";
    cout << "||" << endl;
    cout << "||___________________|_______________________________________________||" << endl;
}

void MD::ShowWithEmployee(){
    int i;
    for(i=1;i<=129;i++)
        cout << "_";
    cout << endl;
    cout << "||";
    for(i=1;i<=53;i++)
        cout << " ";
    cout << "THONG TIN PHONG BAN";
    for(int i=1;i<=53;i++)
        cout << " ";
    cout << "||" <<endl;
    cout << "||" ;
    for(int i=1;i<=125;i++)
        cout << "_";
    cout << "||" << endl;
    cout << "|| Ma so phong ban : " << this->ID << " | Ten phong ban : " << this->MDName;
    for(int i=1;i<= 85 - this->MDName.length();i++)
        cout << " ";
    cout << "||" << endl;
    cout << "||______________________|______________________________________________________________________________________________________||" << endl;
}

void MD::Show(){
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
    cout << *this;
}

// Multiplication of Operator
istream& operator>> (istream&i, MD& MD1){
    cout << "=============================================" << endl;
    cout << "Nhap Ten phong ban: "; getline(i,MD1.MDName);
    cout << "Nhap Ma Phong Ban: ";getline(i,MD1.ID);
    cout << "=============================================" << endl;
    return i;
}

ostream& operator<< (ostream& o,const MD& MD1){
    o << "|| " << MD1.ID << " | " << MD1.MDName;
    for(int i=1;i<=39-MD1.MDName.size();i++){
        o << " ";
    }
    o << "||" << endl;
    o << "||____|";
    for(int i=1;i<=40;i++){
                o << "_";
    }o << "||" << endl;
    return o;
}

int CountNum2(int N){
    int count = 1;
    while (N/10>0){
        count++;
        N /= 10;
    }
    return count;
}

void MD::ShowWithStatistic(int NOF,int NOM,long long SOF,long long SOM) {
    cout << "||                   |                               |         " << NOM;
    for(int i=1;i<=11-CountNum2(NOM);i++)
        cout << " ";
    cout << "|         " << NOF;
    for(int i=1;i<=11-CountNum2(NOF);i++)
        cout << " ";
    cout << "|            " << SOM ;
    for(int i=1;i<=30-13-CountNum2(SOM);i++)
        cout << " ";
    cout << "|            " << SOF ;
    for(int i=1;i<=30-13-CountNum2(SOF);i++)
        cout << " ";
    cout << "||" << endl;
    cout << "||         " << this->ID << "        | " << this->MDName;
    for(int i=1;i<= 30 - MDName.size();i++){
        cout << " ";
    }
    cout << "|____________________|____________________|_____________________________|_____________________________||" << endl;
    cout << "||                   |                               | Tong so nhan vien : " << NOF + NOM;
    for(int i=1;i<=20-CountNum2(NOF+NOM);i++)
        cout << " ";
    cout << "| Tong Thu nhap theo phong ban: " << SOF + SOM;
    for(int i=1;i<=28-CountNum2(SOF + SOM);i++)
        cout << " ";
    cout << "||" << endl;
    cout << "||___________________|_______________________________|_________________________________________|___________________________________________________________||" << endl;
}

#endif  //END MD_CPP