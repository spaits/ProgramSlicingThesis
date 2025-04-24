// llvm-slicer-wrapper.py -f PointerArithmetic.c -c '14:element' -e main
int main() {
    for ( i = 0; i < 3; i++) {
        values[i] = i + 1;
    elementPointer = values + 1;
    element = *elementPointer;
    element++;
