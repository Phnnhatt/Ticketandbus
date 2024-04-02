#pragma once
using namespace std;
#include <iostream>
#include "ticket.h"
#include "bus.h"
class arrbus :public bus {
public:

	bus many_bus[18];

	arrbus();
	void booking();//booking chua them bus_destination va bus_source!!!
	void remove_ticket(string n, int p,int d,int t);
};