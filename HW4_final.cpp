//============================================================================
// Name        : HW4_final.cpp
// Author      : Matthew Brannen
// Version     : 1.0
// Copyright   : Fall Semester 2015 - Numerical Analysis - Sohn
// Description : Midpoint & Simpsons Rule
//============================================================================

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <iomanip>
using namespace std;

double f1(double x) {
	double answer;
	double term1 = x*x;
	answer = 1/(1 + term1);
	return answer;
}
double f2(double x) {
	double answer;
	double xSq = x*x;
	answer = xSq*sin(x);
	return answer;
}


int funSelector(int funInp) {
	if(funInp == 1){
	return 1;
	}
	if(funInp == 2){
	return 2;
	}
	else {
		return 0;
	}
}
int main() {
	int fun;
	bool onOff = true;
	while(onOff == true) //allows for continuous running of program to do multiple problems
	{
	cout << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "Available problem codes:" << endl;
	cout << "Problem - 1: 1 / 1 + x^2" << endl;
	cout << "Problem - 2: x^2 * sin(x)" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "!!! - Enter 0 to Exit - !!!" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << endl;
	cout << "Input which problem (1,2, or 0): ";
	cin >> fun; cout << endl; //user selects a function
	if(funSelector(fun) == 0){
		cout << "See ya" << endl; //terminates program if user inputs 0 or anything other than 1,2, or 3
		onOff = false;
		}
	if(funSelector(fun) == 1){
			double intA;
			double intB;
			int valN;
			bool evenCheck = false;
			cout << endl;
			cout << "Enter interval value a: ";
			cin >> intA; cout << endl;
			cout << "Enter interval value b: ";
			cin >> intB; cout << endl;
			while (evenCheck == false) {
			cout << "Enter an even integer N value: ";
			cin >> valN; cout << endl;
			if(valN%2 == 0 && valN != 0){
				evenCheck = true;
			}
			else{
				cout << "!! - Enter an !EVEN! integer for Composite functions! - !!" << endl;
				cout << endl;
			}
			}
				//Simpsons composite rule implementation
				double valH = (intB - intA)/valN;
				
				double oddFunSum = 0;
				double evenFunSum = 0;
				
				double answer;
				
				for(int i = 1; i <= valN; i++){
					if((i%2) == 1){
						oddFunSum = oddFunSum + f1(intA + (i * valH));
					}
					if((i%2) == 0){
						evenFunSum = evenFunSum + f1((intA + (i * valH)));
					}
					
				}	
				answer = (valH/3)*(f1(intA) + f1(intB) + (4 * oddFunSum) + (2 * evenFunSum));
				
				cout << "---Composite Simpson's Rule---" << endl;
				cout << "Interval of Integration: " << intA << " - " << intB << endl;
				cout << "Number of Subintervals: " << valN << endl;
				cout << "Approximate Value of Integral: " << answer << endl;
				
				cout << endl;
				
				//Composite Midpoint Implementation
				double midAns = 0;
				double answer2;
				double midPnt = intA + (valH/2);
				for(double i = 1; i <= valN; i++ ){
					
					midAns = midAns + f1(intA + midPnt);
					midPnt = midPnt + valH;
				}
				
				answer2 = valH * midAns;
				cout << "---Composite Midpoint Rule---" << endl;
				cout << "Interval of Integration: " << intA << " - " << intB << endl;
				cout << "Number of Subintervals: " << valN << endl;
				cout << "Approximate Value of Integral: " << answer2 << endl;
		}
	if(funSelector(fun) == 2){
			double intA;
			double intB;
			int valN;
			bool evenCheck = false;
			cout << endl;
			cout << "Enter interval value a: ";
			cin >> intA; cout << endl;
			cout << "Enter interval value b: ";
			cin >> intB; cout << endl;
			while (evenCheck == false) {
				cout << "Enter an even integer N value: ";
				cin >> valN; cout << endl;
				if(valN%2 == 0 && valN != 0){
					evenCheck = true;
				}
				else{
				cout << "!! - Enter an !EVEN! integer for Composite functions! - !!" << endl;
				cout << endl;
				}
			}	
				//Simpsons composite rule implementation
				double valH = (intB - intA)/valN;
				double oddFunSum = 0;
				double evenFunSum = 0;
				
				double answer;
				
				for(int i = 1; i <= valN; i++){
					if((i%2) == 1){
						oddFunSum = oddFunSum + f2(intA + (i * valH));
					}
					if((i%2) == 0){
						evenFunSum = evenFunSum + f2((intA + (i * valH)));
					}
					
				}	
				answer = (valH/3)*(f2(intA) + f2(intB) + (4 * oddFunSum) + (2 * evenFunSum));
				
				cout << "---Composite Simpson's Rule---" << endl;
				cout << "Interval of Integration: " << intA << " - " << intB << endl;
				cout << "Number of Subintervals: " << valN << endl;
				cout << "Approximate Value of Integral: " << answer << endl;
				
				cout << endl;
				
				//Composite Midpoint Implementation
				double midAns = 0;
				double answer2;
				double midPnt = intA + (valH/2);
				for(double i = 1; i <= valN; i++ ){
					
					midAns = midAns + f2(intA + midPnt);
					midPnt = midPnt + valH;
				}
				
				answer2 = valH * midAns;
				cout << "---Composite Midpoint Rule---" << endl;
				cout << "Interval of Integration: " << intA << " - " << intB << endl;
				cout << "Number of Subintervals: " << valN << endl;
				cout << "Approximate Value of Integral: " << answer2 << endl;
		}
	
	
	}
}
