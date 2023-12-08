# Exercise

Implement the following functions:

```cpp
void compute_future_distance(VehicleType * vehicle,
                             const float ego_driven_distance,
                             const float seconds);

void compute_future_state(const VehicleType * ego_vehicle,
                          NeighborVehiclesType * vehicles,
                          const float seconds);
```

- compute_future_state
  - Compute the position of all vehicles in **n** seconds
- compute_future_distance
  - Helper function for **compute_future_state**

Hint:

The future distance of a vehicle is dependent on the ego vehicle speed and the others vehicle speed.  
Since the ego vehicle is always at the distance (x) = 0, hence the ego vehicle is the origin of the coordinate system.

## Main Function

```cpp
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
```
