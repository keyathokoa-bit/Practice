#include<iostream>
using namespace std;

int main() {
	int n = 0;
	int sumOfEvens = 0;

	cout << "Please enter a number from 1 to 20: ";
	cin >> n;
	while (n < 1 || n > 20) {
		cout << "Invalid. Try again ( 1-20 ): ";
		cin >> n;
	}

	for (int n = 1; n <= 20; n++) {
		cout << n;

		if (n % 2 == 0) {
			cout << n << " is even" << endl;
			sumOfEvens += n;
		}
		else {
			cout << n << " is odd" << endl;
		}
	}

	cout << "Sum of even numbers: " << sumOfEvens << endl;

	return 0;
}
