#include "ListEmployee.h"
#pragma once
#ifndef LISTEMPLOYEE_CPP
#define LISTEMPLOYEE_CPP


/*------------Construction&Destruction Function----------*/
ListEmployee::ListEmployee(){
    this->p = nullptr;
    this->length = 0;
}

ListEmployee::ListEmployee(Employee* Employees,int length){
    this->length = length;
    p = new Employee[this->length];
    for(int i=0;i<this->length;i++){
        p[i] = Employees[i];
    }
}

ListEmployee::~ListEmployee(){
    delete [] p;
}

/*-------------Set&Get Function------------------*/
void ListEmployee::setLength(int length){
    this->length = length;
}

int ListEmployee::getLength(){
    return this->length;
}

void ListEmployee::getMoney(ListPosition LP1){
    for(int i=0;i < this->length;i++){
        Position temp = LP1.Search(p[i].getIDPosition());
        p[i].setNPosition(temp.getPoName());
        p[i].setAllowance(temp.getAllowance());
        p[i].setMoney(temp.getMoney());
    }
}

void ListEmployee::getMD(ListMD LMD1){
    for(int i=0;i<this->length;i++){
        MD temp = LMD1.Search(p[i].getIDMD());
        p[i].setNMD(temp.getMDName());
    }
}

/*-----------Multiplication of operator----------*/
Employee& ListEmployee::operator[](const int& index){
    static Employee t;
    if(index>=0 && index<this->length){
        return *(this-> p + index);
    }
    else return t;
}

istream& operator>>(istream& in, ListEmployee& l){
    while(l.length <= 0){
        cout << "Nhap vao so nhan vien: ";
        in >> l.length;
    }
    l.p = new Employee[l.length];
    for(int i = 0; i < l.length; i++){
        cout << "Nhan vien thu " << i+1 << endl;
        in >> l[i];
    }
    return in;
}

ostream& operator<<(ostream& o, ListEmployee& l){
    TextColor(3);
    int i,j;
    for(i=1;i<=119;i++){
        cout << "_";
    }
    cout << endl;
    cout << "||";
    cout << " STT |  MSNV   |  Ho va ten ";
    for(i=1;i<=13;i++){
        cout << " ";
    }cout << "| So ngay | Tien P&T  | Phu cap |  nghin dong/ngay   ";
    cout << "| Luong (nghin dong) ||" << endl;
    cout << "||_____|_________|_________________________|_________|___________|_________|____________________|____________________||" << endl ;

    for(int k=0;k<l.length;k++){
        cout << "|| " << k+1;
        for(i=1;i<=4-CountNum(k+1);i++){
            cout << " ";
        }
        cout << "| " << l[k].getIDPerson() << " | " << l[k].getName();
        for(j=1; j<=24- l[k].getName().size() ;j++){
            cout << " ";
        }
        cout << "| " << l[k].getDay();
        for(j=1; j<=8-CountNum(l[k].getDay()) ; j++){
            cout << " ";
        }
        cout << "| " << l[k].getFine();
        for(j=1;j<=10 - CountNum(l[i].getFine());j++){
            cout << " ";
        }
        cout << "| " << l[k].getAllowance();
        for(j=1;j<=8-CountNum(l[k].getAllowance());j++){
            cout << " ";
        }
        cout << "| " << l[k].getMoney();
        for(j=1;j<=19 - CountNum(l[k].getMoney());j++){
            cout << " ";
        }
        cout << "| " << l[k].Salary();
        for(i=1;i<= 19-CountNum(l[k].Salary());i++){
            cout << " ";
        }cout << "||" << endl;
            cout << "||_____|_________|_________________________|_________|___________|_________|____________________|____________________||" << endl ;
    }
    TextColor(7);
}

/*-----------------Function-------------------*/
// Insert Function
void ListEmployee::InsertAt(const Employee& BookI,int k){
    this->length ++;

    Employee *temp = new Employee[this->length];

    for(int i = this->length-1 ; i> k; i--){           // process right
            *(temp+i) = *(p+i-1);
    }

    for(int i=0 ; i< k ; i++){                        // process left
        *(temp+i) = *(p+i);
    }
    *(temp+k) = BookI;

    delete[] p;
    p = new Employee[this->length];

    for(int i=0;i<length;i++){      //copy from temp to p
        *(p+i) = *(temp+i);
    }
    delete[] temp;
}

void ListEmployee::InsertAtLast(const Employee& BookI){
    this->InsertAt(BookI,this->length);
}

void ListEmployee::Insert(const string& ID1){
    int VT = this->Search(ID1);
    if(VT != -1){
        TextColor(4);
        cout << "\t\t\t------------------THONG BAO---------------------" << endl;
        cout << "\t\t\t   Ma nhan vien nay da co trong danh sach !!" << endl;
        cout << "\t\t\t------------------------------------------------" << endl;
        TextColor(7);
    }else{
        Employee temp;
        temp.ID = ID1;
        cout << "------------------------------------" << endl;
        cout << "Moi nhap thong tin nhan vien: " << endl;
        cout << "MSNV: " << ID1 << endl;
        cin.ignore();
        cout << "Ten: ";  getline(cin,temp.Name);
        cout << "Ngay Sinh";cin >> temp.birthDate;
        cout << "CCCD: ";  cin.ignore(); getline(cin,temp.CCCD);
        while(temp.checkCCCD(temp.CCCD) == false){
            TextColor(4);
            cout << "\t\t\t--------------THONG BAO--------------" << endl;
            cout << "\t\t\t Can cuoc cong dan ban nhap vao sai !!" << endl;
            cout << "\t\t\t-------------------------------------" << endl;
            TextColor(7);
            cout << "Nhap lai CCCD: "; getline(cin,temp.CCCD);
        }
        cout << "SDT: "; getline(cin, temp.Tel);
        while(temp.checkTel(temp.Tel) == false){
            TextColor(4);
            cout << "\t\t\t-------------THONG BAO-------------" << endl;
            cout << "\t\t\t So dien thoai ban nhap vao sai !!" << endl;
            cout << "\t\t\t-----------------------------------" << endl;
            TextColor(7);
            cout << "Nhap lai SDT: "; 
            getline(cin,temp.Tel);
        }
        cout << "Address: "; getline(cin, temp.Add);
        cout << "Gioi tinh (Nam:1/Nu:0): "; cin >> temp.Sex;
        cout << "-----------------------------------" << endl;
        cout << "" << endl;
        TextColor(2);
        cout << "\t\t\t--------------THONG BAO-------------" << endl;
        cout << "\t\t\tThong tin nhan vien da duoc them:" << endl;
        cout << "\t\t\t------------------------------------" << endl;
        TextColor(3);
        temp.Person::Show(this->length);
        TextColor(7);
        this->InsertAtLast(temp);
    }
}

// Delete Function
void ListEmployee::DeleteByPosition(const string& IDPD){
    for(int i=0;i<this->length;i++){
        while(this->p[i].getIDPosition() == IDPD)
            this->DeleteAt(i);        
    }
}

void ListEmployee::DeleteByMD(const string& IDMD){
    for(int i=0;i<this->length;i++){
        while(this->p[i].getIDMD() == IDMD)
            this->DeleteAt(i);
    }
}

void ListEmployee::Delete(const string& ID1){
    int t = this->Search(ID1);
    if(t != -1){
        this->DeleteAt(t);
    }else{
        TextColor(4);
        cout << "\t\t\t-------------------THONG BAO-------------------" << endl;
        cout << "\t\t\t Khong the tim thay ma nhan vien thich hop !!" << endl;
        cout << "\t\t\t-----------------------------------------------" << endl;
        TextColor(7);
    }
}

void ListEmployee::DeleteAt(int index){
    for(int i=index; i< this->length-1 ;i++){
        *(p+i) = *(p+i+1);
    }
    this->length--;

    Employee *temp = new Employee[this->length];
    for(int i = 0;i< this->length;i++){
        *(temp+i) = *(p+i);
    }

    delete[] p;
    p = new Employee[this->length];

    for(int i=0 ; i < this->length ;i++){
        *(p+i) = *(temp+i);
    }

    delete[] temp;
}

// Support Function
bool ListEmployee::Exis(string ID6){
    int check = this->Search(ID6);
    if(check == -1){
        return false;
    }
    else return true;
}

int ListEmployee::CountByMD(const string& IDMD){
    int count =0;
    for(int i=0;i<this->length;i++){
        if (this->p[i].getIDMD() == IDMD) count++;
    }
    return count;
}

int ListEmployee::CountByPosition(const string& IDPC){
    int count =0;
    for(int i=0;i<this->length;i++){
        if (this->p[i].getIDPosition() == IDPC) count++;
    }
    return count;
}

bool ListEmployee::CheckID(string ID4){
    if( ID4.size() != 7 ) return false;
    
    if(this->Search(ID4) != -1) return false;

    return true;
}

// Update Function
void ListEmployee::Update(const string & ID1){
    int VT = this->Search(ID1);
    if(VT == -1) {
        TextColor(4);
        cout << "\t\t\t-----------------THONG BAO--------------------" << endl;
        cout << "\t\t\t  Khong the tim thay ma nhan vien thich hop !!" << endl;
        cout << "\t\t\t----------------------------------------------" << endl;
        TextColor(7);
    }
    else{
        cout << "\t\t----------------------------------------" << endl;
        cout << "\t\tNhap thong tin nhan vien: " << endl;
        cout << "\t\tMSNV: " << p[VT].ID << endl;
        cout << "\t\tTen: "; getline(cin,p[VT].Name);
        cout << "\t\tNgay Sinh ";cin >> p[VT].birthDate;
        cout << "\t\tCCCD: "; cin.ignore(); getline(cin,p[VT].CCCD);
        while(p[VT].checkCCCD(p[VT].CCCD) == false){
            TextColor(4);
            cout << "\t\t\t--------------THONG BAO--------------" << endl;
            cout << "\t\t\t Can cuoc cong dan ban nhap vao sai !!" << endl;
            cout << "\t\t\t-------------------------------------" << endl;
            TextColor(7);
            cout << "\t\tNhap lai CCCD: ";getline(cin,p[VT].CCCD);
        }
        cout << "\t\tSDT: "; getline(cin, p[VT].Tel);
        while(p[VT].checkTel(p[VT].Tel) == false){
            TextColor(4);
            cout << "\t\t\t-------------THONG BAO-------------" << endl;
            cout << "\t\t\t So dien thoai ban nhap vao sai !!" << endl;
            cout << "\t\t\t-----------------------------------" << endl;
            TextColor(7);
            cout << "\t\tNhap lai SDT: ";getline(cin,p[VT].Tel);
        }
        cout << "\t\tAddress: ";getline(cin, p[VT].Add);
        cout << "\t\tGioi tinh (Nam:1/Nu:0): "; cin >> p[VT].Sex;
        cout << "\t\t----------------------------------------\n" <<endl;
        TextColor(2);
        cout << "\t\t\t-----------------THONG BAO----------------" << endl;
        cout << "\t\t\t   Thong tin nhan vien da duoc cap nhap" << endl;
        cout << "\t\t\t------------------------------------------" << endl;
        TextColor(3);
        p[VT].Person::Show(VT);
        TextColor(7);
        this->getMD();
        this->getMoney();
    }
}

// Search Function

ListEmployee ListEmployee::SearchByPosition(const string& IDP6){
    ListEmployee LE6;
    for(int i=0;i<this->length;i++){
        if(p[i].getIDPosition() == IDP6){
            Employee temp(p[i]);
            LE6.InsertAtLast(temp);
        }
    }LE6.Sort('D');
    return LE6;
}

ListEmployee ListEmployee::SearchByMD(const string& IDMD6){
    ListEmployee LE7;
    for(int i=0;i<this->length;i++){
        if(p[i].getIDMD() == IDMD6){
            Employee temp (p[i]);
            LE7.InsertAtLast(temp);
        }
    }LE7.Sort('D');
    return LE7;
}

int ListEmployee::Search(const string& ID1){
    for(int i=0;i<this->length;i++){
        if(p[i].getIDPerson() == ID1){
            return i;
        }
    } 
    return -1;
}

// Sort Function
void ListEmployee::Sort(char AD){
    int gap,i,j;
    int n = this->length;
    char left[100],right[100];
    Employee temp;
    for(gap = n/2; gap>0 ; gap = gap/2){
        for(i = gap;i <n;i++){
            for(j = i-gap;j>=0;j = j-gap){
                strcpy( left , ((*(p+j+gap)).getIDPerson()).c_str() );
                strcpy( right , ((*(p+j)).getIDPerson()).c_str() );
                if(strcmp(left,right) >= 0){
                    break;
                }else{
                    temp = *(p+j);
                    *(p+j) = *(p+j+gap);
                    *(p+j+gap) = temp;
                }
            }
        }
    }if(AD == 'D'){
        int l =0;
        int r = this->length - 1;
        while(l<r){
            temp = p[l];
            p[l] = p[r];
            p[r] = temp;
            l++;
            r--;
        }
    }   
}

void ListEmployee::SortByMoney(char AD){
    int gap,i,j;
    int n = this->length;
    Employee temp;
    for(gap = n/2; gap>0 ; gap = gap/2){
        for(i = gap;i <n;i++){
            for(j = i-gap;j>=0;j = j-gap){
                if(p[j].Salary() < p[j+gap].Salary()){
                    break;
                }else{
                    temp = *(p+j);
                    *(p+j) = *(p+j+gap);
                    *(p+j+gap) = temp;
                }
            }
        }
    }if(AD == 'D'){
        int l =0;
        int r = this->length - 1;
        while(l<r){
            temp = p[l];
            p[l] = p[r];
            p[r] = temp;
            l++;
            r--;
        }
    }
}

// Show Function
void ListEmployee::ShowWithPMD(){
    int i,j;
    cout << "||";
    for(int i=1;i<=53;i++)
        cout << " ";
    cout << "THONG TIN NHAN VIEN";
    for(int i=1;i<=53;i++)
        cout << " ";
    cout << "||" <<endl;
    cout << "||";
    for(int i=1;i<=125;i++)
        cout << "_";
    cout << "||" <<endl;
    cout << "|| STT |  MSNV   |  Ho va ten ";
    for(i=1;i<=13;i++){
        cout << " ";
    }cout << "| Ngay sinh  | CCCD";
    for(i=1;i<=9;i++){
        cout << " ";
    }
    cout << "| Gioi tinh | SDT";
    for(i=1;i<=8;i++){
        cout << " ";
    }cout << "| Chuc vu "; // chuc vu
    for(i=1;i<=21;i++){
        cout << " ";
    }cout << "||" << endl;
    cout << "||_____|_________|_________________________|____________|______________|___________|____________|______________________________||" << endl;
    
    for(i=0;i<this->length;i++){
        cout << "|| " << i+1;
        int count = 0 ;
        if(i+1<10){
            cout << "   |";
        }else if(i+1<100 && i+1>=10){
            cout << "  |";
        }else{
            cout << " |";
        }cout << " " << p[i].getIDPerson() << " | " << p[i].getName();
        for(j=1;j<=24-p[i].getName().size();j++){
            cout << " ";
        }cout << "| " << p[i].getBirthDate();
        if(p[i].getBirthDate().getDay()<10) cout << " ";
        if(p[i].getBirthDate().getMonth()<10) cout <<"  | ";
        else cout << " | ";
        cout << p[i].getCCCD();
        for(j=1;j<=13 - p[i].getCCCD().size();j++){
            cout << " ";
        }cout <<"|";
        if(p[i].getSex()==1){
            cout <<"  Nam      |";
        }else{
            cout <<"  Nu       |";
        }cout << " " << p[i].getTel() << " | " << p[i].getNPosition();
        for(int j=1;j<=29 - p[i].getNPosition().size();j++){
            cout << " ";
        }cout << "||" << endl;
        cout << "||_____|_________|_________________________|____________|______________|___________|____________|______________________________||" << endl;
    }
    TextColor(7);
}

void ListEmployee::ShowPerson(){
    TextColor(3);
    int i,j;
    for(i=1;i<=129;i++){
        cout << "_";
    }cout << endl;
    cout << "|| STT |  MSNV   |  Ho va ten ";
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
    
    for(i=0;i<this->length;i++){
        cout << "|| " << i+1;
        int count = 0 ;
        if(i+1<10){
            cout << "   |";
        }else if(i+1<100 && i+1>=10){
            cout << "  |";
        }else{
            cout << " |";
        }cout << " " << p[i].getIDPerson() << " | " << p[i].getName();
        for(j=1;j<=24-p[i].getName().size();j++){
            cout << " ";
        }cout << "| " << p[i].getBirthDate();
        if(p[i].getBirthDate().getDay()<10) cout << " ";
        if(p[i].getBirthDate().getMonth()<10) cout <<"  | ";
        else cout << " | ";
        cout << p[i].getCCCD();
        for(j=1;j<=13 - p[i].getCCCD().size();j++){
            cout << " ";
        }cout <<"|";
        if(p[i].getSex()==1){
            cout <<"  Nam      |";
        }else{
            cout <<"  Nu       |";
        }cout << " " << p[i].getTel() << " | " << p[i].getAdd();
        for(int j=1;j<=29 - p[i].getAdd().size();j++){
            cout << " ";
        }cout << "||" << endl;
        cout << "||_____|_________|_________________________|____________|______________|___________|____________|______________________________||" << endl;
    }
    TextColor(7);
}

void ListEmployee::ShowPosition(){
    TextColor(3);
    for(int i=1;i<=97;i++){
        cout << "_";
    }cout << endl;
    cout << "|| STT | MANV    | Ho va ten               | Chuc vu                 |  Phong Ban              ||" << endl;
    cout << "||_____|_________|_________________________|_________________________|_________________________||" << endl;
    
    for(int i=0;i<this->length;i++){
        cout << "|| " << i+1;
        for(int j=1;j<=4-CountNum(i+1);j++){
            cout << " ";
        }
        cout << "| " << p[i].getIDPerson() << " | ";
        cout << p[i].getName();
        for(int j=1;j<=24-p[i].getName().size();j++)
            cout << " ";
        cout << "| " << p[i].getNPosition();
        for(int j=1;j<=24-p[i].getNPosition().size();j++)
            cout << " ";
        cout << "| " << p[i].getNMD();
        for(int j=1;j<=24-p[i].getNMD().size();j++)
            cout << " ";
        cout << "||" << endl;
        cout << "||_____|_________|_________________________|_________________________|_________________________||" << endl;
    }
    TextColor(7);
}

// Reset Working Days
void ListEmployee::ResetDay(int day){
    for(int i=0;i<this->length;i++){
        p[i].setDay((int)80*day/100);
        p[i].setFine(0);
    }
}

// Support for Statistic
void ListEmployee::CountByPosition(const string& IDP10, int& F, int& N){
    F = N =0;
    for(int i=0;i<this->length;i++){
        if(p[i].getIDPosition() == IDP10){
            if(p[i].getSex() == 1 )
                N++;
            else
                F++;
        }
    }
}

void ListEmployee::MoneyByPosition(const string& IDP10,long long& F,long long& N){
    F = N =0;
    for(int i=0;i<this->length;i++){
        if(p[i].getIDPosition() == IDP10){
            if(p[i].getSex() == 1)
                N += p[i].Salary();
            else{
                F += p[i].Salary();
            }
        }
    }
}

void ListEmployee::CountByMD(const string& IDP10, int& F, int& N){
    F = N =0;
    for(int i=0;i<this->length;i++){
        if(p[i].getIDMD() == IDP10){
            if(p[i].getSex() == 1 )
                N++;
            else
                F++;
        }
    }
}

void ListEmployee::MoneyByMD(const string& IDP10,long long& F,long long& N){
    F = N =0;
    for(int i=0;i<this->length;i++){
        if(p[i].getIDMD() == IDP10){
            if(p[i].getSex() == 1)
                N += p[i].Salary();
            else{
                F += p[i].Salary();
            }
        }
    }
}

// Statistic Fucntion
void ListEmployee::StatisticByPosition(ListPosition PS){
    // Tham so can 
    int NOM,NOF;
    long long SOM,SOF;
    // Khung
    cout << "                                                                >>> THONG KE THEO CHUC VU <<<" << endl;
    cout << "_____________________________________________________________________________________________________________________________________________________________" << endl;
    cout << "||                   |                               |          So luong nhan vien             |                        Tong thu nhap                      ||" << endl;
    cout << "||     ID chuc vu    |          Ten Chuc vu          |_________________________________________|___________________________________________________________||" << endl;
    cout << "||                   |                               |         Nam        |         Nu         |             Nam             |              Nu             ||" << endl;
    cout << "||___________________|_______________________________|____________________|____________________|_____________________________|_____________________________||" << endl;
    // Core
    for(int i=0;i<PS.table.getSize();i++)
        for(int j=0;j<PS.table[i].listLength();j++)
        {
            NOM = NOF = SOM = SOF = 0;
            this->CountByPosition(PS.table[i][j].getID(),NOF,NOM);
            this->MoneyByPosition(PS.table[i][j].getID(),SOF,SOM);
            PS.table[i][j].ShowWithStatistic(NOF,NOM,SOF,SOM);
        }
}

void ListEmployee::StatisticByMD(ListMD MS){
    // Tham so
    int NOM,NOF;
    long long SOM,SOF;
    // Khung 
    TextColor(11);
    cout << "                                                                >>> THONG KE THEO PHONG BAN <<<" << endl;
    cout << "_____________________________________________________________________________________________________________________________________________________________" << endl;
    cout << "||                   |                               |          So luong nhan vien             |                        Tong thu nhap                      ||" << endl;
    cout << "||    ID Phong Ban   |         Ten Phong Ban         |_________________________________________|___________________________________________________________||" << endl;
    cout << "||                   |                               |         Nam        |         Nu         |             Nam             |              Nu             ||" << endl;
    cout << "||___________________|_______________________________|____________________|____________________|_____________________________|_____________________________||" << endl;

    for(int i=0;i<MS.table.getSize();i++)
        for(int j=0;j<MS.table[i].listLength();j++)
        {
            NOM = NOF = SOM = SOF = 0;
            this->CountByMD(MS.table[i][j].getID(),NOF,NOM);
            this->MoneyByMD(MS.table[i][j].getID(),SOF,SOM);
            MS.table[i][j].ShowWithStatistic(NOF,NOM,SOF,SOM);
        }
    TextColor(7);
}

void ListEmployee::StatisticSum(ListPosition LP, ListMD LMd){
    // Tong so luong
    int NOM = 0, NOF =0;
    long long SOM = 0, SOF = 0;
    // ListEmployee
    for(int i=0;i<this->length;i++){
        if(p[i].getSex() == 1)
        {
            NOM ++;
            SOM += p[i].Salary();
        }
        else
        {
            NOF++;
            SOF += p[i].Salary();
        }
    }
    int NOP = 0, NOMD = 0;
    // ListPosition
    for(int i=0;i<LP.table.getSize();i++)
        for(int j=0;j<LP.table[i].listLength();j++)
            NOP ++;
    // ListMD
    for(int i=0;i<LMd.table.getSize();i++)
        for(int j=0;j<LMd.table[i].listLength();j++)
            NOMD ++;
    // Khung
    TextColor(12);
    cout << "\t\t\t\t\t                       >>>> THONG KE CA NHA HANG <<<<" << endl;
    cout << "\t\t\t\t\t___________________________________________________________________________" << endl;
    cout << "\t\t\t\t\t||        So luong nhan vien         |      Thu Nhap ( nghin dong )      ||" << endl;
    cout << "\t\t\t\t\t||___________________________________|___________________________________||" << endl;
    cout << "\t\t\t\t\t||       Nam       |       Nu        |       Nam       |        Nu       ||" << endl;
    cout << "\t\t\t\t\t||_________________|_________________|_________________|_________________||" << endl;
    // In an 
    cout << "\t\t\t\t\t||       " << NOM;
    for(int i=1;i<=10-CountNum(NOM);i++)
        cout << " ";
    cout << "|       " << NOF;
    for(int i=1;i<=10-CountNum(NOF);i++)
        cout << " ";
    cout << "|     " << SOM;
    for(int i=1;i<=12-CountNum(SOM);i++)
        cout << " ";
    cout << "|     " << SOF;
    for(int i=1;i<=12-CountNum(SOF);i++)
        cout << " ";
    cout << "||" << endl;
    cout << "\t\t\t\t\t||_________________|_________________|_________________|_________________||" << endl;
    cout << "\t\t\t\t\t|| Tong so nhan vien : " << NOF+NOM;
    for(int i=1;i<=14-CountNum(NOM+NOF);i++)
        cout << " ";
    cout << "| Tong thu nhap nhan vien: " << SOM + SOF;
    for(int i=1;i<=9-CountNum(SOM+SOF);i++)    
        cout << " ";
    cout << "||" << endl;
    cout << "\t\t\t\t\t||___________________________________|___________________________________||" << endl;
    // In chuc vu va phong ban
    cout << "\t\t\t\t\t|| Tong chuc vu : " << NOP;
    for(int i=1;i<=19-CountNum(NOP);i++)    
        cout << " ";
    cout << "| Tong phong ban: " << NOMD;
    for(int i=1;i<=18-CountNum(NOMD);i++)
        cout << " ";
    cout << "|| " << endl;
    cout << "\t\t\t\t\t||___________________________________|___________________________________||" << endl;
    TextColor(7);
}

/*-------------Process with File-------------------*/
void ListEmployee::InputFilePerson(){
    string f = "./Data/Person.txt";
    int n,i=0;
    ifstream file;
    file.open(f);
    string ID1;
    string Name1;
    string Tel1;
    string CCCD1;
    string Add1;
    bool Sex1;
    int date1;
    int month1;
    int year1;
    string trash;
    do{
        getline(file,Name1,'-');
        file.ignore();
        getline(file,Tel1,'-');
        file.ignore();
        getline(file,ID1,'-');
        file.ignore();
        getline(file,Add1,'-');
        file.ignore();
        getline(file,CCCD1,'-');
        file.ignore();
        file >> Sex1;
        file >> date1;
        file >> month1;
        file >> year1;
        getline(file,trash,'\n');
        Person P2(ID1,Name1,Tel1,CCCD1,Add1,Sex1,Date(date1,month1,year1));
        Employee E1(P2);
        this->InsertAt(E1,i);
        i++;
    }while(!file.eof());
    this->length = i;
    file.close();
}

void ListEmployee::OutFilePerson(){
    string f = "./Data/Person.txt";
    ofstream file;
    file.open(f);
    for(int i=0;i<this->length-1;i++){
        file << p[i].getName() << "- ";
        file << p[i].getTel() << "- ";
        file << p[i].getIDPerson() << "- ";
        file << p[i].getAdd() << "- ";
        file << p[i].getCCCD() << "- ";
        file << p[i].getSex() << " ";
        file << p[i].getBirthDate().getDay() <<" ";
        file << p[i].getBirthDate().getMonth() << " ";
        file << p[i].getBirthDate().getYear() << "   \n";   
    }
    file << p[this->length-1].getName() << "- ";
    file << p[this->length-1].getTel() << "- ";
    file << p[this->length-1].getIDPerson() << "- ";
    file << p[this->length-1].getAdd() << "- ";
    file << p[this->length-1].getCCCD() << "- ";
    file << p[this->length-1].getSex() << " ";
    file << p[this->length-1].getBirthDate().getDay() <<" ";
    file << p[this->length-1].getBirthDate().getMonth() << " ";
    file << p[this->length-1].getBirthDate().getYear() << "   ";   
    file.close();
}

void ListEmployee::InputDate(){
    string trash;
    string f = "./Data/Attendance.txt";
    string ID5;
    long long fine5;
    int date5;
    ifstream file5;
    file5.open(f);
    do{
        getline(file5,ID5,'-');
        file5.ignore();
        file5 >> date5;
        file5 >> fine5;
        getline(file5,trash,'\n');

        int VT4 = this->Search(ID5);
        p[VT4].setDay(date5);
        p[VT4].setFine(fine5);
    }while(!file5.eof());
    file5.close();
}

void ListEmployee::OutDate(){
    string f = "./Data/Attendance.txt";
    ofstream file3;
    file3.open(f);
    for(int i=0; i < this->length-1;i++){
        file3 << p[i].ID << "- ";
        file3 << p[i].Day << "\t";
        file3 << p[i].Fine << "\n";
    }
    file3 << p[this->length -1].ID << "- ";
    file3 << p[this->length -1].Day << "\t";
    file3 << p[this->length -1].Fine;
    file3.close();
}

#endif  // END LISTEMPLOYEE