#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	int data;
	struct stack *next;
}Stack;

void menu() {
    printf("1.判断栈空\n");
    printf("2.计算栈的长度\n");
    printf("3.入栈\n");
    printf("4.出栈\n");
    printf("5.取栈顶值\n");
    printf("6.输出栈内值\n");
    printf("0.退出程序\n");
}

//初始化 
Stack *StackInit() {
	Stack *head = (Stack *)malloc(sizeof(Stack));
	if(head == NULL) {
		printf("链栈创建失败\n");
		return NULL;
	}
	head->next = NULL;
	return head;
}

//判断栈空
void EmptyStack(Stack *head) {
	if(head->next == NULL) {
		printf("栈为空\n");
	}
	else {
		printf("栈不为空\n");
	}
}

//栈的长度
int LengthStack(Stack *head) {
	Stack *p = (Stack *)malloc(sizeof(Stack));
	p = head;
	if(p == NULL) {
		printf("内存请求失败\n");
	}
	int i = 0;
	while(p->next != NULL) {
		p = p->next;
		i++;
	}
	printf("栈的长度为：%d\n",i);
} 

//入栈
int PushStack(Stack *head, int m) {
	Stack *p = (Stack *)malloc(sizeof(Stack));
	if(p == NULL) {
		printf("内存请求失败\n");
	}
	p->data = m;
	p->next = head->next;
	head->next = p;
	printf("新元素%d入栈成功\n",p->data);
} 

//出栈
int PopStack(Stack *head) {
	if(head->next == NULL) {
		printf("栈内为空\n");
	}
	Stack *p = (Stack *)malloc(sizeof(Stack));
	p = head->next;
	if(p == NULL) {
		printf("内存请求失败\n");
	}
	printf("元素%d出栈成功\n",p->data);
	free(p);
} 

//取栈顶值
int MaxStack(Stack *head) {
	if(head->next == 0) {
		printf("栈内为空\n");
	}
	else
	    printf("栈顶元素为：%d\n",head->next->data);
} 

//输出栈内所有值
int PrintStack(Stack *head) {
	if(head->next == 0) {
		printf("栈内为空\n");
	}
	Stack *p = (Stack *)malloc(sizeof(Stack));
	p = head->next;
	if(p == NULL) {
		printf("内存请求失败\n");
	}
	while(p != NULL) {
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}
 

int main() {
	Stack *stack = StackInit();
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
            case 2: // 计算栈的长度
                LengthStack(stack);
                system("pause");
				system("cls"); 
                break;
            case 3: // 入栈
                printf("要入栈的元素为：");
				int pos;
				scanf("%d",&pos);
			    PushStack(stack,pos);
                system("pause");
				system("cls"); 
                break;
            case 4: // 出栈
                printf("出栈的元素为：\n");
			    PopStack(stack);
                system("pause");
				system("cls"); 
                break;
            case 5: // 取栈顶值 
			    MaxStack(stack);
                system("pause");
				system("cls"); 
                break;
            case 6: // 输出栈内所有值 
                printf("栈内的所有值分别为：");
			    PrintStack(stack);
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
