#pragma once
#include <string>
#include <vector>
#include <iostream>

class Owner {
	private:
		std::string name;
		std::string birthday;
		int responsibilityDegree;
	public:
		Owner() {}

		Owner(std::string name, std::string birthday, int responsibilityDegree) {	//����������� �� ����� �����������
			this->name = name;
			this->responsibilityDegree = responsibilityDegree;
			this->birthday = birthday;
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

		std::string giveOwnersInfo() const {
			return "���: " + name + "���� ��������: " + birthday + "������� ���������������: " + std::to_string(responsibilityDegree) + "--------------------------------------\n";
		}
};