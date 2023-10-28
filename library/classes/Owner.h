#pragma once
class Owner {
private:
	std::string name;
	std::string birthday;
	std::string responsibilityDegree;
public:
	Owner() = default;            // конструктор по умолчанию
	Owner(std::string setName, std::string setBirthday, std::string setResponsibilityDegree) {	//конструктор со всеми аргументами
		name = setName;
		responsibilityDegree = setResponsibilityDegree;
		birthday = setBirthday;
	}
	Owner createOwner() {
		std::string nameStorage;
		std::cout << "Введите ФИО: " << std::endl;
		std::cin >> nameStorage;
		std::string birthdayStorage;
		std::cout << "Укажите дату рождения: " << std::endl;
		std::cin >> birthdayStorage;
		std::string degreeStorage;
		std::cout << "Укажите степень ответственности хозяина: " << std::endl;
		std::cin >> degreeStorage;
		Owner newOwner(nameStorage, birthdayStorage, degreeStorage);
		return newOwner;
	}
	std::string getName() const {
		return name;
	}

	std::string getBirthday() const {
		return birthday;
	}

	std::string getResponsibilityDegree() const {
		return responsibilityDegree;
	}

	void toString() const {
		std::cout << "ФИО: " << name;
		std::cout << "Дата рождения: " << birthday;
		std::cout << "Степень ответственности: " << responsibilityDegree;
		std::cout << "--------------------------------------\n";
	}
};