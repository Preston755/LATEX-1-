import time
import random


def merge(arr: list, left: int, mid: int, right: int) -> None:
    """Слияние двух отсортированных подмассивов arr[left..mid] и arr[mid+1..right]."""
    left_part = arr[left:mid + 1]
    right_part = arr[mid + 1:right + 1]

    i = 0  # индекс для left_part
    j = 0  # индекс для right_part
    k = left  # индекс для результирующего массива

    while i < len(left_part) and j < len(right_part):
        if left_part[i] <= right_part[j]:
            arr[k] = left_part[i]
            i += 1
        else:
            arr[k] = right_part[j]
            j += 1
        k += 1

    while i < len(left_part):
        arr[k] = left_part[i]
        i += 1
        k += 1

    while j < len(right_part):
        arr[k] = right_part[j]
        j += 1
        k += 1


def merge_sort(arr: list, left: int, right: int) -> None:
    """Рекурсивная сортировка слиянием.

    arr  --- сортируемый список,
    left --- левая граница подмассива,
    right --- правая граница подмассива.
    """
    if left < right:
        mid = (left + right) // 2
        merge_sort(arr, left, mid)
        merge_sort(arr, mid + 1, right)
        merge(arr, left, mid, right)


if __name__ == "__main__":
    arr = [64, 34, 25, 12, 22, 11, 90, 5, 77, 43]

    print("До сортировки:", arr)

    start = time.perf_counter()
    merge_sort(arr, 0, len(arr) - 1)
    end = time.perf_counter()

    print("После сортировки:", arr)
    print(f"Время выполнения: {(end - start) * 1e6:.2f} мкс")
