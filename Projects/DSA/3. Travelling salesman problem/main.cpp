#include <iostream>
#include <algorithm>
#include <climits>
#include <chrono>
#include <queue>
#include <set>
#include <vector>
#include <fstream>  
#include <string>
#include <cstring>

void generate_random_matrix(void)
{
/* 
generating a random matrix, which represents the cities and the distances between them
and storing it in a file
*/

    std::cout << "Enter file name: ";

    std::string file_name;
    std::getline(std::cin, file_name); /* read file name */

    std::ofstream file(file_name); /* open file for writing */
    
    if(!file.is_open()) exit(-1); /* error opening the file => exit */
    
    size_t cities;
    std::cout << "Enter number of cities: ";
    std::cin >> cities;

    int lower_bound = 1, upper_bound = 50;
/*    
    std::cout << "Enter lower bound of distances: "; std::cin >> lower_bound;
    std::cout << "Enter upper bound of distances: "; std::cin >> upper_bound;
*/
    for (size_t i = 0; i < cities; i++)
    {
        for (size_t j = 0; j < cities; j++)
        {
            if(i == j) file << 0; /* distance form current town to current town = 0 */
            else file << (std::rand() % upper_bound + lower_bound);

            if(j == cities - 1) file << '\n';
            else file << ", ";
        }
    }
    
    file.close(); /* closing the file */

    std::cout << "Successfully genereted a matrix with elements of values between " 
              << lower_bound << " and " << upper_bound << "in file " << file_name << std::endl;
    std::cin.ignore();
}

void read(std::vector<std::vector<int>>& cities) 
{
/* reading the file data, which is in form of a matrix */

    std::cout << "Open a file: ";

    std::string file_name;
    std::getline(std::cin, file_name); /* read file name */
    
    std::ifstream file(file_name); /* open the file */
    if (!file.is_open()) exit(-1);

    std::string line;
    while (std::getline(file, line)) /* getting the file line by line */
    {
        std::vector<int> distances; /* this vector contains the distances from one city to other*/

        char *cstr = new char [line.length() + 1];
        std::strcpy (cstr, line.c_str());  /* taking char* from string */

        char *number = std::strtok(cstr, ",");  /* tokenizing the string */
        while (number != 0)
        {
            distances.push_back(std::stoi(number));
            number = std::strtok(NULL, ",");
        }

        delete[]cstr;
        cities.push_back(distances); /* pushing each line of elements */
    }        
}

void read_v2(std::ifstream& file, std::vector<std::vector<int>>& cities)
{
    std::string line;
    while (std::getline(file, line)) /* getting the file line by line */
    {
        std::vector<int> distances; /* this vector contains the distances from one city to other*/

        char *cstr = new char [line.length() + 1];
        std::strcpy (cstr, line.c_str());  /* taking char* from string */

        char *number = std::strtok(cstr, ",");  /* tokenizing the string */
        while (number != 0)
        {
            distances.push_back(std::stoi(number));
            number = std::strtok(NULL, ",");
        }

        delete[]cstr;
        cities.push_back(distances); /* pushing each line of elements */
    } 
}

void symmetry(std::vector<std::vector<int>>& cities)
{
    for (size_t i = 0; i < cities.size() - 1; i++)  
        if ( (cities[i].size() != cities[i + 1].size()) || (cities.size() != cities[i].size()) ) 
            exit(-1);
    
    for (size_t i = 0; i < cities.size(); i++)
    {
        for (size_t j = 0; j < cities.size(); j++)
        {
            if(i == j && cities[i][j] != 0) cities[i][j] = 0;
            else if(i != j && cities[i][j] == 0 && cities[j][i] != 0) cities[i][j] = cities[j][i];
            else if(i != j && cities[j][i] == 0 && cities[i][j] != 0) cities[j][i] = cities[i][j];
            else if(i != j && cities[i][j] == 0 && cities[j][i] == 0) cities[i][j] = cities[j][i] = std::rand() % 100 + 1;
        }
    }
}

/* Time complexity : O((n - 1)!), where n is the number of cities */
void A_star_alg(const std::vector<std::vector<int>>& cities, const size_t start, std::queue<size_t>& path, int& total_path)
{
/* storing all cities(vertices) apart from starting one(vertex) */
    std::vector<int> vertex;
    for (int i = 0; i < cities.size(); i++)
        if (i != start) vertex.push_back(i);

    int min_path = INT_MAX; /* store minimum weight Hamiltonian cycle */
    do 
    {
        std::queue<size_t> curr_path; /* stores the cities, representint the path in a graphical way */
        
        int current_path_weight = 0; /*  store current path weight */
 
        /* calculate current path weight */
        size_t current = start; 
        curr_path.push(current); /* push the starting city */

        for (size_t i = 0; i < vertex.size(); i++) 
        {
            current_path_weight += cities[current][vertex[i]]; /* add the distance between current city and next city(vectex[i]) */
            current = vertex[i]; /* go to city(vertex[i]) */
            curr_path.push(current); /* push the next city */
        }
        curr_path.push(start); /* all cities are visited and going back to the starting one */
        current_path_weight += cities[current][start];
 
        if(current_path_weight <= min_path) /* found a new mininum path */
        {
            min_path = current_path_weight; /* update minimum */
            path = curr_path; /* update the new path */
        }
        /* or maybe use min_path = std::min(min_path, current_pathweight); ? */
 
    } while (next_permutation(vertex.begin(), vertex.end())); /* generate next permutation of cities */

    total_path = min_path; /* minimal total path */
}

/* Time complexity : O(n*n), where n is the number of cities */
void greedy_alg(const std::vector<std::vector<int>>& cities, const size_t start, std::queue<size_t>& path, int& total_path)
{
    std::set<size_t> vertex; /* a set of cities for checking if its visited or not */

/* storing all cities(vertices) apart from starting one(vertex) */
    for (size_t i = 0; i < cities.size(); i++)
        if(i != start) vertex.insert(i);

    size_t curr_index = start; /* representing the current city with curr_index */

    path.push(curr_index);  /* store the starting point */

    int curr_path = 0; /* current path value */

    size_t size = vertex.size(); /* the number of cities we should visit */

    while(!vertex.empty())
    {
        int min_path = INT_MAX; /* store minimum weight Hamiltonian cycle */
        size_t res_index = 0; /* store the city to which the distance is minimum */

        /* find the minimum distance to the next city and go there  */
        for (std::set<size_t>::iterator it = vertex.begin(); it != vertex.end(); it++) 
        {
            size_t index = *it;
            if (cities[curr_index][index] <= min_path)
            {
                min_path = cities[curr_index][index];
                res_index = index;
            }
        }
        curr_index = res_index; /* go to the city with minimim distance inbetween */
        path.push(curr_index); /* update the path */
        vertex.erase(vertex.find(curr_index)); /* we cannot back to the previous city */
        curr_path += min_path; /* updated path weight */
    }

    curr_path += cities[curr_index][start]; /* go back to the starting city */
    path.push(start);
    total_path = curr_path; /* total path updated */
}

void print_info(const size_t start, std::queue<size_t>& path, const int& total_path, std::chrono::nanoseconds duration)
{
    size_t cities = path.size() - 1;
    printf("Starting city: %ld\nPath: ", start);
    while (!path.empty()) /* print the path */
    {
        std::cout << path.front(); 
        
        if(path.size() > 1) std::cout << " -> ";

        path.pop();
    }
    printf("\nMinimum path: %d\n", total_path);
    std::cout << "Total time for " << cities << " cities: " << duration.count() << " nanoseconds\n\n";
}

void test_A_star(std::vector<std::vector<int>> cities, size_t start)
{
/* check how long it takes for the algorithm to find a solution */
    auto start_time = std::chrono::high_resolution_clock::now(); 

    std::cout << "\n---------- A* algorithm ----------\n";

    std::queue<size_t> path;
    int total_path;
    A_star_alg(cities, start, path, total_path);

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time); 
    print_info(start, path, total_path, duration);    
}

void test_greedy(std::vector<std::vector<int>> cities, size_t start)
{
/* check how long it taks for the algorithm to find a solution */
    auto start_time = std::chrono::high_resolution_clock::now(); 

    std::cout << "---------- Greedy algorithm ----------\n";

    std::queue<size_t> path;
    int total_path;
    greedy_alg(cities, start, path, total_path);

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time); 
    print_info(start, path, total_path, duration);
}

void run(void)
{
    std::vector<std::vector<int>> cities;
    read(cities); /* read from file and store data in cities */
    if(cities.empty()) return; /* exit if no data is added */
    symmetry(cities); /* if the matrix in the file is incorrect => correct it */

    size_t start = std::rand() % (cities.size() - 1) + 0; /* starting from a random city */
    
    test_A_star(cities, start); /* testing A* algorithm */
    test_greedy(cities, start); /* testing Greedy algorithm */
}

void run_v2(const char *file_name)
{
    std::ifstream file(file_name);
    if (!file.is_open()) exit(-1);

    std::vector<std::vector<int>> cities;
    read_v2(file, cities);
    if(cities.empty()) return; /* exit if no data is added */
    symmetry(cities); /* if the matrix in the file is incorrect => correct it */

    size_t start = std::rand() % (cities.size() - 1) + 0; /* starting from a random city */
    test_A_star(cities, start); /* testing A* algorithm */
    test_greedy(cities, start); /* testing Greedy algorithm */
}

int main(int argc, char *argv[])
{
    /* generate_random_matrix(); */
    //run();
    for(int i = 1; i < argc; i++) run_v2(argv[i]); 
    
    return 0;
}
