using namespace std;

long long solution(int weight,int height) {
    long long w = weight;
    long long h = height;
    int gcd, big, small;
    if(w < h) {
        big = h;
        small = w;
    }
    else {
        big = w;
        small = h;
    }
    
    for(int i = small; i > 0; i--) {
        if(w % i == 0 && h % i == 0) {
            gcd = i;
            break;
        }
    }
    
    return w * h - gcd * (w / gcd + h / gcd - 1);
}
