#include <stdio.h>
#include "student.h"

// stats.c 的函数声明
void calcTotal(Student arr[], int n);
void printStats(Student arr[], int n);
void sortByTotal(Student arr[], int n);

static void menu() {
    printf("\n==== 学生成绩统计系统 ====\n");
    printf("1. 添加学生\n");
    printf("2. 删除学生\n");
    printf("3. 修改成绩\n");
    printf("4. 查询学生\n");
    printf("5. 显示所有学生\n");
    printf("6. 统计信息\n");
    printf("7. 按总评排序\n");
    printf("0. 退出\n");
    printf("请选择: ");
}

int main() {
    Student students[MAX_STU];
    int n = 0;
    int choice;

    while (1) {
        menu();
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
            case 1: addStudent(students, &n); break;
            case 2: deleteStudent(students, &n); break;
            case 3: updateStudent(students, n); break;
            case 4: queryStudent(students, n); break;
            case 5: listStudent(students, n); break;
            case 6: printStats(students, n); break;
	    case 7: sortByTotal(students, n); listStudent(students, n); break;
            case 0: printf("退出。\n"); return 0;
            default: printf("无效选择。\n"); break;
        }
    }
    return 0;
}
