#pragma once
#include <string>
#include <vector>
#include <iostream>

class Owner {
	private:
		std::string name;
		std::string birthday;
		int responsibilityDegree;

		friend std::string toString(const Owner owner) {
			return "���: " + owner.getName() + "���� ��������: " + owner.getBirthday() + "������� ���������������: " + std::to_string(owner.getResponsibilityDegree()) + "\n--------------------------------------\n";
		}

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
};