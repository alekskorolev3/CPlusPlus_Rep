#include <iostream>
using namespace std;
template <class T>
class deque
{
public:
    deque();
    ~deque();
    void push_back(T data)
    {

    }
    void push_front(T data);
    void pop_back();
    void pop_front();
    void resize();
    
private:
    T* array;
    int size;
    int capacity;
    T* head;
    T* tail;
};
template <class T>
deque<T>::deque()
{
    size = 0;
    capacity = 2;
    array = new array[capacity];
    head = array;
    tail = array;
}
template <class T>
deque<T>:: ~deque()
{

}

int main()
{
    std::cout << "Hello World!\n";
}

