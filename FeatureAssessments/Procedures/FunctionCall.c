int getValue() {
    return 42;
}

void f() {
    int i;
    i = getValue();
    /*@ slice pragma expr i; */
    i++;
}

int main() {}