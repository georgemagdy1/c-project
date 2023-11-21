#include "SDB.h"
#include <stdio.h>

#define MAX_STUDENTS 10

static student database[MAX_STUDENTS];
static uint8 usedSize = 0;

bool SDB_IsFull() {
    return usedSize == MAX_STUDENTS;
}

uint8 SDB_GetUsedSize() {
    return usedSize;
}

bool SDB_AddEntry() {
    if (SDB_IsFull()) {
        return false;
    }

    printf("Enter student data (ID, Year, Course1_ID, Course1_grade, Course2_ID, Course2_grade, Course3_ID, Course3_grade):\n");
    printf("\n");

    printf("ID :");
    scanf("%u",&database[usedSize].Student_ID);
    printf("Year :");
    scanf("%u",&database[usedSize].Student_year);
    printf("Course1_ID :");
    scanf("%u",&database[usedSize].Course1_ID);
    printf("Course1_grade :");
    scanf("%u",&database[usedSize].Course1_grade);
    printf("Course2_ID :");
    scanf("%u",&database[usedSize].Course2_ID);
    printf("Course2_grade :");
    scanf("%u",&database[usedSize].Course2_grade);
    printf("Course3_ID :");
    scanf("%u",&database[usedSize].Course3_ID);
    printf("Course3_grade :");
    scanf("%u",&database[usedSize].Course3_grade);

    usedSize++;
    return true;
}

void SDB_DeleteEntry(uint32 id) {
    for (uint8 i = 0; i < usedSize; ++i) {
        if (database[i].Student_ID == id) {
            // Shift elements to remove the entry
            for (uint8 j = i; j < usedSize - 1; ++j) {
                database[j] = database[j + 1];
            }
            usedSize--;
            printf("Student with ID %u deleted successfully.\n", id);
            return;
        }
    }
    printf("Student with ID %u not found.\n", id);
}

bool SDB_ReadEntry(uint32 id) {
    for (uint8 i = 0; i < usedSize; ++i) {
        if (database[i].Student_ID == id) {
            printf("Student Data:\n");
            printf("ID: %u\nYear: %u\nCourse1_ID: %u\nCourse1_grade: %u\nCourse2_ID: %u\nCourse2_grade: %u\nCourse3_ID: %u\nCourse3_grade: %u\n",
                   database[i].Student_ID, database[i].Student_year,
                   database[i].Course1_ID, database[i].Course1_grade,
                   database[i].Course2_ID, database[i].Course2_grade,
                   database[i].Course3_ID, database[i].Course3_grade);
            return true;
        }
    }
    printf("Student with ID %u not found.\n", id);
    return false;
}

void SDB_GetList(uint8 *count, uint32 *list) {
    *count = usedSize;
    for (uint8 i = 0; i < usedSize; ++i) {
        list[i] = database[i].Student_ID;
    }
}

bool SDB_IsIdExist(uint32 id) {
    for (uint8 i = 0; i < usedSize; ++i) {
        if (database[i].Student_ID == id) {
            return true;
        }
    }
    return false;
}


