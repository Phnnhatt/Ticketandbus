#include<iostream>
#include "BusCompany.h"
#include "Taxi.h"
#include"CityBus.h"
#include <string.h>

using namespace std;

void checkIn(BusCompany &mat);

int main() {
	BusCompany myCom;
	checkIn(myCom);
	/*Taxi* p = new Taxi("Camry", "22222");
	myCom.addVehicle(p);
	CityBus* q = new CityBus("Bus01", "333333");
	myCom.addVehicle(q);
	q->booking();
	myCom.displayVehicles();

	q->display();*/

	return 0;
}


void checkIn(BusCompany& mat) {
	string kind;
	do {
		mat.displayVehicles();
		cout << "Choose Taxi or Bus: " << endl;
		cin >> kind;
		if ((kind == "Bus") || (kind == "bus")) {
			CityBus B("", "");
			B.booking();
		}
		if ((kind == "Taxi") || (kind == "taxi")) {
			Taxi A("", "");
			A.print();
			A.booking();
			A.info();
		}
		else {
			cout << "Unavailable input" << endl;
			break;
		}
	} while (1);


}