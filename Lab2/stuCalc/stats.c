#include <stdio.h>
#include "student.h"

void calcTotal(Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i].total = arr[i].usual * 0.4f + arr[i].final * 0.6f;
    }
}

void printStats(Student arr[], int n) {
    if (n == 0) {
        printf("暂无数据。\n");
        return;
    }
    float sum = 0, max = arr[0].total, min = arr[0].total;
    for (int i = 0; i < n; i++) {
        sum += arr[i].total;
        if (arr[i].total > max) max = arr[i].total;
        if (arr[i].total < min) min = arr[i].total;
    }
    printf("平均分: %.2f 最高分: %.2f 最低分: %.2f\n", sum / n, max, min);
}

void sortByTotal(Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j].total < arr[j + 1].total) {
                Student tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
