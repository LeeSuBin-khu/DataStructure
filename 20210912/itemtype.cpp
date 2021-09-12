#include "itemtype.h"
#include <iostream>

using namespace std;

RelationType ItemType::ComparedTo(ItemType otherItem) const
{
	if (value < otherItem.value)
		return RelationType::LESS;
	else if (value > otherItem.value)
		return RelationType::GREATER;
	else return RelationType::EQUAL;
}

void ItemType::Print() const
{
	cout << value << endl;
}

void ItemType::Initialize(int number)
{
	value = number;
}