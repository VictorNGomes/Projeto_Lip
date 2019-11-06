#include<iostream>
#include<cstring>
#include<fstream>

const int SMAX = 50;
const int MAX_P = 3;
const int MAX = 1536;
using namespace std;

struct RGB{
    int R[MAX][MAX];
    int G[MAX][MAX];
    int B[MAX][MAX];
};
struct Img{

    char s[SMAX];
    int Altura;
    int Largura;
    int Dim;
    RGB Cor;

};


void abre_imagem(char nome_arquivo[], Img& img);

void salva_arquivo(char novo_arquivo[], Img img);

void converte_para_cinza(Img img_in, Img& img_out);

int main(){

char nome_arquivo[SMAX];
char novo_arquivo[SMAX];
Img img;
Img img_out;
cout << "Digite o nome do arquivo" << endl;
cin.getline(nome_arquivo,SMAX);


abre_imagem(nome_arquivo, img);

cout << "Largura: " << img.Largura << " Altura: " << img.Altura << endl;

cout << "Entre com o nome do novo arquivo" << endl;
cin.getline(novo_arquivo, SMAX);





salva_arquivo(novo_arquivo, img);






return 0;
}




void abre_imagem(char nome_arquivo[], Img& img){

fstream arq;

char tipo[SMAX];
int MAXP;
arq.open(nome_arquivo);

    if(arq.is_open()){

        arq.getline(tipo,SMAX);
        arq >> img.Largura;
        arq >> img.Altura;
        arq >> MAXP;


        for(int i = 0; i<(3*(img.Largura)); i++){
                for(int j = 0; j <img.Altura; j+=3){
                arq >> img.Cor.R[i][j] >> img.Cor.G[i][j+1] >> img.Cor.B[i][j+2];



                }
        }

       cout << "Arquivo Aberto com sucesso" << endl;

    }else{
        cout << "Erro" << endl;

        }



}
void salva_arquivo(char novo_arquivo[], Img img){
ofstream arq ;

char tipo[] = "P3";
int MAXP = 255;
arq.open(novo_arquivo);

    if(arq.is_open()){
        cout << "Novo arquivo criado" << endl;


        arq << tipo << endl;
        arq << img.Largura << " ";
        arq << img.Altura << endl;
        arq << MAXP << endl;



        for(int i = 0; i<(3*(img.Largura)); i++){
                for(int j = 0; j <img.Altura; j+=3){
                arq << img.Cor.R[i][j] << " " << img.Cor.G[i][j+1]<< " " << img.Cor.B[i][j+2] << " ";

                }
                cout << endl;
        }
        cout << "DADOS INSERIDOS COM SUCESSO" << endl;

    }else{
        cout << "eRRO" << endl;
    }


arq.close();

}





void converte_para_cinza(Img img_in, Img& img_out){

    fstream arq;

char tipo[SMAX];
int MAXP;


int media = 0;

        arq.getline(tipo,SMAX);
        arq >> img_in.Largura;
        arq >> img_in.Altura;
        arq >> MAXP;


        for(int i = 0; i<(3*(img_in.Largura)); i++){
                for(int j = 0; j <img_in.Altura; j+=3){
                media+=img_in.Cor.R[i][j];
                media+=img_in.Cor.G[i][j+1];
                media+=img_in.Cor.B[i][j+2];

                media/=3;

                img_out.Cor.R[i][j] = media;
                img_out.Cor.R[i][j+1] = media;
                img_out.Cor.R[i][j+2] = media;




                media = 0;
                }


        }


}


