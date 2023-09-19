#pragma once
#include <string>
#include <vector>

struct Animal {
	std::string name;
	int weight;
};

struct House {
	std::string street;
	int houseNumber;
	std::string phoneNumber;
};

struct petOwner {
	std::string name;
	struct birthDate {
		int day;
		int month;
		int year;
	} d;
};

struct Pet {
	struct Animal Animal;
	struct House Home;
	struct petOwner Owner;
};

std::string PetFound(std::string name, std::vector<struct Pet> list) {
	for (const auto& Pet : list) {
		if (Pet.Animal.name == (name + "\n")) return "����� �������: " + Pet.Home.phoneNumber;
	}
	return "� ������ ��� ������� � ����� �������";
}

void printInfo(std::vector<Pet> list) {
	for (auto& pet : list) {
		std::cout << "\n���������� � �������" << std::endl;
		std::cout << "������: " << pet.Animal.name;
		std::cout << "������: " << pet.Owner.name;
		std::cout << "����� ��� �����: " << pet.Home.phoneNumber << std::endl;
	}
}