classdef waveform
    %WAVEFORM Class to generate different waveforms
    
    properties
        % Waveform type
        type = 'cw';
        % Waveform sampling frequency
        fs = 10e9;
        % Waveform number of samples
        s = 4000;
        % Waveform frequency
        f = 40e6;
    end
    
    methods
        function obj = waveform(inputArg1,inputArg2)
            %WAVEFORM Construct an instance of this class
            %   Detailed explanation goes here
            obj.Property1 = inputArg1 + inputArg2;
        end
        
        function outputArg = method1(obj,inputArg)
            %METHOD1 Summary of this method goes here
            %   Detailed explanation goes here
            outputArg = obj.Property1 + inputArg;
        end
    end
end

