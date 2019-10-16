//Chase Bradshaw
#include <iostream>
#include <array>
#include "GenStack.h"

using namespace std;

//constructor
template<typename t>
GenStack<t>::GenStack(){
    myArray = new t[128];
    size = 128;
    top = -1;

    //initializes all elements to 0

    for (int i=0; i<size; ++i){
        myArray[i]='0';
    }
}

//parameter constructor
template<typename t>
GenStack<t>::GenStack(int maxSize){
    myArray = new t[maxSize];
    size = maxSize;
    top = -1;
}

//destructor
template<typename t>
GenStack<t>::~GenStack(){
    delete[]myArray;
}

//returns top value of stack
template<typename t>
int GenStack<t>::getTop(){
    return top;
}

template<typename t>
void GenStack<t>::push(t d){
    //if stack is not full
    if (isFull()==false){
        for(int i = 0; i<size; ++i){
            if (myArray[i]=='0'){
                myArray[i]=d;
                break;
            }
        }
    }
    else{
        //creates new array with increased size
        t*newArray = new t[size+128];
        //sets new values in larger array to 0
        for (int i=size; i<size+128; ++i){
            myArray[i]=0;
        }
        //corrects size value
        size = size+128;
        //coppies over
        for (int i = 0; i < size; ++i){
            newArray[i] = myArray[i];
        }
    }
}


template<typename t>
char GenStack<t>::pop(){
    char tempValue;
    //error checking, make sure its not isEmpty
    if (isEmpty()==false){
        //finds & saves value
        for (int i=0; i<size; ++i){
            if(myArray[i]=='0'){
                //saves value
                tempValue = myArray[i-1];
                //removes from array
                myArray[i-1]=0;
                break;
            }
        }
        //returns
        //cout<<"TEMPVAL: "<<tempValue<<endl;
        return tempValue;
    }
}

template<typename t>
char GenStack<t>::peek(){
    //check if isEmpty
    if (isEmpty()==false){
        return myArray[top];
    }
    else{
        cout<<"stack is empty"<<endl;
    }
}

template<typename t>
bool GenStack<t>::isFull(){
    return (top == size-1);
}
template<typename t>
bool GenStack<t>::isEmpty(){
    if (myArray[0]=='0'){
        //cout<<"TRUE"<<endl;
        return true;
    }
    else{
        return false;
    }
}

template<typename t>
void GenStack<t>::print(){
    for (int i = 0; i<size; ++i){
        cout<<myArray[i]<<endl;
    }
}

template<typename t>
int GenStack<t>::getSize(){
    return size;
}
