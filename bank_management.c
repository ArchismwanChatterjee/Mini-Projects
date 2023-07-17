
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

struct BankAccount
{
    int accountNumber;
    char accountHolder[50];
    float balance;
};

struct BankAccount bank[100];
int numAccounts = 0, choice;

void createAccount(struct BankAccount bank[], int *numAccounts)
{
    FILE *filePtr;
    filePtr = fopen("record.txt", "a");
    if (*numAccounts >= 100)
    {
        printf("Maximum number of accounts reached.\n");
    }
    struct BankAccount newAccount;
    printf("Enter Account Number :");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter Account Holder Name :");
    scanf("%s", newAccount.accountHolder);
    printf("Enter Initial Balance :");
    scanf("%f", &newAccount.balance);
    bank[*numAccounts] = newAccount;
    (*numAccounts)++;
    printf("Account created succesfully.");
    fprintf(filePtr, "Account Number:%d\nAccount Holder:%s\nAccount Balance:%.2f\n=============================================\n\n", newAccount.accountNumber, newAccount.accountHolder, newAccount.balance);
    fclose(filePtr);
}
void deposit(struct BankAccount bank[], int numAccounts)
{
    int accountNumber, i, c = 0;
    float amount;
    printf("Enter the Account Number :");
    scanf("%d", &accountNumber);
    for (i = 0; i < numAccounts; i++)
    {
        if (bank[i].accountNumber == accountNumber)
        {
            c++;
            printf("Enter Deposit Amount :");
            scanf("%f", &amount);
            bank[i].balance = bank[i].balance + amount;
            printf("Deposit successful. New balance : %.2f\n", bank[i].balance);
        }
    }
    if (c == 0)
    {
        printf("Account not found please try again with sufficient data\n");
    }
}

void withdraw(struct BankAccount bank[], int numAccounts)
{
    int accountNumber, i, c = 0;
    float amount;
    printf("Enter Account Number :");
    scanf("%d", &accountNumber);
    for (i = 0; i < numAccounts; i++)
    {
        if (bank[i].accountNumber == accountNumber)
        {
            c++;
            printf("Enter Withdrawal Amount :");
            scanf("%f", &amount);
            if (amount <= bank[i].balance)
            {
                bank[i].balance = bank[i].balance - amount;
                printf("Withdrawal successful. New balance : %.2f\n", bank[i].balance);
                return;
            }
            else
            {
                printf("Insufficient balance.\n");
            }
        }
    }
    if (c == 0)
    {
        printf("Account not found please try again with sufficient data\n");
    }
}

void displayAccount(struct BankAccount bank[], int numAccounts)
{
    int accountNumber, i;
    int c = 0;
    printf("Enter Account Number :");
    scanf("%d", &accountNumber);
    for (i = 0; i < numAccounts; i++)
    {
        if (bank[i].accountNumber == accountNumber)
        {
            c++;
            printf("Account Number : %d\n", bank[i].accountNumber);
            printf("Account Holder : %s\n", bank[i].accountHolder);
            printf("Balance : %.2f\n", bank[i].balance);
        }
    }
    if (c == 0)
        printf("Account not found please try again with sufficient data\n");
}
void displayALL(struct BankAccount bank[], int numAccounts)
{
    printf("\n");
    if (numAccounts > 0)
    {
        for (int i = 0; i < numAccounts; i++)
        {
            printf("Account Number : %d\n", bank[i].accountNumber);
            printf("Account Holder : %s\n", bank[i].accountHolder);
            printf("Balance : %.2f\n\n", bank[i].balance);
        }
    }
    else
    {
        printf("Sorry no account to display\n\n");
    }
}
int main()
{

    system("cls");
    gotoxy(50, 10);
    printf("Welcome to our Bank");
    Sleep(1000);
    system("cls");
    do
    {
        printf("Please continue with our services\n");
        printf("1. Create New Account\n");
        printf("2. Deposit Cash\n");
        printf("3. Withdraw Cash\n");
        printf("4. View Account\n");
        printf("5. View all the records\n");
        printf("0. Exit\n");
        printf("\nPlease choose our service:");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            createAccount(bank, &numAccounts);
            break;
        case 2:
            deposit(bank, numAccounts);
            break;
        case 3:
            withdraw(bank, numAccounts);
            break;
        case 4:
            displayAccount(bank, numAccounts);
            break;
        case 5:
            displayALL(bank, numAccounts);
            break;
        case 0:
            system("cls");
            gotoxy(40, 10);
            printf("Thank you for visiting Goodbye!!Have a great day ahead\n\n");
            exit(0);
            break;
        default:
            printf("Invalid Choice. Please try again.\n");
        }
        if (choice == 5)
            Sleep(10000);
        Sleep(5000);
        system("cls");
    } while (choice != 0);
    return 0;
}
