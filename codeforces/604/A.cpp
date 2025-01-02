#include <iostream>

double Result(int m_ex, int x_ex, int w_ex){
    double res = std::max<double>(0.3*x_ex, ((1-m_ex/(double)250)*x_ex-50*w_ex));
    //printf("1: %f , 2: (1-m/250 = %f) %f -> res: %f\n", 0.3f*x_ex, (1-(m_ex/250.0f)), (double)((1-(m_ex/250.0f))*x_ex-50*w_ex), res);
    return res;
}

int main(){
    int exMax[5] = {500, 1000, 1500, 2000, 2500};
    int m[5], w[5];
    int hs, hf;
    for (int i = 0; i < 5; i++) std::cin >> m[i];
    for (int i = 0; i < 5; i++) std::cin >> w[i];
    std::cin >> hs >> hf;
    double s = 0;
    for (int i = 0; i < 5; i++){
        double r = Result(m[i], exMax[i], w[i]);
        //printf("_%f\n", r);
        s += r;
    }
    //printf("-_%d\n", (int)s);
    s += 100*hs;
    s -= 50*hf;
    printf("%d\n", (int)s);
    return 0;
}