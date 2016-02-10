#include <iostream>
#include <fstream>
#include <vector>
#include <chrono> 
#include <ctime>
#include "functions.h"

const int MAXVALUES = 15;
using namespace std;

int main(int argc, char *argv[])
{
	/*
   ifstream fin;
   int count = 0;
   int j = 0;
   int temp = 0;
   int i = 0;
   int elemCnt = 0;

   vector<int> sortValue;

   if (!checkArgs(argc, argv))
      return -1;

   if (!openFile(fin, argv[1]))
      return -2;
  while(fin >> temp)
  {
  	sortValue.push_back(temp);
  	count++;
  }
  fin.close();
  auto c1 = clock();
  elemCnt = count/2;
  for(i=0;i<count;++i)
    {
        for(j=0;j<count;j++)
        {
            if(sortValue[j+1] > sortValue[j])
            {
                temp = sortValue[j];
                sortValue[j] = sortValue[j+1];
                sortValue[j+1] = temp;
            }
            //cout << sortValue[elemCnt] << endl;
        }
    }
    auto c2 = clock();
    auto diff1 = c2 - c1;
    cout << "Time :" << diff1 * 1000.0/ CLOCKS_PER_SEC;
    for(i=0; i<count; i++)
    {
    	//cout << sortValue[i] << " ";
    }
    cout << endl;
    */
    int number;
    cin >> number;
    cout << oneCounter(number) << endl;
    /*
    auto c1 = clock();
    int sum = 0;
    int n = 10000;
    int i,j,k;
    for (i = 0; i <n; ++i)
    	++sum;

    auto c2 = clock();
    auto diff1 = c2 - c1;
    cout << "Time :" << diff1 * 1000.0/ CLOCKS_PER_SEC << endl;

    c1 = clock();
    sum = 0;
    for (i = 0; i <n; ++i)
    	for(j=0; j<n; ++j)
    		++sum;

    c2 = clock();
    diff1 = c2 - c1;
    cout << "Time :" << diff1 * 1000.0/ CLOCKS_PER_SEC << endl;


    c1 = clock();
    sum = 0;
    for (i = 0; i <n; ++i)
    	for(j=0; j< n*n; ++j)
    		++sum;

    c2 = clock();
    diff1 = c2 - c1;
    cout << "Time :" << diff1 * 1000.0/ CLOCKS_PER_SEC << endl;


    c1 = clock();
    sum = 0;
    for (i = 0; i <n; ++i)
    	for(j=0; j<i; ++j)
    		++sum;

    c2 = clock();
    diff1 = c2 - c1;
    cout << "Time :" << diff1 * 1000.0/ CLOCKS_PER_SEC << endl;


    c1 = clock();
    sum = 0;
    /*
    for (i = 0; i <n; ++i)
    	for(j=0; j<i*i; ++j)
    		for (k = 0; k<j; ++k)
    			++sum;
    			

    c2 = clock();
    diff1 = c2 - c1;
    cout << "Time :" << diff1 * 1000.0/ CLOCKS_PER_SEC << endl;


    c1 = clock();/*
    sum = 0;
    for (i = 0; i <n; ++i)
    	for(j=0; j<i*i; ++j)
    		if (j%i == 0)
    			for (k = 0; k<j; ++k)
    				++sum;
    				

    c2 = clock();
    diff1 = c2 - c1;
    cout << "Time :" << diff1 * 1000.0/ CLOCKS_PER_SEC << endl;\
    */
   return 0;
}
