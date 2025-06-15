#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

char currencies[35][30] = {
    "US Dollar", "Euro", "British Pound", "Japanese Yen",
    "Canadian Dollar", "Australian Dollar", "Swiss Franc", "Chinese Yuan",
    "Indian Rupee", "Pakistani Rupee", "Russian Ruble", "Brazilian Real",
    "South African Rand", "Mexican Peso", "New Zealand Dollar", "Singapore Dollar",
    "Swedish Krona", "Norwegian Krone", "Danish Krone", "Thai Baht",
    "Hong Kong Dollar", "Malaysian Ringgit", "Philippine Peso", "Indonesian Rupiah",
    "South Korean Won", "Turkish Lira", "Egyptian Pound", "Vietnamese Dong",
    "UAE Dirham", "Saudi Riyal"};

char codes[30][4] = {
    "USD", "EUR", "GBP", "JPY",
    "CAD", "AUD", "CHF", "CNY",
    "INR", "PKR", "RUB", "BRL",
    "ZAR", "MXN", "NZD", "SGD",
    "SEK", "NOK", "DKK", "THB",
    "HKD", "MYR", "PHP", "IDR",
    "KRW", "TRY", "EGP", "VND",
    "AED", "SAR"};

float rates[30] = {
    1.00, 0.92, 0.78, 156.20,
    1.37, 1.51, 0.89, 7.24,
    83.12, 278.50, 92.73, 5.10,
    18.17, 16.96, 1.63, 1.36,
    10.75, 10.62, 6.85, 36.50,
    7.83, 4.69, 58.32, 15983.00,
    1375.00, 32.50, 47.95, 25000.00,
    3.67, 3.75};

void currencymenu()
{
    int i;
    printf("\nSelect your Curreny:\n");
    for (i = 0; i < 30; i++)
    {
        printf("%d. %s(%s) \t\t %d. %s(%s)\n", i + 1, currencies[i], codes[i], i + 2, currencies[i + 1], codes[i + 1]);
        i++;
    }
}

void medium_quiz()
{
    int answer1, useranswer, count = 0;
    srand(time(NULL));
    printf("\nThere will be 7 MCQS\n");
    for (int i = 1; i <= 7; i++)
    {
        int random = (rand() % 500) + 1;
        int r1 = rand() % 15;
        int r2 = rand() % 15;
        printf("%d. %d %s in %s(Hint:ExRate=%.2f , %.2f) = ", i, random, currencies[r1], currencies[r2], rates[r1], rates[r2]);
        answer1 = (random / rates[r1] * rates[r2]);

        while (scanf("%d", &useranswer) != 1)
        {
            printf("Invalid input. Please enter a number: ");
            while (getchar() != '\n');
        }

        printf("\nActual answer is %d\n", answer1);
        if (useranswer == answer1)
        {
            printf("BINGO\n\n");
            count++;
        }
        else if (abs(useranswer - answer1) < 10)
        {
            printf("---- Very Close!! CORRECT ANSWER\n\n ");
            count++;
        }
        else
            printf("Wrong Answer , Let's move on Next\n\n");
    }
    printf("Your Quiz is Over! Thanks!!\nYour Score is %d/7\n", count);
}

void easyquiz()
{
    int answer1, useranswer, count = 0;
    srand(time(NULL));
    printf("\nThere will be 5 MCQS\n");
    for (int i = 1; i <= 5; i++)
    {
        int random = (rand() % 100) + 1;
        int r1 = rand() % 10;
        int r2 = rand() % 10;
        printf("%d. %d %s in %s(Hint:ExRate=%.2f , %.2f) = ", i, random, currencies[r1], currencies[r2], rates[r1], rates[r2]);
        answer1 = (random / rates[r1] * rates[r2]);

        while (scanf("%d", &useranswer) != 1)
        {
            printf("Invalid input. Please enter a number: ");
            while (getchar() != '\n');
        }

        printf("\nActual answer is %d\n", answer1);
        if (useranswer == answer1)
        {
            printf("BINGO\n\n");
            count++;
        }
        else if (abs(useranswer - answer1) < 10)
        {
            printf("---- Very Close!! CORRECT ANSWER\n\n ");
            count++;
        }
        else
            printf("Wrong Answer , Let's move on Next\n\n");
    }
    printf("Your Quiz is Over! Thanks!!\nYour Score is %d/5\n", count);
}

void quiz(int answer)
{
    int ch, useranswer, count = 0;
    char plont;
    printf("              ----WELCOME TO THE QUIZ------\n");
    printf("Description:\n Dont Panic! this quiz require great math capability as well as strong sense of endurance, the one with powerful brain,stamina and capability will stand out, Less than 5 marks means you are a failue, and their will always be an asian kid whose gonna smack you in Maths, So prove what you got!!\n");
    printf("Are you sure you wanna play (y/n): ");
    scanf(" %c", &plont);
    if (plont == 'n' || plont == 'N')
    {
        printf("\nHuh!! I knew you don't have Guts! Go play with Dolls!!!\n");
        return;
    }

    printf("What Level of Difficulty can you Handle!\n1. EASY (kiddo)\n2. MEDIUM (Guts)\n3. HARD (hats off sir)\nEnter: ");
    while (scanf("%d", &ch) != 1 || ch < 1 || ch > 3)
    {
        printf("Invalid input. Enter 1, 2 or 3: ");
        while (getchar() != '\n');
    }

    if (ch == 1)
        easyquiz();
    else if (ch == 2)
        medium_quiz();
    else if (ch == 3)
    {
        srand(time(NULL));
        printf("\nThere will be 10 MCQS\n");
        for (int i = 1; i <= 10; i++)
        {
            int random = (rand() % 1000) + 1;
            int r1 = rand() % 30;
            int r2 = rand() % 30;
            printf("%d. %d %s in %s(Hint:ExRate=%.2f , %.2f) = ", i, random, currencies[r1], currencies[r2], rates[r1], rates[r2]);
            answer = (random / rates[r1] * rates[r2]);

            while (scanf("%d", &useranswer) != 1)
            {
                printf("Invalid input. Please enter a number: ");
                while (getchar() != '\n');
            }

            printf("\nActual answer is %d\n", answer);
            if (useranswer == answer)
            {
                printf("BINGO\n\n");
                count++;
            }
            else if (abs(useranswer - answer) < 10)
            {
                printf("---- Very Close!! CORRECT ANSWER\n\n ");
                count++;
            }
            else
                printf("Wrong Answer , Let's move on Next\n\n");
        }
        printf("Your Quiz is Over! Thanks!!\nYour Score is %d/10\n", count);
    }
}

void show_exchange_rates()
{
    for (int i = 0; i < 30; i++)
    {
        printf("%d. %s = %.2f \t  %d. %s = %.2f\n", i + 1, currencies[i], rates[i], i + 2, currencies[i + 1], rates[i + 1]);
        i++;
    }
}
void guess_exchange_rate_game()
{
    srand(time(NULL));
    int from = rand() % 30;
    int to = rand() % 30;
    while (to == from)
        to = rand() % 30;

    float actual_rate = rates[to] / rates[from];
    float guess;
    int attempts = 3;

    printf("\n             ============================\n");
    printf("                   GUESS THE RATE GAME\n");
    printf("               ============================\n");
    printf("Guess the exchange rate from %s (%s) to %s (%s)\n", 
           currencies[from], codes[from], currencies[to], codes[to]);
    printf("You have %d attempts!\n", attempts);

    while (attempts--)
    {
        printf("Enter your guess (e.g., 1.25): ");
        if (scanf("%f", &guess) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Try again.\n");
            attempts++;
            continue;
        }

        if (guess > actual_rate - 0.1 && guess < actual_rate + 0.1)
        {
            printf(" Correct! The actual rate is approximately %.2f\n", actual_rate);
            return;
        }
        else if (guess > actual_rate)
            printf("Too high!\n");
        else
            printf("Too low!\n");

        if (attempts > 0)
            printf("Try again! Attempts left: %d\n", attempts);
        else
            printf(" Game over! The correct answer was %.2f\n", actual_rate);
    }
}

int main()
{
    int choice, from, to, answer;
    float amount;
    char another;

    printf("  ____                            _                      \n");
    printf(" / ___|___  _ __  _   _ _ __ ___| |__   ___  _ __ ___   \n");
    printf("| |   / _ \\| '_ \\| | | | '__/ __| '_ \\ / _ \\| '_ ` _ \\  \n");
    printf("| |__| (_) | | | | |_| | | | (__| | | | (_) | | | | | | \n");
    printf(" \\____\\___/|_| |_|\\__,_|_|  \\___|_| |_|\\___/|_| |_| |_| \n");
    printf("              +-------------------------+\n");
    printf("              |    Currency Converter   |\n");
    printf("              +-------------------------+\n");

    do
    {
        printf("1. Convert Currency\n");
        printf("2. Quiz\n");
        printf("3. Show Exchange Rates\n");
         printf("4. MINI Game\n");
        printf("5. Exit\n");

    start:
        printf("Enter your choice: ");
        while (scanf("%d", &choice) != 1 || choice < 1 || choice > 5)
        {
            printf("Invalid input. Please enter 1-4: ");
            while (getchar() != '\n');
        }

        if (choice == 1)
        {
            currencymenu();
            printf("Write source currency: ");
            while (scanf("%d", &from) != 1 || from < 1 || from > 30)
            {
                printf("Invalid currency number (1 to 30). Try again: ");
                while (getchar() != '\n');
            }

            printf("In which do you want to convert:\n");
            currencymenu();
            while (scanf("%d", &to) != 1 || to < 1 || to > 30)
            {
                printf("Invalid currency number (1 to 30). Try again: ");
                while (getchar() != '\n');
            }

            printf("Enter Amount: ");
            while (scanf("%f", &amount) != 1 || amount <= 0)
            {
                printf("Invalid amount. Must be positive: ");
                while (getchar() != '\n');
            }

            float convert = (amount / rates[from - 1] * rates[to - 1]);
            printf("Converted Amount: %.2f\n", convert);
        }
        else if (choice == 2)
            quiz(answer);
        else if (choice == 3)
            show_exchange_rates();
            else if(choice==4)
            guess_exchange_rate_game();
        else
        {
            printf("Exiting...\n");
        }

        printf("Do you want to use the Converter again (y/n): ");
        scanf(" %c", &another);
        while (another != 'y' && another != 'Y' && another != 'n' && another != 'N')
        {
            printf("Invalid choice. Enter y/n: ");
            scanf(" %c", &another);
        }
        printf("\n");

    } while (another == 'y' || another == 'Y');

    return 0;
}
