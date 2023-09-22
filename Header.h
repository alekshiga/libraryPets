#pragma once
#pragma once
#include <string>
#include <vector>

struct Animal {
	std::string name, weight;
} AnimalExample;

struct House {
	std::string adress;
	std::string phoneNumber;
} HouseExample;

struct Owner {
	std::string name;
	std::string birthDate;
} OwnerExample;

struct Pet {
	struct Animal Animal;
	struct House House;
	struct Owner Owner;
};

std::string PetFound(std::string name, std::vector<Pet> list) {
	for (const auto& pet : list) {
		if (pet.Animal.name == (name + "\n")) return "Номер хозяина: " + pet.House.phoneNumber;
	}
	return "В списке нет питомца с таким именем";
}

void printInfo(std::vector<Pet> pets) {
	std::cout << "\nИнформация о питомцах\n-----------------------------------------------------" << std::endl;
	for (auto& pet : pets) {
		std::cout << "Кличка: " << pet.Animal.name;
		std::cout << "Хозяин: " << pet.Owner.name;
		std::cout << "Номер телефона: " << pet.House.phoneNumber;
		std::cout << "Адрес: " << pet.House.adress;
		std::cout << "------------------------------------------------------\n";
	}
}

void createRecord(Pet* newPet) {
	std::string storage;
	std::cout << "Введите кличку животного" << std::endl;
	std::cin >> storage;
	(*newPet).Animal.name = storage + "\n";
	std::cout << "Укажите вес животного" << std::endl;
	std::cin >> storage;
	(*newPet).Animal.weight = storage + "\n";
	std::cout << "Введите имя хозяина" << std::endl;
	std::cin >> storage;
	(*newPet).Owner.name = storage + "\n";
	std::cout << "Введите дату рождения хозяина" << std::endl;
	std::cin >> storage;
	(*newPet).Owner.birthDate = storage + "\n";
	std::cout << "Укажите адрес проживания" << std::endl;
	std::cin >> storage;
	(*newPet).House.adress = storage + "\n";
	std::cout << "Укажите номер телефона" << std::endl;
	std::cin >> storage;
	(*newPet).House.phoneNumber = storage + "\n";
}
