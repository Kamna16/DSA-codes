#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int weight, value;
};

bool compare(Item a, Item b) {
    return ((double) a.value / a.weight) > ((double) b.value / b.weight);
}

double fractionalKnapsack(std::vector<int>& values, std::vector<int>& weights, int capacity) {
    int n = values.size();
    std::vector<Item> items(n);

    for (int i = 0; i < n; i++) {
        items[i] = {weights[i], values[i]};
    }

    std::sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for (const Item& item : items) {
        if (capacity >= item.weight) {
            totalValue += item.value;
            capacity -= item.weight;
        } else {
            totalValue += ((double) capacity / item.weight) * item.value;
            break;
        }
    }

    return totalValue;
}

int main() {
    std::vector<int> values = {60, 100, 120};
    std::vector<int> weights = {10, 20, 30};
    int capacity = 50;

    double maxValue = fractionalKnapsack(values, weights, capacity);
    std::cout << "Maximum Value: " << maxValue << std::endl;

    return 0;
}
