#include "libdsp.h"

std::vector<std::complex<double>> calcSigDFT_f(
    const std::vector<double>& signal,
    const size_t N
)
{
    // Initialize the DFT
    std::vector<std::complex<double>> dft(N, 0.0);

    // Iterate through each frequency bin
    for(size_t f = 0; f < N; ++f)
    {
        // Iterate through each sample
        for(size_t s = 0; s < signal.size(); ++s)
        {
            // Compute the real and imaginary parts of the DFT
            double theta = 2.0 * PI * (double)f * (double)s / (double)N;
            dft[f].real(dft[f].real() + signal[s] * std::cos(theta));
            dft[f].imag(dft[f].imag() - signal[s] * std::sin(theta));
        }
    }

    return dft;
}

std::vector<double> calcSigIDFT_f(
    const std::vector<std::complex<double>>& dft,
    const size_t N
)
{
    std::vector<double> idft(N, 0.0);

    for(size_t f = 0; f < N; ++f)
    {
        idft[f] = 0.0;
        for(size_t s = 0; s < N; ++s)
        {
            double theta = 2.0 * PI * (double)f * (double)s / (double)N;
            idft[f] = idft[f] + dft[s].real() * std::cos(theta) - dft[s].imag() * std::sin(theta);
        }
        idft[f] = idft[f] / (double)N;
    }

    return idft;
}

std::vector<double> calcDFTMag
(
    const std::vector<std::complex<double>>& dft
)
{
    std::vector<double> mag(dft.size(), 0.0);
    for(size_t f = 0; f < dft.size(); ++f)
    {
        mag[f] = std::sqrt(dft[f].real() * dft[f].real() + dft[f].imag() * dft[f].imag());
    }
    return mag;
}