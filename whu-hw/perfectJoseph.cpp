#include <iostream>
#include <vector>
using namespace std;

// 节点结构体定义
struct Node {
    int num;           // 人的编号
    Node* next;     // 指向下一个节点
    Node(int n = 0) : num(n), next(nullptr) {} // 构造函数，初始化编号和指针
};

// 约瑟夫环问题解决类
class Joseph {
public:
    Node* startNode = nullptr;      // 起始节点
    int totalCount = 0;             // 总人数
    vector<int> kickout;   // 淘汰步骤序列

    // 构造函数，初始化约瑟夫环
    Joseph(int count, vector<int> steps);

    // 创建环形链表
    Node* createCircle(int count);

    // 根据步数淘汰节点
    Node* eliminate(Node* startNode, int step, int count);
};

// 构造函数实现
Joseph::Joseph(int count, vector<int> steps) : totalCount(count), kickout(steps) {
    // 创建约瑟夫环
    startNode = createCircle(totalCount);

    // 按给定步骤顺序淘汰节点
    for (int i = 0; i < static_cast<int>(kickout.size()); i++) {
        startNode = eliminate(startNode, kickout[i], totalCount);
    }
}

// 创建环形链表
Node* Joseph::createCircle(int count) {
    // 创建第一个节点
    Node* firstNode = new Node(1);
    Node* currentNode = firstNode;

    // 添加后续节点
    for (int i = 2; i <= count; i++) {
        currentNode->next = new Node(i);
        currentNode = currentNode->next;
    }

    // 尾节点指向首节点，形成环
    currentNode->next = firstNode;
    return firstNode;
}

// 淘汰节点的函数
Node* Joseph::eliminate(Node* startNode, int step, int count) {
    Node* eliminationList = nullptr;     // 淘汰序列链表
    Node* currentNode = startNode;       // 当前节点指针
    Node* tempNext;                      // 指向要淘汰节点的指针
    Node* eliminationHead = nullptr;     // 淘汰链表的头节点

    // 循环到只剩一个结点
    for (int i = 1; i <= count; i++) {
        currentNode = startNode;
        int stepCount = 1;

        // 移动到要淘汰的节点
        while (stepCount != step) {
            stepCount++;
            currentNode = currentNode->next;
        }

        // 加入淘汰序列
        if (!eliminationList) {
            eliminationList = new Node(currentNode->num);
            eliminationHead = eliminationList;
        } else {
            eliminationList->next = new Node(currentNode->num);
            eliminationList = eliminationList->next;
        }

        // 删除节点
        tempNext = currentNode->next;
        currentNode->num = tempNext->num;
        currentNode->next = tempNext->next;
        delete tempNext;
        startNode = currentNode;
    }

    // 构成环状
    eliminationList->next = eliminationHead;
    return eliminationHead;
}


int main() {
    int numPeople = 0, step = 0;

    // 总人数和N
    cin >> numPeople;
    vector<int> steps;
    while (cin >> step) {
        steps.push_back(step);
    }

    Joseph game(numPeople, steps);

    // 输出
    for (int i = 0; i < game.totalCount; i++) {
        printf("%4d", game.startNode->num);
        game.startNode = game.startNode->next;
    }

    return 0;
}
