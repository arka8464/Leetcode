class Solution {
public:
    static const int N = 1005; // Declare N as a static member variable
    vector<bool> isPrimes;

    void sieve() {
        isPrimes.assign(N, 1); // Initialize the vector with size N
        isPrimes[0] = isPrimes[1] = false;
        for (int i = 2; i*i < N; i++) {
            if (isPrimes[i] == true) {
                for (int j = 2 * i; j < N; j += i) {
                    isPrimes[j] = false;
                }
            }
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        sieve();
        vector<int> prime;
        for (int i = 0; i < 1005; i++)
            if (isPrimes[i])
                prime.push_back(i);

        int n=nums.size();
     int flg = 0;
        int prev = nums[n-1];
        for(int i=n-2; i>=0; i--){
            if(nums[i]<prev){prev = nums[i]; continue;}
            flg = 1;
            for(int sub=0; sub<prime.size() && prime[sub]<nums[i]; sub++){
                if(nums[i]-prime[sub]<prev){
                    prev = nums[i]-prime[sub];
                    flg = 0;
                    break;
                }
            }
            if(flg) break;

        }
        return !flg;

    }
};
