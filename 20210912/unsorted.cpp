#include "unsorted.h"
#include <iostream>

using namespace std;

UnsortedType::UnsortedType()
{
	length = 0;
	currentPos = 0;
}

void UnsortedType::InsertItem(ItemType item)
{
	info[length] = item;
	length++;
}

int UnsortedType::LengthIs() const
{
	return length;
}

bool UnsortedType::IsFull() const
{
	return (length == MAX_ITEM);
}

void UnsortedType::RetrieveItem(ItemType& item, bool& found)
{
	bool moreToSearch;
	int location = 0;

	found = false;
	moreToSearch = (location < length);
	while (moreToSearch && !found)
	{
		switch (item.ComparedTo(info[location]))
		{
		case RelationType::LESS: cout << "1" << endl;
		case RelationType::GREATER: location++;
			moreToSearch = (location < length);
			cout << "2" << endl;
			break;
		case RelationType::EQUAL: found = true;
			item = info[location];
			cout << "3" << endl;
			break;
		}
	}
}

void UnsortedType::DeleteItem(ItemType item)
{
	int location = 0;
	while (item.ComparedTo(info[location]) != RelationType::EQUAL)
		location++;
	info[location] = info[length - 1];
	length--;
}

void UnsortedType::ResetList()
{
	currentPos = -1;
}

void UnsortedType::GetNextItem(ItemType& item)
{
	currentPos++;
	item = info[currentPos];
}


ostream& operator<< (ostream& os, const UnsortedType& list)
{
	os << list.IsFull();
	return os;
}


int main()
{
	UnsortedType list1;
	ItemType e1, e2, e3, e4, e5;
	bool f;
	e1.Initialize(2);
	e2.Initialize(3);
	e3.Initialize(4);
	e4.Initialize(5);
	e5.Initialize(6);
	list1.InsertItem(e1);
	list1.InsertItem(e2);
	list1.InsertItem(e3);
	list1.InsertItem(e4);
	list1.InsertItem(e5);
	list1.RetrieveItem(e3, f);
	list1.RetrieveItem(e2, f);
	//cout << list1 <<  endl;
	return 0;
}