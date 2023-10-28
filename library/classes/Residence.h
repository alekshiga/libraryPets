#include "Animal.h"
#include "Owner.h"
#include "House.h"
#include "string"

#pragma once
class Residence {
private:
	class House whereLiving;
	class Owner whoLiving;
public:
	Residence() = default;
	Residence(House setWhereLiving, Owner setWhoLiving) {
		whereLiving = setWhereLiving;
		whoLiving = setWhoLiving;
	}

	std::string getOwnerNameFromResidence() const {
		return whoLiving.getName();
	}

	House getHouseFromResidence() const {
		return whereLiving;
	}

	Owner getOwnerFromResidence() const {
		return whoLiving;
	}
};