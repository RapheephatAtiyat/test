#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
    const char *menu = "Main Menu";
    int space = (strlen(line) - strlen(menu)) / 2;

    system("cls");
    printf("%s\n%*s%s%*s\n%s\n", line, space, "", menu, space, "", line);
    printf("1. +\n2. -\n3. X\n4. div\n5. mod\n6. Exit\n\n%s\n", line);

    int selected, num1, num2;
    char res[50];
    printf("Enter the number: ");
    scanf("%d", &selected);

    switch (selected) {
        case 1: case 3: case 5:
            printTitle(selected == 1 ? "Select to choice ==> 1" : (selected == 3 ? "Select to choice ==> 3" : "Select to choice ==> 5"));
            printf("Input Number 1 [1-10] ==> ");
            scanf("%d", &num1);
            printf("Input Number 2 [1-10] ==> ");
            scanf("%d", &num2);
            sprintf(res, "%d %c %d = %d", num1, selected == 1 ? '+' : (selected == 3 ? 'x' : 'm'), num2, cal(num1, num2, selected == 1 ? '+' : (selected == 3 ? 'x' : 'm')));
            printTitle(res);
            break;
        case 2: case 4:
            printTitle(selected == 2 ? "Select to choice ==> 2" : "Select to choice ==> 4");
            printf("Input Number 1 [1-10] ==> ");
            scanf("%d", &num1);
            if (num1 < 1 || num1 > 10) exit(0);
            printf("Input Number 2 [1-10] ==> ");
            scanf("%d", &num2);
            sprintf(res, "%d %c %d = %d", num2, selected == 2 ? '-' : 'd', num1, cal(num2, num1, selected == 2 ? '-' : 'd'));
            printTitle(res);
            break;
        case 6:
            system("cls");
            printTitle("<<Bye Bye>>");
            printf("Press any key to exit...");
            getchar(); // Wait for any key press
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

int main() {
    char input_password[6];
    int attempt = 0;

    while (attempt < 3) {
        printf("Enter the password: ");
        scanf("%s", input_password);
        if (strcmp(Realpassword, input_password) == 0) {
            printf("[Success] Login successful\n");
            sleep(1);
            main_menu();
            break;
        } else {
            attempt++;
            printf("[Fail] Input password at %i not correct\n", attempt);
        }
    }

    sleep(2);
    return 0;
}
