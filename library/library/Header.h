#pragma once
#include <string>
#include <vector>

class Animal {
private:
	std::string name;
	std::string weight;
public:
	Animal() = default;
	Animal(std::string setName, std::string setWeight) {	//����������� �� ����� �����������
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
	House() = default;             // ����������� �� ���������
	House(std::string setAdress, std::string setPhoneNumber) {	//����������� �� ����� �����������
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
	Owner() = default;            // ����������� �� ���������
	Owner(std::string setName, std::string setBirthday) {	//����������� �� ����� �����������
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
	Pet() = default;            // ����������� �� ���������

	Pet(Animal setAnimal, House setHouse, Owner setOwner) {      //����������� �� ����� �����������
		AnimalInPet = setAnimal;
		HouseInPet = setHouse;
		OwnerInPet = setOwner;
	}

	void givePetsInfo() {
		std::cout << "\n������: " << AnimalInPet.getName();
		std::cout << "��� �������: " << OwnerInPet.getName();
		std::cout << "����� ��������: " << HouseInPet.getPhoneNumber() << std::endl;
		std::cout << "------------------------------------------------------------\n";
	}

	Pet changePetOwner(Pet* changingPet, Owner newOwner) {
		std::cout << "\n������: " << (*changingPet).AnimalInPet.getName();
		std::cout << "������� ������: " << (*changingPet).OwnerInPet.getName();
		(*changingPet).OwnerInPet = newOwner;
		std::cout << "����� ������: " << newOwner.getName() << std::endl;
		return *changingPet;
	}
};

