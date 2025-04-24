// llvm-slicer-wrapper.py -f FunctionCall.c -c '9:i' -e f
int getValue() {
    return 42;
void f() {
    i = getValue();
    i++;
