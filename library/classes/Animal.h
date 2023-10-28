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
	virtual void toString() const {}

	virtual void voice() const {}
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
		std::cout << "������: " << name;
		std::cout << "���: dog\n";
		std::cout << "���: " << sex;
		std::cout << "���, ��: " << weight;
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
		std::cout << "������: " << name;
		std::cout << "���: cat\n";
		std::cout << "���: " << sex;
		std::cout << "���, ��: " << weight;
		std::cout << "--------------------------------------\n";
	}

	void voice() const override {
		std::cout << "\nMeow!!";
	}
};