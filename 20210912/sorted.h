#pragma once
#include "itemtype.h"

class SortedType
{
public:
	void InsertItem(ItemType item);
	void DeleteItem(ItemType item);
	void RetrieveItem(ItemType& item, bool& found);

private:
	int length;
	ItemType info[MAX_ITEM];
	int currentPos;
};