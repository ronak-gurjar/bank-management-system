#include<iostream>
#include<string.h>
using namespace std;
/* 
    if we are not using static keyword its value 
    end after any local function is return 

    thats why we are using static because static keyword value 
    "finish" when main function end 
*/
int static num_acc;

class bank{
    
    public:
        char account_number[10],acc_number[10];
        char bank_name[10];
        char acc_holder_name[20];
        char acc_holder_address[50];

        //default balance
        int available_balance=1000;
        int withdraw_amount,deposite_amount;

        //member function
        int create_account();
        int cash_deposite();
        int cash_withdraw();
        int show_detail();
        int display();
        int check_balance();

//for 10 accounts
}account[10];

//for create acount
int bank::create_account()
{
    cout<<"enter bank name              -> ";
    cin>>account[num_acc].bank_name;

    cout<<"enter account holder name    -> ";
    cin>>account[num_acc].acc_holder_name;

    cout<<"enter account number         -> ";
    cin>>account[num_acc].account_number;

    cout<<"enter account holder address -> ";
    cin>>account[num_acc].acc_holder_address;
    
    //increment account
    num_acc++;

}

// for cash deposite
int bank ::cash_deposite()
{
    int i;
    cout<<"enter your account number : ";

//add label
top:
   
    cin>>acc_number;

    for( i=0;i<=num_acc;i++)
    {
        //comparing account number
        if(strcmp(account[i].account_number,acc_number)==0)
        
            break;
        
    }
  
    while(i<=num_acc)
    {
        cout<<"enter amount for deposite : ";
        cin>>account[i].deposite_amount;

        //money credit in your account
        account[i].available_balance+=account[i].deposite_amount;

        cout<<"now your available balance is : "<<account[i].available_balance<<endl;
        break;
            
    }

    if(i>num_acc)
    {
        cout<<"again enter acc no :";
        goto top;
        
    }
 
}

//cash withdraw
int bank::cash_withdraw()
{
    int k;
    cout<<"enter account number : ";

//add label    
top1:
    cin>>acc_number;
    
    for( k=0;k<=num_acc;k++)
    {
        //comparing account number
        if(strcmp(account[k].account_number,acc_number)==0)
    
            break;
        
    }

    while(k<=num_acc)
    {
        cout<<"enter amount for withdraw : ";
        cin>>account[k].withdraw_amount;

        if(account[k].withdraw_amount>account[k].available_balance)
        {
            cout<<"again enter withdraw amount....bcoz your withdraw amount is bigger than actual balance"<<endl;
            cin>>account[k].withdraw_amount;
        }
        // money deducted in your account
        account[k].available_balance-=account[k].withdraw_amount;

        cout<<"now your available balance is : "<<account[k].available_balance<<endl;
        break;
        
    }
    if(k>num_acc)
    {
        cout<<"again enter acc no :";
        goto top1;
        
    }
    
}

//show menu
int bank::display()
{
    cout<<"-------------------------------"<<endl<<endl;
    cout<< " 1 -> create account"<<endl;
    cout<< " 2 -> cash_deposite"<<endl;
    cout<< " 3 -> cash_withdraw"<<endl;
    cout<< " 4 -> show detail"<<endl;
    cout<< " 5 -> check balance"<<endl;
    cout<< " 6 -> logout"<<endl<<endl;
    cout<<"-------------------------------"<<endl<<endl;
}

//show detail
int bank::show_detail()
{
    for(int j=0;j<num_acc;j++)
    {
        cout<<"index number          ->  "<<j+1<<endl<<endl;
        cout<<"bank name             ->  "<<account[j].bank_name<<endl;
        cout<<"acc holder name       ->  "<<account[j].acc_holder_name<<endl;
        cout<<"acc holder acc numbeer->  "<<account[j].account_number<<endl;
        cout<<"acc holder address    ->  "<<account[j].acc_holder_address<<endl;
        cout<<"available balance     ->  "<<account[j].available_balance<<endl<<endl;

    }
   
}

//check balance
int bank::check_balance()
{
    int f;
    cout<<"enter your account number : ";

//add label
back:
    cin>>acc_number;
    for(f=0;f<num_acc;f++)
    {
        if(strcmp(account[f].account_number,acc_number)==0)
        {
        break;
        }
         else
        {
            cout<<"again enter acc no : ";
            goto back;
        }
    
    }
    cout<<"-------------------------------"<<endl<<endl;
    cout<<account[f].acc_holder_name<<", your available balance is "<<account[f].available_balance<<endl;

}

//driver code
int main()
{
    system("cls");
    char choise;

    cout<<"-------------------------------"<<endl<<endl;
    cout<<"     banking application     "<<endl<<endl;
    

    while(1)
    {
        // we use arrow becoz it is calss function
        account->display();

        cout<<"enter choise : ";
        cin>>choise;
        cout<<"-------------------------------"<<endl<<endl;

        switch(choise)
        {
            case '1': account[num_acc].create_account();
                    break;

            case '2': account[num_acc].cash_deposite();
                    break;

            case '3': account[num_acc].cash_withdraw();
                    break;

            case '4': account[num_acc].show_detail();
                    break;

            case '5': account[num_acc].check_balance();
                    break;

            case '6':
                exit(0);

            default: cout<<"wrong...enter correct choise : ";
                break;
            
        }
    }
   
    return 0;
}

      

    

