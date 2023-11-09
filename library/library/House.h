#pragma once
#include <string>
#include <vector>
#include <iostream>

class House {
	private:
		std::string adress;
		std::string phoneNumber;
		int howManyKidsLiving;
	public:
		House() {}

		House(std::string adress, std::string phoneNumber, int howManyKidsLiving) {	//конструктор со всеми аргументами
			this->adress = adress;
			this->phoneNumber = phoneNumber;
			this->howManyKidsLiving = howManyKidsLiving;
		}

		friend std::string toString(const House house) {
			return "Адрес: " + house.getAdress() + "Номер телефона: " + house.getPhoneNumber() + "Детей живет в этом доме: " + std::to_string(house.getKidsInfo()) + "\n--------------------------------------\n";
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
