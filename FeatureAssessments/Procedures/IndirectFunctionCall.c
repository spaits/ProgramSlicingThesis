int getValue() {
    return 42;
}

void f() {
    int i;
    int (*fp)(void);
    fp = getValue;
    i = fp();
    /*@ slice pragma expr i; */
    i++;
}

int main() {}