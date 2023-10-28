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
		std::cout << "Кличка: " << name << std::endl;
		std::cout << "Вид: dog\n";
		std::cout << "Пол: " << sex << std::endl;
		std::cout << "Вес, кг: " << weight << std::endl;
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
		std::cout << "Кличка: " << name << std::endl;
		std::cout << "Вид: cat\n";
		std::cout << "Пол: " << sex << std::endl;
		std::cout << "Вес, кг: " << weight << std::endl;
		std::cout << "--------------------------------------\n";
	}

	void voice() const override {
		std::cout << "\nMeow!!";
	}
};

Dog createDog() {
	std::string name;
	std::cout << "Введите кличку собаки: " << std::endl;
	std::cin >> name;
	std::string sex;
	std::cout << "Укажите пол (м/ж): " << std::endl;
	std::cin >> sex;
	std::string weightString;
	std::cout << "Укажите вес собаки, кг: " << std::endl;
	std::cin >> weightString;
	int weight = std::stoi(weightString);
	return Dog(name, sex, weight);
}

Cat createCat() {
	std::string name;
	std::cout << "Введите кличку кота/кошки: " << std::endl;
	std::cin >> name;
	std::string sex;
	std::cout << "Укажите пол (м/ж): " << std::endl;
	std::cin >> sex;
	std::string weightString;
	std::cout << "Укажите вес кота/кошки, кг: " << std::endl;
	std::cin >> weightString;
	int weight = std::stoi(weightString);
	return Cat(name, sex, weight);
}