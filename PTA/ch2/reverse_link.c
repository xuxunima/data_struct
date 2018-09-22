#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义的数组元素
typedef struct Node {
    char s[6];
    int data;
    char next[6];
} Node;

// 交换数组中两个元素
void swap (Node *Array, int index1, int index2) {
    Node temp;
    if (index1 == index2) {
        return ;
    }
    memcpy(&temp, Array + index1, sizeof(Node));
    memcpy(Array + index1, Array + index2, sizeof(Node));
    memcpy(Array + index2, &temp, sizeof(Node));
}

int  main () {
    int num;
    int changeNum;
    char baseAd[6];
    Node *Array = NULL;
    int i, j;
    int mid;

    scanf("%s %d %d", baseAd, &num, &changeNum);
    if (0 == strcmp("-1", baseAd)) {
        return 1;
    }

    Array = malloc (num * sizeof(Node));
    if (NULL == Array) {
        printf("Malloc Failed!\n");
        return 1;
    }
    // 读入所有元素
    for (i = 0; i < num; i++) {
        scanf("%s %d %s", Array[i].s, &(Array[i].data), Array[i].next);
    }
    // 找到链表的头结点并放置在数组的0位置
    for (i = 0; i < num; i++) {
        if (0 == strcmp(Array[i].s, baseAd)) {
            swap(Array, 0, i);
            break;
        }
    }
    // 从数组0位置的元素开始，根据元素的Next指针不断找到下一个位置应放置的元素，读到Next为-1则表示结束，并记录数组中有效元素的个数
    for (i = 0; i < num - 1; i++) {
        for (j = i + 1; j < num; j++) {
            if (0 == strcmp(Array[i].next, Array[j].s)) {
                swap(Array, i + 1, j);
                break;
            }
        }
        if (0 == strcmp(Array[i + 1].next, "-1")) {
            num = i + 2;
            break;
        }
    }
    // reverse数组元素
    mid = changeNum / 2;
    for (i = 0; i < num; i += changeNum) {
        if ((i + changeNum) > num) { //数组最后剩下的不足changeNum长的不需要reverse
            break;
        }
        for (j = 0; j < mid; j++) {
            swap(Array, i + j, i + changeNum - j - 1);
        }
    }

    for (i = 0; i < num; i++) {
        if (i != (num -1)) {  // 更新元素的Next指针
            strcpy(Array[i].next, Array[i + 1].s);
        } else {
            strcpy(Array[i].next, "-1");
        }
        printf("%s %d %s", Array[i].s, Array[i].data, Array[i].next);  // 打印元素
        if (i != (num - 1)) {
            printf("\n");
        }
    }
    free(Array);  // 最后不能忘了释放空间
    return 0;
}

