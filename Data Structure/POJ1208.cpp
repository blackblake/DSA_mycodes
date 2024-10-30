#include <iostream>
using namespace std;

struct LinkNode
{
    int data;
    LinkNode* next;
    LinkNode* block;
    LinkNode(){
        next=NULL;
        block=NULL;
    }
    LinkNode(int d){
        data=d;
        next=NULL;
        block=NULL;
    }
};

struct LinkList{
    LinkNode* head;
    LinkList(){
        head=new LinkNode();
    }

};


void printList(LinkList l){
    LinkNode* p=l.head->next;
    while (p!=nullptr)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

//清空a上面的block并放回原地
void clearBlock(LinkList l,int x){ 
    LinkNode* p=l.head->next;
    LinkNode* q=nullptr;
    while (p!=nullptr)
    {
        if(p->data==x){
            //断掉x上面的连接
            q=p->block;
            p->block=nullptr;

            //再把上面的block放还
            while (q!=nullptr)
            {
                int val=q->data;
                LinkNode* pointer=l.head->next;
                while (pointer!=nullptr)
                {
                    if(pointer->data==(val-1)){
                        LinkNode* newPointer=new LinkNode(val);
                        newPointer->next=pointer->next;
                        pointer->next=newPointer;
                    }
                    pointer=pointer->next;
                }
                q=q->block;
                
            }
            
            p=p->next;
        }
    }
    
}

void moveOnto(LinkList l,int a,int b){
    //放回a和b上的所有blocks
    clearBlock(l,a);
    clearBlock(l,b);

    LinkNode* p=l.head->next;
    while (p!=nullptr)
    {   
       if(p->data==b){
        p->block=new LinkNode(a);
       }
       p=p->next;
    }
    
}

void moveOver(){
   

}

void pileOnto(){

}

void pileOver(){

}

int main(){
    int n;
    cin>>n;
    
    LinkList l;
    LinkNode* rear=l.head;

    for(int i=0;i<n;i++){
        rear->next=new LinkNode(i);
        rear=rear->next;
    }
    printList(l);

    string str1;
    while (cin>>str1)
    {
        if(str1=="move"){
            int a;string str2;
            cin>>a;cin>>str2;
            if(str2=="onto"){
                int b;
                cin>>b;
                moveOnto(l,a,b);
                printList(l);
            }
            else{
                int b;
                cin>>b;
              //  moveOver();
            }
        }

        else if(str1=="pile"){
            int a;string str2;
            cin>>a;cin>>str2;
            if(str2=="onto"){
                int b;
                cin>>b;
                pileOnto();
            }
            else{
                int b;
                cin>>b;
                pileOver();
            }
        }

        else{
            printList(l);
        }
    }
    
    return 0;
}