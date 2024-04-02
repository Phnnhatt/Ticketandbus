#include "CityBus.h"

CityBus::CityBus(string n, string p) : Vehicle(n, p) {
	for (int i = 0; i < SEAT_NUMBER; i++) {
		seat[i] = new ticket;
		seat[i]->name = "0";
		seat[i]->path = 0;
		//cout << i<<"\t"<<seat[i]->name<<", "<<seat[i]->path<<endl;
	}
}

void CityBus::print() {
	cout << "This is a city bus. Model: " << model << ". Plate: " << plate << endl;
}

int CityBus::available() {
	for (int i = 0; i < SEAT_NUMBER; i++) {
		if (seat[i]->name == "0") {
			return i;
		}
		else
			return SEAT_NUMBER;
	}
}

int CityBus::allowtobook(int n) {
	int set = available() + n;
	if (set < SEAT_NUMBER - 1) {
		return available();
	}
	else
		return SEAT_NUMBER + 1;
}

void CityBus::booking() {
	string n = "0";
	int book, set, last;
	set = 0; last = 0;
label1:
	cout << "how many ticket ";
	cin >> book;
	if (allowtobook(book) != SEAT_NUMBER + 1) {
		set = available(); last = available() + book - 1;
		//cout << set << "\t" << last << endl;
		for (int i = set; i <= last; i++) {
			cout << "name pls: ";
			if (i == set)
				cin.ignore(1, '\n');
			getline(cin, n, '\n');

			seat[i]->name = n;

			cout << seat[i]->name << endl;
		}
	}
	else {
		cout << "sorry there is no seat left to book\n";
		goto label1;
	}
}

void CityBus::display() {
	int count = 0;
	string n = "";
	cout << "name you want to find pls: ";
	getline(cin, n, '\n');
	for (int i = 0; i < SEAT_NUMBER; i++) {
		if (seat[i]->name == n)
			count++;
	}
	if (count == 0)
		cout << "sorry you havent book any tickets yet\n";
	else
		cout << "you have book " << count << " tickets with the name " << n << endl;
}

/*#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include "Vehicle.h"
#include "CityBus.h"

CityBus bus[10];

using namespace std;

static int p = 0;
CityBus::CityBus() {

}

CityBus::CityBus(string n, string p) : Vehicle(n, p) {
    for (int i = 0; i < 5; i++)
        busn[i] = NULL;
    for (int i = 0; i < 50; i++)
        driver[i] = NULL;
    for (int i = 0; i < 10; i++)
        arrival[i] = NULL;
    for (int i = 0; i < 10; i++)
        depart[i] = NULL;
    for (int i = 0; i < 10; i++)
        from[i] = NULL;
    for (int i = 0; i < 10; i++)
        to[i] = NULL;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            for (int z = 0; z < 10; z++) {
                seat[i][j][z] = NULL;
            }
        }
    }
}
CityBus::~CityBus() {
}


void vline(char ch)

{

    for (int i = 80; i > 0; i--)

        cout << ch;

}

void CityBus::install()

{

    cout << "Enter Bus no: ";

    cin >> bus[p].busn;

    cout << "\nEnter Bus Driver's name: ";

    cin >> bus[p].driver;

    cout << "\nBus Arrival time: ";

    cin >> bus[p].arrival;

    cout << "\nBus Departure: ";

    cin >> bus[p].depart;

    cout << "\nFrom: \t\t\t";

    cin >> bus[p].from;

    cout << "\nTo: \t\t\t";

    cin >> bus[p].to;

    bus[p].empty();

    p++;

}

void CityBus::allotment()

{

    int seat;

    char number[5];

top:

    cout << "Bus no: ";

    cin >> number;

    int n;

    for (n = 0; n <= p; n++)

    {

        if (strcmp(bus[n].busn, number) == 0)

            break;

    }

    while (n <= p)

    {

        cout << "\nSeat Number: ";

        cin >> seat;

        if (seat > 32)

        {

            cout << "\nThere are only 32 seats available in this vehicle.";

        }

        else

        {

            if (strcmp(bus[n].seat[seat / 4][(seat % 4) - 1], "Empty") == 0)

            {

                cout << "Enter passanger's name: ";

                cin >> bus[n].seat[seat / 4][(seat % 4) - 1];

                break;

            }

            else

                cout << "The seat no. is already reserved.\n";

        }

    }

    if (n > p)

    {

        cout << "Enter correct Vehicle no.\n";

        goto top;

    }

}


void CityBus::empty()

{

    for (int i = 0; i < 8; i++)

    {

        for (int j = 0; j < 4; j++)

        {

            strcpy_s(bus[p].seat[i][j], "Empty");

        }

    }

}

void CityBus::show()

{

    int n;

    char number[5];

    cout << "Enter vehicle no: ";

    cin >> number;

    for (n = 0; n <= p; n++)

    {

        if (strcmp(bus[n].busn, number) == 0)

            break;

    }

    while (n <= p)

    {

        vline('*');

        cout << "Bus no: \t" << bus[n].busn

            << "\nDriver: \t" << bus[n].driver << "\t\tArrival time: \t"

            << bus[n].arrival << "\tDeparture time:" << bus[n].depart

            << "\nFrom: \t\t" << bus[n].from << "\t\tTo: \t\t" <<

            bus[n].to << "\n";

        vline('*');

        bus[0].position(n);

        int a = 1;

        for (int i = 0; i < 8; i++)

        {

            for (int j = 0; j < 4; j++)

            {

                a++;

                if (strcmp(bus[n].seat[i][j], "Empty") != 0)

                    cout << "\nThe seat no " << (a - 1) << " is reserved for " << bus[n].seat[i][j] << ".";

            }

        }

        break;

    }

    if (n > p)

        cout << "Enter correct bus no: ";

}

void CityBus::position(int l)

{

    int s = 0; p = 0;

    for (int i = 0; i < 8; i++)

    {

        cout << "\n";

        for (int j = 0; j < 4; j++)

        {

            s++;

            if (strcmp(bus[l].seat[i][j], "Empty") == 0)

            {

                cout.width(5);

                cout.fill(' ');

                cout << s << ".";

                cout.width(10);

                cout.fill(' ');

                cout << bus[l].seat[i][j];

                p++;

            }

            else

            {

                cout.width(5);

                cout.fill(' ');

                cout << s << ".";

                cout.width(10);

                cout.fill(' ');

                cout << bus[l].seat[i][j];

            }

        }

    }

    cout << "\n\nThere are " << p << " seats empty in Vehicle No: " << bus[l].busn;

}

void CityBus::avail()

{


    for (int n = 0; n < p; n++)

    {

        vline('*');

        cout << "Bus no: \t" << bus[n].busn << "\nDriver: \t" << bus[n].driver

            << "\t\tArrival time: \t" << bus[n].arrival << "\tDeparture Time: \t"

            << bus[n].depart << "\nFrom: \t\t" << bus[n].from << "\t\tTo: \t\t\t"

            << bus[n].to << "\n";

        vline('*');

        vline('_');

    }

}

void CityBus::booking() {

    system("cls");

    int w;

    while (1)

    {



        cout << "\n\n\n\n\n";
        cout << "\t\t ==== Bus Reservation System ==== \n\n";
        cout << "\t\t\t1. Add Bus Information\n\t\t\t"

            << "2. Reserve\n\t\t\t"

            << "3. View Details\n\t\t\t"

            << "4. Bus Available\n\t\t\t"

            << "5. Exit";

        cout << "\n\t\t\tEnter your choice:-> ";

        cin >> w;

        switch (w)

        {

        case 1:  bus[p].install();

            break;

        case 2:  bus[p].allotment();

            break;

        case 3:  bus[0].show();

            break;

        case 4:  bus[0].avail();

            break;

        case 5:  exit(0);

        }

    }

}
*/