#pragma once
#include "Vehicle.h"
#include <iostream>
#include"ticket.h"
#include<string>
const int SEAT_NUMBER = 36;

class CityBus : public Vehicle {
protected:
	ticket* seat[SEAT_NUMBER];
public:
	CityBus(string m, string p);
	virtual void print();
	int available();
	int allowtobook(int n);
	virtual void display();
	//virtual void print();
	virtual void booking();
	//virtual double payment();
	//virtual void info();

};
/*
#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include "Vehicle.h"
#include "BusCompany.h"


using namespace std;

static int p = 0;

class CityBus : public Vehicle {

	char busn[5], driver[50], arrival[10], depart[10], from[10], to[10], seat[8][4][10];

public:
	CityBus();
	CityBus(string n, string p);
	~CityBus();
	
	void install();

	void allotment();

	void empty();

	void show();

	void avail();

	void position(int i);

	virtual void print();
	virtual void booking();
	virtual double payment();
	virtual void info();
}*/