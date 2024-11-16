#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "AdConstants.h"
#include "AdFunctions.h"

#include "utils.h"

void print_scene(const VehicleType *ego_vehicle,
                 const NeighborVehiclesType *vehicles)
{
    printf("\n\n");
    printf("\t  L   C   R\n");

    size_t left_idx = 0;
    size_t center_idx = 0;
    size_t right_idx = 0;

    float offset_m = 20.0f;

    for (int32_t i = 100; i >= -100; i -= (int32_t)(offset_m))
    {
        const VehicleType *left_vehicle =
            (left_idx >= NUM_VEHICLES_ON_LANE)
                ? NULL
                : &vehicles->vehicles_left_lane[left_idx];
        const VehicleType *center_vehicle =
            (center_idx >= NUM_VEHICLES_ON_LANE)
                ? NULL
                : &vehicles->vehicles_center_lane[center_idx];
        const VehicleType *right_vehicle =
            (right_idx >= NUM_VEHICLES_ON_LANE)
                ? NULL
                : &vehicles->vehicles_right_lane[right_idx];

        char left_string[] = "   ";
        char center_string[] = "   ";
        char right_string[] = "   ";

        const float range_m = (float)(i);

        if ((left_vehicle != NULL) && (range_m >= left_vehicle->distance_m) &&
            (left_vehicle->distance_m > (range_m - offset_m)))
        {
            strncpy(left_string, " V ", 4);
            left_idx++;
        }

        if ((center_vehicle != NULL) &&
            (range_m >= center_vehicle->distance_m) &&
            (center_vehicle->distance_m > (range_m - offset_m)))
        {
            strncpy(center_string, " V ", 4);
            center_idx++;
        }

        if ((right_vehicle != NULL) && (range_m >= right_vehicle->distance_m) &&
            (right_vehicle->distance_m > (range_m - offset_m)))
        {
            strncpy(right_string, " V ", 4);
            right_idx++;
        }

        if (i == 0)
        {
            switch (ego_vehicle->lane)
            {
            case LANE_ASSOCIATION_TYPE_LEFT:
            {
                strncpy(left_string, " E ", 4);
                break;
            }
            case LANE_ASSOCIATION_TYPE_CENTER:
            {
                strncpy(center_string, " E ", 4);
                break;
            }
            case LANE_ASSOCIATION_TYPE_RIGHT:
            {
                strncpy(right_string, " E ", 4);
                break;
            }
            case LANE_ASSOCIATION_TYPE_NONE:
            default:
            {
                break;
            }
            }
        }

        printf("%d\t|%s|%s|%s|\n", i, left_string, center_string, right_string);
    }

    printf("\n");
    printf("Speed: %f\n", ego_vehicle->speed_mps);
    printf("\n");
}

float kph_to_mps(const float kph)
{
    return kph / 3.6f;
}

void init_ego_vehicle(VehicleType *ego_vehicle)
{
    ego_vehicle->id = EGO_VEHICLE_ID;
    ego_vehicle->distance_m = 0.0f;

    ego_vehicle->speed_mps = kph_to_mps(135.0f);
    ego_vehicle->lane = LANE_ASSOCIATION_TYPE_CENTER;
}

void init_vehicle(VehicleType *vehicle,
                  const int32_t id,
                  const float speed_kph,
                  const float distance,
                  const LaneAssociationType lane)
{
    vehicle->id = id;
    vehicle->speed_mps = kph_to_mps(speed_kph);
    vehicle->distance_m = distance;
    vehicle->lane = lane;
}

void init_vehicles(NeighborVehiclesType *vehicles)
{
    init_vehicle(&vehicles->vehicles_left_lane[0],
                 0,
                 130.0f,
                 80.0f,
                 LANE_ASSOCIATION_TYPE_LEFT);
    init_vehicle(&vehicles->vehicles_left_lane[1],
                 1,
                 80.0f,
                 -20.0f,
                 LANE_ASSOCIATION_TYPE_LEFT);
    init_vehicle(&vehicles->vehicles_center_lane[0],
                 2,
                 80.0f,
                 50.0f,
                 LANE_ASSOCIATION_TYPE_CENTER);
    init_vehicle(&vehicles->vehicles_center_lane[1],
                 3,
                 120.0f,
                 -50.0f,
                 LANE_ASSOCIATION_TYPE_CENTER);
    init_vehicle(&vehicles->vehicles_right_lane[0],
                 4,
                 110.0f,
                 30.0f,
                 LANE_ASSOCIATION_TYPE_RIGHT);
    init_vehicle(&vehicles->vehicles_right_lane[1],
                 5,
                 90.0f,
                 -30.0f,
                 LANE_ASSOCIATION_TYPE_RIGHT);
}

void print_vehicle(const VehicleType *vehicle)
{
    printf("ID: %d\n", vehicle->id);
    printf("Speed (m/s): %f\n", vehicle->speed_mps);
    printf("Distance (m): %f\n", vehicle->distance_m);
    printf("Lane: %d\n", vehicle->lane);
}

void print_neighbor_vehicles(const NeighborVehiclesType *vehicles)
{
    print_vehicle(&vehicles->vehicles_left_lane[0]);
    print_vehicle(&vehicles->vehicles_left_lane[1]);
    print_vehicle(&vehicles->vehicles_center_lane[0]);
    print_vehicle(&vehicles->vehicles_center_lane[1]);
    print_vehicle(&vehicles->vehicles_right_lane[0]);
    print_vehicle(&vehicles->vehicles_right_lane[1]);
}
