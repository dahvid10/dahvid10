def quick_sort(arr):
    """
    Args:
     arr(list_int32)
    Returns:
     list_int32
    """
    # Write your code here.
    # set base case: len(arr) <= 1
    if (len(arr) <= 1):
        return arr    
    # set pivot as median of first, middle and last elements in array
    first = ( (arr[0] <= arr[len(arr)//2]) & (arr[0] >= arr[-1]) ) | ( (arr[0] >= arr[len(arr)//2]) & (arr[0] <= arr[-1]) )
    middle = ( (arr[len(arr)//2] <= arr[0]) & (arr[len(arr)//2] >= arr[-1]) ) | ( (arr[len(arr)//2] >= arr[0]) & (arr[len(arr)//2] <= arr[-1]) )
    if first:
        pivot = arr.pop(0)
    elif middle:
        pivot = arr.pop(len(arr)//2)
    else:
        pivot = arr.pop(-1)
    # set left and right partitions
    left = [elem for elem in arr if elem <= pivot]
    right = [elem for elem in arr if elem > pivot]
    # return concatenation of pivot between recursive calls of left and right partitions
    return quick_sort(left) + [pivot] + quick_sort(right)
