#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Animal.h>
#include <Owner.h>
#include <House.h>
#include <Pet.h>
#include <Residence.h>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <conio.h>
#include <string>

std::vector<Owner> owners;
std::vector<Pet> pets;

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const char* animalsfile = "animals.txt";
    const char* ownersfile = "owners.txt";
    const char* housesfile = "houses.txt";
    FILE* ownersstream = fopen(ownersfile, "r");
    if (ownersstream == NULL) throw std::runtime_error("File Open Error");
    char* str = (char*)calloc(50, sizeof(char));
    
    // заполняем векторы животных, хозяев, домов из соответствующих файлов

    for (int i = 0; fgets(str, 30, ownersstream) != NULL; ++i) {
        std::string ownerName = str;
        fgets(str, 15, ownersstream);
        std::string birthday = str;
        fgets(str, 3, ownersstream);
        std::string responsibilityDegree = str;
        int degree = std::atoi(str);
        Owner createOwnerRecord(ownerName, birthday, degree);
        owners.push_back(createOwnerRecord);
    }
    fclose(ownersstream);

    

    Flat flat2 = Flat("Северо-западная 105", 55, "+79831778095", 2, true);
    Cat cat2 = Cat("Барсик", "м", 5);
    Owner owner2 = Owner("Сильянов С.Е.", "08.08.2004", 1);

    Flat* ptrflat2 = &flat2;
    Cat* ptrcat2 = &cat2;

    (*ptrflat2).toString();
    (*ptrcat2).toString();
    owner2.toString();

    Residence residence2 = Residence(ptrflat2, owner2);
    Pet pet2 = Pet(ptrcat2, owners[0], ptrflat2);

    Flat flat1 = createFlat();
    Dog dog1 = createDog();
    Cat cat1 = createCat();

    Flat* ptrflat1 = &flat1;
    Cat* ptrcat1 = &cat1;
    Dog* ptrdog1 = &dog1;

    Residence residence1 = Residence(&flat1, owners[0]);
    Pet pet1 = Pet(ptrdog1, owner2, ptrflat1);

    pets.push_back(pet1);
    pets.push_back(pet2);

    pets[0].toString();
}