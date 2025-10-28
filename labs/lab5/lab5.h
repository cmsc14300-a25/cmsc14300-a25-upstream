#ifndef LAB5_H
#define LAB5_H

/* fib: Compute the nth Fibonacci number, where the 0th number is 0,
 * the 1st is 1, and each subsequent number is the sum of its two
 * predecessors.
 *
 * n: the number of interest
 *
 * Returns: the nth Fibonacci number.
 */
unsigned int fib(unsigned int n);

/* fact: compute n factorial: the product of the values from 1 to
 *   inclusive
 *
 * n: the number of interest
 *
 * Returns: n!
 */
unsigned int fact(unsigned int n);

/* int_new: Allocate space for an int on the heap, initializes it with
 * the specified value, and returns a pointer to the allocated space.
 *
 * init: the initial value
 *
 * Returns: a pointer to enough space to hold an integer, initialized
 *  to the specified value.
 */
int *int_new(int init);


/* upto: builds an array of integers from 0 up to n, inclusive of both
 *   upper and lower bounds.
 *
 * n: the upper bound on the values in the result
 *
 * Returns: an array of integers from 0 to n inclusive.
 */
unsigned int *upto(unsigned int n);


/* num_events: counts the even numbers in the given array.
 *
 * vals: the values of interest
 *
 * Returns: the number of even numbers in vals.
 */
unsigned int num_evens(unsigned int *a, unsigned int len);


#endif
