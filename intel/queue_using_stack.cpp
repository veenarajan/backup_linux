#include <iostream>

using namespace std;

class stack
{
    int top;
    int a[10];
    
    
    public:
    
    stack()
    {
        top = -1;
    }
    
    void push(int x)
    {
        top++;
        a[top] = x;
        if(top==10)
        {
            cout<<"stack is full";
            return;
        }
    }
    
    int pop()
    {
        if(top<0)
        {
            cout<<"stack is empty";
            return -1;
        }
        else
        {
        int k = a[top];
        top--;
        return k;
        }
    }
    
    int getvaluetop()
    {
        return top;
    }
};

stack s1;
stack s2;
   

void enqueue(int x)
{
   s1.push(x);
   
}

void dequeue()
{
   while(s1.getvaluetop()!=-1)
   {
    s2.push(s1.pop());
   }
   int d = s2.pop();
   cout<<d<<endl;
    
}
int main()
{
   
      enqueue(10);
      enqueue(100);
      enqueue(100);
      enqueue(1000);
      
      dequeue();
      dequeue();
      dequeue();
     dequeue();
     
   return 0;
}
