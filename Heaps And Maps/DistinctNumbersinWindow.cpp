/*
You are given an array of N integers, A1, A2 ,…, AN and an integer K. Return the of count of distinct numbers in all windows of size K.

Formally, return an array of size N-K+1 where i’th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,…, Ai+k-1.

Note:

If K > N, return empty array.
For example,

A=[1, 2, 1, 3, 4, 3] and K = 3

All windows of size K are

[1, 2, 1]
[2, 1, 3]
[1, 3, 4]
[3, 4, 3]

So, we return an array [2, 3, 3, 2].
*/

vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> ans;

    int n = A.size();
    
    if(n == 0)
        return ans;
    
    map<int, int> mymap;

    for(int i = 0; i < n; i++)
    {
    
        ++mymap[A[i]];
                
        if(i-B+1 >= 0)
        {
            ans.push_back(mymap.size());
            --mymap[A[i+1-B]];
            if(mymap[A[i+1-B]] == 0)
            {
                mymap.erase(A[i+1-B]);
            }
            
        }
        
    }

    return ans;
}