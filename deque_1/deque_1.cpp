#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
template <class T>
class Block
{
public:
    T chunk[4];
    Block()
    {
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
    bool IsOneChunk(bool direction)
    {
        if (direction)
        {
            int start_ch_index = start / 4;
            int start_index = start % 4;
            int end_ch_index = end  / 4;
            int end_index = end % 4;
            if (start_ch_index == end_ch_index && end_index < start_index)
            {
                return true;
            }
            return false;
        }
        else
        {
            int start_ch_index = start / 4;
            int start_index = start % 4;
            int end_ch_index = end  / 4;
            int end_index = end % 4;
            if (start_ch_index == end_ch_index && end_index < start_index)
            {
                return true;
            }
            return false;
        }
        
    }
    void push_back(T data)
    {
        bool direction = true;
        
        if (IsOneChunk(direction))
        {
            resize(direction);
        }
        int buff = 0;
        buff = end / 4;
        int i = 0;
        i = end % 4;
        Block<T>* temp = adress[buff];
        temp->chunk[i] = data;
        end += 1;
        end %= adress.size() * 4;
        size++;

    }
    void push_front(T data)
    {
        bool direction = false;
        
        start += adress.size() * 4 - 1;
        start %= adress.size() * 4;
        if (IsOneChunk(direction))
        {
            resize(direction);
        }
        int chunk_index = start / 4;
        int i = start % 4;
        Block<T>* temp = adress[chunk_index];
        temp->chunk[i] = data;
        size++;
    }
    void resize(bool flag)
    {
        if (flag)
        {
            int chunk_index = end / 4;
            
            for (int i = 0; i < capacity; i++)
            {
                auto it = adress.begin();
                adress.insert(it + chunk_index, new Block<T>());
            }
            
            end += capacity * 4;
            capacity *= 2;
            
        }
        else
        {
            int chunk_index = (start + 1) / 4;
            
            for (int i = 0; i < capacity; i++)
            {
                auto it = adress.begin();
                adress.insert(it + chunk_index, new Block<T>());
            }
            start += capacity * 4;
            capacity *= 2;
            
        }
        
    }
    void PrintElement(int index)
    {
        int buff = (start + index) % (capacity*4);
        int chunk_index = buff / 4;
        int i = buff % 4;
        Block<T>* temp = adress[chunk_index];
        cout << temp->chunk[i]<< endl;
        /*for (int i = 0; i < adress.size(); i++)
        {
            Block<T>* temp = adress[i];
            for (int j = 0; j < 4; j++)
            {
                cout << temp->chunk[j] << " ";
            }
            cout << endl;
        }*/
        
    }
private:
    int start = 0;
    int end = 0;

};

int main()
{
    deque <int> d;
    
    d.push_front(100);
    d.push_back(10);
    d.push_front(200);
    d.push_back(20);
    d.push_front(300);
    d.push_front(400);
    d.push_front(500);
    d.push_front(600);
    d.push_front(700);
    d.push_back(30);
    d.push_back(40);
    d.push_back(50);
    for (int i = 0; i < d.size; i++)
    {
        d.PrintElement(i);
    }
    
}

