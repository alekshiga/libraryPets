#include "Animal.h"
#include "Owner.h"
#include "House.h"
#include "Residence.h"
#include <iostream>

#pragma once
class Pet {
private:
	Animal* animal;
	Residence residence;
public:
	Pet(Animal* animal, Residence residence) {
		this->animal = animal;
		this->residence = residence;
	}

	Animal* getAnimal() const {
		return animal;
	}

	Residence getResidence() const {
		return this->residence;
	}

	std::string toString() const {
		return "Animal: " + animal->getName() + "\n" +
			"Owner's name: " + residence.getOwnerFromResidence().getName() + "\n" +
			"Owner's phone number: " + residence.getHouseFromResidence()->getPhoneNumber() + "\n" +
			"--------------------------------\n";
	}
};