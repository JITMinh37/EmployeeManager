#include "Position.h"
#ifndef POSITION_CPP
#define POSITION_CPP

// Construction & Destruction Function
Position::Position(int Allowance,long long Money,string PositionName,string PositionID){
    this->Allowance = Allowance;
    this->Money = Money;
    this->PositionID = PositionID;
    this->PositionName = PositionName;
}

Position::~Position(){

}

// Set Function

void Position::setAllowance(int Allowance){
    this->Allowance = Allowance;
}

void Position::setMoney(long long Money){
    this->Money = Money;
}

void Position::setPoID(string PoID){
    this->PositionID = PoID;
}

void Position::setPoName(string PoName){
    this->PositionName = PoName;
}

//get Function

int Position::getAllowance(){
    return this->Allowance;
}

long long Position::getMoney(){
    return this->Money;
}

string Position::getID(){
    return this->PositionID;
}

string Position::getPoName(){
    return this->PositionName;
}

string Position::getIDMD(){
    string f = this->PositionID.substr(0,2);
    return f;
}

//Multiplication of Operator
istream& operator>> (istream& i,Position& P1){
    i.ignore();
    cout << "=============================================" << endl;
    cout << "Nhap thong tin Chuc vu: " << endl;
    cout << "Ma chuc vu: ";
    getline(i,P1.PositionID);
    cout << "Ten chuc vu: "; 
    getline(i,P1.PositionName);
    cout << "Luong (nghin Dong/ngay): ";
    i >> P1.Money;
    cout << "Phu cap (%): ";
    i >> P1.Allowance;
    cout << "=============================================" << endl;
    return i;
}

int CountNum(int N){
    int count = 1;
    while (N/10>0){
        count++;
        N /= 10;
    }
    return count;
}

ostream& operator <<(ostream& o, const Position& p1){
    int i;
    o <<"|| " << p1.PositionID << " | " << p1.PositionName;
    for(int i=1;i<= 24- p1.PositionName.size();i++){
        o << " ";
    }o << "| " << p1.Allowance;
    for(i=1;i<=12-CountNum(p1.Allowance);i++){
        o << " ";
    }o << "| " <<p1.Money;
    for(i=1;i<=19-CountNum(p1.Money);i++){
        o << " ";
    }o <<"||" <<endl;
    o << "||______|_________________________|_____________|____________________||" << endl;
    return o;
}

void Position::ShowWithEmployee(){
    int i,j;
    for(i=1;i<=129;i++){
        cout << "_";
    }cout << "\n||";
    for(int i=1;i<=54;i++){
        cout << " ";
    }cout << "THONG TIN CHUC VU";
    for(int i=1;i<=54;i++){
        cout << " ";
    }cout << "||" << endl;
    cout << "||";
    for(int i=1;i<=125;i++){
        cout << "_";
    }cout << "||" << endl;
    cout << "|| Ma chuc vu : " << this->PositionID << " | Ten chuc vu : " << this->PositionName;
    for(i=1;i<=37 - this->PositionName.length();i++){
        cout << " ";
    }cout << "| Luong (nghin dong/ngay) : " << this->Money;
    for(i =1;i<=6-CountNum(this->Money);i++){
        cout << " ";
    }
    cout << "| Tro cap (%) : " << this->Allowance;
    for(i=1;i<= 3- CountNum(this->Allowance);i++){
        cout << " ";
    }cout << "||" << endl;
    cout << "||___________________|____________________________________________________|_________________________________|__________________||" << endl;
}

void Position::Show(){
    for(int i=1;i<=71;i++){
        cout << "_";
    }cout << endl;
    cout << "|| ID   | Ten chuc vu";
    for(int i=1;i<=13;i++){
        cout << " ";
    }
    cout << "| Phu cap (%) | Luong (nghin/Dong) ||" << endl;
    cout << "||______|_________________________|_____________|____________________||" << endl;
    cout << *this;
}

int CountNum3(int N){
    int count = 1;
    while (N/10>0){
        count++;
        N /= 10;
    }
    return count;
}

void Position::ShowWithStatistic(int NOF,int NOM,long long SOF,long long SOM) const {
    cout << "||                   |                               |         " << NOM;
    for(int i=1;i<=11-CountNum3(NOM);i++)
        cout << " ";
    cout << "|         " << NOF;
    for(int i=1;i<=11-CountNum3(NOF);i++)
        cout << " ";
    cout << "|            " << SOM ;
    for(int i=1;i<=30-13-CountNum3(SOM);i++)
        cout << " ";
    cout << "|            " << SOF ;
    for(int i=1;i<=30-13-CountNum3(SOF);i++)
        cout << " ";
    cout << "||" << endl;
    cout << "||        " << this->PositionID << "       | " << this->PositionName;
    for(int i=1;i<= 30 - PositionName.size();i++){
        cout << " ";
    }
    cout << "|____________________|____________________|_____________________________|_____________________________||" << endl;
    cout << "||                   |                               | Tong so nhan vien : " << NOF + NOM;
    for(int i=1;i<=20-CountNum3(NOF+NOM);i++)
        cout << " ";
    cout << "| Tong Thu nhap theo chuc vu: " << SOF + SOM;
    for(int i=1;i<=30-CountNum3(SOF + SOM);i++)
        cout << " ";
    cout << "||" << endl;
    cout << "||___________________|_______________________________|_________________________________________|___________________________________________________________||" << endl;
}

#endif  // END POSTION_CPP