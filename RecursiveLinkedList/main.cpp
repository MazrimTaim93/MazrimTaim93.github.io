/********************************************************************************************
**	Project: Recursive List
**  Programmer: Jacob Hurren
**	Data:		August 27, 2018
***********************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"
using namespace std;

int main()
{
	// specify the input data file
	const char dataFileName[] = "data.txt";

	// I've got the file name, now try to open the file for reading
	ifstream fileData;
	fileData.open(dataFileName);
	// Make sure we can open it
	if (fileData.good() == false)
	{
		cout << "ERROR: can't open data file: " << dataFileName << endl;
		cout << endl << "Press the [Enter] key to quit...";
		cin.get();
		return -1;
	}

	// I've got the data file open.
	// read and use the data
	LinkedList courses;

	int courseNumber, credits;
	string name, input;
	double grade;

	while (!fileData.eof())
	{
		getline(fileData, input, ',');
		courseNumber = stoi(input);
		getline(fileData, input, ',');
		name = input;
		getline(fileData, input, ',');
		credits = stoi(input);
		getline(fileData, input);
		grade = stod(input);

		Course* course = new Course(courseNumber, name, credits, grade);
		courses.Insert(course);
		fileData.peek();
	}

	fileData.close();

	// display the ordered list of courses
	courses.PrintList();

	double gpa = courses.CalculateGPA();
	cout.precision(4);
	cout << "Cumulative GPA: " << gpa << endl;

	return 0;
}