#include "Multiset.h"
#include <cstring>

Multiset::Multiset()
	: length(0) {}

Multiset::~Multiset()
{
}

Multiset::Multiset(const Multiset& other)
	: length(other.length)
{
	memcpy(this->nodes, other.nodes, sizeof(this->nodes));
}

Multiset& Multiset::operator=(const Multiset& other)
{
	if (this != &other){
		Multiset temp(other);
		swap(temp);
	}
	return *this;
}

bool Multiset::insert(const ItemType& value)
{
	int i = find(value);
	if (i != -1)
		nodes[i].value++;
	else {
		if (length == DEFAULT_MAX_ITEMS)
			return false;
		nodes[length++] = Node(value, 1);
	}
	return true;
}

int Multiset::erase(const ItemType& value)
{
	int i = find(value);
	if (i == -1) return 0;
	if (--nodes[i].value == 0) nodes[i] = nodes[--length];
	return 1;
}

int Multiset::eraseAll(const ItemType& value)
{
	int i = find(value);
	if (i == -1) return 0;
	int ret = nodes[i].value;
	nodes[i] = nodes[--length];
	return ret;
}

inline
void Multiset::swap(Multiset& other)
{
	Node temp[DEFAULT_MAX_ITEMS];
	memcpy(temp, this->nodes, sizeof(this->nodes));
	memcpy(this->nodes, other.nodes, sizeof(this->nodes));
	memcpy(other.nodes, temp, sizeof(this->nodes));
	int i_temp = this->length;
	this->length = other.length;
	other.length = i_temp;
}
