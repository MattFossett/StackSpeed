/** 
 * Author: Matt Fossett
 * 
 * Description: Test speeds of stacks using proper implementation versus poor implementation
 * March 9, 2018
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <iterator>
#include <vector>
#include <ctime>
#include <stack>

using std::stack;
using std::cout;
using std::cin;
using std::vector;

void
bs (size_t elems);

void 
good (size_t elems);

void 
stackS (size_t elems);

int
main()
{
    cout << "Good stack: [0]\nBad stack: [1]\nActual stack: [2]\nGood stack and c++ actual stack [3]\nAll [4]  \n#ofElements: [0,size_t Max);";
    //cout << " show elements[0,1]";
    int choice;
    int numElem;
    cin >> choice;
    cin >> numElem;
    if(choice == 0)
    {
        clock_t begin = clock();
        good (numElem);
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        cout << std::endl << elapsed_secs << std::endl << std::endl;
    }
    else if (choice == 1)
    {
        clock_t begin = clock();
        bs (numElem);
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        cout << std::endl << elapsed_secs << std::endl << std::endl;
    }
    else if( choice == 2)
    {
        clock_t begin = clock();
        stackS (numElem);
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        cout << std::endl << elapsed_secs << std::endl << std::endl;
    }
    else if (choice == 3)
    {
        clock_t beginG = clock();
        good (numElem);
        clock_t endG = clock();
        double elapsedG = double(endG - beginG) / CLOCKS_PER_SEC;
        cout << "\n\n362 Stack: " << elapsedG;        

        clock_t begin = clock();
        stackS (numElem);
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        cout << "\n\nC++ Stack: " << elapsed_secs << std::endl << std::endl;
    }
    else 
    {
        clock_t beginBS = clock();
        bs (numElem);
        cout << "\n\n" << "*********END BS**********";
        clock_t endBS = clock();

        clock_t beginG = clock();
        good (numElem);
        cout << "\n\n" << "*********END GOOD**********";
        clock_t endG = clock();

        clock_t beginS = clock();
        stackS (numElem);
        cout << "\n\n" << "*********END STACK**********";
        clock_t endS = clock();
        
        double elapsedBS = double(endBS - beginBS) / CLOCKS_PER_SEC;
        double elapsedG  = double(endG - beginG) / CLOCKS_PER_SEC;
        double elapsedS  = double(endS - beginS) / CLOCKS_PER_SEC;

        cout << "\n\n" << "Elapsed BS Time: " << elapsedBS;
        cout << "\n" << "Elapsed G  Time: " << elapsedG;
        cout << "\n" << "Elapsed S  Time: " << elapsedS << "\n\n";
        return EXIT_SUCCESS;
    }
}

void 
bs (size_t elems)
{
    vector<int> bs;
    for (; elems > 0; --elems)
    {
        bs.insert(bs.begin(), elems);
    }
    while (!bs.empty())
    {
        bs.erase(bs.begin());
    }
}

void 
good (size_t elems)
{
    vector<int> g;
    for (; elems > 0; --elems)
    {
        g.push_back(elems);
    }
    while(!g.empty())
    {
        g.pop_back();
    }
}

void 
stackS(size_t numElems)
{
    stack<int> s;
    for(; numElems>0 ; numElems--)
    {
        s.push(numElems);
    }
    while(!s.empty())
    {
        s.pop();
    }

}