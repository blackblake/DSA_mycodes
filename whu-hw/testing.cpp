#include <iostream>
using namespace std;

struct LinkNode{
    int data;
    LinkNode* next;
    LinkNode(){
        next=nullptr;
    }
    LinkNode(int d){
        data=d;
        next=nullptr;
    }
};

struct LinkList
{
public:
    LinkNode* head;

    LinkList(){
        head=new LinkNode();
    }
    
    LinkList merge(LinkList l,LinkList r){
        LinkNode* x1=l.head->next;
        LinkNode* x2=r.head->next;
        LinkList newlist;
        LinkNode* rear=newlist.head;

        while (x1!=nullptr&&x2!=nullptr)
        {
            if(x1->data<x2->data){
                LinkNode* newnode=new LinkNode(x1->data);
                rear->next=newnode;
                rear=newnode;
                x1=x1->next;
            }
            else if(x1->data>x2->data){
                LinkNode* newnode=new LinkNode(x2->data);
                rear->next=newnode;
                rear=newnode;
                x2=x2->next;
            }
        }

        if(x1==nullptr){
            rear->next=x2;
        }
        if(x2==nullptr){
            rear->next=x1;
        }
        
        return newlist;
    }

    
    void listSort(){
        LinkList left;
        LinkList right;
        merge(left,right);
    }

};

LinkList merge(LinkList l,LinkList r){
        LinkNode* x1=l.head->next;
        LinkNode* x2=r.head->next;
        LinkList newlist;
        LinkNode* rear=newlist.head;

        while (x1!=nullptr&&x2!=nullptr)
        {
            if(x1->data<x2->data){
                LinkNode* newnode=new LinkNode(x1->data);
                rear->next=newnode;
                rear=newnode;
                x1=x1->next;
            }
            else if(x1->data>x2->data){
                LinkNode* newnode=new LinkNode(x2->data);
                rear->next=newnode;
                rear=newnode;
                x2=x2->next;
            }
        }

        if(x1==nullptr){
            rear->next=x2;
        }
        if(x2==nullptr){
            rear->next=x1;
        }
        
        return newlist;
    }

    

int main(){
  LinkList l;
  LinkList r;

  for(int i=0;i<3;i++){
    int val;
    cin>>val;
    LinkNode* p=new LinkNode(val);
    p->next=l.head->next;
    l.head->next=p;
  }

    for(int i=0;i<3;i++){
    int val;
    cin>>val;
    LinkNode* p=new LinkNode(val);
    p->next=r.head->next;
    r.head->next=p;
  }

    merge(l,r);

    return 0;
}
