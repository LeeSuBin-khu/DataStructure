#include "unsorted.h"

UnsortedType::UnsortedType()
{
	length = 0;
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
		case RelationType::LESS:
		case RelationType::GREATER: location++;
			moreToSearch = (location < length);
			break;
		case RelationType::EQUAL: found = true;
			item = info[location];
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