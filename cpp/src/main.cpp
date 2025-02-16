#include "libdsp.h"
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

    std::vector<std::complex<double>> dft = calcSigDFT_f(waveform, waveform.size());

    std::vector<double> dft_real(dft.size(), 0.0);
    std::vector<double> dft_imag(dft.size(), 0.0);

    for (size_t i = 0; i < dft.size(); i++) {
        dft_real[i] = dft[i].real();
        dft_imag[i] = dft[i].imag();
    }

    exportToFile_f(dft_real, "dft_r.dat", dataPath);
    exportToFile_f(dft_imag, "dft_i.dat", dataPath);

    std::vector<double> synth_waveform = calcSigIDFT_f(dft, dft.size());

    exportToFile_f(synth_waveform, "synth_waveform.dat", dataPath);

    std::vector<double> dft_mag = calcDFTMag_f(dft);

    exportToFile_f(dft_mag, "dft_mag.dat", dataPath);

    return 0;
}