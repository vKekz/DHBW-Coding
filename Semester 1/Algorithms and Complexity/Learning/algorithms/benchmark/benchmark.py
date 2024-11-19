import random
from timeit import timeit
import matplotlib.pyplot as plot
import sys

from algorithms.sort.insertion_sort import insertion_sort
from algorithms.sort.merge_sort import merge_sort, merge_sort_cutoff
from algorithms.sort.quick_sort import quick_sort

number_of_items = []
timings = []

benchmarks = [100, 200, 1000, 2000, 4000, 10000, 20000]

sys.setrecursionlimit(100000)
random.seed(1337)
for n in benchmarks:
    a = []

    for i in range(n):
        a += [i]

    random.shuffle(a)

    average = 100

    avg_time_seconds = timeit(lambda: quick_sort(a, 0, len(a)), number=average) / average
    avg_time_millis = avg_time_seconds * 1000

    number_of_items.append(n)
    timings.append(avg_time_millis)

    print(f"Average time for {n} items: ", avg_time_millis, "ms")

plot.plot(number_of_items, timings)
plot.ylabel("Time (ms)")
plot.xlabel("Number of items")
plot.show()