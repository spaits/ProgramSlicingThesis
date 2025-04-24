int main() {
    int values[3];
    int i;
    int *elementPointer;
    int element;

    for ( i = 0; i < 3; i++) {
        values[i] = i + 1;
    }

    elementPointer = values + 1;
    element = *elementPointer;
    /*@ slice pragma expr element; */
    element++;
}
