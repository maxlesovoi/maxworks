float pow(float a, int b){
    float temp = 1;
    for (int i = 0; i < b; i++){
        temp *= a;
    }
    return temp;
}