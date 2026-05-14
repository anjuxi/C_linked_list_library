#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// ——————————————————————————————————————————————#
typedef int Data;//为了方便修改数据类型。

// 链表节点结构体。
struct Node {
    Data node_data;      // 节点存放的数据。
    struct Node* next;   // 指向下一个节点的指针。
};
typedef struct Node Node;   // 为 struct Node 取别名为 Node。
// ——————————————————————————————————————————————#


// ——————————————————————————————————————————————#
Node* creatList(void);//创建一个空链表。

// 复制构造：以 list2_head 为头节点，创建一个与 list1 内容完全相同的新链表
void copyCreat(Node* list1, Node* list2_head);

// 插入操作
void pushBack(Node* headnode, Data val);      // 尾插：在链表尾部添加值为 val 的新节点
void pushFront(Node* headnode, Data val);     // 头插：在头节点之后、第一个有效节点之前插入
void push(Node* headnode, int index, Data val); // 在指定位置插入：在第 index 个节点之后插入值为 val 的新节点
                                               // index 从 1 开始计数（1 表示第一个有效节点）

// 删除操作
void popBack(Node* headNode);    // 尾删：删除链表最后一个节点
void popFront(Node* headNode);   // 头删：删除第一个有效节点
void pop(Node* headnode, int index); // 删除指定位置的节点（index 从 1 开始）

// 修改指定位置节点的数据
void gai(Node* headnode, int index, Data val); // 将第 index 个节点的数据改为 val

// 查询与显示
void showList(Node* headNode);   // 打印链表中所有有效节点的数据
int nodeNum(Node* headnode);     // 返回链表中有效节点的个数（不含头节点）
Node* lookIt(Node* headNode, int num); // 返回指向第 num 个节点的指针（num 从 1 开始）
int whereData(Node* headNode_P, int listNum, Data data); // 根据数据值查找节点位置
                                                         // 返回第一次出现该数据的节点下标（从1开始），未找到返回0

// 交换两个节点的数据值
void swapNode(Node* headNode, int index1, int index2); // 交换第 index1 和 index2 两个节点的 data 值

// 链表拼接
void listCom(Node* list1, Node* list2); // 将 list2 中所有节点拼接到 list1 的尾部

// 去重（此处实现的功能为：只保留链表中仅出现一次的元素，剔除所有重复出现过的元素）
void popRe(Node* list, Node* outList); // 将去重后的结果存入 outList 链表

// 排序（降序排列）
void listSort(Node* headNode_P, Node* outList); // 对链表进行降序排序，结果存入 outList

// ——————————————————————————————————————————————#



int main() {
    // 创建一个头节点
    Node* headNode = creatList();

    // 尾插测试
    pushBack(headNode, 1);
    pushBack(headNode, 2);
    pushBack(headNode, 3);
    pushBack(headNode, 4);
    pushBack(headNode, 5);
    pushBack(headNode, 6);
    pushBack(headNode, 1);
    pushBack(headNode, 2);
    pushBack(headNode, 3);
    pushBack(headNode, 4);
    pushBack(headNode, 5);
    pushBack(headNode, 6);

    // 头插测试
    pushFront(headNode, 7);
    pushFront(headNode, 8);
    pushFront(headNode, 9);

    printf("原始链表：");
    showList(headNode);
    printf("\n节点个数是：%d\n", nodeNum(headNode));

    // 在第2个节点后插入99
    push(headNode, 2, 99);
    printf("\n第二个节点后插入99后：");
    showList(headNode);
    printf("\n节点个数是：%d\n", nodeNum(headNode));

    // 头删两次
    popFront(headNode);
    popFront(headNode);
    printf("\n头删2次后：");
    showList(headNode);
    printf("\n节点个数是：%d\n", nodeNum(headNode));

    // 删除第4个节点
    pop(headNode, 4);
    printf("\n删除第4个节点后：");
    showList(headNode);
    printf("\n节点个数是：%d\n", nodeNum(headNode));

    // 尾删一次
    popBack(headNode);
    printf("\n尾删后：");
    showList(headNode);
    printf("\n节点个数是：%d\n", nodeNum(headNode));

    // 将第4个节点的数据改为101
    gai(headNode, 4, 101);
    printf("\n将第4个节点改为101后：");
    showList(headNode);
    printf("\n节点个数是：%d\n", nodeNum(headNode));

    // 查看第3个节点
    Node* T = lookIt(headNode, 3);
    printf("\n第3个节点的数据：");
    printf("%d", T->node_data);
    printf("\n节点个数是：%d\n", nodeNum(headNode));

    // 查找数据为4的节点位置
    int i = whereData(headNode, nodeNum(headNode), 4);
    printf("\n数据为4的节点是第%d个\n", i);
    printf("节点个数是：%d\n", nodeNum(headNode));

    // 复制构造一个相同的新链表 list2
    Node* list2 = creatList();
    copyCreat(headNode, list2);
    printf("\n复制构造的链表：");
    showList(list2);
    printf("\n节点个数是：%d\n", nodeNum(list2));

    // 将 list2 拼接到 headNode 尾部
    listCom(headNode, list2);
    printf("\n拼接后的链表：");
    showList(headNode);
    printf("\n节点个数是：%d\n", nodeNum(headNode));

    // 交换第3和第5个节点的数据
    swapNode(headNode, 3, 5);
    printf("\n交换第3和第5个节点后：");
    showList(headNode);
    printf("\n节点个数是：%d\n", nodeNum(headNode));

    // 去重（保留仅出现一次的元素）
    Node* outList = creatList();
    popRe(headNode, outList);
    printf("\n去重后的链表（仅保留唯一元素）：");
    showList(outList);
    printf("\n节点个数是：%d\n", nodeNum(outList));

    // 对去重后的链表进行降序排序
    Node* sortRe = creatList();
    listSort(outList, sortRe);
    printf("\n排序后的链表（降序）：");
    showList(sortRe);
    printf("\n节点个数是：%d\n", nodeNum(sortRe));

    return 0;
}

// ========== 函数实现 ==========

// 创建头节点，其 next 指针初始为 NULL
Node* creatList(void) {
    // 使用 calloc 分配内存，自动初始化为 0。
    Node* headNode = (Node*)calloc(1, sizeof(Node));
    if (!headNode) {
        return NULL;   // 内存分配失败，返回 NULL
    }
    return headNode;   // 返回头节点指针
}

// 复制构造：遍历 list1 的所有节点，依次尾插入 list2_head
void copyCreat(Node* list1, Node* list2_head) {
    Node* curNode = list1->next;   // 跳过头节点，指向第一个有效节点
    for (int i = 1; i <= nodeNum(list1); i++) {
        pushBack(list2_head, curNode->node_data);
        curNode = curNode->next;
    }
}

// 尾插法：在链表末尾添加新节点
void pushBack(Node* headnode, Data val) {
    Node* newNode = (Node*)calloc(1, sizeof(Node));
    if (!newNode) {
        return;    // 分配失败，直接返回
    }
    newNode->node_data = val;    // 设置节点数据

    // 找到当前链表的最后一个节点
    Node* curNode = headnode;
    while (curNode->next != NULL) {
        curNode = curNode->next;
    }
    curNode->next = newNode;     // 将新节点挂到尾部
}

// 头插法：在头节点之后插入新节点
void pushFront(Node* headnode, Data val) {
    Node* newNode = (Node*)calloc(1, sizeof(Node));
    if (!newNode) {
        return;
    }
    newNode->node_data = val;

    Node* temp = headnode->next;   // 保存原来的第一个有效节点
    headnode->next = newNode;      // 头节点指向新节点
    newNode->next = temp;          // 新节点指向原来的第一个节点
}

// 指定位置插入：在第 index 个节点之后插入新节点
void push(Node* headnode, int index, Data val) {
    Node* newNode = (Node*)calloc(1, sizeof(Node));
    if (!newNode) {
        return;
    }
    newNode->node_data = val;

    // 定位到第 index 个节点（从1开始计数）
    Node* curNode = headnode->next;
    for (int i = 1; i < index; i++) {
        curNode = curNode->next;
    }

    // 执行插入操作
    Node* temp = curNode->next;
    curNode->next = newNode;
    newNode->next = temp;
}

// 尾删：删除最后一个节点
void popBack(Node* headNode) {
    // 链表为空则直接返回
    if (headNode->next == NULL) {
        return;
    }

    // 找到倒数第二个节点
    Node* curNode = headNode;
    while ((curNode->next)->next != NULL) {
        curNode = curNode->next;
    }
    free(curNode->next);         // 释放最后一个节点
    curNode->next = NULL;        // 倒数第二个节点成为新的尾节点
}

// 头删：删除第一个有效节点
void popFront(Node* headNode) {
    if (headNode->next == NULL) {
        return;
    }

    Node* temp = headNode->next->next; // 保存第二个节点
    free(headNode->next);              // 释放第一个节点
    headNode->next = temp;             // 头节点指向第二个节点
}

// 删除指定位置的节点（index 从 1 开始）
void pop(Node* headnode, int index) {
    Node* curNode = headnode->next;
    // 定位到待删除节点的前一个节点
    for (int i = 1; i < index - 1; i++) {
        curNode = curNode->next;
    }

    Node* temp = curNode->next->next;  // 保存待删除节点之后的节点
    free(curNode->next);               // 释放待删除节点
    curNode->next = temp;              // 前一个节点指向后一个节点
}

// 修改第 index 个节点的数据为 val
void gai(Node* headnode_P, int index, Data val) {
    Node* curNode_P = headnode_P->next;
    for (int i = 1; i < index; i++) {
        curNode_P = curNode_P->next;
    }
    curNode_P->node_data = val;
}

// 打印整个链表（跳过表头）
void showList(Node* headNode) {
    Node* curNode = headNode->next;  // 从第一个有效节点开始
    while (curNode) {
        printf("%d ", curNode->node_data);
        curNode = curNode->next;
    }
}

// 计算有效节点个数
int nodeNum(Node* headnode) {
    int temp = 0;
    Node* curNode = headnode;
    if (curNode->next == NULL) {
        return temp;  // 空链表返回0
    }
    while (curNode->next != NULL) {
        temp++;
        curNode = curNode->next;
    }
    return temp;
}

// 返回指向第 num 个节点的指针（num 从 1 开始）
Node* lookIt(Node* headNode_P, int num) {
    Node* curNode_P = headNode_P->next;
    for (int i = 1; i < num; i++) {
        curNode_P = curNode_P->next;
    }
    return curNode_P;
}

// 根据数据值查找节点位置，返回第一次出现的下标（从1开始），找不到返回0
int whereData(Node* headNode_P, int listNum, Data data) {
    Node* curNode_P = headNode_P->next;
    for (int i = 1; i <= listNum; i++) {
        if (curNode_P->node_data == data) {
            return i;
        }
        curNode_P = curNode_P->next;
    }
    return 0;
}

// 交换两个指定位置节点的数据值
void swapNode(Node* headNode, int index1, int index2) {
    Node* node1 = lookIt(headNode, index1);
    Node* node2 = lookIt(headNode, index2);

    Data temp = node1->node_data;
    node1->node_data = node2->node_data;
    node2->node_data = temp;
}

// 链表拼接：将 list2 的所有有效节点连接到 list1 的尾部
void listCom(Node* list1, Node* list2) {
    Node* top = list2->next;                       // list2 的第一个有效节点
    Node* list1Tail = lookIt(list1, nodeNum(list1)); // 找到 list1 的尾节点
    list1Tail->next = top;                         // 连接
}

// 去重函数（注意：本函数逻辑为仅保留在整个链表中**只出现一次**的元素）
// 即：如果某个值出现超过一次，则该值对应的所有节点都不会出现在结果中
void popRe(Node* list, Node* outList) {
    int CA = -1;           // copyArray 的写入位置，初始为-1，写入时先+1
    bool flag = 0;         // 0 表示当前元素不是唯一的（存在重复）

    int arrNum = nodeNum(list);
    Data array[arrNum];    // 临时数组，存放链表所有数据

    // 将链表数据复制到数组中
    Node* cur = list->next;
    for (int i = 0; i < arrNum; i++) {
        array[i] = cur->node_data;
        cur = cur->next;
    }

    Data copyArray[arrNum]; // 存放去重后的数据（只保留出现一次的元素）
    for (int i = 0; i < arrNum; i++) {
        copyArray[i] = 0;
    }

    // 遍历每个元素，检查它是否在后续元素中出现过
    for (int i = 0; i < arrNum; i++) {
        flag = 1;  // 先假设它是唯一的
        for (int ii = i + 1; ii < arrNum; ii++) {
            if (array[i] == array[ii]) {
                flag = 0;   // 发现有重复，标记为非唯一
                break;
            }
        }
        // 如果当前元素没有在后方出现，则将其加入结果数组
        if (flag) {
            copyArray[++CA] = array[i];
        }
    }

    // 将结果数组中的元素依次尾插入 outList
    for (int i = 0; i <= CA; i++) {
        pushBack(outList, copyArray[i]);
    }
}

// 排序函数（采用冒泡排序，降序排列：大的在前）
void listSort(Node* headNode_P, Node* outList) {
    int arrNum = nodeNum(headNode_P);
    Data array[arrNum];

    // 将链表数据复制到数组中
    Node* cur = headNode_P->next;
    for (int i = 0; i < arrNum; i++) {
        array[i] = cur->node_data;
        cur = cur->next;
    }

    // 冒泡排序，降序：如果前一个小于后一个则交换
    for (int i = 0; i < arrNum - 1; i++) {
        for (int ii = 0; ii < arrNum - i - 1; ii++) {
            if (array[ii] < array[ii + 1]) {
                // 交换两个数
                int temp = array[ii];
                array[ii] = array[ii + 1];
                array[ii + 1] = temp;
            }
        }
    }

    // 将排序后的数据构建成新链表
    for (int i = 0; i < arrNum; i++) {
        pushBack(outList, array[i]);
    }
}