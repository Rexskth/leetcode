class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> primes(right+1, true);
        primes[0]=false; primes[1]=false;
        for(int i=2; i*i<=right; i++){
            if(!primes[i])
                continue;
            for(int j=i*i; j<=right; j+=i){
                primes[j]=false;
            }
        }

        vector<int> primeNumbers;
        for (int i = left; i <= right; i++) {
            if (primes[i]) {
                primeNumbers.push_back(i);
            }
        }
        if (primeNumbers.size() < 2) {
            return {-1, -1};
        }
        int minDiff = INT_MAX;
        vector<int> answer;
        for (int i = 0; i < primeNumbers.size() - 1; i++) {
            int diff = primeNumbers[i + 1] - primeNumbers[i];
            if (diff < minDiff) {
                minDiff = diff;
                answer = {primeNumbers[i], primeNumbers[i + 1]};
            }
        }
        return answer;
    }
};