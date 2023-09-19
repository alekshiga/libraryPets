#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Header.h"
#include <windows.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const char* name = "data.txt";
    FILE* file = fopen(name, "r");
    if (file == NULL) throw std::runtime_error("Файл не был открыт!");
    else {
        char* str = (char*)calloc(50, sizeof(char));
        fgets(str, 50, file);
        int count = int(*str) - 48;
        std::vector<petOwner> Owners;
        std::vector<House> Houses;
        std::vector<Animal> Animals;
        std::vector<Pet> Pets;
        for (int i = 0; i < count; ++i) {
            petOwner BufferPerson;
            fgets(str, 50, file);
            BufferPerson.name = str;
            fgets(str, 50, file);
            BufferPerson.d.day = atoi(str);
            fgets(str, 50, file);
            BufferPerson.d.month = atoi(str);
            fgets(str, 50, file);
            BufferPerson.d.year = atoi(str);
            Owners.push_back(BufferPerson);
            House BufferHome;
            fgets(str, 50, file);
            BufferHome.street = str;
            fgets(str, 50, file);
            BufferHome.houseNumber = atoi(str);
            fgets(str, 50, file);
            BufferHome.phoneNumber = str;
            Houses.push_back(BufferHome);
            Animal BufferAnimal;
            fgets(str, 50, file);
            BufferAnimal.name = str;
            fgets(str, 50, file);
            BufferAnimal.weight = atoi(str);
            Animals.push_back(BufferAnimal);
            Pet bufferPet;
            bufferPet.Animal = BufferAnimal;
            bufferPet.Home = BufferHome;
            bufferPet.Owner = BufferPerson;
            Pets.push_back(bufferPet);
        }
        printInfo(Pets);
        std::string search;
        std::cout << "Введите кличку животного, чтобы узнать номер его хозяина" << std::endl;
        std::cin >> search;
        std::cout << PetFound(search, Pets) << std::endl;
    }
}
