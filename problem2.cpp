#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Apple {
    int weight;
    bool allocated;
};

void distributeApples(const vector<Apple>& apples, int ramShare, int shamShare, int rahimShare) {
    vector<Apple> ramApples, shamApples, rahimApples;
    int totalWeight = 0;

    // Calculate total weight of apples
    for (const auto& apple : apples) {
        totalWeight += apple.weight;
    }

    // Calculate the target weights for each person
    int ramTarget = (ramShare * totalWeight) / 100;
    int shamTarget = (shamShare * totalWeight) / 100;
    int rahimTarget = (rahimShare * totalWeight) / 100;

    // Distribute apples
    for (const auto& apple : apples) {
        if (!apple.allocated) {
            if (ramTarget > 0 && ramTarget >= apple.weight) {
                ramApples.push_back(apple);
                ramTarget -= apple.weight;
            } else if (shamTarget > 0 && shamTarget >= apple.weight) {
                shamApples.push_back(apple);
                shamTarget -= apple.weight;
            } else if (rahimTarget > 0 && rahimTarget >= apple.weight) {
                rahimApples.push_back(apple);
                rahimTarget -= apple.weight;
            }
        }
    }

    // Output the distribution
    cout << "Distribution Result:\n";
    cout << "Ram: ";
    for (const auto& apple : ramApples) {
        cout << apple.weight << " ";
    }
    cout << "\nSham: ";
    for (const auto& apple : shamApples) {
        cout << apple.weight << " ";
    }
    cout << "\nRahim: ";
    for (const auto& apple : rahimApples) {
        cout << apple.weight << " ";
    }
    cout << endl;
}

int main() {
    vector<Apple> apples;
    int weight;

    // Input apple weights
    cout << "Enter apple weight in gram (-1 to stop): ";
    while (true) {
        cin >> weight;
        if (weight == -1) break;
        apples.push_back({weight, false});
    }

    // Shares paid by Ram, Sham, and Rahim
    int ramShare = 50;
    int shamShare = 30;
    int rahimShare = 20;

    // Distribute apples
    distributeApples(apples, ramShare, shamShare, rahimShare);

    return 0;
}

//https://www.tutorialspoint.com/cplusplus/index.htm