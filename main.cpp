#include<iostream>

using namespace std;

template<class E>
struct Node
{
    E data;
    Node<E> * next;

    Node();
    Node(E item, Node<E> *link = NULL);
};

template<class E>
Node<E>::Node()
{
    next = NULL;
}

template<class E>
Node<E>::Node(E item, Node<E> *link)
{
    data = item;
    next = link;
}

template<class E>
class List
{
protected:
    Node<E> *head;
    Node<E> *GetPtr(int pos) const;
public:
    List();
    ~List();
    int Length() const;
    bool Empty() const;
    void Clear();
    void Traverse(void(*visit)(const E &)) const;
    bool GetElem(int position, E &e) const;
    bool SetElem(int positionm, const E &e);
    bool Delete(int positionm, E &e);
    bool Insert(int position, const E &e);

};
int main()
{

}