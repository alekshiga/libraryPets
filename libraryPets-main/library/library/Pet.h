#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Animal.h"
#include "Owner.h"
#include "House.h"
#include "Residence.h"

class Pet {
private:
	Animal animal;
	Residence residence;
public:
	Pet(Animal animal, Residence residence) {
		this->animal = animal;
		this->residence = residence;
	}

	Animal getAnimal() const {
		return this->animal;
	}

	Residence getResidence() const {
		return this->residence;
	}

	void changeOwner(Pet* changingPet, Residence residence) {
		std::cout << "\nКличка: " << (*changingPet).animal.getName();
		std::cout << "Прежний хозяин: " << (*changingPet).residence.getOwnerFromResidence().getName();
		(*changingPet).residence = residence;
		std::cout << "Новый хозяин: " << residence.getOwnerFromResidence().getName() << std::endl;
	}
};