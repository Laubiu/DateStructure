#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct student 
{
    char cno[10];  
    char cname[10];  
    int score[3]; 
} element;

typedef struct scorelist 
{
    element data[MAX];  // 存储学生信息的数组
    int last;  // 表示当前顺序表的最后一个元素的位置
} stu;

void menu()
{
    printf("1.插入学生信息\n"); 
    printf("2.删除学生信息\n"); 
    printf("3.按位查找学生信息\n"); 
    printf("4.按学号查找学生信息\n"); 
    printf("5.输出学生信息\n"); 
    printf("0.退出程序\n");
}

// 初始化
stu* CreateList() 
{
    stu* L = (stu*)malloc(sizeof(stu));  
    if (L == NULL) 
    {
        printf("内存分配失败！\n");
        return NULL;
    }
    L->last = -1;  
    return L;
}

// 初始化数据
int InitList(stu* L, element n, int i) 
{
    if (L->last >= MAX - 1) 
    {
        printf("顺序表已满\n");
        return 0;
    }
    if (i < 1 || i > L->last + 2) 
    {
        printf("插入位置不合法\n");
        return -1;
    }
    int j;
    for (j = L->last; j >= i - 1; j--) 
    {  
        L->data[j + 1] = L->data[j];
    }
    L->data[i - 1] = n;  
    L->last++;  
    return 1;
}

// 获取顺序表长度
int ListLen(stu* L) 
{
    printf("%d",L -> last + 1);
}

// 输出顺序表内容
void PrintList(stu* L) 
{
    int i;
    if (L->last == -1) 
    {
        printf("顺序表为空\n");
        return;
    }
    printf("学生成绩信息如下：\n");
    for (i = 0; i <= L->last; i++) 
    {
        printf("学号：%s, 姓名：%s, ", L->data[i].cno, L->data[i].cname);
        printf("语文：%d, 数学：%d, 英语：%d\n", L->data[i].score[0], L->data[i].score[1], L->data[i].score[2]);
    }
}

void DeleteList(stu *L, int i)
{
    int j;
    if (i < 1 || i > L->last + 2) {
        printf("删除位置不合法\n");
        return ;
    }
    for(j=i-1;j<=L->last;j++)
    {
        L->data[j] = L->data[j+1];
    }
    printf("删除成功\n");
    L->last = L->last - 1;
}

//按位查找 
void SearchIndexList(stu *L, int i)
{
	if (i < 1 || i > L->last + 2) {
        printf("查找位置不合法\n");
        return ;
    }
	 else if (L->last < i-1)
	{
		printf("顺序表长度暂未至此\n");
	}
	else
	{
		printf("学号：%s, 姓名：%s, ", L->data[i-1].cno, L->data[i-1].cname);
        printf("语文：%d, 数学：%d, 英语：%d\n", L->data[i-1].score[0], L->data[i-1].score[1], L->data[i-1].score[2]);
	    printf("查找成功\n");
	}
}

//按学号查找
void SearchCnoList(stu *L, char pos[10])
{
	int i=0;
	for(i=0;i<=L->last;i++)
	{
		if(strcmp(L->data[i].cno,pos) == 0)
		{
			printf("学号：%s, 姓名：%s, ", L->data[i].cno, L->data[i].cname);
            printf("语文：%d, 数学：%d, 英语：%d\n", L->data[i].score[0], L->data[i].score[1], L->data[i].score[2]);
            printf("查找成功\n");
		}
	}
}

int main() 
{
    stu* L;
    L = CreateList();
    if (L == NULL) 
    {
        return -1;  
    }
    int a;
    while(1)
    {
        menu();
        printf("请输入选项：");
        scanf("%d", &a);
        switch(a)
        {
            case 1: // 插入学生信息
            {
                element e;
                printf("请输入学号：");
                scanf("%s", e.cno);
                printf("请输入姓名：");
                scanf("%s", e.cname);
                printf("请输入语文成绩：");
                scanf("%d", &e.score[0]);
                printf("请输入数学成绩：");
                scanf("%d", &e.score[1]);
                printf("请输入英语成绩：");
                scanf("%d", &e.score[2]);
                printf("请输入插入位置：");
                int pos;
                scanf("%d", &pos);
                if (InitList(L, e, pos) == -1) {
                    printf("插入失败\n");
                } else {
                    printf("插入成功\n");
                }
                system("pause");
                system("cls");
                break;
            }
            case 2: // 删除学生信息
            {
                printf("请输入要删除的学生位置：");
                int pos;
                scanf("%d", &pos);
                DeleteList(L, pos);
                system("pause");
                system("cls");
                break;
            }
            case 3: // 查找学生信息
            {
            	printf("请选择要查找的位次：");
				int pos;
				scanf("%d",&pos);
				SearchIndexList(L,pos); 
                system("pause");
                system("cls");
                break;
            }
            case 4:
            {
            	printf("请选择要查找的学号：");
            	char pos[10];
            	scanf("%s",&pos);
            	SearchCnoList(L,pos); 
                system("pause");
                system("cls");
                break;
			}
            case 5: // 输出学生信息
            {
                PrintList(L);
                system("pause");
                system("cls");
                break;
            }
            case 0: // 退出程序
            {
                printf("退出程序\n");
                free(L);
                return 0;
            }
            default:
            {
                printf("无效选项，请重新输入\n");
                break;
            }
        }
    }
}
