//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    //code here.
    int checker=0;
    
    for(int i=0;i<s.size();i++)
    {
        int bitAtIndex=s[i]-'a';
        if ((checker & (1 << bitAtIndex)) > 0)
            return string (1,s[i]);
        checker |= (1 << bitAtIndex);
        
        /*The operator `|` is a bitwise OR operator. In the context of `checker |= (1 << bitAtIndex)`, it's being used to set the bit at the position `bitAtIndex` in `checker` to `1`.

The `|=` operator is a compound assignment operator that performs a bitwise OR operation on `checker` with the value `(1 << bitAtIndex)` and assigns the result back to `checker`. 

Here's what it does in detail:

1. `(1 << bitAtIndex)`: This creates a bitmask with a `1` at the position `bitAtIndex` and `0` elsewhere.

2. `checker |= (1 << bitAtIndex)`: This performs a bitwise OR operation on `checker` and the bitmask. The result is a number that has a `1` at all the positions where either `checker` or the bitmask has a `1`. This number is then assigned back to `checker`.

In other words, `checker |= (1 << bitAtIndex)` sets the bit at the position `bitAtIndex` in `checker` to `1`, without affecting the other bits in `checker`.

If you directly write `(1 << bitAtIndex)`, it would create the bitmask, but it wouldn't update `checker`. You need to use the `|=` operator to update `checker` with the new bitmask.

Here's an example to illustrate this:

```cpp
int checker = 0; // checker is `00000000` in binary
int bitAtIndex = 2; // We want to set the third bit in checker

// Create a bitmask with a 1 at the third position
int mask = 1 << bitAtIndex; // mask is `00000100` in binary

// Update checker with the bitmask
checker |= mask; // checker is now `00000100` in binary
```

After this code is executed, the third bit in `checker` is set to `1`.

References: [Source 0](https://www.programiz.com/c-programming/bitwise-operators), [Source 3](https://en.wikipedia.org/wiki/Bitwise_operation)*/
    }
    return "-1";
}