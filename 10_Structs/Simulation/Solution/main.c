#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"

#include "AdFunctions.h"
#include "AdTypes.h"

int main()
{
    VehicleType ego_vehicle;
    NeighborVehiclesType vehicles;

    init_ego_vehicle(&ego_vehicle);
    init_vehicles(&vehicles);

    print_vehicle(&ego_vehicle);
    print_neighbor_vehicles(&vehicles);

    print_scene(&ego_vehicle, &vehicles);

    printf("Start simulation?: ");
    char Input;
    (void)scanf("%c", &Input);

    while (true)
    {
        clear_console();

        compute_future_state(&ego_vehicle, &vehicles, 0.500f);
        print_scene(&ego_vehicle, &vehicles);

        sleep_console(500);
    }

    return 0;
}
