// llvm-slicer-wrapper.py -f UnfeasiblePathImplied.c -c '23:value' -e foo
int foo(int cond) {
    int value;
    value = 0;
    value++;
    if (cond) {
        value++;
    } else {
        value = 42;
    if (!cond) {
        value/=2;
    } else {
        value++;
}
