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
std::vector<Animal> animals;
std::vector<House> houses;
std::vector<Residence> residences;
std::vector<Pet> pets;

Flat createFlat() {
    std::string adress;
    std::cout << "Введите адрес: " << std::endl;
    std::cin >> adress;
    int flatNumber;
    std::cout << "Введите номер квартиры: " << std::endl;
    std::cin >> flatNumber;
    std::string phoneNumber;
    std::cout << "Укажите номер телефона: " << std::endl;
    std::cin >> phoneNumber;
    int howManyKidsLiving;
    std::cout << "Укажите, сколько детей живут: " << std::endl;
    std::cin >> howManyKidsLiving;
    bool areNeighborsAngry;
    std::cout << "Введите 1, если соседи злые, введите 0, если соседи добрые: " << std::endl;
    std::cin >> areNeighborsAngry;
    Flat newFlat(adress, flatNumber, phoneNumber, howManyKidsLiving, areNeighborsAngry);
    return newFlat;
}

Dog createDog() {
    std::string name;
    std::cout << "Введите кличку животного: " << std::endl;
    std::cin >> name;
    std::string sex;
    std::cout << "Укажите пол (м/ж): " << std::endl;
    std::cin >> sex;
    std::string weightString;
    std::cout << "Укажите вес животного, кг: " << std::endl;
    std::cin >> weightString;
    int weight = std::stoi(weightString);
    return Dog(name, sex, weight);
}

Cat createCat() {
    std::string name;
    std::cout << "Введите кличку животного: " << std::endl;
    std::cin >> name;
    std::string sex;
    std::cout << "Укажите пол (м/ж): " << std::endl;
    std::cin >> sex;
    std::string weightString;
    std::cout << "Укажите вес животного, кг: " << std::endl;
    std::cin >> weightString;
    int weight = std::stoi(weightString);
    return Cat(name, sex, weight);
}

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
        Owner createOwnerRecord(ownerName, birthday, responsibilityDegree);
        owners.push_back(createOwnerRecord);
    }
    fclose(ownersstream);

    int userChoiceOfOwner;

    Flat flat = createFlat();
    Dog dog = createDog();

    houses.push_back(flat);
    animals.push_back(dog);

    animals[0].toString();

    // связываем дом и жителя в класс резиденция
    residences.push_back(Residence(houses[0], owners[0]));

    std::cout << "\nИнформация о всех хозяевах\n--------------------------------------\n";
    for (int i = 0; i < owners.size(); ++i) {
        std::cout << i + 1 << ". ";
        owners[i].toString();
    }
    std::cout << "\nИнформация о всех животных\n--------------------------------------\n";
    for (int i = 0; i < animals.size(); ++i) {
        std::cout << i + 1 << ". ";
        animals[i].toString();
    }
    std::cout << "\nИнформация о всех домах\n--------------------------------------\n";
    for (int i = 0; i < houses.size(); ++i) {
        std::cout << i + 1 << ". ";
        houses[i].toString();
    }
    int userChoiseOfAnimal;
    std::cout << "\nУкажите номер хозяина из списка, который хочет найти себе питомца: ";
    std::cin >> userChoiceOfOwner;
    std::cout << "Укажите номер животного из списка: ";
    std::cin >> userChoiseOfAnimal;
    char f;

    // создаем пару животное - резиденция

    do {
        std::cout << "\nСоздать пару " << owners[userChoiceOfOwner - 1].getName() << "----------\n" << animals[userChoiseOfAnimal - 1].getName() << animals[userChoiseOfAnimal - 1].getKind();
        std::cout << "Enter - да / Esc - нет\n" << std::endl;
        f = _getch();
    } while (f != 13 && f != 27);
    if (f == 13) {
        std::string findResidenceByName = owners[userChoiceOfOwner - 1].getName();
        for (int i = 0; i < residences.size(); i++) {
            if (findResidenceByName == residences[i].getOwnerNameFromResidence()) {
                Pet beforeAppendToVector(animals[userChoiseOfAnimal - 1], residences[i].getHouseFromResidence(), residences[i].getOwnerFromResidence());
                pets.push_back(beforeAppendToVector);
            }
        }
    }

    // например, поменяем хозяина у какого-нибудь животного, у которого уже есть хозяин

    int userChoiceOfPet;
    for (int i = 0; i < owners.size(); ++i) {
        std::cout << i + 1 << ".";
        owners[i].toString();
    }

    for (int i = 0; i < pets.size(); ++i) {
        std::cout << i + 1 << ".";
        pets[i].givePetInfo();
    }

    std::cout << "Введите номер питомца, у которого хотите поменять хозяина: ";
    std::cin >> userChoiceOfPet;
    std::cout << "Введите номер нового хозяина: ";
    std::cin >> userChoiceOfOwner;
    pets[0].changePetOwner(&(pets[userChoiceOfPet - 1]), owners[userChoiceOfOwner - 1]);
    for (int i = 0; i < pets.size(); ++i) {
        std::cout << i + 1 << ".";
        pets[i].givePetInfo();
    }
    std::cout << "Теперь у " + owners[userChoiceOfOwner - 1].getName() + "в квартире постоянно слышны ";
    for (int i = 0; i < 3; ++i) {
        pets[userChoiceOfPet - 1].getAnimal().voice();
    }
        
}