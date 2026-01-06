#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: task-cli <command> [arguments]\n";
        return 0;
    }

    string command = argv[1];

    cout << "Command received: " << command << endl;

    return 0;
}
