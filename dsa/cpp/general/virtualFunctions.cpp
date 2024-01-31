#include <iostream>

using namespace std;

// abstract class, 'Player', because it has pure virtual function, 'pass'
class Player {
    public:
        // pure virtual function because it is not implemented, override is NECESSARY
        virtual void pass()=0;
};

class Youth {
    public:
        // virtual function, override is optional
        virtual void shoot() {
            cout << "shoot!" << endl;
        }

        virtual void pass() {
            cout << "pass!" << endl;
        }

        void tackle() {
            cout << "tackle!" << endl;
        }
};

class Striker: public Player, public Youth {
    public:
        void shoot() {
            cout << "shoot short range!" << endl;
        }

        void pass() {
            cout << "optional pass" << endl;
        }
};

class Midfielder : public Player, public Youth {
    public:
        void shoot() {
            cout << "shoot long range!" << endl;
        }

        void pass() {
            cout << "creative pass" << endl;
        }

};

class Defender : public Player, public Youth {
    public:
        void pass() {
            cout << "safe pass" << endl;
        }
};

int main() {
    Youth y;
    Defender d;
    Striker s;
    Midfielder m;

    Defender *player0 = &d;
    Striker *player1 = &s;
    Midfielder *player2 = &m;
    
    Youth &yr = y;

    yr.shoot();

    // Player 1 and 2 have unique shots, but player 0 just shoots
    // player 0 shoots
    player0->shoot();

    // player 1 shoots short range
    player1->shoot();

    // player 2 shoots long range
    player2->shoot();
    cout << endl;

    // Everyone has a preferred pass
    // player 0 plays safe passes
    player0->pass();
    // player 1 plays optional passes
    player1->pass();
    // player 2 plays creative passes
    player2->pass();
    cout << endl;

    // Everyone tackles
    player0->tackle();
    player1->tackle();
    player2->tackle();

    return 0;
}