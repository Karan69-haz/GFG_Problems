class Solution {
  public:

    int xorTillN(int n) {

        if (n % 4 == 0) return n;
        if (n % 4 == 1) return 1;
        if (n % 4 == 2) return n+1;
        if (n % 4 == 3) return 0;
    }

    int findXOR(int l, int r) {
        // code here

       /*
       put some random value n and try draw run
       then you will identify what will be the xor of 1 to n
       */

       return xorTillN(r) ^ xorTillN(l-1);
    }
};

