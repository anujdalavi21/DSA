 #include<iostream>
using namespace std;
struct node
{
  int data;
  struct node * next;

};
typedef struct node NODE;
typedef struct node * PNODE;

class SinglyCLL
{
  private:
    PNODE Head;
    PNODE Tail;
  public:
    SinglyCLL();
    void InsertFirst(int no);
    void InsertLast(int no);
    void InsertAtPos(int iPos,int no);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
    void Display();
    int Count();


};

SinglyCLL::SinglyCLL()
{
    Head = NULL;
    Tail = NULL;
}

void SinglyCLL::InsertFirst(int no)
{
  PNODE newn=NULL; 
  newn=new NODE;

  newn->data=no;
  newn->next=NULL;

  if((Head==NULL)&&(Tail==NULL))
  {
    Head=newn;
    Tail=newn;

  }
  else
  {
    newn->next=Head;
    Head=newn;

  }
  Tail->next=Head;


}

void SinglyCLL:: InsertLast(int no)
{
    PNODE newn=NULL;
    newn=new NODE;

    newn->data=no;
    newn->next=NULL;

if((Head==NULL)&&(Tail==NULL))
{
    Head=newn;
    Tail=newn;
}
else
{
  Tail->next=newn;
  Tail=newn;

}
Tail->next=Head;
  
}

void SinglyCLL :: InsertAtPos(int iPos,int no)
{
  int Size=Count();

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

    PNODE temp=Head;
    int iCnt=0;
    for(iCnt=1;iCnt<iPos-1;iCnt++)
    {
        temp=temp->next;
    }
    newn->next=temp->next;
    temp->next=newn;

  }

}

void SinglyCLL:: DeleteFirst()
{
    if(Head==NULL && Tail==NULL)
    {
        return;
    }
    else if(Head==Tail)
    {
        delete Head;
        Head=NULL;
        Tail=NULL;
    }
    else
    {
      Head=Head->next;
      delete Tail->next;
      Tail->next=Head;

    }



}

void SinglyCLL:: DeleteLast()
{
    if(Head==NULL && Tail==NULL)
    {
        return;
    }
    else if(Head==Tail)
    {
        delete Head;
        Head=NULL;
        Tail=NULL;
    }
    else
    {
     PNODE temp=Head;

     while(temp->next !=Tail)
     {
       temp=temp->next;
     }  
     delete Tail;
     Tail=temp;
     Tail->next=Head;
      
    }

}

void SinglyCLL :: DeleteAtPos(int iPos)
{
  int Size=Count();

  if((iPos<1)||(iPos>Size))
  {
    return;
  }

  if(iPos==1)
  {
    DeleteFirst();
  }
  else if(iPos==Size)
  {
    DeleteLast();
  }
  else
  {
    PNODE temp1=Head;
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


void SinglyCLL:: Display()
{ 
    PNODE temp=NULL;
    temp=Head;
    if(Head==NULL  && Tail==NULL)
    {
        return;
    }
    
    do
    {
      cout<<"|"<<temp->data<<"|->";
      temp=temp->next;  
        /* code */
    } while(temp!=Head);

    cout<<"|NULL|"<<endl;

}
    
    int SinglyCLL:: Count()
{ 
     int iCnt=0;
    PNODE temp=NULL;
    temp=Head;
    if(Head==NULL  && Tail==NULL)
    {
        return 0;
    }
    
    do
    {
      iCnt++;
      temp=temp->next;  
        /* code */
    } while(temp!=Head);
    return iCnt;
  

}

int main()
{ 
    SinglyCLL obj;
    int iRet=0;
    obj.InsertFirst(11);
    obj.InsertFirst(21);
    obj.InsertFirst(51);
    obj.InsertFirst(101);

    obj.InsertLast(111);
    obj.InsertLast(121);

   // obj.DeleteFirst();
  //obj.DeleteLast();

  //obj.InsertAtPos(3,123);
  obj.DeleteAtPos(3);

    obj.Display();
   
   iRet=obj.Count();
   cout<<"Total nodes are :"<<iRet<<endl;

    return 0;
}