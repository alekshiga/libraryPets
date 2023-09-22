#pragma once
#include <string>
#include <vector>

class Animal {
private:
	std::string name;
	std::string weight;
public:
	Animal() = default;
	Animal(std::string setName, std::string setWeight) {	//конструктор со всеми аргументами
		name = setName;
		weight = setWeight;
	}
	
	std::string getWeight() const {
		return weight;
	}

	std::string getName() const {
		return name;
	}

	void setWeight(std::string newWeight) {
		weight = newWeight;
	}
};

class House {
private:
	std::string adress;
	std::string phoneNumber;
public:
	House() = default;             // конструктор по умолчанию
	House(std::string setAdress, std::string setPhoneNumber) {	//конструктор со всеми аргументами
		adress = setAdress;
		phoneNumber = setPhoneNumber;
	}

	std::string getPhoneNumber() const {
		return phoneNumber;
	}

	std::string getAdress() const {
		return adress;
	}

	void setAdress(std::string newAdress) {
		adress = newAdress;
	}

	void setPhoneNumber(std::string newPhone) {
		phoneNumber = newPhone;
	}
};

class Owner {
private:
	std::string name;
	std::string birthday;
public:
	Owner() = default;            // конструктор по умолчанию
	Owner(std::string setName, std::string setBirthday) {	//конструктор со всеми аргументами
		name = setName;
		birthday = setBirthday;
	}

	std::string getName() const {
		return name;
	}

	std::string getBirthday() const {
		return birthday;
	}

};


class Pet {
private:
	class Animal AnimalInPet;
	class House HouseInPet;
	class Owner OwnerInPet;
public:
	Pet() = default;            // конструктор по умолчанию

	Pet(Animal setAnimal, House setHouse, Owner setOwner) {      //конструктор со всеми аргументами
		AnimalInPet = setAnimal;
		HouseInPet = setHouse;
		OwnerInPet = setOwner;
	}

	void givePetsInfo() {
		std::cout << "\nКличка: " << AnimalInPet.getName();
		std::cout << "Имя хозяина: " << OwnerInPet.getName();
		std::cout << "Номер телефона: " << HouseInPet.getPhoneNumber() << std::endl;
		std::cout << "------------------------------------------------------------\n";
	}

	Pet changePetOwner(Pet* changingPet, Owner newOwner) {
		std::cout << "\nКличка: " << (*changingPet).AnimalInPet.getName();
		std::cout << "Прежний хозяин: " << (*changingPet).OwnerInPet.getName();
		(*changingPet).OwnerInPet = newOwner;
		std::cout << "Новый хозяин: " << newOwner.getName() << std::endl;
		return *changingPet;
	}
};

