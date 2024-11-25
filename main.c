#include <stdio.h>
#include "map.h"
#include "loc.h"
#include "moves.h"
#include "phase.h"
#include "time.h"
int main() {
    t_map map;

    // The following preprocessor directive checks if the code is being compiled on a Windows system.
    // If either _WIN32 or _WIN64 is defined, it means we are on a Windows platform.
    // On Windows, file paths use backslashes (\), hence we use the appropriate file path for Windows.
#if defined(_WIN32) || defined(_WIN64)
    map = createMapFromFile("..\\maps\\example1.map");
#else
    map = createMapFromFile("../maps/example1.map");
#endif

    printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%d ", map.soils[i][j]);
        }
        printf("\n");
    }
    // printf the costs, aligned left 5 digits
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%-5d ", map.costs[i][j]);
        }
        printf("\n");
    }
    t_chance chance;
    chance.F_10 = 22; chance.F_20 = 15; chance.B_10 = 7; chance.F_30 = 7; chance.T_LEFT = 21; chance.T_RIGHT = 21; chance.U_TURN = 7;
    t_localisation robot = loc_init(3,3,EAST);
    printf("\n");
    displayMap(map);
    printf("\n");
    while (map.costs[robot.pos.x][robot.pos.y]!=0) {
        double time_spent = 0.0;
        clock_t begin = clock();
        robot = phase(robot, chance, map);
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

        printf("\nNouvelle localisation du robot : (x: %d,y : %d) prix : %d\n", robot.pos.x,robot.pos.y,(map.costs[robot.pos.x][robot.pos.y]));
        printf("\nThe elapsed time is %f seconds\n", time_spent);
    }
    printf("\n");
    printf("\n");

    return 0;
}
