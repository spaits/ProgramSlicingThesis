// llvm-slicer-wrapper.py -f IndirectFunctionCall.c -c '11:i' -e f
int getValue() {
    return 42;
void f() {
    fp = getValue;
    i = fp();
    i++;
