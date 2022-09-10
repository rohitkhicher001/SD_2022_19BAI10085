#include <bits/stdc++.h>
using namespace std;
void actionL(bool turnA,int &countA,int &countB,string position,vector<vector<string>> &v,unordered_map<string,pair<int,int>> &m);
void actionR(bool turnA,int &countA,int &countB,string position,vector<vector<string>> &v,unordered_map<string,pair<int,int>> &m);
void actionF(bool turnA,int &countA,int &countB,string position,vector<vector<string>> &v,unordered_map<string,pair<int,int>> &m);
void actionB(bool turnA,int &countA,int &countB,string position,vector<vector<string>> &v,unordered_map<string,pair<int,int>> &m);
void actioninput(bool turnA,int &countA,int &countB,vector<vector<string>> &v,unordered_map<string,pair<int,int>> &m);


void actionL(bool turnA,int &countA,int &countB,string position,vector<vector<string>> &v,unordered_map<string,pair<int,int>> &m)
{
   string temp = position;
   int left = m[position].first;
   int right = m[position].second;
   if(right == 0 && turnA)
   {
       cout<<"Troop is going out of bounds"<<endl;
       actioninput(turnA,countA,countB,v,m);
   }
   else if(right == 4 && !turnA)
   {
       cout<<"Troop is going out of bounds"<<endl;
       actioninput(turnA,countA,countB,v,m);
   }
   if(turnA)
   {
   if(v[left][right-1]!= "#")
   {

       char first_character = v[left][right-1][0];
       if(first_character == 'A' && v[left][right][0] == 'B')
       {
           countA--;
       }
       else if(first_character == 'B' && v[left][right][0] == 'A')
       {

           countB--;
       }
       else{
        cout<<"You cannot kill your own troops"<<endl;
        return;
       }
    }
   v[left][right-1] = v[left][right];
   v[left][right]="#";
   m[temp] = {left,right-1};
   }
   else{
     actionR(!turnA,countA,countB,position,v,m);
   }
}
void actionR(bool turnA,int &countA,int &countB,string position,vector<vector<string>> &v,unordered_map<string,pair<int,int>> &m)
{
string temp = position;
   int left = m[position].first;
   int right = m[position].second;
   if(right == 0 && !turnA)
   {
       cout<<"Troop is going out of bounds"<<endl;
       actioninput(turnA,countA,countB,v,m);
   }
   else if(right == 4 && turnA)
   {
       cout<<"Troop is going out of bounds"<<endl;
       actioninput(turnA,countA,countB,v,m);
   }
   if(turnA)
   {

   if(v[left][right+1]!= "#")
   {

       char first_character = v[left][right+1][0];
       if(first_character == 'A' && v[left][right][0] == 'B')
       {
           countA--;
       }
       else if(first_character == 'B' && v[left][right][0] == 'A')
       {

           countB--;
       }
       else{
        cout<<"You cannot kill your own troops"<<endl;
        return;
       }
    }
   v[left][right+1] = v[left][right];
   v[left][right]="#";
   m[temp] = {left,right+1};
   }
   else
   {
      actionL(!turnA,countA,countB,position,v,m);
   }
}void actionF(bool turnA,int &countA,int &countB,string position,vector<vector<string>> &v,unordered_map<string,pair<int,int>> &m)
{
    string temp = position;
   int left = m[position].first;
   if(left == 0 && turnA)
   {
       cout<<"Troop is going out of bounds"<<endl;
       actioninput(turnA,countA,countB,v,m);
   }
   else if(left == 4 && !turnA)
   {
       cout<<"Troop is going out of bounds"<<endl;
       actioninput(turnA,countA,countB,v,m);
   }
   int right = m[position].second;
   if(turnA)
   {
   if(v[left-1][right]!= "#")
   {

       char first_character = v[left-1][right][0];
       if(first_character == 'A' && v[left][right][0] == 'B')
       {
           countA--;
       }
       else if(first_character == 'B' && v[left][right][0] == 'A')
       {

           countB--;
       }
       else{
        cout<<"You cannot kill your own troops"<<endl;
        return;
       }
    }
   v[left-1][right] = v[left][right];
   v[left][right]="#";
   m[temp] = {left-1,right};
   }
   else
   {
       actionB(!turnA,countA,countB,position,v,m);
   }

}void actionB(bool turnA,int &countA,int &countB,string position,vector<vector<string>> &v,unordered_map<string,pair<int,int>> &m)
{

string temp = position;
   int left = m[position].first;
   int right = m[position].second;
   if(left == 4 && turnA)
   {
       cout<<"Troop is going out of bounds"<<endl;
       actioninput(turnA,countA,countB,v,m);
   }
   else if(left == 0 && !turnA)
   {
       cout<<"Troop is going out of bounds"<<endl;
       actioninput(turnA,countA,countB,v,m);
   }
   if(turnA)
   {
   if(v[left+1][right]!= "#")
   {

       char first_character = v[left+1][right][0];
       if(first_character == 'A' && v[left][right][0] == 'B')
       {
           countA--;
       }
       else if(first_character == 'B' && v[left][right][0] == 'A')
       {

           countB--;
       }
       else{
        cout<<"You cannot kill your own troops"<<endl;
        return;
       }
    }
   v[left+1][right] = v[left][right];
   v[left][right]="#";
   m[temp] = {left+1,right};
   }
   else
   {

       actionF(!turnA,countA,countB,position,v,m);
   }

}
void actioninput(bool turnA,int &countA,int &countB,vector<vector<string>> &v,unordered_map<string,pair<int,int>> &m)
{
    cout<<"Choose player and action (Example: A-p2 L)"<<endl;
    string position;
    cin>>position;
    if((position[0]!= 'A' && position[0] != 'B') || position[1]!= '-' || position[2]!='p' || position[3]>'5' && position[3]<'1' )
    {
        cout<<"Invalid position"<<endl;
        actioninput(turnA,countA,countB,v,m);
    }
    string action;
    cin>>action;
    if(action!="L" && action!= "R" && action!= "F" && action != "B")
    {
        actioninput(turnA,countA,countB,v,m);
    }
    if(turnA&&position[0] == 'B')
    {
        cout<<"Wrong turn please play fairly"<<endl;
        actioninput(turnA,countA,countB,v,m);
    }
    if(action == "L")
    {
        actionL(turnA,countA,countB,position,v,m);
    }
    else  if(action == "R")
    {
        actionR(turnA,countA,countB,position,v,m);
    }
    else  if(action == "F")
    {
        actionF(turnA,countA,countB,position,v,m);
    }
    else  if(action == "B")
    {

        actionB(turnA,countA,countB,position,v,m);

    }

}
void input_vector(vector<int> &v)
{
    for(int i=0;i<5;i++)
    {

        int choice;
        cin>>choice;
        v.push_back(choice-1);
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
    vector<int> choices,tempchoices;
    input_vector(choices);
    for(int i=0;i<5;i++)
    {
        if(choices[i]>4 || choices[i]<0)
        {
            cout<<"Please enter a number between 1 and 5"<<endl;
            choices = tempchoices;
            input_vector(choices);
        }
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
    vector<string> temp(5,"#");
    vector<vector<string>> v(5,temp);

    vector<string> A_characters = input();
    vector<string> B_characters = input();
    for(int i=0;i<5;i++)
    {
        v[0][i] = "B-"+B_characters[i];
    }
     for(int i=0;i<5;i++)
    {
        v[4][i] = "A-"+A_characters[i];
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
    bool turnA = true;
    while(countA && countB)
    {
        actioninput(turnA,countA,countB,v,m);
        turnA = !turnA;
        for(auto i: v)
        {
            for(auto j: i)
            {

                cout<<j<<" ";

            }
            cout<<endl;
        }
        cout<<countA<<" "<<countB<<endl;
    }
    if(countA == 0)
    {

        cout<<"Player B wins"<<endl;

    }
    else if(countB == 0)
    {
        cout<<"Player A wins"<<endl;
    }

    return 0;
}
