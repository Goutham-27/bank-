include <stdio.h>

struct customer
{
    int account_no;
    char name[80];
    int balance;
};

void accept(struct customer[], int);
void display(struct customer[], int);
int search(struct customer[], int, int);
void deposit(struct customer[], int, int, int);
void withdraw(struct customer[], int, int, int);

int main()
{
    struct customer data[20];
    int n, choice, account_no, amount, index;

    printf("Banking System\n\n");
    printf("Number of customer records you want to enter? : ");
    scanf("%d", &n);
    accept(data, n);
    do
    {

        printf("\nBanking System Menu :\n");
        printf("Press 1 to display all records.\n");
        printf("Press 2 to search a record.\n");
        printf("Press 3 to deposit amount.\n");
        printf("Press 4 to withdraw amount.\n");
        printf("Press 0 to exit\n");
        printf("\nEnter choice(0-4) : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                display(data, n);
                break;
            case 2:
                printf("Enter account number to search : ");
                scanf("%d", &account_no);
                index = search(data, n, account_no);
                if (index ==  - 1)
                {
                    printf("Record not found : ");
                }
                else
                {
                    printf("A/c Number: %d\nName: %s\nBalance: %d\n",
                        data[index].account_no, data[index].name,
                        data[index].balance);
                }
                break;
            case 3:
                printf("Enter account number : ");
                scanf("%d", &account_no);
                printf("Enter amount to deposit : ");
                scanf("%d", &amount);
                deposit(data, n, account_no, amount);
                break;
            case 4:
                printf("Enter account number : ");
                scanf("%d", &account_no);
                printf("Enter amount to withdraw : ");
                scanf("%d", &amount);
                withdraw(data, n, account_no, amount);
        }
    }
    while (choice != 0);

    return 0;
}

void accept(struct customer list[80], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        printf("\nEnter data for Record #%d", i + 1);

        printf("\nEnter account_no : ");
        scanf("%d", &list[i].account_no);
        fflush(stdin);
        printf("Enter name : ");
        gets(list[i].name);
        list[i].balance = 0;
    } 
}

void display(struct customer list[80], int s)
{
    int i;

    printf("\n\nA/c No\tName\tBalance\n");
    for (i = 0; i < s; i++)
    {
        printf("%d\t%s\t%d\n", list[i].account_no, list[i].name,
            list[i].balance);
    } 
}

int search(struct customer list[80], int s, int number)
{
    int i;

    for (i = 0; i < s; i++)
    {
        if (list[i].account_no == number)
        {
            return i;
        } 
    }
    return  - 1;
}

void deposit(struct customer list[], int s, int number, int amt)
{
    int i = search(list, s, number);
    if (i ==  - 1)
    {
        printf("Record not found");
    } 
    else
    {
        list[i].balance += amt;
    }
}

void withdraw(struct customer list[], int s, int number, int amt)
{
    int i = search(list, s, number);
    if (i ==  - 1)
    {
        printf("Record not found\n");
    } 
    else if (list[i].balance < amt)
    {
        printf("Insufficient balance\n");
    }
    else
    {
        list[i].balance -= amt;
    }
}
Output:
Banking System

Number of customer records you want to enter? : 3

Enter data for Record #1
Enter account_no : 100
Enter name : Alex

Enter data for Record #2
Enter account_no : 101
Enter name : Monica

Enter data for Record #3
Enter account_no : 103
Enter name : Javed

Banking System Menu :
Press 1 to display all records.
Press 2 to search a record.
Press 3 to deposit amount.
Press 4 to withdraw amount.
Press 0 to exit

Enter choice(0-4) : 1


A/c No Name   Balance
100      Alex       0
101      Monica  0
103      Javed    0

Banking System Menu :
Press 1 to display all records.
Press 2 to search a record.
Press 3 to deposit amount.
Press 4 to withdraw amount.
Press 0 to exit

Enter choice(0-4) : 3
Enter account number : 101
Enter amount to deposit : 500

Banking System Menu :
Press 1 to display all records.
Press 2 to search a record.
Press 3 to deposit amount.
Press 4 to withdraw amount.
Press 0 to exit

Enter choice(0-4) : 2
Enter account number to search : 101
A/c Number: 101
Name: Monica
Balance: 500

Banking System Menu :
Press 1 to display all records.
Press 2 to search a record.
Press 3 to deposit amount.
Press 4 to withdraw amount.
Press 0 to exit

Enter choice(0-4) : 4
Enter account number : 101
Enter amount to withdraw : 150

Banking System Menu :
Press 1 to display all records.
Press 2 to search a record.
Press 3 to deposit amount.
Press 4 to withdraw amount.
Press 0 to exit

Enter choice(0-4) : 1


A/c No Name   Balance
100      Alex      0
101      Monica  350
103      Javed    0

Banking System Menu :
Press 1 to display all records.
Press 2 to search a record.
Press 3 to deposit amount.
Press 4 to withdraw amount.
Press 0 to exit

Enter choice(0-4) : 0
