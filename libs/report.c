#include "report.h"

double timestamp() 
{
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return((double)(tp.tv_sec+tp.tv_usec/1000000.0));
}

void startTimestamp(double * timer) 
{
  *timer = timestamp();
}

void endTimestamp(double * timer)
{
  *timer = timestamp() - *timer;
}