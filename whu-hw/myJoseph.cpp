#include <iostream>
using namespace std;

struct LinkNode
{
    int data;//每个人最初时的编号
    LinkNode* next;
    LinkNode(){
    	data=0;
        next=nullptr;
    }
    LinkNode(int d){
        data=d;
        next=nullptr;
    }
};


void kickout(LinkNode*& head,LinkNode*& rear,int N){

    int i=1;
    LinkNode* p=head;//指向首结点
    while (i!=N-1)
    {
        i++;
        p=p->next;
    }
    
    //此时p已指向报N-1的人,接下来删除第N个人
    LinkNode* temp=p->next;
    p->next=temp->next;
    temp->next=nullptr;
    
    //把第N个人入新链表newlist
    if(rear->data==0){
        rear->data=temp->data;
    }
    else{
        rear->next=temp;
        rear=rear->next;
    }

    //更新head结点
    head=p->next;
}

LinkNode* Joseph(LinkNode* &head,int N){
    LinkNode* newlist=new LinkNode();//新队列
    LinkNode* rear=newlist;//newlist is useless!!
	
    while (head->next!=head)//如果不是只剩下一个结点
    {
        kickout(head,rear,N);
    }
    
    //把剩下的最后一个结点也入新队
    head->next=nullptr;
    rear->next=head;
    rear=head;
	
	rear->next=newlist;
	
	return newlist;
}



int main(){
    int M;
    cin>>M;

    LinkNode* head=new LinkNode(1);
    LinkNode* back=head;
    for(int i=2;i<=M;i++){
        back->next=new LinkNode(i);
        back=back->next;
    }
    back->next=head;

    int N;
    while(cin>>N)
    {
        head=Joseph(head,N);
    }
    
    LinkNode* p=head;
    cout<<"   "<<p->data<<"   ";
    p=p->next;
    while (p->next->next!=head)
    {
        cout<<p->data<<"   ";
        p=p->next;
    }
    cout<<p->data<<"  "<<p->next->data;

    return 0;
}