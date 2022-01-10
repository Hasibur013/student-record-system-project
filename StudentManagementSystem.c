/**
    Md. Hasibur Rahman
*/

#include<stdio.h>
#include<conio.h>


//Structure of students file
typedef struct
{
    int Student_ID;
    char full_name[20];
    char father_name[20];
    char mother_name[20];
    int age;
} StudentInfo;


// function prototype
void login();
void addStudentsInfo(StudentInfo Student_DB[], int StudentCount);
void updateStudentsInfo(StudentInfo Student_DB[], int StudentCount);
void findStudentsInfo(StudentInfo Student_DB[], int StudentCount);
void countStudents(int StudentCount);
void printDB(StudentInfo Student_DB[], int StudentCount);
void ReadDB(FILE *file, StudentInfo Student_DB[], int *StudentCount);
void WriteDB(FILE *file, StudentInfo Student_DB[], int StudentCount);


// main function
int main()
{
    login();
    StudentInfo Student_DB[1000];

    int StudentCount = 0, option;

    FILE *file;

    //open file from the database file
    file = fopen("StudentManagement.txt", "r");

    if(file!=NULL)
    {
        ReadDB(file, Student_DB, &StudentCount);     // read file
        fclose(file);      // close file
    }

    printf("\n\n\n");
    printf("\t\t\t***********************************************************************\n");
    printf("\t\t\t***                                                                 ***\n");
    printf("\t\t\t***   Student Information Management System for 1000 Students       ***\n");
    printf("\t\t\t***                                                                 ***\n");
    printf("\t\t\t***********************************************************************\n");

    printf("\n\n\n\n");

    //loop for display the menu
    while(1)
    {
        printf("\n\t\t\t1 >> Add student Info");
        printf("\n\t\t\t2 >> Update Student Info");
        printf("\n\t\t\t3 >> Find Student Info by ID");
        printf("\n\t\t\t4 >> Total Students");
        printf("\n\t\t\t5 >> Print All Students Database");
        printf("\n\t\t\t6 << Exit");

        printf("\n\n\n");

        printf("\t\t\tEnter option: ");
        scanf("%d", &option);

        if(option==6)
            break;

        switch(option)
        {
        case 1:
            addStudentsInfo(Student_DB, StudentCount);
            StudentCount++;
            break;

        case 2:
            updateStudentsInfo(Student_DB, StudentCount);
            break;

        case 3:
            findStudentsInfo(Student_DB, StudentCount);
            break;

        case 4:
            countStudents(StudentCount);
            break;

        case 5:
            printDB(Student_DB, StudentCount);
            break;
        }
    }


    file = fopen("StudentManagement.txt", "w+");    //open the file

    WriteDB(file, Student_DB, StudentCount);     //write the file

    fclose(file);    //close the file


    return 0;
}

void login()
{
    char username[15];
    char password[12];


    printf("\t\t\t\t\tEnter username: ");
    scanf("%s",&username);

    printf("\t\t\t\t\tEnter your password: ");
    scanf("%s",&password);

    if(strcmp(username,"student")==0)
    {
        if(strcmp(password,"student")==0)
        {

            printf("\n\t\t\t\t\tWelcome.Login Success!");


        }
        else
        {
            printf("\n\t\t\t\t\twrong password");
        }
    }
    else
    {
        printf("\n\t\t\t\t\tUser doesn't exist");
    }
}

// function (addStudentsInfo)
void addStudentsInfo(StudentInfo Student_DB[], int StudentCount)
{
    StudentInfo students;
    int fileCheck, i;

    // check for the uniqueness of the students
    do
    {
        printf("\n\t\t\tStudents ID: ");
        scanf("%d", &students.Student_ID);
        fileCheck = 0;
        for(i=0; i<StudentCount; i++)
        {
            if(Student_DB[i].Student_ID == students.Student_ID)
            {
                printf("\n\t\t\tThis students's ID already exist! Please try another\n");
                fileCheck = 1;
            }
        }
    }
    while(fileCheck != 0);

    printf("\t\t\tName of the students: ");
    scanf(" %[^\n]",students.full_name);
    printf("\t\t\tName of Father's Name: ");
    scanf(" %[^\n]",students.father_name);
    printf("\t\t\tName of Mother's Name: ");
    scanf(" %[^\n]",students.mother_name);
    printf("\t\t\tEnter students Age: ");
    scanf("%d", &students.age);

    Student_DB[StudentCount] = students;
}

// function (updateStudentsInfo)
void updateStudentsInfo(StudentInfo Student_DB[], int StudentCount)
{
    int id, i, option;

    printf("\t\t\tEnter Id to update info: ");
    scanf("%d", &id);

    for(i=0; i<StudentCount; i++)
    {
        if(Student_DB[i].Student_ID == id)
        {
            printf("\n\t\t\t\t1 >> Update Student's Name: ");
            printf("\n\t\t\t\t2 >> Update Father's Name: ");
            printf("\n\t\t\t\t3 >> Update Mother's Name: ");
            printf("\n\t\t\t\t4 >> Update Age: ");
            printf("\n\n\t\t\t\tEnter a option to update: ");
            scanf("%d", &option);

            if(option==1)
            {
                printf("\t\t\t\t\t\tUpdated name: ");
                scanf(" %[^\n]",Student_DB[i].full_name);
            }
            else if(option=2)
            {
                printf("\t\t\t\t\t\tUpdated Father Name: ");
                scanf(" %[^\n]",Student_DB[i].father_name);
            }
            else if(option=3)
            {
                printf("\t\t\t\t\t\tUpdated Mother Name: ");
                scanf(" %[^\n]",Student_DB[i].mother_name);
            }
            else if(option=4)
            {
                printf("\t\t\t\tUpdated Age: ");
                scanf("%d", &Student_DB[i].age);
            }
            return;
        }
    }
    printf("\n\n\t\t\tNot found! Please Enter a valid ID\n");
}

// function (findStudentsInfo)
void findStudentsInfo(StudentInfo Student_DB[], int StudentCount)
{
    int i, id;

    printf("\n\t\t\tEnter students ID to show Details Info: ");
    scanf("%d", &id);

    for(i=0; i<StudentCount; i++)
    {
        if(Student_DB[i].Student_ID == id)
        {
            printf("\n\t\t\t\t\tStudent's ID :  %d\n", Student_DB[i].Student_ID);
            printf("\t\t\t\t\tStudent's Name:  %s\n", Student_DB[i].full_name);
            printf("\t\t\t\t\tStudent's Father Name:  %s\n", Student_DB[i].father_name);
            printf("\t\t\t\t\tStudent's Mother Name:  %s\n", Student_DB[i].mother_name);
            printf("\t\t\t\t\tAge :  %d\n", Student_DB[i].age);
            return;
        }
    }
    printf("\n\n\t\t\tNot found! Please Enter a valid ID\n");
}

// function (countStudents)
void countStudents(int StudentCount)
{
    printf("\n\t\t\t*****************************\n");
    printf("\t\t\t**                         **\n");
    printf("\t\t\t**   Total students = %d   **\n", StudentCount);
    printf("\t\t\t**                         **\n");
    printf("\t\t\t*****************************\n");
}

// function (printDB)
void printDB(StudentInfo Student_DB[], int StudentCount)
{
    int i;

    printf("\n\t\t\t************************************************************************\n");
    printf("\t\t\tStudentsName       FathersName         MothersName         ID       Age \n");
    printf("\t\t\t************************************************************************\n");
    for(i=0; i<StudentCount; i++)
    {
        printf("\t\t\t%-15s%-15s%-15s%-15d%d\n",Student_DB[i].full_name,Student_DB[i].father_name, Student_DB[i].mother_name, Student_DB[i].Student_ID, Student_DB[i].age);
    }
}

// function (ReadDB)
void ReadDB(FILE *file, StudentInfo Student_DB[], int *StudentCount)
{
    char line_for_student_info[1000];
    int i = 0;

    while(!feof(file))
    {
        fgets(Student_DB[i].full_name, 20, file);
        if (feof(file))
            break;
        fgets(Student_DB[i].father_name, 20, file);
        if (feof(file))
            break;
        fgets(Student_DB[i].mother_name, 20, file);
        if (feof(file))
            break;
        fscanf(file, "%d%d\n", &Student_DB[i].Student_ID, &Student_DB[i].age);
        i++;
    }
    *StudentCount = i;
}

// function (WriteDB)
void WriteDB(FILE *file, StudentInfo Student_DB[], int StudentCount)
{
    int i;
    for(i=0; i<StudentCount; i++)
    {
        fprintf(file, "%-20s\t%s\t%s\t%d\t%d\n",Student_DB[i].full_name,Student_DB[i].father_name, Student_DB[i].mother_name,Student_DB[i].Student_ID, Student_DB[i].age);
    }
}

