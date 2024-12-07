// g++ main.cpp financeProfile.cpp -std=c++11
#ifndef FinanceProfile_h
#define FinanceProfile_h

#include <string>
#include <unordered_map>
#include <fstream>

using namespace std;

class FinanceProfile {
	public:
		// Constructors
		FinanceProfile();
		FinanceProfile(string fName, string lName, double newIncome, double newExpenses);
		FinanceProfile(string fName, string lName, double newIncome);
		~FinanceProfile();

		// Member getter methods
		string getWholeName() const { return (firstName + " " + lastName); }
		string getFirstName() const { return firstName; }
		string getLastName() const { return lastName; }
		double getIncome() const { return income; }
		double getExpenses() const { return expenses; }
		unordered_map<string, double> getMonthlyExpenses() const { return monthlyExpenses; }

		void addMonthlyExpenses();
		void addMonthlyExpenses(const string& filename);
		void saveProfile(const string& filename);
		void saveExpenses(const string& filename);
		friend ostream& operator <<(ostream& out, const FinanceProfile& profile);

	private:
		string firstName; // first name of the user
		string lastName; // last name of the user
		double income; // monthly income of the user
		double expenses; // total amount of monthly expenses of the user
		unordered_map<string, double> monthlyExpenses; // name of expense and the monthly cost of it
};

#endif