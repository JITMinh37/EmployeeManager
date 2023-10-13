#include "Menu.cpp"

int main(){
    // Take Present Time & Check Present Date == 1 
    takePresentTime();
    CheckPresentDate();
    // Login In
    Init();
    // Inputfrom file
    LE.InputFilePerson();
    LE.InputDate();
    LE.getMoney();
    LE.getMD();
    // Menu
    Menu();
    // Output to file
    LE.OutFilePerson();
    LE.OutDate();
    LPo.OutData();
    LMD.OutData();
}