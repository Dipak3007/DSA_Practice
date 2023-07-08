/*
    Given an input stream A of n characters consisting only of lower case alphabets. While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.
*/

#include<bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string A){
	vector<int> alpha(26,0);
	queue<char> q;
	string ans;
	for(char i:A){
	    alpha[i-'a']++;
		if(alpha[i-'a']==1) q.push(i);
        while(!q.empty() && alpha[q.front()-'a']>1) q.pop();
		if(q.empty())   ans+='#';
        else    ans+=q.front();
	}
	return ans;
}

int main(){
    string s="aabccbdbd";
    cout<<FirstNonRepeating(s);
    return 0;
}