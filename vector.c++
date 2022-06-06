#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>
using std::sort;

using namespace std;


class Vetor{

    vector<int>::iterator it;

    public:

        int mostraVetor(vector<int>veto){
            for(auto x:veto){
                cout << x << endl;
            }
        }

        void inserirInicio(vector<int>veto,int x){
            it=veto.begin();
            veto.insert(it,x);
            mostraVetor(veto); 
        }

        void inserindo(int vet[],int tam){
            int i;
            int n;
            int aux = 0;

             while(aux < tam){
                for (i = 0; i < tam; i++) {
                    cout << "Insira um número:";
                    cin >> n;
                    vet[i] = n;
                    aux++;
            }      
            for(i = 0; i < tam; i++){
                cout << vet[i] << " ";
            }
        }
        }

        void removerFinal(vector<int>veto){
            veto.pop_back();
            mostraVetor(veto);
        }

        int tamanho(vector<int> veto){
            cout << veto.size();
        }

        string conjuntoVazio(vector<int> veto){
            if(veto.empty()){
                return "Conjunto vazio.";
            }
            else{
                return "Não é um conjunto vazio.";
            }
        }

        int maiorElemento(vector<int> veto){
            int maior = 0;

            for(auto y: veto){
                if (y > maior){
                    maior = y;
                }
            }
            return maior;
        }

        int menorElemento(vector<int> veto){
            int cont = 0;
            int menor;

            for(auto y: veto){
                if (cont == 0){
                    menor = y;
                    cont++;
                } else{
                    if (y < menor){
                        menor = y;
                    }
                }
            }
            return menor;
        }

        bool pesquisa (vector<int> veto,int valor){
            for (int i = 0; i < sizeof(veto);i++){
                    if(veto[i] == valor){
                        return true;
                    }     
                }
            return false;
        }

        string pertenceConjunto(vector<int> veto,int valor){
            for(auto y: veto){
            if(pesquisa(veto,valor)){
                    return "Pertence ao conjunto";
                } 
            }
            return "Não pertence";
        }
        
        int interseccao(vector<int> veto,vector<int> veto2){
            vector<int>veto3={};

            for (int i = 0; i < sizeof(veto);i++){
                for (int j = 0; j < sizeof(veto2);j++){
                    if(veto[i] == veto2[j]){
                        veto3.push_back(veto[i]);
                    }
                }
            }
            for(auto y: veto3){
            cout << y << endl;
            }
        }

        string conjuntosIguais (int vet1[],int len1, int vet2[], int len2){
            int cont = 0;

            if(len1 == len2){
                for(int i = 0; i < len1; i++){
                    for (int j = 0; j < len2; j++){
                        if(vet1[i] == vet2[j]){
                            cont++;
                        }
                    }
                if(cont == len1){
                    return "São conjuntos iguais!";
                }
                }
            }else return "Não são conjuntos iguais!";
        }


        void uniao(int* a, int n, int* b, int m){
            map<int, int> mp;
        
            for (int i = 0; i < n; i++)
                mp.insert({ a[i], i });
        
            for (int i = 0; i < m; i++)
                mp.insert({ b[i], i });

            for (auto itr = mp.begin(); itr != mp.end(); itr++)
                cout << itr->first << " "; 
        }

        int diferenca(int vet1[], int vet2[], int t1,int t2){
            
            int i, j, k;
            int vet3[t1];
            int n = 0;

            for(i = 0; i < t1; i++){
                for(j = 0; j < t1; j++){
                    if(vet1[i]==vet2[j])
                        break;
                }
                if(j == t1){
                    for(k = 0;k < n; k++){
                        if(vet1[i] == vet3[k])
                            break;
                    }
                    if(k == n)
                        vet3[n++] = vet1[i];
                }
            }
            for(k = 0; k < n; k++)
            {
                printf("%i\n", vet3[k]);
            }
            return 0;
        }

    
  
};

int main(){

    Vetor veto;

    int num;
    int tam;
    int i;

    vector<int>v1 = {1,2,3};
    vector<int>v2 = {1,2,5};

    cout << "INSERINDO NO VETOR:\n";
    cout << "Digite o tamanho:";
    cin >> tam;
    int v3[tam];
    veto.inserindo(v3,tam);
    cout << endl;
    
    cout << "INSERIR:\n";
    cout << "Digite um número para inserir no início:";
    cin >> num;
    veto.inserirInicio(v1,num);
   
    cout << endl;
    cout << "REMOVER:\n";
    veto.removerFinal(v1);
    cout << endl;

    cout << "TAMANHO DO VETOR:\n ";
    veto.tamanho(v1);
    cout << endl;

    cout << "CONJUNTO VAZIO:\n ";
    cout << veto.conjuntoVazio(v1);
    cout << endl;

    cout << "MAIOR ELEMENTO:\n ";
    cout << veto.maiorElemento(v1);
    cout << endl;
    cout << "MENOR ELEMENTO:\n ";

    cout << veto.menorElemento(v1);
    cout << endl;

    cout << "PESQUISA:\n ";
    cout << "Digite um número para encontrar:";
    cin >> num;
    cout << veto.pesquisa(v1,num);
    cout << endl;

    cout << "PERTENCE/NÃO PERTENCE\n";
    cout << "Digite um número:";
    cin >> num;
    cout << veto.pertenceConjunto(v1,num);
    cout << endl;

    cout << "INTERSECÇÃO\n";
    cout << veto.interseccao(v1,v2);
    cout << endl;
    
    int vetor1[]={1,2,5};
    int len1 = sizeof(vetor1)/sizeof(vetor1[0]);
    int vetor2[]={1,2,3,1};
    int len2 = sizeof(vetor2)/sizeof(vetor2[0]);

    cout << "TESTAR SE SÃO IGUAIS\n";
    cout << veto.conjuntosIguais(vetor1,len1,vetor2,len2);
    cout << endl;

    cout << "DIFERENÇA:\n";
    veto.diferenca(vetor1,vetor2,3,4); 
    cout << endl; 
 
    cout << "UNIÃO\n";
    veto.uniao(vetor1, 3, vetor2, 4);
    cout << endl;



}

