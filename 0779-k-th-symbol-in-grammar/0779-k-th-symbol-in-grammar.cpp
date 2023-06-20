class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1)
            return 0;
        
        if (K % 2 == 0) {
            int parent = kthGrammar(N - 1, K / 2);
            if (parent == 0)
                return 1;
            else
                return 0;
        } else {
            int parent = kthGrammar(N - 1, (K + 1) / 2);
            if (parent == 0)
                return 0;
            else
                return 1;
        }
    }
};
