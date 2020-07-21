// Ian Fair
// izf0002
// hw3_izf0002.cpp
// This program demonstrates a duel simulator
// I am genius I had no help.
//
//




#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>

using namespace std;

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void Aaron_shoots1(bool& B_alive, bool& C_alive);
void Bob_shoots(bool& A_alive, bool& C_alive);
void Charlie_shoots(bool& A_alive, bool& B_alive);
void Aaron_shoots2(bool& B_alive, bool& C_alive);
void test_at_least_two_alive(void);


//main

int main()
{
	srand(time(0));

	bool Aaron = true;
	bool Bob = true;
	bool Charlie = true;
	int a = 0;
	int b = 0;
	int c = 0;
	int x = 0;
	int y = 0;
	int z = 0;
	const int tenk = 10000;
	const int hitpa = 33;
	const int hitpb = 50;
	

	//Prostrat 1
	for(int i = 0; i < 10000; i++)
	{
	do
	{
	
		if (Aaron == true)
		{
			Aaron_shoots1(Bob, Charlie);
		}
		
		 if (Bob == true)
		{
			Bob_shoots(Aaron, Charlie);
		}
		
		 if (Charlie == true)
		{
			Charlie_shoots(Aaron, Bob);
		}
	} while (at_least_two_alive(Aaron, Bob, Charlie));



	if (Aaron == true) {
		a++;
	}
	if (Bob == true) {
		b++;
	}
	if (Charlie == true) {
		c++;
	}

	//end prostrat1 
	Aaron = true;
	Bob = true;
	Charlie = true;
	}
	
	//Prostratt 2
	for(int j = 0; j < 10000; j++)
	{
		do
		{
			if (Aaron == true)
			{
				Aaron_shoots2(Bob, Charlie);
			}
			
			 if (Bob == true)
			{
				Bob_shoots(Aaron, Charlie);
			}
			
			 if (Charlie == true)
			{
				Charlie_shoots(Aaron, Bob);
			}
		} while (at_least_two_alive(Aaron, Bob, Charlie));

		if (Aaron == true) {
			x++;
		}

		if (Bob == true) {
			y++;
		}

		if (Charlie == true) {
			z++;
		}

		//end Prostratt 2
		Aaron = true;
		Bob = true;
		Charlie = true;
	}
	
	//Percent stats stuff
	double aa = (a * 100);
	double bb = (b * 100);
	double cc = (c * 100);
	double xx = (x * 100);
	double yy = (y * 100);
	double zz = (z * 100);

	//the output
	cout << "*** Welcome to the Duel Simulator ***" << endl;
	test_at_least_two_alive();
	cout << "Press Enter to continue...";
	cin.get();
	cout << "Ready to test strategy 1 (run 10000 times): " << endl;
	cout << "Press Enter to continue...";
	cin.get();
	cout << "Aaron won "<< a << "/10000 duels or " << aa / 10000 << "%" << endl;
	cout << "Bob won " << b << "/10000 duels or " << bb / 10000 << "%" << endl;
	cout << "Charlie won " << c << "/10000 duels or "<< cc / 10000 << "%" << endl;
	cout << endl;


	cout << "Ready to test strategy 2 (run 10000 times): " << endl;
	cout << "Press Enter to continue...";
	cin.get();
	cout << "Aaron won "<< x << "/10000 duels or " << xx / 10000 << "%" << endl;
	cout << "Bob won " << y << "/10000 duels or " << yy / 10000 << "%" << endl;
	cout << "Charlie won " << z << "/10000 duels or " << zz / 10000 << "%" << endl;
	cout << endl;
	
	if (x > a) {
		cout << "Strategy 2 is better than strategy 1." << endl;
	}
	else if (x == a) {
		cout << "The Strategies are equal." << endl;
	}
	else
	{
		cout << "Strategy 1 is better than strategy 2." << endl;
	}
}
	void test_at_least_two_alive(void)
	{
	cout << "Unit Testing 1: Function - at_least_two_alive()\n";
	//unit test
	//test case 1
	cout << "Case 1: Aaron alive, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(true, true, true));
	cout << "Case passed ...\n";
	//test case 2
	cout << "Case 2: Aaron dead, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(false, true, true));
	cout << "Case passed ...\n";
	//test case 3
	cout << "Case 3: Aaron alive, Bob dead, Charlie alive\n";
	assert(true == at_least_two_alive(true, false, true));
	cout << "Case passed ...\n";
	//test case 4
	cout << "Case 4: Aaron alive, Bob alive, Charlie dead\n";
	assert(true == at_least_two_alive(true, true, false));
	cout << "Case passed ...\n";
	//test case 5
	cout << "Case 5: Aaron dead, Bob dead, Charlie alive\n";
	assert(false == at_least_two_alive(false, false, true));
	cout << "Case passed ...\n";
	//test case 6
	cout << "Case 6: Aaron alive, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(true, false, false));
	cout << "Case passed ...\n";
	//test case 7
	cout << "Case 7: Aaron dead, Bob alive, Charlie dead\n";
	assert(false == at_least_two_alive(false, true, false));
	cout << "Case passed ...\n";
	//test case 8
	cout << "Case 8: Aaron dead, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(false, false, false));
	cout << "Case passed ...\n";

	}

	bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive)
	{
	if (((A_alive == true ) && (B_alive == true) && (C_alive == false)) || ((A_alive == true) && (B_alive == false) && (C_alive == true))
	|| ((A_alive == false) && (B_alive == true) && (C_alive == true)) || ((A_alive == true) && (B_alive == true) && (C_alive == true)))
	{
		return true;
	}
	else 
	{
		return false;
	}
	}
	
	void Aaron_shoots1(bool& B_alive, bool& C_alive)
	{
		int result = rand() % 100;
		bool *p1 = &B_alive;
		bool *p2 = &C_alive;
	if (result <= 33) {
		if (C_alive) {
		*p2 = false;
		}
		else
		{
		*p1 = false;
		}
	}
	}
	
	void Bob_shoots(bool& A_alive, bool& C_alive)
	{
		int result = rand() % 100;
		bool *p1 = &A_alive;
		bool *p2 = &C_alive;

		if (result <= 50) {
			if (C_alive) {
				*p2 = false;
			}
			else
			{
				*p1 = false;
			}

		}
	}
	void Charlie_shoots(bool& A_alive, bool& B_alive)
	{
		int result = rand() % 100;
		bool *p1 = &A_alive;
		bool *p2 = &B_alive;
		
		if (B_alive) {
			*p2 = false;
		}
		else
		{
			*p1 = false;
		}
	}
	void Aaron_shoots2(bool& B_alive, bool& C_alive)
	{
		int result = rand() % 100;
		bool *p1 = &B_alive;
		bool *p2 = &C_alive;

		if (result <= 33) {
			if (!(B_alive && C_alive))
			{
				if (C_alive) {
					*p2 = false;
				}
				else
				{
					*p1 = false;
				}
			}
	}


	}
































