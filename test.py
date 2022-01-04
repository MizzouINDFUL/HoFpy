import numpy as np
import matplotlib.pyplot as plt

import hofpy

A = np.zeros((400, 400), dtype='uint8')
B = np.zeros((400, 400), dtype='uint8')

A[100:150, 100:300] = 255
B[200:300, 200:300] = 255

fig, axs = plt.subplots(1, 2)
axs[0].imshow(A)
axs[1].imshow(B)

axs[0].set_title('Image A')
axs[1].set_title('Image B')

h0 = hofpy.F0Hist(A, B)
h2 = hofpy.F2Hist(A, B)

fig, axs = plt.subplots(2, 1)
plt.subplots_adjust(hspace=0.5)

axs[0].set_title('F0 Histogram')
axs[1].set_title('F2 Histogram')

axs[0].plot(np.linspace(0, 360, len(h0)), h0)
axs[1].plot(np.linspace(0, 360, len(h2)), h2)

plt.show()