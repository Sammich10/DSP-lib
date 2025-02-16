#include <complex>
#include <vector>

/**
 * \brief Parse a file and return its contents as a vector of floating point values or complex IQ values
 * 
 * @param filename Name of the file to parse
 * @param path Path to the file
 * @param type Type of the file, either "f" for floating point values or "c" for complex IQ values
 * 
 * @return Vector of floating point values or complex IQ values
 */
std::vector<double> parseFile_f(std::string filename, std::string path)
{
    FILE *fp = fopen((path + filename).c_str(), "r");
    if(fp == NULL)
    {
        printf("Error opening file: %s\n", filename.c_str());
        return std::vector<double>();
    }

    std::vector<double> data;
    // Parse the file as floating point values
    double value;
    while (fscanf(fp, "%lf", &value) != EOF)
    {
        data.push_back(value);
    }
    
    
    fclose(fp);
    
    return data;
}

/**
 * \brief Parse a file and return its contents as a vector of complex IQ values
 * 
 * @param filename Name of the file to parse
 * @param path Path to the file
 * 
 * @return Vector of complex IQ values
 */
std::vector<std::complex<double>> parseFile_c(std::string filename, std::string path)
{
    FILE *fp = fopen((path + filename).c_str(), "r");
    if(fp == NULL)
    {
        printf("Error opening file: %s\n", filename.c_str());
        return std::vector<std::complex<double>>();
    }

    std::vector<std::complex<double>> data;
    // Parse the file as complex IQ values
    std::complex<double> value;
    double real, imag;
    while (fscanf(fp, "%lf,%lf", &real, &imag) != EOF)
    {
        value.real(real);
        value.imag(imag);
        data.push_back(value);
    }
    
    fclose(fp);
    
    return data;
}

/**
 * \brief Write a vector of floating point values to a file
 * 
 * @param data Vector of double values to write to the file
 * @param filename Name of the file to write to
 * @param path Path to the file
 * 
 * @return void
 */
void exportToFile_f(std::vector<double> data, std::string filename, std::string path)
{
    FILE *fp = fopen((path + filename).c_str(), "w");
    if(fp == NULL)
    {
        printf("Error opening file: %s\n", filename.c_str());
        return;
    }
    
    // Write the data to the file as floating point values
    for (double value : data)
    {
        fprintf(fp, "%lf\n", value);
    }
    
    fclose(fp);
}

/**
 * \brief Write a vector of complex IQ values to a file
 * 
 * @param data Vector of complex<double> values to write to the file
 * @param filename Name of the file to write to
 * @param path Path to the file
 * 
 * @return void
 */
void exportToFile_c(std::vector<std::complex<double>> data, std::string filename, std::string path)
{
    FILE *fp = fopen((path + filename).c_str(), "w");
    if(fp == NULL)
    {
        printf("Error opening file: %s\n", filename.c_str());
        return;
    }
    
    // Write the data to the file as complex IQ values
    for (std::complex<double> value : data)
    {
        fprintf(fp, "%lf,%lf\n", value.real(), value.imag());
    }
    
    fclose(fp);
}