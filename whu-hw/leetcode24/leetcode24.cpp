#include <iostream>
using namespace std;

 struct ListNode {
 int val;
 ListNode *next;
 ListNode() : val(0), next(nullptr) {}
 ListNode(int x) : val(x), next(nullptr) {}
 ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


struct List //自己写的List结构体
{
    ListNode* head;
    List(){
        head=new ListNode();
    }

    void swapPairs() {  //关键函数
    
        ListNode* str=head->next;
        ListNode* front=head;
        ListNode* tail=str->next;
    
     while (tail!=nullptr) {
            str->next=tail->next;
            front->next=tail;
            tail->next=str;

    //自己添加的每次循环打印当前链表的代码段，方便调试        
    ListNode* p=head;
    while(p!=nullptr){
        cout<<p->val<<" ";
        p=p->next;
    }

           front=str;
           str=str->next;
           tail=str->next;
        }
    cout<<endl;
        }

    void creatList(int a[]){  //自己添加的尾插法创建链表的函数
        int rear=8;
        ListNode* back=head;

        for(int i=0;i<rear;i++){
            int data=a[i];
            ListNode* p=nullptr;
            p=new ListNode(data);
            
            back->next=p;
            back=back->next;
        }

    }
};



int main(){
    List l;
    int a[]={1,2,3,4,5,6,7,8};
    l.creatList(a);

    l.swapPairs();

    return 0;
}