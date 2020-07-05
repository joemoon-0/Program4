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
#include "StudentSort.h"
#include "StudentSearch.h"


int main() {
	std::ifstream in;
	std::ofstream out;
	int rosterSize = 5;				// Initial array size of student roster
	int rosterIndex;				// Index of student within roster array
	int n_students = 0;				// Number of student objects within roster array
	int studentId;					// Holding variable for activity data
	std::string bookCode;			// Holding variable for activity data
	std::string action;				// Check in or Check out

	LibraryUser student;
	LibraryUser* roster = new LibraryUser[rosterSize];
	LibraryUser* tempRoster;		// Holding array for reallocations

	// Input file names
	std::string file1 = "students.txt";
	std::string file2 = "activity.txt";

	// Output file name
	std::string file3 = "updated_students.txt";


	// STEP 1: Open and check student data
	in.open(file1);
	if (!in.is_open()) {
		std::cout << "Could not open file: " << file1 << std::endl;
	}
	else {
		// STEP 1A: Read student objects and store in roster array
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
	in.close();


	// STEP 2: Sort Student Data by Student ID
	StudentSort(roster, rosterSize);


	// STEP 3A: Open and check activity data
	in.open(file2);
	if (!in.is_open()) {
		std::cout << "Could not open file: " << file2 << std::endl;
	}
	else {
		//STEP 3B: Read and process activity data
		in >> action;
		in >> studentId;
		in >> bookCode;
		rosterIndex = StudentSearch(roster, n_students, studentId);

		while (action == "IN" && roster[rosterIndex].CheckIn(bookCode) 
			|| action == "OUT" && roster[rosterIndex].CheckOut(bookCode)) {
			in >> action;
			in >> studentId;
			in >> bookCode;
			rosterIndex = StudentSearch(roster, n_students, studentId);
		}
	}
	in.close();


	// STEP 4: Write updated Library Data to file
	out.open(file3);
	if (!out.is_open()) {
		std::cout << "Could not open file: " << file3 << std::endl;
	}
	else {
		n_students = 0;
		while (roster[n_students].WriteData(out)) {
			n_students++;
		}
	}
	out.close();

	return 0;
}