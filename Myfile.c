#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the employee structure
typedef struct Employee {
    char name[50];
    int age;
    char department[50];
    struct Employee *next;
    struct Employee *prev;
} Employee;

// Declare global variables
Employee *head = NULL;
Employee *tail = NULL;

// Function to push an employee onto the stack
void push(Employee *emp) {
    if (head == NULL) {
        head = emp;
        tail = emp;
    } else {
        tail->next = emp;
        emp->prev = tail;
        tail = emp;
    }
}

// Function to pop an employee from the stack
Employee *pop() {
    if (tail == NULL) {
        printf("Error: stack is empty\n");
        return NULL;
    } else {
        Employee *temp = tail;
        if (tail == head) {
            tail = NULL;
            head = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        return temp;
    }
}

// Function to print an employee's details
void printEmployee(Employee *emp) {
    printf("Name: %s\n", emp->name);
    printf("Age: %d\n", emp->age);
    printf("Department: %s\n", emp->department);
}

// Function to print all employees on the stack
void printAllEmployees() {
    Employee *current = head;
    while (current != NULL) {
        printEmployee(current);
        current = current->next;
    }
}

// Function to create a new employee
Employee *createEmployee(char *name, int age, char *department) {
    Employee *newEmp = (Employee *) malloc(sizeof(Employee));
    strcpy(newEmp->name, name);
    newEmp->age = age;
    strcpy(newEmp->department, department);
    newEmp->next = NULL;
    newEmp->prev = NULL;
    return newEmp;
}

int main() {
    // Create some sample employees
    Employee *emp1 = createEmployee("John Doe", 30, "Sales");
    Employee *emp2 = createEmployee("Jane Smith", 25, "Marketing");
    Employee *emp3 = createEmployee("Bob Johnson", 40, "HR");

    // Add the employees to the stack
    push(emp1);
    push(emp2);
    push(emp3);

    // Print all employees on the stack
    printf("All employees on the stack:\n");
    printAllEmployees();

    // Pop an employee off the stack and print their details
    Employee *poppedEmp = pop();
    printf("Popped employee:\n");
    printEmployee(poppedEmp);

    // Print all employees on the stack again
    printf("All employees on the stack after popping one:\n");
    printAllEmployees();

    // Clean up memory
    free(emp1);
    free(emp2);
    free(emp3);
    free(poppedEmp);

    return 0;
}
