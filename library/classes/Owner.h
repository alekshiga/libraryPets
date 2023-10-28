#pragma once
class Owner {
private:
	std::string name;
	std::string birthday;
	int responsibilityDegree;
public:
	Owner() = default;            // конструктор по умолчанию
	Owner(std::string setName, std::string setBirthday, int setResponsibilityDegree) {	//конструктор со всеми аргументами
		name = setName;
		responsibilityDegree = setResponsibilityDegree;
		birthday = setBirthday;
	}
	Owner createOwner() {
		std::string name;
		std::cout << "Введите ФИО: " << std::endl;
		std::cin >> name;
		std::string birthday;
		std::cout << "Укажите дату рождения: " << std::endl;
		std::cin >> birthday;
		int degree;
		std::cout << "Укажите степень ответственности хозяина: " << std::endl;
		std::cin >> degree;
		Owner newOwner(name, birthday, degree);
		return newOwner;
	}
	std::string getName() const {
		return name;
	}

	std::string getBirthday() const {
		return birthday;
	}

	int getResponsibilityDegree() const {
		return responsibilityDegree;
	}

	void toString() const {
		std::cout << "ФИО: " << name << std::endl;
		std::cout << "Дата рождения: " << birthday << std::endl;
		std::cout << "Степень ответственности: " << responsibilityDegree << std::endl;
		std::cout << "--------------------------------------\n";
	}
};