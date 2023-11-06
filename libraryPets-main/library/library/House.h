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

		std::string toString() const {
			return "Адрес: " + adress + "Номер телефона: " + phoneNumber + "Детей живет в этом доме: " + std::to_string(howManyKidsLiving) + "\n--------------------------------------\n";
		}
};
