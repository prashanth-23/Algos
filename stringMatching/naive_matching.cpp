#include<iostream>
#include<string>
using namespace std;
void naive_match(string pattern, string text)
{
    int m = pattern.length();
    int n = text.length();
    for(int i = 0; i < n - m; i++)
    {
        int j = 0;
        for(; j < m; j++)
        {
            if(pattern[j] != text[i + j])
            break;
        }
        if(j == m)
        cout<<"pattern found at shift "<<i<<endl;
    }
}
int main()
{
    string text, pattern;
    cout<<"Enter the text ";
    cin>>text;
    cout<<"Enter the pattern to find in text ";
    cin>>pattern;
    naive_match(pattern, text);
}