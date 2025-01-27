function [d] = parseIQ(fname, path)
    %% Default path is the current working directory
    if ~exist('path', 'var') || nargin < 2
        path = pwd();
    end
    % Append slash
    if ~endsWith(path, '\')
        path = path + "\";
    end

    %% Parse the file for floating point values, return parsed array
    fid = fopen(path + fname, "r");
    
    nums = textscan(fid, '%f,%f');

    d = nums{1};
end