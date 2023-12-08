#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "AdFunctions.h"
#include "AdTypes.h"

#include "utils.h"

int main()
{
    VehicleType ego_vehicle;
    NeighborVehiclesType vehicles;

    init_ego_vehicle(&ego_vehicle);
    init_vehicles(&vehicles);

    print_vehicle(&ego_vehicle);
    print_neighbor_vehicles(&vehicles);

    printf("Start simulation?: ");
    char Input;
    (void)scanf("%c", &Input);

    while (true)
    {
        clear_console();

        compute_future_state(&ego_vehicle, &vehicles, 0.500f);
        print_scene(&ego_vehicle, &vehicles);
        longitudinal_control(&vehicles.vehicles_center_lane[0], &ego_vehicle);

        sleep_console(100);
    }

    return 0;
}
