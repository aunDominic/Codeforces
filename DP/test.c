int rec (int a, int b){
    int c = 1;
    int d = a - b;
    if (d > 0){
        rec(b,a);
    } else {
        do {
            a += c; c *=2;
        } while (a <= b);
    }
    return c;
}
int main () {
    int a = 4;
    int b = 2;
    int c = rec(4,2);



}