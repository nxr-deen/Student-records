#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char name[20];
    char affiliation[20];
    int regNumber;
};

int main()
{
    struct Student student;
    FILE *filePointer;

    // creating file
    filePointer = fopen("students.dat", "wb");
    if (filePointer == NULL)
    {
        printf("error");
        return -1;
    }

    // entring the students info
    int numStudents;
    printf("enter the number of students : \n");
    scanf("%d", &numStudents);

    for (int i = 0; i < numStudents; i++)
    {
        printf("\nenter the informations of student number %d \n", i + 1);
        printf("the name : \t");
        scanf("%s", student.name);
        printf("\nthe affiliation : \t");
        scanf("%s", student.affiliation);
        printf("\nthe registration number : \t");
        scanf("%d", &student.regNumber);
        fwrite(&student, sizeof(struct Student), 1, filePointer);
    }
    fclose(filePointer);

    // reading studenst info
    filePointer = fopen("students2.dat", "rb");
    if (filePointer == NULL)
    {
        printf("error");
        return -1;
    }
    printf("\nStored student information:\n");
    while (fread(&student, sizeof(struct Student), 1, filePointer))
    {
        printf("Name: %s\n", student.name);
        printf("Affiliation: %s\n", student.affiliation);
        printf("Registration Number: %d\n\n", student.regNumber);
    }

    fclose(filePointer);

    return 0;
}