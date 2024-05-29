#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <iomanip>
#include <cassert>
using ll = long long;
using namespace std;
 
template <int M>
unsigned int ajustar(unsigned int x) {
    return x >= M ? x - M : x;
}
 
template <int M>
struct NumeroModular {
    unsigned int valor;
    NumeroModular() = default;
    NumeroModular(unsigned int valor) : valor(valor) {}
 
    friend istream &operator>>(istream &in, NumeroModular &a) { return in >> a.valor; }
    friend ostream &operator<<(ostream &out, NumeroModular a) { return out << a.valor; }
 
    friend NumeroModular operator+(NumeroModular a, NumeroModular b) { return ajustar<M>(a.valor + b.valor); }
    friend NumeroModular operator-(NumeroModular a, NumeroModular b) { return ajustar<M>(a.valor - b.valor + M); }
    friend NumeroModular operator*(NumeroModular a, NumeroModular b) { return 1ULL * a.valor * b.valor % M; }
    friend NumeroModular operator/(NumeroModular a, NumeroModular b) { return a * ~b; }
 
    friend NumeroModular operator^(NumeroModular a, int b) {
        NumeroModular res = 1;
        for (; b; b >>= 1, a *= a)
            if (b & 1)
                res *= a;
        return res;
    }
 
    friend NumeroModular operator~(NumeroModular a) { return a ^ (M - 2); }
    friend NumeroModular operator-(NumeroModular a) { return ajustar<M>(M - a.valor); }
 
    friend NumeroModular &operator+=(NumeroModular &a, NumeroModular b) { return a = a + b; }
    friend NumeroModular &operator-=(NumeroModular &a, NumeroModular b) { return a = a - b; }
    friend NumeroModular &operator*=(NumeroModular &a, NumeroModular b) { return a = a * b; }
    friend NumeroModular &operator/=(NumeroModular &a, NumeroModular b) { return a = a / b; }
    friend NumeroModular &operator^=(NumeroModular &a, int b) { return a = a ^ b; }
 
    friend NumeroModular &operator++(NumeroModular &a) { return a += 1; }
    friend NumeroModular operator++(NumeroModular &a, int) {
        NumeroModular tmp = a;
        a += 1;
        return tmp;
    }
 
    friend NumeroModular &operator--(NumeroModular &a) { return a -= 1; }
    friend NumeroModular operator--(NumeroModular &a, int) {
        NumeroModular tmp = a;
        a -= 1;
        return tmp;
    }
 
    friend bool operator==(NumeroModular a, NumeroModular b) { return a.valor == b.valor; }
    friend bool operator!=(NumeroModular a, NumeroModular b) { return !(a == b); }
};
 
using modulo = NumeroModular<1000000007>;
 
template <typename T>
struct ArbolFenwick {
    int tamano;
    vector<T> arreglo;
 
    ArbolFenwick(int tamano = 0) { inicializar(tamano); }
 
    void inicializar(int tamano) {
        this->tamano = tamano;
        arreglo.assign(tamano + 1, T());
    }
 
    void agregar(int indice, T valor) {
        for (int i = indice; i <= tamano; i += i & -i)
            arreglo[i] += valor;
    }
 
    T sumar(int indice) {
        T resultado = T();
        for (int i = indice; i; i -= i & -i)
            resultado += arreglo[i];
        return resultado;
    }
 
    T sumaRango(int izquierda, int derecha) { return sumar(derecha) - sumar(izquierda - 1); }
 
    int kth(T k) {
        int indice = 0;
        for (int i = 1 << __lg(tamano); i; i >>= 1) {
            if (indice + i <= tamano && k >= arreglo[indice + i]) {
                indice += i;
                k -= arreglo[indice];
            }
        }
        return indice;
    }
};
 
void resolver() {
    int nodos, aristas, k;
    cin >> nodos >> aristas >> k;
    vector<array<int, 4>> informacionAristas(aristas);
    for (int i = 0; i < aristas; i++)
        cin >> informacionAristas[i][0] >> informacionAristas[i][1] >> informacionAristas[i][2] >> informacionAristas[i][3], informacionAristas[i][0]--, informacionAristas[i][1]--;
 
    vector<ll> limites(aristas, 2e13), cuentas(aristas);
    auto inicializarLimites = [&](ll x) {
        for (int i = 0; i < aristas; i++) {
            ll val = (x - i) / aristas;
            cuentas[i] = max(0ll, min(limites[i], ((val - informacionAristas[i][3]) / informacionAristas[i][2] + 1) / 2));
        }
    };
 
    struct Grafo {
        vector<int> inicio, hacia, siguiente;
        queue<int> cola; // Renombramos la cola
        vector<int> distancias, grafo;
        vector<ll> capacidades;
        int fuente, sumidero;
 
        Grafo(int _fuente, int _sumidero) : fuente(_fuente), sumidero(_sumidero) {
            inicio.resize(_sumidero + 1, -1);
            distancias.resize(_sumidero + 1);
            grafo.resize(_sumidero + 1);
        }
 
        void agregar(int x, int y, ll z) {
            hacia.push_back(y), siguiente.push_back(inicio[x]);
            capacidades.push_back(z), inicio[x] = hacia.size() - 1;
            hacia.push_back(x), siguiente.push_back(inicio[y]);
            capacidades.push_back(0), inicio[y] = hacia.size() - 1;
        }
 
        bool bfs() {
            distancias.assign(sumidero + 1, -1);
            grafo.assign(sumidero + 1, -1);
            distancias[fuente] = 0;
            cola.push(fuente); 
            while (!cola.empty()) {
                int actual = cola.front();
                grafo[actual] = inicio[actual];
                cola.pop();
                for (int p = inicio[actual]; ~p; p = siguiente[p]) {
 
                    if (capacidades[p] && distancias[hacia[p]] == -1) {
                        distancias[hacia[p]] = distancias[actual] + 1;
                        cola.push(hacia[p]); 
                    }
                }
            }
            return distancias[sumidero] >= 0;
        }
 
        ll dfs(int actual, ll flujo) {
            if (actual == sumidero)
                return flujo;
            ll usado = 0;
            for (int &p = grafo[actual]; ~p; p = siguiente[p]) {
                if (capacidades[p] && distancias[hacia[p]] == distancias[actual] + 1) {
                    ll k = dfs(hacia[p], min(flujo - usado, capacidades[p]));
                    usado += k;
                    capacidades[p] -= k, capacidades[p ^ 1] += k;
                    if  (usado == flujo)
                        break;
                }
            }
            return usado;
        }
 
        ll flujo() {
            ll resultado = 0;
            while (bfs())
                resultado += dfs(fuente, 1e18);
            return resultado;
        }
    };
 
    auto comprobar = [&](ll x) {
        Grafo grafo(nodos + aristas, nodos + aristas + 1);
        inicializarLimites(x);
        for (int i = 0; i < nodos; i++)
            grafo.agregar(nodos + aristas, i, k);
        ll resultado = 0;
        for (int i = 0; i < aristas; i++) {
            grafo.agregar(informacionAristas[i][0], i + nodos, 1e18);
            grafo.agregar(informacionAristas[i][1], i + nodos, 1e18);
            grafo.agregar(i + nodos, nodos + aristas + 1, cuentas[i]);
            resultado += cuentas[i];
        }
        resultado -= grafo.flujo();
        if (resultado)
            return false;
        for (int i = 0; i < nodos; i++) {
            auto tmpGrafo = grafo;
            tmpGrafo.agregar(i, nodos + aristas + 1, k);
            ll tmp = tmpGrafo.flujo();
            if (tmp < k)
                return false;
        }
        return true;
    };
 
    const ll infinito = 2e13;
    ll izquierda = aristas;
    for (int i = 0; i < aristas; i++, izquierda++) {
        ll derecha = infinito, medio;
        while (izquierda < derecha) {
            medio = izquierda + derecha + 1 >> 1;
            if (comprobar(medio))
                izquierda = medio;
            else
                derecha = medio - 1;
        }
        int posicion = (izquierda + 1) % aristas;
        ll valor = (izquierda - posicion) / aristas;
        limites[posicion] = ((valor - informacionAristas[posicion][3]) / informacionAristas[posicion][2] + 1) / 2;
    }
    assert(comprobar(izquierda + 5));
    ll respuesta = 0;
    for (int i = 0; i < aristas; i++) {
        ll a = informacionAristas[i][2], b = informacionAristas[i][3];
        respuesta += limites[i] * limites[i] * a + limites[i] * b;
    }
    cout << respuesta << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int pruebas;
    cin >> pruebas;
    cout << fixed << setprecision(15);
    while (pruebas--)
        resolver();
    return 0;
}
  	  	  		  	 	    	 	 	   		