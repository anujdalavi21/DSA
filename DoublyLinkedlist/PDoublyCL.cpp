#include <iostream>
using namespace std;
struct node
{
  int data;
  struct node *next;
  struct node *prev;
};
typedef struct node NODE;
typedef struct node *PNODE;

class DoublyCLL
{
private:
  int no;
  PNODE Head;
  PNODE Tail;
  int Countnode;

public:
  DoublyCLL();
  void InsertFirst(int no);
  void InsertLast(int no);
  void InsertAtPos(int no, int iPos);

  void DeleteFirst();
  void DeleteLast();
  void DeleteAtPos(int iPos);
  int Count();
  void Display();
};

DoublyCLL::DoublyCLL()
{
  Head = NULL;
  Tail = NULL;
  Countnode = 0;
}

void DoublyCLL::InsertFirst(int no)
{
  PNODE newn = NULL;
  newn = new NODE;

  newn->data = no;
  newn->next = NULL;
  newn->prev = NULL;

  if ((Head == NULL) && (Tail == NULL))
  {
    Head = newn;
    Tail = newn;
  }

  else
  {
    newn->next = Head;
    Head->prev = newn;
    Head = newn;
  }
  Head->prev = Tail;
  Tail->next = Head;

  Countnode++;
}

void DoublyCLL::InsertLast(int no)
{
  PNODE newn = NULL;
  newn = new NODE;

  newn->data = no;
  newn->next = NULL;
  newn->prev = NULL;

  if ((Head == NULL) && (Tail == NULL))
  {
    Head = newn;
    Tail = newn;
  }
  else
  {
    Tail->next = newn;
    newn->prev = Tail;
    Tail = newn;
  }
  Head->prev = Tail;
  Tail->next = Head;

  Countnode++;
}

void DoublyCLL::InsertAtPos(int iNo, int iPos)
{
  if ((iPos < 1) || (iPos > Countnode + 1))
  {
    cout << "Invalid position\n";
    return;
  }

  if (iPos == 1)
  {
    InsertFirst(iNo);
  }
  else if (iPos == Countnode + 1)
  {
    InsertLast(iNo);
  }
  else
  {
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    PNODE temp = Head;

    for (int i = 1; i < iPos - 1; i++)
    {
      temp = temp->next;
    }

    newn->next = temp->next;
    temp->next->prev = newn;
    temp->next = newn;
    newn->prev = temp;

    Countnode++;
  }
}
void DoublyCLL::DeleteFirst()
{
  if (Countnode == 0)
  {
    return;
  }

  if (Countnode == 1)
  {
    delete Head;
    Head = NULL;
    Tail = NULL;
  }
  else
  {
    Head = Head->next;
    delete Tail->next;
  }
  Head->prev = Tail;
  Tail->next = Head;

  Countnode--;
}

void DoublyCLL::DeleteLast()
{
  if (Countnode == 0)
  {
    return;
  }

  if (Countnode == 1)
  {
    delete Head;
    Head = NULL;
    Tail = NULL;
  }
  else
  {
    Tail = Tail->prev;
    delete Head->prev;
  }
  Head->prev = Tail;
  Tail->next = Head;

  Countnode--;
}

void DoublyCLL::DeleteAtPos(int iPos)
{

  if ((iPos < 1) || (iPos > Countnode + 1))
  {
    return;
  }

  if (iPos == 1)
  {
    DeleteFirst();
  }
  else if (iPos == Countnode)
  {
    DeleteLast();
  }

  else
  {
    PNODE temp = Head;
    for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
    {
      temp = temp->next;
    }
    temp->next = temp->next->next;
    delete temp->next->prev;
    temp->next->prev = temp;

    Countnode--;
  }
}

void DoublyCLL::Display()
{
  PNODE temp = Head;
  int iCnt = 0;
  for (iCnt = 1; iCnt <= Countnode; iCnt++)
  {
    cout << "|" << temp->data << "|->";
    temp = temp->next;
  }
  cout << "NULL\n";
}

int DoublyCLL::Count()
{
  return Countnode;
}

int main()
{
  DoublyCLL obj;
  obj.InsertFirst(11);
  obj.InsertFirst(21);
  obj.InsertFirst(51);
  obj.InsertLast(101);
   obj.InsertLast(101);

  //obj.InsertAtPos(112, 4);

  // obj.DeleteFirst();

  // obj.DeleteLast();
  obj.DeleteAtPos(4);
  obj.Display();

  int iRet = obj.Count();
  cout << "Total nodes are:" << iRet << endl;

  return 0;
}