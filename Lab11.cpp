//Carlos Escobar
//This program will read the contents of a file into an array and display various things
//3/21/2026
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

const int SIZE = 100;

int readFile(double arr[], int size);
void analyzeArray(double arr[], int count);

int main()
{
	double number[SIZE];
	int count;

    count = readFile(number, SIZE);

    if (count > 0)
    {
        analyzeArray(number, count);
    }
    else
    {
        cout << "No numbers read.\n";
    }

    return 0;
}

