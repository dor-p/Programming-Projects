def binary_search(arr, val):
    if len(arr) == 0 or (len(arr) == 1 and arr[0] != val):
        print('The Value Doesnt Exist')

    mid = arr[len(arr)// 2]

    if val == mid: print('its here bro')
    if val < mid: return binary_search(arr[:len(arr)// 2], val)
    if val > mid: return binary_search(arr[len(arr)// 2 + 1:], val)



a = [1, 2, 3, 4, 5, 6, 7, 8, 9]


