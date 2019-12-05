/* Programação Dinâmica - Algoritmo de Kadane
   Em Ciência da Computação, encontrar a sublista contígua de maior soma a partir de
   uma lista de números é um problema bastante conhecido.

   [10    5   -17   20    50    -1    3   -30   10]

   Na seqüência acima, a sublista contígua de maior soma é [20, 50, -1, 3]
   e a soma total desse trecho é 72.
 */

#include <iostream>
#include <vector>

using namespace std;

void kadane(vector<int>& vet) {
        int current_max = 0, max_total = -1;

        for(int i = 0; i < vet.size(); i++) {
                current_max = current_max + vet[i];

                if(current_max < 0) {
                        current_max = 0;
                }

                if(current_max > max_total) {
                        max_total = current_max;
                }
        }

        cout << "\nSoma maxima: " << max_total << endl;
}

void print_vector(vector<int>& vet){
        for(int i = 0; i < vet.size(); i++) {
                printf("%d ", vet[i]);
        }
}

int main(int argc, char *argv[]) {
        vector<int> vet {
                10, 5, -17, 20, 50, -1, 3, -30, 10
        };

        print_vector(vet);
        kadane(vet);

        return 0;
}
