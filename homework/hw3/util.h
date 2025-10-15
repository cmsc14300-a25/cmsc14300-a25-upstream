#ifndef UTIL_H
#define UTIL_H

/* read_ballots_from_file: read ballots from a ballot file.
 *
 * filename: the name of the file with the ballots
 * num_ballots: out parameter to hold the number of ballots read from the file.
 *
 * Returns: an array of ballots.
 */
char ***read_ballots_from_file(char *filename, int *num_ballots);

/* print_ballots: print an array of ballots in ballot-file format to stdout.
 *   Uses student's print_ballot function to generate the string for each
 * ballot.
 *
 * ballots: the ballots to count
 * num_ballots: the number of ballots to count
 */
void print_ballots(char ***ballots, int num_ballots);

/* free_ballots: free the space associated with an array of ballots.
 *   Uses student's free_ballot function to free an individual ballot.
 *
 * ballots: the ballots to count
 * num_ballots: the number of ballots to count
 */
void free_ballots(char ***ballots, int num_ballots);

/* read_candidates_from_file: helper function that reads the
 *   a list of viable candidates from a file
 *
 * filename: the name of the candidate file
 * num_candidates: an out parameter that will be set to the number
 *   of candidates
 *
 * Returns: an array of candidate names, represented as strings.
 */
char **read_candidates_from_file(char *filename, int *num_candidates);

/* 
 * free_candidates: free the space associated with a viable candidates
 *   array.
 *
 * viable_candidates: the viable candidates
 * num_candidates: the number of candidates
 *
 * Returns: nothing
 */
void free_candidates(char *viable_candidates[], int num_candidates);

#endif  // UTIL_H
