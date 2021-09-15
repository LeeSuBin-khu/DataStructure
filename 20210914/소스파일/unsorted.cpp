// Implementation file for Unsorted.h
#include "unsorted.h"
#include <iostream>

using namespace std;

UnsortedType::UnsortedType()
{
  length = 0;
}
bool UnsortedType::IsFull() const
{
  return (length == MAX_ITEMS);
}

int UnsortedType::LengthIs() const
{
  return length;
}
void UnsortedType::RetrieveItem(ItemType& item, bool& found) 
// Pre:  Key member(s) of item is initialized. 
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item; 
//       otherwise, item is unchanged. 
{
  bool moreToSearch;
  int location = 0;
  found = false;

  moreToSearch = (location < length);

  while (moreToSearch && !found) 
  {
    switch (item.ComparedTo(info[location]))
    {
      case LESS    : 
      case GREATER : location++;
                     moreToSearch = (location < length);
                     break;
      case EQUAL   : found = true;
                     item = info[location];
                     break;
    }
  }
}
void UnsortedType::InsertItem(ItemType item)
// Post: item is in the list.
{
  info[length] = item;
  length++;
}
void UnsortedType::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
  int location = 0;

  while (item.ComparedTo(info[location]) != EQUAL)
    location++;

  info[location] = info[length - 1];
  length--;
}

void UnsortedType::ResetList()
// Post: currentPos has been initialized.
{
  currentPos = -1;
}

void UnsortedType::GetNextItem(ItemType& item)
// Post: item is current item.
//       Current position has been updated.
{
  currentPos++;
  item = info[currentPos];
}

void UnsortedType::DeleteItem_a(ItemType item)
{
    int location = 0;

    while (item.ComparedTo(info[location]) != EQUAL)
    {
        location++;
        if (location == (length - 1))
        {
            break;
        }
    }

    if (location != (length - 1))
    {
        info[location] = info[length - 1];
        length--;
    }

    for (int i = 0;i < length;i++)
    {
        info[i].Print(cout);
        cout << endl;
    }
}

void UnsortedType::DeleteItem_c(ItemType item)
{
    int temp1[MAX_ITEMS];
    int temp2[MAX_ITEMS];
    int num1 = 0;
    int num2 = 0;

    ItemType t1;
    t1.Initialize(0);

    for (int i = 0;i < length;i++)
    {
        if (item.ComparedTo(info[i]) == EQUAL)
        {
            temp1[num1] = i;
            num1++;
        }
        else
        {
            temp2[num2] = i;
            num2++;
        }
    }

    for (int j = 0;j < num1;j++)
    {
        if (num2 <= 0)
        {
            info[temp1[j]] = t1;
        }
        else
        {
            info[temp1[j]] = info[temp2[num2 - 1]];
        }
        length--;
        num2--;
    }

    for (int i = 0;i < length;i++)
    {
        info[i].Print(cout);
        cout << endl;
    }
    cout << endl << endl;
}