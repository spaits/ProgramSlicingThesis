// llvm-slicer-wrapper.py -f UnfeasiblePath.c -c '9:value' -e foo
int foo(int cond) {
    if (cond) {
    } else {
        value = 42;
