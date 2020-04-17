bool inArray(int array[], int n, int len){
    for(int i = 0; i < len; i++){
        if(n == array[i]) return true;
    }  
    return false;
}

int findindex(int array[], int n, int len){
    for(int i = 0; i < len; i++){
        if(n == array[i]) return i;
    }  
    return -1;
}

int numberOfBoomerangs(int** points, int pointsSize, int* pointsColSize){
    int x, y, distance, result = 0, index;
    *pointsColSize = 500;
    
    for(int i = 0; i < pointsSize; i++){
        int** dis_map = malloc(*pointsColSize * sizeof(int*));
        int store[*pointsColSize];
        index = 0;
        for(int j = 0; j < pointsSize; j++){
            if(i != j){             
                x = points[i][0] - points[j][0];
                y = points[i][1] - points[j][1];
                distance = x * x + y * y; 
                if(inArray(store, distance, index)){
                    dis_map[findindex(store, distance, index)][1] ++;
                } else {
                    dis_map[index] = calloc(2, sizeof(int));
                    dis_map[index][1] ++;
                    store[index] = distance;
                    index ++;
                }
            }
        }        
        for(int k = 0; k < index; k++)
            result += dis_map[k][1] * (dis_map[k][1] - 1);
    }
    
    return result;
}
