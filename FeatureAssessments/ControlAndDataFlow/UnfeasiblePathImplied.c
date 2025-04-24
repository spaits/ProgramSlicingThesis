void foo(int cond) {
    int value;
    value = 0;
    value++;
    if (cond) {
        value++;
    } else {
        value = 42;
    }

    if (!cond) {
        /*@ slice pragma expr value; */
        value/=2;
    } else {
        value++;
    }
}

int main() {}