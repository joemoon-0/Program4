#ifndef STUDENT_SORT_H
#define STUDENT_SORT_H

#include "LibraryUser.h"

void StudentSort(LibraryUser* &studentList, int n_students);
/**
* PRE: Objects from data file entered into roster array.
* POST: Rearranges array by ascending numerical order using student ID.
* RETURNS: None.
* I/O, USER INTERACTION: None.
* EXCEPTIONS OR ERROR CONDITIONS: Discontinues search if array elements with no data is reached.
*								  Ex. The roster array may have been expanded to 160 elements but only 
*								      holds 109 elements worth of student data.
**/

#endif