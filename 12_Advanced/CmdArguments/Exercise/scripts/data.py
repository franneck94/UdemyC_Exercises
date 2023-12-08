import argparse
import enum
import os
from typing import Dict

import numpy as np

np.random.seed(0)


class LaneAssociation(enum.Enum):
    UNKNOWN = 0
    RIGHT = 1
    CENTER = 2
    LEFT = 3


NUM_VEHICLES = 6
NUM_CYCLES = 1_000
FPS = 25


def get_vehicle_filepath(idx: int, use_case_idx: int = 0) -> str:
    VEHICLE_FILENAME = f"vehicle_{idx}_data.txt"
    DATA_PATH = os.path.join(
        os.path.dirname(os.path.dirname(__file__)), "data", str(use_case_idx),
    )
    if not os.path.exists(DATA_PATH):
        os.mkdir(DATA_PATH)
    VEHICLE_FILEPATH = os.path.join(DATA_PATH, VEHICLE_FILENAME,)
    return VEHICLE_FILEPATH


def get_ego_vehicle_filepath(use_case_idx: int = 0) -> str:
    EGO_FILENAME = "ego_data.txt"
    DATA_PATH = os.path.join(
        os.path.dirname(os.path.dirname(__file__)), "data", str(use_case_idx)
    )
    if not os.path.exists(DATA_PATH):
        os.mkdir(DATA_PATH)
    EGO_VEHICLE_FILEPATH = os.path.join(DATA_PATH, EGO_FILENAME)
    return EGO_VEHICLE_FILEPATH


def kph_to_mps(kph: float) -> float:
    return kph / 3.6


def generate_vehicle_data(id_: int) -> dict:
    if id_ < 2:
        lane_data = int(LaneAssociation.LEFT.value)
        start_speed = np.random.uniform(110, 130)
    elif id_ < 4:
        lane_data = int(LaneAssociation.CENTER.value)
        start_speed = np.random.uniform(100, 110)
    else:
        lane_data = int(LaneAssociation.RIGHT.value)
        start_speed = np.random.uniform(80, 100)

    if id_ == 0 or id_ == 2 or id_ == 4:
        distance = np.random.uniform(20, 80)

    elif id_ == 1 or id_ == 3 or id_ == 5:
        distance = np.random.uniform(-80, -20)

    start_speed = kph_to_mps(start_speed)
    speed_data = [start_speed for _ in range(NUM_CYCLES)]
    for it in range(1, NUM_CYCLES):
        speed_data[it] = speed_data[it - 1] + np.random.normal(
            loc=0.0, scale=0.5
        )

    data_dict = {
        "Lane": lane_data,
        "Distance": distance,
        "Speed": speed_data,
    }
    return data_dict


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--num_use_cases", type=int, default=1)
    args = parser.parse_args()
    num_use_cases = args.num_use_cases

    for use_case_idx in range(num_use_cases):
        vehicle_datas: Dict[int, dict] = {idx: {} for idx in range(NUM_VEHICLES)}

        for i in range(NUM_VEHICLES):
            data = generate_vehicle_data(i)
            vehicle_datas[i] = data

        for i in range(NUM_VEHICLES):
            with open(get_vehicle_filepath(i, use_case_idx), "w") as file_object:
                file_object.write("Lane: " + str(vehicle_datas[i]["Lane"]) + "\n")
                file_object.write(
                    "Distance: " + str(vehicle_datas[i]["Distance"]) + "\n"
                )
                for idx, speed_val in enumerate(vehicle_datas[i]["Speed"]):
                    file_object.write(f"Speed {idx}: " + str(speed_val) + "\n")

        ego_vehicle_data = {
            "Lane": int(LaneAssociation.CENTER.value),
            "Speed": kph_to_mps(np.random.uniform(110, 130)),
        }

        with open(get_ego_vehicle_filepath(use_case_idx), "w") as file_object:
            file_object.write("Lane: " + str(ego_vehicle_data["Lane"]) + "\n")
            file_object.write("Speed: " + str(ego_vehicle_data["Speed"]) + "\n")

    return 0


if __name__ == "__main__":
    main()
