#ifndef LIBRARY_USER_H
#define LIBRARY_USER_H

#include <string>

class LibraryUser {
private:
	std::string firstName;			// Student's first name
	std::string lastName;			// Student's last name
	unsigned int studentId;			// Student's ID number
	unsigned int checkedOut;		// Number of items the student has checked out
	unsigned int itemArraySize;		// Array size for item bar codes
	std::string* barCodes;			// Pointer for bar code array

public:
	LibraryUser();
	/**
	* PRE: Object declaration.
	* POST: Initializes strings to empty, numerical variables to 0 (except itemArraySize = 3), pointesr to nullptr.
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/


	LibraryUser(std::string first, std::string last, unsigned int Id);
	/**
	* PRE: Object declaration.
	* POST: Initializes firstName, lastName, studentID to parameterized values.  Remaining variables same as default constructor.
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/


	LibraryUser(const LibraryUser& other);
	/**
	* PRE: Object declaration.
	* POST: Initializes one LibraryUser object to another.
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/


	const LibraryUser& operator=(const LibraryUser& rhs);
	/**
	* PRE: Object declaration.
	* POST: Copies member variables from one object to another.
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	
	~LibraryUser();
	/**
	* PRE: Object deletion.
	* POST: Deallocates object data.
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/


	std::string getFirstName() const;
	/**
	* PRE: firstName set.
	* POST: None.
	* RETURNS: firstName.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/
	

	std::string getLastName() const;
	/**
	* PRE: lastName set.
	* POST: None.
	* RETURNS: lastName.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/


	std::string getFullName() const;
	/**
	* PRE: firstName and lastName set.
	* POST: Concatinates firstName and lastName with a single white space inbetween.
	* RETURNS: Full name of student.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/
	
	
	unsigned int getStudentId() const;
	/**
	* PRE: studentID set.
	* POST: None.
	* RETURNS: studentID.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/


	bool setFirstName(std::string first);
	/**
	* PRE: firstName read in from data file.
	* POST: Assigns data to firstName.
	* RETURNS: Boolean on correct member variable assignment.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/


	bool setLastName(std::string last);
	/**
	* PRE: firstName read in from data file.
	* POST: Assigns data to firstName.
	* RETURNS: Boolean on correct member variable assignment.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/


	bool setStudentId(unsigned int Id);
	/**
	* PRE: studentID read in from data file.
	* POST: Validates student ID wtihing range.
	* RETURNS: Boolean on correct member variable assignment.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: studentID range check between 1000 to 10000, inclusive.
	**/


	unsigned int CheckoutCount() const;
	/**
	* PRE: checkOut set.
	* POST: None.
	* RETURNS: checkOut.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/


	bool CheckOut(const std::string& item);
	/**
	* PRE: Item to be actioned is read in from file.
	* POST: Verifies that the item is not already checked out and adds to array.
	* RETURNS: Boolean on successful addition of item to array.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: Checks if item is already checked-out or cannot be added.
	**/


	bool CheckIn(const std::string& item);
	/**
	* PRE: Item to be actioned is read in from file.
	* POST: Verifies that the item is already checked out and removes it from array.
	* RETURNS: Boolean on successful removal of item from array.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: Checks if item is the last array element.  If so, deletes array.
	**/


	bool HasCheckedOut(const std::string& item);
	/**
	* PRE: Item to be actioned is read in from file.
	* POST: Checks array if item already exists.
	* RETURNS: Boolean on finding item within array.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/


	void Clear();
	/**
	* PRE: None.
	* POST: Resets member variables to constructor values.
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/


	bool ReadData(std::istream& in);
	/**
	* PRE: istream open for input.
	* POST: Reads object's data from provided istream.  If items are checked-out, populates a barCode array.
	* RETURNS: Boolean on successful read of object data.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/


	bool WriteData(std::ostream& out);
	/**
	* PRE: ostream open for output.
	* POST: Writes object's data to provided ostream.
	* RETURNS: Boolean on successful write of object data.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: Discontinues writing to file after last valid data entry.
	**/
};

#endif