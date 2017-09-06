//
//  main.c
//  SampleCode
//
//  Created by bobchen on 2017/9/1.
//  Copyright © 2017年 bobchen. All rights reserved.
//

#include <stdio.h>
#include <malloc/malloc.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 1000
#define NODESIZE 20
typedef int ElemType;
// 线性表顺序存储结构
typedef struct {
    ElemType data[MAXSIZE]; // 数组存储数据元素
    int length; // 线性表当前长度
}Sqlist;


// 顺序存储结构插入与删除
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
// 获取元素
Status GetElem(Sqlist L, int i, ElemType * e){
    // 如果长度等于0或者要获取的元素的下表不在范围内，返回错误状态
    if (L.length == 0 || i < 1 || i > L.length) {
        return ERROR;
    }
    
    // 返回L中第i个位置的元素值
    *e = L.data[i - 1];
    return OK;
};

// 插入操作
Status ListInsert(Sqlist * L, int i, ElemType e)
{
    int k;
    if (L->length == MAXSIZE)
    {
        return ERROR;
    }
    if (i < 1 || i > L->length + 1) {
        return ERROR;
    }
    
    // 插入的位置不在表尾的时候将要插入位置的之后的元素向后移动一个位置
    if (i < L->length) {
        for (k = L->length - 1; k >= i - 1; k--) {
            L->data[k + 1] = L -> data[k];
            
        }
        
    }
    // 插入新元素
    L->data[i - 1] = e;
    
    // 表的长度增加1
    L->length++;
    return OK;
}

// 删除操作
Status ListDelete(Sqlist *L, int i, ElemType * e)
{
    int k ;
    if (L->length == 0) { // 线性表为空
        return ERROR;
    }
    
    if (i < 1 || i > L->length) { // 位置错误
        return ERROR;
    }
    
    *e = L->data[i - 1];
    
    // 从删除位置遍历到最后一个元素位置，将它们向前移动一个位置
    if (i < L->length) {
        for (k = i; k < L->length; k ++) {
            L->data[k - 1] = L->data[k];
        }
    }
    
    // 整表的长度减一
    L->length -- ;
    return OK;
}




int main(int argc, const char * argv[]) {
    // insert code here...
    
    return 0;
    
}

// 线性表单链表存储结构
typedef struct Node{
    ElemType data; // 数据域
    struct Node * next; // 指针域
    
} Node;
typedef struct Node * SingleLinkList; // 定义一个单链表

// 单链表的读取
Status SingleGetelem (SingleLinkList L, int i, ElemType * e)
{
    int j;
    SingleLinkList  p; // 声明一个指针P
    p = L->next; // p只想链表的第一个结点
    j = 1;  // 计数器
    
    // p指针存在并且小于i，进行循环直到找到第i个数据
    while (p && j < i)
    {
        p = p -> next; // 指针不断后移
        ++j;
    }
    
    // 遍历到头也没有找到i
    if (!p || j > i) {
        return ERROR;
    }
    *e = p -> data;
    return OK;
}

// 单链表的插入
Status SingleListInsert (SingleLinkList *L, int i,  ElemType e)
{
    int j;
    SingleLinkList p, s;
    p = *L;
    j = 1;
    while (p && j < 1) {
        p = p->next;
        ++j;
    }
    if (!p || j > 1) {
        return ERROR;
    }
    
    
    // 这里采用malloc函数生成一个全新的结点
    s = (SingleLinkList)malloc(sizeof(Node));
    s -> data = e;
    s -> next = p -> next;
    p -> next = s;
    return OK;
}

// 单链表的删除
Status SingleListDelete (SingleLinkList * L,int i,ElemType * e)
{
    int j;
    SingleLinkList p, q;
    p = *L;
    j = 1;
    while (p -> next && j < i) {
        p = p -> next;
        ++j;
    }
    if (!(p -> next) || j > i) {
        return ERROR;
    }
    
    q = p ->next;
    p ->next = q ->next;
    *e = q ->data;
    free(q); // 回收此结点，释放内存
    return OK;
}

// 单链表的整表创建(头插法)
void CreateSingleListHead(SingleLinkList *L, int n)
{
    SingleLinkList p; // 声明指针P
    int i; // 计数器
    // 初始化空链表
    *L = (SingleLinkList)malloc(sizeof(Node));
    
    // 让空链表的头结点的指针先只想NULL
    (*L)->next = NULL;
    
    for (i = 0; i < n; i ++) {
        p = (SingleLinkList)malloc(sizeof(Node)); // 生成新的结点
        p ->data = rand() % 100 + 1;
        
        // 让新结点p的指针域指向表头之前指针域锁指向的空间
        p ->next = (*L) ->next;
        
        (*L) -> next = p; // 让表头的指针域指向新的结点(插入到表头)
    }
}

// 单链表的整表创建(尾插法)
void CreateSingleListTail(SingleLinkList *L, int n)
{
    SingleLinkList p, r;
    int i;
    *L = (SingleLinkList)malloc(sizeof(Node));
    r = *L;
    for (i = 0; i < n; i ++) {
        p = (Node *)malloc(sizeof(Node));
        p ->data = rand() % 100 + 1;
        r ->next = p;
        r = p;
        
    }
    r ->next = NULL;
    
}

// 单链表的整表删除
Status ClearSingleList (SingleLinkList * L)
{
    SingleLinkList p, q;
    p = (*L) -> next;
    while (p) {
        q = p ->next;
        free(p);
        p = q;
    }
    (*L) ->next = NULL;
    return OK;
}


// 静态链表
typedef struct {
    ElemType data; // 数据域
    int cur; // 游标
    
} Componet, StaticLinkList[MAXSIZE];



// 双向链表存储结构
typedef struct DulNode{
    ElemType *elem; // 数据域
    struct DulNode * prior; // 直接前驱指针
    struct DulNode * next; // 直接后继指针
} DullNode, *DuLinkList;

#pragma mark - 栈和队列
typedef int SElemType;
typedef struct {
    SElemType data[MAXSIZE];
    int top; // 标记栈顶指针
    
}SqStack;

#pragma mark - 栈的顺序存储结构
// 进栈
Status Push(SqStack * S, SElemType e){
    if (S ->top == MAXSIZE - 1) // 栈的存储空间已满
    {
        return ERROR;
    }
    
    S -> top++; // 加入一个元素，栈顶指针增加1
    S -> data[S -> top] = e; // 新插入的元素赋值给栈顶空间
    return OK;
}

// 出栈操作
Status Pop(SqStack * S, SElemType e)
{
    if (S -> top == -1) { // 如果当前栈的栈顶已经为-1则不能再进行出栈操作
        return ERROR;
    }
    e = S -> data[S -> top];
    S -> top -- ;
    return OK;
}

// 两栈共享空间
typedef struct {
    SElemType data[MAXSIZE];
    int top1; // 栈1的栈顶指针
    int top2; // 栈2的栈顶指针
    
}SqDoubleStack;

// 两栈共享空间push
Status SqDoublePush(SqDoubleStack * S, SElemType e, int stackNumber){
    if (S -> top1 +1 == S ->top2) // 满栈
    {
        return ERROR;
    }
    if (stackNumber == 1) {
        S -> data[++S->top1] = e;
    }
    if (stackNumber == 2) {
        S -> data[-- S-> top2] = e;
    }
    return OK;
}

Status SqDoublePop(SqDoubleStack * S, SElemType *e, int stackNumber)
{
    if (stackNumber == 1) {
        if (S->top1 == -1) // 栈1是空栈
        {
            return ERROR;
        }
        *e = S->data[S->top1 --];
    }
    if (stackNumber == 2) {
        if (S->top2 == MAXSIZE) {
            return ERROR;
        }
        *e = S->data[S->top2 ++];
    }
    return OK;
}

#pragma mark - 栈的链式存储结构
// 结构
typedef struct StackNode {
    SElemType data;
    struct StackNode * next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack{
    LinkStackPtr top;
    int count;
}LinkStack;



















