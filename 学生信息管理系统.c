#include <stdio.h>
#include <stdlib.h>  
#include <string.h> 

#define MAX_SIZE 100

typedef struct {
    int sno;          // ѧ��
    char sname[20];  // ����
    char sex[10];    // �Ա�
    int age;         // ����
} Student;

typedef struct {  
    Student students[MAX_SIZE];  
    int size;  
} StudentList;  

// �˵�
void Menu() 
{
    printf("�˵���\n");
    printf("1. ��ʾȫ��ѧ����Ϣ\n");
    printf("2. ����ѧ����Ϣ\n");
    printf("3. �޸�ѧ����Ϣ\n");
    printf("4. ɾ��ѧ����Ϣ\n");
    printf("5. ��ѧ�Ų�ѯѧ����Ϣ\n");
    printf("6. ������ѯѧ����Ϣ\n");
    printf("7. �˳�\n");
}

// ��ʼ��ѧ����Ϣ��  
void InitList(StudentList *list) 
{  
    list->size = 0;  
}  

// ���ѧ�� 
void AddList(StudentList *list, int count) 
{
	int i=0;
    for (i = 0; i < count; i++) 
	{  
        if (list->size < MAX_SIZE) 
		{  
            int sno;  
            char sname[20];  
            char sex[10];
            int age;  

            printf("����� %d ��ѧ����ѧ��: ", i + 1);  
            scanf("%d", &sno);  
            printf("����� %d ��ѧ��������: ", i + 1);  
            scanf("%s", sname);  
            printf("����� %d ��ѧ�����Ա�: ", i + 1);  
            scanf("%s", sex);  
            printf("����� %d ��ѧ��������: ", i + 1);  
            scanf("%d", &age);  

            list->students[list->size].sno = sno;  
            strcpy(list->students[list->size].sname, sname);  
            strcpy(list->students[list->size].sex, sex);
            list->students[list->size].age = age;  
            list->size++;  
        } 
		else 
		{  
            printf("ѧ����Ϣ���������޷���Ӹ���ѧ����\n");  
            break;  
        }  
    }  
}

// ��ӡ����ѧ����Ϣ
void PrintList(StudentList *list) 
{
	int i=0;
    printf("����ѧ����Ϣ��ʾ����:\n");
    for (i = 0; i < list->size; i++) 
	{
		printf("����ѧ����ѧ��: ");
        printf("%d\n", list->students[i].sno);
        printf("����ѧ��������: ");
        printf("%s\n", list->students[i].sname);
        printf("����ѧ�����Ա�: ");
        printf("%s\n", list->students[i].sex);
        printf("����ѧ��������: ");
        printf("%d\n", list->students[i].age);
    }
}

//�޸�ѧ����Ϣ 
void ModifyList(StudentList *list)
{
	int i=0;
	int flag=0;
	int no;
	printf("����Ҫ�޸ĵ�ѧ����ѧ�ţ�");
	scanf("%d",&no);
	for(i=0; i<list->size; i++)
	{
		if(list->students[i].sno==no)
		{
			flag=1;
			
			scanf("%d %s %s %d",&list->students[i].sno,&list->students[i].sname,&list->students[i].sex,&list->students[i].age);
	        printf("��Ϣ�޸ĳɹ�");
		}
	}
	if(flag==0)
    {
    	printf("������ѧ��Ϊ %d ��ѧ����\n",no);
	}
}

//ɾ��ѧ����Ϣ
void DeleteList(StudentList *list) 
{
	int i,j;
	int flag=0;
	int no;
	printf("����Ҫɾ����ѧ����ѧ�ţ�");
	scanf("%d",&no); 
	for(i=0; i<list->size; i++)
	{
		if(list->students[i].sno==no)
		{
			flag=1;
			for(j=i; j<list->size-1; j++)
	        {
		        /*
				list->students[j].sno=list->students[j+1].sno;
		        strcpy(list->students[j].sname, list->students[j+1].sname);  
                strcpy(list->students[j].sex, list->students[j+1].sex);  
		        list->students[j].age=list->students[j+1].age;
		        */
		        list->students[j] = list->students[j+1]; // ֱ�Ӹ��ƽṹ�� 
	        }
	        list->size--; // ����ѧ������  
	        printf("ѧ��Ϊ %d ��ѧ����Ϣ��ɾ����\n", no);  
		}
    }
    if(flag==0)
    {
    	printf("������ѧ��Ϊ %d ��ѧ����\n",no);
	}
}

//��ѧ�Ų�ѯ��Ψһ����� 
void SearchList_No(StudentList *list)
{
	int i;
	int no;
	int flag=0;
	printf("����Ҫ��ѯ��ѧ����ѧ�ţ�");
	scanf("%d",&no); 
	for(i=0; i<list->size; i++)
	{
		if(list->students[i].sno == no)
		{
			flag=1;
			printf("��ѧ������Ϣ������ʾ��\n");
			printf("%d  %s  %s  %d\n", list->students[i].sno, list->students[i].sname, list->students[i].sex, list->students[i].age);  
		}
	}
	if(flag==0)
    {
    	printf("������ѧ��Ϊ %d ��ѧ����\n",no);
	}
}

//��������ѯ����Ψһ�����
void SearchList_Name(StudentList *list)
{
	int i;
	char name[20];
	int flag=0;
	printf("����Ҫ��ѯ��ѧ����������");
	scanf("%s",name); 
	for(i=0; i<list->size; i++)
	{
		if(strcmp(list->students[i].sname,name) == 0)
		{
			flag=1;
			printf("��ѧ������Ϣ������ʾ��\n");
			printf("%d  %s  %s  %d\n", list->students[i].sno, list->students[i].sname, list->students[i].sex, list->students[i].age);  
		}
	}
	if(flag==0)
    {
    	printf("����������Ϊ %s ��ѧ����\n",name);
	}
}

int main() 
{
    StudentList list;  
    InitList(&list);  

    int choice;
    do {
        Menu();  // ��ʾ�˵�
        printf("��ѡ�����: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1: 
			{
                PrintList(&list);
                system("pause");
                system("cls");
                break;
            }
            case 2: 
			{
                int count;
                printf("����Ҫ��ӵ�ѧ������: ");  
                scanf("%d", &count);  
                AddList(&list, count); 
                system("pause");
				system("cls"); 
                break;
            }
            case 3:
			{
				ModifyList(&list);
				system("pause");
				system("cls"); 
                break;
			} 
            case 4:
            {
            	DeleteList(&list);
                system("pause");
            	system("cls");
            	break;
			}
            case 5:
            {
            	SearchList_No(&list);
                system("pause");
            	system("cls");
            	break;
			}
			case 6:
            {
            	SearchList_Name(&list);
                system("pause");
            	system("cls");
            	break;
			}
            case 7: 
			{
                printf("�˳�����\n");
                break;
            }
            default: 
			{
                printf("��Ч��ѡ�����������롣\n");
                break;
            }
        }
    } while (choice != 7);

    return 0;
}


