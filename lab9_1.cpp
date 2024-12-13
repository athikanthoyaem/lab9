#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){	

	double loan,interestRate, payment ;
	cout << "Enter initial loan: " ;
	cin >> loan ;
	cout << "Enter interest rate per year (%): ";
	cin >> interestRate ;
	cout << "Enter amount you can pay per year: ";
	cin >> payment ;

	interestRate = interestRate/100 ;

	int year = 1 ;
	double PrevBalance = loan ;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	
//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect
	cout << fixed << setprecision(2); 
	while( PrevBalance > 0 ){
		double interest = PrevBalance * interestRate ;
		double total = PrevBalance + interest ;
		double Newbalance = total - payment ;
		if(payment > total ){
			payment = total ;
			Newbalance = 0 ;
		}
	cout << setw(13) << left << year; 
	cout << setw(13) << left << PrevBalance;
	cout << setw(13) << left << interest ;
	cout << setw(13) << left << total;
	cout << setw(13) << left << payment;
	cout << setw(13) << left << Newbalance;
	cout << "\n";	

	if(Newbalance < 0.01 ) break;

	PrevBalance = Newbalance;
	year++;

	}
	
	
	return 0;
}
