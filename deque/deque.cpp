#include <iostream>
using namespace std;

template <class T>
class deque
{
private:
    template <class T>
    class Node
    {
    public:

        T data;
        Node* pNext;
        Node* pPrev;
        Node(T data = T())
        {
            this->data = data;
            pNext = nullptr;
            pPrev = nullptr;
        }
    };

public:
    int size;
    int capacity;
    Node<T> *head;
    Node<T> *tail;
    deque()
    {
        capacity = 2;
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void push_back(T data)
    {
        if (tail == nullptr)
        {
            tail = new Node<T>(data);
            size++;
        }
        else
        {
            Node<T> *current = this->tail;
            while (current->pPrev != nullptr)
            {
                current = current->pPrev;
            }
            current->pPrev = new Node<T>(data);
            tail = current->pPrev;
            tail->pNext = current;
            size++;

        }
    }

    void push_front(T data)
    {
        if (head == nullptr)
        {
            head = new Node<T>(data);
            size++;
        }
        else
        {
            Node<T>* current = this->head;
            while (current->pNext != nullptr)
            {
                current = current->pNext;
            }
            current->pNext = new Node<T>(data);
            head = current->pNext;
            head->pPrev = current;
            size++;

        }
    }
    void pop_back()
    {
        cout << tail->data << endl;
        Node<T> *del = tail;
        tail = tail->pNext;
        tail->pPrev = nullptr;
        delete del;
    }
    void pop_front()
    {
        cout << head->data << endl;
        Node<T> *del = head;
        head = head->pPrev;
        head->pPrev = nullptr;
        delete del;
    }

};

int main()
{
    deque <int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.pop_back();
    d.pop_back();
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);
    d.pop_front();
    d.pop_front();
}