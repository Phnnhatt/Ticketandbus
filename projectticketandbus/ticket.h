#pragma once
using namespace std;
#include <iostream>

class ticket {
public:
	string name;
	int path;// what bus you want to go
	int day;
	int time;

	ticket();
	ticket( string n, int p, int d, int t );
	
};