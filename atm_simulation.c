#include <stdio.h>

int balance = 10000;   
int correctPin = 1234; 
char name[50];
int accNo;


void userdata();
void savedata();
int verifyPin();
void showmenu();
void checkbalance();
void deposit();
void withdraw();
void viewdetails();


//----Prateek:main(),showmenu(),savedata()-----
int main()
{
    int choice;

    userdata();

    
    if (!verifyPin())
    {
        printf("\nToo many wrong attempts. Your card is blocked.\n");
        return 0;
    }

    while (1)
    {
        showmenu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                checkbalance();
                break;
            case 2:
                deposit();
                savedata();
                break;
            case 3:
                withdraw();
                savedata();
                break;
            case 4:
                savedata();
                printf("Thank you for using the ATM. Goodbye!\n");
                return 0;
            case 5:
                viewdetails();
                break;
            default:
                printf("Invalid choice! Please select 1-5.\n");
        }
    }

    return 0;
}

//------Urvashi:userdata(),verify()--------
void userdata()
{
    FILE *fp;
    fp = fopen("data.txt", "r");

    if (fp != NULL)
    {
        fscanf(fp, "%s", name);
        fscanf(fp, "%d", &accNo);
        fscanf(fp, "%d", &correctPin);
        fscanf(fp, "%d", &balance);
        fclose(fp);
    }
    else
    {
        printf("Enter your first name: ");
        scanf("%s", name);
        printf("Enter account number: ");
        scanf("%d", &accNo);
        printf("Set a 4-digit PIN: ");
        scanf("%d", &correctPin);

        savedata();
    }
}

void savedata()
{
    FILE *fp;
    fp = fopen("data.txt", "w");

    if (fp != NULL)
    {
        fprintf(fp, "%s\n", name);
        fprintf(fp, "%d\n", accNo);
        fprintf(fp, "%d\n", correctPin);
        fprintf(fp, "%d\n", balance);
        fclose(fp);
    }
}


int verifyPin()
{
    int enteredPin;
    int attempts = 0;

    while (attempts < 3)
    {
        printf("\nEnter your 4-digit PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == correctPin)
        {
            printf("PIN verified successfully!\n");
            return 1;
        }
        else
        {
            attempts++;
            printf("Incorrect PIN! Attempts remaining: %d\n", 3 - attempts);
        }
    }
    return 0;
}

void showmenu()
{
    printf("\n--- ATM MENU ---\n");
    printf("1. Check Balance\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
    printf("5. View Account Details\n");
    printf("Enter choice: ");
}



//-----Chavi:checkbalance(),deposit(),withdraw(),viewdetails()
void checkbalance()
{
    printf("Your current balance is: %d\n", balance);
}

void deposit()
{
    int amount;
    printf("Enter amount to deposit: ");
    scanf("%d", &amount);

    if (amount > 0)
    {
        balance += amount;
        printf("Deposited %d successfully. New balance: %d\n", amount, balance);
    }
    else
    {
        printf("Invalid amount!\n");
    }
}

void withdraw()
{
    int amount;
    printf("Enter amount to withdraw: ");
    scanf("%d", &amount);

    if (amount <= 0)
    {
        printf("Invalid amount!\n");
    }
    else if (amount > balance)
    {
        printf("Insufficient balance! Available balance: %d\n", balance);
    }
    else
    {
        balance -= amount;
        printf("Please collect your cash: %d\n", amount);
        printf("Remaining balance: %d\n", balance);
    }
}

void viewdetails()
{
    printf("\n--- ACCOUNT DETAILS ---\n");
    printf("Name: %s\n", name);
    printf("Account No: %d\n", accNo);
    printf("Balance: %d\n", balance);
}