#include<iostream>
#include<cctype>
#include<iomanip>
#include<string>
using namespace std;


const double rent = 100.00;


const int number = 100;
int main() {

	int roomNo[number];
	double discount = 0.0;
	double finalRent = 0.0;
	cout << "enter number of room:";
	int i;
	for ( i = 0; i >=10 && i<20; i++)
	{
		cin >> roomNo[i];
		 discount = 0.1;
	}
	finalRent = (discount * rent) - rent;
	cout << " final cost is: " << finalRent;


	



}