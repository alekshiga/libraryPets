#include "Animal.h"
#include "Owner.h"
#include "House.h"
#include "Residence.h"
#include <iostream>

#pragma once
class Pet {
private:
	class Animal animal;
	class House house;
	class Owner owner;
public:
	Pet() = default;            // конструктор по умолчанию

	Pet(Animal Animal, House House, Owner Owner) {      //конструктор со всеми аргументами
		animal = Animal;
		house = House;
		owner = Owner;
	}

	void givePetInfo() {
		std::cout << "\nКличка: " << animal.getName();
		std::cout << "Имя хозяина: " << owner.getName();
		std::cout << "Номер телефона: " << house.getPhoneNumber() << std::endl;
		std::cout << "--------------------------------\n";
	}

	void changePetOwner(Pet* changingPet, Owner newOwner) {
		std::cout << "\nКличка: " << (*changingPet).animal.getName();
		std::cout << "Прежний хозяин: " << (*changingPet).owner.getName();
		(*changingPet).owner = newOwner;
		std::cout << "Новый хозяин: " << newOwner.getName() << std::endl;
	}

	Animal getAnimal() {
		return this->animal;
	}
};