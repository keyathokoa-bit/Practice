#include <iostream>
using namespace std;

void showBanner();
double celsiusToFahrenheit(double celsius);
double fahrenheitToCelsius(double fahrenheit);

int main() {
	double temp;
	
	showBanner();

		cout << "Enter the temperature in Celsius: ";
		cin >> temp;

		cout << temp << "C = " << celsiusToFahrenheit(temp) << "F" << endl;

		cout << "Enter the temperature in Fahrenheit: ";
		cin >> temp;
		cout << temp << "F = " << fahrenheitToCelsius(temp) << "C" << endl;

		return 0;
}
void showBanner() {
	cout << "Temperature Conversion Program" << endl;
}
double celsiusToFahrenheit(double celsius) {
	return (celsius * 9.0 / 5.0) + 32;
}
double fahrenheitToCelsius(double fahrenheit) {
	return (fahrenheit - 32) * 5.0 / 9.0;
}
