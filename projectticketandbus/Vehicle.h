#pragma once
#include <string>
#include <string>

using namespace std;

class Vehicle {
protected:
	string model;
	string plate;

public:
	Vehicle(string n, string p);
	virtual void print() = 0;
	virtual double payment() = 0;
	virtual void booking() = 0;
	virtual void info() = 0;
};

