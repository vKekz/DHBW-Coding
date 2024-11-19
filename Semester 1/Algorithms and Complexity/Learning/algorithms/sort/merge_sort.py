from algorithms.sort.insertion_sort import insertion_sort

cutoff = 12

def merge_sort(array):
    if len(array) <= 1:
        return array

    mid = len(array) // 2
    left = array[0:mid]
    right = array[mid:]

    left = merge_sort_cutoff(left)
    right = merge_sort_cutoff(right)

    return merge(left, right)

def merge_sort_cutoff(array):
    if len(array) <= 12:
        return insertion_sort(array)

    mid = len(array) // 2
    left = array[0:mid]
    right = array[mid:]

    left = merge_sort_cutoff(left)
    right = merge_sort_cutoff(right)

    return merge(left, right)

def merge(left, right):
    result = []
    left_index, right_index = 0, 0
    left_len, right_len = len(left), len(right)

    while left_index < left_len and right_index < right_len:
        if left[left_index] <= right[right_index]:
            result.append(left[left_index])
            left_index += 1
        else:
            result.append(right[right_index])
            right_index += 1

    while left_index < left_len:
        result.append(left[left_index])
        left_index += 1

    while right_index < right_len:
        result.append(right[right_index])
        right_index += 1

    return result
