/*#include<iostream>
#include<fstream>
using namespace std;

struct queueNode
{
    int data;
    queueNode* next;
    queueNode(){
        next=nullptr;
    }
    queueNode(int val){
        data=val;
        next=nullptr;
    }
};


int main(){
    ifstream infile("in.txt");
    int n;int N=0;
    queueNode* head=new queueNode();
    queueNode* rear=head;
    while(infile>>n){
        queueNode* s=new queueNode(n);
        rear->next=s;
        rear=rear->next;
        N++;
    }
	infile.close();
	
	ofstream outfile("out.txt");
    queueNode*p=head;
    int x=1;
    
    while ((N%2==0&&x<=N/2)||(N%2==1&&x<=N/2+1))
    {
        if(p->next->data%2==1){
            queueNode*ptr=p->next;
            p->next=ptr->next;
            rear->next=ptr;
            ptr->next=nullptr;
            rear=rear->next;
        }
        p=p->next;
        x++;
    }
    
    queueNode*p2=head->next;
    while (p2){
        outfile<<p2->data<<" ";
        p2=p2->next;
    }
    outfile.close();
    
    return 0;
}*/

#include<iostream>
#include<fstream>
using namespace std;

struct queueNode
{
    int data;
    queueNode* next;
    queueNode(){
        next=nullptr;
    }
    queueNode(int val){
        data=val;
        next=nullptr;
    }
};


int main(){
    ifstream infile("in.txt");
    int n;int N=0;
    queueNode* head=new queueNode();
    queueNode* rear=head;
    while(infile>>n){
        queueNode* s=new queueNode(n);
        rear->next=s;
        rear=rear->next;
        N++;
    }
	infile.close();
	ofstream outfile("out.txt");
    queueNode*p=head;
    int x=1;
    
    while ((N%2==0&&x<=N-1)||(N%2==1&&x<=N))
    {
        if(x%2==1){
            queueNode*ptr=p->next;
            p->next=ptr->next;
            rear->next=ptr;
            ptr->next=nullptr;
            rear=rear->next;
        }
        p=p->next;
        x+=2;
    }
    
    queueNode*p2=head->next;
    while (p2){
        outfile<<p2->data<<" ";
        p2=p2->next;
    }
    outfile.close();
    return 0;
}