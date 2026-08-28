import math
from collections import Counter

class Solution:
    def countAnagrams(self, s: str) -> int:
        words = s.split()
        ans = 1
        MOD = 10**9 + 7

        for word in words:
            num = math.factorial(len(word))
            freq = Counter(word)

            den = 1
            for count in freq.values():
                den *= math.factorial(count)

            ans = (ans * (num // den)) % MOD

        return ans