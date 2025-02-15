function plotSigReal(filename, type)

% Parse file as complex numbers
if type == 'c'
    figure();
    iq = parseIQ(filename);
    plot(1:length(iq), iq);
% Parse file as floating point values
elseif type == 'f'
    figure();
    iq = parseDouble(filename);
    plot(1:length(iq), real(iq));
end




end

