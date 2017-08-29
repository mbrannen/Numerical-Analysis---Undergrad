//============================================================================
// Name        : assignment2.cpp
// Author      : Matthew Brannen
// Version     : 1.0
// Copyright   : Fall Semester 2015 - Numerical Analysis - Sohn
// Description : Newton Method
//============================================================================

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <iomanip>
using namespace std;

// defining the functions from the assignment
double f1(double x) {
	double answer;
	double e = 2.7182818284590452353602874; //e defined as a constant to 25 decimal places
	double n = x;
	answer = pow(e,n) + sin(x) - 4;
	return answer;
}
double ff1(double x) {
	double answer;
	double e = 2.7182818284590452353602874; //e defined as a constant to 25 decimal places
	double n = x;
	answer = (pow(e,n)) + cos(x);
	return answer;
}
double f2(double x) {
	double answer;
	double e = 2.7182818284590452353602874; //e defined as a constant to 25 decimal places
	double n = x - 2;
	answer = 14*x*(pow(e,n)) - 12*(pow(e,n)) - (7*x*x*x) + (20*x*x) - (26*x) + 12;
	return answer;
}
double ff2a(double x) {
	double answer;
	double e = 2.7182818284590452353602874; //e defined as a constant to 25 decimal places
	double n = x - 2;
	answer = 14*(pow(e,n))*(x - 1) - (12*(pow(e,n))) - (21*x*x) + (40*x) - 26;
	return answer;
}
double ff2b(double x) {
	double answer;
	double e = 2.7182818284590452353602874; //e defined as a constant to 25 decimal places
	double n = x - 2;
	answer = (14*(pow(e,n))*x) + (2*(pow(e,n))) - (21*x*x) + (40*x) - 26;
	return answer;
}
double f3(double x) {
	double answer;
	double e = 2.7182818284590452353602874; //e defined as a constant to 25 decimal places
	double n = sin(x)*sin(x)*sin(x);
	answer = (pow(e,n)) + (pow(x,6)) - (2*x*x*x*x) - (x*x*x) - 1;
	return answer;
}
double ff3(double x) {
	double answer;
	double e = 2.7182818284590452353602874; //e defined as a constant to 25 decimal places
	double n = sin(x)*sin(x)*sin(x);
	answer = (3*(pow(e,n)*sin(x)*sin(x)*cos(x))) + (6*(pow(x,5))) - (8*x*x*x) - (3*x*x);
	return answer;
}

/*function that handle the users input and selects the appropriate function to use */
int funSelector(int funInp) {
	if(funInp == 1){
	return 1;
	}
	if(funInp == 2){
	return 2;
	}
	if(funInp == 3){
	return 3;
	}
	else {
		return 0;
	}
}

//Main function that holds the newton method for each problem. Changes based on function selected
void newton(int fun, double a, double TOL, int NMAX){
	int n = 1;
	double b;
	double initA = a;
	double funF;
	double funFF;
	switch(fun){
		case 1:
			while(n <= NMAX){
				funF = f1(a);
				funFF = ff1(a);
				b = a - ((funF)/(funFF));
				double tolCheck = fabs(b-a);
				if(tolCheck < TOL){
					cout << "Solution found!: ";
					cout << setprecision(9) << b << endl;
					cout << "iteration number: " << n << endl;
					cout << "Initial Guess: " << initA << endl;
					cout << endl;
					return;
				}
				a=b;
				n++;
			}
			cout << "Solution not found! Method Failed.";
			break; 
		case 2:
			while(n <= NMAX){ //first while loop to find first root
				funF = f2(a);
				funFF = ff2a(a);
				b = a - ((funF)/(funFF));
				double tolCheck = fabs(b-a);
				if(tolCheck < TOL){
					cout << "Solution found!: ";
					cout << setprecision(6) << b << endl;
					cout << "iteration number: " << n << endl;
					cout << "Initial Guess: " << initA << endl;
					cout << endl;
					n=1;
					a = initA;
					while(n <= NMAX){ //second while loop to find seceond root
						funF = f2(a);
						funFF = ff2b(a);
						b = a - ((funF)/(funFF));
						double tolCheck = fabs(b-a);
						if(tolCheck < TOL){
							cout << "Solution found!: ";
							cout << setprecision(7) << b << endl;
							cout << "iteration number: " << n << endl;
							cout << "Initial Guess: " << initA << endl;
							cout << endl;
							return;
						}
						a=b;
						n++;
					}			
				}
				a=b;
				n++;
			}
			cout << "Solution not found! Method Failed.";
			break;
			
		case 3:
			while(n <= NMAX){ //first while loop to find root
				funF = f3(a);
				funFF = ff3(a);
				b = a - ((funF)/(funFF));
				double tolCheck = fabs(b-a);
				if(tolCheck < TOL){
					cout << "Solution found!: ";
					cout << setprecision(7) << b << endl;
					cout << "iteration number: " << n << endl;
					cout << "Initial Guess: " << initA << endl;
					cout << endl;
					n=1;
					initA = -1;
					a= -1;
					while(n <= NMAX){ //second while loop to find root
						funF = f3(a);
						funFF = ff3(a);
						b = a - ((funF)/(funFF));
						double tolCheck = fabs(b-a);
						if(tolCheck < TOL){
							cout << "Solution found!: ";
							cout << setprecision(7) << b << endl;
							cout << "iteration number: " << n << endl;
							cout << "Initial Guess: " << initA << endl;
							cout << endl;
							return;
						}
						a=b;
						n++;
					}					
				}
				a=b;
				n++;
			}			
			cout << "Solution not found! Method Failed.";
			break;
	}
}

int main() {
	//initial display
	int fun;
	bool onOff = true;
	while(onOff == true) //allows for continuous running of program to do multiple problems
	{
	cout << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "Available problem codes:" << endl;
	cout << "Problem - 1: Intersection of y= e^x & y=4-sin(x)" << endl;
	cout << "Problem - 2: 14x*e^(x-2) - 12e^(x-2) - 7x^3 + 20x^2 -26x +12" << endl;
	cout << "Problem - 3: e^sin^3(x) + x^6 - 2x^4 - x^3 - 1" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "!!! - Enter 0 to Exit - !!!" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << endl;
	cout << "Input which problem (1,2,3, or 0): ";
	cin >> fun; cout << endl; //user selects a function
	if(funSelector(fun) == 0){
		cout << "See ya" << endl; //terminates program if user inputs 0 or anything other than 1,2, or 3
		onOff = false;
	}
	else{
		double a; //initializing variables for input
		double TOL;
		int NMAX;
		cout << "Function Entered: " << fun << endl;
		cout << "---------------------" << endl;
		cout << "---------------------" << endl;
		switch (fun){ //performs newtons method on the problem selected
			case 1:
				TOL = 10e-8;
				a = 4;
				NMAX = 1000;
				newton(fun,a,TOL,NMAX);
				break;
			case 2:
				TOL = 10e-6;
				a = 3;
				NMAX = 1000;
				newton(fun,a,TOL,NMAX); 
				break;
		
			case 3:
				TOL = 10e-6;
				a = 2;
				NMAX = 1000;
				newton(fun,a,TOL,NMAX); 
				break;
		}
		

	}
}
return 0;
}



