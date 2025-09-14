#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int id;
    char name[50];
    int age;
    float marks;
};

struct Student students[MAX];
int count = 0;

// Function Prototypes
void addStudent();
void displayStudents();
void updateStudent();
void deleteStudent();
void filterByMarks();
void linearSearch();
void bubbleSort();
void selectionSort();
void insertionSort();


void addStudent() {
    if (count < MAX) {
        printf("Enter ID: ");
        scanf("%d", &students[count].id);
        printf("Enter Name: ");
        scanf(" %[^\n]", students[count].name);
        printf("Enter Age: ");
        scanf("%d", &students[count].age);
        printf("Enter Marks: ");
        scanf("%f", &students[count].marks);
        count++;
        printf("Student added successfully!\n");
    } else {
        printf("Student list is full!\n");
    }
}


void displayStudents() {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }
    printf("\nID\tName\t\tAge\tMarks\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-10s\t%d\t%.2f\n", students[i].id, students[i].name, students[i].age, students[i].marks);
    }
}


void updateStudent() {
    int id, found = 0;
    printf("Enter ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Enter new Name: ");
            scanf(" %[^\n]", students[i].name);
            printf("Enter new Age: ");
            scanf("%d", &students[i].age);
            printf("Enter new Marks: ");
            scanf("%f", &students[i].marks);
            printf("Student updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student not found!\n");
    }
}


void deleteStudent() {
    int id, found = 0;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("Student deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student not found!\n");
    }
}

// ---------------- Filter Students ----------------
void filterByMarks() {
    float threshold;
    printf("Enter marks threshold: ");
    scanf("%f", &threshold);
    printf("\nStudents scoring above %.2f:\n", threshold);
    printf("ID\tName\t\tAge\tMarks\n");
    for (int i = 0; i < count; i++) {
        if (students[i].marks >= threshold) {
            printf("%d\t%-10s\t%d\t%.2f\n", students[i].id, students[i].name, students[i].age, students[i].marks);
        }
    }
}


void linearSearch() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Student Found: %d, %s, %d, %.2f\n", students[i].id, students[i].name, students[i].age, students[i].marks);
            return;
        }
    }
    printf("Student not found.\n");
}


void bubbleSort() {
    struct Student temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Students sorted by marks (descending).\n");
}


void selectionSort() {
    for (int i = 0; i < count - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < count; j++) {
            if (students[j].id < students[minIndex].id) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            struct Student temp = students[i];
            students[i] = students[minIndex];
            students[minIndex] = temp;
        }
    }
    printf("Students sorted by ID (ascending).\n");
}


void insertionSort() {
    for (int i = 1; i < count; i++) {
        struct Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].age > key.age) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
    printf(" Students sorted by Age (ascending).\n");
}


int main() {
    int choice;
    do {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n2. Display Students\n3. Update Student\n4. Delete Student\n");
        printf("5. Filter by Marks\n6. Search Student\n7. Sort by Marks (Bubble Sort)\n");
        printf("8. Sort by ID (Selection Sort)\n9. Sort by Age (Insertion Sort)\n10. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 5: filterByMarks(); break;
            case 6: linearSearch(); break;
            case 7: bubbleSort(); displayStudents(); break;
            case 8: selectionSort(); displayStudents(); break;
            case 9: insertionSort(); displayStudents(); break;
            case 10: printf(" Exiting...\n"); break;
            default: printf(" Invalid choice! Try again.\n");
        }
    } while (choice != 10);

    return 0;
}
