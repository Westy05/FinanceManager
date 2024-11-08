// g++ main.cpp financeProfile.cpp -std=c++11
#ifndef FinanceProfile_h
#define FinanceProfile_h

#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <cctype>
#include <fstream>
#include <cstdlib>

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
		map<string, double> getSubscriptions() const { return subscriptions; }

		void addSubscriptions();
		void saveProfile(const string& filename);
		friend ostream& operator <<(ostream& out, const FinanceProfile& profile);

	private:
		string firstName; // first name of the user
		string lastName; // last name of the user
		double income; // monthly income of the user
		double expenses; // monthly expenses of the user
		map<string, double> subscriptions; // name of subscription and the monthly cost
};

#endif