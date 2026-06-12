#include "Card.h"

#define CREATE_OR_LOAD 1 //CREATE 1, LOAD 0

int main() {

//     Card Bohdan;//Bohdan = "undefined", nomber = 0, money = 0
//     Bohdan.createCard();//!!!!!!!!!!!
//
//     cout << "--------------------------\n";
//     Bohdan.showCard();
//
//
//     FILE* file = nullptr;
// #if VS_OR_CLION == 1
//     fopen_s(&file, "bank.bin", "wb"); //VS  !!!!!!!!!!!!
// #elif VS_OR_CLION == 0
//     file = fopen("bank.bin", "b"); //CLion, Online !!!!!!!!!!!!
// #endif
//
//     if (file!= nullptr) {
//         Bohdan.saveCardToBinFile(file);//!!!!!!!!!!!!!!!!
//        // Bohdan.loadCardFromBinFile(file);//!!!!!!!!!!!
//         fclose(file);
//         cout << "Loaded!\n";
//     }
//     cout << "--------------------------\n";
//     Bohdan.showCard();

    int sizeBank = 0;
    Card* bank = nullptr;

    int menu = 0;

#if CREATE_OR_LOAD == 1
    sizeBank = 3;
    bank = new Card[sizeBank] {
        {"Ivanov Volodymyr", 12345, 250},
        {"Kalashnikov Marko", 67895, 500},
        {"Konovalenko Tymofii", 45678, 300}
    };
#elif CREATE_OR_LOAD == 0
    loadArrayFromBinFile(bank, sizeBank);
#endif


    do {
        cout << "===========================================\n";
        cout << "\t MENU:\n";
        cout << "===========================================\n";
        cout << "0 - Save and Exit\n";
        cout << "1 - Show all cards.\n";
        cout << "===========================================\n";
        cout << ">>> ";
        cin >> menu;

        switch (menu) {
            case 0: saveArrayToBinFile(bank, sizeBank); break;
            case 1: showArrayCards(bank, sizeBank); break;
        }
    } while (menu != 0);



    return 0;
}