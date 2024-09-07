#include <stdio.h>  
#define MAXSIZE 100  

typedef struct   
{  
	int elem[MAXSIZE];  
	int size;  
} SeqList;  

void Menu()   
{  
    printf("菜单：\n");  
    printf("1. 查询表长\n");  
    printf("2. 插入数据\n");  
    printf("3. 删除数据\n");  
    printf("4. 修改数据\n");  
    printf("5. 按值查询\n");  
    printf("6. 按下标查询\n");  
    printf("7. 显示所有数据\n");  
    printf("8. 退出\n");  
}  

void InitList(SeqList *L)  
{  
	L->size = 0;  
}  

void GetSize(SeqList *L)  
{  
	printf("表长为 %d\n", L->size);  
}  

void InsertList(SeqList *L)  
{  
	int i, n;  
	printf("请输入插入的元素的数量：");  
	scanf("%d", &n);  
	if (L->size + n > MAXSIZE) {  
		printf("插入数量超过最大容量，无法添加更多数据。\n");  
		return;  
	}  
	printf("插入的元素分别为：");  
	for (i = 0; i < n; i++)  
	{  
		scanf("%d", &L->elem[L->size + i]);  
	}  
	L->size += n;  
}  

void DeleteList(SeqList *L)  
{  
	int i, j, num;  
	if (L->size == 0)  
	{  
		printf("顺序表为空，无法删除。\n");  
		return;  
	}  
	printf("要删除的元素值:");  
	scanf("%d", &num);  
	for (i = 0; i < L->size; i++)  
	{  
		if (L->elem[i] == num)  
		{  
			for (j = i; j < L->size - 1; j++)  
			{  
				L->elem[j] = L->elem[j + 1];  
			}  
			L->size--;  
			printf("数据删除成功！\n");  
			return;  
		}  
	}  
	printf("未找到该元素，删除失败。\n");  
}  

void ModifyList(SeqList *L)  
{  
	int i, index;  
	if (L->size == 0)  
	{  
		printf("顺序表为空，无法修改。\n");  
		return;  
	}  
	printf("要修改的元素下标: ");   
	scanf("%d", &index);  
	if (index < 0 || index >= L->size)   
	{  
		printf("修改位置不合法。\n");  
		return;  
	}  
	printf("请输入修改后的数据:");  
	scanf("%d", &L->elem[index]);  
}  

void GetElem(SeqList *L)  
{  
	int i, num;  
	int flag = 0;  
	printf("请输入想查询的值：");  
	scanf("%d", &num);  
	for (i = 0; i < L->size; i++)  
	{  
		if (L->elem[i] == num)  
		{  
			flag = 1;  
			printf("元素 %d 存在于该顺序表中。\n", num);  
			break;  
		}  
	}  
	if (!flag)  
	{  
		printf("该顺序表中不存在该元素。\n");  
	}  
}  

void GetIndex(SeqList *L)  
{  
	int index;  
	if (L->size == 0)  
	{  
		printf("顺序表为空，无法查询。\n");  
		return;  
	}  
	printf("查询下标为：");  
	scanf("%d", &index);  
	if (index < 0 || index >= L->size)  
	{  
		printf("下标不合法。\n");  
		return;  
	}  
	printf("下标为 %d 的元素为：%d\n", index, L->elem[index]);  
}  

void PrintList(SeqList *L)  
{  
	int i;  
	if (L->size == 0)  
	{  
		printf("顺序表为空，无法显示。\n");  
		return;  
	}  
	printf("元素显示如下：\n");  
	for (i = 0; i < L->size; i++)  
	{  
		printf("%d ", L->elem[i]);  
	}  
	printf("\n");  
}  

int main()   
{  
    SeqList L;  
    InitList(&L);  

    int choice;  
    do {  
        Menu();  // 显示菜单  
        printf("请选择操作: ");  
        scanf("%d", &choice);  

        switch (choice)   
		{  
            case 1:   
			{  
                GetSize(&L);  
                system("pause");
            	system("cls");
                break;  
            }  
            case 2:   
			{  
                InsertList(&L);
				system("pause");
            	system("cls");   
                break;  
            }  
            case 3:  
			{  
				DeleteList(&L);  
				system("pause");
            	system("cls");
				break;  
			}   
            case 4:  
            {  
            	ModifyList(&L);  
            	system("pause");
            	system("cls");
            	break;  
			}  
            case 5:  
            {  
            	GetElem(&L);  
            	system("pause");
            	system("cls");
            	break;  
			}  
			case 6:  
            {  
            	GetIndex(&L);  
            	system("pause");
            	system("cls");
            	break;  
			}  
			case 7:  
			{  
				PrintList(&L);  
				system("pause");
            	system("cls");
            	break;  
			}  
            case 8:   
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
    } while (choice != 8);  

    return 0;  
}
