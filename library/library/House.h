#pragma once
#include <string>
#include <vector>
#include <iostream>

class House {
	private:
		std::string adress;
		std::string phoneNumber;
		int howManyKidsLiving;

		friend std::string toString(const House house) {
			return "�����: " + house.getAdress() + "����� ��������: " + house.getPhoneNumber() + "����� ����� � ���� ����: " + std::to_string(house.getKidsInfo()) + "\n--------------------------------------\n";
		}

	public:
		House() {}

		House(std::string adress, std::string phoneNumber, int howManyKidsLiving) {	//����������� �� ����� �����������
			this->adress = adress;
			this->phoneNumber = phoneNumber;
			this->howManyKidsLiving = howManyKidsLiving;
		}

		std::string getPhoneNumber() const {
			return phoneNumber;
		}

		std::string getAdress() const {
			return adress;
		}

		int getKidsInfo() const {
			return howManyKidsLiving;
		}

		void setPhoneNumber(std::string phoneNumber) {
			this->phoneNumber = phoneNumber;
		}

		void setKidsAmount(int howManyKidsLiving) {
			this->howManyKidsLiving = howManyKidsLiving;
		}

		void operator++() {
			this->howManyKidsLiving++;
		}
};
