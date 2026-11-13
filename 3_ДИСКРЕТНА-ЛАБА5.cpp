//Завдання 3. Розфарбування графа методом бектрекінгу
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int V = 6; // Кількість вершин у графі (Таблиця 3: індекси 1..6)

// Перевірка, чи безпечно призначити колір c для вершини v
bool isSafe(int v, const vector<vector<int>>& adj, const vector<int>& color, int c) {
    for (int i = 0; i < V; i++) {
        if (adj[v][i] > 0 && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Рекурсивна функція бектрекінгу
bool graphColoringUtil(const vector<vector<int>>& adj, int m, vector<int>& color, int v) {
    if (v == V) {
        return true; // Усі вершини успішно розфарбовано
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, adj, color, c)) {
            color[v] = c;

            if (graphColoringUtil(adj, m, color, v + 1)) {
                return true;
            }

            // Повернення назад (бектрекінг)
            color[v] = 0;
        }
    }
    return false;
}

int main() {
    // Матриця суміжності 6x6 побудована за Таблицею 3 для Варіанта 18:
    // R12=2, R13=1, R14=0, R15=1, R16=0
    // R23=1, R24=1, R25=0, R26=0
    // R34=0, R35=1, R36=0
    // R45=1, R46=1
    // R56=1
    vector<vector<int>> adj = {
        {0, 2, 1, 0, 1, 0}, // Вершина 1
        {2, 0, 1, 1, 0, 0}, // Вершина 2
        {1, 1, 0, 0, 1, 0}, // Вершина 3
        {0, 1, 0, 0, 1, 1}, // Вершина 4
        {1, 0, 1, 1, 0, 1}, // Вершина 5
        {0, 0, 0, 1, 1, 0}  // Вершина 6
    };

    int numColors = 3; // Кількість кольорів (A, B, C)
    vector<int> color(V, 0);
    string colorNames[] = {"", "A", "B", "C"};

    if (graphColoringUtil(adj, numColors, color, 0)) {
        cout << "Graph coloring for Variant 18 (3 colors):" << endl;
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << (i + 1) << " -> Color " << colorNames[color[i]] << endl;
        }
    } else {
        cout << "Solution does not exist with " << numColors << " colors." << endl;
    }

    return 0;
}
