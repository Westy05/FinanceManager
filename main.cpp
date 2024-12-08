#include "FinanceProfile.h"
#include <iostream> // for cin and cout
#include <limits> // for numeric_limits

using namespace std;

string validInput(string outputVal, bool isNum);

// TODO: maybe add an imput manager class
int main() {
	FinanceProfile f1;
	string firstName, lastName;
	double income;

	firstName = validInput(string("first name"), false);
	lastName = validInput(string("last name"), false);
	income = stod(validInput(string("income"), true));

	FinanceProfile f2(firstName, lastName, income);
	f2.addMonthlyExpenses();
	f2.saveExpenses("expenses.csv");
	f2.saveProfile("profile.txt");
	cout << f2;

	return 0;
}

// gets an input from the user that makes sure that it is correct
string validInput(string outputVal, bool isNum) {
	string result;
	
	if (!isNum) { // checks whether to take a string input or a double input
		while (true) {
			cout << "Enter your " << outputVal << ": ";
			cin >> result;
			if (!cin.fail() && !result.empty()) {
				break;
			} else {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input! Please enter a valid " << outputVal << "." << endl;
			}
		}
	} else {
		double number;
		while (true) { // note: does not accept anything 0 or less
			cout << "Enter your " << outputVal << ": ";
			cin >> number;
			if (!cin.fail() && number > 0) {
				break;
			} else {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input! Please enter a valid, postive " << outputVal << "." << endl;
			}
		}
		result = to_string(number);
	}

	return result;
}