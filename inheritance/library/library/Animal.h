#pragma once
#include <string>
#include <vector>
#include <iostream>

class Animal {
protected:
	std::string name;
	int age;
	std::string kind;
	std::string sex;

	friend std::string toString(const Animal* animal) {
		return "Кличка: " + animal->name + 
			"Вид: " + animal->kind + 
			"Пол: " + animal->sex +
			"Возраст: " + std::to_string(animal->age) +
			"\n--------------------------------------\n";
	}

	Animal() = default;

public:
	int getAge() const {
		return age;
	}

	std::string getName() const {
		return name;
	}

	std::string getKind() const {
		return kind;
	}

	std::string getSex() const {
		return sex;
	}

	void operator++() {
		this->age++;
	}

	virtual void toString() const = 0;

	virtual void voice() const = 0;
};

class Dog : public Animal {
public:
	Dog(std::string name, std::string sex, int age) {
		this->name = name;
		this->sex = sex;
		this->age = age;
		kind = "dog";
	}

	void toString() const override {
		std::cout << "Name: " << name << std::endl;
		std::cout << "Kind: dog\n";
		std::cout << "Sex: " << sex << std::endl;
		std::cout << "Age: " << age << std::endl;
		std::cout << "--------------------------------------\n";
	}

	void voice() const override {
		std::cout << "Bark!!";
	}
};

class Cat : public Animal {

public:
	Cat(std::string name, std::string sex, int age) {
		this->name = name;
		this->sex = sex;
		this->age = age;
		this->kind = "cat";
	}

	void toString() const override {
		std::cout << "Name: " << name << std::endl;
		std::cout << "Kind: cat\n";
		std::cout << "Sex: " << sex << std::endl;
		std::cout << "Age: " << age << std::endl;
		std::cout << "--------------------------------------\n";
	}

	void voice() const override {
		std::cout << "\nMeow!!";
	}
};

Animal* createDog() {
	std::string name;
	std::cout << "Enter dog's name: " << std::endl;
	std::cin >> name;
	std::string sex;
	std::cout << "Enter dog's sex: " << std::endl;
	std::cin >> sex;
	int age;
	std::cout << "Enter dog's age: " << std::endl;
	std::cin >> age;
	return new Dog(name, sex, age);
}

Animal* createCat() {
	std::string name;
	std::cout << "Enter cat's name: " << std::endl;
	std::cin >> name;
	std::string sex;
	std::cout << "Enter cat's sex: " << std::endl;
	std::cin >> sex;
	int age;
	std::cout << "Enter cat's age: " << std::endl;
	std::cin >> age;
	return new Cat(name, sex, age);
}