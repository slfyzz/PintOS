#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <stdint.h>

typedef int fixed_point;

fixed_point convert_to_fixed (int n);
int convert_to_int (fixed_point x);
int convert_to_int_round( fixed_point x);
fixed_point add (fixed_point x, fixed_point y);
fixed_point sub (fixed_point x, fixed_point y);
fixed_point mul (fixed_point x, fixed_point y);
fixed_point div (fixed_point x, fixed_point y);
fixed_point add_int (fixed_point x, int n);
fixed_point sub_int (fixed_point x, int n);
fixed_point mul_int (fixed_point x, int n);
fixed_point div_int (fixed_point x, int n);

#endif
