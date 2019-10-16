//Chase Bradshaw
#include<iostream>
#include "GenStack.cpp"
#include<fstream>

using namespace std;

int checkDelimiters(GenStack<char> s){
    int parCounter=0;
    int curlyCounter=0;
    int squareCounter=0;
    int remainder;
    char tempVal;
    for(int i=0; i<s.getSize(); ++i){
        tempVal = s.pop();
        if(tempVal=='(' || tempVal==')'){
            ++parCounter;
        }
        if(tempVal=='{' || tempVal=='}'){
            ++curlyCounter;
        }
        if(tempVal=='[' || tempVal==']'){
            ++squareCounter;
        }
    }

    //this block decides if there is the correct number of delimters, if not the program ends

    remainder = parCounter%2;
    if (remainder==0){
        cout<<"Parenthesis correct"<<endl;
    }
    else{
        cout<<"Incorrect parenthesis! Program will now exit"<<endl;
        return 2;
    }

    remainder = curlyCounter%2;
    if (remainder==0){
        cout<<"Curly brackets correct"<<endl;
    }
    else{
        cout<<"Incorrect curly brackets! Program will now exit"<<endl;
        return 2;
    }

    remainder = squareCounter%2;
    if(remainder==0){
        cout<<"Square brackets correct"<<endl;
    }
    else{
        cout<<"Incorrect square brakets! Program will now exit"<<endl;
        return 2;
    }
    cout<<"code correct"<<endl;
    return 1;
}

int main(){
    int userChoice = 1;
    string fileName = "";

    GenStack<char> stack;

    //GenStack stack = new GenStack(128);

    while (userChoice == 1){
        cout<<"Enter 1 to read file. Enter 2 to end program"<<endl;
        cin>>userChoice;
        if(userChoice==1){
            cout<<"Enter file name to read: "<<endl;
            cin>>fileName;


            char ch;
            fstream fin(fileName, fstream::in);
            //https://stackoverflow.com/questions/12240010/how-to-read-from-a-text-file-character-by-character-in-c

            while (fin >> noskipws >> ch) {
                //cout << ch <<endl;
                if(ch=='[' || ch==']' || ch=='{' || ch=='}' || ch=='(' || ch==')'){
                    stack.push(ch);
                    //cout<<"push complete"<<endl;
                }
            }
            //cout<<"PRINTING: "<<endl;
            //stack.print();
            //cout<<"POPPING: "<<endl;
            userChoice=checkDelimiters(stack);
            //checkCode(stack);


        }
    }
}
