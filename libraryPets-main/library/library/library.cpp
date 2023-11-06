#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <algorithm>
#include <conio.h>
#include "Animal.h"
#include "Owner.h"
#include "House.h"
#include "Pet.h"
#include "Residence.h"

static int petQuantity;

static std::vector<Owner> owners;
static std::vector<Animal> animals;
static std::vector<House> houses;
static std::vector<Residence> residences;
static std::vector<Pet> pets;

static void petsToString() {
    for (auto pet : pets) {
        std::cout << pet.getAnimal().toString();
    }
}

Animal createAnimal() {
    std::string name;
    std::cout << "Введите кличку животного: " << std::endl;
    std::cin >> name;
    name += "\n";
    std::string kind;
    std::cout << "Укажите вид животного: " << std::endl;
    std::cin >> kind;
    kind = +"\n";
    std::string sex;
    std::cout << "Укажите пол животного(м/ж): " << std::endl;
    std::cin >> sex;
    sex += "\n";
    int age;
    std::cout << "Укажите вес животного, кг: " << std::endl;
    std::cin >> age;
    Animal animal(name, kind, sex, age);
    return animal;
}

House createHouse() {
    std::string adress;
    std::cout << "Введите адрес: " << std::endl;
    std::cin >> adress;
    adress += "\n";
    std::string phoneNumber;
    std::cout << "Укажите номер телефона: " << std::endl;
    std::cin >> phoneNumber;
    phoneNumber += "\n";
    int howManyKidsLiving;
    std::cout << "Укажите, сколько детей живут: " << std::endl;
    std::cin >> howManyKidsLiving;
    House house(adress, phoneNumber, howManyKidsLiving);
    return house;
}

Owner createOwner() {
    std::string name;
    std::cout << "Введите ФИО: " << std::endl;
    std::cin >> name;
    name += "\n";
    std::string birthday;
    std::cout << "Укажите дату рождения: " << std::endl;
    std::cin >> birthday;
    birthday += "\n";
    int responsibilityDegree;
    std::cout << "Укажите степень ответственности хозяина: " << std::endl;
    std::cin >> responsibilityDegree;
    Owner owner(name, birthday, responsibilityDegree);
    return owner;
}

static int petRecordsCount = 0;

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

    for (int i = 0; fgets(str, 30, ownersstream) != NULL; ++i) {
        std::string name = str;
        fgets(str, 15, ownersstream);
        std::string birthday = str;
        fgets(str, 3, ownersstream);
        int responsibilityDegree = std::stoi(str);
        Owner createOwnerRecord(name, birthday, responsibilityDegree);
        owners.push_back(createOwnerRecord);
    }
    fclose(ownersstream);

    for (int i = 0; fgets(str, 50, housesstream) != NULL; ++i) {
        std::string adress = str;
        fgets(str, 15, housesstream);
        std::string phoneNumber = str;
        fgets(str, 3, housesstream);
        int howManyKidsLiving = std::stoi(str);
        House createHouseRecord(adress, phoneNumber, howManyKidsLiving);
        houses.push_back(createHouseRecord);
    }
    fclose(housesstream);

    for (int i = 0; fgets(str, 20, animalsstream) != NULL; ++i) {
        std::string name = str;
        fgets(str, 20, animalsstream);
        std::string kind = str;
        fgets(str, 3, animalsstream);
        std::string sex = str;
        fgets(str, 5, animalsstream);
        int age = std::stoi(str);
        Animal createAnimalRecord(name, kind, sex, age);
        animals.push_back(createAnimalRecord);
    }
    fclose(animalsstream);

    Animal firstanimal = createAnimal();
    Owner firstowner = createOwner();
    House firsthouse = createHouse();

    animals.push_back(firstanimal);
    owners.push_back(firstowner);
    houses.push_back(firsthouse);

    Residence firstresidence = Residence(houses[0], owners[0]);
    Residence secondresidence = Residence(houses[1], owners[1]);
    Residence thirdresidence = Residence(houses[2], owners[2]);

    residences.push_back(firstresidence);
    residences.push_back(secondresidence);
    residences.push_back(thirdresidence);

    std::cout << "Информация о всех хозяевах\n--------------------------------------\n";
    for (auto residence : residences) {
        std::cout << residence.getOwnerFromResidence().getName();
        std::cout << residence.getHouseFromResidence().toString();
    }
    std::cout << "\nИнформация о всех питомцах\n--------------------------------------\n";

    Pet firstpet = Pet(animals[0], residences[0]);
    Pet secondpet = Pet(animals[1], residences[1]);
    Pet thirdpet = Pet(animals[2], residences[2]);

    pets.push_back(firstpet);
    pets.push_back(secondpet);
    pets.push_back(thirdpet);

    petsToString();

    pets[0].changeOwner(&pets[1], residences[1]);
    pets[1].changeOwner(&pets[2], residences[2]);
}
