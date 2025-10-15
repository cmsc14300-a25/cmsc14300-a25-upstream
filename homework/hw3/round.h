/*
 * CMSC 14300
 * Autumn 2025
 * Homework #3: Round header file
 *
 * Do not modify this file
 */

#ifndef ROUND_H
#define ROUND_H

// Data structure for holding the information for an election.
struct election_info {
  int num_candidates;         // Oiginal number of candidates
  int num_viable_candidates;  // Number of candidates who are still viable
  char **candidates;          // The first num_viable_candidates slots
                              // contain the viable candidates

  int num_ballots;
  char ***ballots;

  int *counts;            // Computed in run_round
  int exhausted_ballots;  // Computed in run_round
};

/* count_votes: Given an array of viable candidates and an array of ballots,
 *   set the ith element of the input count array to contain the number of
 *   times the ith candidate occurs as a voter's first viable choice.
 *
 * viable_candidates: the viable candidates
 * num_viable_candidates: the number of viable candidates in
 *   the candidates array
 * ballots: the ballots to count
 * num_ballots: the number of ballots to count
 * counts: an out parameter for reporting the number of votes each candidate
 *   received.  Has the same length as candidates.
 */
void count_votes(char *viable_candidates[], int num_viable_candidates,
                 char **ballots[], int num_ballots, int counts[]);

/* find_winner: Return the index of the candidate that has more than
 *   half the votes or -1, if none of the candidates reached that winning
 *   threshold.  Also, computes the total number of available ballots.
 *
 * counts: the number of votes earned by each candidate
 * num_viable_candidates: the number of candidates
 * *num_available_votes: an out parameter for the number of available
 *   ballots.
 *
 * Returns: the index of the winning candidate or -1, if there is no winner.
 */
int find_winner(int counts[], int num_viable_candidates,
                int *num_available_votes);

/* swap_lowest: Determine the candidate to be dropped.  Swap the
 *   candidate in the last spot in the viable candidates list with
 *   the candidate with the fewest votes.  Swap their counts as well.
 *
 *
 * viable_candidates: the viable candidates
 * num_viable_candidates: the number of viable candidates
 * counts: the number of votes earned by each candidate
 *
 */
void swap_lowest(char **viable_candidates, int num_viable_candidates,
                 int counts[]);

/* run_round: run one round of the election.
 *
 * info: the information need to run a round of the election.  The
 *   fields in this struct may be changed by the computation.
 *
 * Returns: the index of the winner, if there is one, and -1 otherwise.
 */
int run_round(struct election_info *info);

#endif  // ROUND_H
