/***
* Joe Moon
* jmn5y@mail.umkc.edu
* CS 201R Summer 2020
* Program 4 - Library Database
***/

#include <iostream>
#include <string>
#include <fstream>
#include "LibraryUser.h";

int main() {
	bool filesOpen = true;
	std::ifstream in;
	std::ofstream out;
	int rosterSize = 5;
	int n_students = 0;

	LibraryUser student;
	LibraryUser* roster = new LibraryUser[rosterSize];
	LibraryUser* tempRoster;		// Holding array for reallocations


	// Input file names
	std::string file1 = "students.txt";
	std::string file2 = "activity.txt";

	// STEP 1: Open and check input files
	in.open(file1);
	if (!in.is_open()) {
		std::cout << "Could not open file: " << file1 << std::endl;
		filesOpen = false;
	}
	else {
		// STEP 1A: Read student data
		while (student.ReadData(in)) {
			roster[n_students] = student;
			n_students++;

			// Reallocate data into larger array if current array is full
			if (n_students == rosterSize) {
				rosterSize *= 2;
				tempRoster = new LibraryUser[rosterSize];

				// Copy contents of old array into new array
				for (int i = 0; i < n_students; i++) {
					tempRoster[i] = roster[i];
				}
				
				// Delete old array
				delete[] roster;
				roster = tempRoster;
				tempRoster = nullptr;
			}
		}
	}

	for (int i = 0; i < n_students; i++) {
		std::cout << "Student: " << roster[i].getStudentId() << " " << roster[i].getFullName() << std::endl;
	}

	return 0;
}