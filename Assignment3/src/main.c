/*
 Author = "Alireza Khodamoradi"
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pmu_counters.h>
#include <cycletime.h>

unsigned int my_get_cyclecount(void){
  return get_cyclecount();
}

void my_init_counters(int32_t do_reset, int32_t enable_divider){
init_counters(do_reset, enable_divider);
}

