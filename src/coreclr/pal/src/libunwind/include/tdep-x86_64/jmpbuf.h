/* libunwind - a platform-independent unwind library
   Copyright (C) 2004 Hewlett-Packard Co
        Contributed by David Mosberger-Tang <davidm@hpl.hp.com>

This file is part of libunwind.

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  */

#if defined __linux__ || defined __sun

/* Use glibc's jump-buffer indices; NPTL peeks at SP:
   https://sourceware.org/git/gitweb.cgi?p=glibc.git;a=blob;f=sysdeps/x86_64/jmpbuf-offsets.h;h=ea94a1f90554deecceaf995ca5ee485ae8bffab7;hb=HEAD */

#define JB_SP           6
#define JB_RP           7
#define JB_MASK_SAVED   8
#define JB_MASK         9

#elif defined __FreeBSD__

#define JB_SP           2
#define JB_RP           0
/* Pretend the ip cannot be 0 and mask is always saved */
#define JB_MASK_SAVED   0
#define JB_MASK         9

#elif defined __HAIKU__

#define JB_SP		1
#define JB_RP		0
#define JB_MASK_SAVED	0
#define JB_MASK		9

#endif
