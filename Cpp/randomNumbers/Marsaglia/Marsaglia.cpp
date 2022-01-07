// Marsaglia's xorshf generator
//

#include <stdio.h>

static unsigned long x=123456789, y=362436069, z=521288629;

unsigned long xorshf96(void) {          //period 2^96-1
unsigned long t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;

   t = x;
   x = y;
   y = z;
   z = t ^ x ^ y;

  return z;
}



int main(){
  const int Nsteps = 100000;
  for (int i=0; i< Nsteps; i++)
    printf("%d\n", xorshf96());
  return 0;
}





/**
 



  
  Numerical Recipes (I know, it's kind of debatable as they have put a lot of nonsense into those books over the years) advises against using XOR-shift alone and instead only in a combined generator. – Joey Nov 3 '09 at 6:42
       
        
        too few singular matrices is how it should be, because singular matrices are "singular" in the space of all matrices. – becko Feb 27 '14 at 16:29
             
              
              What can be a 64-bit version without calling this function twice? Is it enough to replace with uint64_t and change the first shift from 16 to 32? – Serge Rogatch Jun 15 '15 at 15:03
                   
                    
                    Tried this and on my hardware/compiler it was slightly slower than the xorshift128 on the wikipedia page for xorshift. – Paul Brannan Sep 4 '15 at 16:48 
 *
 *
 *
 * /
