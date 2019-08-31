
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

#include "inner_product.h"

/* Maximum vector length. */ 
#define MAX_LENGTH 10

int inner_product(int a[], int b[], int length) {
    int i = 0;
    int result = 0;

    /* Validate the vector length. */
    if ((length < 1) || (length > MAX_LENGTH)) {
        fprintf(stderr, "Invalid vector length.\n");
        exit(1);
    }

    /* Return the result. */
    for (i = 0; i < length; i++) {
        result += a[i] * b[i];
    }
    return result; 

    return 0;
}
