using namespace std;
#include <iostream>
#include "ticket.h"
#include "bus.h"

bus::bus() {
	for (int i = 0; i < 36; i++) {
		seat[i].name = "";
		seat[i].day = 0;
		seat[i].path = 0;
		seat[i].time = 0;
	}
	buspath = 0;
	busday = 0;
	bustime = 0;
	bookedseat = 0;
	bus_destination = "0";
	bus_source = "0";
}

bus::bus(int p, int d, int t,string s,string des){
	for (int i = 0; i < 36; i++) {
		seat[i].name = "";
		seat[i].day = 0;
		seat[i].path = 0;
		seat[i].time = 0;
	}
	buspath = p;
	busday = d;
	bustime = t;
	bookedseat = 0;
	bus_destination = "0";
	bus_source = "0";
}

void bus::numberbookedseat() {
	if (bookedseat > 36) {
		cout << "the bus has been full, you cannot book this bus anymore" << endl;
	}
	else {
		bookedseat++;
	}
}

