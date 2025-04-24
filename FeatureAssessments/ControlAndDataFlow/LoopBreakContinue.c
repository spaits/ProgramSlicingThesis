void foo(int b) {
    int i = 0;
    while (i < 42) {
        if (b % 2 == 0) {
            i += 2;
        } else {
            /*@ slice pragma expr i; */
            i++;
            continue;
        }
        if (i == 21) {
            i = 42;
            break;
        }
    }
}

int main() {}