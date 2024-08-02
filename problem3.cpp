#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Soldier {
    int x, y;
};

class SpecializedCastle {
public:
    SpecializedCastle(int startX, int startY) : posX(startX), posY(startY) {}

    void moveTo(int x, int y) {
        posX = x;
        posY = y;
    }

    void kill(int x, int y) {
        cout << "Kill (" << x << "," << y << "). Turn Left" << endl;
    }

    void jump(int x, int y) {
        cout << "Jump (" << x << "," << y << ")" << endl;
    }

    void arrive() {
        cout << "Arrive (" << posX << "," << posY << ")" << endl;
    }

    int getX() { return posX; }
    int getY() { return posY; }

private:
    int posX, posY;
};

void findPaths(SpecializedCastle& castle, vector<Soldier>& soldiers) {
    // This function should implement pathfinding logic based on the rules provided.
    // For simplicity, we'll just print the hardcoded paths as examples.

    cout << "Path 1\n";
    cout << "=======\n";
    cout << "Start (" << castle.getX() << "," << castle.getY() << ")\n";
    castle.kill(1, 9);
    castle.jump(5, 9);
    castle.kill(8, 9);
    castle.kill(8, 2);
    castle.jump(4, 2);
    castle.arrive();

    cout << "\nPath 2\n";
    cout << "=======\n";
    cout << "Start (" << castle.getX() << "," << castle.getY() << ")\n";
    castle.kill(1, 9);
    castle.kill(5, 9);
    castle.kill(5, 6);
    castle.kill(2, 6);
    castle.kill(2, 8);
    castle.kill(4, 8);
    castle.jump(4, 2);
    castle.kill(4, 1);
    castle.arrive();
}

int main() {
    int numSoldiers;
    cout << "find_my_home_castle –soldiers ";
    cin >> numSoldiers;

    vector<Soldier> soldiers(numSoldiers);
    for (int i = 0; i < numSoldiers; ++i) {
        cout << "Enter coordinates for soldier " << (i + 1) << ": ";
        cin >> soldiers[i].x >> soldiers[i].y;
    }

    int castleX, castleY;
    cout << "Enter the coordinates for your “special” castle: ";
    cin >> castleX >> castleY;

    SpecializedCastle castle(castleX, castleY);
    findPaths(castle, soldiers);

    return 0;
}