import sys

import numpy as np


def main() -> int:
    M = np.array([[1, 2, 3], [4, 5, 6]], dtype=np.float32)
    v = np.array([1, 2, 3], dtype=np.float32)
    print("M: ", M)
    print("v: ", v)

    print("norm v: ", np.linalg.norm(v))
    print("M_T = ", np.transpose(M))
    print("M * v = ", np.dot(M, v))

    return 0


if __name__ == "__main__":
    sys.exit(main())
