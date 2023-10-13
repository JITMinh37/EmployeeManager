#include "Employee.h"
#ifndef EMPLOYEE_CPP
#define EMPLOYEE_CPP

Employee::Employee(){
    this->Day = 0;
    this->Money = 0;
    this->Allowance = 0;
    this->Fine = 0;
    this->ID = "";
    this->Name = "";
    this->Tel = "";
    this->CCCD = "";
    this->Add = "";
    this->Sex = false;
    this->birthDate.setNull();
}

Employee::Employee(string ID, string Name, string Tel,string CCCD ,string Add ,bool Sex, Date birthDate,int day,long long money,int allowance,long long fine) : Person(ID ,Name ,Tel ,CCCD ,Add ,Sex ,birthDate){
    this->Day = day;
    this->Allowance = allowance;
    this->Fine = fine;
    this->Money = money;
}

Employee::Employee(const Person& Ps1,int Day,int allowance,long long money, long long fine) : Person(Ps1){
    this->Day = Day;
    this->Allowance = allowance;
    this->Money = money;
    this->Fine = fine;
}

Employee::~Employee(){

}

//setFunction
void Employee::setDay(int Day){
    if( Day>=0 && Day <= tinhSoNgayTrongThang(PresentMonth,PresentYear))
        this->Day = Day;
    else{
        TextColor(4);
        cout << "\t\t\t--------------THONG BAO-------------" << endl;
        cout << "\t\t\t  So ngay ban nhap vao khong hop le "  << endl;
        cout << "\t\t\t------------------------------------" << endl;
        TextColor(7);
    }
}

void Employee::setMoney(long long Money){
    this->Money = Money;
}

void Employee::setAllowance(int Allowance){
    this->Allowance = Allowance;
}

void Employee::setFine(long long Fine){
    this->Fine = Fine;
}

//getFunction
int Employee::getDay(){
    return this->Day;
}

long long Employee::getMoney(){
    return this->Money;
}

int Employee::getAllowance(){
    return this->Allowance;
}

long long Employee::getFine(){
    return this->Fine;
}

//Calculate SalaryFunction
long long Employee::Salary(){
    return Day*Money + Allowance*(Day*Money)/100 + Fine;
}

//ShowFunction
int CountNum1(int N){
    int count = 1;
    while (N/10>0){
        count++;
        N /= 10;
    }
    return count;
}

void Employee::ShowBySearch(){
    cout << "_______________________________________________________________________________________________________________________________________________" << endl;
    cout << "|| ID      | Ten nhan vien           | Chuc vu                 | Phong ban               | So ngay di lam | Tien phat | Luong ( nghin dong ) ||" << endl;
    cout << "||_________|_________________________|_________________________|_________________________|________________|___________|______________________||" << endl;
    cout << "|| " << this->ID << " | " << this->Name;
    for(int i=1;i<=24-this->Name.size();i++)
        cout << " ";
    cout << "| " << this->NPoistion;
    for(int i=1;i<=24-this->NPoistion.size();i++)
        cout << " ";
    cout << "| " << this->NMD;
    for(int i=1;i<=24-this->NMD.size();i++)
        cout << " ";
    cout << "| " << this->Day;
    for(int i=1;i<=15-CountNum1(this->Day);i++)
        cout << " ";
    cout << "| " << this->Fine;
    for(int i=1;i<=10-CountNum1(this->Fine);i++)
        cout << " ";
    cout << "| " << this->Salary();
    for(int i=1;i<=21-CountNum1(this->Salary());i++)
        cout << " ";
    cout << "||" << endl;
    cout << "||_________|_________________________|_________________________|_________________________|________________|___________|______________________||" << endl;
}

void Employee::Show(int k){
    TextColor(3);
    int i,j;
    for(i=1;i<=66;i++){
        cout << "_";
    }
    cout << endl;
    cout << "||";
    cout << " STT |  MSNV   |  Ho va ten ";
    for(i=1;i<=13;i++){
        cout << " ";
    }cout << "| Luong (nghin/Dong) ||" << endl;
    cout << "||_____|_________|_________________________|____________________||" << endl;

    cout << "|| " << k+1;
    for(i=1;i<=4-CountNum1(k+1);i++){
        cout << " ";
    }
    cout << "| " << getIDPerson() << " | " << getName();
    for(j=1;j<=24-getName().size();j++){
        cout << " ";
    }cout <<"| " << this->Salary();
    for(i=1;i<= 19-CountNum1(Salary());i++){
        cout << " ";
    }cout << "||" << endl;
    cout << "||_____|_________|_________________________|____________________||" << endl;
    TextColor(7);
}

//Multiplication of Operators

istream& operator>> (istream& i,Employee& Ps1){
    cout << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Nhap thong tin nhan vien " << endl;
    cout << "MSNV: "; getline(i,Ps1.ID);
    cout << "Ten: "; getline(i,Ps1.Name);
    cout << "Ngay Sinh: ";i >> Ps1.birthDate;
    cout << "CMND: "; i.ignore(); getline(i,Ps1.CCCD);
    cout << "SDT: "; getline(i, Ps1.Tel);
    cout << "Dia chi: "; getline(i, Ps1.Add);
    cout << "Gioi tinh (Nam:1/Nu:0): "; i >> Ps1.Sex;
    cout << "So ngay lam: "; i >> Ps1.Day;
    cout << "Luong (nghin Dong/h): "; i >> Ps1.Money;
    cout << "Tro cap (%): "; i>> Ps1.Allowance;
    cout << "Tien phat(nghin Dong): "; i>> Ps1.Fine;
    cout << "----------------------------------------------------" << endl;
    return i;
}

ostream& operator<< (ostream& o,Employee& Ps1){
    o << "MSNV: " << Ps1.ID;
    o << "\tTen: " << Ps1.Name;
    o << "\tPhu cap: " << Ps1.Allowance;
    o << "\tSo ngay: " << Ps1.Day;
    o << "\tLuong (nghin dong/ngay): " << Ps1.Money;
    o <<"\tThuc linh : " << Ps1.Salary() << "000 ( Dong )" << endl;
}

#endif  //END EMPLOYEE_CPP
