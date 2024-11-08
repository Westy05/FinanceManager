#include "FinanceProfile.h"

using namespace std;

int main() {
	FinanceProfile f1;
	string firstName, lastName;
	double income;

	while (true) {
		cout << "Enter your first name: ";
		cin >> firstName;
		if (!cin.fail() && !firstName.empty()) {
			break;
		} else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input! Please enter a valid first name." << endl;
		}
	}

	while (true) {
		cout << "Enter your last name: ";
		cin >> lastName;
		if (!cin.fail() && !lastName.empty()) {
			break;
		} else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input! Please enter a valid last name." << endl;
		}
	}

	while (true) {
		cout << "Enter your monthly income: ";
		cin >> income;
		if (!cin.fail() && income >= 0) {
			break;
		} else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input! Please enter a valid non-negative number for income." << endl;
		}
	}

	FinanceProfile f2(firstName, lastName, income);
	f2.addSubscriptions();
	f2.saveProfile("profile.txt");
	cout << f2;

	return 0;
}