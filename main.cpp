#include <bits/stdc++.h>
using namespace std;

vector<string> input()
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
vector<string> A_characters;
    cout<<"Your characters are : ";
    for(int i=0;i<5;i++)
    {
        string res = "";
        for(int j=3;j<characters[choices[i]].length();j++)
        {

            res+= characters[choices[i]][j];
        }
        cout<<res<<" ";
        A_characters.push_back(res);
    }
    cout<<endl;
    return A_characters;

}
int main() {
    vector<string> temp(5,"a");
    vector<vector<string>> v(5,temp);

    vector<string> A_characters = input();
    vector<string> B_characters = input();
    for(int i=0;i<5;i++)
    {
        v[0][i] = A_characters[i];
    }
     for(int i=0;i<5;i++)
    {
        v[4][i] = B_characters[i];
    }
      for(auto i: v)
    {
        for(auto j: i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
