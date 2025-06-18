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

void currencymenu() {
    printf("\033[1;36mSelect your Currency:\033[0m\n\n");
    int i;
    for ( i = 0; i < 30; i += 3) {
        printf("%2d. %-25s", i + 1, currencies[i]);
        if (i + 1 < 30) printf("%2d. %-25s", i + 2, currencies[i + 1]);
        if (i + 2 < 30) printf("%2d. %-25s", i + 3, currencies[i + 2]);
        printf("\n");
    }
}


void medium_quiz()
{
    int answer1, useranswer, count = 0;
    srand(time(NULL));
    printf("\033[1;36m\nThere will be 7 MCQS\n\033[0m");
    int i;
    for (i = 1; i <= 7; i++)
    {
        int random = (rand() % 500) + 1;
        int r1 = rand() % 15;
        int r2 = rand() % 15;
        printf("\033[1;33m%d. %d %s in %s(Hint:ExRate=%.2f , %.2f) = \033[0m", i, random, currencies[r1], currencies[r2], rates[r1], rates[r2]);
        answer1 = (random / rates[r1] * rates[r2]);

        while (scanf("%d", &useranswer) != 1)
        {
            printf("\033[1;31mInvalid input. Please enter a number: \033[0m");
            while (getchar() != '\n');
        }

        printf("\n\033[0;32mActual answer is %d\n\033[0m", answer1);
        if (useranswer == answer1)
        {
            printf("\033[1;32mBINGO\n\n\033[0m");
            count++;
        }
        else if (abs(useranswer - answer1) < 10)
        {
            printf("\033[1;34m---- Very Close!! CORRECT ANSWER\n\n \033[0m");
            count++;
        }
        else
            printf("\033[1;31mWrong Answer , Let's move on Next\n\n\033[0m");
    }
    printf("\033[1;36mYour Quiz is Over! Thanks!!\nYour Score is %d/7\n\033[0m", count);
}

void easyquiz()
{
    int answer1, useranswer, count = 0;
    srand(time(NULL));
    printf("\033[1;36m\nThere will be 5 MCQS\n\033[0m");
    int i;
    for (i = 1; i <= 5; i++)
    {
        int random = (rand() % 100) + 1;
        int r1 = rand() % 10;
        int r2 = rand() % 10;
        printf("\033[1;33m%d. %d %s in %s(Hint:ExRate=%.2f , %.2f) = \033[0m", i, random, currencies[r1], currencies[r2], rates[r1], rates[r2]);
        answer1 = (random / rates[r1] * rates[r2]);

        while (scanf("%d", &useranswer) != 1)
        {
            printf("\033[1;31mInvalid input. Please enter a number: \033[0m");
            while (getchar() != '\n');
        }

        printf("\n\033[0;32mActual answer is %d\n\033[0m", answer1);
        if (useranswer == answer1)
        {
            printf("\033[1;32mBINGO\n\n\033[0m");
            count++;
        }
        else if (abs(useranswer - answer1) < 10)
        {
            printf("\033[1;34m---- Very Close!! CORRECT ANSWER\n\n \033[0m");
            count++;
        }
        else
            printf("\033[1;31mWrong Answer , Let's move on Next\n\n\033[0m");
    }
    printf("\033[1;36mYour Quiz is Over! Thanks!!\nYour Score is %d/5\n\033[0m", count);
}

void quiz(int answer)
{
    int ch, useranswer, count = 0;
    char plont;
    printf("\033[1;36m              ----WELCOME TO THE QUIZ------\n\033[0m");
    printf("\033[0;35mDescription:\n Dont Panic! this quiz require great math capability as well as strong sense of endurance, the one with powerful brain,stamina and capability will stand out, Less than 5 marks means you are a failue, and their will always be an asian kid whose gonna smack you in Maths, So prove what you got!!\n\033[0m");
    printf("\033[1;33mAre you sure you wanna play (y/n): \033[0m");
    scanf(" %c", &plont);
    if (plont == 'n' || plont == 'N')
    {
        printf("\033[1;31m\nHuh!! I knew you don't have Guts! Go play with Dolls!!!\n\033[0m");
        return;
    }

    printf("\033[1;36mWhat Level of Difficulty can you Handle!\n1. EASY (kiddo)\n2. MEDIUM (Guts)\n3. HARD (hats off sir)\nEnter: \033[0m");
    while (scanf("%d", &ch) != 1 || ch < 1 || ch > 3)
    {
        printf("\033[1;31mInvalid input. Enter 1, 2 or 3: \033[0m");
        while (getchar() != '\n');
    }

    if (ch == 1)
        easyquiz();
    else if (ch == 2)
        medium_quiz();
    else if (ch == 3)
    {
        srand(time(NULL));
        printf("\033[1;36m\nThere will be 10 MCQS\n\033[0m");
        int i;
        for (i = 1; i <= 10; i++)
        {
            int random = (rand() % 1000) + 1;
            int r1 = rand() % 30;
            int r2 = rand() % 30;
            printf("\033[1;33m%d. %d %s in %s(Hint:ExRate=%.2f , %.2f) = \033[0m", i, random, currencies[r1], currencies[r2], rates[r1], rates[r2]);
            answer = (random / rates[r1] * rates[r2]);

            while (scanf("%d", &useranswer) != 1)
            {
                printf("\033[1;31mInvalid input. Please enter a number: \033[0m");
                while (getchar() != '\n');
            }

            printf("\n\033[0;32mActual answer is %d\n\033[0m", answer);
            if (useranswer == answer)
            {
                printf("\033[1;32mBINGO\n\n\033[0m");
                count++;
            }
            else if (abs(useranswer - answer) < 10)
            {
                printf("\033[1;34m---- Very Close!! CORRECT ANSWER\n\n \033[0m");
                count++;
            }
            else
                printf("\033[1;31mWrong Answer , Let's move on Next\n\n\033[0m");
        }
        printf("\033[1;36mYour Quiz is Over! Thanks!!\nYour Score is %d/10\n\033[0m", count);
    }
}

void show_exchange_rates()
{
    int i;
    for (i = 0; i < 30; i++)
    {
        printf("\033[0;33m%d. %s = %.2f\033[0m \t  \033[0;33m%d. %s = %.2f\033[0m\n", i + 1, currencies[i], rates[i], i + 2, currencies[i + 1], rates[i + 1]);
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

    printf("\n\033[1;36m             ============================\n");
    printf("                   GUESS THE RATE GAME\n");
    printf("               ============================\n\033[0m");
    printf("\033[0;35mGuess the exchange rate from %s (%s) to %s (%s)\n\033[0m", 
           currencies[from], codes[from], currencies[to], codes[to]);
    printf("\033[1;33mYou have %d attempts!\n\033[0m", attempts);

    while (attempts--)
    {
        printf("\033[1;36mEnter your guess (e.g., 1.25): \033[0m");
        if (scanf("%f", &guess) != 1) {
            while (getchar() != '\n');
            printf("\033[1;31mInvalid input. Try again.\n\033[0m");
            attempts++;
            continue;
        }

        if (guess > actual_rate - 0.1 && guess < actual_rate + 0.1)
        {
            printf("\033[1;32m Correct! The actual rate is approximately %.2f\n\033[0m", actual_rate);
            return;
        }
        else if (guess > actual_rate)
            printf("\033[1;33mToo high!\n\033[0m");
        else
            printf("\033[1;33mToo low!\n\033[0m");

        if (attempts > 0)
            printf("\033[1;36mTry again! Attempts left: %d\n\033[0m", attempts);
        else
            printf("\033[1;31m Game over! The correct answer was %.2f\n\033[0m", actual_rate);
    }
}

int main()
{
    int choice, from, to, answer;
    float amount;
    char another;
    printf("\033[96m");

    printf("      ___           ___           ___                         ___           ___           ___                 \n");
    printf("     /\\  \\         /|  |         /\\  \\                       /\\__\\         /\\  \\         /|  |                \n");
    printf("    /::\\  \\       |:|  |        /::\\  \\         ___         /:/ _/_        \\:\\  \\       |:|  |        ___     \n");
    printf("   /:/\\:\\  \\      |:|  |       /:/\\:\\  \\       /\\__\\       /:/ /\\  \\        \\:\\  \\      |:|  |       /\\__\\    \n");
    printf("  /:/ /::\\  \\   __|:|  |      /:/ /::\\  \\     /:/  /      /:/ /::\\  \\   ___  \\:\\  \\   __|:|  |      /:/__/    \n");
    printf(" /:/_/:/\\:\\__\\ /\\ |:|__|____ /:/_/:/\\:\\__\\   /:/__/      /:/_/:/\\:\\__\\ /\\  \\  \\:\\__\\ /\\ |:|__|____ /::\\  \\    \n");
    printf(" \\:\\/:/  \\/__/ \\:\\/:::::/__/ \\:\\/:/  \\/__/  /::\\  \\      \\:\\/:/ /:/  / \\:\\  \\ /:/  / \\:\\/:::::/__/ \\/\\:\\  \\__ \n");
    printf("  \\::/__/       \\::/~~/~      \\::/__/      /:/\\:\\  \\      \\::/ /:/  /   \\:\\  /:/  /   \\::/~~/~      ~~\\:\\/\\__\\\n");
    printf("   \\:\\  \\        \\:\\~~\\        \\:\\  \\      \\/__\\:\\  \\      \\/_:/  /     \\:\\/:/  /     \\:\\~~\\          \\::/  / \n");
    printf("    \\:\\__\\        \\:\\__\\        \\:\\__\\          \\:\\__\\       /:/  /       \\::/  /       \\:\\__\\         /:/  / \n");
    printf("     \\/__/         \\/__/         \\/__/           \\/__/       \\/__/         \\/__/         \\/__/         \\/__/  \n");
    printf("\n_________________________________________________________________________________________________________________________________________\n\n");
    printf("\033[0m");
    printf("\033[1;36m              +-------------------------+\n");
    printf("              |     Smart Currency Exchange System   |\n");
    printf("              +-------------------------+\n\033[0m");

    do
    {
        printf("\033[1;33m1. Convert Currency\n");
        printf("2. Quiz\n");
        printf("3. Show Exchange Rates\n");
        printf("4. MINI Game\n");
        printf("5. Exit\n\033[0m");

    start:
        printf("\033[1;32mEnter your choice: \033[0m");
        while (scanf("%d", &choice) != 1 || choice < 1 || choice > 5)
        {
            printf("\033[1;31mInvalid input. Please enter 1-5: \033[0m");
            while (getchar() != '\n');
        }

        if (choice == 1)
        {
            currencymenu();
            printf("\033[1;36mWrite source currency: \033[0m");
            while (scanf("%d", &from) != 1 || from < 1 || from > 30)
            {
                printf("\033[1;31mInvalid currency number (1 to 30). Try again: \033[0m");
                while (getchar() != '\n');
            }

            printf("\033[1;36mIn which do you want to convert:\n\033[0m");
            currencymenu();
            while (scanf("%d", &to) != 1 || to < 1 || to > 30)
            {
                printf("\033[1;31mInvalid currency number (1 to 30). Try again: \033[0m");
                while (getchar() != '\n');
            }

            printf("\033[1;36mEnter Amount: \033[0m");
            while (scanf("%f", &amount) != 1 || amount <= 0)
            {
                printf("\033[1;31mInvalid amount. Must be positive: \033[0m");
                while (getchar() != '\n');
            }

            float convert = (amount / rates[from - 1] * rates[to - 1]);
            printf("\033[1;32mConverted Amount: %.2f\033[0m\n", convert);
        }
        else if (choice == 2)
            quiz(answer);
        else if (choice == 3)
            show_exchange_rates();
        else if (choice == 4)
            guess_exchange_rate_game();
        else
        {
            printf("\033[1;31mExiting...\033[0m\n");
        }

        printf("\033[1;33mDo you want to use the Converter again (y/n): \033[0m");
        scanf(" %c", &another);
        while (another != 'y' && another != 'Y' && another != 'n' && another != 'N')
        {
            printf("\033[1;31mInvalid choice. Enter y/n: \033[0m");
            scanf(" %c", &another);
        }
        printf("\n");

    } while (another == 'y' || another == 'Y');

    return 0;
}
