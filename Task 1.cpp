/* Create a program that generates a random number and asks the
 user to guess it. Provide feedback on whether the guess is too
 high or too low until the user guesses the correct number.*/
// Anurag
// 03/07/2023   11:24

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <ctime>
using namespace std;

class Guess
{
private:
    int g, n, count;

public:
    Guess()
    {
        // taking guess input
        count = 1; // initilization
        cout << "\nChance: " << count;
        cout << "\nInput your guess (between 1 to 10)= ";
        cin >> n;
    }

    // to guess number and print output
    void guessFun()
    {
        // generating a random number
        srand(time(nullptr));
        g = 1 + (rand() % 10);

        // checking the guess

        while (count <= 5)
        {
            count++; // updation
            if (g == n)
            {
                cout << "\n\t\t\t\t"
                     << "+-----------------+\n"
                     << "\t\t\t\t"
                     << "| Congratulations |\n"
                     << "\t\t\t\t"
                     << "+-----------------+\n";
                cout << g << " is the write guess";

                getch();
                exit(1);
            }
            else if (count <= 5)
            {
                if (g > n)
                {
                    cout << "\nInput a larger number !";
                }
                else
                {
                    cout << "\nInput a smaller number!\n";
                }

                cout << "\n-----------------------------------------------";
                cout << "\nChance: " << count;
                cout << "\nInput your guess (between 1 to 10)= ";
                cin >> n;
            }
        }

        // if failed to guess
        cout << "\n\t\t\t\t"
             << "+------------+\n"
             << "\t\t\t\t"
             << "| You Failed |\n"
             << "\t\t\t\t"
             << "+------------+\n";
        cout << g << " is the write guess";
    }
};

int main()
{
    cout << "\t\t\t\t+------------------+\n";
    cout << "\t\t\t\t| Guess the number |\n";
    cout << "\t\t\t\t+------------------+\n";

    cout << "\nYou have 5 chances to guess the number\n";
    Guess G;
    G.guessFun();

    getch();
    return 0;
}