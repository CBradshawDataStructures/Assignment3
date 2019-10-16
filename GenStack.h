//Chase Bradshaw
#include <iostream>

using namespace std;

template<typename t>
class GenStack{
public:
    //variables
    int size;
    int top;
    t*myArray;

    //constructors & destructor
    GenStack();
    GenStack(int maxSize);
    ~GenStack();

    //methods
    int getTop();
    void push(t d);
    char pop();
    char peek();
    bool isFull();
    bool isEmpty();
    void print();
    int getSize();
};
