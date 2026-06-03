#include <iostream.h>
#include <fstream.h>

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

// сортиране във възходящ ред на масив от 3 цели числа
void sort3(int nums[])
{
    if(nums[1] < nums[0])
        swap(nums[0], nums[1]);
    if(nums[2] < nums[1])
    { 
        swap(nums[2], nums[1]);
        if(nums[1] < nums[0])
            swap(nums[0], nums[1]);
    }
}

int main()
{ 
    // отваряне на входния файл
    const char* input_file_name = "numbers.txt";
    ifstream in_file(input_file_name);
    if(!in_file)
    {
        cerr << "Не може да се отвори файлът "
             << input_file_name << '\n';
        return 1;
    }

    // отваряне на изходния файл
    const char* output_file_name = "sorted.dat";
    ofstream out_file(output_file_name, ios::binary | ios::trunc);
    if(!out_file)
    {
        cerr << "Не може да се отвори файлът "
             << output_file_name << '\n';
        in_file.close();
        return 1;
    }

    int nums[3];
    // четене на три числа от входния файл
    while(in_file >> nums[0] >> nums[1] >> nums[2])
    { 
        // сортиране на числата
        sort3(nums);
        // записване във файла
        out_file.write((const char *)nums, 3*sizeof(nums[0]));
    }

    in_file.close();
    out_file.close();
    return 0;
}
