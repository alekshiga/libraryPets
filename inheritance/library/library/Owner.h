#pragma once
class Owner {
private:
	std::string name;
	std::string birthday;
	int responsibilityDegree;
public:
	Owner() = default;            // ??????????? ?? ?????????
	Owner(std::string name, std::string birthday, int responsibilityDegree) {	//??????????? ?? ????? ???????????
		this->name = name;
		this->birthday = birthday;
		this->responsibilityDegree = responsibilityDegree;
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

	std::string toString() const {
		return "Name: " + name + "\n" + 
		"Birthday: " + birthday + "\n" +
		"Responsibility degree: " + std::to_string(responsibilityDegree) + "\n" +
		"--------------------------------------\n";
	}
};

Owner createOwner() {
	std::string name;
	std::cout << "Enter owner's name: " << std::endl;
	std::cin >> name;
	std::string birthday;
	std::cout << "Enter owner's birthday: " << std::endl;
	std::cin >> birthday;
	int degree;
	std::cout << "Enter responsibility degree (0 - 2): " << std::endl;
	std::cin >> degree;
	Owner owner(name, birthday, degree);
	return owner;
}