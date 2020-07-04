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
	LibraryUser(std::string first, std::string last, unsigned int Id);
	LibraryUser(const LibraryUser& other);
	const LibraryUser& operator=(const LibraryUser& rhs);
	~LibraryUser();

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getFullName() const;
	unsigned int getStudentId() const;
	bool setFirstName(std::string first);
	bool setLastName(std::string last);
	bool setStudentId(unsigned int Id);
	unsigned int CheckoutCount() const;
	bool CheckOut(const std::string& item);
	bool CheckIn(const std::string& item);
	bool HasCheckedOut(const std::string& item);
	void Clear();
	bool ReadData(std::istream& in);
	bool WriteData(std::ostream& out);
};

#endif