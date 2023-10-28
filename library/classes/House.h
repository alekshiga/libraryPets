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

	virtual void toString() const = 0;
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
		std::cout << "Адрес: " << adress << ", квартира " << flatNumber << std::endl;
		std::cout << "Номер телефона: " << phoneNumber << std::endl;
		std::cout << "Детей живет в квартире: " << howManyKidsLiving << std::endl;
		if (areNeighborsAngry) {
			std::cout << "Злые соседи: yes" << std::endl;
		} else if (!areNeighborsAngry) {
			std::cout << "Злые соседи: no" << std::endl;
		} else {
			throw std::runtime_error("Should not reach here, invalid data");
		}
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
		std::cout << "Адрес: " << adress << std::endl;
		std::cout << "Номер телефона: " << phoneNumber << std::endl;
		std::cout << "Детей живет в этом доме: " << howManyKidsLiving << std::endl;
		std::cout << "--------------------------------------\n";
	}
};

Flat createFlat() {
	std::string adress;
	std::cout << "Введите адрес: " << std::endl;
	std::cin >> adress;
	int flatNumber;
	std::cout << "Введите номер квартиры: " << std::endl;
	std::cin >> flatNumber;
	std::string phoneNumber;
	std::cout << "Укажите номер телефона: " << std::endl;
	std::cin >> phoneNumber;
	int howManyKidsLiving;
	std::cout << "Укажите, сколько детей живут: " << std::endl;
	std::cin >> howManyKidsLiving;
	bool areNeighborsAngry;
	std::cout << "Введите 1, если соседи злые, введите 0, если соседи добрые: " << std::endl;
	std::cin >> areNeighborsAngry;
	Flat newFlat(adress, flatNumber, phoneNumber, howManyKidsLiving, areNeighborsAngry);
	return newFlat;
}

PrivateHouse createHouse() {
	std::string adress;
	std::cout << "Введите адрес: " << std::endl;
	std::cin >> adress;
	std::string phoneNumber;
	std::cout << "Укажите номер телефона: " << std::endl;
	std::cin >> phoneNumber;
	int howManyKidsLiving;
	std::cout << "Укажите, сколько детей живут: " << std::endl;
	std::cin >> howManyKidsLiving;
	PrivateHouse newPrivateHouse(adress, phoneNumber, howManyKidsLiving);
	return newPrivateHouse;
}