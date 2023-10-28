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
		std::cout << "\n������: " << (*animal).getName() << std::endl;
		std::cout << "��� �������: " << residence.getOwnerFromResidence().getName();
		std::cout << "����� ��������: " << residence.getHouseFromResidence()->getPhoneNumber() << std::endl;
		std::cout << "--------------------------------\n";
	}

	Animal* getAnimal() {
		return animal;
	}
};