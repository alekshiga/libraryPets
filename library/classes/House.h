#include <string>

#pragma once
class House {

public:
	std::string adress;
	std::string phoneNumber;
	int howManyKidsLiving;

	std::string getPhoneNumber() const {
		return phoneNumber;
	}

	virtual std::string getAdress() const {return "";}

	int getKidsInfo() const {
		return howManyKidsLiving;
	}

	void setAdress(std::string newAdress) {
		adress = newAdress;
	}

	void setPhoneNumber(std::string newPhone) {
		phoneNumber = newPhone;
	}

	void setKidsAmount(int newHowManyKidsLiving) {
		howManyKidsLiving = newHowManyKidsLiving;
	}

	virtual void toString() const {}
};

class Flat : public House {

private:
	int flatNumber;
	bool areNeighborsAngry;

public:
	Flat(std::string Adress, int FlatNumber, std::string PhoneNumber, int HowManyKidsLiving, bool AreNeighborsAngry) {
		adress = Adress;
		flatNumber = FlatNumber;
		phoneNumber = PhoneNumber;
		howManyKidsLiving = HowManyKidsLiving;
		areNeighborsAngry = AreNeighborsAngry;
	}

	std::string getAdress() const override {
		std::string flatNumberString = std::to_string(flatNumber);
		return adress + "Квартира " + flatNumberString;
	}

	void toString() const override {
		std::cout << "Адрес: " << adress << "Квартира " + flatNumber;
		std::cout << "Номер телефона: " << phoneNumber;
		std::cout << "Детей живет в квартире: " << howManyKidsLiving;
		std::cout << "--------------------------------------\n";
	}
};

class PrivateHouse : House {

public:
	PrivateHouse(std::string Adress, std::string PhoneNumber, int HowManyKidsLiving) {
		adress = Adress;
		phoneNumber = PhoneNumber;
		howManyKidsLiving = HowManyKidsLiving;
	}

	std::string getAdress() const override {
		return adress;
	}

	void toString() const override {
		std::cout << "Адрес: " << adress;
		std::cout << "Номер телефона: " << phoneNumber;
		std::cout << "Детей живет в этом доме: " << howManyKidsLiving;
		std::cout << "--------------------------------------\n";
	}
};