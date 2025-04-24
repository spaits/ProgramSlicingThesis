int main() {
    int value = 0;
    int cond = 1;
    if (cond) {
        value = 42;
    } else {
        value++;
    }
    /*@ slice pragma expr value; */
    value++;
    return 0;
}