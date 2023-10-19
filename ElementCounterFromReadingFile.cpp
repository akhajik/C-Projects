#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>



using namespace std;
const int max = 50;

int main() {

	string filename, outfilename;

	ifstream fin(filename, ios::in);
	ofstream fout(outfilename, ios::out);

	filename = "File For Final.txt";
	outfilename = "khajikgeregoruyFinal3Source Results File.txt";

	fin.open(filename);
	fout.open(outfilename);



	if (!fin.is_open()) {
		cout << " Error Due Read/Open-ing file ...." << endl;
		exit(1);
	}
	else
	{



		cout << endl;
		cout << "xxxx File Successfuly Opened xxxx \t \n" << endl;
		double myArray[max];

		double element = 0.0;
		string line;
		int elementCounter = 0;
		double sum = 0.00;
		double average = 0.00;
		average = sum / 50;

		while (fin >> element && !fin.eof()) {

			cout << element << endl;


			int i;
			i = max;
			for (i = 0; i < max; i++) {
				myArray[i] = element;
			}
			elementCounter++;
			sum += element;
		}
		average = (sum + element) / elementCounter);
		average % 100;
		cout << endl;
		if (!fin.eof())
			cout << " test for end-of-file is : " << !fin.eof();
		else
			cout << " test for end-of-file is : " << fin.eof() << endl;

		cout << " There are [" << elementCounter << "] elements in Array. " << endl;
		cout << " Sum =[" << sum + element << "] " << endl;
		cout << setprecision(3) << fixed;
		cout << " Average =[ " << average  << " ] ." << endl << setprecision(2);

	}

	return 0;
}






