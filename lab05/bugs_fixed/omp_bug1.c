/******************************************************************************
* FILE: omp_bug1.c
* DESCRIPTION:
*   This example attempts to show use of the parallel for construct.  However
*   it will generate errors at compile time.  Try to determine what is causing
*   the error.
* AUTHOR: Blaise Barney  5/99
* LAST REVISED: 04/06/05
******************************************************************************/
/******************************************************************************
 * problem: there should be a for loop immediately after the #pragma 'for' clause
 * solution: move for loop right close to #pragma omp parallel for
******************************************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N       50
#define CHUNKSIZE   5

int main (int argc, char *argv[]) 
{
int i, chunk, tid;
float a[N], b[N], c[N];

/* Some initializations */
for (i=0; i < N; i++)
  a[i] = b[i] = i * 1.0;
chunk = CHUNKSIZE;

#pragma omp parallel for     \
  shared(a,b,c,chunk)            \
  private(i,tid)             \
  schedule(static,chunk)
  for (i=0; i < N; i++)
  {
   tid = omp_get_thread_num();
   c[i] = a[i] + b[i];
   printf("tid= %d i= %d c[i]= %f\n", tid, i, c[i]);
  }  /* end of parallel for construct */
 } 
