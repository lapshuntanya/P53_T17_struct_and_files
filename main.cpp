#include "Card.h"

#define CREATE_OR_LOAD 0 //CREATE 1, LOAD 0

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
        cout << "2 - Open a new card.\n";
        cout << "3 - Sort cards by money\n";
        cout << "4 - Withdraw cash\n";
        cout << "5 - Close cards with 0 balance\n";
        cout << "===========================================\n";
        cout << ">>> ";
        cin >> menu;

        switch (menu) {
            case 0: saveArrayToBinFile(bank, sizeBank); break;
            case 1: showArrayCards(bank, sizeBank); break;
            case 2: {
                Card tmp; // name = "undefined", number =0, money = 0
                cin.ignore();
                tmp.createCard();
                addItemBack(bank, sizeBank, tmp);
            }break;
            case 3:
                mySort<Card>(bank, sizeBank, [](Card left, Card right) {
                    return left.money > right.money;
                });
                break;
            case 4: {
                unsigned long user_number = 0;
                double user_money = 0;
                cout << "Input number of your card: ";
                cout << "Input money: ";

            }break;
        }//end switch
    } while (menu != 0);



    return 0;
}