#include<iostream>
#include<string>
using namespace std;
void compute_prefix(string pattern, int prefix[]);
void kmp_match(string pattern, string text)
{
    int n = text.length();
    int m = pattern.length();
    int prefix[m];
    compute_prefix(pattern, prefix);
    int q = -1;
    for(int i = 0; i < n; i++)
    {
        while(q > -1 && pattern[q + 1] != text[i])
            q = prefix[q];
        if(pattern[q + 1] == text[i])
            q = q + 1;
        if(q == m - 1)
        {
            cout<<"Pattern occurs at shift "<<i - m + 1<<endl;
            q = prefix[q];
        }
    }    
}
void compute_prefix(string pattern, int prefix[])
{
    int m = pattern.length();
    prefix[0] = -1;
    int k = -1;
    for(int q = 1; q < m; q++)
    {
        while(k > -1 && pattern[k + 1] != pattern[q])
            {
                k = prefix[k];
            }
        if(pattern[k + 1] == pattern[q])
            k = k + 1;
        prefix[q] = k;
    }
}
int main()
{
    string text, pattern;
    cout<<"Enter the text ";
    cin>>text;
    cout<<"Enter the pattern to find in text ";
    cin>>pattern;
    kmp_match(pattern, text);
}