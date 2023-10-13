#include "Person.h"
#ifndef PERSON_CPP
#define PERSON_CPP

Person::Person(string ID, string Name, string Tel,string CCCD ,string Add ,bool Sex, Date birthDate) : birthDate(birthDate){
    this->ID = ID;
    this->Name = Name;
    this->Tel = Tel;
    this->Sex = Sex;
    this->CCCD = CCCD;
    this->Add = Add;
}

Person::~Person(){}

// Check Function 
bool Person::checkCCCD(const string& CCCDCheck){
    if(CCCDCheck.size() != 12)
        return false;
    return true;
}

bool Person::checkTel(const string& TelCheck){
    if(TelCheck[0] != '0')
        return false;
    if(TelCheck.size() != 10)
        return false;
    return true;
}

// Show Function
void Person::Show(int k){
    int i,j;
    for(i=1;i<=129;i++){
        cout << "_";
    }cout << endl;
    cout << "||";
    cout << " STT |  MSNV   |  Ho va ten ";
    for(i=1;i<=13;i++){
        cout << " ";
    }cout << "| Ngay sinh  | CCCD";
    for(i=1;i<=9;i++){
        cout << " ";
    }
    cout << "| Gioi tinh | SDT";
    for(i=1;i<=8;i++){
        cout << " ";
    }cout << "| Dia chi";
    for(i=1;i<=22;i++){
        cout << " ";
    }cout << "||" << endl;
    cout << "||_____|_________|_________________________|____________|______________|___________|____________|______________________________||" << endl;
    

    cout << "|| " << k+1;
    int count = 0 ;
    if(k+1<10){
        cout << "   |";
    }else if(k+1<100 && k+1>=10){
        cout << "  |";
    }else{
        cout << " |";
    }cout << " " << getIDPerson() << " | " << getName();
    for(j=1;j<=24-getName().size();j++){
        cout << " ";
    }cout << "| " << getBirthDate();
    if(getBirthDate().getDay()<10) cout << " ";
    if(getBirthDate().getMonth()<10) cout <<"  | ";
    else cout << " | ";
    cout << getCCCD();
    for(j=1;j<=13 - getCCCD().size();j++){
        cout << " ";
    }cout <<"|";
    if(getSex()==1){
        cout <<"  Nam      |";
    }else{
        cout <<"  Nu       |";
    }cout << " " << getTel() << " | " << getAdd();
    for(int j=1;j<=29 - getAdd().size();j++){
        cout << " ";
    }cout << "||" << endl;
    cout << "||_____|_________|_________________________|____________|______________|___________|____________|______________________________||" << endl;

}

istream& operator>> (istream& i,Person& Ps1){
    std::cout << "----------------------------------------------------------"<< endl;
    i.ignore();
    std::cout << "Nhap thong tin nhan vien: " << endl;
    std::cout << "MSNV: "; getline(i,Ps1.ID);
    std::cout << "Ten: "; getline(i,Ps1.Name);
    std::cout << "Ngay Sinh: ";i >> Ps1.birthDate;
    std::cout << "CMND: "; i.ignore(); getline(i,Ps1.CCCD);
    std::cout << "SDT: "; getline(i, Ps1.Tel);
    std::cout << "Address: "; getline(i, Ps1.Add);
    std::cout << "Gioi tinh (Nam:1/Nu:0): "; i >> Ps1.Sex;
    std::cout << "----------------------------------------------------------"<< endl;
    return i;
}

ostream& operator<< (ostream& o,const Person& Ps1){
    o << "-----------------------------------" << endl;
    o << "MSNV: " << Ps1.ID;
    o << "\t\tTen: " << Ps1.Name;
    o << "\tNgay Sinh: " << Ps1.birthDate;
    o << "\tCMND: " << Ps1.CCCD;
    o << "\t\tSDT: " << Ps1.Tel;
    o << "\t\tAddress: " << Ps1.Add;
    if(Ps1.Sex == true){
        o << "\t\tGioi tinh: Nam";
    }else
        o << "\t\tGioi tinh: Nu";
    std::cout << "-----------------------------------" << endl;
}

// SetFunction
void Person::setID(string ID){
    this->ID = ID;
}

void Person::setTel(string Tel){
    this->Tel = Tel;
}

void Person::setName(string Name){
    this->Name = Name;
}

void Person::setCCCD(string CCCD){
    this->CCCD = CCCD;
}

void Person::setAdd(string Add){
    this->Add = Add;
}

void Person::setSex(bool Sex){
    this->Sex = Sex;
}

void Person::setBirthDate(Date BirthDate){
    this->birthDate = BirthDate;
}

void Person::setNPosition(string NPosition){
    this->NPoistion = NPosition;
}

void Person::setNMD(string NMD){
    this->NMD = NMD;
}

// GetFunction

string Person::getIDPosition(){
    string f = this->ID.substr(0,4);
    return f;
}

string Person::getIDPerson(){
    return this->ID;
}

string Person::getIDMD(){
    string f = this->ID.substr(0,2);
    return f;
}

string Person::getTel(){
    return this->Tel;
}

string Person::getName(){
    return this->Name;
}

string Person::getCCCD(){
    return this->CCCD;
}

string Person::getAdd(){
    return this->Add;
}

bool Person::getSex(){
    return this->Sex;
}

Date Person::getBirthDate(){
    return this->birthDate;
}

string Person::getNPosition(){
    return this->NPoistion;
}

string Person::getNMD(){
    return this->NMD;
}

#endif  //END PERSON_CPP