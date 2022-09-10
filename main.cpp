#include <bits/stdc++.h>
using namespace std;
void actionL(string position,vector<vector<string>> &v,unordered_map<string,pair<int,int>> &m)
{
   string temp = position;
   int left = m[position].first;
   int right = m[position].second;
   v[left][right-1] = v[left][right];
   v[left][right]="";
   m[temp] = {left,right-1};
}
void actionR(string position,vector<vector<string>> &v,unordered_map<string,pair<int,int>> &m)
{
string temp = position;
   int left = m[position].first;
   int right = m[position].second;
   v[left][right+1] = v[left][right];
   v[left][right]="";
   m[temp] = {left,right+1};
}void actionF(string position,vector<vector<string>> &v,unordered_map<string,pair<int,int>> &m)
{
    string temp = position;
   int left = m[position].first;
   int right = m[position].second;
   v[left+1][right] = v[left][right];
   v[left][right]="";
   m[temp] = {left+1,right};

}void actionB(string position,vector<vector<string>> &v,unordered_map<string,pair<int,int>> &m)
{
string temp = position;
   int left = m[position].first;
   int right = m[position].second;
   v[left][right-1] = v[left][right];
   v[left][right]="";
   m[temp] = {left,right-1};
}
void actioninput(vector<vector<string>> &v,unordered_map<string,pair<int,int>> &m)
{
    cout<<"Choose player and action (Example: A-p2 L)"<<endl;
    string position;
    cin>>position;
    string action;
    cin>>action;
    if(action == "L")
    {
        actionL(position,v,m);
    }
    else  if(action == "R")
    {
        actionR(position,v,m);
    }
    else  if(action == "F")
    {
        actionF(position,v,m);
    }
    else  if(action == "B")
    {
        actionB(position,v,m);
    }

}
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
        v[0][i] = "A-"+A_characters[i];
    }
     for(int i=0;i<5;i++)
    {
        v[4][i] = "B-"+B_characters[i];
    }
     unordered_map<string,pair<int,int>> m;
    for(int i=0;i<5;i++)
    {

        for(int j=0;j<5;j++)
        {
            m[v[i][j]] = {i,j};
        }
    }

 for(auto i: v)
        {
            for(auto j: i)
            {

                cout<<j<<" ";

            }
            cout<<endl;
        }
    int countA =5;
    int countB= 5;
    while(true)
    {
        actioninput(v,m);
        for(auto i: v)
        {
            for(auto j: i)
            {

                cout<<j<<" ";

            }
            cout<<endl;
        }
    }

    return 0;
}
