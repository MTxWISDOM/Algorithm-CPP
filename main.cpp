#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int stuNum;

struct student
{
    char name[10]; //ѧ������
    int studentNum; //ѧ��
    char sex[5]; //�Ա�
    char birth[15]; //����������
    char inClass[20]; //�༶
    char phoneNum[20]; //�绰����

} student[100];

//����
void cover()
{
    int b;
    for(b = 0; b < 5; b++)
    {
        printf("\n");
    }
    printf("\t\t\t***ѧ��ѧ������ϵͳ***\n");
    printf("\t\t\t1 ����ѧ��ѧ����Ϣ\n\n");
    printf("\t\t\t2 �鿴ѧ��ѧ����Ϣ\n\n");
    printf("\t\t\t3 ɾ��ѧ��ѧ����Ϣ\n\n");
    printf("\t\t\t4 ����ѧ��ѧ����Ϣ\n\n");
    printf("\t\t\t5 �˳�");
    printf("\n\n");
    printf("������Ҫ������ѡ��(1~5) ");
}

//����ѧ����Ϣ ��һ��ѡ��
void WriteIn()
{
    system("cls"); //��������
    int b;
    int num;
    for(b = 0; b < 5; b++)
    {
        printf("\n");
    }
    printf("\t\t\t***ѧ��ѧ������ϵͳ***\n\n");
    printf("\t��������Ҫ�����ѧ����Ϣ������ ");
    scanf("%d",&num);
    int i;
    for(i = 0; i < num; i++)
    {
        printf("\t������ѧ�������� ");
        scanf("%s",student[stuNum].name);
        printf("\t������ѧ��ѧ�ţ� ");
        scanf("%d",&student[stuNum].studentNum);
        printf("\t������ѧ���Ա� ");
        scanf("%s",student[stuNum].sex);
        printf("\t������ѧ����������(YY/MM/DD)�� ");
        scanf("%s",student[stuNum].birth);
        printf("\t������ѧ���༶�� ");
        scanf("%s",student[stuNum].inClass);
        printf("%s", student[stuNum].inClass);
        printf("\t������ѧ���ֻ��ţ� ");
        scanf("%s",student[stuNum].phoneNum);
        printf("%s", student[stuNum].phoneNum);
        stuNum++;
        printf("\n");
    }
    for(b = 0; b < 3; b++)
    {
        printf("\n");
    }
    printf("�������");
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
    printf("\t\t\t***ѧ��ѧ������ϵͳ***\n\n");
    printf("����\t\tѧ��\t\t�Ա�\t\t��������\t\t�绰����\t\t�༶\n");
    for(i = 0; i < stuNum; i++)
    {
        if(student[i].studentNum == -1) //�Ѿ�ɾ����ѧ��
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
    printf("���س�������....");
    getchar();
    getchar();
    system("cls");
    cover();
}

void Del()
{
    char an[10]; //ѯ���Ƿ�����ַ���
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
        printf("\t\t\t***ѧ��ѧ������ϵͳ***\n\n");
        printf("\t��������Ҫɾ����ѧ���������� ");
        scanf("%s", dName);
        for(i = 0; i < stuNum; i++)
        {
            if(strcmp(student[i].name, dName) == 0)
            {
                student[i].studentNum = -1; //��ѧ������Ϊ-1 ����ɾ����show()ʱ�ж�
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
            printf("ɾ���ɹ���");
        }
        else
        {
            printf("ɾ��ʧ�ܣ�û��ѧ����Ϣ��");
        }
        printf("\n�Ƿ����������Ϣ��(yes or no)...");
        scanf("%s", an);
    }
    while(strcmp(an, "yes") == 0);
    printf("���س�������....");
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
        printf("\t\t\t***ѧ��ѧ������ϵͳ***\n\n");
        printf("\t��������Ҫ������Ϣ��ѧ�������� ");
        scanf("%s", Rname);
        for(i = 0; i < stuNum; i++)
        {
            if(strcmp(student[i].name, Rname)== 0)
            {
                index = i;
            }
        }
        printf("������ѧ�������� ");
        scanf("%s",student[index].name);
        printf("������ѧ��ѧ�ţ� ");
        scanf("%d",&student[index].studentNum);
        printf("������ѧ���Ա� ");
        scanf("%s",student[index].sex);
        printf("������ѧ����������(YY/MM/DD)�� ");
        scanf("%s",student[index].birth);
        printf("������ѧ���༶�� ");
        scanf("%s",student[index].inClass);
        printf("������ѧ���ֻ��ţ� ");
        scanf("%s", &student[index].phoneNum);
        printf("\n������Ϣ�ɹ���\n\n");
        printf("�Ƿ����������Ϣ��(yes or no)...");
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
            printf("\t\t\t\tллʹ��\n\n");
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
