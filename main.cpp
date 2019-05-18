#include <iostream>
#include "Staque.h"

using namespace std;

void print(Staque st)
{
    st.display(cout);
}
int main()
{
    int looper = 0;
    int reply = 0;
    int reply2 = 0;
    Staque s;
    cout << "The default staque has the following numbers in it: 1,3,2,4,6,8,9.\n" << endl;
    s.enqueue(1);
    s.enqueue(3);
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(8);
    s.enqueue(9);
    cout << "These numbers ordered by evens on the left and odds on the right will look like this: \n";
    s.display(cout); cout << endl;
    while(looper == 0)
    {
        cout << "Would you like to add to the Staque or take out from the Staque?\n"
        << "Please select from the following numbers: \n" << "1. Add to the Staque\n"
        << "2. Take out from the Staque\n" << "3. Exit the program\n" << endl;
        cin >> reply;
        cout << endl;
        if(reply == 1) /** Add numbers to the Staque **/
        {
            cout << "Please input the number you would like to add: " << endl;
            cin >> reply2;
            cout << endl;
            if(reply2%2 == 0)
            {
                s.push(reply2);
            }
            else if(reply%2 == 1)
            {
                s.enqueue(reply2);
            }
            cout << "The updated staque is: " << endl;
            s.display(cout); cout << endl;
        }
        else if(reply == 2)
        {
            if(s.empty() == false)
            {
                cout << "The numbers that will be removed will be the numbers that are last in the list or\n"
                << "last added into the staque (Last In First Out).\n" << endl;
                s.pop();
                cout << "The updated staque is: " << endl;
                s.display(cout); cout << endl;
            }
            else if(s.empty() == true)
            {
                cout << "The staque is empty. Please insert some numbers into the stack.\n" << endl;
            }
        }
        else if(reply == 3) /** Exits the program **/
        {
            cout << "Goodbye!\n" << endl;
            break;
        }
        else
        {
            cout << "Invalid number input.\n" << endl;
        }
    }
    return 0;
}
