#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import resample_poly

# Prepare the test signal (just sine wawe)
fs = 10  # Initial frequency, Hz
t = np.linspace(0, 1, fs, endpoint=False)
x = np.sin(2 * np.pi * 1 * t)  # 1 Hz sine wave

# Resempling: change the sampling rate from fs to (3/2)*fs
L = 5  # Interpolation (Increase the sampling rate up to 5 times)
M = 3  # Decimation (Decrease the sampling rate down to 3 times)
y = resample_poly(x, up=L, down=M)

# Plotting
t_resampled = np.linspace(0, 1, len(y), endpoint=False)

plt.figure(figsize=(12, 5))
plt.plot(t, x, label="Original signal", alpha=0.6)
plt.plot(t_resampled, y, label="Resampled signal (3/2)", alpha=0.8)
plt.legend()
plt.title("Rational Resampling Using Polyphase FIR Filter")
plt.xlabel("Time [s]")
plt.grid(True)
plt.tight_layout()
plt.show()

# The block diagram of the rational resampling process is as follows:
# Input Signal (x[n])
#       │
#       ▼
# Zero Insertion (Up-sampling by L)
#       │
#       ▼
# FIR Low-Pass Filter (Polyphase structure)
#       │
#       ▼
# Down-sampling by M
#       │
#       ▼
# Output Signal (y[n])
