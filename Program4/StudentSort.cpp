#include "StudentSort.h"

void StudentSort(LibraryUser* &studentList, int rosterSize) {
	int i, j;
	LibraryUser temp;			// Temporary holding object for swap

	for (i = 1; i < rosterSize; i++) {
		j = i;

		if (studentList[j].getStudentId() == 0) {
			// ERROR CONDITION: Discontinue sort if array elements with no data is reached
			break;
		}
		else {
			while (j > 0 && studentList[j].getStudentId() < studentList[j - 1].getStudentId()) {
				temp = studentList[j];
				studentList[j] = studentList[j - 1];
				studentList[j - 1] = temp;
				j--;
			}
		}
	}
}