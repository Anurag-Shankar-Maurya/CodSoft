/*
Create a program that manages student grades. Allow the user
to input student names and their corresponding grades.
Calculate the average grade and display it along with the highest
and lowest grades.
*/
// Anurag
// 03/07/2023   21:34

#include <iostream>
#include <conio.h>
#include <string.h>
#include <cstring>
#define size 50 // number of data
using namespace std;

int main()
{
    char choice = 'y', n, i;
    char name[size][30];
    int max;
    char inputName[20];
    char grade[3];
    char gradeArray[size][3];
    char gradeReference[8][3];

    // storing values of grades
    strcpy(gradeReference[7], "A+");
    strcpy(gradeReference[6], "A");
    strcpy(gradeReference[5], "B+");
    strcpy(gradeReference[4], "B");
    strcpy(gradeReference[3], "C");
    strcpy(gradeReference[2], "D");
    strcpy(gradeReference[1], "E");
    strcpy(gradeReference[0], "F");

    cout << "\t\t\t\t+----------------+\n";
    cout << "\t\t\t\t| Grading System |\n";
    cout << "\t\t\t\t+----------------+\n";

    // printing grade reference
    cout << "Grade reference:\n";
    for (int h = 7; h >= 0; h--)
    {
        cout << gradeReference[h];
        if (h != 0)
            cout << ", ";
    }

    // taking name and grade as input

    cout << "\n\nInput student's name and respective grades:\n";

    i = -1;
    do
    {
        i++;
        cout << "\nInput student's name= ";
        cin >> inputName;
        strcpy(name[i], inputName);
        cout << "Input grade= ";
        cin >> grade;
        strcpy(gradeArray[i], grade);

        cout << "\nDo you want to input more data?";
        choice = getch();
    } while ((choice != 'N' || choice != 'n') && (choice == 'Y' || choice == 'y'));

    // findind size of largest name
    {
        max = strlen(name[1]);
        for (int k = 0; k <= i; k++)
        {
            if (max < strlen(name[k]))
            {
                max = strlen(name[k]);
            }
        }
    }
    // command line table display

    // printing names less than or equal to the length of 4
    int space;
    if (max <= 4)
    { // as "Name" be of fout characters
        cout << "\n\t\t+------+-------+";
        cout << "\n\t\t| Name | Grade |";
        cout << "\n\t\t+------+-------+";

        // prnting names and grades of respective students
        for (int m = 0; m <= i; m++)
        {
            space = (6 - strlen(name[m])) / 2;
            cout << "\n\t\t|";

            for (int p = 1; p <= space; p++)
            {
                cout << " ";
            }
            cout << name[m];

            for (int p = 1; p <= (6 - space - strlen(name[m])); p++)
            {
                cout << " ";
            }

            cout << "|   ";
            cout << gradeArray[m];
            strcpy(grade, gradeArray[m]);
            if (strlen(grade) == 2)
            {
                cout << "  |";
            }
            else if (strlen(grade) == 1)
            {
                cout << "   |";
            }
            else
            {
                cout << "    |";
            }
            cout << "\n\t\t+------+-------+";
        }
    }

    // printing name greater than length of 4
    if (max > 4)
    {
        cout << "\n\t\t+-";
        for (int p = 1; p <= max; p++)
        {
            cout << "-";
        }
        cout << "-+-------+";

        cout << "\n\t\t|";
        space = (max + 2 - 4) / 2;
        for (int p = 1; p <= space; p++)
        {
            cout << " ";
        }
        cout << "Name";
        for (int p = 1; p <= (max + 2 - 4 - space); p++)
        {
            cout << " ";
        }
        cout << "| Grade |";

        cout << "\n\t\t+-";
        for (int p = 1; p <= max; p++)
        {
            cout << "-";
        }
        cout << "-+-------+";

        // prnting names and grades of respective students
        for (int m = 0; m <= i; m++)
        {
            space = (max + 2 - strlen(name[m])) / 2;
            cout << "\n\t\t|";

            for (int p = 1; p <= space; p++)
            {
                cout << " ";
            }
            cout << name[m];

            for (int p = 1; p <= (max + 2 - space - strlen(name[m])); p++)
            {
                cout << " ";
            }

            cout << "|   ";
            cout << gradeArray[m];
            strcpy(grade, gradeArray[m]);
            if (strlen(grade) == 2)
            {
                cout << "  |";
            }
            else if (strlen(grade) == 1)
            {
                cout << "   |";
            }
            else
            {
                cout << "    |";
            }

            cout << "\n\t\t+-";
            for (int p = 1; p <= max; p++)
            {
                cout << "-";
            }
            cout << "-+-------+";
        }

        // finding max grade and min grade
        int maxGradeIndex = 7;
        int minGradeIndex = 0;
        int gradeIndex[size];
        int retainIndexMax;
        int retainIndexMin;
        char maxGrade[3];
        char minGrade[3];
        for (int h = 0; h <= i; h++)
        {
            for (int g = 0; g < 7; g++)
                if (strcmp(gradeArray[h], gradeReference[g]) == 0)
                    gradeIndex[h] = g;

            if (maxGradeIndex < gradeIndex[h])
            {
                maxGradeIndex = gradeIndex[h];
                retainIndexMax = h;
            }
            if (minGradeIndex > gradeIndex[h])
            {
                minGradeIndex = gradeIndex[h];
                retainIndexMin = h;
            }
        }
        strcpy(maxGrade, gradeReference[maxGradeIndex]);
        cout << "\nThe max grade is: " << maxGrade << "\nby student: " << name[retainIndexMax]<<endl;

        strcpy(minGrade, gradeReference[minGradeIndex]);
        cout << "\nThe min grade is: " << minGrade << "\nby student: " << name[retainIndexMin];

        getch();
        return 0;
    }
}