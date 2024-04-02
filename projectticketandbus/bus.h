#pragma once
using namespace std;
#include <iostream>
#include "ticket.h"
class bus :public ticket {
public:
	ticket seat[36];
	int bookedseat;
	int buspath;// define its source and destinantion
	int busday;
	int bustime;
	string bus_source;
	string bus_destination;
	bus();
	bus(int p, int d, int t,string s, string des);//create a new bus

	void numberbookedseat();
};

