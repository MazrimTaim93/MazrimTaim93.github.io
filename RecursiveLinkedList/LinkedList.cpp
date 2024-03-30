#include <iostream>
#include "LinkedList.h"
#include "course.h"
using namespace std;

void LinkedList::Insert(Course* newCourse)
{
	if (head == nullptr)
	{
		head = newCourse;
		cout << "New list head added.";
		PrintList();
	}
	else
		InsertHelper(head, newCourse);
}

Course* LinkedList::InsertHelper(Course* cursor, Course* newCourse)
{
	
	if (cursor == head && cursor->courseNumber > newCourse->courseNumber)
	{
		newCourse->next = head;
		head = newCourse;
	}
	else if (cursor->next == nullptr)
		cursor->next = newCourse;
	else if (cursor->next->courseNumber > newCourse->courseNumber)
	{
		newCourse->next = cursor->next;
		cursor->next = newCourse;
	}
	else
		InsertHelper(cursor->next, newCourse);

	return newCourse;
}

int LinkedList::Size() const
{
	int size = -1;

	if (head == nullptr)
		size = 0;
	else
		size = SizeHelper(head);

	return size;
}

int LinkedList::SizeHelper(Course const* cursor) const
{
	if (cursor->next == nullptr)
		return 1;
	else
		return SizeHelper(cursor->next) + 1;
}

// prints the contents of the list of courses to cout
void LinkedList::PrintList() const
{
	cout << "Printing List.\n";

	if (head != nullptr)
	{
		int listSize = Size();
		cout << "Current List: " << listSize << endl;
		PrintListHelper(head);
		cout << endl;
	}
	else
		cout << "No list to print.\n";
}

void LinkedList::PrintListHelper(Course const* cursor) const
{
	cout << "cs" << cursor->courseNumber << " " << cursor->courseName << " Grade: "
		<< cursor->grade << " Credit Hours: " << cursor->credits << endl;

	if (cursor->next != nullptr)
		PrintListHelper(cursor->next);
}

LinkedList::~LinkedList()
{
	if (head != nullptr)
		DestructorHelper(head);
}

void LinkedList::DestructorHelper(Course* cursor)
{
	if (cursor->next == nullptr)
		delete cursor;
	else
	{
		DestructorHelper(cursor->next);
		delete cursor;
	}
}

double LinkedList::CalculateGPA() const
{
	double gradePoints = 0;
	double credits = 0;

	if (head != nullptr)
	{
		gradePoints = CalculateTotalGradePoints(head);
		credits = CalculateTotalCredits(head);
	}
	
	return gradePoints / credits;
}

double LinkedList::CalculateTotalGradePoints(Course const* cursor) const
{
	double gradePoints = 0;

	if (cursor->next == nullptr)
		gradePoints = cursor->credits * cursor->grade;
	else
		gradePoints = (cursor->credits * cursor->grade) + CalculateTotalGradePoints(cursor->next);
	
	return gradePoints;
}

unsigned int LinkedList::CalculateTotalCredits(Course const* cursor) const
{
	int credits = 0;

	if (cursor->next == nullptr)
		credits = cursor->credits;
	else
		credits = cursor->credits + CalculateTotalCredits(cursor->next);
	
	return credits;
}