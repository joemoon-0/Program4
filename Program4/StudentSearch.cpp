#include "StudentSearch.h"

int StudentSearch(LibraryUser*& studentList, int n_students, int n_ID) {
	for (int i = 0; i < n_students; i++) {
		if (studentList[i].getStudentId() == n_ID) {
			return i;
		}
	}
	return -1;	// not found
}