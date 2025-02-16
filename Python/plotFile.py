import matplotlib.pyplot as plt
import numpy as np
import argparse
from parseFile import parseFileAsFloat, parseFileAsComplex

def plotSigReal(data):
    # Plot the data
    plt.plot(data)
    plt.show()
    
# Plot the power spectrum
def plotSigPower(data):
    power = np.abs(data)**2
    plt.plot(power)
    plt.show()
    
def plotSigFFT(data):
    # Compute the FFT
    fft = np.fft.fft(data)
    # Perform FFT shift
    fft = np.fft.fftshift(fft)
    # Get the frequency axis
    t = np.linspace(0, 1, len(data))
    freq = np.fft.fftfreq(len(data), d=t[1] - t[0])
    # Plot the FFT
    plt.plot(freq, np.abs(fft))
    plt.xlabel('Frequency (Hz)')
    plt.ylabel('Magnitude')
    plt.show()

if(__name__ == '__main__'):
    parser = argparse.ArgumentParser()
    parser.add_argument('-f', '--filename', help='File name', type=str)
    parser.add_argument('-t', '--type', help='Data type ("float" or "complex")', type=str, default='float')
    parser.add_argument('-p', '--path', help='Path to the file', type=str, default='../Data/')
    parser.add_argument('-o', '--output', help='Output file name', type=str, default='output.dat')
    parser.add_argument('-g', '--graph', help='Graph type (real, power, fft)', type=str, default='real')
    args = parser.parse_args()
    filename = args.filename
    path = args.path
    type = args.type
    
    data = []
    # Parse the file
    if type == 'float':
        data = parseFileAsFloat(filename, path)
    elif type == 'complex':
        data = parseFileAsComplex(filename, path)
    #plotSigReal(data)
    #plotSigPower(data)
    plotSigFFT(data)

