typedef unsigned long ItemType;
const int DEFAULT_MAX_ITEMS = 200;

class Multiset
{
  public:
	Multiset();    // Create an empty multiset.
	~Multiset();
	Multiset(const Multiset& other);
	Multiset& operator=(const Multiset& other);

	bool empty() const;  // Return true if the multiset is empty, otherwise false.

	int size() const;
	  // Return the number of items in the multiset.  For example, the size
	  // of a multiset containing "cumin", "cumin", "cumin", "turmeric" is 4.

	int uniqueSize() const;
	  // Return the number of distinct items in the multiset.  For example,
	  // the uniqueSize of a multiset containing "cumin", "cumin", "cumin",
	  // "turmeric" is 2.
 
	bool insert(const ItemType& value);
	  // Insert value into the multiset.  Return true if the value was
	  // actually inserted.  Return false if the value was not inserted
	  // (perhaps because the multiset has a fixed capacity and is full).
 
	int erase(const ItemType& value);
	  // Remove one instance of value from the multiset if present.
	  // Return the number of instances removed, which will be 1 or 0.
 
	int eraseAll(const ItemType& value);
	  // Remove all instances of value from the multiset if present.
	  // Return the number of instances removed.
 
	bool contains(const ItemType& value) const;
	  // Return true if the value is in the multiset, otherwise false.
 
	int count(const ItemType& value) const;
	  // Return the number of instances of value in the multiset.

	int get(int i, ItemType& value) const;
	  // If 0 <= i < uniqueSize(), copy into value an item in the
	  // multiset and return the number of instances of that item in
	  // the multiset.  Otherwise, leave value unchanged and return 0.
	  // (See below for details about this function.)

	void swap(Multiset& other);
	  // Exchange the contents of this multiset with the other one.
	  
  private:
	int find(const ItemType& value) const;

	struct Node
	{
		Node() {}
		Node(ItemType k, int v) : key(k), value(v) {}
		ItemType key;
		int value;
	};

	Node nodes[DEFAULT_MAX_ITEMS];
	int length;
};

inline
bool Multiset::empty() const 
{
	return length == 0;
}

inline
int Multiset::size() const
{
	int ret = 0;
	for (int i = 0; i < length; i++)
		ret += nodes[i].value;
	return ret;
}

inline
int Multiset::uniqueSize() const
{
	return length;
}

inline
bool Multiset::contains(const ItemType& value) const
{
	return find(value) != -1;
}

inline
int Multiset::count(const ItemType& value) const
{
	int i = find(value);
	return (i == -1) ? 0 : nodes[i].value;
}

inline
int Multiset::get(int i, ItemType& value) const
{
	if (i < 0 || i >= uniqueSize()) return 0;
	value = nodes[i].key;
	return nodes[i].value;
}

inline
int Multiset::find(const ItemType& value) const
{
	for (int i = 0; i < length; i++)
		if (nodes[i].key == value)
			return i;
	return -1;
}
