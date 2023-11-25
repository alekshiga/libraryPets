#pragma once
#include <string>
#include <vector>
#include <iostream>

class House {
public:
	std::string adress;
	std::string phoneNumber;
	int howManyKidsLiving;

	friend std::string toString(const House house) {
		return "Adress: " + house.adress +
			"Phone number: " + house.phoneNumber +
			"Kids living: " + std::to_string(house.howManyKidsLiving) +
			"\n--------------------------------------\n";
	}
	House() = default;

	House(std::string adress, std::string phoneNumber, int howManyKidsLiving) {
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

House* createHouse() {
	std::string adress;
	std::cout << "Enter adress: " << std::endl;
	std::cin >> adress;
	std::string phoneNumber;
	std::cout << "Enter phone number: " << std::endl;
	std::cin >> phoneNumber;
	int howManyKidsLiving;
	std::cout << "How many kids living: " << std::endl;
	std::cin >> howManyKidsLiving;
	return new House(adress, phoneNumber, howManyKidsLiving);
}

class Flat : public House {

protected:
	int flatNumber;
	bool areNeighborsAngry;

public:
		Flat(std::string adress, int flatNumber, std::string phoneNumber, int howManyKidsLiving, bool areNeighborsAngry) {
		this->adress = adress;
		this->flatNumber = flatNumber;
		this->phoneNumber = phoneNumber;
		this->howManyKidsLiving = howManyKidsLiving;
		this->areNeighborsAngry = areNeighborsAngry;
	}

	std::string getAdress() const {
		std::string flatNumberString = std::to_string(flatNumber);
		return adress + ", flat " + flatNumberString;
	}

	std::string toString() const {
		std::string result;
		result = "Adress: " + adress + ", flat" + std::to_string(flatNumber) + "\n" +
			"Phone number: " + phoneNumber + "\n" +
			"Kids living: " + std::to_string(howManyKidsLiving) + "\n";
		if (areNeighborsAngry) {
			result += "Angry neighbors: yes\n";
		}
		else if (!areNeighborsAngry) {
			result += "Angry neighbors: no\n";
		}
		else {
			throw std::runtime_error("Should not reach here, invalid data");
		}
		result += "--------------------------------------\n";
		return result;
	}

	Flat& operator=(House& other) {
		if (this != &other) {
			this->adress = other.adress;
			this->howManyKidsLiving = other.howManyKidsLiving;
			this->phoneNumber = phoneNumber;
			this->areNeighborsAngry = false;
			this->flatNumber = 0;
		}
		return *this;
	}
};

House* createFlat() {
	std::string adress;
	std::cout << "Enter adress: " << std::endl;
	std::cin >> adress;
	int flatNumber;
	std::cout << "Enter flat number: " << std::endl;
	std::cin >> flatNumber;
	std::string phoneNumber;
	std::cout << "Enter phone number: " << std::endl;
	std::cin >> phoneNumber;
	int howManyKidsLiving;
	std::cout << "How many kids living: " << std::endl;
	std::cin >> howManyKidsLiving;
	bool areNeighborsAngry;
	std::cout << "If neighbors are angry enter 1, else enter 0: " << std::endl;
	std::cin >> areNeighborsAngry;
	return new Flat(adress, flatNumber, phoneNumber, howManyKidsLiving, areNeighborsAngry);
}