#include <string>
#pragma once
class Animal {

public:
	std::string name;
	int weight;
	std::string kind;
	std::string sex;
	
	int getWeight() const {
		return weight;
	}

	std::string getName() const {
		return name;
	}

	std::string getKind() const {
		return kind;
	}

	void setWeight(int Weight) {
		weight = Weight;
	}
	virtual void toString() const = 0;

	virtual void voice() const = 0;
};

class Dog : public Animal {
public:
	Dog(std::string Name, std::string Sex, int Weight) {
		name = Name;
		sex = Sex;
		weight = Weight;
		kind = "dog";
	}

	void toString() const override {
		std::cout << "������: " << name << std::endl;
		std::cout << "���: dog\n";
		std::cout << "���: " << sex << std::endl;
		std::cout << "���, ��: " << weight << std::endl;
		std::cout << "--------------------------------------\n";
	}

	void voice() const override {
		std::cout << "Bark!!";
	}
};

class Cat : public Animal {

public:
	Cat(std::string Name, std::string Sex, int Weight) {
		name = Name;
		sex = Sex;
		weight = Weight;
		kind = "cat";
	}

	void toString() const override {
		std::cout << "������: " << name << std::endl;
		std::cout << "���: cat\n";
		std::cout << "���: " << sex << std::endl;
		std::cout << "���, ��: " << weight << std::endl;
		std::cout << "--------------------------------------\n";
	}

	void voice() const override {
		std::cout << "\nMeow!!";
	}
};

Dog createDog() {
	std::string name;
	std::cout << "������� ������ ������: " << std::endl;
	std::cin >> name;
	std::string sex;
	std::cout << "������� ��� (�/�): " << std::endl;
	std::cin >> sex;
	std::string weightString;
	std::cout << "������� ��� ������, ��: " << std::endl;
	std::cin >> weightString;
	int weight = std::stoi(weightString);
	return Dog(name, sex, weight);
}

Cat createCat() {
	std::string name;
	std::cout << "������� ������ ����/�����: " << std::endl;
	std::cin >> name;
	std::string sex;
	std::cout << "������� ��� (�/�): " << std::endl;
	std::cin >> sex;
	std::string weightString;
	std::cout << "������� ��� ����/�����, ��: " << std::endl;
	std::cin >> weightString;
	int weight = std::stoi(weightString);
	return Cat(name, sex, weight);
}