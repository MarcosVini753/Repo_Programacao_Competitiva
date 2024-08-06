#include <bits/stdc++.h>
using namespace std;
bool compara(int& x, int& y){
    // vdd se x deve estar antes de y
    return x < y;} 
//https://cplusplus.com/reference/stl/
int main(){
    vector<int> vec(10, 2); // tamanho e valor padrao 
    vec.push_back(3); // insere no final
    vec.pop_back(); // remove do final 
    sort(vec.rbegin(), vec.rend());// decrescente
    vec.empty(); // retorna vdd se vazio

    stack<int> st; // pilha
    st.push(3); // insere
    st.top(); // retorna o topo
    st.pop(); // remove o topo

    queue<int> qu; // fila
    qu.push(3); // poe no final
    qu.front(); // retorna o inicio
    qu.pop(); // remove o inicio
    qu.back(); // retorna o ultimo

    priority_queue<int> pq; // fila de prioridade (maior no inicio)
    pq.push(3); // poe na fila
    pq.top(); // retorna o inicio
    pq.pop(); // remove o inicio

    deque<int> dq; // fila dupla; passivel de acesso com []
    dq.push_back(3); // insere no final
    dq.push_front(5); // insere no inicio
    dq.pop_back(); // remove do final
    dq.pop_front(); // remove do inicio
    dq.erase(dq.begin()+3); // remove pela posicao

    set<int> cnj; // conjunto
    cnj.insert(3); // adiciona elemento
    cnj.count(1); // conta ocorrencia
    cnj.erase(3);// remove elemento

    for(auto x: cnj); // itera sobre os elementos do conjunto

    map<string, int> mp; // mapa/dicionario
    mp["tres"] = 3; // chave: "tres", valor: 3
    mp.erase("tres"); // remove

    //todas tem struture.size();

    for(auto [chave, valor] : mp); // itera sobre os elementos do mapa

    pair<int, int> par; // par 
    par.first = 30;
    par.second = 23;

    return 0;
}