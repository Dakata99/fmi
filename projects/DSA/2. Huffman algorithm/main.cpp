#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include <cmath>
#include <set>
#define COUNT 10

struct Node
{
    char symbol;
    size_t frequency;
    Node *left, *right;
    Node(Node* _left = nullptr, const char sym = ' ', const size_t freq = 0, Node* _right = nullptr):left(_left), symbol(sym), frequency(freq), right(_right){}
};

size_t times(const char symbol, const std::string str)
{
    size_t counter = 0;
    for (const char sym : str)
        if (sym == symbol)
            counter++;

    return counter;
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
void replace(std::vector<Node*>::iterator begin, std::vector<Node*>::iterator end, Node*& oldValue, Node* newValue)
{
    while (begin != end)
    {
        if ((*begin)->symbol == oldValue->symbol && (*begin)->frequency == oldValue->frequency)
        {
            (*begin) = new Node(newValue->left, newValue->symbol, newValue->frequency, newValue->right);
        }
        begin++;
    }
}

void printTree(const Node* root)
{
    if (root == nullptr)
    {
        return;
    }
    std::cout << root->frequency << std::endl;
    printTree(root->left);
    printTree(root->right);
}
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
            replace(nodes.begin(), nodes.end(), nodes[i], new Node(nodes[i], ' ', current, nodes[j]));
            nodes.erase(nodes.begin() + j);
            findMins(nodes, i, j);
        }
        // else if(nodes.size() == 2)
        // {
        //     tree = createTree(nodes[0], nodes[1]);
        //     current = tree->frequency;
        //     replace(nodes.begin(), nodes.end(), nodes[0], new Node(nodes[0], ' ', current, nodes[1]));
        //     nodes.erase(nodes.begin() + 1);
        // }
    }

    return tree;
}
std::string octets(const std::string& binary)
{
    std::string result;
    for (size_t i = 0; i < binary.size(); i++)
    {
        if (i % 8 == 0 && i > 0)
        {
            result += ' ';
        }
        result += binary[i];
    }

    return result;
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
int decimal(const std::string& byte)
{
    int result = 0;
    for (int i = byte.size() - 1, j = 0; i >= 0; i--, j++)
        if (byte[i] == '1')
            result += 1 * pow(2, j);
            
    return result;
}
std::vector<int> convert(std::string binary)
{
    std::vector<int> vec;
    
    while (binary != "")
    {    
        std::string byte;
        if (binary.find(' ') != std::string::npos)
            byte = binary.substr(0, binary.find(' '));
        else
            byte = binary.substr(0, binary.size());

        //if we have less than 8 bits, we fill them with 0-bits
        if (byte.size() < 8) 
            for (size_t i = 0; i < 8 - byte.size(); i++)
                byte.insert(byte.begin(), '0');    

        vec.push_back(decimal(byte));
        binary.erase(0, byte.size() + 1);
    }
    return vec;
}
void write(std::ofstream& output, const std::vector<int>& nums)
{
    std::stringstream s;
    for (size_t i = 0; i < nums.size(); i++)
        s << nums[i] << ' ';
    
    output << s.str();
}

char decompress(const char sym, const Node* root)
{
    if (root == nullptr)
    {
        return root->symbol;
    }
    else if (sym == '0')
    {
        decompress(sym, root->left);
    }
    else if (sym == '1')
    {
        decompress(sym, root->right);
    }
    return '\0';
}

std::vector<int> compress(std::ifstream& input)
{
    std::cout << "--- Compress mode ---\n";
    std::string str;
    std::getline(input, str);

    //setting up all characters in a set
    std::set<char> symbols;
    for (const char sym : str)
        symbols.insert(sym);

    //creating the leaves of the tree with characters and times of 
    std::vector<Node*> nodes;
    for (const char sym : symbols)
        nodes.push_back(new Node(nullptr, sym, times(sym, str), nullptr));

    //creating the tree
    Node* tree = huffman(nodes);

    //printTree(tree);
    //print2D(tree);

    //making binary table -> character == binary code
    std::map<char, std::string> table;
    for (const char sym : symbols)
        table.insert({sym, binary(tree, sym, "")});

    std::string binaryOcts;
    for (size_t i = 0; i < str.size(); i++)
        binaryOcts += table[str[i]];

    binaryOcts = octets(binaryOcts);
    
    return convert(binaryOcts);
}
void decompress(std::ifstream& input)
{
    std::cout << "--- Decompress mode ---\n";
    std::string str;
    std::getline(input, str);    
}

void open(std::ifstream& input, const std::string& fileName)
{
    input.open(fileName);
    if (input.is_open())
        std::cout << "Successfully opened " << fileName << std::endl;
    else
        std::cout << "Cannot open " << fileName << std::endl; 
}

void run()
{
    std::ifstream input;
    std::ofstream output;
    std::string commandLine;
    std::vector<int> digits;
    std::cout << "To exit the program type exit!\n";

    do
    {
        std::cout << "> ";
        std::getline(std::cin, commandLine);
        std::string command = commandLine.substr(0, commandLine.find(' ')), 
                    argument = commandLine.substr(commandLine.find(' ') + 1, commandLine.size());
        
        if (command == "i" && !input.is_open())
        {
            open(input, argument);
        }
        else if (command == "o" && input.is_open())
        {
            output.open(argument);
            write(output, digits);
        }
        else if (command == "c" || command == "compress")
        {
            if (input.is_open())
                digits = compress(input); 
            else
                std::cout << "OPEN A FILE FIRST!\n";
        }
        else if (command == "d" || command == "decompress")
        {
            if (input.is_open())
                decompress(input);
            else
                std::cout << "OPEN A FILE FIRST!\n";
        }
        else if(command != "exit")
        {
            std::cout << "Invalid command!\n";
        }   
    } while (commandLine != "exit");
}

int main()
{
    run();

    return 0;
}