#include "../include/so_long.h"

//gcc  -I ./mlx -L ./mlx -lmlx -framework OpenGL -framework AppKit main.c -o so_long

// int main(int argc, char **argv)
// {
//     t_map *map_data;
//     char **map;
//     int i;

//     map_data = check_map(argc, argv);
//     if (!map_data)
//         return (1);

//     map = ber_to_array(argc, argv, map_data);
//     if (!map)
//     {
//         free(map_data);
//         return (1);
//     }

//     i = 0;
//     while (i < map_data->rows)
//     {
//         printf("%s\n", map[i]);
//         i++;
//     }
//     check_border(map, map_data);
//     count_cpe(map, map_data);
//     check_cpe(map, map_data);
//     printf(1, "total rows :%d \n", map_data->rows);
//     printf(1, "total columns :%d \n", map_data->columns);
//     printf(1, "total total C :%d \n", map_data->total_c);
//     printf(1, "total Total P :%d \n", map_data->total_p);    
//     printf(1, "total Total E :%d \n", map_data->total_e);
//     printf(1, "Wrong Columns :%d \n", map_data->wrong_columns);
//     printf(1, "test");
//     // Clean up
//     free_array(map, map_data->rows);
//     free(map_data);
//     return (0);
// }

int main(int argc, char **argv)
{
    t_map *map_data;
    char **map;
    int i;

    write (2, "test\n", 5);

    // Validate command-line arguments
    if (argc != 2)
    {
        write(2, "Error: Invalid number of arguments\n", 35);
        return (1);
    }

    // Check map and validate map data
    map_data = check_map(argc, argv);
    if (!map_data)
    {
        write(2, "Error: Map validation failed\n", 29);
        return (1);
    }

    // Convert .ber file to array
    map = ber_to_array(argc, argv, map_data);
    if (!map)
    {
        write(2, "Error: Failed to convert map to array\n", 38);
        free(map_data);
        return (1);
    }

    // Optional: Print map contents
    i = 0;
    while (i < map_data->rows)
    {
        write(1, map[i], map_data->columns);
        write(1, "\n", 1);
        i++;
    }

    // Validate map components
    if (check_border(map, map_data) == 0)
    {
        write(2, "Error: Invalid map borders\n", 27);
        free_array(map, map_data->rows);
        free(map_data);
        return (1);
    }

    // Count and check map components
    count_cpe(map, map_data);
    if (check_cpe(map, map_data) == 0)
    {
        free_array(map, map_data->rows);
        free(map_data);
        return (1);
    }

    // Debug print statements
    dprintf(1, "Total rows: %d\n", map_data->rows);
    dprintf(1, "Total columns: %d\n", map_data->columns);
    dprintf(1, "Total Collectibles: %d\n", map_data->total_c);
    dprintf(1, "Total Player: %d\n", map_data->total_p);    
    dprintf(1, "Total Exit: %d\n", map_data->total_e);
    dprintf(1, "Wrong Columns: %d\n", map_data->wrong_columns);

    // Clean up
    free_array(map, map_data->rows);
    free(map_data);
    return (0);
}