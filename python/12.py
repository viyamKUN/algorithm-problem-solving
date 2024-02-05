class Solution(object):
    def intToRoman(self, num):
        romans = ["I", "V", "X", "L", "C", "D", "M"]
        result = ""

        digitCnt = 0
        while num > 0:
            target = num % 10
            targetToRom = ""
            if (target == 9):
                targetToRom = romans[digitCnt * 2] + romans[(digitCnt + 1) * 2]
            elif (target == 4):
                targetToRom = romans[digitCnt * 2] + romans[digitCnt * 2 + 1]
            else:
                while target > 0:
                    if (target >= 5):
                        target -= 5
                        targetToRom = targetToRom + romans[digitCnt * 2 + 1]
                    else:
                        target -= 1
                        targetToRom = targetToRom + romans[digitCnt * 2]
            num //= 10
            digitCnt += 1
            result = targetToRom + result
        return result

if __name__ == "__main__":
    assert Solution().intToRoman(3) == "III"
    assert Solution().intToRoman(58) == "LVIII"
    assert Solution().intToRoman(1994) == "MCMXCIV"
