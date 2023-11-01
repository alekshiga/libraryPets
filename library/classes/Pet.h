#include "Animal.h"
#include "Owner.h"
#include "House.h"
#include "Residence.h"
#include <iostream>

#pragma once
class Pet {
private:
	Animal* animal;
	House* house;
	Owner owner;
public:
	Pet(Animal* animal, Owner owner, House* house)
		: animal(animal), house(house), owner(owner)
	{}

	void toString() {
		std::cout << "\nКличка: " << (*animal).getName() << std::endl;
		std::cout << "Имя хозяина: " << owner.getName();
		std::cout << "Номер телефона: " << (*house).getPhoneNumber() << std::endl;
		std::cout << "--------------------------------\n";
	}

	Animal* getAnimal() {
		return animal;
	}
};