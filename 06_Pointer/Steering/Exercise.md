# Exercise

For this exercise, we will extend our **Lanes2** code.  

We will add the option that the user can decide whether to change the lane and to accelerate or decelerate the car.  

For this implement the following function:

- get_user_input

Inside of this function you have to read whether the user wants to perform any actions.  
In the AdTypes.h file create two enums:

- **LongitudinalAction**: for acceleration or deceleration action (or none)
- **LateralAction**: for lane change action (to left or right, or none)

After processing the user input, do a lane change and adapt the vehicle speed regarding the input.

- handle_lateral_user_input(lane_idx, lateral_action);
- handle_longitudinal_user_input(speed_mps, longitudinal_action);

The acceleration/deceleration is applied by increasing/reducing the current speed ($\frac{m}{s}$) by 5%.  

For this we have the define **LONGITUDINAL_DIFFERENCE_PERCENTAGE** in **AdConstants.h**

## Example Console Output

![alt](../../media/6_Steering.png)

## Main Function

```cpp
int main()
{
    printf("Create the properties of a vehicle.\n");

    float speed_mps;
    printf("Speed in $\frac{m}{s}$: ");
    scanf("%f", &speed_mps);

    uint32_t lane_idx;
    printf("Lane (1=Right, 2=Center, 3=Left): ");
    scanf("%u", &lane_idx);

    while (true)
    {
        clear_console();

        print_scene(speed_mps, lane_idx);
        get_user_input(&speed_mps, &lane_idx);
    }

    return 0;
}
```
