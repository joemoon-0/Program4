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

int main() {
	std::ifstream in;
	std::ofstream out;
	int rosterSize = 5;				// Initial array size of student roster
	int rosterIndex;				// Index of student within roster array
	int n_students = 0;				// Index for student roster array
	std::string action;				// Check in or Check out

	LibraryUser student;
	LibraryUser* roster = new LibraryUser[rosterSize];
	LibraryUser* tempRoster;		// Holding array for reallocations

	int counter = 1;	// FIXME
	int studentId;
	std::string bookCode;

	// Input file names
	std::string file1 = "students.txt";
	std::string file2 = "activity.txt";

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
	StudentSort(roster, n_students);

	for (int i = 0; i < n_students; i++) {
		std::cout << "Student: " << roster[i].getStudentId() << " " << roster[i].getFullName() 
			<< " " << roster[i].CheckoutCount() << std::endl;
	}


	// STEP 3: Open and check activity data
	in.open(file2);
	if (!in.is_open()) {
		std::cout << "Could not open file: " << file2 << std::endl;
	}
	else {
		in >> action;
		in >> studentId;
		in >> bookCode;
		//while(!in.eof()) {
		while (false) {
			if (action == "IN") {
				//std::cout << counter << " - " << action << " " << studentId << " " << bookCode << std::endl;
			
			}
			else if (action == "OUT") {
				std::cout << counter << " - " << action << " " << studentId << " " << bookCode << std::endl;
			}
			else {
				std::cout << "Invalid Activity Read" << std::endl;
			}
			counter++;

			in >> action;
			in >> studentId;
			in >> bookCode;
		}
	}
	in.close();


	// STEP X: Write Library Data to file



	return 0;
}