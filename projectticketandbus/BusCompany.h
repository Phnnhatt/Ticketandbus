#pragma once
#include "Vehicle.h"

const int VEHICLE_NUM = 4;

class BusCompany {
protected:
	

public:
	BusCompany();
	~BusCompany();
	Vehicle* vehicles[VEHICLE_NUM];

	void displayVehicles();
	//void addVehicle(Vehicle* p);
};


