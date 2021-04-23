#include <iostream>
#include <forward_list>
using namespace std;
template <typename KeyType, typename ValueType, typename Hasher = std::hash<KeyType>>
class hash_table
{
public:
	hash_table()
	{
		m_size = 5;
		m_list_size = 3;
		list = new std::forward_list<std::pair<const KeyType, ValueType>>[m_size];
	}
	~hash_table() {
		delete[] list;
	}
	void insert(pair<KeyType, ValueType> value)
	{
		int index = hash(value.first) % m_size;
		int counter = 0;
		for (auto it : list[index]) {
			if (it.first == value.first)
			{
				throw std::domain_error("the value with the given key already exists");
			}
			++counter;
		}
		if (counter >= m_size) {
			rehash(m_size * 2);
			insert(value);
		}
		else
		{
			list[index].push_front(value);
		}
	}
	void print()
	{
		for (int i = 0; i < m_size; ++i) {
			for (auto it : list[i])
				std::cout << "key : " << it.first << "\tvalue : " << it.second << '\n';
		}
	}
	void rehash(int newSize)
	{
		int oldSize = m_size;
		m_size = newSize;
		forward_list<pair<const KeyType, ValueType>>* oldList = list;
		list = new forward_list<pair<const KeyType, ValueType>>[m_size];
		for (int i = 0; i < m_size; ++i)
		{
			list[i] = forward_list<pair<const KeyType, ValueType>>();
		}
		for (int i = 0; i < oldSize; ++i) {
			for (auto it : oldList[i])
			{
				insert(it);
			}
		}
	}
	bool contains(const KeyType key)
	{
		int index = hash(key) % m_size;
		for (auto it : list[index]) {
			if (it.first == key)
			{
				return true;
			}
		}
		return false;
	}
	void erase(const KeyType key)
	{
		int index = hash(key) % m_size;
		auto temp = list[index].begin();
		for (auto it = list[index].begin(); it != list[index].end(); ++it) {
			if ((*it).first == key) {
				if (it == list[index].begin()) {
					list[index].pop_front();
					break;
				}
				list[index].erase_after(temp);
			}
			break;
			temp = it;
		}
	}
	void clear()
	{
		delete[] list;
		m_size = 5;
		m_list_size = 3;
		list = new forward_list<pair<const KeyType, ValueType>>[m_size];
		for (int i = 0; i < m_size; i++)
		{
			list[i] = forward_list<pair<const KeyType, ValueType>>();
		}
	}
	
	ValueType operator[](const KeyType key) const
	{
		int index = hash(key) % m_size;
		for (auto it = list[index].begin(); it != list[index].end(); ++it) 
		{
			if ((*it).first == key)
			{
				return (*it).second;
			}
		}
		throw domain_error("Key error:(");
	}
	hash_table& operator=(const hash_table& other)
	{
		this->m_size = other.m_size;
		this->m_list_size = other.m_list_size;
		this->list = new forward_list<pair<const KeyType, ValueType>>[m_size];
		for (int i = 0; i < m_size; i++)
			list[i] = forward_list<pair<const KeyType, ValueType>>();
		for (int i = 0; i < m_size; i++) {
			for (auto it : other.list[i])
				insert(it);
		}
		return *this;
	}
private:
	Hasher hash;
	int m_size;
	int m_list_size;
	forward_list<pair<const KeyType, ValueType>>* list;
};
int main()
{
	hash_table<int, int> ht;
	ht.insert({1, 2});
	ht.insert({ 5, 6 });
	ht.insert({ 9, 10 });
	ht.print();
	ht.erase(9);
	ht.print();
	cout << ht.contains(1) << endl;
	cout << ht[5] << endl;
	hash_table<int, int> ht_next;
	ht_next = ht;
	ht_next.print();
	return 0;
}