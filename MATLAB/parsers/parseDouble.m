function [d] = parseDouble(fname)

    %% Parse the file for floating point values, return parsed array
    fid = fopen(fname, "r");
    
    nums = textscan(fid, '%f');

    fclose(fid);

    d = nums{1};
end