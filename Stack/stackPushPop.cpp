#include<iostream>
using namespace std;

struct stack{
    int size;
    int top;
    int *arr;

};

int isEmpty(struct stack *ptr){
    if(ptr-> top == -1){
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr){
    if(ptr-> top == ptr-> size-1){
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, int val){
    if(isFull(ptr))
        cout<<"Stack Overflow can't push" << val <<"to the stack" << endl;
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        cout<<"Stack Overflow can't push to the stack" << endl;    
        return -1;
        }
        else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}


int main()
{
    struct stack *sp = new stack();
    sp-> size = 10;
    sp-> top = -1;
    sp-> arr = (int*) malloc(sp->size* sizeof(int));

     cout<<"Stack has been created successfully" << endl;
     
    // for(int i=50; i<60; i++){
    // push(sp, i++);
    // }

    cout << "Before pushing, Full: "<< isFull(sp) << endl;
    
    push(sp, 1);
    push(sp, 23);
    push(sp, 99);
    push(sp, 75);
    push(sp, 3);
    push(sp, 64);
    push(sp, 57);
    push(sp, 46);
    push(sp, 89);
    push(sp, 6); // ---> Pushed 10 values 
   // push(sp, 46); // Stack Overflow since the size of the stack is 10

    cout << "After pushing, Full: "<< isFull(sp) << endl;

    cout << "Popped " << pop(sp) << " from the stack" << endl; // --> Last in first out!
    cout << "Popped " << pop(sp) << " from the stack" << endl; // --> Last in first out!
    cout << "Popped " << pop(sp) << " from the stack" << endl; // --> Last in first out!
    


    return 0;
}