#include "dsp.h"
#include "waveforms.cpp"
#include "fileparseing.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <complex>

int main() {
    std::string dataPath = "../Data/";
    std::string waveformFile = "waveform.dat";
    std::string impulseResponseFile = "impulse_response.dat";
    std::string floatType = "f";

    std::vector<double> waveform = parseFile_f(waveformFile, dataPath);
    std::vector<double> impulseResponse = parseFile_f(impulseResponseFile, dataPath);

    std::vector<double> convolvedSignal = convolveFull(waveform, impulseResponse);

    exportToFile_f(convolvedSignal, "convolved_signal.dat", dataPath);

    return 0;
}