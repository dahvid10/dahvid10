# MERGE SORT
def scratch_merge_sort():
    # pseudocode
    # summary: divide array into singular elements, then combine array by sorting
    # helper fn
        # base case: if len(arr) <= 1, return arr
        # get midpoint
        # get left partition
        # get right partition
        # recursive call on left
        # recursive call on right
        # sort elements from left and right partitions
        # set remaining elements from either left or right partition
        # return sorted arr
    # return output of initial call to helper fn

    # code
    def merge_sort(arr):
        def merger(arr):
            if len(arr) <= 1:
                return arr
            mid = len(arr) // 2
            left = arr[:mid]
            right = arr[mid:]
            merger(left)
            merger(right)
            [leftInd, rightInd, finalInd] = [0,0,0]
            while (leftInd < len(left)) and (rightInd < len(right)):
                if(left[leftInd] <= right[rightInd]):
                    arr[finalInd] = left[leftInd]
                    leftInd += 1
                    finalInd += 1
                else:
                    arr[finalInd] = right[rightInd]
                    rightInd += 1
                    finalInd += 1
            while(leftInd < len(left)):
                arr[finalInd] = left[leftInd]
                leftInd += 1
                finalInd += 1
            while(rightInd < len(right)):
                arr[finalInd] = right[rightInd]
                rightInd += 1
                finalInd += 1
            return arr
        return merger(arr)

    # test
    arr = [23,54,34,65,45,78,88]
    print(merge_sort(arr))
    return

# QUICK SORT
def scratch_quick_sort():
    # pseudocode
    # summary: set pivot, then recursively sort arr around pivot
    # set base case
    # set pivot
    # set left and right partitions
    # return output of recursive calls of left and right partitions with pivot in middle

    # code
    def quick_sort(arr):
        if len(arr) <= 1:
            return arr
        f_elem = arr[0]
        m_elem = arr[len(arr) // 2]
        l_elem = arr[-1]
        first = ((f_elem <= m_elem) and (f_elem >= l_elem)) or ((f_elem >= m_elem) and (f_elem <= l_elem))
        middle = ((m_elem <= f_elem) and (m_elem >= l_elem)) or ((m_elem >= f_elem) and (m_elem <= l_elem))
        if first:
            pivot = arr.pop(0)
        elif middle:
            pivot = arr.pop(len(arr) // 2)
        else:
            pivot = arr.pop(-1)
        left = [elem for elem in arr if elem <= pivot]
        right = [elem for elem in arr if elem > pivot]
        return quick_sort(left) + [pivot] + quick_sort(right)
    # test
    arr = [33,23,12,54,45,65,47,98,78,89]
    print(quick_sort(arr))
    return


