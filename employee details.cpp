#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int id;
    char name[30];
    float salary;
} Employee;
void addEmployee(FILE *fp);
void displayEmployee(FILE *fp);
void updateEmployee(FILE *fp);
int main() {
    FILE *fp;
    int choice;
    fp = fopen("employees.dat", "rb+");
    if (fp == NULL) {
        fp = fopen("employees.dat", "wb+");
        if (fp == NULL) {
            printf("Cannot open file.\n");
            exit(1);
        }
    }
    while(1) {
        printf("1. Add Employee\n");
        printf("2. Display Employee\n");
        printf("3. Update Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addEmployee(fp);
                break;
            case 2:
                displayEmployee(fp);
                break;
            case 3:
                updateEmployee(fp);
                break;
            case 4:
                fclose(fp);
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}
void addEmployee(FILE *fp) {
    Employee emp;
    printf("Enter ID: ");
    scanf("%d", &emp.id);
    printf("Enter name: ");
    scanf("%s", emp.name);
    printf("Enter salary: ");
    scanf("%f", &emp.salary);
    fseek(fp, 0, SEEK_END);
    fwrite(&emp, sizeof(emp), 1, fp); 
    printf("Employee added successfully.\n");
}
void displayEmployee(FILE *fp) {
    Employee emp;
    int id, found = 0;
    printf("Enter ID to display: ");
    scanf("%d", &id);
    rewind(fp);
    while(fread(&emp, sizeof(emp), 1, fp) == 1) {
        if(emp.id == id) {
            printf("ID: %d\n", emp.id);
            printf("Name: %s\n", emp.name);
            printf("Salary: %.2f\n", emp.salary);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Employee not found.\n");
    }
}
void updateEmployee(FILE *fp) {
    Employee emp;
    int id, found = 0;
    printf("Enter ID to update: ");
    scanf("%d", &id);
    rewind(fp);
    while(fread(&emp, sizeof(emp), 1, fp) == 1) {
        if(emp.id == id) {
            printf("Enter new name: ");
            scanf("%s", emp.name);
            printf("Enter new salary: ");
            scanf("%f", &emp.salary);
            fseek(fp, -sizeof(emp), SEEK_CUR); 
            fwrite(&emp, sizeof(emp), 1, fp);  
            found = 1;
            printf("Employee updated successfully.\n");
            break;
        }
    }
    if(!found) {
        printf("Employee not found.\n");
    }
}

