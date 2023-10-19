/*
**************************************************************************************
**************************************************************************************
***********************	Student: 		Arshen KhajikGeregoury	**********************
***********************	ID:				900255878				**********************
***********************	Class:			CS216					**********************
***********************	Section #:		21123					**********************
***********************	Semester:		Spring 2021				**********************
**************************************************************************************
**************************************************************************************
*/
#include <iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
using namespace std;


const float dis10 = 0.1;
const float dis20 = 0.2;
const float dis30 = 0.3;
const float disFor3Day = 0.05;

	template <class TTT>
	TTT getMultipliesFor3Inputs(TTT a, TTT b, TTT c) {
		return (a * b * c);
	};


	template <class TT>
	TT getMultipliesFor2Inputs(TT a, TT b) {
		return (a * b);
	};


	double total(int& days, int& roomNo, double& userPrice,double& salesTax) {
		double result;
		double price = getMultipliesFor3Inputs<double>(days, roomNo, userPrice);
		float dis;
		double billCost = price + (getMultipliesFor2Inputs<double>(price, salesTax));

		if (roomNo >= 30 && days >= 3) {
			dis = dis30 + disFor3Day;
			result = price - (price * dis);
			billCost = result + getMultipliesFor2Inputs<double>(result, salesTax);
			cout  <<showpoint<<left<<fixed<< "\nIncluded:\n" << salesTax * 100 << "% SalesTax\n"<< dis30*100<<"% + "<<disFor3Day*100 << "% discount." << endl;
		}
		else if (roomNo >= 20 && days >= 3) {
			dis = dis20 + disFor3Day;
			result = price - (price * dis);
			billCost = result + getMultipliesFor2Inputs<double>(result, salesTax);
			cout << showpoint << left << fixed << "\nIncluded:\n" << salesTax * 100 << "% SalesTax\n" << dis20 * 100 << "% + " << disFor3Day * 100 << "% discount." << endl;
		}
		else if (roomNo >= 10 && days >= 3) {
			dis = dis10 + disFor3Day;
			result = price - (price * dis);
			billCost = result + getMultipliesFor2Inputs<double>(result, salesTax);
			cout << showpoint << left << fixed << "\nIncluded:\n" << salesTax * 100 << "% SalesTax\n" << dis10 * 100 << "% + " << disFor3Day * 100 << "% discount." << endl;
		}
		else if (roomNo >= 1 && days >= 3) {

			result = price - (price * disFor3Day);
			billCost = result + getMultipliesFor2Inputs<double>(result, salesTax);
			cout << showpoint << left << fixed << "\nIncluded:\n" << salesTax * 100 << "% SalesTax\n" << disFor3Day * 100 << "% discount\n";

		}
		else if (roomNo >= 30) {

			result = price - (price * dis30);
			billCost = result + getMultipliesFor2Inputs<double>(result, salesTax);
			cout << showpoint << left << fixed << "\nIncluded:\n" << salesTax * 100 << "% SalesTax\n" << dis30 * 100 << "% discount\n";

		}
		else if (roomNo >= 20) {

			result = price - (price * dis20);
			billCost = result + getMultipliesFor2Inputs<double>(result, salesTax);
			cout << showpoint << left << fixed << "\nIncluded:\n" << salesTax * 100 << "% SalesTax\n" << dis20 * 100 << "% discount\n";
		}
		else if (roomNo >= 10) {
			result = price - (price * dis10);
			billCost = result + getMultipliesFor2Inputs<double>(result, salesTax);
			cout << showpoint << left << fixed << "\nIncluded:\n" << salesTax * 100 << "% SalesTax\n" << dis10 * 100 << "% discount\n";
		}

		else if(roomNo>=1){
			
			result = price;
			billCost = result + getMultipliesFor2Inputs<double>(result, salesTax);
			cout << showpoint << left << fixed << "\nIncluded:\n" << salesTax * 100 << "% SalesTax\n"<< "0% discount\n";
		}
		else {
		
				cerr << endl << left << "	*** WRONG INPUT,TRY AGAIN ***\n";
				exit (1);
		}


		return billCost;
	}
	





	int main()
	{

		cout << "Enter minimum cost of room for one night: ";
		double userPrice;
		cin >> userPrice;
		if (userPrice == 0)
		{
			cerr << "wrong input, run the program again " << endl;
			exit(1);
		}

		else
			cout << "Enter minimum number of rooms which you want to book: ";
		int roomNo = 0;
		cin >> roomNo;
		if (roomNo == 0)
		{
			cerr << "wrong input, run the program again " << endl;
			exit(1);
		}
		else
			cout << "Enter minimum number of days booked for the rooms: ";
		int days;
		cin >> days;
		if (days == 0)
		{
			cerr << "wrong input, run the program again " << endl;
			exit(1);
		}

		else
			cout << "Enter minimum sales tax:(If you want 10% sales tax, you just enter ""10"" following bye ""ENTER"" from Keypad):\n";
		double userTax;
		cin >> userTax;
			double salesTax = userTax / 100;
			cout << endl << endl << "=================================================================================================================\n";
			cout << setprecision(2) << right << fixed << "OneRoomCost:\t			" << left << userPrice << " $\n";
			cout << setprecision(2) << right << fixed << "NumberOfRoomsBooked:\t		" << left << roomNo << endl;
			cout << setprecision(2) << right << fixed << "NumberOfDays:\t			" << left << days << endl;
			cout << setprecision(2) << right << fixed << "---------------------------------------------------------------------------------------------\n";
			cout << setprecision(2) << right << fixed << "TotalCostOfRooms:\t		" << left << getMultipliesFor2Inputs<double>(roomNo, userPrice) << " $\n";
			cout << setprecision(2) << right << fixed << "\nTotalBilling:\t			" << left << total(days, roomNo, userPrice, salesTax) << " $\n";

			cout << endl << endl;



	


	return 0;
}