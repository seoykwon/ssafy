#include <stdio.h>

// Conditional definitions for ABC, BBQ, and KFC
#ifndef _ABC_
#define _ABC_ 1
printf("Defining _ABC_\n");
#endif

#ifndef BBQ
#define BBQ "BBQ Defined"
#endif

#ifndef KFC
#define KFC "KFC Defined"
printf("Defining KFC\n");
#endif

// Main function
int main()
{
// If BBQ is defined, print name
#ifdef BBQ
    printf("BBQ is defined. My name is Kwon Seoy.\n");
#endif

    return 0;
}
