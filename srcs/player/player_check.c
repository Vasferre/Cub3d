#include "../../includes/cub3d.h"

bool player_check(char c)
{
    if(c ==  'N' || c == 'S' || c == 'W' || c == 'E')
        return(true);
    return(false);
}