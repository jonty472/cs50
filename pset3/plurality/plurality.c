#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
	string name;
	int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
	// Check for invalid usage
	if (argc < 2)
	{
		printf("Usage: plurality [candidate ...]\n");
		return 1;
	}

	// Populate array of candidates
	candidate_count = argc - 1;
	if (candidate_count > MAX)
	{
		printf("Maximum number of candidates is %i\n", MAX);
		return 2;
	}
	for (int i = 0; i < candidate_count; i++)
	{
		candidates[i].name = argv[i + 1];
		candidates[i].votes = 0;
	}

	int voter_count = get_int("Number of voters: ");

	// Loop over all voters
	for (int i = 0; i < voter_count; i++)
	{
		string name = get_string("Vote: ");

		// Check for invalid vote
		if (!vote(name))
		{
			printf("Invalid vote.\n");
		}
		else //count candidates vote
		{
			for (int j = 0; j < candidate_count; ++j)
			{
				if (strcmp(candidates[j].name, name) == 0)
				{
					candidates[j].votes += 1;
				}
			}
		}
	}
	// Display winner of election
	print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
	// valid candidate.name
	for (int i = 0; i <= candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            //printf("Found %s\n", candidates[i].name);
            return true;
        }
	}

	// if candidates.name not found
	return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
	int sorted_votes[candidate_count];

	// array copy of candidates.votes for bubble sort
	for (int i = 0; i < candidate_count; i++)
	{
		sorted_votes[i] = candidates[i].votes;
	}
	// bubble sorting candidates.votes
	for (int i = 0; i <= candidate_count - 1; i++)
    {
        for (int j = 0; j <= candidate_count - 2; j++)
        {
            // if 5 > 2
            if (sorted_votes[j] < sorted_votes[j+1])
            {
                int swap = sorted_votes[j+1];
                sorted_votes[j+1] = sorted_votes[j];
                sorted_votes[j] = swap;
            }
        }
    }

	// find winner(s)
	for (int i = 0; i < candidate_count; i++)
	{
		if (candidates[i].votes == sorted_votes[0])
		{
			printf("%s", candidates[i].name);
			printf("\n");
		}
	}
}