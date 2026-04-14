#include <iostream>
using namespace std;

class Activity {
public:
    virtual double calculateCaloriesBurned() = 0;
};

class Running : public Activity {
private:
    double distance;
    double time;
public:
    Running(double d, double t) {
        distance = d;
        time = t;
    }

    double calculateCaloriesBurned() {
        return distance * 60;
    }
};

class Cycling : public Activity {
private:
    double speed;
    double time;
public:
    Cycling(double s, double t) {
        speed = s;
        time = t;
    }

    double calculateCaloriesBurned() {
        return speed * time * 8;
    }
};

int main() {
    Activity* a1 = new Running(5, 30);
    Activity* a2 = new Cycling(20, 1);

    cout << "Running Calories Burned: " << a1->calculateCaloriesBurned() << endl;
    cout << "Cycling Calories Burned: " << a2->calculateCaloriesBurned() << endl;

    delete a1;
    delete a2;

    return 0;
}
