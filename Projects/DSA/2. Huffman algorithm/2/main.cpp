#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#define COUNT 10

struct Node
{
    char symbol;
    size_t frequency;
    Node *left, *right;
    Node(Node* _left = nullptr, const char sym = ' ', const size_t freq = 0, Node* _right = nullptr):left(_left), symbol(sym), frequency(freq), right(_right){}
};

void print2DUtil(Node *root, int space)  
{  
    // Base case  
    if (root == NULL)  
        return;  
  
    // Increase distance between levels  
    space += COUNT;  
  
    // Process right child first  
    print2DUtil(root->right, space);  
  
    // Print current node after space  
    // count  
    std::cout << std::endl;  
    for (int i = COUNT; i < space; i++)  
        std::cout << " ";  
    std::cout << root->frequency << "\n";  
  
    // Process left child  
    print2DUtil(root->left, space);  
}  
// Wrapper over print2DUtil()  
void print2D(Node *root)  
{  
    // Pass initial space count as 0  
    print2DUtil(root, 0);  
}  


size_t times(const char symbol, const std::string str)
{
    size_t counter = 0;
    for (const char sym : str)
        if (sym == symbol)
            counter++;

    return counter;
}
void initTable(std::map<char, size_t>& table, const std::string& str)
{
    //setting up all characters in a set
    std::set<char> symbols;
    for (const char sym : str)
        symbols.insert(sym);

    //frequency table
    for (const char sym : str)
        table[sym] = times(sym, str);
}

void findMins(std::vector<Node*> nodes, size_t& min1, size_t& min2)
{
    if (nodes.size() < 2)
        return;
    
    if (nodes[0]->frequency <= nodes[1]->frequency)
        min1 = 0, min2 = 1;
    else
        min1 = 1, min2 = 0;
    
    for (size_t i = 2; i < nodes.size(); i++)
    {
        if (nodes[i]->frequency < nodes[min1]->frequency)
        {
            min2 = min1;
            min1 = i;
        }
        else if (nodes[i]->frequency < nodes[min2]->frequency)
        {
            min2 = i;
        }
    }

    if(min1 > min2)
        std::swap(min1, min2);
}
Node* createTree(Node* left, Node* right)
{
    return (new Node(left, ' ', left->frequency + right->frequency, right));
}

Node* huffman(std::vector<Node*> nodes)
{
    size_t total = 0, current = 0;
    for (size_t i = 0; i < nodes.size(); i++)
        total += nodes[i]->frequency;

    //setting the first indexes with minimum roots weights
    size_t i, j;
    findMins(nodes, i, j);

    Node* tree = nullptr;
    while (current != total)
    {           
        if(nodes.size() >= 2)
        {
            tree = createTree(nodes[i], nodes[j]);
            current = tree->frequency;
            nodes[i] = tree;
            nodes.erase(nodes.begin() + j);
            findMins(nodes, i, j);
        }
    }

    return tree;
}
std::string binary(const Node* root, const char sym, const std::string res)
{
    if (root == nullptr)
    {
        return "";
    }
    else if (root->symbol == sym)
    {
        return res;
    }
    
    return binary(root->left, sym, res + '0') + binary(root->right, sym, res + '1');
}

void read(const std::string& fileName, std::string& binaryCode, Node*& tree)
{
    std::ifstream input(fileName);
    if (input.is_open())
    {
        std::cout << "Successfully opened " << fileName << std::endl;
        
        std::string str;
        std::getline(input, str);

        //frequency table
        std::map<char, size_t> table;
        initTable(table, str);

        //creating the leaves of the tree with characters and their frequency
        std::vector<Node*> nodes;
        for (const std::pair<char, size_t> pair: table)
            nodes.push_back(new Node(nullptr, pair.first, pair.second, nullptr));

        //creating tree
        tree = huffman(nodes);
        //print2D(tree);
        
        //binary code
        for (const char sym : str)
            binaryCode += binary(tree, sym, "");   
    }
    else
    {
        std::cout << "Could not open " << fileName << std::endl;
    }
}
void write(const std::string& fileName, const std::string& result)
{
    std::ofstream output(fileName, std::ios::trunc|std::ios::out);
    output << result;
}

std::string fill(std::string binary)
{
    if (binary.size() % 8 == 0)
    {
        return binary;
    }
    
    std::string result;
    while (binary != "")
    {
        std::string byte = binary.substr(0, 8);
        if (byte.size() < 8)
            for (size_t j = 0, size = byte.size(); j < 8 - size; j++)
                byte.insert(byte.begin(), '0');

        result += byte;
        binary.erase(0, 8);
    }
    
    return result;
}

void compressInfo(const std::string& binary, const std::string& str)
{
    size_t result = ((double)binary.size() / (8 * str.size())) * 100;
    std::cout << "Compressed file is with " << result << "% less size from the original size!\n";
}

std::string compress(std::string& binary, Node*& tree)
{
    std::string str;
    std::string commandLine;
    do
    {
        std::cout << "> ";
        std::getline(std::cin, commandLine);
        std::string command = commandLine.substr(0, commandLine.find(' ')), 
                    argument = commandLine.substr(commandLine.find(' ') + 1, commandLine.size());
        
        if (command == "i")
        {
            read(argument, binary, tree);
            std::ifstream in(argument);
            std::getline(in, str);
        }
        else if (command == "o")
        {
           write(argument, binary);
           compressInfo(binary, str);
        }
        else if(command == "exit")
        {
            return "exit";
        }
        else
        {
            std::cout << "Invalid command!\n";
        }
    } while (commandLine != "decompress" && commandLine != "d");

    //compressInfo(binary);
    binary = fill(binary);

    return commandLine;
}

std::string decompress(std::string& binary, Node* tree)
{
    std::string commandLine;
    std::string str;
    do
    {
        std::cout << "> ";
        std::getline(std::cin, commandLine);
        std::string command = commandLine.substr(0, commandLine.find(' ')), 
                    argument = commandLine.substr(commandLine.find(' ') + 1, commandLine.size());
        
        if(command == "exit")
        {
            return "exit";
        }
        else
        {
            std::cout << "Invalid command!\n";
        }
        
    } while (commandLine != "compress" && commandLine != "c");
    
    return commandLine;
}

void run(std::string& mode)
{
    std::cin.ignore();
    std::string binary;
    Node* tree = nullptr;
    while (mode != "exit")
    {
        if (mode == "compress" || mode == "c")
        {
            std::cout << "--- Compress mode ---\n";
            while (mode == "compress")
                mode = compress(binary, tree);
        }
        else if (mode == "decompress" || mode == "d")
        {
            std::cout << "--- Decompress mode ---\n";
            while (mode == "decompress")
                mode = decompress(binary, tree);
        }
    }
}

int main()
{
    std::cout << "To exit the program type exit!\n";
    std::string mode;
    std::cout << "> ";
    std::cin >> mode;
    run(mode);

    return 0;
}