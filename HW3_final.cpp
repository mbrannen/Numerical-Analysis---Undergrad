//============================================================================
// Name        : HW3_final.cpp
// Author      : Matthew Brannen
// Version     : 1.0
// Copyright   : Fall Semester 2015 - Numerical Analysis - Sohn
// Description : Newton Divided Difference
//============================================================================

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <iomanip>
using namespace std;

double f1(double x) {
	double answer;
	double term1 = sin(x)*sin(x)*sin(x);
	double n = 3;
	double term2 = x*3;
	answer = 5*term1 + cos(term2);
	return answer;
}
double f2(double x) {
	double answer;
	double e = 2.7182818284590452353602874; //e defined as a constant to 25 decimal places
	double xSq = x*x;
	double n = xSq;
	answer = pow(e,n);
	return answer;
}
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
int main() {
	int fun;
	bool onOff = true;
	while(onOff == true) //allows for continuous running of program to do multiple problems
	{
	cout << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "Available problem codes:" << endl;
	cout << "Problem - 1: 5sin^3(x) + cos(3x)" << endl;
	cout << "Problem - 2: e^x^2" << endl;
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
			double valX;
			cout << endl;
			cout << "Enter interval value a: ";
			cin >> intA; cout << endl;
			cout << "Enter interval value b: ";
			cin >> intB; cout << endl;
			cout << "Enter X value to determine: ";
			cin >> valX; cout << endl;
		//	intervalDetermine(intA, intB);
				double intXArray[11];
				double intYArray[11];
				double addValue;
				addValue = ((intB-intA)/9);
				intXArray[1]= intA;
				intXArray [10] = intB;
				for (int i = 2;i < 10; i++){	
					int loc = i - 1;
					intXArray[i] = intXArray[loc] + addValue;
				}
				for(int i = 1; i<=10;i++){
					cout << "x" << i << " value: " << intXArray[i] << endl;
					intYArray[i] = f1(intXArray[i]);
				}
				for(int i = 1; i<=10;i++){
				cout << "y" << i << "value: " << intYArray[i] << endl;
				}
				cout << endl;
				
				double helpArray[11];
				int j = 1;
				int n = 10;
				double fu1 = 1;
				double fu2 = 0;
				double fO = intYArray[1];
				while( n != 1){
					for (int i=1;i<=n-1;i++)
     			   {
       			     helpArray[i] = ((intYArray[i+1]-intYArray[i])/(intXArray[i+j] - intXArray[i]));
     		     	  intYArray[i]= helpArray[i];
     		     	  
    				}
      			  fu1=1;
       				for(int i=1;i<=j;i++)
         			{
               		 fu1 *= (valX - intXArray[i]);
           			}
      				fu2 += (intYArray[1]*fu1);
        			n--;
        			j++;
				}
				double finalYVal = fO + fu2;
				cout << "P(x) value: " << finalYVal << endl;
				double error;
				error = f1(valX) - finalYVal;
				cout << "error of P(x) - f(x): " << error << endl;
				

		}
	if(funSelector(fun) == 2){
			double intA;
			double intB;
			double valX;
			cout << endl;
			cout << "Enter interval value a: ";
			cin >> intA; cout << endl;
			cout << "Enter interval value b: ";
			cin >> intB; cout << endl;
			cout << "Enter X value to determine: ";
			cin >> valX; cout << endl;
		//	intervalDetermine(intA, intB);
				double intXArray[11];
				double intYArray[11];
				double addValue;
				addValue = ((intB-intA)/9);
				intXArray[1]= intA;
				intXArray [10] = intB;
				for (int i = 2;i < 10; i++){	
					int loc = i - 1;
					intXArray[i] = intXArray[loc] + addValue;
				}
				for(int i = 1; i<=10;i++){
					cout << "x" << i << " value: " << intXArray[i] << endl;
					intYArray[i] = f2(intXArray[i]);
				}
				for(int i = 1; i<=10;i++){
				cout << "y" << i << " value: " << intYArray[i] << endl;
				}
				
				cout << endl;
				double helpArray[11];
				int j = 1;
				int n = 10;
				double fu1 = 1;
				double fu2 = 0;
				double fO = intYArray[1];
				while( n != 1){
					for (int i=1;i<=n-1;i++)
     			   {
       			     helpArray[i] = ((intYArray[i+1]-intYArray[i])/(intXArray[i+j] - intXArray[i]));
     		     	  intYArray[i]= helpArray[i];
     		     	  
    				}
      			  fu1=1;
       				for(int i=1;i<=j;i++)
         			{
               		 fu1 *= (valX - intXArray[i]);
           			}
      				fu2 += (intYArray[1]*fu1);
        			n--;
        			j++;
				}
				double finalYVal = fO + fu2;
				cout << "P(x) value: " << finalYVal << endl;
				double error;
				error = f2(valX) - finalYVal;
				cout << "error of P(x) - f(x): " << error << endl;
				

		}
	
	
	}
}
