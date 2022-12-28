"""
Python runner for Python wrapped C++ implementation of rejection sampling.
Uses C++ to run computation and return the result, then use seaborn to make
nicer plots.

To run: make build to build the project then run with python viz.py

Last edited: 12.27.22
"""
import sys

sys.path.append("../build/src/")
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns

sns.set_theme()

from CPPViz import RejectionSample

N = int(1e6)

g = lambda t: np.sin(10 * t) ** 2 * abs(t**3 + 2 * t - 3) if ((t > -1 and t < 0) or (t > 1 / 2 and t < 1)) else 0
rej = RejectionSample()
rej.rejection_sample(g, N, -1, 1, 0, 10)
x = rej.res

sns.histplot(x)
plt.show()
