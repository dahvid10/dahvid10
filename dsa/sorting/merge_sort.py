def merge_sort(arr):
    """
    Args:
     arr(list_int32)
    Returns:
     list_int32
    """
    # Write your code here.
    # create helper fn for recursion
    def merger(arr):
        # set base case: if len(arr) <= 1, return
        if(len(arr) <= 1):
            return arr
        # get midpoint
        mid = len(arr) // 2
        # get left partition
        left = arr[:mid]
        # get right partition
        right = arr[mid:]
        # call helper fn on left partition
        merger(left)
        # call helper fn on right partition
        merger(right)
        # compare values from left and right partitions to sort
        [leftInd, rightInd, finalInd] = [0, 0, 0]
        while ( (leftInd < len(left)) & (rightInd < len(right)) ):
            if(left[leftInd] < right[rightInd]):
                arr[finalInd] = left[leftInd]
                leftInd += 1
                finalInd += 1
            else:
                arr[finalInd] = right[rightInd]
                rightInd += 1
                finalInd += 1
        # empty contents of remaining arr into final arr
        while (leftInd < len(left)):
            arr[finalInd] = left[leftInd]
            leftInd += 1
            finalInd += 1
        while(rightInd < len(right)):
            arr[finalInd] = right[rightInd]
            rightInd += 1
            finalInd += 1
        # return sorted arr
        return arr
    return merger(arr)
