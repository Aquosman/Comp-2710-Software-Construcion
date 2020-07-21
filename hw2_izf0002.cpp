//Ian Fair
//izf0002
//hw2_izf0002.cpp
//The program calulates interest and end balance.
//I received no help at all. I am a boy genius.

#include <iostream>
#include <cmath>

using namespace  std;

int main()
{

	double interestRate = 0;
	double loanBalance = 0;
	double monthlyBalance = 0;
	double totalBalance = 0;
	int monthCount = 0;
	cout.precision(2);

	//Asks user for loan amount
	cout <<( "Loan Amount: ");
	cin >> loanBalance;

	//Now asks user for the interest rate
	cout << ("Interest Rate (% per year): ");
	cin >> interestRate;

	//Now asks for monthly amount
	cout << ("Monthly Payments: ");
	cin >> monthlyBalance;
	cout << endl;

	//Now for the variables that were stated earlier
	double monthlyInterest = interestRate / 12;
	double loanPayable = loanBalance;
	double interestThisMonth = loanBalance * (monthlyInterest / 100);
	double principal = 0;

	//Start of output code
	cout << ("******************************************************") << endl;
	cout << ("               Amortization Table") << endl;
	cout << ("******************************************************") << endl;
	cout << ("Month  Balance  Payment  Rate  Interest  Principal") << endl;
	cout << ("0      $")<< fixed << loanBalance << ("   N/A    N/A      N/A      N/A") << endl;

	//for loop that does the calculating with month counting
	while(loanPayable > 0)
	{

	interestThisMonth = loanPayable * (monthlyInterest / 100);
	loanPayable -= monthlyBalance - interestThisMonth;
	principal = monthlyBalance - interestThisMonth;
	totalBalance += interestThisMonth;

	if (principal < 0) {

	cout <<  ("ERROR: Principal is less than 0") << endl;
	break;
	}

	
	if (loanPayable < 0) {
		principal += loanPayable;
		monthlyBalance += loanPayable;
		loanPayable = 0;
	}
	if(monthCount == 30)
	{
	cout << "Error cannot exceed 30 months";
	break;
	}
	cout << monthCount + 1 << ("     $") << fixed << loanPayable << ("    $") << fixed << monthlyBalance << ("  ") << fixed << monthlyInterest  << ("    $") << fixed << interestThisMonth << ("     $") << fixed << principal << endl;
	monthCount++;
}

	//Now lastly the bottom part of the users output
	cout << ("*****************************************************") << endl;
	cout << endl;
	cout << ("It takes ") << monthCount << (" months to pay off the loan.") << endl;
	cout << ("Total interest paid is:  $") << fixed << totalBalance << endl;
	cout << endl;
return 0;
}
	   

