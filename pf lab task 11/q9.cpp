#include <stdio.h>
#include <string.h>
#define MAX_DEPTS 10
#define MAX_COURSES 5
#define MAX_STUDENTS 50
#define MAX_NAME_LEN 100

struct Student {
    int id;
    char name[MAX_NAME_LEN];
};

struct Instructor {
    int id;
    char name[MAX_NAME_LEN];
    char department[MAX_NAME_LEN];
};

struct Course {
    int id;
    char name[MAX_NAME_LEN];
    struct Instructor instructor;
    struct Student students[MAX_STUDENTS];
    int numStudents;
};

struct Department {
    int id;
    char name[MAX_NAME_LEN];
    struct Course courses[MAX_COURSES];
    int numCourses;
};

struct University {
    struct Department departments[MAX_DEPTS];
    int numDepartments;
};

void addDepartment(struct University *uni) {
    if (uni->numDepartments >= MAX_DEPTS) {
        printf("Max departments reached.\n");
        return;
    }

    struct Department dept;
    printf("Enter Department ID: ");
    scanf("%d", &dept.id);
    printf("Enter Department Name: ");
    scanf(" %[^\n]", dept.name);
    dept.numCourses = 0;

    uni->departments[uni->numDepartments++] = dept;
}

void addCourse(struct University *uni, int deptId) {
    for (int i = 0; i < uni->numDepartments; i++) {
        if (uni->departments[i].id == deptId) {
            if (uni->departments[i].numCourses >= MAX_COURSES) {
                printf("Max courses reached in department.\n");
                return;
            }

            struct Course course;
            printf("Enter Course ID: ");
            scanf("%d", &course.id);
            printf("Enter Course Name: ");
            scanf(" %[^\n]", course.name);
            
            printf("Enter Instructor ID: ");
            scanf("%d", &course.instructor.id);
            printf("Enter Instructor Name: ");
            scanf(" %[^\n]", course.instructor.name);
            printf("Enter Instructor Department: ");
            scanf(" %[^\n]", course.instructor.department);

            course.numStudents = 0;
            uni->departments[i].courses[uni->departments[i].numCourses++] = course;
            return;
        }
    }
    printf("Department not found.\n");
}

void enrollStudent(struct University *uni, int deptId, int courseId) {
    for (int i = 0; i < uni->numDepartments; i++) {
        if (uni->departments[i].id == deptId) {
            for (int j = 0; j < uni->departments[i].numCourses; j++) {
                if (uni->departments[i].courses[j].id == courseId) {
                    if (uni->departments[i].courses[j].numStudents >= MAX_STUDENTS) {
                        printf("Max students reached in this course.\n");
                        return;
                    }

                    struct Student student;
                    printf("Enter Student ID: ");
                    scanf("%d", &student.id);
                    printf("Enter Student Name: ");
                    scanf(" %[^\n]", student.name);

                    uni->departments[i].courses[j].students[uni->departments[i].courses[j].numStudents++] = student;
                    printf("Student enrolled successfully.\n");
                    return;
                }
            }
            printf("Course not found.\n");
            return;
        }
    }
    printf("Department not found.\n");
}

void viewUniversity(struct University *uni) {
    for (int i = 0; i < uni->numDepartments; i++) {
        printf("\nDepartment ID: %d\n", uni->departments[i].id);
        printf("Department Name: %s\n", uni->departments[i].name);

        for (int j = 0; j < uni->departments[i].numCourses; j++) {
            printf("\tCourse ID: %d\n", uni->departments[i].courses[j].id);
            printf("\tCourse Name: %s\n", uni->departments[i].courses[j].name);
            printf("\tInstructor: %s (%s)\n", uni->departments[i].courses[j].instructor.name, uni->departments[i].courses[j].instructor.department);

            for (int k = 0; k < uni->departments[i].courses[j].numStudents; k++) {
                printf("\t\tStudent ID: %d\n", uni->departments[i].courses[j].students[k].id);
                printf("\t\tStudent Name: %s\n", uni->departments[i].courses[j].students[k].name);
            }
        }
    }
}

int main() {
    struct University uni;
    uni.numDepartments = 0;
    
    int choice;
    while (1) {
        printf("\nUniversity Management System\n");
        printf("1. Add Department\n");
        printf("2. Add Course\n");
        printf("3. Enroll Student\n");
        printf("4. View University Details\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            addDepartment(&uni);
        } else if (choice == 2) {
            int deptId;
            printf("Enter Department ID: ");
            scanf("%d", &deptId);
            addCourse(&uni, deptId);
        } else if (choice == 3) {
            int deptId, courseId;
            printf("Enter Department ID: ");
            scanf("%d", &deptId);
            printf("Enter Course ID: ");
            scanf("%d", &courseId);
            enrollStudent(&uni, deptId, courseId);
        } else if (choice == 4) {
            viewUniversity(&uni);
        } else if (choice == 5) {
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
