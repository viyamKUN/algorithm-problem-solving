from collections import defaultdict


class Solution(object):
    def lengthOfLongestSubstring(self, s):
        counters = defaultdict(lambda: 0)
        max = 0
        for ch in s:

            if counters[ch] > 0:
                counters[ch] = 0
            # print("A:  " + str(counters["a"]))
            for alphabet, count in counters.items():
                counters[alphabet] += 1
                if counters[alphabet] > max:
                    max = counters[alphabet]
            print(str(max))

        print(str(max))
        return max


if __name__ == "__main__":
    assert Solution().lengthOfLongestSubstring("abcabcbb") == 3
    assert Solution().lengthOfLongestSubstring("au") == 2
    assert Solution().lengthOfLongestSubstring("") == 0
    assert Solution().lengthOfLongestSubstring(" ") == 1
