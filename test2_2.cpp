//============================================================================
// Name        : assignment1.cpp
// Author      : Matthew Brannen
// Version     : 1.0
// Copyright   : Fall Semester 2015 - Numerical Analysis - Sohn
// Description : Bisection Method
//============================================================================

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <iomanip>
using namespace std;

// defining the functions from the assignment
double f1(double x) {
	double answer;
	answer = 2*(x*x*x) - 6*(x) - 1;
	return answer;
}
double f2(double x) {
	double answer;
	double e = 2.7182818284590452353602874; //e defined as a constant to 25 decimal places
	double n = x - 2;
	answer = (pow(e,n)) + (x*x*x) - x;
	return answer;
}
double f3(double x) {
	double answer;
	answer = (pow(x,3)) - 100;
	return answer;
}
double f4(double x) {
	double answer;
	double cosX = cos(x);
	double cosSq = pow(cosX,2);
	answer = cosSq - x + 6;
	return answer;
}

//Function for checking the appropriate interval condition
bool initInterv(double a, double b){
	if((a < 0)  && (b > 0)){
		return true;
	}
	if((a > 0) && (b < 0)){
		return true;
	}
	else{
		return false;
	}

}

//Function for checking if the number is positive or negative
bool sign(double x){
	if (x > 0){
		return true;
	}
	else{
		return false;
	}
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
	if(funInp == 4){
	return 4;
	}
	else {
		return 0;
	}
}

//Main function that holds the bisection methods for each problem. Changes based on function selected
void bisection(int fun, double a, double b, double TOL, int NMAX){
	int n = 1;
	double c;
	double funA;
	double initA = a;
	double initB = b;
	double funC;
	bool signC;
	bool signA;
	switch(fun){
		case 1:
			while(n <= NMAX){
				c = (a+b)/2;
				funC = f1(c);
				double tolCheck = ((b-a)/2);
				if(funC == 0 || tolCheck < TOL){
					cout << "Solution found!: ";
					cout << setprecision(7) << c << endl;
					cout << "iteration number: " << n << endl;
					cout << "First Interval: " << initA << " through " << initB << endl;
					cout << "Last Interval: " << a << " through " << b;
					return;
				}
				n++;
				funA = f1(a);
				signC = sign(funC);
				signA = sign(funA);
				if(signC == signA){
					a = c;
				}
				else{
					b = c;
				}
			}
			cout << "Solution not found! Method Failed.";
			break;
		case 2:
			while(n <= NMAX){
				c = (a+b)/2;
				funC = f2(c);
				if(funC == 0 || ((b-a)/2) < TOL){
					cout << "Solution found!: ";
					cout << setprecision(7) << c <<  endl;
					cout << "iteration number: " << n <<endl;
					cout << "First Interval: " << initA << " through " << initB << endl;
					cout << "Last Interval: " << a << " through " << b;
					return;
				}
				n++;
				funA = f2(a);
				if(sign(funC) == sign(funA)){
					a = c;
				}
				else{
					b = c;
				}
			}
			cout << "Solution not found! Method Failed.";
			break;
		case 4:
			while(n <= NMAX){
				c = (a+b)/2;
				funC = f4(c);
				if(funC == 0 || ((b-a)/2) < TOL){
					cout << "Solution found!: ";
					cout << setprecision(7) << c << endl;
					cout << "iteration number: " << n <<endl;
					cout << "First Interval: " << initA << " through " << initB << endl;
					cout << "Last Interval: " << a << " through " << b;
					return;
				}
				n++;
				funA = f4(a);
				if(sign(funC) == sign(funA)){
					a = c;
				}
				else{
					b = c;
				}
			}
			cout << "Solution not found! Method Failed.";
			break;
		case 3:
			while(n <= NMAX){
				c = (a+b)/2;
				funC = f3(c);
				if(funC == 0 || ((b-a)/2) < TOL){
					cout << "Solution found!: ";
					cout << setprecision(7) << c << endl;
					cout << "iteration number: " << n <<endl;
					cout << "First Interval: " << initA << " through " << initB << endl;
					cout << "Last Interval: " << a << " through " << b;
					return;
				}
				n++;
				funA = f3(a);
				if(sign(funC) == sign(funA)){
					a = c;
				}
				else{
					b = c;
				}
			}
			cout << "Solution not found! Method Failed.";
			break;

	}
}

int main() {
	//initial display
	int fun;
	bool onOff = true;
	while(onOff == true){
	cout << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "Available function codes:" << endl;
	cout << "Function - 1: 2x^3-6x-1" << endl;
	cout << "Function - 2: e^(x-2) +x^3 -x" << endl;
	cout << "Function - 3: y^3 - 100" << endl;
	cout << "Function - 4: Intersection of y=cos^2(x) & y= x-6" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "!!! - Enter 0 to Exit - !!!" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << endl;	
	cout << "Input which function (1,2,3,4, or 0): ";
	cin >> fun; cout << endl; //user selects a function
	if(funSelector(fun) == 0){
		cout << "Program ending." << endl;
		onOff = false;
	}
	else{
		 double a; //initializing variables for input
		 double b = -100;
		double TOL;
		int NMAX;
		double aRoot;
		double bRoot;
		bool intervCheck;
		cout << "Function Entered: " << fun << endl;
		cout << "------------------" << endl;
	//	cout << "Select starting interval value a: "; //gathers input
	//	cin >> a; cout << endl;
	//		while((b <= a)){
	//		cout << "Select starting interval value b greater than a: ";
	//		cin >> b; cout << endl;
	//		}
	//	cout << "Select Tolerance: ";
	//	cin >> TOL; cout << endl;
	//	cout << "Select Maximum Iterations: ";
	//	cin >> NMAX; cout << endl;
		cout << "------------------" << endl;
		//selects which function to run and checks to see if the interval holds up first to the conditions
		switch (fun){
			case 1:
				a = -10;
				b = 10;
				TOL = 0.5*10e-6;
				NMAX = 1000;
				aRoot = f1(a);
				bRoot = f1(b);
				intervCheck = initInterv(a,b);
				cout << "Good interval? (0 is false, 1 is true): " << intervCheck << endl;
				cout << "F of a: " << aRoot << endl;cout << "F of b: " << bRoot << endl;
				if(intervCheck == true){
				bisection(fun, a, b, TOL, NMAX);
				}else{
					cout << "Pick a new interval";
					break;
				}
				break;
			case 2:
				a = -10;
				b = 10;
				TOL = 10e-6;
				NMAX = 1000;				
				 aRoot = f2(a);
				 bRoot = f2(b);
				 intervCheck = initInterv(a,b);
				 cout << "Good interval? (0 is false, 1 is true): " << intervCheck << endl;
				cout << "F of a: " << aRoot << endl;cout << "F of b: " << bRoot << endl;
				if(intervCheck == true){
					bisection(fun, a, b, TOL, NMAX);
				}else{
					cout << "Pick a new interval";
					return 0;
				}
				break;
			case 3:
				a = -10;
				b = 10;
				TOL = 10e-4;
				NMAX = 1000;				
				 aRoot = f3(a);
				 bRoot = f3(b);
				 intervCheck = initInterv(a,b);
				 cout << "Good interval? (0 is false, 1 is true): " << intervCheck << endl;
				cout << "F of a: " << aRoot << endl;cout << "F of b: " << bRoot << endl;
				if(intervCheck == true){
					bisection(fun, a, b, TOL, NMAX);
				}else{
					cout << "Pick a new interval";
					return 0;
				}
				break;
			case 4:
				a = -10;
				b = 10;
				TOL = 0.5*10e-6;
				NMAX = 1000;				
				aRoot = f4(a);
				bRoot = f4(b);
				intervCheck = initInterv(a,b);
				cout << "Good interval? (0 is false, 1 is true): " << intervCheck << endl;
				cout << "F of a: " << aRoot << endl;cout << "F of b: " << bRoot << endl;
				if(intervCheck == true){
					bisection(fun, a, b, TOL, NMAX);
				}else{
					cout << "Pick a new interval";
					return 0;
				}
				break;
		}
		

	}
}
return 0;
}


