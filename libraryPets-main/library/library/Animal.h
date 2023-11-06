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

	Animal(std::string name, std::string kind, std::string sex, int age) {	//����������� �� ����� �����������
		this->name = name;
		this->age = age;
		this->kind = kind;
		this->sex = sex;
	}

	int getWeight() const {
		return age;
	}

	std::string getName() const {
		return name;
	}

	std::string getKind() const {
		return kind;
	}

	void operator++() {
		this->age++;
	}

	std::string toString() const {
		return "������: " + name + "���: " + kind + "���: " + sex + "�������: " + std::to_string(age) + "\n--------------------------------------\n";
	}
};