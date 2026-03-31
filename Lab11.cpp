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

//This program reads the contents of a file and use the information of a it to look out various digits
int main()
{
	double number[SIZE];
	int count;

    cout << "This program reads the contents of a file and use the information of a it to look out various digits" << endl;

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

//function
int readFile(double arr[], int size)
{
    string filename;
    ifstream inputFile;
    int count = 0;

    cout << "Enter file name: ";
    cin >> filename;

    inputFile.open(filename);

    if (!inputFile)
    {
        cout << "Error opening file.\n";
        return 0;
    }

    while (count < size && inputFile >> arr[count])
    {
        count++;
    }

    inputFile.close();
    return count;
}

//function
void analyzeArray(double arr[], int count)
{
    double min = arr[0];
    double max = arr[0];
    double sum = 0;

    for (int i = 0; i < count; i++)
    {
        if (arr[i] < min)
            min = arr[i];

        if (arr[i] > max)
            max = arr[i];

        sum += arr[i];
    }

    double average = sum / count;

    // Standard deviation
    double variance = 0;
    for (int i = 0; i < count; i++)
    {
        variance += pow(arr[i] - average, 2);
    }

    variance /= count;
    double stdDev = sqrt(variance);

    // Output
    cout << "\nThe results are the following: \n";
    cout << "Lowest: " << min << endl;
    cout << "Highest: " << max << endl;
    cout << "Total: " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Standard Deviation: " << stdDev << endl;
}
