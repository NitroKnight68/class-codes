#include <iostream>
  
using namespace std;

class Stack {
    int sp;
  
public:
    int size;
    int a[50];
  
    Stack() {
    	sp = -1; 
    }
    bool push(int x);
    int pop();
    int top();
    bool empty();
};
  
bool Stack::push(int x)
{
    if (sp >= (size - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a[++sp] = x;
        cout << x << " was pushed into stack\n";
        return true;
    }
}
  
int Stack::pop()
{
    if (sp < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int x = a[sp--];
        return x;
    }
}
int Stack::top()
{
    if (sp < 0) {
        cout << "Stack is empty";
        return 0;
    }
    else {
        int x = a[sp];
        return x;
    }
}
  
bool Stack::empty()
{
    return (sp < 0);
}

int main()
{
    int ele;
    class Stack s;
    printf("----------Inserting into Stack----------\n\n");
    printf("Enter the size of the stack:\n");
    scanf("%d", &s.size);
    printf("Enter the elements to be pushed into the stack:\n");
    for(int i = 0; i < s.size; i++) {
    	scanf("%d", &ele);
    	s.push(ele);
    }
    printf("\n----------Popping from Stack----------\n");
    cout << s.pop() << " was popped from stack\n";
    cout << s.pop() << " was popped from stack\n";
    
    printf("\n----------Top Element of Stack----------\n");
    cout << "The top element is : " << s.top() << endl;
    
    printf("\n----------Displaying the Stack----------\n");
    cout <<"Elements present in stack : ";
    while(!s.empty())
    {
        cout << s.top() <<" ";
        s.pop();
    }  
    return 0;
}
