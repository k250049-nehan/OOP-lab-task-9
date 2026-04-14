#include <iostream>
using namespace std;

class SmartDevice {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void getStatus() = 0;
};

class LightBulb : public SmartDevice {
private:
    bool isOn;
    int brightness;
public:
    LightBulb(int b = 0) {
        isOn = false;
        brightness = b;
    }

    void turnOn() {
        isOn = true;
    }

    void turnOff() {
        isOn = false;
    }

    void getStatus() {
        cout << "LightBulb is " << (isOn ? "ON" : "OFF") 
             << ", Brightness: " << brightness << "%" << endl;
    }
};

class Thermostat : public SmartDevice {
private:
    bool isOn;
    double temperature;
public:
    Thermostat(double t = 0) {
        isOn = false;
        temperature = t;
    }

    void turnOn() {
        isOn = true;
    }

    void turnOff() {
        isOn = false;
    }

    void getStatus() {
        cout << "Thermostat is " << (isOn ? "ON" : "OFF") 
             << ", Temperature: " << temperature << "°C" << endl;
    }
};

int main() {
    SmartDevice* d1 = new LightBulb(75);
    SmartDevice* d2 = new Thermostat(24.5);

    d1->turnOn();
    d1->getStatus();

    d2->turnOn();
    d2->getStatus();

    d1->turnOff();
    d1->getStatus();

    d2->turnOff();
    d2->getStatus();

    delete d1;
    delete d2;

    return 0;
}
