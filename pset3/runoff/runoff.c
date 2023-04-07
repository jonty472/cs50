#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count = 3;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = get_string("Candidate? ");
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);
            // Record vote, unless it's invalid          
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // valid candidate.name
	for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            // i here will end up being the index of candidates[i].name
            preferences[voter][rank] = i;
            return true;
        }
	}
	// if candidates.name not found
	return false;
}

// Tabulate votes for non-eliminated candidate
void tabulate(void)
{
    int j = 0;
    for (int i = 0; i <= candidate_count; i++)
    {
        if (candidates[i].eliminated == false)
        {
            candidates[preferences[i][0]].votes++;
        }
        else
        {
            j++;
            candidates[preferences[i][j]].votes++;
        }
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    float total_votes = voter_count;
    
    float percentage_of_votes = candidates[0].votes / total_votes;
    for (int i = 0; i < candidate_count; i++)
    {
        // if a candidate has more than half the total votes they're the winner
        if ((candidates[i].votes / total_votes) > .50)
        {
            printf("winner is %s", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // copy candidate.votes
    int votes[candidate_count];
    for (int i = 0; i <= candidate_count; i++)
    {
        votes[i] = candidates[i].votes;
    }
    // sorting algorithm
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j <= candidate_count - 2; j++ )
        {
            if (votes[j] > votes[j+1])
            {
                int swap = votes[j+1];
                votes[j+1] = votes[j];
                votes[j] = swap;
            }
        }
    }
    return votes[0];
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // counter variable to establish if all candidates have the same amount of votes
    int number_of_ties = 0;
    for (int i = 0; i <= candidate_count; i++)
    {
        if (candidates[0].votes == candidates[i+1].votes)
        {
           number_of_ties++; 
        }
    }

    if (number_of_ties == candidate_count)
    {
        return true;
    }
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }    
}