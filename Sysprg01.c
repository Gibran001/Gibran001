#include <stdio.h>

int main() {
    int choice;
    float result, width, height, radius;

    do {
        printf("Menu:\n");
        printf("1. Calculator Program\n");
        printf("2. Area Program\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                char op;
                float num1, num2;
                printf("Enter an operator (+, -, *, /): ");
                scanf(" %c", &op);
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                switch(op) {
                    case '+':
                        result = num1 + num2;
                        printf("%.2f + %.2f = %.2f\n", num1, num2, result);
                        break;
                    case '-':
                        result = num1 - num2;
                        printf("%.2f - %.2f = %.2f\n", num1, num2, result);
                        break;
                    case '*':
                        result = num1 * num2;
                        printf("%.2f * %.2f = %.2f\n", num1, num2, result);
                        break;
                    case '/':
                        if(num2 == 0) {
                            printf("Error: Division by zero\n");
                        } else {
                            result = num1 / num2;
                            printf("%.2f / %.2f = %.2f\n", num1, num2, result);
                        }
                        break;
                    default:
                        printf("Error: Invalid operator\n");
                }
                break;
            case 2:
                printf("Enter the width and height of a rectangle: ");
                scanf("%f %f", &width, &height);
                result = width * height;
                printf("Area of the rectangle is %.2f square units\n", result);

                printf("Enter the radius of a circle: ");
                scanf("%f", &radius);
                result = 3.14 * radius * radius;
                printf("Area of the circle is %.2f square units\n", result);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Error: Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}
