//
// Created by Tetiana Perederii on 12.06.2026.
//

#ifndef P53_T17_STRUCT_AND_FILES_CARD_H
#define P53_T17_STRUCT_AND_FILES_CARD_H
#include "ArrayTemplate.h"
#include <iomanip>
#include <cstdio>

struct Card {
    char name[100] = "undefined";
    unsigned long number = 0;       //0 .... +
    double money = 0;

    void createCard() {
        cout << "input name: ";
        cin.getline(name, 100);
        number = rand()%32'000* 10'000 + rand()%32'000;
        money = 200;
    }

    void showCard() {
        cout << setw(20) << name << ",  " << setw(10) << number << ",  " << money << "UAH\n";
    }

    void saveCardToBinFile(FILE* file) {
        int sizeName = strlen(name) + 1;
        fwrite(&sizeName, sizeof(int), 1, file);
        fwrite(name, sizeof(char), sizeName, file);

        fwrite(&number, sizeof(unsigned long), 1, file);

        fwrite(&money, sizeof(double), 1, file);
    }

    void loadCardFromBinFile(FILE* file) {
        int sizeName = 0;
        fread(&sizeName, sizeof(int), 1, file);
        fread(name, sizeof(char), sizeName, file);

        fread(&number, sizeof(unsigned long), 1, file);

        fread(&money, sizeof(double), 1, file);
    }

}; //end struct Card


//====================================
//Функції для масиву структур
//====================================
void showArrayCards(Card* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << i+1 << " ";
        arr[i].showCard();
    }
}


void saveArrayToBinFile(Card* arr, int size) {
        FILE* file = nullptr;
    #if VS_OR_CLION == 1
        fopen_s(&file, "bank.bin", "wb"); //VS  !!!!!!!!!!!!
    #elif VS_OR_CLION == 0
        file = fopen("bank.bin", "wb"); //CLion, Online !!!!!!!!!!!!
    #endif


    if (file!=nullptr) {
        fwrite(&size, sizeof(int), 1, file);
        for (int i =0; i < size; i++) {
            arr[i].saveCardToBinFile(file);
        }
        fclose(file);
        cout << "Saved!\n";
    }
}


void loadArrayFromBinFile(Card*& arr, int& size) {

    FILE* file = nullptr;
#if VS_OR_CLION == 1
    fopen_s(&file, "bank.bin", "rb"); //VS  !!!!!!!!!!!!
#elif VS_OR_CLION == 0
    file = fopen("bank.bin", "rb"); //CLion, Online !!!!!!!!!!!!
#endif

    if (file == nullptr) {
        cout << "Error: not loaded!\n";
        arr = nullptr;
        size = 0;
    }else {
        fread(&size, sizeof(int), 1, file);
        arr = new Card[size];
        for (int i = 0; i < size; ++i) {
            arr[i].loadCardFromBinFile(file);
        }
        fclose(file);
        cout << "Loaded!\n";
    }

}


void withdrawMoney(Card* arr, int size, unsigned long user_number,  double user_money) {
    int id = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i].number == user_number)
            id = i;
    }

    if ( id == -1)
        cout << "Error: not found!\n";
    else {
        if (user_money > arr[id].money)
            cout << "Error: " << arr[id].name << "has not " << user_money << "UAH\n";
        else {
            arr[id].money -= user_money;
            cout << "Current balance: " << arr[id].money << "UAH\n";
        }
    }

}
#endif //P53_T17_STRUCT_AND_FILES_CARD_H
