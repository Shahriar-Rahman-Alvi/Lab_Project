#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_COURSES 100
#define MAX_SECTIONS 10
#define FILENAME_STUDENTS "students.txt"
#define FILENAME_COURSES "courses.txt"
#define FILENAME_COURSE_SECTIONS "course_sections.txt"

char enter;

struct Student
{
    int student_id;
    char name[50];
};

struct Course
{
    char course_code[10];
    char course_name[50];
    int num_sections;
};

struct course_section_information
{
    char course_code[10];
    int section;
    char student_id[10];
    int marks;
    char grade;
};


void printStudent(struct Student s);
void printCourse(struct Course c);
void addStudent();
void addCourse();
void searchStudent();
void searchCourse();
void updateStudent();
void updateCourse();
void deleteStudent();
void deleteCourse();
void create_course_section_information();
void read_course_section_information();
void showAllStudent();
void showAllCourses();

int main()
{
    int choice;

    do
    {
        printf("Main Menu\n");
        printf("1. Add Student\n");
        printf("2. Add Course\n");
        printf("3. Search Student\n");
        printf("4. Search Course\n");
        printf("5. Update Student\n");
        printf("6. Update Course\n");
        printf("7. Delete Student\n");
        printf("8. Delete Course\n");
        printf("9. Add Course Section Information\n");
        printf("10. Read Course Section Information\n");
        printf("11. Show All Student\n");
        printf("12. Show All Courses\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            addCourse();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            searchCourse();
            break;
        case 5:
            updateStudent();
            break;
        case 6:
            updateCourse();
            break;
        case 7:
            deleteStudent();
            break;
        case 8:
            deleteCourse();
            break;
        case 9:
            create_course_section_information();
            break;
        case 10:
            read_course_section_information();
            break;
        case 11:
            showAllStudent();
            break;
        case 12:
            showAllCourses();
            break;
        case 13:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }
    while (choice != 13);

    return 0;
}

void printStudent(struct Student s)
{
    printf("--------------------------------\n");
    printf("Student ID: %d\n", s.student_id);
    printf("Name: %s\n", s.name);
    printf("--------------------------------\n");
}

void printCourse(struct Course c)
{
    printf("--------------------------------\n");
    printf("Course Code: %s\n", c.course_code);
    printf("Course Name: %s\n", c.course_name);
    printf("Number of Sections: %d\n", c.num_sections);
    printf("--------------------------------\n");
}

void addStudent()
{
    struct Student s;
    FILE *fp;

    printf("Enter student ID: ");
    scanf("%d", &s.student_id);
    scanf("%c", &enter);

    printf("Enter student name: ");
    scanf("%[^\n]s", s.name);

    fp = fopen(FILENAME_STUDENTS, "a");
    fprintf(fp, "%d,%s\n", s.student_id, s.name);
    fclose(fp);

    printf("Student added successfully.\n");
}

void addCourse()
{
    struct Course c;
    FILE *fp;

    printf("Enter course code: ");
    scanf("%s", &c.course_code);
    scanf("%c", &enter);

    printf("Enter course name: ");
    scanf("%[^\n]s", c.course_name);
    scanf("%c", &enter);

    printf("Enter number of sections: ");
    scanf("%d", &c.num_sections);

    fp = fopen(FILENAME_COURSES, "a");
    fprintf(fp, "%s,%s,%d\n", c.course_code, c.course_name, c.num_sections);
    fclose(fp);

    printf("Course added successfully.\n");
}

void searchStudent()
{
    int student_id, found = 0;
    struct Student s;
    FILE *fp;

    printf("Enter student ID to search: ");
    scanf("%d", &student_id);

    fp = fopen(FILENAME_STUDENTS, "r");
    while (fscanf(fp, "%d,%[^\n]s", &s.student_id, s.name) != EOF)
    {
        if (s.student_id == student_id)
        {
            found = 1;
            printStudent(s);
            break;
        }
    }
    fclose(fp);

    if (!found)
    {
        printf("Student with ID %d not found.\n", student_id);
    }
}

void searchCourse()
{
    char course_code[10];
    int found = 0;
    struct Course c;
    FILE *fp;
    printf("Enter course code to search: ");
    scanf("%s", &course_code);

    fp = fopen(FILENAME_COURSES, "r");
    while (fscanf(fp, "%[^,],%[^,],%d\n", c.course_code, c.course_name, &c.num_sections) != EOF)
    {
        if (strcmp(c.course_code, course_code) == 0)
        {
            found = 1;
            printCourse(c);
            break;
        }
    }
    fclose(fp);

    if (!found)
    {
        printf("Course with code %s not found.\n", course_code);
    }
}

void updateStudent()
{
    int student_id, found = 0;
    struct Student s, updated_s;
    FILE *fp, *fp_tmp;
    printf("Enter student ID to update: ");
    scanf("%d", &student_id);
    scanf("%c", &enter);

    fp = fopen(FILENAME_STUDENTS, "r");
    fp_tmp = fopen("tmp.txt", "w");

    while (fscanf(fp, "%d,%[^\n]s", &s.student_id, s.name) != EOF)
    {
        if (s.student_id == student_id)
        {
            found = 1;

            printf("Enter updated student name: ");
            scanf("%[^\n]s", updated_s.name);

            fprintf(fp_tmp, "%d,%s\n", s.student_id, updated_s.name);

            printf("Student with ID %d updated successfully.\n", student_id);
        }
        else
        {
            fprintf(fp_tmp, "%d,%s\n", s.student_id, s.name);
        }
    }

    fclose(fp);
    fclose(fp_tmp);

    remove(FILENAME_STUDENTS);
    rename("tmp.txt", FILENAME_STUDENTS);

    if (!found)
    {
        printf("Student with ID %d not found.\n", student_id);
    }
}

void updateCourse()
{
    char course_code[10];
    int found = 0;
    struct Course c, updated_c;
    FILE *fp, *fp_tmp;
    printf("Enter course code to update: ");
    scanf("%s", course_code);
    scanf("%c", &enter);

    fp = fopen(FILENAME_COURSES, "r");
    fp_tmp = fopen("tmp.txt", "w");

    while (fscanf(fp, "%[^,],%[^,],%d\n", c.course_code, c.course_name, &c.num_sections) != EOF)
    {
        if (strcmp(c.course_code, course_code) == 0)
        {
            found = 1;

            printf("Enter updated course name: ");
            scanf("%[^\n]s", updated_c.course_name);
            scanf("%c", &enter);

            printf("Enter updated number of sections: ");
            scanf("%d", &updated_c.num_sections);

            fprintf(fp_tmp, "%s,%s,%d\n", c.course_code, updated_c.course_name, updated_c.num_sections);
            printf("--------------------------------\n");
            printf("Course with code %s updated successfully.\n", course_code);
            printf("--------------------------------\n");
        }
        else
        {
            fprintf(fp_tmp, "%s,%s,%d\n", c.course_code, c.course_name, c.num_sections);
        }
    }
    fclose(fp);
    fclose(fp_tmp);

    remove(FILENAME_COURSES);
    rename("tmp.txt", FILENAME_COURSES);

    if (!found)
    {
        printf("Course with code %s not found.\n", course_code);
    }

}

void deleteStudent()
{
    int student_id, found = 0;
    struct Student s;
    FILE *fp, *fp_tmp;
    printf("Enter student ID to delete: ");
    scanf("%d", &student_id);

    fp = fopen(FILENAME_STUDENTS, "r");
    fp_tmp = fopen("tmp.txt", "w");

    while (fscanf(fp, "%d,%[^\n]s", &s.student_id, s.name) != EOF)
    {
        if (s.student_id == student_id)
        {
            found = 1;
            printf("Student with ID %d deleted successfully.\n", student_id);
        }
        else
        {
            fprintf(fp_tmp, "%d,%s\n", s.student_id, s.name);
        }
    }

    fclose(fp);
    fclose(fp_tmp);

    remove(FILENAME_STUDENTS);
    rename("tmp.txt", FILENAME_STUDENTS);

    if (!found)
    {
        printf("Student with ID %d not found.\n", student_id);
    }

}

void deleteCourse()
{
    char course_code[10];
    int found = 0;
    struct Course c;
    FILE *fp, *fp_tmp;
    printf("Enter course code to delete: ");
    scanf("%s", &course_code);

    fp = fopen(FILENAME_COURSES, "r");
    fp_tmp = fopen("tmp.txt", "w");

    while (fscanf(fp, "%[^,],%[^,],%d\n", &c.course_code, c.course_name, &c.num_sections) != EOF)
    {
        if (strcmp(c.course_code, course_code) == 0)
        {
            found = 1;
            printf("Course with code %s deleted successfully.\n", course_code);
        }
        else
        {
            fprintf(fp_tmp, "%s,%s,%d\n", c.course_code, c.course_name, c.num_sections);
        }
    }

    fclose(fp);
    fclose(fp_tmp);

    remove(FILENAME_COURSES);
    rename("tmp.txt", FILENAME_COURSES);

    if (!found)
    {
        printf("Course with code %d not found.\n", course_code);
    }
}

void create_course_section_information()
{
    struct course_section_information csi;
    struct course;
    struct student;

    printf("Enter course code: ");
    scanf("%s", csi.course_code);

    printf("Enter section: ");
    scanf("%d", &csi.section);

    printf("Enter student ID: ");
    scanf("%s", csi.student_id);

    printf("Enter marks: ");
    scanf("%d", &csi.marks);

    if (csi.marks >= 90)
    {
        csi.grade = 'A';
    }
    else if (csi.marks >= 80)
    {
        csi.grade = 'B';
    }
    else if (csi.marks >= 70)
    {
        csi.grade = 'C';
    }
    else if (csi.marks >= 60)
    {
        csi.grade = 'D';
    }
    else
    {
        csi.grade = 'F';
    }

    FILE* fp = fopen("course_section_information.txt", "a");
    fprintf(fp, "%s %d %s %d %c\n", csi.course_code, csi.section, csi.student_id, csi.marks, csi.grade);
    fclose(fp);
}

void read_course_section_information()
{
    struct course_section_information csi;
    printf("Course Code\tSection\tStudent ID\tMarks\tGrade\n");

    FILE* fp = fopen("course_section_information.txt", "r");
    while (fscanf(fp, "%s %d %s %d %c", csi.course_code, &csi.section, csi.student_id, &csi.marks, &csi.grade) == 5)
    {
        printf("%s\t\t%d\t%s\t\t%d\t%c\n", csi.course_code, csi.section, csi.student_id, csi.marks, csi.grade);
    }
    fclose(fp);
}

void showAllStudent()
{
    struct Student s;
    FILE *fp;

    fp = fopen(FILENAME_STUDENTS, "r");

    while (fscanf(fp, "%d,%[^\n]s", &s.student_id, s.name) != EOF)
    {
        printStudent(s);
    }

    fclose(fp);
}


void showAllCourses()
{
    struct Course c;
    FILE *fp;
    fp = fopen(FILENAME_COURSES, "r");
    while (fscanf(fp, "%[^,],%[^,],%d\n", c.course_code, c.course_name, &c.num_sections) != EOF)
    {
        printCourse(c);
    }
    fclose(fp);
}


