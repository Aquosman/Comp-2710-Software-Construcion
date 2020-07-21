//Ian Fair	
//izf0002
//hw1_izf0002.cpp
//The program calculates the fatal amount of diet coke (ew)
//I received no help at all. I am a boy genius.

#include <iostream>
#include <cmath>

using namespace std;

float calculateFD(float data[]);
int main()
{
	float data[3];
	const double artificial_sweetener = 0.001;
	double fatal_amount_human;

	cout << "Please input the weight of the mouse in kg: " <<endl;

		cin >> data[0];

	cout << "Please input the fatal amount of sweetener for a mouse in kg: " <<endl;

		cin >> data[1];

	cout << "Please input the weight of your dear friend in kg: " <<endl;

		cin >> data[2];

	cout << "The fatal amount of Coke for your friend is: "<<calculateFD(data)<<"kg" <<endl;
	return 0;
}
float calculateFD(float data[])
{
	const double artificial_sweetener = 0.001;
	double fatal_amount_human = (data[1] * data[2]) / (data[0] * artificial_sweetener);

	return fatal_amount_human;
}

