class ArrayOperations:
    def removeDuplicatesReference(self, nums):
        if not nums:
            return 0

        result = []

        for num in nums:
            exists = False

            for resNum in result:
                if num == resNum:
                    exists = True
                    break

            if not exists:
                result.append(num)

        for i in range(len(result)):
            nums[i] = result[i]

        return len(result)

    def removeDuplicatesOptimized(self, nums):
        if not nums:
            return 0

        slow = 0

        for fast in range(1, len(nums)):
            if nums[fast] != nums[slow]:
                slow += 1
                nums[slow] = nums[fast]

        return slow + 1

    def pairSumBruteForce(self, nums, target):
        n = len(nums)

        for i in range(n):
            for j in range(i + 1, n):
                if nums[i] + nums[j] == target:
                    return (i, j)

        return (-1, -1)

    def pairSumOptimized(self, nums, target):
        left = 0
        right = len(nums) - 1

        while left < right:
            currentSum = nums[left] + nums[right]

            if currentSum == target:
                return (left, right)
            elif currentSum < target:
                left += 1
            else:
                right -= 1

        return (-1, -1)

    def printArray(self, nums, k):
        print(nums[:k], end="")


obj = ArrayOperations()

dupTests = [
    [1, 1, 2, 2, 2, 3, 4, 4],
    [5],
    [],
    [-3, -3, -1, 0, 0]
]

print("PART A: REMOVE DUPLICATES")

for t, test in enumerate(dupTests):
    arrRef = test.copy()
    arrOpt = test.copy()

    kRef = obj.removeDuplicatesReference(arrRef)
    kOpt = obj.removeDuplicatesOptimized(arrOpt)

    print(f"\nTest Case {t + 1} Input: ", end="")
    obj.printArray(test, len(test))

    print(f"\nReference k = {kRef}, Prefix: ", end="")
    obj.printArray(arrRef, kRef)

    print(f"\nOptimized k = {kOpt}, Prefix: ", end="")
    obj.printArray(arrOpt, kOpt)

    print()

pairTests = [
    ([1, 2, 4, 7, 11, 15], 15),
    ([1, 3, 5, 8], 7),
    ([2, 4, 6], 20),
    ([1, 2, 2, 3], 4)
]

print("\nPART B: PAIR SUM")

for t, (arr, target) in enumerate(pairTests):
    resBF = obj.pairSumBruteForce(arr, target)
    resOpt = obj.pairSumOptimized(arr, target)

    print(f"\nTest Case {t + 1} Input: {arr}, Target = {target}")
    print(f"Brute Force Indices: {resBF}")
    print(f"Optimized Indices: {resOpt}")
