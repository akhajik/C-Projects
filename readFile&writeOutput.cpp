#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>



using namespace std;
int max = 18;

int ParArray[19];
int ScoreArray[19];

 
string file1 = "data.txt";
string file2 = "score.txt";




int getSumPar(ifstream& fin1, int myArray[],int max) {
	int sum = 0;
	int element = 0;
	cout << endl;
	
	while (fin1 >> myArray[max] && !fin1.eof()) {

		int i;
		
		for (i = 1; i < max; i++) {
			myArray[i] = element;
			
		}
		cout << myArray[i] << " ";

		sum += myArray[max];
	}
	cout << setw(4) << left << fixed;
	cout << " --> Sum=["  << sum << "]" << endl;

	return sum;
}


int getSumScore(ifstream& fin2, int myArray[], int max) {
	int sum = 0;
	int element = 0;
	cout << endl;

	while (fin2 >> element && !fin2.eof()) {


		int i;
		i = max;
		for (i = 0; i < max; i++) {
			myArray[max] = element;
		}
		cout << element << " ";

		sum += element;
	}
	cout << setw(4) << left << fixed;
	cout << " --> Sum=[" << sum << "]" << endl;


	return sum;
}










int main() {

	string file1, file2, outfilename;

	ifstream fin1(file1, ios::in);
	ifstream fin2(file2, ios::in);

	ofstream fout(outfilename, ios::out);

	file1 = "data.txt";
	fin1.open(file1);
	file2 = "score.txt";
	fin2.open(file2);

	//outfilename = "fileName.txt";

	fout.open(outfilename);



	if (!fin1.is_open())
		cout << " Error Due Read/Open-ing file ...." << endl;

	else if (!fin2.is_open())
		cout << " Error Due Read/Open-ing file ...." << endl;


	else
	{

		cout << endl;
		cout << "xxxx File Successfuly Opened xxxx \t \n" << endl;

		double element = 0.0;
		string line;
		int elementCounter = 0;
		double sum = 0.00;
		double average = 0.00;
		average = sum / 50;
		cout << " ParData: ";
		if (max = 17)
			getSumPar(fin1, ParArray, max);

		cout << endl;
		cout << " ScoreBoard: ";
		getSumScore(fin2, ScoreArray, max);
		cout << endl;
	}
		/*int* ps[max];
		*ps = &ScoreArray[max];
		*ps = ScoreArray;

		while (fin2 >> element) {
			int i;
			for (i = 0; i < max; i++)
			{

				*ps[i] = element;
				fin2 >> *ps[i];
			}
				cout << " *ptrScore[" << i << "] = " << *ps[i] << endl;


		}*/





		/*cout << " There are [" << elementCounter << "] elements in Array. " << endl;
		cout << " Sum =[" << sum + element << "] " << endl;
		cout << setprecision(3) << fixed;
		//cout << " Average =[ " << average << " ] ." << endl << setprecision(2);
		*/


	

	return 0;

}

