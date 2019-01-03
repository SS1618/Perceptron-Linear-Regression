// PerceptronLinearRegression.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "math.h"
using namespace std;
#define RATE 0.01;
double costFunc(double correct, double answer);
double calcGrad(double cF, double x);
int main()
{
	double input[10][2] = {
		{1,3},
		{4,9},
		{3,7},
		{6,13},
		{9,19},
		{5,11},
		{7,15},
		{8,17},
		{10,21},
		{13,27}
	};
	double bias = 0.5;
	double w[2] = { 1,1 };
	double sum;
	double costF;
	for (int i = 0; i < 10; i++) {
		sum = (w[0] * bias) + (w[1] * input[i][0]);
		costF = costFunc(input[i][1], sum);
		cout << "Error: " << costF << endl;
		cout << "Outputs: " << sum << " for Input: " << input[i][0] << endl;
		w[1] -= calcGrad(costF, input[i][0])*RATE;
		w[0] -= calcGrad(costF, bias)*RATE;
	}
	cout << "y = " << w[1] << "x + " << w[0] << endl;
	cin.ignore();
	return 0;
}
double costFunc(double correct, double answer) {
	return (1.0 / 2.0)*((correct - answer)*(correct - answer));
}
double calcGrad(double cF, double x) {
	double grad = sqrt(cF * 2);
	grad *= x;
	return -1.0*grad;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
