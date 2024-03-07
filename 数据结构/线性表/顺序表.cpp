#include<cstdio>
// 顺序表的静态分配
#define MaxSize  50
typedef struct {
    int data[MaxSize];
    int length;
} SqList;

// 顺序表的动态分配
//#define InitSize 100
//typedef struct{
//    int *data;
//    int MaxSize,length;
//}SeqLiszt;

// 顺序表的基本操作
// 1、初始化
void InitList(SqList &L) {
    L.length = 0;
};
//2、插入操作 在顺序表第i个元素位置插入元素e
bool ListInsert(SqList &L, int i, int e) {
    if (i < 1 || i > L.length + 1) return false;   // 确定边界，i代表位序，是
    if (L.length >= MaxSize) return false;
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;   // 线性表长度加1
    return true;
};
//3、删除操作
bool DeleteList(SqList &L, int i, int &e) {
    // 确定边界
    if (i < 1 || i > L.length) return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
};
// 4、查找
int LocateElem(SqList L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}
//5、打印
void PrintList(SqList &L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d\n", L.data[i]);
    }
};

int main() {
    SqList L;
    InitList(L);
    for (int i = 0; i < 10; i++) {
        ListInsert(L, i + 1, i * i);
    }
    PrintList(L);
    int e = -1;
    DeleteList(L, 5, e);
    printf("删除了的元素是%d\n", e);
    PrintList(L);
    printf("查找元素%d\n", LocateElem(L, 11));
    printf("查找元素%d\n", LocateElem(L, 25));
    return 0;
}

