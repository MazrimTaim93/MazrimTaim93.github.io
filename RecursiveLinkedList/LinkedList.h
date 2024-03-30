#ifndef __LinkedList__
#define __LinkedList__

#include "Course.h"

class LinkedList
{
public:
	LinkedList() { head = nullptr; }
	~LinkedList();

	// prints the contents of the list of courses to cout
	void PrintList() const;

	// precondition: list is in sorted order
	// postcondition: newCourse is inserted into the list so the list maintains
	//                sorted order. using recursison.
	void Insert(Course* newCourse);

	// postcondition: size is returned. Must be calculated using recursion.
	int Size() const;

	// calculates the Cumulative GPA of all courses in the list.
	double CalculateGPA() const;
	Course* GetListHead() {
		return head;
	}

private:
	Course* head;	// start of linked list

	Course* InsertHelper(Course* head, Course* newCourse); // recursive helper for insert()
	int SizeHelper(Course const* cursor) const; // recursive helper for size()
	void PrintListHelper(Course const* cursor) const; // recursive helper for PrintList()
	void DestructorHelper(Course* cursor); // recursive helper for ~LinkedList()

	double CalculateTotalGradePoints(Course const* cursor) const;	// total of all earned Grade Points in list of courses
	unsigned int CalculateTotalCredits(Course const* cursor) const; // total of all credits in list of courses
};

#endif

