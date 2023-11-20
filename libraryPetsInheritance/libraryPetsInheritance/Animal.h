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

	virtual std::string toString() const {
		return "Name: " + name + "\n" +
				"Kind: " + kind + "\n" +
				"Sex: " + sex + "\n" +
				"Age: " + std::to_string(age) + "\n" +
				"--------------------------------------\n";
	}

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

	std::string toString() const {
		return "Name: " + name + "\n" + 
		"Kind: dog\n" + 
		"Sex: " + sex + "\n" +
		"Age: " + std::to_string(age) + "\n" + 
		"--------------------------------------\n";
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

	std::string toString() const {
		return "Name: " + name + "\n" +
		"Kind: cat\n" +
		"Sex: " + sex + "\n" +
		"Age: " + std::to_string(age) + "\n" +
		"--------------------------------------\n";
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