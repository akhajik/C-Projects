// boxoffice2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Arshen Khajikgeregoury
// student ID: 900255878
// e-mail: khajika5420@student.laccd.edu
// CS-216 -- Section #21123 -- Spring 2021
#include <iostream>
#include<cctype>
#include<string>
#include<iomanip>

using namespace std;


class boxOffice
{
public:
    boxOffice();
    double adults = 0.0, child = 0.0;
    
    double getGross();
    double getProfit();
    double getDistributor();
   
private:
    double gross, distributor, profit;
    string name;
    
};

double boxOffice::getGross() {
     gross = (adults * 6.0) + (child * 3.0);
    
    return gross;

}



double boxOffice::getProfit() {
    profit = gross * 0.2;
    return profit;
}


double boxOffice::getDistributor() {
    distributor=profit - gross;
    return distributor;
}

boxOffice::boxOffice() {
    string movieName = name;

};


int main()
{
    string movieName;
    cout << "Enter the name of the movie: ";
    getline(cin, movieName);   
    boxOffice b;
    
    cout << "Enter the number of the adult tickets sold: ";
    cin >> b.adults;

    cout << "Enter the number of the children tickets sold: ";
    cin >> b.child;

    cout << "\nMovie Name:\t\t" <<setw(6)<< "\""<<movieName<<"\""<< endl;
    cout << "Adult Tickets Sold:\t\t" << right<<setw(6) << b.adults << endl;
    cout << "Child Tickets Sold:\t\t" << right<<setw(6) << b.child << endl << endl;
    cout << showpoint << setprecision(2) << fixed;
    
    double resultForGross = b.getGross();
    double resultForProfit = b.getProfit();
    double resultForDistributor = b.getDistributor();
    
    cout << "Gross Box Office Profit:\t$" << setw(10) << resultForGross << endl;
    cout << "Amount Paid to Distributor:\t$" << setw(10)<< resultForDistributor << endl;
    cout << "Net Box Office Profit:\t\t$" << setw(10) << resultForProfit << endl;

    return 0;
}