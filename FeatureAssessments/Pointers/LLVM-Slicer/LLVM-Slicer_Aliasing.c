// llvm-slicer-wrapper.py -f Aliasing.c -c '19:valueToTrack' -e main
int main() {
    mp = &data;
    valueToTrack = mp;
    anotherOne = *valueToTrack + 21; 
