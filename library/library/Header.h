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
		if (Pet.Animal.name == (name + "\n")) return "Номер хозяина: " + Pet.Home.phoneNumber;
	}
	return "В списке нет питомца с такой кличкой";
}

void printInfo(std::vector<Pet> list) {
	for (auto& pet : list) {
		std::cout << "\nИнформация о питомце" << std::endl;
		std::cout << "Кличка: " << pet.Animal.name;
		std::cout << "Хозяин: " << pet.Owner.name;
		std::cout << "Номер для связи: " << pet.Home.phoneNumber << std::endl;
	}
}