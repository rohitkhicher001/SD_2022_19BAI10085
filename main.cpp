#include <bits/stdc++.h>
using namespace std;

void input()
{
    vector<string> characters = {"1: p1","2: p2","3: p3","4: p4","5: p5"};
    cout<<"choose 5 characters from : ";
    for(auto i: characters)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    vector<int> choices;
    for(int i=0;i<5;i++)
    {
        int choice;
        cin>>choice;
        choices.push_back(choice-1);
    }
    for(int i=0;i<5;i++)
    {
        cout<<characters[choices[i]]<<" ";
    }

}
int main() {
    vector<vector<string>> v;
    input();
    return 0;
}
