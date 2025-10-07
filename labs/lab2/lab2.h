/*
 * CMSC 14300
 * Autumn 2025
 * Lab #2 Header File
 *
 * Do not modify this file
 */

#include <stdbool.h>

/*
 * Task 1
 *
 * compute_div_fraction - extract fractional part of the value that
 * results from dividing x by y.
 *
 * x: numerator (assume x > 0)
 * y: denominator (assume y > 0)
 *
 * Returns: value less than or equal to zero
 */
double compute_div_fraction(int x, int y);

/* Task 2
 *
 * in_range_1: is x in the range lb..ub
 *
 * Restriction: use only relational (<, <=, >, >=, ==) and logical
 * operators (&&, ||, !) for this task.  You may NOT use conditional
 * statements or conditional expressions for this task.
 *
 * lb, ub: range
 * is_inclusive: true if ends points should included in the range
 * x: value to check
 *
 * Returns: true if x is in the range, false otherwise.
 */
bool in_range_1(double lb, double ub, double x, bool is_inclusive);

/* Task 3
 *
 * in_range_1: is x in the range lb..ub
 *
 * Restriction: use only relational operators (<, <=, >, >=, ==) and
 * conditionals for this task.  You may NOT use logical operators
 * (that is, &&, ||, or !) for this task.
 *
 * lb, ub: range
 * is_inclusive: true if ends points should included in the range
 * x: value to check
 *
 * Returns: true if x is in the range, false otherwise.
 */
bool in_range_2(double lb, double ub, double x, bool is_inclusive);

/* Task 4
 *
 * clip - clip values outside the interval [lb, ub] (inclusive) to the
 *   interval edges.
 *
 * You are required to use a conditional expression for this task.
 *
 * x: value to be clipped
 * lb: lower bound of the interval
 * ub: upper bound of the interval
 *
 * Returns: clipped value
 */

double clip(double x, double lb, double ub);

/* Task 5
 *
 * compute_leonardo_iter - the Leonardo numbers are a sequence of numbers given
 * by the recurrence:
 *    L(n) = 1  if n = 0
 *         = 1  if n = 1
 *         = L(n-1) + L(n-2) + 1 if n > 1
 *
 * The first few Leonardo Numbers are 1, 1, 3, 5, 9, 15, 25, 41, 67, 109,
 *   177, 287, 465, 753, 1219, 1973, 3193, 5167, 8361, ···
 * Returns: nth leonardo number as an integer
 */
int compute_leonardo(int n);