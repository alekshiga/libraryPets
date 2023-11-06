#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Owner.h"
#include "House.h"

class Residence {
	private:
		class House whereLiving;
		class Owner whoLiving;
	public:
		Residence() = default;
		Residence(House whereLiving, Owner whoLiving) {
			this->whereLiving = whereLiving;
			this->whoLiving = whoLiving;
		}

		House getHouseFromResidence() const {
			return whereLiving;
		}

		Owner getOwnerFromResidence() const {
			return whoLiving;
		}
};