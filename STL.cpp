#include<bits/stdc++.h>
using namespace std;

int main()
{
    ///Sorting
    /*
    int a[] = {2,1,6,4,5};
    sort(a,a+5,greater<int>()); // descending order
    sort(a,a+5,); // ascending order
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }

    */

    /// Vector
    /*
    vector<int> v;
    cout<<v.size()<<endl;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout<<v.size()<<endl;

    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    for(auto i = v.begin(); i<v.end(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    for(int i: v)
    {
        cout<<i<<" ";
    }

    v.erase(v.begin()+1);
    cout<<endl;
    for(int i: v)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    v.insert(v.begin()+1, 2);
    for(int i: v)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    sort(v.begin(),v.end(),);

    for(int i: v)
    {
        cout<<i<<" ";
    }

    */

    /// Stack
    /*
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while(!s.empty()){
        cout<<s.top()<< " ";
        s.pop();
    }

    */

    /// Queue

    /*queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    */

    return 0;
}
