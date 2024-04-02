#pragma once

#include "Vehicle.h"
class Taxi : public Vehicle {
protected:
	string nameCustomer;
	int numTicket;
	double distance;
	int numOfTaxi;

public:
	Taxi(string m, string p);

	int choosingTaxi(int r);
	virtual void print();
	virtual void booking();
	virtual double payment();
	virtual void info();
};

