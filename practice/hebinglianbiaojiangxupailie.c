#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

typedef struct LNode
{
    int data;
    struct LNode *next;
} *LinkList;

// 初始化带头结点的空链表
void InitList(LinkList *L) {
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
}

// 尾插法插入元素（用于测试）
void ListTailInsert(LinkList L, int e) {
    LNode *p = L;
    while (p->next) p = p->next;
    LNode *newNode = (LNode *)malloc(sizeof(LNode));
    newNode->data = e;
    newNode->next = NULL;
    p->next = newNode;
}

// 打印链表（用于测试）
void PrintList(LinkList L) {
    LNode *p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 合并函数：将递增有序的 la 和 lb 合并成递减有序且去重的 lc
void Merg(LinkList la, LinkList lb, LinkList *lc) {
    InitList(lc);  // 初始化 lc 为空链表

    LNode *pa = la->next;
    LNode *pb = lb->next;

    // 用于构建 lc 的头插指针
    LNode *pc = *lc;

    int prev = 0;  // 用于记录上一个插入 lc 的值，避免重复
    int first = 1;      // 标记是否是第一个元素

    // 使用双指针从后往前比较（但链表只能前向遍历）
    // 所以我们先正向遍历，将结果头插到 lc，从而实现递减
    while (pa && pb) {
        if (pa->data < pb->data) {
            if (first || pa->data != prev) {
                LNode *newNode = (LNode *)malloc(sizeof(LNode));
                newNode->data = pa->data;
                newNode->next = pc->next;
                pc->next = newNode;
                prev = pa->data;
                first = 0;
            }
            pa = pa->next;
        } else if (pa->data > pb->data) {
            if (first || pb->data != prev) {
                LNode *newNode = (LNode *)malloc(sizeof(LNode));
                newNode->data = pb->data;
                newNode->next = pc->next;
                pc->next = newNode;
                prev = pb->data;
                first = 0;
            }
            pb = pb->next;
        } else { // pa->data == pb->data
            if (first || pa->data != prev) {
                LNode *newNode = (LNode *)malloc(sizeof(LNode));
                newNode->data = pa->data;
                newNode->next = pc->next;
                pc->next = newNode;
                prev = pa->data;
                first = 0;
            }
            pa = pa->next;
            pb = pb->next;
        }
    }

    // 处理剩余部分
    while (pa) {
        if (first || pa->data != prev) {
            LNode *newNode = (LNode *)malloc(sizeof(LNode));
            newNode->data = pa->data;
            newNode->next = pc->next;
            pc->next = newNode;
            prev = pa->data;
            first = 0;
        }
        pa = pa->next;
    }

    while (pb) {
        if (first || pb->data != prev) {
            LNode *newNode = (LNode *)malloc(sizeof(LNode));
            newNode->data = pb->data;
            newNode->next = pc->next;
            pc->next = newNode;
            prev = pb->data;
            first = 0;
        }
        pb = pb->next;
    }
}

// 示例测试
int main() {
    LinkList la, lb, lc;
    InitList(&la);
    InitList(&lb);

    // 构造递增有序链表 la: 1 -> 3 -> 5 -> 7
    ListTailInsert(la, 1);
    ListTailInsert(la, 3);
    ListTailInsert(la, 5);
    ListTailInsert(la, 7);

    // 构造递增有序链表 lb: 2 -> 3 -> 6 -> 7 -> 8
    ListTailInsert(lb, 2);
    ListTailInsert(lb, 3);
    ListTailInsert(lb, 6);
    ListTailInsert(lb, 7);
    ListTailInsert(lb, 8);

    printf("la: ");
    PrintList(la);
    printf("lb: ");
    PrintList(lb);

    Merg(la, lb, &lc);

    printf("lc (递减去重): ");
    PrintList(lc);

    return 0;
}