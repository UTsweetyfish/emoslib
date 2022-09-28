/**
* Copyright 1981-2016 ECMWF.
*
* This software is licensed under the terms of the Apache Licence
* Version 2.0 which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
*
* In applying this licence, ECMWF does not waive the privileges and immunities
* granted to it by virtue of its status as an intergovernmental organisation
* nor does it submit to any jurisdiction.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common/fortint.h"

fortint mvchars_(fortint * k, char * s, long ls) {
/*
// Callable from Fortran to move a string of characters from s to integer
// array k:
//
//       INTEGER K(*)
//       CHARACTER*(*) S
//       INTEGER MVCHARS
//       EXTERNAL MVCHARS
//
//       IRET = MVCHARS(K, S)
//
// Trailing blanks are ignored.
// IRET is the count of the number of characters moved.
*/
int loop, last = -1;
char * p = (char *) k;
/*
// Find the last non-blank character
*/
    for( loop = (ls - 1) ; loop >=0;  loop-- )
      if( *(s+loop) != ' ' ) {
        last = loop;
        break;
      }
/*
// Fill k from s
*/
    for( loop = 0; loop <= last ; loop++ )
      *p++ = *(s+loop);

    return (fortint) (last+1);
}

fortint mvchars(fortint * k, char * s, long ls) {

return  mvchars_(k,s,ls);
}
