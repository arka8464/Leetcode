class Solution {
public:
//     bool isPowerOfTwo(int n)
// {
//     int cnt = 0;
        
//     while (n > 0) {
//         if ((n & 1) == 1) {
//             cnt++;
//         }
//         n = n >> 1;
//     }
 
//     if (cnt == 1) {   
//         return true;
//     }
//     return false;
// }
    bool isPowerOfFour(int num) {
         if(num<0)return false;
        for(int i=0;i<32;i+=2)if(num==1<<i)return true;
        return false;      
    }
};