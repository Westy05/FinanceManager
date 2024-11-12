Welcome to my first personal programming project! This project is intended to make managing your monthly budget easier by keeping track of your monthly income and expenses. 

## <ins>**Function Overview**<ins/>
Currently this project has a few functions, it can...
* Read user input and compile it into data for keeping track of monthly income and expenses.
* Use a map<string, double> object to hold the monthly expenses' names and costs.
* Prevent invalid inputs from the user from occurring such as typing in words for the cost instead of numbers.
* Save a FinanceProfile object's data to a .txt file or its map object to a .csv file.
* Add monthly expenses by reading a .txt file that contains the name of the expense and the cost of it.

## <ins>**File Overview**<ins/>
### main.cpp
This file essentially runs the code written in the other files so that the .exe actually does something when compiled.

### financeProfile.cpp
Essentially the implementation of the FinanceProfile class which allows the easy management of finances such as monthly income, expenses, etc.

### financeProfile.h
Just the declaration of the previously mentioned FinanceProfile class.


**Want to tweak my project?**

It's simple. All you have to do is just change the code inside the main function in main.cpp to change how it runs. Of course after making said changes, you have to recompile the program with all .h and .cpp files included.
