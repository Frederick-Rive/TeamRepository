#include <iostream>
#include <vector>
#include <ctime>
//this one sucks
int BadSort(std::vector<short> vec)
{
    int rtrn = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (vec[i] > vec[j])
            {
                short temp = vec[i];

                vec[i] = vec[j];
                vec[j] = temp;

                rtrn++;
            }
        }
    }

    return rtrn;
}
//this ones cool
int GoodSort(short* ptr, int length)
{
    int rtrn = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (*(ptr + i) > *(ptr + j))
            {
                int temp = *(ptr + i);

                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;

                rtrn++;
            }
        }
    }

    return rtrn;
}

int main()
{
    srand(time(0));

    std::vector<short> vecctoorr;
    std::vector<short> vec;

    for (int i = 0; i < 5000; i++)
    {
        vecctoorr.push_back(rand() % 1000);
        vec.push_back(vecctoorr[i]);
    }

    short* ptr = &vecctoorr[0];

    int t = clock();

    int q = GoodSort(ptr, vecctoorr.size());

    t = clock() - t;

    int y = clock();

    int w = BadSort(vec);

    y = clock() - y;

    std::cout << "Time taken for pointer sort: " << ((float)t) / CLOCKS_PER_SEC;
    std::cout << "\nTime taken for old sort: " << ((float)y) / CLOCKS_PER_SEC;
    std::cout << "\nDifference in time: " << ((float)y - t) / CLOCKS_PER_SEC << std::endl;
    std::cout << "Number of item changes: " << w;
}
