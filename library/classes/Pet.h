#include "Animal.h"
#include "Owner.h"
#include "House.h"
#include "Residence.h"
#include <iostream>

#pragma once
class Pet {
private:
	class Animal* animal;
	class Residence residence;
public:
	Pet(Animal* Animal, Residence Residence) {
		*animal = *Animal;
		residence = Residence;
	}

	void toString() {
		std::cout << "\nКличка: " << (*animal).getName() << std::endl;
		std::cout << "Имя хозяина: " << residence.getOwnerFromResidence().getName();
		std::cout << "Номер телефона: " << residence.getHouseFromResidence()->getPhoneNumber() << std::endl;
		std::cout << "--------------------------------\n";
	}

	Animal* getAnimal() {
		return animal;
	}
};