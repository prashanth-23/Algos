#include<iostream>
#include<string>
using namespace std;
class stack
  {
	char a[50];
	int top;
  public:
	stack()
	 {
	   top=-1;
	 }
	void push(char x)
	 {
	  a[++top]=x;
	 }
	char pop()
	 {
	  return a[top--];
	 }
	bool isstackempty()
	 {
	  if(top==-1)
	  return true;
	  else
	  return false;
	 }
	char stacktop()
	 {
	  return a[top];
	 }
  };
int priority(char ch)
  {
	if(ch=='^')
	 return 3;
	else 
	  if(ch=='*'||ch=='/')
	    return 2;
	  else 
	    if(ch=='+'||ch=='-')
	      return 1;
	    else
	      return 0;
  }
int main()
  {
	char ch,toptoken,tokenout;
	stack s;
	string infix;
	char postfix[100];
	int l=0;
	cout<<"enter infix";
	cin>>infix;
	for(int i=0;i<infix.size();i++)
	 {
	  ch=infix[i];
	  if(ch=='(')
	    s.push(ch);
	  else 
	   if(ch==')')
	     {
	       ch=s.pop();
	         while(ch!='(')
		  {
		   postfix[l++]=ch;
		   ch=s.pop();
		  }
	     }
	  else 
	   if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
	     {
	       toptoken=s.stacktop();
		while(!(s.isstackempty())&&priority(ch)<=priority(toptoken))
		 {
		  tokenout=s.pop();
		  postfix[l++]=tokenout;
		  toptoken=s.stacktop();
		 }
		s.push(ch);
	     }
	   else postfix[l++]=ch;
	 }
	 while(!(s.isstackempty()))
	  {
	   ch=s.pop();
	   postfix[l++]=ch;
	  }
	 postfix[l]='\0';
	 cout<<postfix;
  }
