#include <bits/stdc++.h>
using namespace std;

/// problem number 1 find the minimum and maximum elements of an array
pair<int, int> FindMinMax(int *arr, int l, int h)
{
    if(l==h)  /// size 1
    {
        return make_pair(arr[l],arr[l]);
    }
    if(l+1==h) /// size 2
    {
        if(arr[l]<arr[h])
        {
            return make_pair(arr[l],arr[h]);
        }
        else
        {
            return make_pair(arr[h],arr[l]);
        }
    }

    int mid = l+h/2;
    pair <int, int > left = FindMinMax(arr,l,mid-1);
    pair <int, int > right = FindMinMax(arr,mid,h);
    return make_pair(min(left.first,right.first),max(left.second,right.second));

}


/// problem number 2 find x^y using (DAC)
double findPower(double x, int y)
{
    if(y==1)
    {
        return x;
    }
    int l = y/2;
    int r = y - l;
    double left = findPower(x,l);
    double right = findPower(x,r);
    return left*right;

}



/// problem number 3 merge sort
void merge(int *arr, int low, int mid, int high)
{

    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = low;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

/// problem number 4 inversion count using (DAC)

int countInversionMerge(int *arr, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int inversion = 0;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = low;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            inversion+=(n1-i);
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    return inversion;
}
int  countInversion(int arr[], int low, int high)
{
    int inversion = 0;
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        inversion+=countInversion(arr, low, mid);
        inversion+=countInversion(arr, mid + 1, high);
        inversion+=countInversionMerge(arr, low, mid, high);
    }
    return inversion;
}

/// problem number 5 Quick sort algorithm

int partision(int *arr, int p, int r){
    int x = arr[r];
    int i =  p - 1;
    for(int j=p ;j<r;j++){
        if(arr[j]<=x){
            i++;
            swap(arr[i],arr[j]);
        }

    }
    swap(arr[i+1], arr[r]);

    return i+1;
}

void quickSort(int *arr, int p, int r){
    if(p<r){
        int q = partision(arr, p,r);
        quickSort(arr,p,q-1);
        quickSort(arr,q+1,r );
    }
}

/// problem number 6 binary search using (DAC)

int binarySearch(int *arr, int key, int low, int high){
    if(low>high){
        return -1;
    }
    int mid = low+(high-low)/2;
    if(arr[mid]==key){
        return mid;
    }
    else if(arr[mid]>key){
        return binarySearch(arr,key,low,mid-1);
    }
    else{
       return binarySearch(arr, key, mid+1, high);
    }
}

/// problem number 7 print all the odd elements of an array using (DAC)

void print_odd(int *arr, int l, int h)
{
    if(l==h)
    {
        if(arr[l]%2)
        {
            cout<<arr[l]<<" ";
        }
    }
    else
    {
        int mid = l+(h-l)/2;
        print_odd(arr,l,mid);
        print_odd(arr,mid+1,h);

    }

}

/// problem number 8  calculate the sum of all the elements of an array (DAC method)
int calc_sum(int *arr, int l, int h)
{
    if(l==h)
    {
        return arr[l];
    }
    int mid = l+(h-l)/2;
    int left_sum = calc_sum(arr,l,mid);
    int right_sum = calc_sum(arr,mid+1,h);
    return left_sum+right_sum;


}

/// problem number 9  calculate the sum of all the even elements of an array (DAC method)
int calculateSumOfEven(int *arr, int l, int h){
    if(l==h){
        if(arr[l]%2==0){
            return arr[l];
        }
        else{
            return 0;
        }
    }
    int mid = l+(h-l)/2;
    int left = calculateSumOfEven(arr,l,mid);
    int right = calculateSumOfEven(arr,mid+1,h);

    return left+right;

}


/// problem number 10 find maximum sum sub array
vector<int> FindCrossMax(int *arr, int l, int mid, int h)
{

    int left_sum = 0;
    int right_sum = 0;

    int t1 = -10000;

    int left_idx = 0;
    int right_idx = 0;

    for(int i=mid; i>=l; i--)
    {
        left_sum+=arr[i];
        if(left_sum>t1)
        {
            left_idx = i;
            t1= left_sum;
        }
    }

    int t2 = -100000;
    for(int i=mid+1; i<=h; i++)
    {
        right_sum+=arr[i];
        if(right_sum>t2)
        {
            right_idx = i;
            t2 = right_sum;
        }
    }


    vector<int> v = {left_idx,right_idx,t1+t2};
    //cout<<endl<<endl<<v[0]<<"     "<<v[1]<<"     "<<v[2]<<endl<<endl;
    return v;
}

vector<int> FindMaximumSumSubarray(int *arr, int l, int h)
{
    if(l==h)
    {
        vector<int> v = {l,l,arr[l]};
        return v;
    }
    int mid = l+(h-l)/2;
    vector<int> left = FindMaximumSumSubarray(arr,l,mid);
    vector<int> righ = FindMaximumSumSubarray(arr,mid+1,h);

    vector<int> cross = FindCrossMax(arr,l,mid,h);

    //cout<<left.at(0)<<", "<<righ[2]<<", "<<cross[2]<<endl;
    int mx = max(left[2],righ[2]);
    mx = max(mx,cross[2]);
    if(mx==left[2])
    {
        return left;
    }
    else if(mx==righ[2])
    {
        return righ;
    }
    else return cross;

}

///problem number 11 longest common prefix  of n string
string commonPrefixofTwo(string s1, string s2){
    int n1 = s1.size();
    int n2 = s2.size();
    string str = "";
    int n = min(n1,n2);
    for(int i=0;i<n;i++){
        if(s1[i]==s2[i]){
            str+=s1[i];
        }
        else{
            break;
        }
    }

    return str;
}
string findLongestCommonPrefix(string *strList, int l, int h){
    if(l==h){
        return strList[l];
    }
    else if(l+1==h){
        return commonPrefixofTwo(strList[l],strList[h]);
    }
    else{
        int mid = l+(h-l)/2;
        string left = findLongestCommonPrefix(strList, l, mid);
        string righ = findLongestCommonPrefix(strList,mid+1, h);
        return commonPrefixofTwo(left,righ);

    }


}

void input(int *arr, int n)
{
    cout<<"Enter array elements : ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
}

void output(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        \
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{

    /// check for problem number 1
    /*
    int n;
    cout<<"Enter array size : ";
    cin>>n;
    int arr[n];
    input(arr,n);
    pair<int, int > p;
    p = FindMinMax(arr,0,n-1);
    cout<<"Min : "<<p.first<<endl<<"Max : "<<p.second<<endl;
    */

    /// check for problem number 2
    /*
    double x; int y;
    cout<<"Enter the value of base and power : ";
    cin>>x>>y;
    cout<<x<<"^"<<y<<" = "<<findPower(x,y)<<endl;
    */

    /// check for problem number  3
    /*
    int n;
    cout<<"Enter the size : ";
    cin>>n;
    int arr[n];
    input(arr,n);
    cout<<"Before : ";
    output(arr, n);
    cout<<"After : ";
    mergeSort(arr,0,n-1);
    output(arr, n);
    //output(arr, n);
    */

    /// check for problem number 4
    /*
    int n;
    cout<<"Enter the size : ";
    cin>>n;
    int arr[n];
    input(arr,n);
    int inversion = countInversion(arr, 0, n-1);
    cout<<"Total number of inversion : "<<inversion<<endl;
    */

    /// check for problem number 5
    /*
    int n;
    cout<<"Enter the size : ";
    cin>>n;
    int arr[n];
    input(arr, n);
    cout<<"Before : ";
    output(arr, n);
    quickSort(arr, 0, n-1);

    cout<<"After : ";
    output(arr, n);
    */

    /// check for problem number 6
    /*
    int n;
    cout<<"Enter array size of (sorted array) : ";
    cin>>n;
    int arr[n];
    input(arr, n);
    int key;
    cout<<"Enter the key for search : ";
    cin>>key;
    int i = binarySearch(arr,key,0,n-1);
    if(i==-1){
        cout<<"Not found"<<endl;
    }
    else{
        cout<<key<<" found at "<<i<<" Index "<<endl;
    }

    */

    /// check for problem number 7 and 8
    /*
    int n;
    cin>>n;
    int arr[n];
    input(arr,n);
    cout<<"Odd elements : ";
    print_odd(arr,0,n-1);
    cout<<endl;
    int sum = 0;
    cout<<"Sum of all elements : "<<calc_sum(arr,0,n-1)<<endl;
    */

    /// check for problem number 9
    /*
    int n;
    cout<<"Enter the size : ";
    cin>>n;
    int arr[n];
    input(arr,n);
    int sum = calculateSumOfEven(arr, 0, n-1);
    cout<<"Sum of all even elements is : "<<sum<<endl;

    */


    /// check for problem number 10
    /*
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    int arr[n];
    input(arr,n);
    vector<int> v ;
    v = FindMaximumSumSubarray(arr,0,n-1);
    cout<<"The maximum sum sub-array is :";
    for(int i=v[0];i<=v[1];i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"and the sum is : "<<v[2]<<endl;
    */

    int n;
    cout<<"Enter the size of the list of string : ";
    cin>>n;
    string s[n];
    cout<<"Enter all the string : ";
    for(int i=0;i<n;i++){
        cin>>s[i];
    }

    string pre = findLongestCommonPrefix(s,0,n-1);
    if(pre.size()==0){
        cout<<"No common prefix"<<endl;
    }
    else{
        cout<<"Longest common prefix is = "<<pre<<endl;
    }
    return 0;

}

