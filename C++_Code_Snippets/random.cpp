#include <stdlib.h>

int rand(void);
// returns a pseudo-random number in the range of 0 to RAND_MAX. RAND_MAX is a constant whose default value may vary between implementations,
// but it is granted to be at least 32767.

void srand(unsigned seed); 
// Seeds the pseudo-random number generator used by rand() with the value seed.
#include <time.h>
srand(time(0)); 
for(int i = 0; i<4; i++) 
    printf(" %d ", rand());
