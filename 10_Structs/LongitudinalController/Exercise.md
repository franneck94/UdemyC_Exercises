# Exercise

Update the following functions

- print_scene:
  - Update the distance slices to 10m instead of 20m

Implement the following functions:

```cpp
float mps_to_kph(const float mps);

void decrease_speed(VehicleType *ego_vehicle);

void longitudinal_control(const VehicleType *front_vehicle, VehicleType *ego_vehicle);
```

- mps_to_kph
  - Convert $\frac{m}{s}$ to $\frac{km}{h}$ value
- longitudinal_control
  - If there is a vehicle in front of the ego vehicle
    - and the distance is below half speed (kph, "halbe tacho"), the vehicle needs to **decrease_speed**
- decrease_speed
  - Decrease the speed by the **LONGITUDINAL_DIFFERENCE_PERCENTAGE**

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

    printf("Start simulation?: ");
    char Input;
    (void)scanf("%c", &Input);

    while (true)
    {
        clear_console();

        print_scene(&ego_vehicle, &vehicles);
        compute_future_state(&ego_vehicle, &vehicles, 0.100F);
        longitudinal_control(&vehicles.vehicles_center_lane[0], &ego_vehicle);

        sleep_console(100);
    }

    return 0;
}
```
