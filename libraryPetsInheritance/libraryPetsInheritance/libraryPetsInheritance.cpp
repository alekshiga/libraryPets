#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <stdexcept>
#include <concepts>
#include "Animal.h"
#include "Owner.h"
#include "House.h"
#include "Pet.h"
#include "Residence.h"

using namespace std;

static int petQuantity = 0;

static std::vector<std::vector<std::string>> table;

static std::vector<Owner> owners;
static std::vector<Animal*> animals;
static std::vector<House*> houses;
static std::vector<Residence> residences;
static std::vector<Pet> pets;

std::string searchByName() {
    bool f;
    std::string name;
    std::string birthday;
    std::cout << "Enter name: ";
    std::cin >> name;
    for (int i = 0; i < owners.size(); ++i) {
        if (owners[i].getName() == name) {
            return name + ", " + owners[i].getBirthday() + ", " + std::to_string(owners[i].getResponsibilityDegree()) + "\n\n";
        }
    }
    return "Owner not found\n\n";
}

static bool compareByName(const Animal* a, const Animal* b) {
    return a->getName() < b->getName();
}

void createTable(int petQuantity, std::vector<Pet> pets) {
    if (table.capacity() < pets.size()) table.resize(petQuantity);
    for (int i = 0; i < petQuantity; i++) {
        Pet pet = pets[i];
        table[i].push_back(pet.getAnimal()->getName());
        table[i].push_back(pet.getAnimal()->getKind());
        table[i].push_back(std::to_string(pet.getAnimal()->getAge()));
        table[i].push_back(pet.getAnimal()->getSex());
    }
}

void showTable() {
    for (int i = 0; i < petQuantity; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << table[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

static void petsToString() {
    for (auto pet : pets) {
        std::cout << std::endl;
        std::cout << pet.toString();
    }
}

static void push_pet(Pet pet) {
    pets.push_back(pet);
    petQuantity++;
}

template <typename T>
concept HasToString = requires(T t) {
    { t.toString() } -> std::convertible_to<std::string>;
};

template <HasToString T>
void stringPrint(const T& t) {
    std::cout << t.toString() << std::endl;
}

int main() {
    try {
        if (owners.size() == 0) {
            throw std::runtime_error("No owners in database");
        }
        else {
            std::cout << "Average animals for one owner " << animals.size() / owners.size() << "animal" << std::endl;;
        }
    }
    catch (std::runtime_error& e) {
        std::cout << "Dividing by zero\n" << e.what() << std::endl;
    }

    Animal* vasya = new Cat("Vasiliy", "m", 5);
    Animal* kozel = new Cat("Kozel", "m", 2);
    Animal* mittens = new Cat("Mittens", "m", 2);
    Owner sergey = Owner("Silyanov", "08.08.2004", 2);
    Owner timofey = Owner("Tagaev", "10.12.2004", 1);
    Owner vladimir = Owner("Ruppel", "04.02.2000", 0);
    owners.push_back(sergey);
    owners.push_back(timofey);
    owners.push_back(vladimir);
    House* house = new House("Myatnaya 48", "+79831778095", 0);
    House* flat = new Flat("Apples, 78", 44, "+79832178095", 0, true);
    Animal* goldy = new Dog("Goldy", "m", 5);

    animals.push_back(vasya);
    animals.push_back(mittens);
    animals.push_back(goldy);
    animals.push_back(kozel);

    std::sort(animals.begin(), animals.end(), compareByName);
    
    std::cout << "\tAnimal sorted list\n";
    for (auto animal : animals) {
        std::cout << animal->getName() << std::endl;
    }
    std::cout << std::endl;

    Residence res(house, sergey);
    Residence res1(flat, vladimir);
    Pet pet1(goldy, res1);
    Pet pet(vasya, res);
    push_pet(pet);
    push_pet(pet1);
    
    createTable(petQuantity, pets);
    showTable();
    std::cout << std::endl;

    std::cout << searchByName();

    stringPrint(sergey);
    stringPrint(*vasya);

    delete kozel;
    delete mittens;
    delete goldy;
    delete vasya;
}