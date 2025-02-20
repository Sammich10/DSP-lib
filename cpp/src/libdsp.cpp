#include "libdsp.h"

std::vector<complex_t> calcSigDFT_f(
    const std::vector<double>& signal,
    const size_t N
)
{
    // Initialize the DFT
    std::vector<complex_t> dft(N, {0.0, 0.0});

    // Iterate through each frequency bin
    for(size_t f = 0; f < N; ++f)
    {
        // Iterate through each sample
        for(size_t s = 0; s < signal.size(); ++s)
        {
            // Compute the real and imaginary parts of the DFT
            double theta = 2.0 * M_PI * (double)f * (double)s / (double)N;
            dft[f].real(dft[f].re + signal[s] * std::cos(theta));
            dft[f].imag(dft[f].im - signal[s] * std::sin(theta));
        }
    }

    return dft;
}

std::vector<double> calcSigIDFT_f(
    const std::vector<complex_t>& dft,
    const size_t N
)
{
    std::vector<double> idft(N, 0.0);

    for(size_t f = 0; f < N; ++f)
    {
        idft[f] = 0.0;
        for(size_t s = 0; s < N; ++s)
        {
            double theta = 2.0 * M_PI * (double)f * (double)s / (double)N;
            idft[f] = idft[f] + dft[s].re * std::cos(theta) - dft[s].im * std::sin(theta);
        }
        idft[f] = idft[f] / (double)N;
    }

    return idft;
}

std::vector<complex_t> calcSigDFT
(
    const std::vector<complex_t>& signal
)
{
    std::vector<complex_t> dft(signal.size(), {0.0, 0.0});
    for(size_t f = 0; f < signal.size(); ++f)
    {
        complex_t sum = {0.0, 0.0};
        for(size_t s = 0; s < signal.size(); ++s)
        {
            double theta = 2.0 * M_PI * (double)f * (double)s / (double)signal.size();
            double cos_theta = std::cos(theta);
            double sin_theta = std::sin(theta);
            sum += signal[s] * complex_t(cos_theta, sin_theta);
        }
        dft[f] = sum;
    }
    return dft;
}

std::vector<double> calcDFTMag
(
    const std::vector<complex_t>& dft
)
{
    std::vector<double> mag(dft.size(), 0.0);
    for(size_t f = 0; f < dft.size(); ++f)
    {
        mag[f] = std::sqrt(dft[f].re * dft[f].re + dft[f].im * dft[f].im);
    }
    return mag;
}
