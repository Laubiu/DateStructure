#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef int element;
typedef struct score {
	element data[MAX];
	int top;
}Sequence;

void menu() {
    printf("1.判断栈空\n");
    printf("2.判断栈满\n");
    printf("3.计算栈的长度\n");
    printf("4.入栈\n");
    printf("5.出栈\n");
    printf("6.取栈顶值\n");
    printf("0.退出程序\n");
}

//初始化 
Sequence *CreateStack() {
	Sequence *L;
	L = (Sequence *)malloc(sizeof(Sequence));
	if(L == NULL) {
		printf("创建栈失败\n");
		return L;
	}
	L->top = -1;
	return L;
}

//判断栈空
int EmptyStack(Sequence *L) {
	if(L->top == -1) {
		printf("栈空\n");
		return 1;
	}
	else {
		printf("栈不为空\n");
		return 0;
	}
}

//判断栈满
int FullStack(Sequence *L) {
	if(L->top == MAX - 1) {
		printf("栈空间已满\n");
		return 1;
	}
	else {
		printf("栈未满\n");
		return 0;
	}
}

//计算长度
int LengthStack(Sequence *L) {
	int length;
	length = L->top + 1;
	printf("%d\n",length);
}

//入栈
void PushStack(Sequence *L, element e) {
	if(L->top == MAX - 1) {
		printf("栈无空间了\n");
		return ;
	}
	L->top++;
	L->data[L->top] = e;
} 

//出栈
void PopStack(Sequence *L) {
	if(L->top == -1) {
		printf("栈内无元素\n");
	}
	else {
		L->data[L->top] = L->data[L->top - 1];
		L->top = L->top - 1;
	}
}

//取栈顶值
void MaxStack(Sequence *L) {
	if(L->top == -1) {
		printf("栈内无元素\n");
	}
	else {
		printf("栈顶元素为：%d\n",L->data[L->top]);
	}
}

int main() {
	Sequence *stack = CreateStack();
    if (stack == NULL) {
        return -1;
    }
    int choice, value;
    while (1) {
        menu();
        printf("请输入选项：");
        scanf("%d", &choice);
        switch (choice) {
            case 1: // 判断栈空
                EmptyStack(stack);
                system("pause");
				system("cls"); 
                break;
            case 2: // 判断栈满
                FullStack(stack);
                system("pause");
				system("cls"); 
                break;
            case 3: // 计算栈的长度
                LengthStack(stack);
                system("pause");
				system("cls"); 
                break;
            case 4: // 入栈
                printf("请输入要入栈的元素：");
                scanf("%d", &value);
                PushStack(stack, value);
                system("pause");
				system("cls"); 
                break;
            case 5: // 出栈
                PopStack(stack);
                system("pause");
				system("cls"); 
                break;
            case 6: // 取栈顶值
                MaxStack(stack);
                system("pause");
				system("cls"); 
                break;
            case 0: // 退出程序
                printf("退出程序\n");
                free(stack);
                return 0;
            default:
                printf("无效选项，请重新输入\n");
                break;
        }
    }
}
