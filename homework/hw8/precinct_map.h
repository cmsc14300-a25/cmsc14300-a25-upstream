/*
 * CMSC 14300
 * Autumn 2025
 * Homework #7: Precinct map header file
 *
 * Do not modify this file
 */


#ifndef PRECINCT_MAP_H
#define PRECINCT_MAP_H

#include "precinct.h"

typedef struct precinct_map precinct_map_t;

/* mk_ht: constructs an empty precinct map
 *
 * Returns: a precinct map
 */
precinct_map_t *mk_pm(void);


/* free_pm: frees the space associated with a precinct map, including
 *   the precincts themselves.
 *
 * pm: a precinct map
 *
 * Returns: nothing
 */
void free_pm(precinct_map_t *pm);


/* lookup_pm: lookups the name of a precinct in the precinct map,
 *   returns the associated precinct or NULL, if the specified name
 *   does not appear in the map.
 *
 * pm: a precinct map
 * name: the name of a precinct
 *
 * Returns: the precinct associated with the name or NULL, if the name
 *   does not occur in the map.
 */
precinct_t *lookup_pm(precinct_map_t *pm, char *name);


/* add_precinct_pm: Adds the name/precinct to the map only if the
 *   precinct is not already in the map.  Returns true if the precinct
 *   is new and false, otherwise.
 *
 * pm: a precinct map
 * precinct: the precinct to be added.
 *
 * Returns: true if the precinct was added to the map and false,
 *   otherwise.
 */
bool add_precinct_pm(precinct_map_t *pm, precinct_t *precinct);


/* get_num_entries_pm: returns the number of name/precinct pairs in
 *   the map
 *
 * pm: a precinct map
 *
 * Returns: the number of name/precinct pairs in the map.
 */
unsigned int get_num_entries_pm(precinct_map_t *pm);


/* get_names_pm: fills the names array with the names from the map.
 *   This function will fail if len is less than the number of names
 *   in the map.
 *

 * names: an array of strings long enough to hold all the names
 * len: the length of the array
 *
 * Returns: nothing
 */
void get_names_pm(precinct_map_t *pm, char *names[], int len);

#endif
