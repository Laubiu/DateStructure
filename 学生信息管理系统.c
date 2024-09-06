#include <stdio.h>
#include <stdlib.h>  
#include <string.h> 

#define MAX_SIZE 100

typedef struct {
    int sno;          // 学号
    char sname[20];  // 姓名
    char sex[10];    // 性别
    int age;         // 年龄
} Student;

typedef struct {  
    Student students[MAX_SIZE];  
    int size;  
} StudentList;  

// 菜单
void Menu() 
{
    printf("菜单：\n");
    printf("1. 显示全体学生信息\n");
    printf("2. 插入学生信息\n");
    printf("3. 修改学生信息\n");
    printf("4. 删除学生信息\n");
    printf("5. 按学号查询学生信息\n");
    printf("6. 按名查询学生信息\n");
    printf("7. 退出\n");
}

// 初始化学生信息表  
void InitList(StudentList *list) 
{  
    list->size = 0;  
}  

// 添加学生 
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

            printf("输入第 %d 个学生的学号: ", i + 1);  
            scanf("%d", &sno);  
            printf("输入第 %d 个学生的姓名: ", i + 1);  
            scanf("%s", sname);  
            printf("输入第 %d 个学生的性别: ", i + 1);  
            scanf("%s", sex);  
            printf("输入第 %d 个学生的年龄: ", i + 1);  
            scanf("%d", &age);  

            list->students[list->size].sno = sno;  
            strcpy(list->students[list->size].sname, sname);  
            strcpy(list->students[list->size].sex, sex);
            list->students[list->size].age = age;  
            list->size++;  
        } 
		else 
		{  
            printf("学生信息表已满，无法添加更多学生。\n");  
            break;  
        }  
    }  
}

// 打印所有学生信息
void PrintList(StudentList *list) 
{
	int i=0;
    printf("所有学生信息显示如下:\n");
    for (i = 0; i < list->size; i++) 
	{
		printf("输入学生的学号: ");
        printf("%d\n", list->students[i].sno);
        printf("输入学生的姓名: ");
        printf("%s\n", list->students[i].sname);
        printf("输入学生的性别: ");
        printf("%s\n", list->students[i].sex);
        printf("输入学生的年龄: ");
        printf("%d\n", list->students[i].age);
    }
}

//修改学生信息 
void ModifyList(StudentList *list)
{
	int i=0;
	int flag=0;
	int no;
	printf("输入要修改的学生的学号：");
	scanf("%d",&no);
	for(i=0; i<list->size; i++)
	{
		if(list->students[i].sno==no)
		{
			flag=1;
			
			scanf("%d %s %s %d",&list->students[i].sno,&list->students[i].sname,&list->students[i].sex,&list->students[i].age);
	        printf("信息修改成功");
		}
	}
	if(flag==0)
    {
    	printf("不存在学号为 %d 的学生。\n",no);
	}
}

//删除学生信息
void DeleteList(StudentList *list) 
{
	int i,j;
	int flag=0;
	int no;
	printf("输入要删除的学生的学号：");
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
		        list->students[j] = list->students[j+1]; // 直接复制结构体 
	        }
	        list->size--; // 更新学生数量  
	        printf("学号为 %d 的学生信息已删除。\n", no);  
		}
    }
    if(flag==0)
    {
    	printf("不存在学号为 %d 的学生。\n",no);
	}
}

//按学号查询（唯一结果） 
void SearchList_No(StudentList *list)
{
	int i;
	int no;
	int flag=0;
	printf("输入要查询的学生的学号：");
	scanf("%d",&no); 
	for(i=0; i<list->size; i++)
	{
		if(list->students[i].sno == no)
		{
			flag=1;
			printf("该学生的信息如下所示：\n");
			printf("%d  %s  %s  %d\n", list->students[i].sno, list->students[i].sname, list->students[i].sex, list->students[i].age);  
		}
	}
	if(flag==0)
    {
    	printf("不存在学号为 %d 的学生。\n",no);
	}
}

//按姓名查询（不唯一结果）
void SearchList_Name(StudentList *list)
{
	int i;
	char name[20];
	int flag=0;
	printf("输入要查询的学生的姓名：");
	scanf("%s",name); 
	for(i=0; i<list->size; i++)
	{
		if(strcmp(list->students[i].sname,name) == 0)
		{
			flag=1;
			printf("该学生的信息如下所示：\n");
			printf("%d  %s  %s  %d\n", list->students[i].sno, list->students[i].sname, list->students[i].sex, list->students[i].age);  
		}
	}
	if(flag==0)
    {
    	printf("不存在姓名为 %s 的学生。\n",name);
	}
}

int main() 
{
    StudentList list;  
    InitList(&list);  

    int choice;
    do {
        Menu();  // 显示菜单
        printf("请选择操作: ");
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
                printf("输入要添加的学生数量: ");  
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
                printf("退出程序。\n");
                break;
            }
            default: 
			{
                printf("无效的选择，请重新输入。\n");
                break;
            }
        }
    } while (choice != 7);

    return 0;
}


