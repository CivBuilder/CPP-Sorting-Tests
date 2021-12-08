/// @author Chris Catechis
/// @brief This program tests different sort algorithms with the vector class.

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <vector>

// global constant declaration phase
const int ten = 10;
const int tenK = 10000;
const int twentyK = 20000;
const int fortyK = 40000;
const int eightyK = 80000;

using namespace std::chrono;
using namespace std;

// function declarations
void print_table();
void bubble_sort(vector<int> vec);
void insertion_sort(vector<int> vec);
void selection_sort (vector<int> vec);
double process_vec(vector<int> vec, void funcPtr(vector<int>));

int main() {
    vector<int> bubble_vec1;

    
    // processing phase


    // output phase
    print_table();
}

void print_table() {
    
    cout << left;

    cout << setw(12) << "Bubble:";
    cout << '{' << bubble_vec1 << "} => {" << bubble_vec2 << "}\n";

    cout << setw(12) << "Insertion:";
    cout << '{' << insert_vec1 << "} => {" << insert_vec2 << "}\n";

    cout << setw(12) << "Selection:";
    cout << '{' << selec_vec1 << "} => {" << selec_vec2 << "}\n";

    cout << setw(12) << "std::sort:";
    cout << '{' << std_vec1 << "} => {" << std_vec2 << "}\n";

    cout << '\n';

    cout << setw(5) << "Size";
    cout << right;
    cout << setw(11) << "Bubble";
    cout << setw(11) << "Insertion";
    cout << setw(11) << "Selection";
    cout << setw(11) << "std::sort";
    cout << endl;

    cout << left << setw(5) << tenK;
    cout << right;
    // output tenk times setw(11);
    cout << endl;

    cout << left << setw(5) << twentyK;
    cout << right;
    // output twentyk times;
    cout << endl;

    cout << left << setw(5) << fortyK;
    cout << right;
    // output fortyk times;
    cout << endl;

    cout << left << setw(5) << eightyK;
    cout << right;
    // output eightyk times;
    cout << endl;

    cout << '\n';

    cout << "Times reported in seconds." << endl;
}

void bubble_sort(vector<int> vec) {
    int temp;  // holds i + 1
    int swap_count = -1;  // if 0, list is sorted

    for (int i = 1; i < vec.size() && swap_count == 0; ++i) {
        swap_count = 0;
        for (int index = 0; index < vec.size() - i; ++index) {
            if (vec.at(index) > vec.at(index + 1)) {
                temp = vec.at(index);
                vec.at(index) = vec.at(index + 1);
                vec.at(index + 1) = temp;
                ++swap_count;
            }
        }
    }

}

void insertion_sort (vector<int> vec) {
    int location;  // location of element in wrong place
    int temp;  // holds temporary element

    for (int wrongPlace = 1; wrongPlace < vec.size(); ++wrongPlace) {
        if (vec.at(wrongPlace) < vec.at(wrongPlace - 1)) {
            temp = vec.at(wrongPlace);
            location = wrongPlace;

            do {
                vec.at(location) = vec.at(location - 1);
                --location;
            }
            while (location > 0 && vec.at(location - 1) > temp);

            vec.at(location) = temp;
        }
    }
}

void selection_sort (vector<int> vec) {
    int smallest_index;  // holds index of smallest incorrect element
    int temp;  // holds temporary element

    for (int index = 0; index < vec.size() + 1; ++index) {
        smallest_index = index;

        for (int location = index + 1; location < vec.size(); ++location) {
            if (vec.at(location) < vec.at(smallest_index)) {
                smallest_index = location;
            }

            temp = vec.at(smallest_index);
            vec.at(smallest_index) = vec.at(index);
            vec.at(index) = temp;
        }
    }
}

double process_vec(vector<int> vec, void funcPtr(vector<int>)) {
    shuffle(vec.begin(), vec.end(), rand);  // randomize the vector
    auto start = high_resolution_clock::now();  // gets current time
    (*funcPtr)(vec);  // sort the vector
    auto stop = high_resolution_clock::now();  // post function time
    auto duration = duration_cast<microseconds>(stop - start);  // run time
    auto run_time = duration.count() / 1000000.0;  // convert to seconds

    return run_time;
}