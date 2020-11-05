#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;

//rules of this game
int rules()
{
    cout<<"-----------------------------------------------------"<<endl<<endl;
    cout<<"1 -> choose number between 1 to 10 : "<<endl;
    cout<<"2 -> if you win this game , you will get 10 time of money you bet "<<endl;
    cout<<"3 -> if you lose game ,you will lose your beting money"<<endl;
    cout<<"-----------------------------------------------------"<<endl<<endl;

}
int main()
{
    char player_name[10],choise;
    int amount,betting_amount,dice_number,guess_number;
    
    while(1)    
    {
        cout<<"-----------------------------------------------------"<<endl<<endl;
        cout<<"             casino number guessing game             "<<endl<<endl;
        cout<<"-----------------------------------------------------"<<endl<<endl;

        cout<<"enter player name  ->  ";
        cin>>player_name;
        cout<<"-----------------------------------------------------"<<endl<<endl;

// label
back:
        cout<<"enter amount  ->  ";
        cin>>amount;

        //calling function
        rules();

        while(amount>0)
        {
            cout<<"enter betting amount  ->  ";
            cin>>betting_amount;

            if(betting_amount>amount)
            {
                cout<<"your betting amount is more than amount"<<endl<<endl;
                cout<<"again enter betting amount  ->  ";
                cin>>betting_amount;
                
            }
            
            cout<<"enter guessing number  ->  ";
            cin>>guess_number;

            if(guess_number<0 || guess_number>10)
            {
                cout<<"number not valid..,enter again..."<<endl<<endl;
                cout<<"again enter guessing number  ->  ";
                cin>>guess_number;
            }
            
            // generate randon number
            dice_number=rand()%10+1;

            if(dice_number==guess_number)
            {
                cout<<"---------------------------------------------"<<endl<<endl;
                cout<<"dice number  ->  "<<dice_number<<endl;
                cout<< "congrats...you are win"<<endl;
                amount=amount+betting_amount*10;
                cout<<"your amount: "<<amount<<endl<<endl;
                cout<<"---------------------------------------------"<<endl<<endl;
            }
            else
            {
                cout<<"---------------------------------------------"<<endl<<endl;
                cout<<"dice number ->  "<<dice_number<<endl;
                cout<< "sorry...you are lose"<<endl;
                amount=amount-betting_amount;
                cout<<"your amount: "<<amount<<endl<<endl;
                cout<<"---------------------------------------------"<<endl<<endl;

                if(amount==0)
                {
                    cout<<player_name<<" you are lose all money"<<endl<<endl;
                    
                    cout<<"do you want to play this game again ? enter your choise Y / N  ->  ";
                    cin>>choise;
                
                    if(choise== 'y' || choise== 'Y')
                    {
                        return main();
                    }
                    else 
                    {
                    
                        return 0;
                    }
                
    
                }

            }
            
        }
        if(amount<0)
        {
            cout<<"enter positive amount : "<<endl;
            goto back;
        }
    }

return 0;

}