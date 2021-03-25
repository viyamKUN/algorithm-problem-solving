class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        _sum = l1.val + l2.val
        result = ListNode(_sum % 10)
        tempResult = result
        while True:
            if l1.next is None and l2.next is None and int(_sum / 10) == 0:
                break
            l1 = l1.next if l1.next is not None else ListNode(0)
            l2 = l2.next if l2.next is not None else ListNode(0)
            _sum = l1.val + l2.val + int(_sum / 10)
            tempResult.next = ListNode(_sum % 10)
            tempResult = tempResult.next
        return result


if __name__ == "__main__":
    l1 = ListNode(2, ListNode(4, ListNode(3)))
    l2 = ListNode(5, ListNode(6, ListNode(4)))
    answer = [7, 0, 8]
    result = Solution().addTwoNumbers(l1, l2)

    for element in answer:
        assert element == result.val
        result = result.next

    assert result is None
