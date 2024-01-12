#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>

const char *line = "-------------------------------------------------------------------";
const char *Realpassword = "12345";

int cal(int n1, int n2, char symbol) {
    switch (symbol) {
        case '+': return n1 + n2;
        case '-': return n1 - n2;
        case 'x': return n1 * n2;
        case 'd': return n1 / n2;
        case 'm': return (int)n1 % (int)n2;
        default: return 0;
    }
}

void printTitle(const char *title) {
    int space = (strlen(line) - strlen(title)) / 2;
    printf("%s\n", line);
    printf("%*s%s%*s\n", space, "", title, space, "");
    printf("%s\n", line);
}

void main_menu() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const char *menu = "Main Menu";
    int space = (strlen(line) - strlen(menu)) / 2;

    printf("%s\n%*s%s%*s\n%s\n", line, space, "", menu, space, "", line);
    printf("1. +\n2. -\n3. X\n4. div\n5. mod\n6. Exit\n\n%s\n", line);

    int selected, num1, num2;
    char res[50];
    printf("Enter the number: ");
    scanf("%d", &selected);

    switch (selected) {
        case 1: case 3:
        	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
            printTitle(selected == 1 ? "Select to choice ==> 1" : "Select to choice ==> 3");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
            printf("Input Number 1 [1-10] ==> ");
            scanf("%d", &num1);
            if (num1 < 1 || num1 > 10) exit(0);
            printf("Input Number 2 [1-10] ==> ");
            scanf("%d", &num2);
            if (num2 < 1 || num2 > 10) exit(0);
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            sprintf(res, "%d %c %d = %d", num1, selected == 1 ? '+' : 'x', num2, cal(num1, num2, selected == 1 ? '+' : 'x'));
            printTitle(res);
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
            main_menu();
            break;
        case 2: case 4: case 5:
        	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
            printTitle(selected == 2 ? "Select to choice ==> 2" : selected == 4 ? "Select to choice ==> 4" : "Select to choice ==> 5");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
            printf("Input Number 1 [1-10] ==> ");
            scanf("%d", &num1);
            if (num1 < 1 || num1 > 10) exit(0);
            printf("Input Number 2 [1-10] ==> ");
            scanf("%d", &num2);
            if (num2 < 1 || num2 > 10) exit(0);
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            if(num1 < num2) {
            	sprintf(res, "%d %s %d = %d", num2, selected == 2 ? "-" : selected == 4 ? "div" : "mod", num1, cal(num2, num1, selected == 2 ? '-' : selected == 4 ? 'd' : 'm'));
            	printTitle(res);
			} else {
				sprintf(res, "%d %s %d = %d", num1, selected == 2 ? "-" : selected == 4 ? "div" : "mod", num2, cal(num1, num2, selected == 2 ? '-' : selected == 4 ? 'd' : 'm'));
            	printTitle(res);
			}
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
            main_menu();
            break;
        case 6:
            system("cls");
            printTitle("<< Bye Bye >>");
            sleep(5);
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

void check_password() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char input_password[6];
    int attempt = 0;
	printTitle("Welcome, program created by Rapheephat Atiyat");
    while (attempt < 3) {
        printf("Input the password ==> ");
        scanf("%s", input_password);
        if (strcmp(Realpassword, input_password) == 0) {
        	system("cls");
        	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printTitle("You are now successfully logged in.");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
            sleep(1);
            main_menu();
            break;
        } else {
            attempt++;
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
            printf("[Warning] Input password at %i not correct\n", attempt);
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
    }
}

int main() {
	check_password();
	sleep(1);
	return 0;
}
