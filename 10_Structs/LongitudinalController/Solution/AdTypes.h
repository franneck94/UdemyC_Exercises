#ifndef AD_TYPES_H
#define AD_TYPES_H

#include <stdint.h>

typedef enum
{
    LANE_ASSOCIATION_TYPE_NONE,
    LANE_ASSOCIATION_TYPE_LEFT,
    LANE_ASSOCIATION_TYPE_CENTER,
    LANE_ASSOCIATION_TYPE_RIGHT,
} LaneAssociationType;

typedef enum
{
    LONGITUDINAL_ACTION_NONE,
    LONGITUDINAL_ACTION_ACCELERATE = 'w',
    LONGITUDINAL_ACTION_DECELERATE = 's',
} LongitudinalAction;

typedef enum
{
    LATERAL_ACTION_NONE,
    LATERAL_ACTION_LEFT = 'a',
    LATERAL_ACTION_RIGHT = 'd',
} LateralAction;

typedef struct
{
    int32_t id;
    LaneAssociationType lane;
    float speed_mps;
    float distance_m;
} VehicleType;

typedef struct
{
    VehicleType vehicles_left_lane[2];
    VehicleType vehicles_center_lane[2];
    VehicleType vehicles_right_lane[2];
} NeighborVehiclesType;

#endif
