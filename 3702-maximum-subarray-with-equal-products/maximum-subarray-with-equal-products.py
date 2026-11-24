from math import gcd

class Solution:
    def maxLength(self, nums: List[int]) -> int:
        n = len(nums)
        res = 1

        for i in range(n):
            prod = 1
            l = 1
            g = 0

            for j in range(i, n):
                prod *= nums[j]
                l = l * nums[j] // gcd(l, nums[j])
                g = gcd(g, nums[j])

                if prod == l * g:
                    res = max(res, j - i + 1)

        return res