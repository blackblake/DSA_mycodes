#include <iostream>
#include <fstream>
using namespace std;

struct LinkNode {
    int data;
    LinkNode* next;
    LinkNode() {
        next = nullptr;
    }
    LinkNode(int val) {
        data = val;
        next = nullptr;
    }
};

// 合并两个有序链表(包括了左右各只有一个结点的排序！)
LinkNode* merge(LinkNode* left, LinkNode* right) {
    LinkNode* rear = new LinkNode(); 
    LinkNode* head = rear;

    while (left && right) {
        if (left->data < right->data) {
            rear->next = left;
            left = left->next;//别忘了把left(right)往前进！
        } else {
            rear->next = right;
            right = right->next;//别忘了把left(right)往前进！
        }
        rear = rear->next;
    }

    // 将剩余的节点接到合并后的链表后面
    if (left) rear->next = left;
    if (right) rear->next = right;

    return head->next; 
}


LinkNode* listSort(LinkNode* head) {

    // 如果链表为空或只有一个节点，直接返回
    //必须加上
   if (!head || !head->next) return head;

    // 快慢指针法找中间节点
    //必须反复背下来！
    LinkNode* slow = head;
    LinkNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 断开链表
    //一定不能忘记断开，不然会导致运行时错误!
    LinkNode* right = slow->next;
    slow->next = nullptr;

    // 递归排序左半部分和右半部分
    LinkNode* left = listSort(head);
    right = listSort(right);

    // 合并已排序的左右部分
    return merge(left, right);
}

int main() {
    ifstream infile("in.txt");

    int val;
    LinkNode* head = new LinkNode(); 
    LinkNode* rear = head;

   
    while (infile >> val) {
        LinkNode* p = new LinkNode(val);
        rear->next = p;
        rear = rear->next;
    }
    infile.close(); //输入文件in.txt关闭后才能打开输出文件out.txt！

    
    head->next = listSort(head->next);

   
    ofstream outfile("out.txt"); //输入文件in.txt关闭后才能打开输出文件out.txt！
    
    LinkNode* printlist = head->next;
    while (printlist != nullptr) {
        outfile << printlist->data << " ";
        printlist = printlist->next;
    }

    outfile.close();

    return 0;
}
