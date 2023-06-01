#include<iostream>
using namespace std;

struct node
{
 int data;
 struct node * next; 
};
typedef struct node NODE;
typedef struct node * PNODE;

class Queue
{
  private:
     PNODE Head;

  public:
    Queue();
    void Enqueue(int no);
    void Dequeue();
    void Display();
    int Count();

};

Queue::Queue()
{
  Head=NULL;

}

void Queue::Enqueue(int no)    //InsertLast SinglyLinkedlist
{
 PNODE newn=NULL;
 newn=new NODE;
 
 newn->data=no;
 newn->next=NULL;

 if(Head==NULL)
 {
    Head=newn;
 }

 else
 { 
    PNODE temp=Head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
   temp->next=newn;
 } 

}

void Queue::Dequeue()
{
 PNODE temp=NULL;

 if(Head==NULL)
 {
    return;
 }

temp=Head;
Head=Head->next;
delete temp;
 
}

void Queue::Display()
{
 PNODE temp=Head;
 while(temp!=NULL)
 {
    cout<<temp->data<<" ";
    temp=temp->next;
 } 
cout<<endl; 

}


int Queue::Count()
{
 PNODE temp=Head;
 int iCnt=0;
 while(temp!=NULL)
 {
    iCnt++;
    temp=temp->next;
 } 
 return iCnt;

}


int main()
{
  Queue obj;

  obj.Enqueue(11);
  obj.Enqueue(21);
  obj.Enqueue(51);
  obj.Enqueue(101);

  //obj.Dequeue();

  obj.Display();
 int iRet=obj.Count();
 cout<<"Total nodes are:"<<iRet<<endl;

    return 0;
}