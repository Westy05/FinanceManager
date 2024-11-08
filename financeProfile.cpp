#include "FinanceProfile.h"

using namespace std;

// default constructor
FinanceProfile::FinanceProfile() {
	firstName = "N/A";
	lastName = "N/A";
	income = 0;
	expenses = 0;
}

// constructor with all parameters
FinanceProfile::FinanceProfile(string fName, string lName, double newIncome, double newExpenses) {
	firstName = fName;
	lastName = lName;
	income = newIncome;
	expenses = newExpenses;
}

// constructor with only first name, last name, and income
FinanceProfile::FinanceProfile(string fName, string lName, double newIncome) {
	firstName = fName;
	lastName = lName;
	income = newIncome;
	expenses = 0;
}

// destructor, just clears the subscriptions map
FinanceProfile::~FinanceProfile() {
	monthlyExpenses.clear();
}

// adds the cost to the total expenses and inserts the sub's name and cost into the subscriptions map
void FinanceProfile::addMonthlyExpenses() {
	string nameOfSub = "";
	double costOfSub = 0;
	char moreSubs;

	// loops while the user is not done yet entering their subscriptions
	while (true) {

		// first asks for name of sub and gets the line for it, while loop prevents a non-string from being entered
		cout << "Enter the name of the subscription: ";
		getline(cin, nameOfSub);

		// Validate that the name isn't empty and contains at least one non-whitespace character
		while (nameOfSub.empty() || nameOfSub.find_first_not_of(" \t\n\r") == string::npos) {
			cout << "Invalid name! Please enter a non-empty name: ";
			getline(cin, nameOfSub);
		}

		cout << endl << "Enter the monthly cost of the subscription: ";
		cin >> costOfSub;
		cin.ignore();

		// makes sure no invalid types are added
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Wrong type! Please enter a number: ";
			cin >> costOfSub;
		}

		// adds the cost to the total expenses
		expenses += costOfSub;
		// inserts the sub's name and cost into the subscriptions map
		monthlyExpenses.insert({nameOfSub, costOfSub});

		// checks if the user wants to add anymore additional subs, prevents anything other than a char
		cout << endl << "Anymore subscriptions to add? (Y/N): ";
		cin >> moreSubs;
		cin.ignore();

		while (cin.fail() || (toupper(moreSubs) != 'Y' && toupper(moreSubs) != 'N')) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter Y or N: ";
			cin >> moreSubs;
			cin.ignore();
		}

		// ends while loop if user says it has no more additional subs to add
		if (toupper(moreSubs) == 'N') {
			break;
		}
	}
}

// adds the monthly expenses from a file (preferably a .txt file) to the finance profile object
void FinanceProfile::addMonthlyExpenses(const string& filename) {
	ifstream inFile(filename);
	string nameOfSub = "";
	double costOfSub = 0;

	// checks if the file was opened successfully
	if (inFile.fail()) {
		cout << "Error opening file for reading!" << endl;
		exit(1);
	}

	while (inFile >> nameOfSub >> costOfSub) {
		expenses += costOfSub;
		monthlyExpenses.insert({nameOfSub, costOfSub});
	}

	inFile.close();
}

// saves the finance profile to a file, preferably a .txt file
void FinanceProfile::saveProfile(const string& filename) {
	ofstream outFile(filename);

	// checks if the file was opened successfully
	if (outFile.fail()) {
		cout << "Error opening file for writing!" << endl;
		
		exit(1);
	}

	// writes the finance profile to the file and closes it
	outFile << *this;
	outFile.close();
}

// overloaded << operator to output the finance profile
ostream& operator <<(ostream& out, const FinanceProfile& profile) {
	out << "Name: " << profile.getWholeName() << endl;
	out << "Income: $" << profile.getIncome() << endl;
	out << "Expenses: $" << profile.getExpenses() << endl;
	out << "Net Worth: $" << profile.getIncome() - profile.getExpenses() << endl;
	out << "Subscriptions: " << endl;

	// iterates through the monthly expenses map and outputs the name and cost of each subscription
	for (const auto& sub : profile.monthlyExpenses) {
		out << "Paying " << sub.first << " for $" << sub.second << " per month" << endl;
	}

	return out;
}
