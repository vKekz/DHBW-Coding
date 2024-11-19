def insertion_sort(array):
    length = len(array)

    for i in range(1, length):
      j = i
      element = array[i]

      while j > 0 and element < array[j - 1]:
        array[j] = array[j - 1]
        array[j - 1] = element

        j -= 1

      array[j] = element

    return array
