#include <stdio.h>  
#define MAXSIZE 100  

typedef struct   
{  
	int elem[MAXSIZE];  
	int size;  
} SeqList;  

void Menu()   
{  
    printf("�˵���\n");  
    printf("1. ��ѯ��\n");  
    printf("2. ��������\n");  
    printf("3. ɾ������\n");  
    printf("4. �޸�����\n");  
    printf("5. ��ֵ��ѯ\n");  
    printf("6. ���±��ѯ\n");  
    printf("7. ��ʾ��������\n");  
    printf("8. �˳�\n");  
}  

void InitList(SeqList *L)  
{  
	L->size = 0;  
}  

void GetSize(SeqList *L)  
{  
	printf("��Ϊ %d\n", L->size);  
}  

void InsertList(SeqList *L)  
{  
	int i, n;  
	printf("����������Ԫ�ص�������");  
	scanf("%d", &n);  
	if (L->size + n > MAXSIZE) {  
		printf("����������������������޷���Ӹ������ݡ�\n");  
		return;  
	}  
	printf("�����Ԫ�طֱ�Ϊ��");  
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
		printf("˳���Ϊ�գ��޷�ɾ����\n");  
		return;  
	}  
	printf("Ҫɾ����Ԫ��ֵ:");  
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
			printf("����ɾ���ɹ���\n");  
			return;  
		}  
	}  
	printf("δ�ҵ���Ԫ�أ�ɾ��ʧ�ܡ�\n");  
}  

void ModifyList(SeqList *L)  
{  
	int i, index;  
	if (L->size == 0)  
	{  
		printf("˳���Ϊ�գ��޷��޸ġ�\n");  
		return;  
	}  
	printf("Ҫ�޸ĵ�Ԫ���±�: ");   
	scanf("%d", &index);  
	if (index < 0 || index >= L->size)   
	{  
		printf("�޸�λ�ò��Ϸ���\n");  
		return;  
	}  
	printf("�������޸ĺ������:");  
	scanf("%d", &L->elem[index]);  
}  

void GetElem(SeqList *L)  
{  
	int i, num;  
	int flag = 0;  
	printf("���������ѯ��ֵ��");  
	scanf("%d", &num);  
	for (i = 0; i < L->size; i++)  
	{  
		if (L->elem[i] == num)  
		{  
			flag = 1;  
			printf("Ԫ�� %d �����ڸ�˳����С�\n", num);  
			break;  
		}  
	}  
	if (!flag)  
	{  
		printf("��˳����в����ڸ�Ԫ�ء�\n");  
	}  
}  

void GetIndex(SeqList *L)  
{  
	int index;  
	if (L->size == 0)  
	{  
		printf("˳���Ϊ�գ��޷���ѯ��\n");  
		return;  
	}  
	printf("��ѯ�±�Ϊ��");  
	scanf("%d", &index);  
	if (index < 0 || index >= L->size)  
	{  
		printf("�±겻�Ϸ���\n");  
		return;  
	}  
	printf("�±�Ϊ %d ��Ԫ��Ϊ��%d\n", index, L->elem[index]);  
}  

void PrintList(SeqList *L)  
{  
	int i;  
	if (L->size == 0)  
	{  
		printf("˳���Ϊ�գ��޷���ʾ��\n");  
		return;  
	}  
	printf("Ԫ����ʾ���£�\n");  
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
        Menu();  // ��ʾ�˵�  
        printf("��ѡ�����: ");  
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
                printf("�˳�����\n");  
                break;  
            }  
            default:   
			{  
                printf("��Ч��ѡ�����������롣\n");  
                break;  
            }  
        }  
    } while (choice != 8);  

    return 0;  
}
