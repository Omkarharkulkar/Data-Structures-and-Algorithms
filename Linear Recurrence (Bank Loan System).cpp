// Design and develop a program using linear recurrence relations for various loan schemes of a bank.

#include<iostream>

using namespace std;

float Recursive(float Balance, float ir=0, int time=0);
void display()
{
	cout<<"_____________________Welcome to MIT Bank_______________________"<<"\n";
	cout<<"Our Bank gives THREE types of LOANS:"<<"\n";
	cout<<"1) Educational Loan"<<"\n";
	cout<<"2) Home Loan"<<"\n";
	cout<<"3) Car Loan"<<"\n";
}

int main()
{
	int t, no, choice=1;
	float p, r;
	display();
	
	while(choice!=0)
	{
		cout<<"\nEnter which loan you want: ";
		cin>>no;
		
		switch(no)
		{
			case 1:
				cout<<"\nRate of interest for Educational Loan amount are as follow: "<<"\n";
				cout<<"0 to 1,000 interest is 6 percent"<<"\n";
				cout<<"1,000 to 1,00,000 interest is 8 percent"<<"\n";
				cout<<"Above 1,00,000 interest is 10 percent"<<"\n\n";
				cout<<"Enter amount you want to take from bank: Rs.";
				cin>>p;
				cout<<"Enter time after which you will repay: ";
				cin>>t;
				
				if(p<1000)
				{
					r=6;
				}
				else if(p>1000 && p<100000)
				{
					r=8;
				}
				else
				{
					r=10;
				}
				
				cout<<"\nYou have to pay Rs."<<Recursive(p,r,t)<<" after "<<t<<" years"<<endl;
				break;
				
			case 2:
				cout<<"\nRate of interest for Home Loan amount are as follow: "<<"\n";
				cout<<"0 to 1,000 interest is 8 percent"<<"\n";
				cout<<"1,000 to 1,00,000 interest is 10 percent"<<"\n";
				cout<<"Above 1,00,000 interest is 12 percent"<<"\n\n";
				cout<<"Enter amount you want to take from bank: Rs.";
				cin>>p;
				cout<<"Enter time after which you will repay: ";
				cin>>t;
				
				if(p<1000)
				{
					r=8;
				}
				else if(p>1000 && p<100000)
				{
					r=10;
				}
				else
				{
					r=12;
				}
				
				cout<<"\nYou have to pay Rs."<<Recursive(p,r,t)<<" after "<<t<<" years"<<endl;
				break;
				
			case 3:
				cout<<"\nRate of interest for Car Loan amount are as follow: "<<"\n";
				cout<<"0 to 1,000 interest is 10 percent"<<"\n";
				cout<<"1,000 to 1,00,000 interest is 12 percent"<<"\n";
				cout<<"Above 1,00,000 interest is 14 percent"<<"\n\n";
				cout<<"Enter amount you want to take from bank: Rs.";
				cin>>p;
				cout<<"Enter time after which you will repay: ";
				cin>>t;
				
				if(p<1000)
				{
					r=10;
				}
				else if(p>1000 && p<100000)
				{
					r=12;
				}
				else
				{
					r=14;
				}
				
				cout<<"\nYou have to pay Rs."<<Recursive(p,r,t)<<" after "<<t<<" years"<<endl;
				break;
				
			default:
				cout<<"Something went wrong !!"<<endl;
		}
		
		cout<<"\nStill want to continue?? 1 to continue, 0 to discontinue: ";
		cin>>choice;
	}
}

float Recursive(float Balance, float ir, int time)
{
	if(time==0)
	{
		return Balance;
	}
	
	float interest = Balance*ir/100;
	
	return Recursive(Balance+interest, ir, time-1);
}

/* Output:

_____________________Welcome to MIT Bank_______________________
Our Bank gives THREE types of LOANS:
1) Educational Loan
2) Home Loan
3) Car Loan

Enter which loan you want: 1

Rate of interest for Educational Loan amount are as follow:
0 to 1,000 interest is 6 percent
1,000 to 1,00,000 interest is 8 percent
Above 1,00,000 interest is 10 percent

Enter amount you want to take from bank: Rs.100000
Enter time after which you will repay: 12

You have to pay Rs.313843 after 12 years

Still want to continue?? 1 to continue, 0 to discontinue: 0

*/
