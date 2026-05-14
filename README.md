# C语言链表库 (C Linked List Library)

[![C](https://img.shields.io/badge/C-99%2F11-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

一个功能完善、易于使用的C语言单向链表实现库，支持动态内存管理、多种操作函数和完整的测试用例。

## 功能特性

- **动态内存管理**：使用 `calloc` 自动初始化内存，包含空指针检查
- **带头节点设计**：简化边界条件处理，统一操作逻辑
- **完整操作集**：支持增删改查、排序、去重、拼接等常用操作
- **类型可扩展**：通过 `typedef` 轻松修改数据类型
- **中文注释**：代码注释详尽，便于学习和理解

## 支持的编译器

- GCC
- Clang
- MSVC
- MinGW

## 依赖

[![C Standard Library](https://img.shields.io/badge/C%20Standard%20Library-stdio.h%20%7C%20stdlib.h%20%7C%20stdbool.h-blue.svg)](https://en.cppreference.com/w/c/header)

本项目仅依赖C标准库：

- `stdio.h` - 标准输入输出
- `stdlib.h` - 内存分配函数
- `stdbool.h` - 布尔类型支持

## API 文档

### 数据结构

```c
typedef int Data;  // 可根据需要修改为其他数据类型

struct Node {
    Data node_data;      // 节点数据
    struct Node* next;   // 指向下一个节点的指针
};
typedef struct Node Node;
```

### 核心函数

#### 链表创建与复制

| 函数                                            | 说明                                                      |
| ----------------------------------------------- | --------------------------------------------------------- |
| `Node* creatList(void)`                         | 创建一个带头节点的空链表                                  |
| `void copyCreat(Node* list1, Node* list2_head)` | 复制链表，将 list1 的内容复制到以 list2_head 为头的新链表 |

#### 插入操作

| 函数                                             | 说明                                                     |
| ------------------------------------------------ | -------------------------------------------------------- |
| `void pushBack(Node* headnode, Data val)`        | 尾插：在链表末尾添加值为 val 的节点                      |
| `void pushFront(Node* headnode, Data val)`       | 头插：在头节点后插入值为 val 的节点                      |
| `void push(Node* headnode, int index, Data val)` | 指定位置插入：在第 index 个节点后插入（index 从 1 开始） |

#### 删除操作

| 函数                                  | 说明                                |
| ------------------------------------- | ----------------------------------- |
| `void popBack(Node* headNode)`        | 尾删：删除链表最后一个节点          |
| `void popFront(Node* headNode)`       | 头删：删除第一个有效节点            |
| `void pop(Node* headnode, int index)` | 删除指定位置节点（index 从 1 开始） |

#### 修改与查询

| 函数                                                      | 说明                                                       |
| --------------------------------------------------------- | ---------------------------------------------------------- |
| `void gai(Node* headnode, int index, Data val)`           | 修改第 index 个节点的数据为 val                            |
| `void showList(Node* headNode)`                           | 打印链表中所有有效节点的数据                               |
| `int nodeNum(Node* headnode)`                             | 返回链表中有效节点的个数（不含头节点）                     |
| `Node* lookIt(Node* headNode, int num)`                   | 返回指向第 num 个节点的指针（num 从 1 开始）               |
| `int whereData(Node* headNode_P, int listNum, Data data)` | 根据数据值查找节点位置，返回第一次出现的下标，未找到返回 0 |

#### 高级操作

| 函数                                                    | 说明                                                   |
| ------------------------------------------------------- | ------------------------------------------------------ |
| `void swapNode(Node* headNode, int index1, int index2)` | 交换第 index1 和 index2 两个节点的数据值               |
| `void listCom(Node* list1, Node* list2)`                | 将 list2 中所有节点拼接到 list1 的尾部                 |
| `void popRe(Node* list, Node* outList)`                 | 去重：仅保留链表中只出现一次的元素，结果存入 outList   |
| `void listSort(Node* headNode_P, Node* outList)`        | 降序排序：对链表进行冒泡排序（降序），结果存入 outList |

## 使用示例

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 包含链表库函数声明（建议分离为头文件）
// #include "linkedlist.h"

int main() {
    // 创建链表
    Node* list = creatList();
    
    // 插入数据
    pushBack(list, 10);   // 尾插
    pushBack(list, 20);
    pushFront(list, 5);   // 头插
    push(list, 2, 15);    // 在第2个位置后插入
    
    // 显示链表
    printf("链表内容：");
    showList(list);       // 输出：5 10 15 20
    printf("\n节点数：%d\n", nodeNum(list));  // 输出：4
    
    // 修改数据
    gai(list, 2, 100);
    showList(list);       // 输出：5 100 15 20
    
    // 删除操作
    popFront(list);       // 头删
    popBack(list);        // 尾删
    showList(list);       // 输出：100 15
    
    // 排序
    Node* sorted = creatList();
    listSort(list, sorted);
    printf("排序后：");
    showList(sorted);     // 降序输出
    
    return 0;
}
```

## 编译运行

### 使用 GCC

```bash
gcc 链表库.cpp
```

## 项目结构

```
C语言链表库/
├── 链表库.cpp      # 主文件（包含实现和测试）
├── a.exe           # 编译生成的可执行文件
└── README.md       # 项目说明文档
```

## 设计说明

1. **带头节点设计**：使用一个空的头节点简化边界条件处理，所有操作统一对待
2. **内存安全**：每次内存分配都进行空指针检查，防止段错误
3. **下标约定**：所有涉及位置的参数均从 1 开始计数（第 1 个表示第一个有效节点）
4. **去重逻辑**：`popRe` 函数仅保留在整个链表中**只出现一次**的元素
5. **排序算法**：采用冒泡排序实现降序排列，可通过修改比较符号改为升序

## 扩展建议

- 将代码分离为 `linkedlist.h`（头文件）和 `linkedlist.c`（实现文件）
- 添加链表反转函数 `reverseList()`
- 添加链表销毁函数 `destroyList()` 防止内存泄漏
- 实现更高效的排序算法（如快速排序）
- 支持泛型编程（使用 `void*` 指针）

## 作者信息

**谙弆悕博士（Ailan Anjuxi）**

- 邮箱：[anjuxi.ME@outlook.com](mailto:anjuxi.ME@outlook.com)
- SIP电话：[sip:anjuxi@sip.linphone.org](sip:anjuxi@sip.linphone.org)

## 许可证

本项目采用 MIT 许可证，详情请参见 LICENSE 文件。

---

*本项目为C语言数据结构学习与实践作品，欢迎交流与改进。*
