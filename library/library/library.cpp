#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Header.h"
#include <windows.h>
#include <algorithm>

std::vector<Owner> Owners;
std::vector<Animal> Animals;
std::vector<House> Houses;
std::vector<Pet> Pets;

int findMinLength(std::vector<Owner> Owners, std::vector<Animal> Animals, std::vector<House> Houses) {
    int min = Animals.size();
    if (min > Owners.size()) min = Owners.size();
    if (min > Houses.size()) min = Houses.size();
    return min;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const char* animalsfile = "animals.txt";
    const char* ownersfile = "owners.txt";
    const char* housesfile = "houses.txt";
    FILE* animalsstream = fopen(animalsfile, "r");
    FILE* ownersstream = fopen(ownersfile, "r");
    FILE* housesstream = fopen(housesfile, "r");
    if (animalsstream == NULL || ownersstream == NULL || housesstream == NULL) throw std::runtime_error("File Open Error");
    char* str = (char*)calloc(50, sizeof(char));
    
    for (int i = 0; fgets(str, 50, ownersstream) != NULL; ++i) {
        std::string ownerName = str;
        fgets(str, 50, ownersstream);
        std::string birthday = str;
        Owner createOwnerRecord(ownerName, birthday);
        Owners.push_back(createOwnerRecord);
    }
    fclose(ownersstream);

    for (int i = 0; fgets(str, 50, housesstream) != NULL; ++i) {
        std::string ownerAdress = str;
        fgets(str, 50, ownersstream);
        std::string phoneNumber = str;
        House createHouseRecord(ownerAdress, phoneNumber);
        Houses.push_back(createHouseRecord);
    }
    fclose(housesstream);

    for (int i = 0; fgets(str, 50, animalsstream) != NULL; ++i) {
        std::string petName = str;
        fgets(str, 50, animalsstream);
        std::string petWeight = str;
        Animal createAnimalRecord(petName, petWeight);
        Animals.push_back(createAnimalRecord);
    }
    fclose(animalsstream);

    int min = findMinLength(Owners, Animals, Houses);
    for (int i = 0; i < min; ++i) {                     //      создали запись о том, что Animals[0] это питомец Owners[0] и живут они по адресу Houses[0]
        Pet createPetRecord(Animals[i], Houses[i], Owners[i]);
        Pets.push_back(createPetRecord);
    }

    std::cout << "Информация о питомцах и их хозяевах\n------------------------------------------------------------\n";
    for (int i = 0; i < Pets.size(); ++i) {
        Pets[i].givePetsInfo();
    }

    Pets[1].changePetOwner(&Pets[1], Owners[0]);  // у животного появился новый хозяин
    
    std::cout << "Информация о питомцах и их хозяевах\n------------------------------------------------------------\n";
    for (int i = 0; i < Pets.size(); ++i) {
        Pets[i].givePetsInfo();
    }

    std::cout << "Информация о питомцах и их хозяевах\n------------------------------------------------------------\n";
    for (int i = 0; i < Pets.size(); ++i) {
        Pets[i].givePetsInfo();
    }

}
