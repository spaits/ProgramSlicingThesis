// llvm-slicer-wrapper.py -f ConcreteValuePropagation.c -c '10:value' -e main
int main() {
    int value = 0;
    int cond = 1;
    if (cond) {
        value = 42;
    } else {
        value++;
    value++;
