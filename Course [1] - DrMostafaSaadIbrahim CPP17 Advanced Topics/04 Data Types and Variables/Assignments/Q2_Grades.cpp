/**
	----------------------------------------------------------------------
	Homework #2:
	------------
		Example of Student Data, Name,ID, and Grade.
	----------------------------------------------------------------------
**/
#include <iostream>
using namespace std;

int main()
{
	// Student Name.
	string name1;
	cout << "What is student 1 name: ";
	cin >> name1;

	// Student ID.
	// Although looks as integer, no guarantee (make be big or has letters).
	string id1;
	cout << "His id: ";
	cin >> id1;

	// Student Grade.
	// Although looks as integer, but grade could be 30.5
	double grade1;
	cout << "His math exam grade: ";
	cin >> grade1;

	/////////////////////////
	string name2;
	cout << "What is student 2 name: ";
	cin >> name2;

	string id2;
	cout << "His id: ";
	cin >> id2;

	double grade2;
	cout << "His math exam grade: ";
	cin >> grade2;

	cout << "\nStudents grades in math\n";

	cout << name1 << " (with id " << id1 << ") got grade: " << grade1 << "\n";
	cout << name2 << " (with id " << id2 << ") got grade: " << grade2 << "\n";
	cout << "Average grade is " << (grade1 + grade2) / 2.0 << "\n";

	// Notice we used () to apply this operation first. More later

	return 0;
}
