class Solution:
    def countCommas(self, n: int) -> int:
        start = 1000
        commas = 1
        ans = 0
        while start <= n:
            end = min(n,start*1000-1)
            req = (end-start+1)*commas
            ans = ans + req
            start = start*1000
            commas = commas + 1
        return ans 