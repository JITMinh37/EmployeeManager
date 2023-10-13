#include "ListEmployee.cpp"
#include "LogIn.cpp"

ListEmployee LE;
ListMD LMD;
ListPosition LPo;

// 1
void Show(int choose)
{
    LPo.OutData();
    LMD.OutData();
    LE.getMoney();
    LE.getMD();
    switch (choose)
    {
    case 1:
    {
        cout << "\t\t\t\t\t         ====== BANG DANH SACH NHAN VIEN ======" << endl;
        LE.ShowPerson();
        break;
    }
    case 2:
    {
        cout << "\t\t\t============ Bang Chuc Vu ============" << endl;
        LPo.Show();
        break;
    }
    case 3:
    {
        cout << "\t\t\t==== Bang phong ban ====" << endl;
        LMD.Show();
        break;
    }
    case 4:
    {
        cout << "\t\t\t================ Bang luong cua nhan vien ================" << endl;
        cout << LE;
        break;
    }
    case 5:
    {
        cout << "\t\t\t============== Bang chuc vu cua nhan vien ==============" << endl;
        LE.ShowPosition();
        break;
    }
    default:
        break;
    }
}

// 2
void Sort(int choose)
{
    int c2;
    cout << endl;
    cout << "\t\t=========Theo thu tu=========" << endl;
    cout << "\t\t||    1. Tang dan          ||" << endl;
    cout << "\t\t||    2. Giam dan          ||" << endl;
    cout << "\t\t||    3. Thoat             ||" << endl;
    cout << "\t\t=============================" << endl;
    cout << "\t\t-> Lua chon cua ban (1-3): ";
    cin >> c2;
    if(c2 != 1 && c2 != 2) return;
    switch (choose)
    {
        case 1:
        {
            if(c2 == 1)     LE.Sort('A');
            else    LE.Sort('D');
            Show(1);
            system("Pause");
            break;
        }
        case 2:
        {
            if (c2 ==1 )    LE.SortByMoney('A');
            else    LE.SortByMoney('D');
            Show(4);
            system("Pause");
            break;
        }
        default: break;
    }
}

// 3
void Delete(int choose)
{
    cin.ignore();
    char yn;
    string ID3;
    int countE;
    switch (choose)
    {
    case 1:
    {
        cout << "\t\tNhap ID nhan vien ban muon xoa: ";
        getline(cin, ID3);
        while (LE.Exis(ID3) == false)
        {
            TextColor(4);
            cout << "\t\t\t---------------THONG BAO------------------" << endl;
            cout << "\t\t\t    ID nay khong co trong danh sach !!" << endl;
            cout << "\t\t\t------------------------------------------" << endl;
            TextColor(7);
            cout << "\t\tBan co muon nhap lai khong (y/n) : ";
            cin >> yn;
            while (yn != 'n' && yn != 'y')
            {
                TextColor(7);
                cout << "\t\tMuon nhap lai vui long nhan y, Khong muon nhap lai nhan n: ";
                cin.ignore();
                cin >> yn;
            }
            if (yn == 'n')
                break;
            if (yn == 'y')
            {
                cin.ignore();
                cout << "\t\tNhap ID nhan vien ban muon xoa: ";
                getline(cin, ID3);
            }
        }
        if (yn == 'n')
            break;
        LE.Delete(ID3);
        TextColor(2);
        cout << "\t\t\t----------THONG BAO-----------" << endl;
        cout << "\t\t\t       Xoa thanh cong !!" << endl;
        cout << "\t\t\t------------------------------" << endl;
        TextColor(7);
        break;
    }
    case 2:
    {
        cout << "\t\tNhap ID chuc vu ban muon xoa: ";
        getline(cin, ID3);
        while (LPo.Exis(ID3) == false)
        {
            TextColor(4);
            cout << "\t\t\t---------------THONG BAO------------------" << endl;
            cout << "\t\t\t    ID nay khong co trong danh sach !!" << endl;
            cout << "\t\t\t------------------------------------------" << endl;
            TextColor(7);
            cout << "\t\tBan co muon nhap lai khong (y/n) : ";
            cin >> yn;
            while (yn != 'n' && yn != 'y')
            {
                TextColor(7);
                cout << "\t\tMuon nhap lai vui long nhan y, Khong muon nhap lai nhan n: ";
                cin.ignore();
                cin >> yn;
            }
            if (yn == 'n')
                break;
            if (yn == 'y')
            {
                cin.ignore();
                cout << "\t\tNhap ID chuc vu ban muon xoa: ";
                getline(cin, ID3);
            }
        }
        if (yn == 'n')
            break;
        // LPo.Delete(ID3);
        TextColor(8);
        cout << "\t\t\t------------------THONG BAO---------------------" << endl;
        cout << "\t\t\t  Co tat ca " << LE.CountByPosition(ID3) << " nhan vien thuoc chuc vu nay !! " << endl;
        cout << "\t\t\t  Ban co muon xoa khong (y/n): ";
        cin >> yn;
        while (yn != 'n' && yn != 'y')
        {
            TextColor(7);
            cout << "\t\tMuon nhap lai vui long nhan y, Khong muon nhap lai nhan n: ";
            cin.ignore();
            cin >> yn;
        }
        cout << "\t\t\t------------------------------------------------" << endl;
        if (yn == 'y')
        {
            LPo.Delete(ID3);
            LE.DeleteByPosition(ID3);
            TextColor(2);
            cout << "\t\t\t----------THONG BAO-----------" << endl;
            cout << "\t\t\t       Xoa thanh cong !!" << endl;
            cout << "\t\t\t------------------------------" << endl;
            TextColor(7);
            break;
        }
        else
            break;
    }
    case 3:
    {
        cout << "\t\tNhap ID phong ban ban muon xoa: ";
        getline(cin, ID3);
        while (LMD.Exis(ID3) == false)
        {
            TextColor(4);
            cout << "\t\t\t---------------THONG BAO------------------" << endl;
            cout << "\t\t\t    ID nay khong co trong danh sach !!" << endl;
            cout << "\t\t\t------------------------------------------" << endl;
            TextColor(7);
            cout << "\t\tBan co muon nhap lai khong (y/n) : ";
            cin >> yn;
            while (yn != 'n' && yn != 'y')
            {
                TextColor(7);
                cout << "\t\tMuon nhap lai vui long nhan y, Khong muon nhap lai nhan n: ";
                cin.ignore();
                cin >> yn;
            }
            if (yn == 'n')
                break;
            if (yn == 'y')
            {
                cin.ignore();
                cout << "\t\tNhap ID phong ban ban muon tim: ";
                getline(cin, ID3);
            }
        }
        if (yn == 'n')
            break;
        // check muon xoa cac chuc vu trong phong ban nay hay khong
        TextColor(8);
        cout << "\t\t\t------------------THONG BAO---------------------" << endl;
        cout << "\t\t\t  Co tat ca " << LPo.CountByMD(ID3) << " chuc vu thuoc phong ban nay !! " << endl;
        cout << "\t\t\t  Va co tat ca " << LE.CountByMD(ID3) << " nhan vien thuoc phong ban nay !!" << endl;
        cout << "\t\t\t  Ban co muon xoa khong (y/n): ";
        cin >> yn;
        while (yn != 'n' && yn != 'y')
        {
            TextColor(7);
            cout << "\t\tMuon nhap lai vui long nhan y, Khong muon nhap lai nhan n: ";
            cin.ignore();
            cin >> yn;
        }
        cout << "\t\t\t------------------------------------------------" << endl;
        if (yn == 'y')
        {
            LMD.Delete(ID3);
            LPo.DeleteByMD(ID3);
            LE.DeleteByMD(ID3);
            TextColor(2);
            cout << "\t\t\t----------THONG BAO-----------" << endl;
            cout << "\t\t\t       Xoa thanh cong !!" << endl;
            cout << "\t\t\t------------------------------" << endl;
            TextColor(7);
            break;
        }
        else
            break;
    }
    }
}

// 4
void Add(int choose){
    char yn;
    cin.ignore();
    string ID6;
    string Name6;
    int allowance;
    long long money;
    switch (choose)
    {
        case 1:
        {
            cout << "\t\tNhap ID Nhan Vien ban muon them: ";
            getline(cin,ID6);
            while (LE.CheckID(ID6) == false){
                TextColor(4);
                cout << "\t\t\t-------------THONG BAO-------------" << endl;
                cout << "\t\t\t ID nhan vien nay khong phu hop !!" << endl;
                cout << "\t\t\t-----------------------------------" << endl;
                TextColor(7);
                cout << "\t\tBan muon nhap lai khong (y/n): ";
                cin >> yn;
                if(yn == 'n') break;
                cout << "\n\t\tNhap ID nhan vien ban muon them :";
                cin.ignore();
                getline(cin,ID6);
            }
            if(yn == 'n') break;
            // Check Managerment Department da ton tai hay chua
            if(LMD.Exis(ID6.substr(0,2)) == false){
                TextColor(8);
                cout << "\t\t\t--------------------THONG BAO--------------------" << endl;
                cout << "\t\t\t Ma nhan vien nay chua co phong ban tuong ung !!" << endl;
                cout << "\t\t\t-------------------------------------------------" << endl;
                TextColor(7);
                cout << "\t\tBan co muon nhap thong tin cho phong ban nay khong (y/n): ";
                cin >> yn;
                if(yn == 'n') break;
                cout << "\t-------------------------------------" << endl;
                cout << "\tID phong ban: " << ID6.substr(0,2) << endl;
                cout << "\tNhap ten phong ban: ";
                cin.ignore();
                getline(cin,Name6);
                cout << "\t-------------------------------------" << endl;
                MD M6(Name6,ID6.substr(0,2));
                LMD.Add(M6); 
            }
            // Check ID Position va ID Managerment Derpartment da co chua
            // ID Position da ton tai hay chua
            if(LPo.Exis(ID6.substr(0,4)) == false){
                TextColor(8);
                cout << "\t\t\t-------------------THONG BAO-------------------" << endl;
                cout << "\t\t\t Ma nhan vien nay chua co chuc vu tuong ung !!" << endl;
                cout << "\t\t\t-----------------------------------------------" << endl;
                TextColor(7);
                cout << "\t\tBan co muon nhap thong tin cho chuc vu nay khong (y/n): ";
                cin >> yn;
                if(yn == 'n') break;
                cout << "\t-------------------------------------" << endl;
                cout << "\tID chuc vu: " << ID6.substr(0,4) << endl;
                cout << "\tNhap ten Chuc vu: ";
                cin.ignore();
                getline(cin,Name6);
                cout << "\tNhap phu cap (%): ";
                cin >> allowance;
                cout << "\tNhap luong (nghin dong/ngay): ";
                cin >>money;
                cout << "\t-------------------------------------" << endl;
                Position P6(allowance,money,Name6,ID6.substr(0,4));
                LPo.Add(P6); 
            }
            LE.Insert(ID6);
            LPo.OutData();
            LMD.OutData();
            LE.getMD();
            LE.getMoney();
            break;
        }
        case 2:
        {
            cout << "\t\tNhap ID Chuc Vu ban muon them: ";
            getline(cin,ID6);
            while (LPo.CheckID(ID6) == false){
                TextColor(4);
                cout << "\t\t\t-------------THONG BAO-------------" << endl;
                cout << "\t\t\t ID chuc vu nay khong phu hop !!" << endl;
                cout << "\t\t\t-----------------------------------" << endl;
                TextColor(7);
                cout << "\t\tBan muon nhap lai khong (y/n): ";
                cin >> yn;
                if(yn == 'n') break;
                cout << "\n\t\tNhap ID Chuc Vu ban muon them :";
                cin.ignore();
                getline(cin,ID6);
            }
            if(yn == 'n') break;

            // Check Managerment Department da ton tai hay chua
            if(LMD.Exis(ID6.substr(0,2)) == false){
                TextColor(8);
                cout << "\t\t\t--------------------THONG BAO--------------------" << endl;
                cout << "\t\t\t Ma nhan vien nay chua co phong ban tuong ung !!" << endl;
                cout << "\t\t\t-------------------------------------------------" << endl;
                TextColor(7);
                cout << "\t\tBan co muon nhap thong tin cho phong ban nay khong (y/n): ";
                cin >> yn;
                if(yn == 'n') break;
                cout << "\t-------------------------------------" << endl;
                cout << "\tID Phong Ban: " << ID6.substr(0,2) << endl;
                cout << "\tNhap ten Phong Ban: ";
                cin.ignore();
                getline(cin,Name6);
                cout << "\t-------------------------------------" << endl;
                MD M6(Name6,ID6.substr(0,2));
                LMD.Add(M6); 
            }
            cout << "\t\tNhap ten Chuc vu: ";
            getline(cin,Name6);
            cout << "\t\tNhap phu cap (%): ";
            cin >> allowance;
            cout << "\t\tNhap luong (nghin dong/ngay): ";
            cin >>money;
            Position P6(allowance,money,Name6,ID6);
            LPo.Add(P6); 
            break;
        }
        case 3:
        {
            cout << "\tNhap ID Phong Ban ban muon them: ";
            getline(cin,ID6);
            while (LMD.CheckID(ID6) == false){
                TextColor(4);
                cout << "\t\t\t-------------THONG BAO-------------" << endl;
                cout << "\t\t\t ID phong ban nay khong phu hop !!" << endl;
                cout << "\t\t\t-----------------------------------" << endl;
                TextColor(7);
                cout << "\t\tBan muon nhap lai khong (y/n): ";
                cin >> yn;
                if(yn == 'n') break;
                cout << "\n\tNhap ID Phong Ban ban muon them :";
                cin.ignore();
                getline(cin,ID6);
            }
            if( yn == 'n') break;
            cout << "\tNhap ten Phong Ban: ";
            getline(cin,Name6);
            MD M6(Name6,ID6);
            LMD.Add(M6); 
            break;
        }
    }
}

// 5
void Update(int choose){
    cin.ignore();
    char yn;
    string ID6;
    switch(choose)
    {
        case 1:
        {
            cout << "\t\tNhap ID nhan vien ban muon sua thong tin: ";
            getline(cin,ID6);
            while(LE.Exis(ID6) == false){
                TextColor(4);
                cout << "\t\t\t---------------THONG BAO------------------" << endl;
                cout << "\t\t\t    ID nay khong co trong danh sach !!" << endl;
                cout << "\t\t\t------------------------------------------" << endl;
                TextColor(7);
                cout << "\t\tBan co muon nhap lai khong (y/n) : " ;
                cin >> yn;
                if(yn == 'n') break;
                cin.ignore();
                cout << "\t\tNhap ID nhan vien ban muon sua thong tin: ";
                getline(cin,ID6);
            }
            if(yn == 'n') break;
            LE.Update(ID6);

            LMD.OutData();
            LPo.OutData();
            LE.getMD();
            LE.getMoney();

            break;
        }
        case 2:
        {    cout << "\t\tNhap ID chuc vu ban muon sua: " ;
            getline(cin,ID6);
            while(LPo.Exis(ID6) == false){
                TextColor(4);
                cout << "\t\t\t---------------THONG BAO------------------" << endl;
                cout << "\t\t\t    ID nay khong co trong danh sach !!" << endl;
                cout << "\t\t\t------------------------------------------" << endl;
                TextColor(7);
                cout << "\t\tBan co muon nhap lai khong (y/n) : ";
                cin >> yn;
                if(yn == 'n') break;
                cin.ignore();
                cout << "\t\tNhap ID chuc vu ban muon sua: ";
                getline(cin,ID6);
            }
            if(yn == 'n') break;
            LPo.Update(ID6,8);
            break;
        }
        case 3:
        {
            cout << "\t\tNhap ID phong ban ban muon sua: " ;
            getline(cin,ID6);
            while(LMD.Exis(ID6) == false){
                TextColor(4);
                cout << "\t\t\t---------------THONG BAO------------------" << endl;
                cout << "\t\t\t    ID nay khong co trong danh sach !!" << endl;
                cout << "\t\t\t------------------------------------------" << endl;
                TextColor(7);
                cout << "\t\tBan co muon nhap lai khong (y/n) : ";
                cin >> yn;
                if(yn == 'n') break;
                cin.ignore();
                cout << "\t\tNhap ID phong ban ban muon sua: ";
                getline(cin,ID6);
            }
            if(yn == 'n') break;
            LMD.Update(ID6,9);
            break;
        }
    }
}

// 6
void Search(int choose)
{
    cin.ignore();
    string ID6;
    int c6;
    char yn;
    switch (choose)
    {
    case 1:
    {
        cout << "\t\tNhap ID nhan vien ban muon tim: ";
        getline(cin, ID6);
        while (LE.Exis(ID6) == false)
        {
            TextColor(4);
            cout << "\t\t\t---------------THONG BAO------------------" << endl;
            cout << "\t\t\t    ID nay khong co trong danh sach !!" << endl;
            cout << "\t\t\t------------------------------------------" << endl;
            TextColor(7);
            cout << "\t\tBan co muon nhap lai khong (y/n) : ";
            cin >> yn;
            if (yn == 'n')
                break;
            cin.ignore();
            cout << "\t\tNhap ID nhan vien ban muon tim: ";
            getline(cin, ID6);
        }
        if (yn == 'n')
            break;
        int position = LE.Search(ID6);
        TextColor(3);
        cout << "\t\t\t*****************Thong tin nhan vien*****************" << endl;
        LE[position].ShowBySearch();
        cout << "\t\t\t*****************************************************" << endl;
        TextColor(7);
        break;
    }
    case 2:
    {
        // CHECK ID
        cout << "\t\tNhap ID chuc vu ban muon tim: ";
        getline(cin, ID6);
        while (LPo.Exis(ID6) == false)
        {
            TextColor(4);
            cout << "\t\t\t-----------------THONG BAO---------------------" << endl;
            cout << "\t\t\t   ID nay khong co trong danh sach chuc vu  " << endl;
            cout << "\t\t\t-----------------------------------------------" << endl;
            TextColor(7);
            cout << "\t\tBan co muon nhap lai khong (y/n): ";
            cin >> yn;
            if (yn == 'n')
            {
                break;
            }
            cin.ignore();
            cout << "\t\tNhap ID chuc vu ban muon tim: ";
            getline(cin, ID6);
        }
        if (yn == 'n')
            break;
        // END CHECK
        TextColor(3);
        LPo.Search(ID6).ShowWithEmployee();
        LE.SearchByPosition(ID6).ShowWithPMD();
        TextColor(7);
        break;
    }
    case 3:
    {
        // Check ID phong ban
        cout << "\t\tNhap ID phong ban ban muon tim: ";
        getline(cin, ID6);
        while (LMD.Exis(ID6) == false)
        {
            TextColor(4);
            cout << "\t\t\t-----------------THONG BAO---------------------" << endl;
            cout << "\t\t\t   ID nay khong co trong danh sach phong ban  " << endl;
            cout << "\t\t\t-----------------------------------------------" << endl;
            TextColor(7);
            cout << "\t\tBan co muon nhap lai khong (y/n): ";
            cin >> yn;
            if (yn == 'n')
            {
                break;
            }
            cin.ignore();
            cout << "\t\tNhap ID phong ban ban muon tim: ";
            getline(cin, ID6);
        }
        if (yn == 'n')
            break;
        // END check ID phong ban
        TextColor(3);
        LMD.Search(ID6).ShowWithEmployee();
        LE.SearchByMD(ID6).ShowWithPMD();
        TextColor(7);
        break;
    }
    case 4:
    {
        // Check ID phong ban
        cout << "\t\tNhap ID phong ban ban muon tim: ";
        getline(cin, ID6);
        while (LMD.Exis(ID6) == false)
        {
            TextColor(4);
            cout << "\t\t\t-----------------THONG BAO---------------------" << endl;
            cout << "\t\t\t   ID nay khong co trong danh sach phong ban  " << endl;
            cout << "\t\t\t-----------------------------------------------" << endl;
            TextColor(7);
            cout << "\t\tBan co muon nhap lai khong (y/n): ";
            cin >> yn;
            if (yn == 'n')
            {
                break;
            }
            cin.ignore();
            cout << "\t\tNhap ID phong ban ban muon tim: ";
            getline(cin, ID6);
        }
        if (yn == 'n')
            break;
        // END check ID phong ban
        TextColor(3);
        LMD.Search(ID6).ShowWithPosition();
        LPo.SearchByMD(ID6).ShowWithMD();
        TextColor(7);
        break;
    }
    case 5:
    {
        // CHECK ID
        cout << "\t\tNhap ID chuc vu ban muon tim: ";
        getline(cin, ID6);
        while (LPo.Exis(ID6) == false)
        {
            TextColor(4);
            cout << "\t\t\t-----------------THONG BAO---------------------" << endl;
            cout << "\t\t\t   ID nay khong co trong danh sach chuc vu  " << endl;
            cout << "\t\t\t-----------------------------------------------" << endl;
            TextColor(7);
            cout << "\t\tBan co muon nhap lai khong (y/n): ";
            cin >> yn;
            if (yn == 'n')
            {
                break;
            }
            cin.ignore();
            cout << "\t\tNhap ID chuc vu ban muon tim: ";
            getline(cin, ID6);
        }
        if (yn == 'n')
            break;
        // END CHECK
        TextColor(3);
        cout << "\t\t***************Thong tin chuc vu******************" << endl;
        LPo.Search(ID6).Show();
        cout << "\t\t**************************************************" << endl;
        TextColor(7);
        break;
    }
    case 6:
    {
        // Check ID phong ban
        cout << "\t\tNhap ID phong ban ban muon tim: ";
        getline(cin, ID6);
        while (LMD.Exis(ID6) == false)
        {
            TextColor(4);
            cout << "\t\t\t-----------------THONG BAO---------------------" << endl;
            cout << "\t\t\t   ID nay khong co trong danh sach phong ban  " << endl;
            cout << "\t\t\t-----------------------------------------------" << endl;
            TextColor(7);
            cout << "\t\tBan co muon nhap lai khong (y/n): ";
            cin >> yn;
            if (yn == 'n')
            {
                break;
            }
            cin.ignore();
            cout << "\t\tNhap ID phong ban ban muon tim: ";
            getline(cin, ID6);
        }
        if (yn == 'n')
            break;
        // END check ID phong ban
        TextColor(3);
        cout << "\t\t***************Thong tin phong ban******************" << endl;
        LMD.Search(ID6).Show();
        cout << "\t\t**************************************************" << endl;
        TextColor(7);
        break;
    }
    }
}

// 7
void Statistic(int choose)
{
    LPo.OutData();
    LMD.OutData();
    switch (choose)
    {
    case 1:
    {
        LE.StatisticByPosition();
        break;
    }
    case 2:
    {
        LE.StatisticByMD();
        break;
    }
    case 3:
    {
        LE.StatisticSum();
        break;
    }
    case 4:
    {
        LE.StatisticByPosition();
        LE.StatisticByMD();
        LE.StatisticSum();
        break;
    }
    default:
        break;
    }
}

// 8
void Fine(int choose)
{
    int mn;
    char yn;
    string ID8;
    long long fine9;
    int VT;
    switch(choose){
    case 1:
    {
        cout << "\t\tNhap so nhan vien ban muon phat: ";
        cin >> mn;
        while (mn < 0 || mn > LE.getLength())
        {
            TextColor(4);
            cout << "\t\t\t----------------------THONG BAO----------------------" << endl;
            cout << "\t\t\t    So luong nhan vien ban nhap vao khong phu hop " << endl;
            cout << "\t\t\t-----------------------------------------------------" << endl;
            TextColor(7);
            cout << "\t\tNhap lai so nhan vien ban muon phat: ";
            cin >> mn;
        }
        for (int i = 0; i < mn; i++)
        {
            TextColor(5);
            cout << "\t\tNhap ma nhan vien " << i + 1 << ": ";
            cin.ignore();
            getline(cin, ID8);
            while (LE.Exis(ID8) == false)
            {
                TextColor(4);
                cout << "\t\t\t-------------------THONG BAO-------------------" << endl;
                cout << "\t\t\t  ID nhan vien nay khong co trong danh sach" << endl;
                cout << "\t\t\t-----------------------------------------------" << endl;
                cout << "\t\tBan co muon nhap lai khong (y/n): ";
                cin >> yn;
                TextColor(5);
                if (yn == 'n')
                    break;
                cout << "\t\tNhap ma nhan vien " << i + 1 << ": ";
                cin.ignore();
                getline(cin, ID8);
            }
            if (yn == 'n')
                continue;
            cout << "\t\tNhap so tien phat (nghin dong): ";
            cin >> fine9;
            VT = LE.Search(ID8);
            LE[VT].setFine(LE[VT].getFine() - fine9);
        }
        break;
    }
    case 2:
    {
        cout << "\t\tNhap so nhan vien ban muon thuong: ";
        cin >> mn;
        while (mn < 0 || mn > LE.getLength())
        {
            TextColor(4);
            cout << "\t\t\t----------------------THONG BAO----------------------" << endl;
            cout << "\t\t\t    So luong nhan vien ban nhap vao khong phu hop " << endl;
            cout << "\t\t\t-----------------------------------------------------" << endl;
            TextColor(7);
            cout << "\t\tNhap lai so nhan vien ban muon thuong: ";
            cin >> mn;
        }
        for (int i = 0; i < mn; i++)
        {
            TextColor(9);
            cout << "\t\tNhap ma nhan vien " << i + 1 << ": ";
            cin.ignore();
            getline(cin, ID8);
            while (LE.Exis(ID8) == false)
            {
                TextColor(4);
                cout << "\t\t\t-------------------THONG BAO-------------------" << endl;
                cout << "\t\t\t  ID nhan vien nay khong co trong danh sach" << endl;
                cout << "\t\t\t-----------------------------------------------" << endl;
                cout << "\t\tBan co muon nhap lai khong (y/n): ";
                cin >> yn;
                if (yn == 'n')
                    break;
                TextColor(9);
                cout << "\t\tNhap ma nhan vien " << i + 1 << ": ";
                cin.ignore();
                getline(cin, ID8);
            }
            if (yn == 'n')
                continue;
            cout << "\t\tNhap so tien thuong (nghin dong): ";
            cin >> fine9;
            VT = LE.Search(ID8);
            LE[VT].setFine(LE[VT].getFine() + fine9);
        }
        break;
    }
    }
    TextColor(2);
    cout << "\t\t--------------THONG BAO--------------" << endl;
    cout << "\t\t        Cap nhap thanh cong !!" << endl;
    cout << "\t\t-------------------------------------" << endl;
    TextColor(7);
}

// 9
void EditSalary(int choose)
{
    char yn;
    string ID10;
    int d1;
    int mb;
    int VT1;
    switch (choose)
    {
    case 1:
    {
        cout << "\tNhap so nhan vien muon sua lai ngay di lam: ";
        cin >> mb;
        while (mb < 0 || mb > LE.getLength())
        {
            TextColor(4);
            cout << "\t\t\t----------------------THONG BAO----------------------" << endl;
            cout << "\t\t\t    So luong nhan vien ban nhap vao khong phu hop " << endl;
            cout << "\t\t\t-----------------------------------------------------" << endl;
            TextColor(7);
            cout << "\t\tNhap lai so nhan vien ban muon phat: ";
            cin >> mb;
        }
        cout << "\t******************************************************" << endl;
        for (int i = 0; i < mb; i++)
        {
            cout << "\t\tNhap ID nhan vien " << i + 1 << ": ";
            cin.ignore();
            getline(cin, ID10);
            while (LE.Exis(ID10) == false)
            {
                TextColor(4);
                cout << "\t\t\t-------------------THONG BAO-------------------" << endl;
                cout << "\t\t\t  ID nhan vien nay khong co trong danh sach" << endl;
                cout << "\t\t\t-----------------------------------------------" << endl;
                cout << "\t\tBan co muon nhap lai khong (y/n): ";
                cin >> yn;
                TextColor(7);
                if (yn == 'n')
                    break;
                cout << "\t\tNhap ID nhan vien " << i + 1 << ": ";
                cin.ignore();
                getline(cin, ID10);
            }
            if (yn == 'n')
                continue;
            cout << "\t\tNhap so ngay muon chinh sua lai: ";
            cin >> d1;
            while(d1 < 0 || d1 > tinhSoNgayTrongThang(PresentMonth,PresentYear)){
                    TextColor(4);
                    cout << "\t\t\t--------------THONG BAO-------------" << endl;
                    cout << "\t\t\t  So ngay ban nhap vao khong hop le "  << endl;
                    cout << "\t\t\t------------------------------------" << endl;
                    TextColor(7);
                    cout << "\t\tNhap lai so ngay muon chinh sua lai: ";
                    cin >> d1;
                }
            VT1 = LE.Search(ID10);
            LE[VT1].setDay(d1);
        }
        cout << "\t******************************************************" << endl;
        break;
    }
    case 2:
    {
        cout << "\t\tNhap so nhan vien muon them ngay di lam: ";
        cin >> mb;
        while (mb < 0 || mb > LE.getLength())
        {
            TextColor(4);
            cout << "\t\t\t----------------------THONG BAO----------------------" << endl;
            cout << "\t\t\t    So luong nhan vien ban nhap vao khong phu hop " << endl;
            cout << "\t\t\t-----------------------------------------------------" << endl;
            TextColor(7);
            cout << "\t\tNhap lai so nhan vien ban muon phat: ";
            cin >> mb;
        }
        cout << "******************************************************" << endl;
        for (int i = 0; i < mb; i++)
        {
            cout << "\t\tNhap ID nhan vien " << i + 1 << ": ";
            cin.ignore();
            getline(cin, ID10);
            while (LE.Exis(ID10) == false)
            {
                TextColor(4);
                cout << "\t\t\t-------------------THONG BAO-------------------" << endl;
                cout << "\t\t\t  ID nhan vien nay khong co trong danh sach" << endl;
                cout << "\t\t\t-----------------------------------------------" << endl;
                cout << "\t\tBan co muon nhap lai khong (y/n): ";
                cin >> yn;
                TextColor(7);
                if (yn == 'n')
                    break;
                cout << "\t\tNhap ID nhan vien " << i + 1 << ": ";
                cin.ignore();
                getline(cin, ID10);
            }
            if (yn == 'n')
                continue;
            cout << "\t\tNhap so ngay muon them: ";
            cin >> d1;
            VT1 = LE.Search(ID10);
            while(LE[VT1].getDay() + d1 < 0 || LE[VT1].getDay() + d1 > tinhSoNgayTrongThang(PresentMonth,PresentYear)){
                    TextColor(4);
                    cout << "\t\t\t--------------THONG BAO-------------" << endl;
                    cout << "\t\t\t  So ngay ban nhap vao khong hop le "  << endl;
                    cout << "\t\t\t------------------------------------" << endl;
                    TextColor(7);
                    cout << "\t\tNhap lai so ngay tang them: ";
                    cin >> d1;
                }
            LE[VT1].setDay(LE[VT1].getDay() + d1);
        }
        cout << "******************************************************" << endl;
        break;
    }
    case 3:
    {
        cout << "\t\tNhap so nhan vien muon giam ngay di lam: ";
        cin >> mb;
        while (mb < 0 || mb > LE.getLength())
        {
            TextColor(4);
            cout << "\t\t\t----------------------THONG BAO----------------------" << endl;
            cout << "\t\t\t    So luong nhan vien ban nhap vao khong phu hop " << endl;
            cout << "\t\t\t-----------------------------------------------------" << endl;
            TextColor(7);
            cout << "\t\tNhap lai so nhan vien ban muon phat: ";
            cin >> mb;
        }
        cout << "******************************************************" << endl;
        for (int i = 0; i < mb; i++)
        {
            cout << "\t\tNhap ID nhan vien " << i + 1 << ": ";
            cin.ignore();
            getline(cin, ID10);
            while (LE.Exis(ID10) == false)
            {
                TextColor(4);
                cout << "\t\t\t-------------------THONG BAO-------------------" << endl;
                cout << "\t\t\t  ID nhan vien nay khong co trong danh sach" << endl;
                cout << "\t\t\t-----------------------------------------------" << endl;
                cout << "\t\tBan co muon nhap lai khong (y/n): ";
                cin >> yn;
                TextColor(7);
                if (yn == 'n')
                    break;
                cout << "\t\tNhap ID nhan vien " << i + 1 << ": ";
                cin.ignore();
                getline(cin, ID10);
            }
            if (yn == 'n')
                continue;
            cout << "\t\tNhap so ngay giam di: ";
            cin >> d1;
            VT1 = LE.Search(ID10);
            while(LE[VT1].getDay() - d1 < 0 || LE[VT1].getDay() - d1 > tinhSoNgayTrongThang(PresentMonth,PresentYear)){
                    TextColor(4);
                    cout << "\t\t\t--------------THONG BAO-------------" << endl;
                    cout << "\t\t\t  So ngay ban nhap vao khong hop le "  << endl;
                    cout << "\t\t\t------------------------------------" << endl;
                    TextColor(7);
                    cout << "\t\tNhap lai so ngay giam di: ";
                    cin >> d1;
                }
            LE[VT1].setDay(LE[VT1].getDay() - d1);
        }
        cout << "******************************************************" << endl;
        break;
    }
    }
    TextColor(2);
    cout << "\t\t\t--------------THONG BAO--------------" << endl;
    cout << "\t\t\t        Cap nhap thanh cong !!" << endl;
    cout << "\t\t\t-------------------------------------" << endl;
    TextColor(7);
}

// 10
void Reset()
{
    cout << "\t\tTai khoan hien tai : " << realtk << endl;
    cout << "\t\tTai khoan moi : ";
    cin.ignore();
    getline(cin, realtk);
    cout << "\t\tMat khau hien tai : " << realPassWord << endl;
    cout << "\t\tMat khau moi : ";
    getline(cin, realPassWord);

    OutUserAndPass();
}