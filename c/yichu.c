  #include <stdio.h>
  #include <stdlib.h>
  void _ctx_iface(__int128_t s, __int128_t mask, int i)
  {
      printf("%c", (char)(((s & (mask << i)) >> i) + (__int128_t)65));
  }
  
  int main(int argc, char **argv)
  {
      _ctx_iface(0xDA, 0xFULL, 3);
      _ctx_iface(0x42, 0xFULL, 3);
      _ctx_iface(0x6f, 0xFULL, 3);
      _ctx_iface(0x283, 0x1FULL, 5);
      _ctx_iface(0x6e0, 0x1FULL, 5);
  }
