#include <stdio.h>

FILE* file=NULL;

typedef struct 
{
    int id;
    char name[20];
    float grade[3];
}Student;

void getStudentAverageGrade(Student* students)
{
    float sum=0;
    for(int i=0;i<3;++i)
        sum+=students->grade[i];
    sum/=3;
    printf("Student:%s (ID:%d) AverageGrade is : %f\n",students->name,students->id,sum);
    fprintf(file,"Student:%s (ID:%d) AverageGrade is : %f\n",students->name,students->id,sum);
}

void getCourseAverageGrade(Student* students,int coursenum)
{
    float sum=0;
    for(int i=0;i<3;++i)
        sum+=students[i].grade[coursenum];
    sum/=3;
    printf("Course:%d AverageGrade is : %f\n",coursenum,sum);
    fprintf(file,"Course:%d AverageGrade is : %f\n",coursenum,sum);
}

void getBestGrade(Student* student)
{
    Student best=student[0];
    int bestcourse=0;
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            if(student[i].grade[j]>best.grade[bestcourse])
            {
                best=student[i];
                bestcourse=j;
            }
        }   
    }
    printf("The best grade is %f in course: %d , %s (ID:%d) got it",best.grade[bestcourse],bestcourse,best.name,best.id);
    fprintf(file,"The best grade is %f in course: %d , %s (ID:%d) got it",best.grade[bestcourse],bestcourse,best.name,best.id);
}

int main(void)
{
    FILE* partial_file=fopen("out.txt","w");
    file=partial_file;
    if(file==NULL)
    {
        printf("Fail to open file\n");
        return 0;
    }
    Student students[3];
    for(int i=0;i<3;++i) 
        scanf("%d%s%f%f%f",&students[i].id,students[i].name,&students[i].grade[0],&students[i].grade[1],&students[i].grade[2]);
    for(int i=0;i<3;++i)
        getStudentAverageGrade(&students[i]);
    for(int i=0;i<3;++i)
        getCourseAverageGrade(students,i);
    getBestGrade(students);
    fclose(file);
    return 0;
}