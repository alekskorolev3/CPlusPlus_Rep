#include <iostream>
#include <vector>

using namespace std;


template <class T>
class Block
{
protected:
    T *chunk;
    
public:
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
    int start;
    int end;
    deque();
    bool IsOneChunk(bool direction);
    void push_back(T data);
    void push_front(T data);
    void resize(bool flag);
    void pop_back();
    void pop_front();
    void clear();
    bool empty();
    int size();
    
    
    T& operator [] (const int index)
    {
        int buff = (start + index) % (capacity * 4);
        int chunk_index = buff / 4;
        int i = buff % 4;
        Block<T>* temp = adress[chunk_index];
        return temp->GetChunk()[i];
    }
   
    class Iterator
    {
    private:
        Block<T>* node;
        deque<T>* pointer;
        int index;
        int s;
        int e;
    public:
        Iterator()
        {
            node = nullptr;
            pointer = nullptr;
            index = 0;
            s = 0;
            e = 0;
        }
        Iterator(deque<T> *d, bool flag)
        {
            pointer = d;
            s = pointer->start;
            e = pointer->end;
            if (flag)
            {
                int chunk_index = s / 4;
                index = s % 4;
                node = pointer->adress[chunk_index];
            }
            else
            {
                int chunk_index = e / 4;
                index = e % 4;
                node = pointer->adress[chunk_index];
            }
        }
        T& operator *()
        {
            return node->GetChunk()[index];
        }
        Iterator operator ++()
        {
            s += pointer->capacity * 4 + 1;
            s %= pointer->capacity * 4;
            int chunk_index = s / 4;
            index = s % 4;
            node = pointer->adress[chunk_index];
            return *this;
        }
        Iterator operator --()
        {
            s += pointer->capacity * 4 - 1;
            s %= pointer->capacity * 4;
            int chunk_index = s / 4;
            index = s % 4;
            node = pointer->adress[chunk_index];
            return *this;
        }
        Iterator operator +(int index)
        {
            s += pointer->capacity * 4 + index;
            s %= pointer->capacity * 4;
            int chunk_index = s / 4;
            index = s % 4;
            node = pointer->adress[chunk_index];
            return *this;
        }
        Iterator operator -(int index)
        {
            s += pointer->capacity * 4 - index;
            s %= pointer->capacity * 4;
            int chunk_index = s / 4;
            index = s % 4;
            node = pointer->adress[chunk_index];
            return *this;
        }

    };
    Iterator Begin()
    {
        bool flag = true;
        Iterator buff(this, flag);
        return buff;
    }
    Iterator End()
    {
        bool flag = false;
        Iterator b(this, flag);
        return b;
    }
protected:
    
    int Size;
    int capacity;
    
};

template <class T>
deque<T>::deque()
{
    capacity = 2;
    for (int i = 0; i < capacity; i++)
    {
        Block<T>* b = new Block<T>();
        adress.push_back(b);
    }
    start = 0;
    end = 0;
    Size = 0;
}

template <class T>
bool deque<T>::empty()
{
    if (Size)
    {
        return false;
    }
    return true;
}

template <class T>
int deque<T>::size()
{
    return Size;
}

template <class T>
void deque<T>::clear()
{
    for (int i = 0; i < adress.size(); i++)
    {
        Block<T>* temp = adress[i];
        delete temp;
        adress[i] = nullptr;
        adress.clear();
    }
    deque();
}

template <class T>
void deque<T>::pop_back()
{
    end--;
    Size--;
}

template <class T>
void deque<T>::pop_front()
{
    start++;
    Size--;
}

template <class T>
void deque<T>::resize(bool flag)
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

template <class T>
void deque<T>::push_front(T data)
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
    temp->GetChunk()[i] = data;
    Size++;
}

template <class T>
void deque<T>::push_back(T data)
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
    temp->GetChunk()[i] = data;
    end += 1;
    end %= adress.size() * 4;
    Size++;

}

template <class T>
bool deque<T>::IsOneChunk(bool direction)
{
    if (direction)
    {
        int start_ch_index = start / 4;
        int start_index = start % 4;
        int end_ch_index = end / 4;
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
        int end_ch_index = end / 4;
        int end_index = end % 4;
        if (start_ch_index == end_ch_index && end_index < start_index)
        {
            return true;
        }
        return false;
    }

}




int main()
{
    deque <int> d;
    deque <int> ::Iterator it;
    
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
    d.pop_back();
    d.pop_front();
    it = d.Begin();
    cout << *(it + 3) << endl;
    
    
}

