# define d 256
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
void rabinkarp_match(string pattern, string text)
{
    int m = pattern.length();
    int n = text.length();
    int h = pow(d, m - 1);
    int pattern_hash = 0;
    int text_hash = 0;
    int q = 101;
    for(int i = 0; i < m; i++)
    {
        pattern_hash = (d * pattern_hash + pattern[i] ) % q;
        text_hash = (d * text_hash + text[i]) % q;
    }
    for(int i = 0; i < n - m; i++)
    {
        if(pattern_hash == text_hash)
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
        text_hash = (( d * (text_hash - h * text[i])) + text[i + m]) % q;
        if(text_hash < 0)
        text_hash = text_hash + q;
    }   
}
int main()
{
    string text, pattern;
    cout<<"Enter the text ";
    cin>>text;
    cout<<"Enter the pattern to find in text ";
    cin>>pattern;
    rabinkarp_match(pattern, text);
}