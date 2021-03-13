#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
template <class T>
class Block
{
public:
    T* chunk;
    Block()
    {
        chunk = new T[4];

    }
    T* GetChunk()
    {
        return chunk;
    }
};


template <class T>
class deque : public Block<T>
{
public:
    vector <Block<T>*> adress;
    int size = 0;
    int capacity = 2;
    deque()
    {
        for (int i = 0; i < capacity; i++)
        {
            Block<T>* b = new Block<T>();
            adress.push_back(b);

        }



    }
    void IsOneChunk(bool direction)
    {
        if (start / 4 == end / 4)
        {
            if (!direction)
            {
                resize(false);
            }
            else { resize(true); }
        }
    }
    void push_back(T data)
    {
        bool direction = true;
        int buff = 0;
        buff = end / 4;
        int i = 0;
        i = end % 4;
        Block<T>* temp = adress[buff];
        temp->chunk[i] = data;
        end += 1;
        end %= adress.size() * 4;


    }
    void push_front(T data)
    {
        bool direction = false;
        start += adress.size() * 4 - 1;
        start %= adress.size() * 4;
        int chunk_index = start / 4;
        int i = start % 4;
        IsOneChunk(direction);
        Block<T>* temp = adress[chunk_index];
        temp->chunk[i] = data;
    }
    void resize(bool flag)
    {
        if (flag)
        {
            int chunk_index = end / 4;
            auto it = adress.begin();
            for (int i = 0; i < capacity; i++)
            {
                adress.insert(it + i + chunk_index, new Block<T>());
            }
            capacity *= 2;
        }
        else
        {
            int chunk_index = start / 4;
            auto it = adress.begin();
            for (int i = 0; i < capacity; i++)
            {
                adress.insert(it + i + chunk_index, new Block<T>());
            }
            capacity *= 2;
        }
        
    }
    void PrintElement(int index)
    {
        int chunk_index = (start + index) % 12;
        int buff = chunk_index / 4;
        int i = chunk_index % 4;
        Block<T>* temp = adress[buff];
        cout << temp->chunk[i]<< endl;
        
    }
private:
    int start = 0;
    int end = 0;

};

int main()
{
    deque <int> d;
    
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);
    d.push_front(400);
    d.push_front(500);

    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_back(40);
    d.push_back(50);
    for (int i = 0; i < 10; i++)
    {
        d.PrintElement(i);
    }
}

