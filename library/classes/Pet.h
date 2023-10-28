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
	Pet() = default;            // ����������� �� ���������

	Pet(Animal Animal, House House, Owner Owner) {      //����������� �� ����� �����������
		animal = Animal;
		house = House;
		owner = Owner;
	}

	void givePetInfo() {
		std::cout << "\n������: " << animal.getName();
		std::cout << "��� �������: " << owner.getName();
		std::cout << "����� ��������: " << house.getPhoneNumber() << std::endl;
		std::cout << "--------------------------------\n";
	}

	void changePetOwner(Pet* changingPet, Owner newOwner) {
		std::cout << "\n������: " << (*changingPet).animal.getName();
		std::cout << "������� ������: " << (*changingPet).owner.getName();
		(*changingPet).owner = newOwner;
		std::cout << "����� ������: " << newOwner.getName() << std::endl;
	}

	Animal getAnimal() {
		return this->animal;
	}
};