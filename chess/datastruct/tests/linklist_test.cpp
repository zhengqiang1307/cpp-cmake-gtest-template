#include "gmock/gmock.h"
#include "chess/datastruct/linklist.h"

#include <iostream>

using namespace std;
void linkListTest(void)
{
    LinkList* li = linklist_create();
    char a[] = "hello";
    char b[] = "world";
    char c[] = "china";
    printf("%p\n", a);
    snprintf(a, 100, "hello");

    linklist_insert(li, a, 0);
    linklist_insert(li, b, 0);
    linklist_insert(li, c, 0);
    char* t = (char*)linklist_get(li, 0);
    printf("%p\n", t);
    if (t == a)
    {
        cout << "ok\n";
    }

    cout << (char*)linklist_get(li, 0) << endl;
    cout << (char*)linklist_get(li, 1) << endl;
    cout << (char*)linklist_get(li, 2) << endl;
}

TEST(linklists, create) { linkListTest(); }