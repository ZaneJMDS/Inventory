#include "Node.h"

Node::Node(int _key)
{
	key = _key;
	Item NewItem;
	value = NewItem;
	mpNext = nullptr;
	mpPrevious = nullptr;
}

Node::~Node()
{
}
