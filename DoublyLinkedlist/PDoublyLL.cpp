#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyLL
{
    private:
        PNODE Head;
        PNODE Tail;
        

     public:
        DoublyLL();

        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        int Count();
        void Display();
};

DoublyLL::DoublyLL()
{
   Head = NULL;
   Tail = NULL;
   
}

void DoublyLL:: InsertFirst(int no)
{
  PNODE newn=NULL;
  
  newn=new NODE;

  newn->data=no;
  newn->next=NULL;
  newn->prev=NULL;

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

void DoublyLL::InsertLast(int no)
{
  PNODE newn=NULL;
  newn=new NODE;

  newn->data=no;
  newn->next=NULL;
  newn->prev=NULL;

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
   newn->prev=temp;
 }


}

void DoublyLL::InsertAtPos(int iPos,int no)
{
   int iSize=0;
   iSize=Count();

   if((iPos<1)||(iPos>iSize+1))
   {
    return;
   }

   if(iPos==1)
   {
    InsertFirst(no);
   }
  else if(iPos==iSize+1)
  {
   InsertLast(no);

  }
  else
  {
    int iCnt=0;
    PNODE temp=Head;
    PNODE newn=new NODE;
   
   newn->data=no;
   newn->next=NULL;
   newn->prev=NULL;

   for(iCnt=1;iCnt<iPos-1;iCnt++)
   {
     temp=temp->next;
      
   }
   newn->next=temp->next;
   temp->next->prev=newn;
   temp->next=newn;
   newn->prev=temp;

  }

}

void DoublyLL::DeleteFirst()
{
  if(Head==NULL)
  {
    return;
  }

  if(Head->next==NULL)
  {
    delete Head;
    Head=NULL;

  }

  else
  {
    Head=Head->next;

    delete Head->prev;

    Head->prev=NULL;

  }

}

void DoublyLL:: DeleteLast()
{
 PNODE temp=NULL;
 temp=Head;

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

    while(temp->next->next!=NULL)
    {
      temp=temp->next;
    }

    delete temp->next;
    temp->next=NULL; 


  }

}

void DoublyLL::DeleteAtPos(int iPos)
{
   int iSize=0;
   iSize=Count();

   if((iPos<1)||(iPos>iSize))
   {
    return;
   }

   if(iPos==1)
   {
    DeleteFirst();
   }
  else if(iPos==iSize)
  {
   DeleteLast();

  }
  else
  {
    int iCnt=0;
    PNODE temp=Head;

   for(iCnt=1;iCnt<iPos-1;iCnt++)
   {
     temp=temp->next;
      
   }
  temp->next=temp->next->next;

  delete(temp->next->prev);

  temp->next->prev=temp;

  }

}



void DoublyLL :: Display()
{
  PNODE temp=Head;
  while(temp!=NULL)
  {
   cout<<"|"<<temp->data<<"|->";
   temp=temp->next;

  }
 cout<<"NULL\n";

}

int DoublyLL :: Count()
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
  DoublyLL obj;
  obj.InsertFirst(11);
  obj.InsertFirst(21);
  obj.InsertFirst(51);

 obj.InsertLast(111);
 obj.InsertLast(101);

 //obj.InsertAtPos(3,95);
  obj.DeleteAtPos(3);
  obj.Display();
  int iRet=obj.Count();
  cout<<"Total nodes are:"<<iRet;
    return 0;
}
 