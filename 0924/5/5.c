#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    //    char vect[100] = "DBABCABCEQ";
    char vect[100] = "DBABCEQABC";
    char tar[4] = "ABC";

    char *p = strstr(vect, tar);
    char *pp = vect;

    int idx = 0;

    int len = strlen(vect);

    while (idx < len)
    {

        p = strstr(pp, tar);

        if (&vect[idx] == p)
        {
            idx += 3;
            pp = &vect[idx];
            //        	p = strstr(pp, tar);
            continue;
        }
        printf("%c", vect[idx]);
        idx++;
    }
}

// #include <stdio.h>
// #include <string.h>
//
// int main() {
//     char vect[100] = "DBABCEQABC";
//     char tar[4] = "ABC";
//
//     char* p = strstr(vect, tar);
//     int tar_len = strlen(tar);  // Length of the substring to be removed
//
//     while (p != NULL) {
//         // Shift the remaining characters left to remove the substring
//         int i;
//         for (i = 0; p[i + tar_len] != '\0'; i++) {
//             p[i] = p[i + tar_len];  // Move characters to the left
//         }
//         p[i] = '\0';  // Null-terminate the string after shifting
//
//         // Find the next occurrence of 'tar'
//         p = strstr(vect, tar);
//     }
//
//     // Print the modified string after all occurrences of 'tar' have been removed
//     printf("%s\n", vect);
//
//     return 0;
// }
