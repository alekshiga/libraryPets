#pragma once
class Owner {
private:
	std::string name;
	std::string birthday;
	std::string responsibilityDegree;
public:
	Owner() = default;            // ����������� �� ���������
	Owner(std::string setName, std::string setBirthday, std::string setResponsibilityDegree) {	//����������� �� ����� �����������
		name = setName;
		responsibilityDegree = setResponsibilityDegree;
		birthday = setBirthday;
	}
	Owner createOwner() {
		std::string nameStorage;
		std::cout << "������� ���: " << std::endl;
		std::cin >> nameStorage;
		std::string birthdayStorage;
		std::cout << "������� ���� ��������: " << std::endl;
		std::cin >> birthdayStorage;
		std::string degreeStorage;
		std::cout << "������� ������� ��������������� �������: " << std::endl;
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
		std::cout << "���: " << name;
		std::cout << "���� ��������: " << birthday;
		std::cout << "������� ���������������: " << responsibilityDegree;
		std::cout << "--------------------------------------\n";
	}
};