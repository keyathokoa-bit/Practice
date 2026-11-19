#include<iostream>
#include<iomanip>
using namespace std;
 
int main() {

	double distance, fare;

	cout << "Enter the distance in kilometers: ";
	cin >> distance;

	cout << fixed << setprecision(2);

	if (distance <= 5) {
		fare = 25.0;
		cout << "Taxi fare is R"<< fare << endl;
	}
	else {
	    fare = 25.0 + (distance - 5) * 4.50;
	}
	cout << "Taxi fare is R" << fixed << setprecision(2) << fare << endl;

	return 0;
}