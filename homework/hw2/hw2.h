/*
 * CMSC 14300
 * Autumn 2025
 * Homework #2 Header File
 *
 * Do not modify this file
 */

/* As in Lab #2, there are restrictions on the operators and/or control
 * constructs that you are allowed to use in some of the exercises. Please
 * note that you will not receive creait for solutions violate the restrictions.
 * See the assignment writeup for details.
 */

#include <stdbool.h>

/*
 * Exercise 1
 *
 * are_friendly: Determine whether two integers are friendly
 * with respect to a divisor.
 *
 * num1: the first integer
 * num2: the second integer
 * divisor: the divisor
 *
 * Returns: true if num1 and num2 are friendly, false otherwise.
 */
bool are_friendly(int num1, int num2, int divisor);

/* Exercise 2
 *
 * compute_degree_of_friendship: Find the number of common divisors
 * for two integers.
 *
 * num1: the first integer
 * num2: the second integer
 *
 * Returns: The number of common divisors.
 */
int compute_degree_of_friendship(int num1, int num2);

/* Exercise 3
 *
 * has_even_parity: Determine whether an integer has even parity
 * (i.e., whether it's even).
 *
 * num: the integer
 *
 * Returns: true if num is even, false otherwise.
 */
bool has_even_parity(int num);

/* Exercise 4
 *
 * goldschmidt: Compute the square root of a number using Goldschmidt's
 * algorithm.
 *
 * N: the number to find the square root of
 * est: an estimate for 1/sqrt(N)
 * max_iters: the maximum number of iteration to perform
 * tol: the convergence tolerance
 *
 * Returns: An approximation of the square root of N.
 */
double goldschmidt(double N, double est, int max_iters, double tol);

/* Exercise 5
 *
 * find_index_of_lowest_1: Find the index of the lowest-order 1 bit
 * in the binary representation of an integer.
 *
 * num: the integer
 *
 * Returns: The index of the lowest-order 1 in an unsigned integer, or -1
 * value does not have a 1 in its representation.
 */
int find_index_of_lowest_1(unsigned int num);

/* Exercise 6
 *
 * find_index_of_highest_1: Find the index of the highest-order 1 bit
 * in the binary representation of an integer.
 *
 * num: the integer
 *
 * Returns: The index of the highest-order 1 in an unsigned integer, or -1
 * value does not have a 1 in its representation.
 */
int find_index_of_highest_1(unsigned int num);

/* Exercise 7
 *
 * set_bits_between: computes a new unsigned integer where all the bits
 * between the lowest-order 1 and the highest order 1 are set to 1.
 *
 * num: the unsigned integer
 *
 * Returns: An unsigned integer with all the bits between the lowest order
 * one bit in the input and the highest order one bit in the input to one.
 * Returns zero if there are no one bits in the input.
 */
unsigned int set_bits_between(unsigned int num);
