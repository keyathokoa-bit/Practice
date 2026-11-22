#include <iostream>
#include <string>
using namespace std;

int main() {
	string fullName;
	int age;
	double height;
	char initial;

	cout << "Enter your fullName: ";
	cin >> fullName;
	cout << "Enter your age: ";
	cin >> age;
	cout << "Enter your height: ";
	cin >> height;
	cout << "Enter your initial: ";
	cin >> initial;

	cout << "\n------About Me------" << endl;
	cout << "Name: " << fullName << endl;
	cout << "Age: " << age << endl;
	cout << "Height: " << height << endl;
	cout << "Initial: " << initial << endl;

	return 0;
}