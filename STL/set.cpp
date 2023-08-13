








#include <iostream>
#include <set>
#include <unordered_set>

int main() {
    std::set<int> set;
    set.insert(1);
    set.insert(2);
    set.insert(3);
    std::cout << "Set: ";
    for (int i : set) {
        std::cout << i << " ";
    }
    std::cout << std::endl; // Output: Set: 1 2 3
    set.erase(2);
    std::cout << "Set: ";
    for (int i : set) {
        std::cout << i << " ";
    }
    std::cout << std::endl; // Output: Set: 1 3
    std::cout << "Contains 3: " << (set.count(3) > 0) << std::endl; // Output: Contains 3: 1
    std::cout << "Size: " << set.size() << std::endl; // Output: Size: 2

    std::unordered_set<int> unorderedSet;
    unorderedSet.insert(1);
    unorderedSet.insert(2);
    unorderedSet.insert(3);
    std::cout << "Unordered Set: ";
    for (int i : unorderedSet) {
        std::cout << i << " ";
    }
    std::cout << std::endl; // Output: Unordered Set: 1 2 3
    unorderedSet.erase(2);
    std::cout << "Unordered Set: ";
    for (int i : unorderedSet) {
        std::cout << i << " ";
    }
    std::cout << std::endl; // Output: Unordered Set: 1 3
    std::cout << "Contains 3: " << (unorderedSet.count(3) > 0) << std::endl; // Output: Contains 3: 1
    std::cout << "Size: " << unorderedSet.size() << std::endl; // Output: Size: 2

    return 0;
}



















// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     set<int> s;
//     s.insert(1);
//     s.insert(2);
//     s.insert(6);
//     s.insert(3);
//     s.insert(9);
//     s.insert(7);
//     s.insert(4);
//     s.insert(4);
//     s.insert(5);

//     set<int>::iterator it;
//     for(it=s.begin();it!=s.end();it++)
//     {
//         cout<<*it<<" ";
//     }
//     cout<<endl;
//     // for(auto it=vec.rbegin();it!=vec.rend();it++)
//     // {
//     //     cout<<*it<<" ";
//     // }
    
//     int el = 32;
//     auto ite= s.find(el);
//     if(ite!= s.end())
//     {
//         cout<<"found "<<endl;
//     }
//     else{
//         cout<<"not found"<<endl;
//     }
//     return 0;
// }