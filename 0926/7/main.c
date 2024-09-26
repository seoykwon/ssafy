#include <stdio.h>

// Conditional configuration for DEBUG and RELEASE modes
#ifdef DEBUG
#define CAMERA 1  // Camera module exists in DEBUG mode
printf("Defining CAMERA in DEBUG mode\n");
#else
#define GPS 1     // GPS module exists in RELEASE mode
printf("Defining GPS in RELEASE mode\n");
#endif

int main() {
	// If CAMERA module is defined, print "hifaker"
#ifdef CAMERA
	printf("hifaker\n");
#endif

	// If GPS module is defined, print "BBQ"
#ifdef GPS
	printf("BBQ\n");
#endif

	return 0;
}
