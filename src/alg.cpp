// Copyright 2021 NNTU-CS
#include <algorithm>

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0, right = len - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            int count_left = 1;
            while (left + count_left < len && arr[left + count_left] == arr[left]) {
                count_left++;
            }
            int count_right = 1;
            while (right - count_right >= 0 && arr[right - count_right] == arr[right]) {
                count_right++;
            }

            if (arr[left] != arr[right]) {
                count += count_left * count_right;
                left += count_left;
                right -= count_right;
            } else {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                left = right + 1;
            }
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int target = value - arr[i];
        int left = i + 1;
        int right = len - 1;

        int *first = std::lower_bound(arr + left, arr + right + 1, target);
        if (first > arr + right || *first != target) {
            continue;
        }
        int *last = std::upper_bound(arr + left, arr + right + 1, target);
        count += last - first;
    }
    return count;
}
