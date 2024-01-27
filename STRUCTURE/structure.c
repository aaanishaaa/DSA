/*  1) Get the input of student: Name, Roll No, Marks in 6 subjects in 12th. Find if the student is eligible for admission in Delhi University.
 student is eligible for DU if he has scored 95 % or more in Best 4.
    2) Write a program to store and print the roll no., name, age and marks of a student using structures. Write a program to store the roll no.
     (starting from 1), name and age of 5 students and then print the details of the student with roll no. 1.
    3) Write a program to store and print the roll no., name, age, address and marks of 15 students using structure
    4) Enter the marks of 5 students in Chemistry, Mathematics and Physics (each out of 100) using a structure named Marks having elements roll no.,
name, chem_marks, maths_marks and phy_marks and then display the percentage of each student

#include <stdio.h>
    struct Student {
    char name[50];
    int rollNo;
    float marks[6];
};
int calculateBestFour(struct Student student) {
    int bestFour = 0;
    int lowestMark = student.marks[0];

    for (int i = 0; i < 6; i++) {
        if (student.marks[i] < lowestMark) {
            lowestMark = student.marks[i];
        }
    }
    for (int i = 0; i < 6; i++) {
        if (student.marks[i] != lowestMark) {
            bestFour += student.marks[i];
        }
    }
    return bestFour;
}
int main() {
    struct Student student;
    printf("Enter student name: ");
    scanf("%s", student.name);
    printf("Enter student roll number: ");
    scanf("%d", &student.rollNo);
    printf("Enter marks in 6 subjects in 12th:\n");
    for (int i = 0; i < 6; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &student.marks[i]);
    }
    float bestFour = calculateBestFour(student);
    float percentage = (bestFour / 400) ;
    if (percentage >= 95) {
        printf("Congratulations! %s is eligible for admission to Delhi University", student.name);
    } else {
        printf("Sorry, You are not eligible for admission to Delhi University ");
    }
    return 0;
}
*/
#include <stdio.h>

// Define a structure to represent a student
struct Student {
    int rollNo;
    char name[50];
    int age;
    float marks;
};

int main() {
    struct Student students[5]; // Array to store information of 5 students

    // Input information for 5 students
    for (int i = 0; i < 5; i++) {
        printf("Enter details for Student %d:\n", i + 1);
        students[i].rollNo = i + 1; // Roll numbers start from 1
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
        printf("\n");
    }

    // Print details of the student with roll number 1
    printf("Details of Student with Roll No. 1:\n");
    printf("Roll No: %d\n", students[0].rollNo);
    printf("Name: %s\n", students[0].name);
    printf("Age: %d\n", students[0].age);
    printf("Marks: %.2f\n", students[0].marks);

    return 0;
}

