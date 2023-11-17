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

using namespace std;

static int petQuantity;

static std::vector<std::vector<std::string>> table;

void createTable(int petQuantity, std::vector<Pet> pets) {
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

Animal* vasya = new Cat("Vasya", "m", 5);
Owner artem = Owner("Silyanov S.E.", "08.08.2004", 2);
House* artemHouse = new House("Myatnaya 48", "+79831778095", 0);

static std::vector<Owner> owners;
static std::vector<Animal> animals;
static std::vector<House> houses;
static std::vector<Residence> residences;
static std::vector<Pet> pets;

static void petsToString() {
    for (auto pet : pets) {
        std::cout << std::endl;
        std::cout << pet.toString();
    }
}

int main() {
    Animal* bobik = createDog();
    Owner anton = createOwner();
    House* antonFlat = createFlat();

    animals.push_back(*vasya);
    animals.push_back(*bobik);
    owners.push_back(anton);
    owners.push_back(artem);
    houses.push_back(*antonFlat);
    houses.push_back(*artemHouse);

    Residence artemResidence = Residence(artemHouse, artem);
    Residence antonResidence = Residence(antonFlat, anton);

    Pet vasyaPet = Pet(vasya, artemResidence);
    petQuantity++;
    Pet bobikPet = Pet(bobik, antonResidence);
    petQuantity++;

    createTable(petQuantity, pets);
    showTable();

}
