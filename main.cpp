#include "FinanceProfile.h"

using namespace std;

int main() {
	FinanceProfile f1;
	FinanceProfile f2("John", "Smith", 50000);
	f2.addSubscriptions();
	f2.saveProfile("profile.txt");
	cout << f2;

	return 0;
}