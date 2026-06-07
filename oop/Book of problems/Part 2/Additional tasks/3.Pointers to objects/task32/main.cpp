#include <iostream>
#include "RatNum.cpp"
#include "RatNums.cpp"

int main()
{
    RatNums nums(5);
    nums.setSize(5);
    nums.add(RatNum(1, 2), 0);
    nums.add(RatNum(3, 4), 1);
    nums.add(RatNum(4, 5), 2);
    nums.add(RatNum(5, 6), 3);
    nums.add(RatNum(6, 7), 4);
    nums.add(RatNum(7, 8), 5);
    nums.print();

    RatNums nums2(3);
    nums2.add(RatNum(7, 8), 0);
    nums2.add(RatNum(8, 9), 1);
    nums2.add(RatNum(9, 10), 2);
    nums2.print();

    RatNums temp = merge(nums, nums2);
    temp.print();

    std::cout << temp[4] << std::endl;  

    return 0;
}