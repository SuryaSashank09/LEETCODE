int largestAltitude(int* gain, int gainSize) {
    int maxAltitude = 0;  
    int current = 0;     
    
    for (int i = 0; i < gainSize; i++) {
        current += gain[i];            
        if (current > maxAltitude) {   
            maxAltitude = current;
        }
    }
    
    return maxAltitude;
}
