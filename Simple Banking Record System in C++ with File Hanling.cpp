#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Function to add a record
void addRecord() {
ofstream file("Bank Records.txt", ios::app); // Open file in append mode
if (!file) {
cout << "Error opening file!\n";
return;
}

int accountNumber;
string firstName, lastName;
float balance;

cout << "Enter Account Number: ";
cin >> accountNumber;
cout << "Enter First Name: ";
cin >> firstName;
cout << "Enter Last Name: ";
cin >> lastName;
cout << "Enter Balance: ";
cin >> balance;

file << accountNumber << " " << firstName << " " << lastName << " " << balance << endl;

file.close();
cout << "Record added successfully!\n";

}

// Function to display all records
void displayRecords() {
ifstream file("Bank Records.txt");
if (!file) {
cout << "Error opening file or no records found!\n";
return;
}

int accountNumber;
string firstName, lastName;
float balance;

cout << "\nBank Records:\n";
cout << "--------------------------------\n";
while (file >> accountNumber >> firstName >> lastName >> balance) {
	cout << setprecision(2) << showpoint << fixed;
    cout << "Account No: " << accountNumber << "\n";
    cout << "Name: " << firstName << " " << lastName << "\n";
    cout << "Balance: $" << balance << "\n";
    cout << "--------------------------------\n";
}

file.close();

}

// Function to search for a record
void searchRecord() {
ifstream file("Bank Records.txt");
if (!file) {
cout << "Error opening file or no records found!\n";
return;
}


int searchAcc, accountNumber;
string firstName, lastName;
float balance;
bool found = false;

cout << "Enter Account Number to search: ";
cin >> searchAcc;

while (file >> accountNumber >> firstName >> lastName >> balance) {
    if (accountNumber == searchAcc) {
    	cout << setprecision(2) << showpoint << fixed;
        cout << "\nRecord Found:\n";
        cout << "--------------------------------\n";
        cout << "Account No: " << accountNumber << "\n";
        cout << "Name: " << firstName << " " << lastName << "\n";
        cout << "Balance: $" << balance << "\n";
        cout << "--------------------------------\n";
        found = true;
        break;
    }
}

if (!found) {
    cout << "Record not found!!\n";
}

file.close();


}

// Function with menu

void menu(){
int choice;


do {
    cout << "---Banking Record System---\n\n";
    cout << "1. Add a record to a file\n";
    cout << "2. Display records from a file\n";
    cout << "3. Search a record from a file\n";
    cout << "4. Quit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            addRecord();
            break;
        case 2:
            displayRecords();
            break;
        case 3:
            searchRecord();
            break;
        case 4:
            cout << "Exiting the program...\n";
            break;
        default:
            cout << "Invalid choice! Please enter a number between 1-4.\n";
    }
} while (choice != 4);


}

// Main function with menu
int main() {
menu();
return 0;
}
