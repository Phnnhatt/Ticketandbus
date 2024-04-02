#include "BusCompany.h"
#include "taxi.h"
#include "citybus.h"
#include <iostream>

using namespace std;
BusCompany::BusCompany()
{
	for (int i = 0; i < VEHICLE_NUM; i++)
		this->vehicles[i] = NULL;

	this->vehicles[0] = new CityBus("Bus", "52 seats");
	this->vehicles[1] = new Taxi("MondayTaxi", "4 seats");
	this->vehicles[1] = new Taxi("WednesdayTaxi", "4 seats");
	this->vehicles[1] = new Taxi("SundayTaxi", "4 seats");

}

BusCompany::~BusCompany()
{
	for (int i = 0; i < VEHICLE_NUM; i++) {
		if (this->vehicles[i] != NULL)
			delete this->vehicles[i];
	}
}

void BusCompany::displayVehicles() {
	for (int i = 0; i < VEHICLE_NUM; i++) {
		if (this->vehicles[i] != NULL) {
			cout << this->vehicles[i] << endl;
		}
	}
}

/*void BusCompany::addVehicle(Vehicle* p)
{
	for (int i = 0; i < VEHICLE_NUM; i++) {
		if (this->vehicles[i] == NULL) {
			this->vehicles[i] = p;
			break;
		}
	}
}
*/