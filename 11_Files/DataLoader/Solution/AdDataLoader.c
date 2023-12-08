#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "AdConstants.h"
#include "AdDataLoader.h"
#include "AdFunctions.h"
#include "AdTypes.h"

#include "utils.h"

static VehicleType EGO_VEHICLE_DATA;
static VehicleType VEHICLE_DATA[NUM_VEHICLES][NUM_CYCLES];

void preload_ego_vehicle_data(const char datapath[128])
{
    char filepath[256] = {'\0'};
    strncpy(filepath, datapath, 128);
    char filename[128] = "ego_data.txt";
    strncat(filepath, filename, 128);

    FILE *fp = fopen(filepath, "r");

    if (fp == NULL)
    {
        return;
    }

    int line_size = 256;
    char line[256] = {'\0'};

    fgets(line, line_size, fp);
    size_t lane_str_len = strlen("Lane: ");
    int lane_idx = atoi(line + lane_str_len);

    fgets(line, line_size, fp);
    size_t speed_str_len = strlen("Speed: ");
    float speed_mps = (float)atof(line + speed_str_len);

    EGO_VEHICLE_DATA.speed_mps = speed_mps;
    EGO_VEHICLE_DATA.distance_m = 0.0f;
    EGO_VEHICLE_DATA.lane = lane_idx;
    EGO_VEHICLE_DATA.id = EGO_VEHICLE_ID;

    fclose(fp);
}

void preload_vehicle_data(const char datapath[128])
{
    for (int vehicle_idx = 0; vehicle_idx < NUM_VEHICLES; vehicle_idx++)
    {
        char filepath[256] = {'\0'};
        strncpy(filepath, datapath, 128);
        char filename[128] = {'\0'};
        snprintf(filename, 128, "vehicle_%d_data.txt", vehicle_idx);
        strncat(filepath, filename, 128);

        FILE *fp = fopen(filepath, "r");

        if (fp == NULL)
        {
            return;
        }

        int line_size = 256;
        char line[256] = {'\0'};

        fgets(line, line_size, fp);
        size_t lane_str_len = strlen("Lane: ");
        int lane_idx = atoi(line + lane_str_len);

        fgets(line, line_size, fp);
        size_t distance_str_len = strlen("Distance: ");
        float distance_m = (float)atof(line + distance_str_len);

        int idx = 0;
        while (fgets(line, line_size, fp) != NULL)
        {
            char speed_str[128] = {'\0'};
            snprintf(speed_str, 128, "Speed %d: ", idx);
            size_t speed_str_len = strlen(speed_str);

            float speed_mps = (float)atof(line + speed_str_len);

            VEHICLE_DATA[vehicle_idx][idx].id = vehicle_idx;
            VEHICLE_DATA[vehicle_idx][idx].speed_mps = speed_mps;
            VEHICLE_DATA[vehicle_idx][idx].distance_m = distance_m;
            VEHICLE_DATA[vehicle_idx][idx].lane = lane_idx;

            idx++;
        }

        fclose(fp);
    }
}

void init_ego_vehicle(VehicleType *ego_vehicle)
{
}

void init_vehicle(VehicleType *vehicle, const int32_t id, const uint32_t cycle)
{
}

void init_vehicles(NeighborVehiclesType *vehicles)
{
}

void load_cycle(NeighborVehiclesType *vehicles, const uint32_t cycle)
{
}
