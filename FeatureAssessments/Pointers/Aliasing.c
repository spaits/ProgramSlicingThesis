int main() {
    int data;
    int *mp;
    int *p1;
    int *p2;
    int *valueToTrack;
    int anotherOne;

    data = 42;
    mp = &data;
    p1 = mp;
    p2 = p1;
    valueToTrack = mp;
    *p2 = 0;
    *valueToTrack = *p2 + 42;
    *p1 = *p1 + 8;
    *mp = *mp + 21;
    /*@ slice pragma expr valueToTrack; */
    anotherOne = *valueToTrack + 21; 
}