#include "StudentSort.h"

void StudentSort(LibraryUser* &studentList, int n_students) {
	int i, j;
	LibraryUser temp;

	for (i = 1; i < n_students; i++) {
		j = i;
		while (j > 0 && studentList[j].getStudentId() < studentList[j - 1].getStudentId()) {
			temp = studentList[j];
			studentList[j] = studentList[j - 1];
			studentList[j - 1] = temp;
			j--;
		}
	}
}