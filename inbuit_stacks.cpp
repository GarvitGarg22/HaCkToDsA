#include <iostream>
using namespace std;
#include "StacksUsingArray.h"
#include <stack>

int main(){

stack<int> obj;

obj.push(10);
obj.push(20);
obj.push(30);
obj.push(40);
obj.push(50);

cout<<obj.top()<<endl;
obj.pop();
cout<<obj.top()<<endl;
cout<<obj.size()<<endl;
cout<<obj.empty()<<endl;

/*
StacksUsingArray obj;


obj.push(10);
obj.push(20);
obj.push(30);
obj.push(40);
obj.push(50);

cout<<obj.top()<<endl;
cout<<obj.pop()<<endl;
cout<<obj.pop()<<endl;
// cout<<obj.pop()<<endl;
// cout<<obj.pop()<<endl;
// cout<<obj.pop()<<endl;
cout<<obj.size()<<endl;
cout<<obj.isEmpty()<<endl;

return 0;

*/
}