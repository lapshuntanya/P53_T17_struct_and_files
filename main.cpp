#include "Card.h"


int main() {

    Card Bohdan;
    Bohdan.createCard();

    cout << "--------------------------\n";
    Bohdan.showCard();


    FILE* file = nullptr;
    //fopen_s(&file, "bank.bin", "w"); //VS
    file = fopen("bank.bin", "w"); //CLion, Online
    if (file!= nullptr) {
        Bohdan.saveCardToBinFile(file);
        fclose(file);
        cout << "Saved!\n";
    }


    return 0;
}