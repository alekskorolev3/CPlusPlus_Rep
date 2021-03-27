#include <iostream>
using namespace std;

template <class T1, class T2>
class Map
{
private:
	struct Node
	{
		pair<T1, T2> data;
		Node* left;
		Node* right;
	};
	Node* tnode;
	Node* thead;
	int _size;
public:
	int _index;
	Map()
	{
		tnode = nullptr;
		thead = nullptr;
		_size = 0;
		_index = 0;
	}
	Node* getHead()
	{
		return thead;
	}

	void add(T1 key, T2 value)
	{
		if (tnode == nullptr)
		{
			tnode = new Node;
			thead = tnode;
			tnode->data.first = key;
			tnode->data.second = value;
			tnode->left = nullptr;
			tnode->right = nullptr;
		}
		else
		{
			Node* cur = thead;
			while (true)
			{
				
				if (key < cur->data.first)
				{
					if (cur->left == nullptr)
					{
						
						cur->left = new Node;
						cur = cur->left;
						cur->left = nullptr;
						cur->right = nullptr;
						cur->data.first = key;
						cur->data.second = value;
						break;
					}
					cur = cur->left;
				}
				if (key > cur->data.first)
				{
					if (cur->right == nullptr)
					{
						cur->right = new Node;
						cur = cur->right;
						cur->left = nullptr;
						cur->right = nullptr;
						cur->data.first = key;
						cur->data.second = value;
						break;
					}
					cur = cur->right;
				}
			}
		}
	}

	void print(Node* cur)
	{
		
		if (cur != nullptr)
		{
			print(cur->left);
			cout << cur->data.first << " " << cur->data.second << endl;
			print(cur->right);
		}
	}

	int size()
	{
		return _size;
	}
	bool empty()
	{
		if (thead == nullptr)
		{
			return true;
		}
		return false;
	}
	Node* find(Node* cur, T1 key)
	{
		if (key == cur->data.first || cur == nullptr)
		{
			return cur;
		}
		if (key < cur->data.first)
		{
			return find(cur->left, key);
		}
		else
		{
			return find(cur->right, key);
		}
	}

};

int main()
{
	Map<int, char> map;
	map.add(10, 'a');
	map.add(5, 'b');
	map.add(20, 'c');
	map.add(1, 'd');
	map.add(8, 'e');
	map.add(40, 'f');
	map.print(map.getHead());
	auto it = map.find(map.getHead(), 8);
	cout << it->data.first << " " << it->data.second;
	return 0;

}