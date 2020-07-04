#include <string>
#include <fstream>
#include "LibraryUser.h"

LibraryUser::LibraryUser() {
	firstName = "";
	lastName = "";
	studentId = 0;
	checkedOut = 0;
	itemArraySize = 5;
	barCodes = nullptr;
}


LibraryUser::LibraryUser(std::string first, std::string last, unsigned int Id) {
	firstName = first;
	lastName = last;
	studentId = Id;
	checkedOut = 0;
	itemArraySize = 5;
	barCodes = nullptr;
}


LibraryUser::LibraryUser(const LibraryUser& other) {
	barCodes = nullptr;
	*this = other;
}


const LibraryUser& LibraryUser::operator=(const LibraryUser& rhs) {
	if (this != &rhs) {
		// Delete old dynamic data
		if (barCodes != nullptr) {
			delete[] barCodes;
			barCodes = nullptr;
		}
		//Allocate new dynamic data
		if (rhs.barCodes != nullptr) {
			barCodes = new std::string[rhs.itemArraySize];

			// Copy dynamic Data
			for (int i = 0; i < itemArraySize; i++) {
				barCodes[i] = rhs.barCodes[i];
			}
		}
		// Copy Static data
		firstName = rhs.firstName;
		lastName = rhs.lastName;
		studentId = rhs.studentId;
		checkedOut = rhs.checkedOut;
		itemArraySize = rhs.itemArraySize;
		//barCodes = rhs.barCodes;
	}
	return *this;
}


LibraryUser::~LibraryUser() {
	if (barCodes != nullptr) {	
		delete[] barCodes;
		barCodes = nullptr;
	}

}


std::string LibraryUser::getFirstName() const {
	return firstName;
}


std::string LibraryUser::getLastName() const {
	return lastName;
}


std::string LibraryUser::getFullName() const {
	return firstName + " " + lastName;
}


unsigned int LibraryUser::getStudentId() const {
	return studentId;
}


bool LibraryUser::setFirstName(std::string first) {
	firstName = first;
	return true;
}


bool LibraryUser::setLastName(std::string last) {
	lastName = last;
	return true;
}


bool LibraryUser::setStudentId(unsigned int Id) {
	if (Id >= 1000 && Id <= 10000) {
		studentId = Id;
		return true;
	}
	else {
		return false;
	}
}


unsigned int LibraryUser::CheckoutCount() const {
	return checkedOut;
}


//bool LibraryUser::CheckOut(const std::string& item) {
//
//}


//bool LibraryUser::CheckIn(const std::string& item) {
//
//}


bool LibraryUser::HasCheckedOut(const std::string& item) {



	return true;
}


void LibraryUser::Clear() {
	firstName = " ";
	lastName = " ";
	studentId = 0;
	checkedOut = 0;
	itemArraySize = 5;

	if (barCodes != nullptr) {
		delete[] barCodes;
		barCodes = nullptr;
	}
}


bool LibraryUser::ReadData(std::istream& in) {
	unsigned int Id;			// Student's ID number
	std::string first;			// Student's first name
	std::string last;			// Student's last name
	unsigned int itemsOut;		// Number of items checked out from file
	std::string bookCode;		// Holding variable for bar codes
	int itemIndex = 0;			// Index for bar code array
	std::string* tempCodes;		// Holding array for reallocating data
	
	// STEP 1: Reset student data
	Clear();

	// STEP 2: Read Static Data
	in >> Id;
	if (!setStudentId(Id)) {	// End ReadData if ID is invalid
		return false;
	}

	in >> first;
	setFirstName(first);
	in >> last;
	setLastName(last);
	in >> itemsOut;
	checkedOut = itemsOut;
	
	// STEP 3: Read barcodes if student has items checked out
	if (itemsOut > 0) {
		barCodes = new std::string[itemArraySize];
		for (int i = 0; i < itemsOut; i++) {
			in >> bookCode;
			barCodes[itemIndex] = bookCode;
			itemIndex++;

			// Reallocate data into larger array if current array is full
			if (itemIndex == itemArraySize) {
				itemArraySize *= 2;
				tempCodes = new std::string[itemArraySize];

				// Copy contents of old array into new array
				for (int i = 0; i < itemIndex; i++) {
					tempCodes[i] = barCodes[i];
				}

				// Delete old array
				delete[] barCodes;
				barCodes = tempCodes;
				tempCodes = nullptr;
			}
		}
	}
	else {
		barCodes = nullptr;
	}

	return in.good();
}


bool LibraryUser::WriteData(std::ostream& out) {
	return out.good();
}