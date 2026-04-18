#include <stdio.h>
#include <string.h>
#include "student.h"

static int findIndexById(Student arr[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (arr[i].id == id) return i;
    }
    return -1;
}

void addStudent(Student arr[], int *n) {
    if (*n >= MAX_STU) {
        printf("学生数量已满。\n");
        return;
    }
    Student s;
    printf("输入学号 姓名 平时成绩 期末成绩: ");
    if (scanf("%d %19s %f %f", &s.id, s.name, &s.usual, &s.final) != 4) {
        printf("输入格式错误。\n");
        return;
    }
    s.total = s.usual * 0.4f + s.final * 0.6f;

    if (findIndexById(arr, *n, s.id) != -1) {
        printf("学号已存在。\n");
        return;
    }
    arr[*n] = s;
    (*n)++;
    printf("添加成功。\n");
}

void deleteStudent(Student arr[], int *n) {
    int id;
    printf("输入要删除的学号: ");
    if (scanf("%d", &id) != 1) return;
    int idx = findIndexById(arr, *n, id);
    if (idx == -1) {
        printf("未找到该学生。\n");
        return;
    }
    for (int i = idx; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("删除成功。\n");
}

void updateStudent(Student arr[], int n) {
    int id;
    printf("输入要修改的学号: ");
    if (scanf("%d", &id) != 1) return;
    int idx = findIndexById(arr, n, id);
    if (idx == -1) {
        printf("未找到该学生。\n");
        return;
    }
    printf("输入新的平时成绩 期末成绩: ");
    if (scanf("%f %f", &arr[idx].usual, &arr[idx].final) != 2) {
        printf("输入格式错误。\n");
        return;
    }
    arr[idx].total = arr[idx].usual * 0.4f + arr[idx].final * 0.6f;
    printf("修改成功。\n");
}

void queryStudent(Student arr[], int n) {
    int id;
    printf("输入要查询的学号: ");
    if (scanf("%d", &id) != 1) return;
    int idx = findIndexById(arr, n, id);
    if (idx == -1) {
        printf("未找到该学生。\n");
        return;
    }
    Student s = arr[idx];
    printf("学号:%d 姓名:%s 平时:%.2f 期末:%.2f 总评:%.2f\n",
           s.id, s.name, s.usual, s.final, s.total);
}

void listStudent(Student arr[], int n) {
    printf("学号\t姓名\t平时\t期末\t总评\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\t%.2f\t%.2f\n",
               arr[i].id, arr[i].name, arr[i].usual, arr[i].final, arr[i].total);
    }
}
