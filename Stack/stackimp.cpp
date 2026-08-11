#include<bits/stdc++.h>
using namespace std;
#define MAX 5
int stack_arr[MAX];
int top=-1;
int isFULL(){
    if(top==MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEMPTY(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(int data){
    if(isFULL()){
        cout<<"Stack Overflow!!";
        return;
    }
        top=top+1;
        stack_arr[top]=data;
}
int pop(){
    int value;
    if(isEMPTY()){
        cout<<"Stack Underflow!!";
        exit(1);
    }
    value=stack_arr[top];
    top=top-1;
    return value;
}
int peek(){
    if(isEMPTY()){
        cout<<"Stack Underflow!!";
        exit(1);
    }
    else{
        return stack_arr[top];
    }
}
void print(){
    if(top==-1){
        cout<<"Stack Underflow!!";
    }
    else{
        for(int i=top; i>=0; i--){
            cout<<stack_arr[i];
            cout<<"\n";
        }
    }
}
int main()
{
    int data, choice;
    while(1){
        cout<<"1. Push an element:\n";
        cout<<"2. Pop an element:\n";
        cout<<"3. Show the top element:\n";
        cout<<"4. Show every element available:\n";
        cout<<"5. Quit:\n";
        cout<<"Choose an option:\n";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the data to be pushed:\n";
                cin>>data;
                push(data);
                break;
            case 2:
                data=pop();
                cout<<"Popped element is:"<<data<<"\n";
                break;
            case 3:
                data=peek();
                cout<<"Top element is:"<<data<<"\n";
                break;
            case 4:
                print();
                break;
            case 5:
                exit(1);
            default:
                cout<<"Invalid option!!\n";
        }
    }
}