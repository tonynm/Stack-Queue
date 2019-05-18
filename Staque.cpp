#include <iostream>
#include <stdlib.h>
#include <new>
#include "Staque.h"

using namespace std;

/** Auxiliary Functions **/
int counter = 0;

/** Constructors **/
Staque::Staque()
: myTop(0), myBot(0)
{}

Staque::Staque(const Staque & original)
{
    myTop = 0;
    myBot = 0;
    if(!original.empty())
    {

        myTop = myBot = new Staque::Node(original.top());

        Staque::NodePointer origPtr = original.myTop->next;
        while(origPtr != 0)
        {
            myBot->next = new Staque::Node(origPtr->data);
            myBot = myBot->next;
            origPtr = origPtr->next;
        }
    }
}

//Definition of destructor
Staque::~Staque()
{
    Staque::NodePointer currPtr = myTop, nextPtr;
    while(currPtr != 0)
    {
        nextPtr = currPtr->next;
        delete currPtr;
        currPtr = nextPtr;
    }
}

//Definition of empty()
bool Staque::empty() const
{
    return(myTop == 0);
}

//Definition of push()
void Staque::push(const StackElement & value)
{
    Staque::NodePointer nxtptr = new Staque::Node(value);
    if(empty() == true)
    {
        myBot = nxtptr;
        myTop = nxtptr;
        myTop->order = counter;
    }
    else if(empty() == false)
    {
        nxtptr->next = myTop;
        myTop = nxtptr;
        myTop->order = ++counter;
    }
}

//Definition of enqueue()
void Staque::enqueue(const StackElement & value)
{
    Staque::NodePointer nextptr = new Staque::Node(value);
    if(empty() == true)
    {
        myTop = nextptr;
        myBot = nextptr;
        myBot->order = counter;
    }
    else if(empty() == false)
    {
        myBot->next = nextptr;
        myBot = nextptr;
        myBot->order = ++counter;
    }

}

//Definition of pop()
void Staque::pop()
{
    if(myTop->order > myBot->order)
    {
        Staque::NodePointer ptr = myTop;
        myTop = ptr->next;
        delete ptr;
        if(myTop == 0)
        {
            myBot = 0;
        }
    }
    else if(myTop->order < myBot->order)
    {
        Staque::NodePointer ptr = myTop;
        Staque::NodePointer prevPtr = 0;
        while(ptr->next != 0)
        {
            prevPtr = ptr;
            ptr = ptr->next;
        }
        myBot = prevPtr;
        delete ptr;
        prevPtr->next = 0;
    }
    else if(myTop->order == myBot->order)
    {
        Staque::NodePointer ptr = myTop;
        delete ptr;
        myTop = 0;
        myBot = 0;
    }
}

//Definition of top()
StackElement Staque::top() const
{
    if(!empty())
    {
        return (myTop->data);
    }
    else
    {
        cerr << "Stack is empty\n" << "Returning Garbage\n" << endl;
        StackElement * temp = new(StackElement);
        StackElement garbage = *temp;
        delete temp;
        return garbage;
    }
}

//Definition of display()
void Staque::display(ostream & out) const
{
    Staque::NodePointer ptr;
    for(ptr = myTop; ptr != 0; ptr = ptr->next)
    {
        out << ptr->data << " " << endl;
    }
}
