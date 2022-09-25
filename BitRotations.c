#include <stdio.h>
void print_bits(unsigned int x)
{ // print 32 bits in 4 bits pairs
    unsigned int size = sizeof(unsigned int);
    unsigned int maxPow = 1<<(size*8-1);
    
    for(int i = 31; i >= 0; i--){
        printf("%u", !!(x & maxPow));
        x = x<<1;
        if (i % 4 == 0)
            printf(" ");
    }
     printf("\n"); 
}

unsigned int rotate_left_by_nbits(unsigned int x, int n){
    unsigned int size = sizeof(unsigned int);

    if((n&=size*8-1) ==0){
        return x;
     }
    return (x <<n) | (x >> (size*8 - n));

}

unsigned int rotate_right_by_nbits(unsigned int x, int n) {
    unsigned int size = sizeof(unsigned int);
    if((n &= size*8 - 1) == 0){
        return x;
    }
    
    return (x >> n) | (x << (size*8 - n));
    }


unsigned int rotate_first_nbits_left(unsigned int x, int n) {
    unsigned int size = sizeof(unsigned int);
  return (x << n) | (x >> (size*8 - n));
}

unsigned int rotate_first_nbits_right(unsigned int x, int n) {
    unsigned int size = sizeof(unsigned int);
    
  return (x >> n) | (x << (size*8 - n));
}


int main()
{
    print_bits(123);
    print_bits(0xa5f41039);
    print_bits(rotate_left_by_nbits(0xa5f41039, 6));
    print_bits(rotate_right_by_nbits(0xa5f41039, 3));
    print_bits(rotate_first_nbits_left(0xa5f41039, 8));
    print_bits(rotate_first_nbits_right(0xa5f41039, 4));

}