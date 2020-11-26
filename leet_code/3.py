from collections import defaultdict


class Solution(object):
    def lengthOfLongestSubstring(self, s):
        counters = defaultdict(lambda: (0, 0))

        for ch in s:
            if counters[ch][1] > 0:
                counters[ch][1] = 0
            for counterUnit in counters:
                counterUnit[1] += 1
                if counterUnit[0] < counterUnit[1]:
                    counterUnit[0] = counterUnit[1]
        return 1


if __name__ == "__main__":
    assert Solution().lengthOfLongestSubstring("abcabcbb") == 3
