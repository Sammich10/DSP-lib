function [iq] = generateSignal(samples, fs, freq)

    t = (0:samples-1)/fs;
    iq = complex(sin(2*pi*freq*t), cos(2*pi*freq*t));
end

