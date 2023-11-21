#include "SDB.h"
#include <stdio.h>
#define MAX_STUDENTS 10

void SDB_action(uint8 choice) {
    switch (choice) {
    case 1:
        if (SDB_AddEntry()) {
            printf("Entry added successfully.\n");
        } else {
            printf("Failed to add entry. Database is full.\n");
        }
        break;
    case 2:
        printf("Used size in the database: %u\n", SDB_GetUsedSize());
        break;
    case 3:
        printf("Enter student ID to read data: ");
        uint32 id;
        scanf("%u", &id);
        SDB_ReadEntry(id);
        break;
    case 4:
        printf("List of all student IDs:\n");
        uint8 count;
        uint32 list[MAX_STUDENTS];
        SDB_GetList(&count, list);
        for (uint8 i = 0; i < count; ++i) {
            printf("%u ", list[i]);
        }
        printf("\n");
        break;
    case 5:
        printf("Enter student ID to check existence: ");
        uint32 checkId;
        scanf("%u", &checkId);
        if (SDB_IsIdExist(checkId)) {
            printf("Student with ID %u exists.\n", checkId);
        } else {
            printf("Student with ID %u does not exist.\n", checkId);
        }
        break;
    case 6:
        printf("Enter student ID to delete: ");
        uint32 deleteId;
        scanf("%u", &deleteId);
        SDB_DeleteEntry(deleteId);
        break;
    case 7:
        if (SDB_IsFull()) {
            printf("The database is full.\n");
        } else {
            printf("The database is not full.\n");
        }
        break;
    case 0:
        printf("Exiting the program.\n");
        break;
    default:
        printf("Invalid choice. Please enter a valid option.\n");
    }
}

void SDB_APP() {
    uint8 choice;

    do {
        printf("Choose an option:\n");
        printf("1. To add entry, enter 1\n");
        printf("2. To get used size in the database, enter 2\n");
        printf("3. To read student data, enter 3\n");
        printf("4. To get the list of all student IDs, enter 4\n");
        printf("5. To check if ID is existed, enter 5\n");
        printf("6. To delete student data, enter 6\n");
        printf("7. To check if the database is full, enter 7\n");
        printf("8. To exit, enter 0\n");

        scanf("%hhu", &choice);
        SDB_action(choice);
    } while (choice != 0);
}

