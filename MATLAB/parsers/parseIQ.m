function [d] = parseIQ(fname
    %% Parse the file for floating point values, return parsed array
    fid = fopen(fname, "r");
    
    nums = textscan(fid, '%f,%f');

    d = complex{1};
end