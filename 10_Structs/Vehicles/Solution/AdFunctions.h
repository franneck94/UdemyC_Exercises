#ifndef AD_FUNCTIONS_H
#define AD_FUNCTIONS_H

#include <stdint.h>

#include "AdTypes.h"

float kph_to_mps(float kph);

void init_vehicle(VehicleType *vehicle,
                  int32_t id,
                  float speed_kph,
                  float distance,
                  LaneAssociationType lane);

void init_ego_vehicle(VehicleType *ego_vehicle);

void init_vehicles(NeighborVehiclesType *vehicles);

void print_vehicle(const VehicleType *vehicle);

void print_neighbor_vehicles(const NeighborVehiclesType *vehicles);

void print_scene(float speed_mps, uint32_t lane_idx);

void get_user_input(float *speed_mps, uint32_t *lane_idx);

void handle_lateral_user_input(uint32_t *lane_idx, char lateral_action);

void handle_longitudinal_user_input(float *speed_mps, char longitudinal_action);

#endif
