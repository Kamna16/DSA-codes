





#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> map;
    map["apple"] = 1;
    map["banana"] = 2;
    map["cherry"] = 3;
    std::cout << "Map: ";
    for (const auto& pair : map) {
        std::cout << pair.first << "=" << pair.second << " ";
    }
    std::cout << std::endl; // Output: Map: apple=1 banana=2 cherry=3
    map.erase("banana");
    std::cout << "Map: ";
    for (const auto& pair : map) {
        std::cout << pair.first << "=" << pair.second << " ";
    }
    std::cout << std::endl; // Output: Map: apple=1 cherry=3
    std::cout << "Value of apple: " << map["apple"] << std::endl; // Output: Value of apple: 1
    std::cout << "Size: " << map.size() << std::endl; // Output: Size: 2

    return 0;
}






















// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     map<int,string> m;
//     m[2] = "B";
//     m[1] = "A";
//     m[3] = "C";
//     m[1] = "D"; // value will be overriden

//     map<int,string>::iterator it;
//     for(it=m.begin();it!=m.end();it++)
//     {
//         cout<<"Key: "<<it->first<<" ";
//         cout<<"value: "<<it->second<<endl;
//     }
//     cout<<endl;

//     auto it2 = max_element(m.begin(), m.end());
//     cout<<"max Key: "<<it2->first<<" ";
//     cout<<"value: "<<it2->second<<endl;
    
//     int k=1;
//     cout<<m[k]<<endl;

//     k=2;
//     auto iter = m.find(k);
//     return 0;
// }