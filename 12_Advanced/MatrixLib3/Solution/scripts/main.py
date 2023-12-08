import sys

import numpy as np


def main() -> int:
    a = np.array([[1, 2, ], [3, 4, ]], dtype=np.float32)
    print(a)

    print("np.min(a, axis=0): ", np.min(a, axis=0))
    print("np.max(a, axis=0): ", np.max(a, axis=0))

    print("np.min(a, axis=1): ", np.min(a, axis=1))
    print("np.max(a, axis=1): ", np.max(a, axis=1))

    print("np.mean(a, axis=0): ", np.mean(a, axis=0))
    print("np.mean(a, axis=1): ", np.mean(a, axis=1))

    return 0


if __name__ == "__main__":
    sys.exit(main())
