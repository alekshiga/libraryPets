#pragma once
#include <string>
#include <vector>
#include <iostream>

class Animal {
private:
	std::string name;
	int age;
	std::string kind;
	std::string sex;

public:
	Animal() {}

	Animal(std::string name, std::string kind, std::string sex, int age) {	//конструктор со всеми аргументами
		this->name = name;
		this->age = age;
		this->kind = kind;
		this->sex = sex;
	}

	friend std::string toString(const Animal animal) {
		return "Кличка: " + animal.name + "Вид: " + animal.kind + "Пол: " + animal.sex + "Возраст: " + std::to_string(animal.age) + "\n--------------------------------------\n";
	}

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

	std::string toString() const {
		return "Кличка: " + name + "Вид: " + kind + "Пол: " + sex + "Возраст: " + std::to_string(age) + "\n--------------------------------------\n";
	}
};