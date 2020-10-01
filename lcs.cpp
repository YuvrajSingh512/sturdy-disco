Aim is to find the length of longest, common subsequence of 2 strings.

Example:
string 1 = "hello"
string 2 = "bell"
expected o/p: 3 ("ell")

DP approach:
#include <iostream>
#include <algorithm>
#include <string>
#include<cstring>
using namespace std;
#define ll long long

int lcs(string str1, string str2, int m, int n,int cache[][101]){
    if(m==0||n==0){
        return 0;
    }
    if(str1[m-1]==str2[n-1]){
        return 1 + lcs(str1,str2,m-1,n-1,cache);
    }
    if(cache[m][n]>=0){
        return cache[m][n];
    }
    cache[m][n] = max(lcs(str1,str2,m,n-1,cache),lcs(str1,str2,m-1,n,cache));
    return cache[m][n];
}

int lcs(string str1, string str2, int m, int n){
    int cache[101][101];
    memset(cache,-1,sizeof(cache));
    return lcs(str1,str2,m,n,cache);
}

int main() {
	// your code goes here
	string s1,s2;
    int n;
    cin >> n;
    ll arr1[n];
    for(int i=0;i<n;i++){
        cin >> arr1[i];
        s1.push_back(arr1[i]);
    }
    int m;
    cin >> m;
    ll arr2[m];
    for(int i=0;i<m;i++){
        cin >> arr2[i];
        s2.push_back(arr2[i]);
    }
    
	cout << lcs(s1,s2,s1.length(),s2.length());
	return 0;
}

INPUT:
4
2 7 8 3 
4
5 2 8 7

OUTPUT:
2

EXPLANATION:
lcs is "27"

Number of recursive calls in above (DP) approach: 28.
Number of recursive calls in naive approach: 52.
