
def binary_search(nums, val):
    """using binary search to find an element in an array """

    if len(nums) == 0 or (len(nums) == 1 and nums[0] != val):
        print('The Value Doesnt Exist In The Array')

    mid = nums[len(nums)// 2]

    if val == mid:
        print('The number exist in the array!')
    if val < mid:
        return binary_search(nums[:len(nums)// 2], val)
    if val > mid:
        return binary_search(nums[len(nums)// 2 + 1:], val)



some_array = [4, 5, 6, 7, 8, 9, 10, 20, 50]

binary_search(some_array, 20)


