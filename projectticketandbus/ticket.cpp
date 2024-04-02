using namespace std;
#include <iostream>
#include "bus.h"

ticket::ticket() {
	name = "";
	path = 0;
	day = 0;
	time = 0;
}
ticket::ticket(string n, int p, int d, int t){
	name = n;
	path = p;
	day = d;
	time = t;
}



