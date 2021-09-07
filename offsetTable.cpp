#include <iostream> 
using namespace std;

typedef char String[9];
struct StudentRecord
{
	String firstName;
	String lastName;
	int id;
	float gpa;
	// char gender;
	int currentHours;
	int totalHours;
};
StudentRecord student;
StudentRecord students[100];
int main() {
	cout << sizeof(student.firstName)+sizeof(student.lastName)+sizeof(student.id)<< endl;
	cout << sizeof(StudentRecord) << endl;
	return 0;
}