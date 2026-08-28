from collections import Counter

class Solution:
    def countAnagrams(self, s: str) -> int:
        MOD = 10**9 + 7
        n = len(s)

        # Precompute factorials
        fact = [1] * (n + 1)

        for i in range(1, n + 1):
            fact[i] = (fact[i - 1] * i) % MOD
        print(fact)

        ans = 1

        for word in s.split():
            # numerator
            ways = fact[len(word)]

            # denominator
            freq = Counter(word)

            for count in freq.values():
                ways = ways * pow(fact[count], MOD - 2, MOD)
                ways %= MOD

            ans = (ans * ways) % MOD

        return ans