#include "Taxi.h"
#include "Vehicle.h"
#include <iostream>
#include <string>
#include <cassert>

using namespace std;
Taxi::Taxi(string n, string p) : Vehicle(n, p)
{
	 nameCustomer = "NULL";
	 numTicket = 0;
	 distance = 0;
	 numOfTaxi = 0;
}

/*Taxi::Taxi() {
	string nameCustomer = "NULL";
	int numTicket = 0;
	double distance = 0;
	int numOfTaxi = 0;
}*/
void Taxi::print() {
		cout << "Choose the Taxi you want to go" << endl;
		cout << "1. This is a taxi of Monday. " << endl;
		cout << "2. This is a taxi of Wednesday. " << endl;
		cout << "3. This is a taxi of Sunday. " << endl;
		cin >> numOfTaxi;
		assert(numOfTaxi <= 3 && numOfTaxi >= 1);
		if (numOfTaxi == 1)
			Taxi("MondayTaxi", "4 seats");
		else if (numOfTaxi == 2)
			Taxi("WednesdayTaxi", "4 seats");
		else
			Taxi("SundayTaxi", "4 seats");
}

void Taxi::booking() {
	char c;
	cout << "Gia cuoc 11k cho 31km dau tien, 9k5 cho cac km tiep theo. Do u agree? (y/n)" << endl;
	cin >> c;
	if (c == 'n')
		exit(1);
	cout << "How many ticket do u want to book ( 4 seats is available)? " << endl;
	cin >> numTicket;
	assert(numTicket <= 4);
	cout << "The distance do u want to go? :" << endl;
	cin >> distance;
	cout << "Please enter your name: " << endl;
	//getline(cin, nameCustomer);
	getline(cin, nameCustomer);
	cout << nameCustomer;
}

double Taxi::payment() {
	double price = 0;
	if (distance <= 30) {
		price = numTicket * 11000 * distance;
		return price;
	}
	else 
		price = 30 * 11000 + (distance - 30) * 9500;
	return price;
}

void Taxi::info() {
	cout << "Name of customer: " << nameCustomer << endl;
	cout << "Kind of Taxi you had booked: ";
	if (numOfTaxi == 1)
		cout << "MondayTaxi with 4 seats" << endl;
	else if (numOfTaxi == 2)
		cout << "WednesdayTaxi with 4 seats" << endl;
	else
		cout << "SundayTaxi with 4 seats" << endl;
	cout << "Number of tickets you had booked: " << numTicket << endl;
}