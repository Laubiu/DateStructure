#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char sno[10];
    char sname[10];
    int score[3];
} element;

typedef struct node {
    element data;
    struct node* next;
} LinkList;

void menu() {
    printf("1.插入学生信息\n");
    printf("2.删除学生信息\n");
    printf("3.按位查找学生信息\n");
    printf("4.按学号查找学生信息\n");
    printf("5.输出学生信息\n");
    printf("0.退出程序\n");
}

// 初始化单链表
LinkList* CreateList() {
    LinkList* head = (LinkList*)malloc(sizeof(LinkList));
    if (head == NULL) {
        printf("内存分配失败\n");
        return NULL;
    }
    head->next = NULL;
    printf("单链表创建成功\n");
    return head;
}

// 建立单链表
void InitList(LinkList* head) {
    element x;
    LinkList* p;
    printf("输入数据，输入学号为'0'时结束\n");
    while (1) {
        printf("请输入学号、姓名、语文成绩、数学成绩、英语成绩：\n");
        scanf("%s %s %d %d %d", x.sno, x.sname, &x.score[0], &x.score[1], &x.score[2]);
        if (strcmp(x.sno, "0") == 0) { // 输入学号为0时结束
            break;
        }
        p = (LinkList*)malloc(sizeof(LinkList));
        if (p == NULL) {
            printf("内存分配失败！\n");
            return;
        }
        p->data = x;
        p->next = head->next;
        head->next = p;
    }
}

// 插入
void InsertList(LinkList* head, element x, int i) {
    LinkList* p = head;
    if (p == NULL) {
        printf("链表为空，无法插入\n");
        return;
    }
    int j = 0;
    while (p->next != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (i < 1 || p->next == NULL && j != i - 1) {
        printf("插入位置不合法\n");
        return;
    }
    LinkList* s = (LinkList*)malloc(sizeof(LinkList));
    if (s == NULL) {
        printf("内存分配失败！\n");
        return;
    }
    s->data = x;
    s->next = p->next;
    p->next = s;
}

// 删除
void DeleteList(LinkList* head, int i) {
    LinkList* p = head;
    if (p == NULL) {
        printf("链表为空，无法删除\n");
        return;
    }
    int j = 0;
    while (p->next != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (i < 1 || p->next == NULL) {
        printf("删除位置不合法\n");
        return;
    }
    LinkList* s = p->next;
    p->next = s->next;
    free(s);
}

//查找
void SearchList(LinkList *head, int i) {
	LinkList* p = head->next;
    if (p == NULL) {
        printf("链表为空，无法显示\n");
        return;
    }
    if (i < 1 || p == NULL) {
        printf("查找位置不合法\n");
        return;
    }
    int j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    printf("%s %s %d %d %d\n", p->data.sno, p->data.sname, p->data.score[0], p->data.score[1], p->data.score[2]);
} 

// 显示
void PrintList(LinkList* head) {
    LinkList* p = head->next;
    if (p == NULL) {
        printf("链表为空，无法显示\n");
        return;
    }
    while (p != NULL) {
        printf("%s %s %d %d %d\n", p->data.sno, p->data.sname, p->data.score[0], p->data.score[1], p->data.score[2]);
        p = p->next;
    }
}

int main() {
    LinkList* head = CreateList();
    if (head == NULL) {
        return -1;
    }
    int a;
    while (1) {
        menu();
        printf("请输入选项：");
        scanf("%d", &a);
        switch (a) {
            case 1: // 插入学生信息
            {
                element e;
                printf("请输入学号：");
                scanf("%s", e.sno);
                printf("请输入姓名：");
                scanf("%s", e.sname);
                printf("请输入语文成绩：");
                scanf("%d", &e.score[0]);
                printf("请输入数学成绩：");
                scanf("%d", &e.score[1]);
                printf("请输入英语成绩：");
                scanf("%d", &e.score[2]);
                printf("请输入插入位置：");
                int pos;
                scanf("%d", &pos);
                InsertList(head, e, pos);
                printf("插入结束\n");
                system("pause");
                system("cls");
                break;
            }
            case 2: // 删除学生信息
            {
                printf("请输入要删除的学生位置：");
                int pos;
                scanf("%d", &pos);
                DeleteList(head, pos);
                printf("删除结束\n");
                system("pause");
                system("cls");
                break;
            }
            case 3:   //查找 
            {
            	printf("请输入要查找的学生位置：");
                int pos;
                scanf("%d", &pos);
                SearchList(head, pos);
                printf("查找结束\n");
            	system("pause");
                system("cls");
			}
            case 5: // 输出学生信息
            {
                PrintList(head);
                system("pause");
                system("cls");
                break;
            }
            case 0: // 退出程序
            {
                printf("退出程序\n");
                free(head);
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
