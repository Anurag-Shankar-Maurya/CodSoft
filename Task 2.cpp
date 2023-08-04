/*
 Develop a calculator program that performs basic arithmetic
 operations such as addition, subtraction, multiplication, and
 division. Allow the user to input two numbers and choose an
 operation to perform.
*/
// Anurag
// 03/07/2023   18:22

#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    float num1, num2;
    char oper;
    cout << "\t\t\t\t+------------+\n";
    cout << "\t\t\t\t| Calculator |\n";
    cout << "\t\t\t\t+------------+\n";

    // Input two numbers
    cout << "Input the first number= ";
    cin >> num1;
    cout << "Input the second number= ";
    cin >> num2;

again:
    // Input the operator
    cout << "\nInput the arithmatic operation (+, -, *, /): ";
    cin >> oper;

    cout << endl;
    // operations
    switch (oper)
    {
    case '+':
        cout << num1 << " + " << num2 << " = " << num1 + num2;
        break;
    case '-':
        cout << num1 << " - " << num2 << " = " << num1 - num2;
        break;
    case '*':
        cout << num1 << " * " << num2 << " = " << num1 * num2;
        break;
    case '/':
        cout << num1 << " / " << num2 << " = " << num1 / num2;
        break;

    default:
        cout << "Input the correct operator!";
        goto again;
        break;
    }
    getch();
    return 0;
}