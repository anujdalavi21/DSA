 #include<iostream>
using namespace std;
 
struct node
{
 int data;
 struct node * next;
 
}; 
typedef struct node NODE;
typedef struct node *PNODE;

class Stack
{
  private:
    PNODE Head;
  public:
    Stack();
    void Push(int no);
    void Pop();
    void Display();
    int Count();
};

Stack::Stack()
{
    Head=NULL;
}

void Stack::Push(int no)
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
   newn->next=Head;
   Head=newn;
 }

}

void Stack::Pop()
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

void Stack::Display()
{
  PNODE temp=NULL;
  temp=Head;

  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;

}


int Stack::Count()
{
  PNODE temp=NULL;
  temp=Head;
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
  Stack obj;
  int iRet=0;
  obj.Push(11);
  obj.Push(21);
  obj.Push(51);

  obj.Display();

  iRet=obj.Count();
  cout<<"Total nodes are:"<<iRet<<endl;
  
  //obj.Pop();

 // obj.Display();

 // iRet=obj.Count()
  //cout<<"Total nodes in Stack are:"<<iRet<<endl;

    return 0;
}