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
		Node* parent;
	};
	
	Node* tnode;
	Node* thead;
	int _size;

	Node* min(Node* cur)
	{
		if (cur->left == nullptr)
		{
			return cur;
		}
		return min(cur->left);
	}

	Node* max(Node* cur)
	{
		if (cur->right == nullptr)
		{
			return cur;
		}
		return max(cur->right);
	}


public:


	class Iterator
	{
	private:
		Map<T1, T2>* mp;
		Node* tnode;
	public:
		Iterator()
		{

			tnode = nullptr;
		}
		Iterator(Map<T1, T2>* map)
		{
			mp = map;
			tnode = mp->min(mp->getHead());
		}

		

		Iterator& operator =(Node* cur)
		{
			tnode = cur;
			return *this;
		}
		Iterator& operator ++()
		{
			tnode = mp->next(tnode->data.first);
			return *this;
		}
		Node* operator *()
		{
			return tnode;
		}
	};

	Iterator Begin()
	{
		Iterator buff(this);
		return buff;
	}

	Map()
	{
		
		tnode = nullptr;
		thead = nullptr;
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
			tnode->parent = nullptr;
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
						cur->left->parent = cur;
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
						cur->right->parent = cur;
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

	T2& operator [](T1 key)
	{
		Node* temp = this->find(thead, key);
		return temp->data.second;
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

	Node* next(T1 key)
	{
		Node* cur = thead;
		Node* suc = nullptr;
		while (cur != nullptr)
		{
			if (key < cur->data.first)
			{
				suc = cur;
				cur = cur->left;
			}
			else
			{
				cur = cur->right;
			}
		}
		return suc;
	}

	Node* prev(T1 key)

	{
		Node* cur = thead;
		Node* suc = nullptr;
		while (cur != nullptr)
		{
			if (key > cur->data.first)
			{
				suc = cur;
				cur = cur->right;
			}
			else
			{
				cur = cur->left;
			}
		}
		return suc;
	}

	Node* erase (Node* cur, T1 key)
	{
		if (cur == nullptr)
		{
			return cur;
		}
		if (key < cur->data.first)
		{
			cur->left = erase(cur->left, key);
		}
		else if (key > cur->data.first)
		{
			cur->right = erase(cur->right, key);
		}
		else if (cur->left != nullptr && cur->right != nullptr)
		{
			cur->data.first = min(cur->right)->data.first;
			cur->right = erase(cur->right, cur->data.first);
		}
		else
		{
			if (cur->left != nullptr)
			{
				cur = cur->left;
			}
			else if (cur->right != nullptr)
			{
				cur = cur->right;
			}
			else
			{
				cur = nullptr;
			}
		}
		return cur;
	}

	
};


int main()
{
	Map<int, char> map;
	Map<int, char> :: Iterator It;
	map.add(10, 'a');
	map.add(5, 'b');
	map.add(20, 'c');
	map.add(1, 'd');
	map.add(8, 'e');
	map.add(40, 'f');
	auto head = map.getHead();
	map.print(head);
	map.erase(head, 5);
	It = map.Begin();
	++It;
	++It;
	++It;	
	cout << (*It)->data.first << endl;
	cout << map[8];
}