void foo(int cond) {
    int value;
    value = 0;
    value++;
    if (cond) {
        value++;
    } else {
        /*@ slice pragma expr value; */
        value = 42;
    }
}

int main() {}