#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include<time.h>
#include <conio.h>

int base_amt=10000,total_amt,account_no,choice;
char cust_name[60],branch[50];

void t_money();
void d_money();
void w_money();
void balance();
void acc_details();
void tra_history();
void menu();
void divider()
{
    for (int i = 0; i < 10; i++)
    {
        printf("*");
    }
}



int main() 
{
    int  service_no;

    FILE *ptr = fopen("Account.txt", "w");
    printf("Enter Your Name: ");
    fgets(cust_name,60,stdin);
    fprintf(ptr, "The customer name is %s\n", cust_name);

    printf("Enter Branch:\n");
    scanf("%s",&branch);

    printf("enter account number:\n");
    scanf("%d",&account_no);
    fprintf(ptr, "The account number is %d\n", account_no);
    
    
 while (1)

{
    menu();

     printf("choose service no:");
     scanf("%d",&service_no);

    switch (service_no)
    {
    case 1:
        system("cls");
         t_money();

        break;

    case 2:
       system("cls");
         d_money();
         break;

    case 3:
    system("cls");
        w_money();
        break;


    case 4:
    system("cls");
         balance();
        break;

    case 5:
        system("cls");
        acc_details();
        break;


    case 6:
        system("cls");
        tra_history();
        break;
    
    default:
    printf("Invalid Choice\n");
        break;
    }

 }

       return 0;
}


void  menu()
    {
        printf("Hello %s \n",cust_name);

        printf("1.Transfer Money \n");
        printf("2.Deposit Money \n");
        printf("3.withdraw Money  \n");
        printf("4. Check Bank Balance  \n");
        printf("5.Account Details  \n"); 
        printf("6.Transaction History  \n");
        
        
    }


void t_money()

{
    time_t tm;
    time(&tm);
    int cust2_name,amt;

   FILE *ptr= fopen("Account.txt","a");

    printf("Transfer Money To (Account No) \n:");
    scanf("%d",&cust2_name);
    printf("Ammount\n:");
    scanf("%d",&amt);
    if (amt<base_amt)
    {
    printf("Transfered Successfully");
    fprintf(ptr,"Rs.%d has been transfered to %d\n",amt,cust2_name);
    fprintf(ptr,"the time of transaction is %s",ctime(&tm));
    
    fclose(ptr);
    
    printf("Press any Key to exit \n");
    getch();

     }
     else{
        printf("Not Enough Balance\t");
     }
    
   

}


void d_money()
{
    system("cls");
    time_t tm;
    time(&tm);
    int deposit,total_amt;
    FILE *ptr=fopen("Account.txt","a");

    printf("enter the amount to be deposited \n:");
    scanf("%d",&deposit);
    fprintf(ptr,"%d has been deposited to your account.\n", deposit);
    fprintf(ptr,"The time of Deposit is %s", ctime(&tm));
    printf("Deposited Successfully");
    printf("Your total balance now");
    total_amt=base_amt+deposit;
    printf("%d",total_amt);

    fclose(ptr);
    


printf("press any key To exit\n");
getch();

   

}

void w_money()

{   time_t tm;
    time(&tm);
    int withdraw,total_amt;
    FILE *ptr=fopen("Account.txt","a");

    printf("enter the amount to be Withdraw \n:");
    scanf("%d",&withdraw);

    if(withdraw<base_amt)
    {
     printf("Withdrawl Successfully");
    printf("Your total balance now");
    total_amt=base_amt-withdraw;
    printf("%d",total_amt);
    fprintf(ptr, "\nRs%d had been withdrawn from your account \n", withdraw);
    fprintf(ptr, "Date/Time of transaction :  %s\n", ctime(&tm));
    }


    else
    {
        printf("Not enough Balance\n");
    }

    fclose(ptr);
    printf("press any key.");

    getch();

    
}

void  balance()
{
    printf("your total Bank BAlance is %d",total_amt);
    printf("press any key to exit.");
    getch();
}

void acc_details()
{
    printf("Your name is %s \n",cust_name);
    
    printf("Your branch is %s\n",branch);

    printf("Your acount number:%d",account_no);

    printf("press any key to exit.");
    getch();

}

void  tra_history()
{
    time_t tm;
    time(&tm);
    char fname[20];
    FILE *ptr;

    printf("enter file name(i.e Account.txt):\n");
    scanf("%s",fname);
    ptr=fopen(fname,"r");
    fclose(ptr);
    printf("press any key to exit.");
    getch();
   
}