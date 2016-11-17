 int f(int a, int b)
 {
     return a + b;
 }
 int g(int a, int b)
 {
     return a*b;
 }
 int main()
 {
     int c,d,e,f;
     c = d = e = f = 1;
     f <<= 1;
     e >>= 2;
     d += 5;
     c ^= 0x10;
     for (int i = 0; i <= 5; ++i) {
         if (i % 2 == 0) {
             f(i, i+1);
         } else {
             g(i, i+1);
         }
     }
 }