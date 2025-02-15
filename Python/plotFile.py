import matplotlib.pyplot as plt
import numpy as np
from parseFile import parseFileAsFloat, parseFileAsComplex

def plotFileReal(filename, path, type='f'):
    # Parse the file
    if type == 'f':
        data = parseFileAsFloat(filename, path)
    elif type == 'c':
        data = parseFileAsComplex(filename, path)
    # Plot the data
    plt.plot(data)
    plt.show()
    


if(__name__ == '__main__'):
    plotFileReal('waveform.dat', '../Data/', 'f')

