#include "sorted.h";
#include <iostream>

using namespace std;

void SortedType::InsertItem(ItemType item)
{
	bool moreToSearch;
	int location = 0;

	moreToSearch = (location < length);
	while (moreToSearch)
	{
		switch (item.ComparedTo(info[location]))
		{
		case RelationType::LESS: moreToSearch = false;
			break;
		case RelationType::GREATER: location++;
			moreToSearch = (location < length);
			break;
		}
	}
		for (int index = length; index > location; index--)
			info[index] = info[index - 1];
		info[location] = item;
		length++;
}

void SortedType::DeleteItem(ItemType item)
{
	int location = 0;
	while (item.ComparedTo(info[location]) != RelationType::EQUAL)
		location++;

	for (int index = location + 1; index < length; index++)
		info[index - 1] = info[index];

	length--;
}

void SortedType::RetrieveItem(ItemType& item, bool& found)
{
	int midPoint;
	int first = 0;
	int last = length - 1;
	bool moreToSearch = (first <= last);

	found = false;
	while (moreToSearch && !found)
	{
		midPoint = (first + last) / 2;
		switch (item.ComparedTo(info[midPoint]))
		{
		case RelationType::LESS:
			last = midPoint - 1;
			moreToSearch = (first <= last);
			break;
			case RelationType::GREATER:
				first = midPoint + 1;
				moreToSearch = (first <= last);
				break;
			case RelationType::EQUAL:
				found = true;
				item = info[midPoint];
				break;
		}
	}
}