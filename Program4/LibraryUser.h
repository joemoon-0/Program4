
#ifndef LIBRARY_USER_H
#define LIBRARY_USER_H

#include <string>


class LibraryUser {
private:
	std::string firstName;
	std::string lastName;
	unsigned int studentId;
	unsigned int checkedOut;
	unsigned int itemArraySize;
	std::string* barCodes;

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
