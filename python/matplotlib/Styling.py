

import numpy as np
import matplotlib.pyplot as plt

with plt.style.context(('dark_background')):
    plt.plot(np.sin(np.linspace(0, 2 * np.pi)), 'r-o')

# Some plotting code with the default style

plt.show()


