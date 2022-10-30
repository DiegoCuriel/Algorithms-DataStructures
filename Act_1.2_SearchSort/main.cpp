// Act 1.2 - Algoritmos de Búsqueda y Ordenamiento
// Diego Curiel Castellanos - A01640372

#include <iostream>
#include <vector>

using namespace std;

int ordenaInsercion(vector<int>& vector) //Complejidad computacional: O(n^2)
{
	int cont = 0;
	for(int i = 1; i < vector.size(); i++)
	{
		int j = i;
        int var = vector[i];
		cont++; // Contador de comparaciones

        while(j > 0 && var < vector[j - 1])
        {
            vector[j] = vector[j - 1];
            j--;
			cont++; // Contador de comparaciones
        }
        vector[j] = var;
  	}
	return cont;
}

void swap(int i, int j, vector<int>& vector)
{
	int var = vector[i];
	vector[i] = vector[j];
	vector[j] = var;
}

int ordenaBurbuja(vector<int>& vector) //Complejidad computacional: O(n^2)
{
	int cont = 0;

	for(int i = 1; i < vector.size(); i++)
	{	
		bool bandera = false;
		for(int j = 0; j < vector.size()-i; j++)
		{ 
			cont++; // Contador de comparaciones
			if(vector[j] > vector[j + 1])
			{
				swap(j, j + 1, vector);
				bandera = true;
			}
		}
		if(bandera == false) // optimización
		{
			return cont;
		}
	}
	return cont;
}

void mezcla(vector<int>& vector, int ini, int fin, int& cont) // Cueva, V. González, L. Salinas, E. (2020). Estructura de datos y algoritmos fundamentales. Editorial Digital
{
	int cen = (ini + fin) / 2;
	int j = ini;
	int k = cen + 1;
	int size = fin - ini + 1;
	int vectorTmp[size];

	for (int i = 0; i < size; i++)
	{
		if (j <= cen && k <= fin)
		{
			cont++; // Contador de comparaciones
			if (vector[j] < vector[k])
			{
				vectorTmp[i] = vector[j++];
			}
			else
			{
				vectorTmp[i] = vector[k++];
			}
		}
		else if (j <= cen)
		{
			vectorTmp[i] = vector[j++];
		}
		else
		{
			vectorTmp[i] = vector[k++];
		}
	}

	for (int m = 0; m < size; m++)
	{
		vector[ini + m] = vectorTmp[m];
	}
}

void mergesort(vector<int>& vector, int ini, int fin, int& cont) // Cueva, V. González, L. Salinas, E. (2020). Estructura de datos y algoritmos fundamentales. Editorial Digital
{
	if (ini < fin)
	{
		int cen = (ini + fin) / 2;
		mergesort (vector, ini, cen, cont);
		mergesort (vector, cen + 1, fin, cont);
		mezcla(vector, ini, fin, cont);
	}
}

int ordenaMerge(vector<int>& vector) //Complejidad computacional: O(n log n)
{
	int cont = 0;
	mergesort(vector, 0, vector.size() - 1, cont);
	return cont;
}

int busqSecuencial(vector<int>& vector, int dato, int& cont) //Complejidad computacional: O(n)
{
	for(int i = 0; i < vector.size(); i++)
    {
		cont++; // Contador de comparaciones
        if(vector[i] == dato)
        return i;
    }
	return -1;
}

int busqBinaria(vector<int>& vector, int dato, int& cont) //Complejidad computacional: O(log n)
{
	int low = 0;
    int high = vector.size() - 1;

    int mid;

    while (low <= high)
    {
		cont++; // Contador de comparaciones

        mid = (low + high) / 2;

        if(dato == vector[mid])
        {
            return mid;
        }
        else if (dato > vector[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
	vector<int> v1, v2, v3;
	int n, dato;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> dato;
		v1.push_back(dato);
		v2.push_back(dato);
		v3.push_back(dato);
	}

	cout << ordenaInsercion(v1) << " " << ordenaBurbuja(v2) << " " << ordenaMerge(v3) << endl;

	int q, pos;
	int cantBS, cantBB;
	cin >> q;

	for (int i = 0; i < q; i++)
	{
		cantBS = 0;
		cantBB = 0;
		cin >> dato;
		pos = busqSecuencial(v1, dato, cantBS);
		pos = busqBinaria(v1, dato, cantBB);
		cout << pos << " " << cantBS << " " << cantBB << endl; 
	}
    return 0;
}