#pragma once
class Owner {
private:
	std::string name;
	std::string birthday;
	int responsibilityDegree;
public:
	Owner() = default;            // ����������� �� ���������
	Owner(std::string setName, std::string setBirthday, int setResponsibilityDegree) {	//����������� �� ����� �����������
		name = setName;
		responsibilityDegree = setResponsibilityDegree;
		birthday = setBirthday;
	}
	Owner createOwner() {
		std::string name;
		std::cout << "������� ���: " << std::endl;
		std::cin >> name;
		std::string birthday;
		std::cout << "������� ���� ��������: " << std::endl;
		std::cin >> birthday;
		int degree;
		std::cout << "������� ������� ��������������� �������: " << std::endl;
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
		std::cout << "���: " << name << std::endl;
		std::cout << "���� ��������: " << birthday << std::endl;
		std::cout << "������� ���������������: " << responsibilityDegree << std::endl;
		std::cout << "--------------------------------------\n";
	}
};