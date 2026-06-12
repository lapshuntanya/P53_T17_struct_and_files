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

};




#endif //P53_T17_STRUCT_AND_FILES_CARD_H
