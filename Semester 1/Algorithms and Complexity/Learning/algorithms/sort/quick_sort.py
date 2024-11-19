import random

from algorithms.sort.insertion_sort import insertion_sort


def quick_sort(array, lower, higher):
    if lower < higher:
        pivot = partition(array, lower, higher)
        quick_sort(array, lower, pivot)
        quick_sort(array, pivot + 1, higher)

def quick_sort_cutoff(array, lower, higher, cutoff=10):
    if lower < higher - cutoff:
        pivot = partition(array, lower, higher)
        quick_sort(array, lower, pivot)
        quick_sort(array, pivot + 1, higher)
    else:
        insertion_sort(array)

def partition(array, lower, higher):
    pivot = array[(lower + higher) // 2]

    left = lower
    right = higher

    while True:
        while array[left] < array[pivot]:
            left += 1
        while array[right] > array[pivot]:
            right -= 1

        if left >= right:
            return right

        array[left], array[right] = array[right], array[left]

        left += 1
        right -= 1

def three_way_partition(array, lower, higher):
    pivot = array[lower]

    lt = lower
    gt = higher
    i = lower

    while i <= gt:
        if array[i] < pivot:
            array[lt], array[i] = array[i], array[lt]
            lt += 1
            i += 1
        elif array[i] > pivot:
            array[i], array[gt] = array[gt], array[i]
            gt -= 1
        else:
            i += 1
    return lt, gt