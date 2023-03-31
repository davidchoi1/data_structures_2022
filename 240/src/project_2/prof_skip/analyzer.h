#include<iostream>
#include<iomanip>

#ifndef ANALYZER
#define ANALYZER

#include"skiplist.h"
#include"skiplist_node.h"

#define PAGE_SIZE 15

struct Analyzer
{
    template<typename T>
    static void printList(const Skiplist<T>& list, bool paginate = false)
    {
        int count{0};
        int pager{0};
        size_t maxHeight{1};

        SkiplistNode<T>* ptr{list.heads[0]};

        while(ptr)
        {
            std::cout << std::setw(9) << std::right <<  (++count) << ") " 
                      << std::setw(9) << std::left << ptr->item << " " 
#ifdef WINDOWS
                      << char(16);
#else
                      << ':';
#endif

            maxHeight = std::max(ptr->height, maxHeight);

            for(size_t i{0}; i < maxHeight; ++i)
#ifdef WINDOWS
                std::cout <<  (i <= ptr->height ? char(196) : char(255)) 
                          <<  (i <= ptr->height ? char(196) : char(255)) 
                          << (i <= ptr->height ? char(254) : char(179));
#else
                std::wcout << (i <= ptr->height ? "--" : "  ") 
                           << (i <= ptr->height ? '0' : '|');
#endif
            std::cout << std::endl;
            ptr = ptr->nexts[0];

            if(paginate && ++pager == PAGE_SIZE)
            {
                std::cout << "Enter for next page";
                std::cin.get();
                std::cout << "\x1b[A";
                pager = 0;                
            }
        }
    }
    
    template<typename T>
    static void printMaxHeight(const Skiplist<T>& list)
    {
        std::cout << "Maximum height = " << list.heads.size() << std::endl;
    }
};

#endif /* ANALYZER */
