#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define RESET 0
#define COLS 60
#define ROWS 30

FILE *file;

// Функції Дениса
void balance_output(int);
void balance_stored(int, char *);
void profile_password(int, char *);
void sol(int, char *, int);
void profile_username(char *, int);
void transactions();
void titleScreen();
int mainMenu();

int main()
{
    int c = 0;
    int balance = 0;
    int passcode = 0;
    int deposit_amount = 0;
    int withdraw_amount = 0;
    int command_number = 0;
    char data_string[256];

    file = fopen("balance.txt", "r");
    while (fgets(data_string, 225, file) != NULL)
    {
        puts(data_string);

        for (int i = 0; data_string[i] != '\0'; i++)
        {
            balance = balance * 10 + (data_string[i] - 48);
        }
    }

    fclose(file);

    titleScreen();
    profile_username(data_string, passcode);

    if (getchar() == '\n')
    {
        while (1)
        {
            system("cls");

            printf("#\n");

            file = fopen("username.txt", "r");
            while (fgets(data_string, 225, file) != NULL)
            {
                printf("#\t  Profile name: %s\n", data_string);
            }
            fclose(file);

            printf("#\t  Balance: %d \n", balance);
            printf("#\t  Expenses for today: -%d\n", withdraw_amount);
            printf("#\t  Incomes for today: +%d\n", deposit_amount);
            printf("#\n#\n#\n");
            printf("#\t1 - Add transaction \n#\t2 - Open general statistic \n#\n#\n#\t0 - Exit\n");
            printf("Enter the number to choose: ");

            char choice = getchar();
            while (getchar() != '\n')
                ;

            if (choice == '1')
            {
                system("cls");

                system("cls");
                printf("#\t 1 - Add to the balance \n#\t 2 - Subtract from the balance \n");
                printf("#\n#\n#\t Answer: ");
                scanf("%d", &command_number);

                if (command_number == 1)
                {
                    c = 1;
                    printf("Enter deposit amount: ");
                    scanf("%d", &deposit_amount);
                    sol(deposit_amount, data_string, c);
                    balance = deposit_amount + balance;
                    balance_stored(balance, data_string);
                    balance_output(balance);
                }
                else if (command_number == 2)
                {
                    c = 2;
                    printf("Enter withdraw amount: ");
                    scanf("%d", &withdraw_amount);
                    sol(withdraw_amount, data_string, c);
                    if (withdraw_amount > balance)
                    {
                        printf("No enough funds to withdraw\n");
                    }
                    else
                    {
                        balance = balance - withdraw_amount;
                        balance_stored(balance, data_string);
                        balance_output(balance);
                    }
                }
            }
            else if (choice == '2')
            {
                system("cls");
                file = fopen("statistics.txt", "r");
                while (fgets(data_string, 225, file) != NULL)
                {
                    printf("%s", data_string);
                }
                fclose(file);
                printf("Press enter to continue...\n");
                if (getchar() == '\n')
                {
                    continue;
                }
            }
            else if (choice == '0')
            {
                system("cls");
                printf("See you next time! ^_^\n");
                sleep(2);
                exit(0);
            }

            if (getchar() == '0')
            {
                break;
            }
        }
    }
    return 0;
}

void balance_output(int balance)
{
    printf("Balance: %d\n", balance);
}

void balance_stored(int balance, char *data_string)
{
    file = fopen("balance.txt", "w");
    sprintf(data_string, "%d", balance);
    fputs(data_string, file);
    fclose(file);
}

void profile_password(int password, char *data_string)
{
    file = fopen("pin.txt", "a");
    sprintf(data_string, "%d", password);
    fputs(data_string, file);
    fclose(file);
}

void sol(int transaction, char *data_string, int c)
{

    if (transaction != 0)
    {
        if (c == 1)
        {
            file = fopen("statistics.txt", "a");
            sprintf(data_string, "%d", transaction);
            fputc('+', file);
            fputs(data_string, file);
            fputc('\n', file);
            fclose(file);
        }
        else if (c == 2)
        {
            file = fopen("statistics.txt", "a");
            sprintf(data_string, "%d", transaction);
            fputc('-', file);
            fputs(data_string, file);
            fputc('\n', file);
            fclose(file);
        }
    }
}

void profile_username(char *data_string, int passcode)
{
    int passcode_in_file = 0;
    int a = 0;

    if ((file = fopen("username.txt", "r")) == NULL)
    {
        printf("You need to create profile\n");
        printf("Enter your username: ");
        file = fopen("username.txt", "a");
        scanf("%s", data_string);
        fputs(data_string, file);
        fclose(file);
        printf("Create your passcode: ");
        file = fopen("passcode.txt", "a");
        scanf("%s", data_string);
        fputs(data_string, file);
        fclose(file);
    }

    file = fopen("passcode.txt", "r");
    while (fgets(data_string, 225, file) != NULL)
    {
        for (int i = 0; data_string[i] != '\0'; i++)
        {
            passcode_in_file = passcode_in_file * 10 + (data_string[i] - 48);
        }
    }
    fclose(file);

    while (a != 1)
    {
        printf("Enter your passcode to log in: ");
        scanf("%d", &passcode);

        if (passcode == passcode_in_file)
        {
            printf("Approved!\n");
            a = 1;
        }
        else
        {
            printf("Failed!\n");
        }
    }
}

void titleScreen()
{
    printf("#");
    for (int i = 0; i < COLS; i++)
    {
        printf("#");
    }
    printf("#\n");

    for (int j = 0; j < 3; j++)
    {
        printf("#\t\t\t\t\t\t\t     #\n");
    }

    printf("#\t\t\t    WELCOME\t\t\t     #\n");
    printf("#\t\t\t\t\t\t\t     #\n");

    printf("#\t \t  \t      TO\t\t\t     #\n");

    printf("#\t\t\t\t\t\t\t     #\n");
    printf("#\t\t      Your Finance System    \t\t     #\n");

    printf("#\t\t\t\t\t\t\t     #\n");
    printf("#\t\t\t\t\t\t\t     #\n");

    for (int i = 0; i < 2; i++)
    {
        printf("#\t\t\t\t\t\t\t     #\n");
    }
    printf("#\t\tPlease press Enter to continue... \t     #\n");

    for (int j = 0; j < 2; j++)
    {
        printf("#\t\t\t\t\t\t\t     #\n");
    }

    printf("#");
    for (int i = 0; i < COLS; i++)
    {
        printf("#");
    }
    printf("#\n");
}
