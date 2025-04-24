// llvm-slicer-wrapper.py -f LoopBreakContinue.c -c '8:i' -e foo
void foo(int b) {
    int i = 0;
    while (i < 42) {
        if (b % 2 == 0) {
            i += 2;
        } else {
            i++;
        if (i == 21) {
