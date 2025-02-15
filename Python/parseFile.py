
def parseFileAsFloat(filename, path):
    try:
        with open(path + filename, 'r') as f:
            return [float(line) for line in f]
    except FileNotFoundError:
        print(f"Error opening file: {filename}")
        return []
    
def parseFileAsComplex(filename, path):
    try:
        with open(path + filename, 'r') as f:
            return [complex(float(line.split(',')[0]), float(line.split(',')[1])) for line in f]
    except FileNotFoundError:
        print(f"Error opening file: {filename}")
        return []
    