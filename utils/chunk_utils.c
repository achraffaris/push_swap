#include "../push_swap.h"

int exists(int *ref_arr, int node_id, int start, int end)
{
    int i;

    i = start;
    while (i <= end)
    {
        if (ref_arr[i] == node_id)
            return (TRUE);
        i++;
    }
    return (FALSE);
}