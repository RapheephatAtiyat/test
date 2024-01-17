#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

const char *MAINPASSWORD = "12345";
const char *LINE = "-----------------------------------------------------------------------------------------";

void CheckPassword();
void PrintHeader(const char *header);
void MainMenu();
int Calculator(int num1, int num2, char symbol);

int main() {
    CheckPassword();
    return 0;
}

void PrintHeader(const char *header) {
    int space = (strlen(LINE) - strlen(header)) / 2;
    printf("%s\n%*s%s%*s\n%s\n", LINE, space, "", header, space, "", LINE);
}

int Calculator(int num1, int num2, char symbol) {
    switch (symbol) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case 'x': return num1 * num2;
        case 'd': return num1 / num2;
        case 'm': return (int)num1 % (int)num2;
        default: return 0;
    }
}

void CheckPassword() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char InputPassword[5];
    int attempts = 0;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    PrintHeader("Welcome, This program created by Rapheephat Atiyat");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    while (attempts < 3) {
        printf("Input the password ==> ");
        scanf("%s", InputPassword);
        if(strcmp(MAINPASSWORD, InputPassword) == 0) {
            system("cls");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            PrintHeader("You are now successfully logged in.");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            MainMenu();
            break;
        } else {
            attempts++;
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
            printf("[Warning] Input password at %i no correct.\n", attempts);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
    }
}

void MainMenu() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const char *txt = "Main Menu";
    int space = (strlen(LINE) - strlen(txt)) / 2;
    printf("%s\n%*s%s%*s\n%s\n", LINE, space, "", txt, space, "", LINE);
    printf("1. +\n2. -\n3. x\n4. div\n5. mod\n6. Exit\n");
    printf("%s\n", LINE);

    int selected, num1, num2;
    char res[50];
    printf("Input the number ==> ");
    scanf("%d", &selected);
    
    switch (selected) {
    case 1: case 3:
    	system("cls");
    	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
        PrintHeader(selected == 1 ? "Select to choice ==> 1" : "Select to choice ==> 3");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("Input Number 1 [1-10] ==> ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        scanf("%d", &num1);
        if(num1 < 1 || num1 > 10) {
        	system("cls");
			MainMenu();
		}
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        printf("Input Number 2 [1-10] ==> ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        scanf("%d", &num2);
        if(num2 < 1 || num2 > 10) {
        	system("cls");
			MainMenu();
		}
        sprintf(res, "%d %c %d = %d", num1, selected == 1 ? '+' : 'x', num2, Calculator(num1, num2, selected == 1 ? '+' : 'x'));
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        PrintHeader(res);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        MainMenu();
        break;
    case 2: case 4: case 5:
    	system("cls");
    	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
        PrintHeader(selected == 2 ? "Select to choice ==> 2" : selected == 4 ? "Select to choice ==> 4" : "Select to choice ==> 5");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("Input Number 1 [1-10] ==> ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        scanf("%d", &num1);
        if(num1 < 1 || num1 > 10) {
        	system("cls");
			MainMenu();
		}
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        printf("Input Number 2 [1-10] ==> ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        scanf("%d", &num2);
        if(num2 < 1 || num2 > 10) {
        	system("cls");
			MainMenu();
		}
        if(num1 < num2) {
            sprintf(res, "%d %s %d = %d", num2, selected == 2 ? "-" : selected == 4 ? "div" : "mod", num1, Calculator(num2, num1, selected == 2 ? '-' : selected == 4 ? 'd': 'm'));
        } else {
            sprintf(res, "%d %s %d = %d", num1, selected == 2 ? "-" : selected == 4 ? "div" : "mod", num2, Calculator(num1, num2, selected == 2 ? '-' : selected == 4 ? 'd': 'm'));
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        PrintHeader(res);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        MainMenu();
        break;
    case 6:
    	system("cls");
    	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    	PrintHeader("<<< Bye Bye >>>");
    	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    	sleep(2);
    	break;
    default:
    	system("cls");
    	MainMenu();
        break;
    }
}
