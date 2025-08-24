#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ---------- Python Caller ----------
void callPython(const char *script)
{
    char command[300];
    snprintf(command, sizeof(command), "python ..\\Python_Functional\\%s", script);
    system(command);
}

// ---------- Python Caller for Option 2 ----------
void callPythonOption2()
{
    char command[400];
    snprintf(command, sizeof(command), "python ..\\Python_Functional\\Print1.py");
    system(command);
}

// ---------- Python Caller for Option 3 ----------
void callPythonOption3()
{
    char command[400];
    snprintf(command, sizeof(command), "python ..\\Python_Functional\\Print2.py");
    system(command);
}

// ---------- C++ Caller ----------
void callCpp(const char *exe)
{
    char command[400];
    snprintf(command, sizeof(command), "cmd /c \"%s\"", exe);
    int ret = system(command);
    if (ret != 0)
        printf("Failed to run C++ executable. Error code: %d\n", ret);
}

// ---------- Prolog Caller ----------
void callProlog(const char *script, const char *from, const char *to, const char *via)
{
    char command[500];
    // Pass all arguments to print_message/3 in Prolog
    snprintf(command, sizeof(command),
             "swipl -q -s ..\\Prolog_Logic\\%s -g \"print_message('%s','%s','%s')\" -t halt",
             script, from, to, via);
    system(command);
}

// ---------- Helper: Trim whitespace ----------
void trim(char *str)
{
    // Trim leading spaces
    while(isspace((unsigned char)*str)) str++;

    // Trim trailing spaces
    char *end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
}

// ---------- Main CLI ----------
int main()
{
    int choice;
    char from[50], to[50], via[50];

    do
    {
        printf("\n========== CTCTG CLI ==========\n");
        printf("1. Available routes between From → To\n");
        printf("2. For the chosen route, show all modes of transport, cost, time, distance\n");
        printf("3. Shortest / Longest distance route\n");
        printf("4. Is there a route from A → B via C\n");
        printf("5. Travel times of all modes of transport for a given route\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume leftover newline
        printf("===================================\n");

        switch (choice)
        {
            case 1:
                printf("-----------------------------------------------\n");
                printf("You chose: Available routes between From → To\n");
                callPython("Print.py");
                printf("-----------------------------------------------\n");
                break;

            case 2:
                printf("-----------------------------------------------\n");
                printf("You chose: Modes of transport, cost, time, distance\n");
                callPythonOption2();
                printf("-----------------------------------------------\n");
                break;

            case 3:
                printf("-----------------------------------------------\n");
                printf("You chose: Shortest / Longest distance route\n");
                callPythonOption3();
                printf("-----------------------------------------------\n");
                break;

            case 4:
                printf("----------------------------------------------\n");
                printf("You chose: Is there a route from A → B via C\n");
                printf("From: ");
                fgets(from, sizeof(from), stdin);
                trim(from);
                printf("To: ");
                fgets(to, sizeof(to), stdin);
                trim(to);
                printf("Via: ");
                fgets(via, sizeof(via), stdin);
                trim(via);

                callProlog("Qna.pl", from, to, via); // now passes all three arguments
                printf("----------------------------------------------\n");
                break;

            case 5:
                printf("---------------------------------------------------\n");
                printf("You chose: Travel times of all modes of transport\n");
                callCpp("D:\\STARTED\\CTCTG\\Cpp_Object\\Call.exe");
                printf("---------------------------------------------------\n");
                break;

            case 6:
                printf("---------------------\n");
                printf("Exiting... Goodbye!\n");
                printf("---------------------\n");
                break;

            default:
                printf("-----------------------------------\n");
                printf("Invalid choice! Please try again.\n");
                printf("-----------------------------------\n");
        }

    } while (choice != 6);

    return 0;
}
