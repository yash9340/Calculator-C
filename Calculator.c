#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>  // For isdigit function

// Function to check if the input is a valid number (floating-point number)
int isValidNumber(char* str) {
    int dotCount = 0;
    if (str[0] == '-' || str[0] == '+') {
        // Skip the first character if it's a '+' or '-'
        str++;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(isdigit(str[i]))) {
            if (str[i] == '.' && dotCount == 0) {
                dotCount++;  // Allow only one decimal point
            } else {
                return 0;  // Invalid number
            }
        }
    }
    return 1;  // Valid number
}

void calculator() {
    double a, b;
    int choice;

    // Loop to get the first number from the user
    while (1) {
        char num1[100];
        printf("Type the value of 'a': ");
        fgets(num1, sizeof(num1), stdin);
        num1[strcspn(num1, "\n")] = '\0';  // Remove newline character

        if (isValidNumber(num1)) {
            a = atof(num1);  // Convert string to number
            break;  // Exit loop on successful conversion
        } else {
            printf("Invalid input. Please enter a valid number.\n");
        }
    }

    // Loop to get the second number from the user
    while (1) {
        char num2[100];
        printf("Type the value of 'b': ");
        fgets(num2, sizeof(num2), stdin);
        num2[strcspn(num2, "\n")] = '\0';  // Remove newline character

        if (isValidNumber(num2)) {
            b = atof(num2);  // Convert string to number
            break;  // Exit loop on successful conversion
        } else {
            printf("Invalid input. Please enter a valid number.\n");
        }
    }

    // Display welcome message
    char message[] = "We are going to create a calculator.";
    printf("%s\n", message);

    // Display operation options to the user
    printf("What you want to perform.\n");
    printf("1. Sum\n2. Subtraction\n3. Multiplication\n4. Divide\n5. Remainder\n6. Exponentiation\n7. Floor Division\n");

    // Loop to get the operation choice from the user
    while (1) {
        printf("Type chosen option: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');  // Clear the input buffer
            printf("Invalid input, please enter an integer between 1 to 7.\n");
        } else if (choice > 0 && choice <= 7) {
            break;  // Exit loop on valid input
        } else {
            printf("Please type an integer between 1 to 7.\n");
        }
    }

    // Perform the chosen operation and display the result
    switch (choice) {
        case 1:
            printf("The sum of %.2f and %.2f is %.2f.\n", a, b, a + b);
            break;
        case 2:
            printf("The subtraction from %.2f to %.2f is %.2f.\n", a, b, a - b);
            break;
        case 3:
            printf("The multiplication of %.2f with %.2f is %.2f.\n", a, b, a * b);
            break;
        case 4:
            if (b == 0) {
                printf("The division of %.2f by %.2f is undefined.\n", a, b);
            } else {
                printf("The division of %.2f by %.2f is %.2f.\n", a, b, a / b);
            }
            break;
        case 5:
            printf("The remainder when we divide %.2f by %.2f is %.2f.\n", a, b, fmod(a, b));
            break;
        case 6:
            if (b == 0) {
                printf("Exponentiation with zero is undefined.\n");
            } else {
                printf("The exponentiation of %.2f and %.2f is %.2f.\n", a, b, pow(a, b));
            }
            break;
        case 7:
            if (b == 0) {
                printf("The floor division of %.2f by %.2f is undefined.\n", a, b);
            } else {
                printf("The floor division of %.2f by %.2f is %.2f.\n", a, b, floor(a / b));
            }
            break;
        default:
            printf("Invalid operation.\n");
            break;
    }

    // Ask the user if they want to continue
    int continue_choice;
    while (1) {
        printf("Type 1 for continue / 0 for stop: ");
        
        // Clear the input buffer before using scanf again
        while (getchar() != '\n');  // Clear the input buffer

        if (scanf("%d", &continue_choice) != 1 || (continue_choice != 0 && continue_choice != 1)) {
            printf("Invalid input. Please type 1 or 0.\n");
        } else {
            break;
        }
    }

    if (continue_choice == 0) {
        printf("Ok, Thanks for using.\n");
        return;
    } else {
        calculator();  // Restart the calculator
    }
}

int main() {
    calculator();  // Start the calculator
    return 0;
}
