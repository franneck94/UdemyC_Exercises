# Exercise

Remove the following functions from AdFunctuns.c/h:

```cpp
void init_vehicle(VehicleType *vehicle,
                  const int32_t id,
                  const float speed_kph,
                  const float distance,
                  const LaneAssociationType lane);

void init_ego_vehicle(VehicleType *ego_vehicle);

void init_vehicles(NeighborVehiclesType *vehicles);
```

Add the following defines to AdConstants.h

- NUM_CYCLES = 1000
- NUM_VEHICLES = 6

Implement the following functions in the AdDataLoader.c/h:

```cpp
void preload_ego_vehicle_data(const char datapath[128]);

void preload_vehicle_data(const char datapath[128]);

// The functions below will be implemented in the next exercise
void init_ego_vehicle(VehicleType *ego_vehicle);

void init_vehicle(VehicleType *vehicle, const int32_t id, const uint32_t cycle);

void init_vehicles(NeighborVehiclesType *vehicles);

void load_cycle(NeighborVehiclesType *vehicles, const uint32_t cycle);
```

- **preload_ego_vehicle_data**
  - Read in the data from the file **./data/ego_data.txt**
    - Store the information into a global **static** struct variable **EGO_VEHICLE_DATA**
- **preload_vehicle_data**
  - Read in the complete data from the files **./data/vehicle_0...6.txt**
    - Store the information into a global **static** struct variable **VEHICLE_DATA**

## Main Function

```cpp
int main()
{
    VehicleType ego_vehicle;
    NeighborVehiclesType vehicles;

    preload_ego_vehicle_data(datapath);
    preload_vehicle_data(datapath);

    init_ego_vehicle(&ego_vehicle);
    init_vehicles(&vehicles);

    print_vehicle(&ego_vehicle);
    print_neighbor_vehicles(&vehicles);

    printf("Start simulation?: ");
    char Input;
    (void)scanf("%c", &Input);

    for (uint32_t cycle = 0; cycle < NUM_CYCLES; cycle++)
    {
        clear_console();
        load_cycle(&vehicles, cycle);

        print_scene(&ego_vehicle, &vehicles);
        compute_future_state(&ego_vehicle, &vehicles, 0.100F);

        const VehicleType *ego_lane_vehicles = get_vehicle_array(ego_vehicle.lane, &vehicles);
        longitudinal_control(&ego_lane_vehicles[0], &ego_vehicle);

        const LaneAssociationType lane_change_request =
            get_lane_change_request(&ego_vehicle, &vehicles);
        const bool lane_change_executed = lateral_control(lane_change_request, &ego_vehicle);

        if (lane_change_executed)
        {
            printf("Executed lane change!");
        }

        sleep_console(100);
    }


    return 0;
}
```
