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
#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;

int main() {

    const int max = 3;//define maximum size for array

    string lastName[max], firstName[max],current[max], rate[max];
    double updatedSalary[max];
    
    //Create pointer 
    string* pCurrent;
    pCurrent = &current[0];

    string* pRate;
    pRate = &rate[0];
        
    string line; //for specify LINE while program streams data


    ifstream in; //read from text file
    ofstream out; //write red data to outputfile
    
    //open file from filename
    in.open("employeeSalary.txt", ios::in);
    //make file for write data in it
    out.open("employeeOutput.txt");
    
    // declare error message if file can not open
    if (!in.is_open()) {
        cerr << " error in reading... " << endl;
    }
    else{

        int i;
        cout << " firstName\tlastName\tupdatedSalar\t\t\n";
        cout << "==============================================\n";
         out << " firstName\tlastName\tupdatedSalar\t\t\n";
         out << "==============================================\n";
         double sum = 0.0;

         //FOR loop for read data line-by-line from input txt file

         for (i = 0; i < max; i++) {
             in >> lastName[i] >> firstName[i] >> current[i] >> rate[i];

             getline(in, line); //declate newLine

             istringstream iss(line); //Declare istringstream for specify the type of data and store in sepcific array
             
                                      
             // Convert data that had been red from file,
             // (string to double) and store in specific array
             double currentSalary[max];
             currentSalary[i] = stod(pCurrent[i]); 
             double increaseRate[max];
             increaseRate[i] = stod(pRate[i]) / 100;
             
             // read/store data from each line
             iss >> currentSalary[i] >> increaseRate[i];

             //Calculate updatedSalary for employees
             updatedSalary[i] = (currentSalary[i] * increaseRate[i]) + currentSalary[i];
             //Calculate/sum: total updated salary for thease employees
             sum += updatedSalary[i];

             //Display data and write data on "outputFile.txt"
             cout << setprecision(2) << fixed << " " << firstName[i] << "\t\t" << lastName[i] << "\t\t" << updatedSalary[i] << "  $\t\n";
             out << setprecision(2) << fixed << " " << firstName[i] << "\t\t" << lastName[i] << "\t\t" << updatedSalary[i] << "  $\t\n";

         }
         cout << endl;
         cout << "----------------------------------------------\n";
         cout << setprecision(2) << fixed << " SumOFUpdatedSalary:\t\t" << sum << " $\t\n";
         cout << "----------------------------------------------\n";
         out << endl;
         out << "----------------------------------------------\n";
         out << setprecision(2) << fixed << " SumOFUpdatedSalary:\t\t" << sum << " $\t\n";
         out << "----------------------------------------------\n";



        out << endl;
        out << "***********************************************************************************************************";
        out << "\nCoded by:\nStudent:\t\tArshen KhajikGeregoury\nStudentID:\t\t900255878\nClass:\t\tCS216\nSection#:\t\t21123\nSpring 2021\n";
        out << "***********************************************************************************************************";


        // end of program finishing with close read/write data from/to fileName
        in.close();
        out.close();
    }


    return 0;

}
