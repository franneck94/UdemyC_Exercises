#ifndef AD_FUNCTIONS_H
#define AD_FUNCTIONS_H

#include <stdbool.h>
#include <stdint.h>

#include "AdTypes.h"

float kph_to_mps(const float kph);

float mps_to_kph(const float mps);

void decrease_speed(VehicleType *ego_vehicle);

void init_vehicle(VehicleType *vehicle,
                  const int32_t id,
                  const float speed_kph,
                  const float distance,
                  const LaneAssociationType lane);

void init_ego_vehicle(VehicleType *ego_vehicle);

void init_vehicles(NeighborVehiclesType *vehicles);

void print_vehicle(const VehicleType *vehicle);

void print_neighbor_vehicles(const NeighborVehiclesType *vehicles);

void print_scene(const VehicleType *ego_vehicle, const NeighborVehiclesType *vehicles);

void compute_future_distance(VehicleType *vehicle, const float ego_driven_distance, const float seconds);

void compute_future_state(const VehicleType *ego_vehicle,
                          NeighborVehiclesType *vehicles,
                          const float seconds);

const VehicleType *get_vehicle_array(const LaneAssociationType ego_lane,
                                     const NeighborVehiclesType *vehicles);

void longitudinal_control(const VehicleType *front_vehicle, VehicleType *ego_vehicle);

LaneAssociationType get_lane_change_request(const VehicleType *ego_vehicle,
                                            const NeighborVehiclesType *vehicles);

bool lateral_control(const LaneAssociationType lane_change_request, VehicleType *ego_vehicle);

#endif
