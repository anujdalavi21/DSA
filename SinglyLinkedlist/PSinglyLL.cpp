#include<iostream>
using namespace std;
struct node
{
  int data;
  struct node * next;
};
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class SinglyLL
{
  private:
    PNODE Head;
  public:
    SinglyLL();
    void InsertFirst(int no);
    void InsertAtPos(int iPos,int no);
    void InsertLast(int no);
    void DeleteFirst();
    void DeleteAtPos(int iPos);
    void DeleteLast();
    void Display();
    int Count();
};

SinglyLL::SinglyLL()
{
  Head=NULL;
}

void SinglyLL ::InsertFirst(int no)
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
void SinglyLL::InsertAtPos(int iPos,int no)
{
  int Size=0;
  int iCnt=0;
  Size=Count();

  if((iPos<1)||(iPos>Size+1))
  {
    return;
  }

  if(iPos==1)
  { 
    InsertFirst(no);
  }
  else if(iPos==Size+1)
   {
    InsertLast(no);
  }
  else
  {
    PNODE newn=NULL;
    newn=new NODE;

    newn->data=no;
    newn->next=NULL;
    
    PNODE temp=NULL;
    temp=Head;

    for(iCnt=1;iCnt<iPos-1;iCnt++)
    {
      temp=temp->next;
    }
    newn->next=temp->next;
    temp->next=newn;

  }
  
}

void SinglyLL::InsertLast(int no)
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
    PNODE temp=NULL;
    temp=Head;
    
    while(temp->next!=NULL)
    {
      temp=temp->next;
    }
    temp->next=newn;

  }

}

void SinglyLL::DeleteFirst()
{
  PNODE temp=NULL;

  if(Head==NULL)
  {
    return;
  }
  else
  {
    temp=Head;
    Head=temp->next;

    delete temp;
  }


}

void SinglyLL :: DeleteLast()
{
  if(Head==NULL)
  {
    return;
  } 
  else if(Head->next==NULL)
  {
    delete Head;
    Head=NULL;
  } 
  else
  {
    PNODE temp=NULL;
    temp=Head;

    while(temp->next->next!=NULL)
    {
      temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;


  }

}

void SinglyLL:: DeleteAtPos(int iPos)
{
  int iSize=0;
  iSize=Count();

  if((iPos<1)||(iPos>iSize+1))
  {
    return;
  }

  if(iPos==1)
  {
    DeleteFirst();
  }
  else if(iPos==iSize+1)
  {
    DeleteLast();
  }
  else
  { 
    PNODE temp1=NULL;
    temp1=Head;
    PNODE temp2=NULL;

    int iCnt=0;
    for(iCnt=1;iCnt<iPos-1;iCnt++)
    {
      temp1=temp1->next;
    }
    temp2=temp1->next;
    temp1->next=temp1->next->next;
    delete temp2;

  }

}

void SinglyLL:: Display()
{
  PNODE temp=NULL;
  temp=Head;

  while(temp!=NULL)
  {
   cout<<"|"<<temp->data<<"|->";
    temp=temp->next;
  }
  cout<<"NULL\n";

}

int SinglyLL::Count()
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
   int iRet=0;
   SinglyLL obj;
   obj.InsertFirst(121);
   obj.InsertFirst(111);
   obj.InsertFirst(51);
   obj.InsertFirst(21);
  // obj.Display();

   obj.InsertLast(11);
   obj.InsertLast(101);
   
   obj.InsertAtPos(3,95);

   //obj.DeleteFirst();

 //  obj.DeleteLast();
 
   obj.DeleteAtPos(3);

   obj.Display();

   iRet=obj.Count();
   cout<<"Total nodes are:"<<iRet<<endl;
  
  return 0;
}