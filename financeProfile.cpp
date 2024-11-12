#include "FinanceProfile.h"
#include <iostream> // for cin and cout
#include <limits> // for numeric_limits
#include <cstdlib> // for exit()

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

// destructor, just clears the monthly expenses map
FinanceProfile::~FinanceProfile() {
	monthlyExpenses.clear();
}

// adds the cost to the total expenses and inserts the expense's name and cost into the monthly expenses map
void FinanceProfile::addMonthlyExpenses() {
	string nameOfExpense = "";
	double costOfExpense = 0;
	char moreExpenses;

	cin.ignore();
	// loops while the user is not done yet entering their monthly expenses
	while (true) {
		// first asks for name of expense and gets the line for it, while loop prevents a non-string from being entered
		cout << "Enter the name of the monthly expense: ";
		getline(cin, nameOfExpense);

		// Validate that the name isn't empty and contains at least one non-whitespace character
		while (nameOfExpense.empty() || nameOfExpense.find_first_not_of(" \t\n\r") == string::npos) {
			cout << "Invalid name! Please enter a non-empty name: ";
			getline(cin, nameOfExpense);
		}

		cout << endl << "Enter the monthly cost of the expense: ";
		cin >> costOfExpense;
		cin.ignore();

		// makes sure no invalid types are added
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Wrong type! Please enter a number: ";
			cin >> costOfExpense;
		}

		// adds the cost to the total expenses
		expenses += costOfExpense;
		// inserts the expense's name and cost into the monthly expenses map
		monthlyExpenses.insert({nameOfExpense, costOfExpense});

		// checks if the user wants to add anymore additional expenses, prevents anything other than a char
		cout << endl << "Anymore monthly expenses to add? (Y/N): ";
		cin >> moreExpenses;
		cin.ignore();

		while (cin.fail() || (toupper(moreExpenses) != 'Y' && toupper(moreExpenses) != 'N')) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter Y or N: ";
			cin >> moreExpenses;
			cin.ignore();
		}

		// ends while loop if user says it has no more additional expenses to add
		if (toupper(moreExpenses) == 'N') {
			break;
		}
	}
}

// adds the monthly expenses from a file (preferably a .txt file) to the finance profile object
void FinanceProfile::addMonthlyExpenses(const string& filename) {
	ifstream inFile(filename);
	string nameOfExpense = "";
	double costOfExpense = 0;

	// checks if the file was opened successfully
	if (inFile.fail()) {
		cout << "Error opening file for reading!" << endl;
		exit(1);
	}

	while (inFile >> nameOfExpense >> costOfExpense) {
		expenses += costOfExpense;
		monthlyExpenses.insert({nameOfExpense, costOfExpense});
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


// saves the finance profile to a file, preferably a .csv file
void FinanceProfile::saveExpenses(const string& filename) {
	ofstream outFile(filename);

	// checks if the file was opened successfully
	if (outFile.fail()) {
		cout << "Error opening file for writing!" << endl;
		
		exit(1);
	}

	// iterates through the monthly expenses map and outputs the name and cost of each expense
	outFile << "NameOfExpense,CostOfExpense" << endl;
	for (const auto& expense : monthlyExpenses) {
		outFile << expense.first << "," << expense.second << endl;
	}

	outFile.close();
}

// overloaded << operator to output the finance profile
ostream& operator <<(ostream& out, const FinanceProfile& profile) {
	out << "Name: " << profile.getWholeName() << endl;
	out << "Monthly Income: $" << profile.getIncome() << endl;
	out << "Total Monthly Expenses: $" << profile.getExpenses() << endl;
	out << "Net Monthly Income: $" << profile.getIncome() - profile.getExpenses() << endl;
	out << "Monthly Expenses: " << endl;

	// iterates through the monthly expenses map and outputs the name and cost of each expense
	for (const auto& expense : profile.monthlyExpenses) {
		out << "Paying " << expense.first << " for $" << expense.second << " per month" << endl;
	}

	return out;
}
