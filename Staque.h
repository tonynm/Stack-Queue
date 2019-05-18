#include <iostream>

using namespace std;

#ifndef Staque_h
#define Staque_h

typedef int StackElement;

class Staque
{
public:
    /** Constructor **/
    Staque();
    Staque(const Staque & original);
    /** Destructor **/
    ~Staque();
    /** Assignment **/
    bool empty() const;
    void push(const StackElement & value);
    void display(ostream & out) const;
    void pop();
    void enqueue(const StackElement & value);
    StackElement top() const;


private:
    /** Node Class **/
    class Node
    {
    public:
        StackElement data;
        int order;
        Node * next;

        Node(StackElement value, int sequence = 0, Node * link = 0)
        : data(value), order(sequence), next(link)
        {}
    };

    typedef Node * NodePointer;
    /** Data Members **/
    NodePointer myTop;
    NodePointer myBot;
};
#endif // Staque_h
