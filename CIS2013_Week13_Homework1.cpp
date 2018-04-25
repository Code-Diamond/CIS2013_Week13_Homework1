#include <iostream>
#include <cstring>

using namespace std;

class BankAccount
{

	public:
		string name;
		int acctNumber;
		long long phone;
		long long balance;
		int rate;
		string accountType;
		int overdraftFee = 50;

		int minimumBalance = 1000;
		int withdrawLimit = 800;
		string getName()
		{
			return name;
		}	
		int getAcctNumber()
		{
			return acctNumber;
		}	
		long long getPhone()
		{
			return phone;
		}	
		int getBalance()
		{
			return balance;
		}	
		int getRate()
		{
			return rate;
		}	
		void setName(string inputName)
		{
			name = inputName;
		}	
		void setAcctNumber(int inputAcctNumber)
		{
			acctNumber = inputAcctNumber;
		}	
		void setPhone(int inputPhone)
		{
			phone = inputPhone;
		}	
		void setBalance(int inputBalance)
		{
			balance = inputBalance;
		}	
		void setRate(int inputRate)
		{
			rate = inputRate;
		}			

		void printBalance()
		{
			cout << "Current balance is: " << balance;
			system("pause");
		}
		
		void depositMoney()
		{
			system("CLS");
			cout << "\n\n\n		How much would you like to deposit?	\n";
			int amount;
			cin >> amount;
			balance += amount;
		}

		void withdrawMoney()
		{
			system("CLS");
			cout << "\n\n\n		How much would you like to withdraw?	\n";
			int amount;
			cin >> amount;
			if(accountType == "Savings")
			{
				if((balance - amount) < minimumBalance)
				{
					cout << "Warning! You will get a min balance fee unless you deposit enough to have $1000 before settlement.\n";
					balance -= amount;
					system("pause");
				}
				else if(amount > withdrawLimit)
				{
					cout << "You cannot withdraw that much, $800 is the maximum withdrawal in a day. . . Returning to the main menu.\n";
					system("pause");
				}
				else
				{
					balance -= amount;
				}
			}
			else if(accountType == "Checking")
			{
				balance -= amount;
				if(balance < 0)
				{
					balance -= overdraftFee;
				}
			}
			else
			{
				balance -= amount;	
			}

			
		}
		void displayAccountInformation()
		{
			cout << "Name: " << name << endl;
			cout << "Account Number: " << acctNumber << endl;
			cout << "Phone: " << phone << endl;
			cout << "Balance: " << balance << endl;
			cout << "Rate: " << rate << endl;
			cout << "Account Type: " << accountType << endl << endl << endl;
			system("pause");
		}


};
class Regular: public BankAccount
{
public:
	Regular(int i)
	{
		system("CLS");
		string inputName;
		long long inputPhone;
		long long inputBalance;
		rate = 1;
		cout << "Please enter your account's name: ", cin >> inputName;
		name = inputName;
		cout << "Please enter your account's phone (No dashes): ", cin >> inputPhone;
		phone = inputPhone;
		cout << "Please enter your account's balance: ", cin >> inputBalance;
		balance = inputBalance;

		cout << "Bank account made!\n\n";
		acctNumber = i;
		accountType = "Regular";
		displayAccountInformation();
	}

};
class Savings: public BankAccount
{
	public:


		Savings(int i)
		{
			system("CLS");
			string inputName;
			long long inputPhone;
			long long inputBalance;
			cout << "Please enter your account's name: ", cin >> inputName;
			name = inputName;
			cout << "Please enter your account's phone (No dashes): ", cin >> inputPhone;
			phone = inputPhone;
			balance = 0;
			rate = 2;
			while(balance < minimumBalance)
			{
				cout << "Please enter your account's balance: ", cin >> inputBalance;
				balance = inputBalance;
				if(balance < minimumBalance)
				{
					cout << "A minimum balance of $1000 is required to open this account.\n";
				}
			}
			
			accountType = "Savings";
			cout << "Bank account made!\n\n";
			acctNumber = i;
			displayAccountInformation();
		}

};

class Checking: public BankAccount
{
	public:
		Checking(int i)
		{
			system("CLS");
			string inputName;
			long long inputPhone;
			long long inputBalance;
			rate = 1;
			cout << "Please enter your account's name: ", cin >> inputName;
			name = inputName;
			cout << "Please enter your account's phone (No dashes): ", cin >> inputPhone;
			phone = inputPhone;
			cout << "Please enter your account's balance: ", cin >> inputBalance;
			balance = inputBalance;

			cout << "Bank account made!\n\n";
			accountType = "Checking";
			acctNumber = i;
			displayAccountInformation();
		}
};



string PrintMenu();
string PrintNewAccountMenu();
string AccountMenu();
void MainMenuLogic(string);



string PrintMenu();
string PrintNewAccountMenu();
void MainMenuLogic(string);
BankAccount *accounts[100];

int numberOfAccounts = 1;

int main()
{

	system("CLS");
	cout << "\n\n\nWelcome to the infamous bank account application.\n\n\n";
	system("pause");
	while(true)
	{
		string decision = PrintMenu();	
		MainMenuLogic(decision);
	}

	return 0;
}






void MainMenuLogic(string decision)
{
	if(decision == "o" || decision == "O")
	{
		string newAccountDecision = PrintNewAccountMenu();

		if(newAccountDecision == "r" || newAccountDecision == "R")
		{
			accounts[numberOfAccounts] = new Regular(numberOfAccounts);
			numberOfAccounts++;
		}
		else if(newAccountDecision == "s" || newAccountDecision == "S")
		{
			accounts[numberOfAccounts] = new Savings(numberOfAccounts);
			numberOfAccounts++;
		}
		else if(newAccountDecision == "c" || newAccountDecision == "C")
		{
			accounts[numberOfAccounts] = new Checking(numberOfAccounts);
			numberOfAccounts++;			
		}
	}
	else if(decision == "C" || decision == "c")
	{
		system("CLS");
		int inputAcctNumber;
		cout << "Please enter the account number: ";
		cin >> inputAcctNumber;
		accounts[inputAcctNumber]->displayAccountInformation();

		string accountDecision = AccountMenu();

		if(accountDecision == "d")
		{
			accounts[inputAcctNumber]->depositMoney();
		}
		else if(accountDecision == "w")
		{
			accounts[inputAcctNumber]->withdrawMoney();
		}
	}
	else
	{

		cout << "You entered something else...\n\n";
		system("pause");
	}
}


string PrintMenu()
{
	system("CLS");
	cout << "\n\n		Main Menu		\n";
	cout << "\n			-Open new bank account		(o)\n";
	cout << "\n			-Check a bank account		(c)\n";
	string decision;
	cin >> decision;
	return decision;
}

string AccountMenu()
{
	system("CLS");
	cout << "\n\n		What would you like to do?		\n";
	cout << "\n			-deposit money		(d)\n";
	cout << "\n			-withdraw money		(w)\n";
	string decision;
	cin >> decision;
	return decision;
}

string PrintNewAccountMenu()
{
	system("CLS");
	cout << "\n\n\n		Which type of account?		\n";
	cout << "\n\n\n			-regular		(r)\n";
	cout << "\n\n\n			-savings		(s)\n";
	cout << "\n\n\n			-checking		(c)\n";
	string decision;
	cin >> decision;
	return decision;
}
