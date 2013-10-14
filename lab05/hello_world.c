/******************************************************************************
Can you also make it so that it also works with a non-openmp compiler?
******************************************************************************/
#ifdef _OPENMP
   #include <omp.h>
#else
      #define omp_get_thread_num() 0
      #define omp_get_num_threads() 1
#endif
#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
#pragma omp parallel
 {
  #pragma omp master
   {
    int nthreads = omp_get_num_threads();
    printf("Total number of tasks: %d\n", nthreads);
   }

  #pragma omp barrier
  int tid = omp_get_thread_num();
  printf("Hello world from task: %d \n",tid);
 }
}
