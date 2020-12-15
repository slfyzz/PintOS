#include "fixed_point.h"


static int f = 1 << 14;

fixed_point convert_to_fixed (int n) {
    return n * f;
}

int convert_to_int (fixed_point x) {
    return x / f;
}

int convert_to_int_round( fixed_point x) {
    return (x >= 0) ? (x + f / 2) / f : (x - f / 2) / f;
}

fixed_point add (fixed_point x, fixed_point y) {
    return x + y;
}

fixed_point sub (fixed_point x, fixed_point y) {
    return x - y;
}

fixed_point mul (fixed_point x, fixed_point y) {
    return ((int64_t) x) * y / f;
}

fixed_point div (fixed_point x, fixed_point y) {
    return  ((int64_t) x) * f / y;
}