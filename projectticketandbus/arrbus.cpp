using namespace std;
#include <iostream>
#include "ticket.h"
#include "bus.h"
#include "arrbus.h"



arrbus::arrbus() {
	for (int i = 0; i < 18; i++) {
		many_bus[i].bookedseat = 0;
		many_bus[i].busday = 0;
		many_bus[i].buspath = 0;
		many_bus[i].bustime = 0;
	}
}

void arrbus::booking() {
	int d, t, p;
	string n;
label1:
	cout << "Please enter the date you want to go \nIf you want to go on\n\tMonday please press 1\n\tWednesday please press 2\n\tFriday please press 3" << endl;
	cin >> d;
	if (d > 0 && d < 4) {
		goto label2;
	}
	else {
		cout << "you should enter a number between 1 and 3\n ";
		goto label1;
	}
label2:
	cout << "Please enter the time you want to go \nIf you want to from\n\t7h please press 1\n\t16h please press 2" << endl;
	cin >> t;
	if (t > 0 && t < 3) {
		goto label3;
	}
	else {
		cout << "you should enter 1 or 2\n ";
		goto label2;
	}
label3:
	cout << "Please enter the bus you want to go \nIf you want to go from\n\tDistrict 1 to district 2 please press 1\n\tDistrict 2 to district 3 please press 2\n\tDistrict 3 to district 4 please press 3" << endl;
	cin >> p;
	if (p > 0 && p < 4) {
		goto label4;
	}
	else {
		cout << "you should enter a number between 1 and 3\n ";
		goto label3;
	}
label4:
	cout << "please enter your name";
	cin >> n;

	for (int i = 0; i < 18; i++) {
		if ((many_bus[i].busday = d )&& (many_bus[i].buspath = p )&& (many_bus[i].time = t)) {
			if (many_bus[i].bookedseat < 36) {
				many_bus[i].seat[bookedseat].name = n;
				many_bus[i].seat[bookedseat].day = d;
				many_bus[i].seat[bookedseat].time = t;
				many_bus[i].seat[bookedseat].path = p;
			}
		}
	}
}

void arrbus::remove_ticket(string n, int p, int d, int t) {
	for (int i = 0; i < 18; i++) {
		if ((many_bus[i].busday == d) && (many_bus[i].buspath == p) && (many_bus[i].time == t)) {
			for (int j = 0; j < 18;j++) {
				if (many_bus[i].seat[j].name == n) {
					many_bus[i].seat[bookedseat].name = "0";
					/*many_bus[i].seat[bookedseat].day = d;
					many_bus[i].seat[bookedseat].time = t;
					many_bus[i].seat[bookedseat].path = p;*/
				}
			}
		}
	}
}
