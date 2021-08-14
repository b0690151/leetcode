    if( n <= 2 ) 
        return 0;
    
    int count = n/2;
    bool isPrimes[ n ];
    
    memset( isPrimes, 1, sizeof(isPrimes) );
    for( int i=3; i*i<n; i+=2 ){
        if( isPrimes[i] ){
            for( int j=3; i*j<n; j+=2 ){
                if( isPrimes[i*j] ){
                    isPrimes[i*j] = false;
                    count -= 1;
                }
            }
        }
    }
    
    return count;