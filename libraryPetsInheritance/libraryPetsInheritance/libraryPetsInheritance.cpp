#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <algorithm>
#include <conio.h>
#include <stdexcept>
#include "Animal.h"
#include "Owner.h"
#include "House.h"
#include "Pet.h"
#include "Residence.h"

using namespace std;

static int petQuantity = 0;

static std::vector<std::vector<std::string>> table;

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

static std::vector<Owner> owners;
static std::vector<Animal*> animals;
static std::vector<House*> houses;
static std::vector<Residence> residences;
static std::vector<Pet> pets;

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

    Animal* vasya = new Cat("Vasya", "m", 5);
    Owner artem = Owner("Silyanov S.E.", "08.08.2004", 2);
    House* artemHouse = new House("Myatnaya 48", "+79831778095", 0);

    Animal* bobik = createDog();
    Owner anton = createOwner();
    House* antonFlat = createFlat();

    animals.push_back(vasya);

    Flat* mama = &artemHouse;

    Residence res(artemHouse, artem);
    Residence res1(antonFlat, anton);
    Pet pet1(bobik, res1);
    Pet pet(vasya, res);
    push_pet(pet);
    push_pet(pet1);
    
    createTable(petQuantity, pets);
    
    showTable();

    delete vasya;
    
}