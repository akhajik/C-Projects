#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<vector>
using namespace std;




int main()
{
    const int n = 10;
    string lastName[n], firstName[n];
    double current[n], rate[n], increased[n];
    string main;
    ifstream in;
    
    ofstream out;
    in.open("employeSalary.txt",ios::in);
    



    string* ptr[100];
    while (in) {
        int i, j;
        int m = sizeof(ptr) / sizeof(ptr[0]);
        for (i = 0; i < m; i++)
        {
            for (j = i + 1; j < m; j++)
            {
                if (in >> *ptr[i] >> *ptr[j]) {
                    *ptr[i] = firstName[i];
                    *ptr[j] = lastName[j];


                }
            }
            cout << *ptr[i] << *ptr[j];

            cout << setprecision(2) << showpoint << fixed;
        }






        /* updatedSalaryA = currentSalaryA + (currentSalaryA * percentPayIncreaseA / 100);
         updatedSalaryB = currentSalaryB + (currentSalaryB * percentPayIncreaseB / 100);
         updatedSalaryC = currentSalaryC + (currentSalaryC * percentPayIncreaseC / 100);

         outFile << lastnameA << " " << firstnameA << " " << updatedSalaryA << endl;
         outFile << lastnameB << " " << firstnameB << " " << updatedSalaryB << endl;
         outFile << lastnameC << " " << firstnameC << " " << updatedSalaryC << endl;
         */
        in.close();
        out.close();



        return 0;
    }
}

