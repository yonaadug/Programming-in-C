
/*******************************************************************************
@ddblock_begin copyright 

Copyright (c) 1999-2009
Maryland DSPCAD Research Group, The University of Maryland at College Park 
All rights reserved.

IN NO EVENT SHALL THE UNIVERSITY OF MARYLAND BE LIABLE TO ANY PARTY
FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES
ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF
THE UNIVERSITY OF MARYLAND HAS BEEN ADVISED OF THE POSSIBILITY OF
SUCH DAMAGE.

THE UNIVERSITY OF MARYLAND SPECIFICALLY DISCLAIMS ANY WARRANTIES,
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. THE SOFTWARE
PROVIDED HEREUNDER IS ON AN "AS IS" BASIS, AND THE UNIVERSITY OF
MARYLAND HAS NO OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT, UPDATES,
ENHANCEMENTS, OR MODIFICATIONS.
@ddblock_end copyright 
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>


/* Maximum vector length. */ 
#define MAX_LENGTH 10

/*****************************************************************************
Determine the inner product of two vectors.
*****************************************************************************/
int main(void) {
    int length = 0;
    int i = 0;
    int a[MAX_LENGTH];
    int b[MAX_LENGTH];
    int result = 0;

    /* Read and validate the vector length. */
    printf("Enter the vector length: \n");
    if (scanf("%d", &length) != 1) {
        fprintf(stderr, "Missing vector length.\n");
        exit(1);
    }
    if ((length < 1) || (length > MAX_LENGTH)) {
        fprintf(stderr, "Invalid vector length.\n");
        exit(1);
    }

    /* Read the first vector. */
    printf("Enter the first vector, separate each element by whitespace.\n");
    for (i = 0; i < length; i++) {
        if (scanf("%d", &(a[i])) != 1) {
            fprintf(stderr, "Missing vector element.\n");
            exit(1);
        }
    }

    /* Read the second vector. */
    printf("Enter the second vector, separate each element by whitespace.\n");
    for (i = 0; i < length; i++) {
        if (scanf("%d", &(b[i])) != 1) {
            fprintf(stderr, "Missing vector element.\n");
            exit(1);
        }
    }

    /* Compute and print the result. */
    for (i = 0; i < length; i++) {
        result += a[i] * b[i];
    }
    printf("The result is %d\n", result);

    return 0;
}
