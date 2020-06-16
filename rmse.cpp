#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

typedef struct{
    int x;
    int y;
}match;

typedef vector<match> matcher;

float rmse(matcher descritores1, matcher descritores2){
    float erro;
    for(int i = 0; i < descritores1.size(); i++){
        erro += pow(descritores1[i].x - pow(descritores2[i].x,20),2) + pow(descritores1[i].y - pow(descritores2[i].y,20),2) ;
    }

    erro = 1/20 * erro;

    erro = sqrt(erro);

    return erro;
}

int main(){

    srand(time(NULL));

    int altura, largura; 
    matcher descritores1;
    matcher descritores2;
    match keypoint;

    cout << "Digite a altura da imagem: " << endl;
    cin >> altura;
    cout << "Digite a largura da imagem: " << endl;
    cin >> largura;

    for(int i = 0; i < 20; i++){
        keypoint.x = rand() % altura + 1;
        keypoint.y = rand() % largura + 1;
        descritores1.push_back(keypoint);

        keypoint.x = rand() % altura + 1;
        keypoint.y = rand() % largura + 1;
        descritores2.push_back(keypoint);
    }

    float erro = rmse(descritores1, descritores2);

    cout << "O erro encontrado é : " << erro << endl;

    return 0;
}