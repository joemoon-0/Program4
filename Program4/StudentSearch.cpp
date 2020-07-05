#include "StudentSearch.h"

int StudentSearch(LibraryUser*& studentList, int n_students, int n_ID) {
	int low, mid, high;
	low = 0;
	high = n_students - 1;

	while (high >= low) {
		mid = (high + low) / 2;
		if (studentList[mid].getStudentId() < n_ID) {
			low = mid + 1;
		}
		else if (studentList[mid].getStudentId() > n_ID) {
			high = mid - 1;
		}
		else {
			return mid;
		}
	}
	return -1;	// not found
}