def binary_search(array, item):
    low, high = 0, len(array) - 1

    while low <= high:
        mid = (low + high) // 2

        if array[mid] == item:
            return mid
        elif array[mid] < item:
            low = mid + 1
        else:
            high = mid - 1

    return -1

def binary_search_recursive(array, item, low, high):
    if low > high:
        return -1

    mid = (low + high) // 2

    if array[mid] == item:
        return mid
    elif array[mid] < item:
        return binary_search_recursive(array, item, mid + 1, high)
    else:
        return binary_search_recursive(array, item, low, mid - 1)