//  Project		:		Bank Management System
//	Author		:		Muhammad Hammad
//	Language	:		C++
//	Description:
//			A console based Bank management system. User can open account in bank by using their ID 
//			card number, can deposit deposite and withdraw amount, can check their balance.

#include<iostream>
#include<cstdlib>
#include<string>
#include<ctime>
using namespace std;

// ---------- Global Data (shared across all functions) ----------
const int max_acc=50;        // Maximum number of accounts the system can store
string names[max_acc];       // Array to store account holder names
int acc_numbers[max_acc];    // Array to store account numbers
int balance[max_acc];        // Array to store balance for each account
int numbers=0;                // Counter: total number of accounts created so far
int account_no;              // Temporary variable used to hold entered account number

// ---------- Function Declarations ----------
void create_acc();
void amount_depo();
void amount_withdraw();
void check_balance();

int main()
{
	int choice;
	bool run=true;
	
	// Main menu loop - keeps running until user selects Exit
	while (run)
		{
            cout<<"======== Menu ========"<<endl;
	cout<<"1. Create Account "<<endl<<"2. Deposit amount "<< endl<<"3. Withdraw amount"<<endl<<"4. Check Balance "<<endl<<"5. Exit"<<endl;
	cout<<"Enter your choice: ";
			cin>>choice;
			cin.ignore(); // Clear leftover newline so getline() works correctly next
			switch(choice)
				{
					case 1:
						create_acc();      // Open a new account
						break;
					case 2:
						amount_depo();     // Add money to an existing account
						break;
					case 3:
						amount_withdraw(); // Remove money from an existing account
						break;
					case 4:
						check_balance();   // Display balance of an account
						break;
					case 5:
						cout<<"Exiting"<<endl;
						run=false;         // Stop the while loop
						break;
					default:
						{
							cout<<"Invalid Choice: "<<endl;
						}
						
				}
		}
	return 0;	
}

// ---------- Create a new bank account ----------
void create_acc()
	{
		string name;
		int age;
		string ID_no;
		cout<<"Please Enter Your Number: ";
		getline(cin,name);              // Read full name (allows spaces)
		cout<<"Enter Your Age: ";
		cin>>age;
        cin.ignore();                    // Clear newline left by cin>>age

		// Age check - account holder must be 18 or older
		if (age<18)
			{
				cout<<"Sorry, Your Account Cannot be Opned. You are under 18."<<endl;
				return ;
			}

		// ID number must be exactly 13 digits
		cout<<"Enter your 13-digits ID Number: ";
        getline(cin, ID_no);
        while (ID_no.length()<13 || ID_no.length()>13)
        	{
        		cout<<"Invalid length of ID number. Please enter valid ID number"<<endl;
        		return;
			}

		// Show confirmation details
		cout<<"======== Congratulation Your Account is Opened: ========"<<endl;
		cout<<"Account Holder: "<<name<<endl;
		cout<<"Age: "<<age<<endl;
		cout<<"ID Number: "<<ID_no<<endl;

		// Generate a random account number between 1 and 100
		srand(time(0));
		account_no= rand()%100+1;
		cout<<"Your Account Number:  "<<account_no<<endl;

		// Store the new account details in the arrays
		names[numbers]= name;
		acc_numbers[numbers]= account_no;
		numbers++;   // Increase total account count
	}

// ---------- Deposit money into an existing account ----------
void amount_depo()
{
    float deposit;
    int index_found= -1;     // Will store the array index of the matched account
    cout<<"Enter Your Account Number: ";
    cin>>account_no;

    // Search for the account number in the array
    for(int i=0; i<numbers; i++)
        {
            int check=0;
            if(account_no==acc_numbers[i])
                {
                    cout<<"Enter Your Deposit Amount: ";
                    cin>>deposit;
                    index_found=i;   // Account found - remember its index
                    
                }
        } 

    // If account was found, add the deposit to its balance
    if(index_found != -1)  
        {
            balance[index_found]+=deposit;
            cout<<"Deposit Successfull"<<endl;
            cout<<"Your Balance is "<<balance[index_found];
        }
    else
        {
            cout<<"Account not found. Enter Valid Account number"<<endl;
        }   
 } 
 
 // ---------- Withdraw money from an existing account ----------
 void amount_withdraw()
 {
     float with_amount;
     int index_found= -1;     // Will store the array index of the matched account
     
     cout<<"Enter Your Account Number= ";
     cin>>account_no;

     // Search for the account number in the array
     for(int j=0; j<numbers; j++)
         {
             if(account_no==acc_numbers[j])
                 {
                     cout<<"Your Account Balance is "<<balance[j];
                     cout<<"Enter your amount: ";
                     cin>>with_amount;

                         // Keep asking until withdrawal amount is valid (not more than balance)
                         while(with_amount>balance[j])
                             {
                                 cout<<"Enter Valid Amount";
                                 cin>>with_amount;
                             
                             }
                      index_found=j;       
                     
                 }
         
         }

     // If account was found, subtract the withdrawal from its balance
     if(index_found != -1)
         {
             balance[index_found]-= with_amount;
             cout<<"Withdraw Successfull"<<endl;
             cout<<"Your Balance is "<<balance[index_found]<<endl;
         }  
     else 
         {cout<<"Enter Valid Account number: "<<endl;} 
 }
 
 // ---------- Check balance of an existing account ----------
 void check_balance()
 {
     int index_found= -1;     // Will store the array index of the matched account
     cout<<"Enter Your account number: ";
     cin>>account_no;

     // Search for the account number in the array
     for(int k=0; k<numbers; k++)
         {
             if(account_no==acc_numbers[k])
                 {
                    index_found=k; 
                 }
         
         }

     // If found, display the balance; otherwise show an error
     if(index_found !=-1)
         {
             cout<<"Your Account Balance is "<<balance[index_found];
         }
      else
      cout<<"Account not found"   <<endl;
         
 }
