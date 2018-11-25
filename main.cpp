#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int stuNum;

struct student
{
    char name[10]; //学生名字
    int studentNum; //学号
    char sex[5]; //性别
    char birth[15]; //出生年月日
    char inClass[20]; //班级
    char phoneNum[20]; //电话号码

} student[100];

//封面
void cover()
{
    int b;
    for(b = 0; b < 5; b++)
    {
        printf("\n");
    }
    printf("\t\t\t***学生学籍管理系统***\n");
    printf("\t\t\t1 输入学生学籍信息\n\n");
    printf("\t\t\t2 查看学生学籍信息\n\n");
    printf("\t\t\t3 删除学生学籍信息\n\n");
    printf("\t\t\t4 更改学生学籍信息\n\n");
    printf("\t\t\t5 退出");
    printf("\n\n");
    printf("请输入要操作的选项(1~5) ");
}

//输入学生信息 第一个选项
void WriteIn()
{
    system("cls"); //清屏函数
    int b;
    int num;
    for(b = 0; b < 5; b++)
    {
        printf("\n");
    }
    printf("\t\t\t***学生学籍管理系统***\n\n");
    printf("\t请输入需要输入的学生信息数量： ");
    scanf("%d",&num);
    int i;
    for(i = 0; i < num; i++)
    {
        printf("\t请输入学生姓名： ");
        scanf("%s",student[stuNum].name);
        printf("\t请输入学生学号： ");
        scanf("%d",&student[stuNum].studentNum);
        printf("\t请输入学生性别： ");
        scanf("%s",student[stuNum].sex);
        printf("\t请输入学生出生日期(YY/MM/DD)： ");
        scanf("%s",student[stuNum].birth);
        printf("\t请输入学生班级： ");
        scanf("%s",student[stuNum].inClass);
        printf("%s", student[stuNum].inClass);
        printf("\t请输入学生手机号： ");
        scanf("%s",student[stuNum].phoneNum);
        printf("%s", student[stuNum].phoneNum);
        stuNum++;
        printf("\n");
    }
    for(b = 0; b < 3; b++)
    {
        printf("\n");
    }
    printf("输入完成");
    Sleep(1000);
    system("cls");
    cover();
}

void show()
{
    system("cls");
    int b, i;
    for(b = 0; b < 5; b++)
    {
        printf("\n");
    }
    printf("\t\t\t***学生学籍管理系统***\n\n");
    printf("姓名\t\t学号\t\t性别\t\t出生日期\t\t电话号码\t\t班级\n");
    for(i = 0; i < stuNum; i++)
    {
        if(student[i].studentNum == -1) //已经删除的学生
        {
            continue;
        }
        printf("%s\t\t", student[i].name);
        printf("%d\t",student[i].studentNum);
        printf("%s\t\t",student[i].sex);
        printf("%s\t\t", student[i].birth);
        printf("%s\t\t", student[i].phoneNum);
        printf("%s", student[i].inClass);
        printf("\n\n");
    }
    for(b = 0; b < 3; b++)
    {
        printf("\n");
    }
    printf("按回车键返回....");
    getchar();
    getchar();
    system("cls");
    cover();
}

void Del()
{
    char an[10]; //询问是否继续字符串
    int i,b;
    char dName[10];
    int tag = 0;
    do
    {
        system("cls");
        for(b = 0; b < 5; b++)
        {
            printf("\n");
        }
        printf("\t\t\t***学生学籍管理系统***\n\n");
        printf("\t请输入需要删除的学生的姓名： ");
        scanf("%s", dName);
        for(i = 0; i < stuNum; i++)
        {
            if(strcmp(student[i].name, dName) == 0)
            {
                student[i].studentNum = -1; //把学号设置为-1 当作删除，show()时判断
                tag = 1;
                break;
            }
        }
        for(b = 0; b < 2; b++)
        {
            printf("\n");
        }
        if(tag == 1)
        {
            printf("删除成功！");
        }
        else
        {
            printf("删除失败，没有学生信息！");
        }
        printf("\n是否继续更改信息？(yes or no)...");
        scanf("%s", an);
    }
    while(strcmp(an, "yes") == 0);
    printf("按回车键返回....");
    getchar();
    getchar();
    system("cls");
    cover();
}

void ReWrite()
{
    char an[10];
    int index;
    int b, i;
    char Rname[10];
    do
    {
        system("cls");
        for(b = 0; b < 5; b++)
        {
            printf("\n");
        }
        printf("\t\t\t***学生学籍管理系统***\n\n");
        printf("\t请输入需要更改信息的学生姓名： ");
        scanf("%s", Rname);
        for(i = 0; i < stuNum; i++)
        {
            if(strcmp(student[i].name, Rname)== 0)
            {
                index = i;
            }
        }
        printf("请输入学生姓名： ");
        scanf("%s",student[index].name);
        printf("请输入学生学号： ");
        scanf("%d",&student[index].studentNum);
        printf("请输入学生性别： ");
        scanf("%s",student[index].sex);
        printf("请输入学生出生日期(YY/MM/DD)： ");
        scanf("%s",student[index].birth);
        printf("请输入学生班级： ");
        scanf("%s",student[index].inClass);
        printf("请输入学生手机号： ");
        scanf("%s", &student[index].phoneNum);
        printf("\n更改信息成功！\n\n");
        printf("是否继续更改信息？(yes or no)...");
        scanf("%s", an);
    }
    while(strcmp(an, "yes") == 0);
    system("cls");
    cover();
}

int main()
{
    cover();
    stuNum = 0;
    int option;
    while(scanf("%d",&option))
    {
        if(option == 5)
        {
            system("cls");
            for(option = 0; option < 5; option++)
            {
                printf("\n");
            }
            printf("\t\t\t\t谢谢使用\n\n");
            exit(-1);
        }
        switch(option)
        {
            case 1:
                WriteIn();
                break;
            case 2:
                show();
                break;
            case 3:
                Del();
                break;
            case 4:
                ReWrite();
                break;
        }
    }
    return 0;
}
