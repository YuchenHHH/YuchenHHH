#include <stdio.h>
#include <string.h>
#include <stddef.h> // offsetof 的头文件
#include <stdlib.h>

void changeValue(int *p)
{
    *p = 100;
    printf(" ");
}

void func(char *p)
{
    strcpy(p, "hello, world");
}

void test()
{
    char buf[1024];
    memset(buf, 0, 1024);
    char str1[] = "hello";
    char str2[] = "world";
    int len = sprintf(buf, "%d", 100);
    printf("%s\n%d\n", buf, len);
}

void test03()
{
    char *p = nullptr;
}

// 指针步长练习

struct Person
{
    char a;       // 0 - 3
    int b;        // 4 - 7
    char buf[64]; // 8 - 71
    int d;        // 72-75
};

void test02()
{
    struct Person p = {'a', 10, "Hello, world", 1000}; // 初始化
    // p 中的 d 属性偏移量是多少?
    printf("d 的漂移量是 %ld\n", offsetof(struct Person, d));
    printf("d 的值为 %d\n", *(int *)((char *)&p + offsetof(struct Person, d)));
}

int main()
{
    test();
    return 0;
}