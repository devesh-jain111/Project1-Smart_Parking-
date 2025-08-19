#include <iostream>
#include <string>

using namespace std;

// Structure to represent a parked car
struct Car {
    string license_plate;
    Car* next;
};

// Class to represent the parking lot
class ParkingLot {
private:
    Car* head;
    int capacity;
    int current_count;

public:
    ParkingLot(int cap) : head(nullptr), capacity(cap), current_count(0) {}

    // Function to park a car
    bool parkCar(const string& license_plate) {
        if (current_count >= capacity) {
            cout << "Parking lot is full! Cannot park the car with license plate: " << license_plate << endl;
            return false; // Failure
        }
        Car* new_car = new Car{license_plate, head};
        head = new_car;
        current_count++;
        cout << "Car with license plate " << license_plate << " parked successfully." << endl;
        return true; // Success
    }

    // Function to remove a car
    bool removeCar(const string& license_plate) {
        Car* current = head;
        Car* previous = nullptr;

        while (current != nullptr) {
            if (current->license_plate == license_plate) {
                if (previous == nullptr) {
                    head = current->next; // Remove head
                } else {
                    previous->next = current->next; // Bypass the current car
                }
                delete current;
                current_count--;
                cout << "Car with license plate " << license_plate << " removed successfully." << endl;
                return true; // Success
            }
            previous = current;
            current = current->next;
        }
        cout << "Car with license plate " << license_plate << " not found!" << endl;
        return false; // Failure
    }

    // Function to display parked cars
    void displayParkedCars() const {
        Car* current = head;
        cout << "Currently parked cars:" << endl;
        while (current != nullptr) {
            cout << "- " << current->license_plate << endl;
            current = current->next;
        }
    }

    // Destructor to free the parking lot
    ~ParkingLot() {
        Car* current = head;
        while (current != nullptr) {
            Car* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the parking lot: ";
    cin >> capacity;

    ParkingLot lot(capacity);
    int choice;
    string license_plate;

    do {
        cout << "\n1. Park Car\n2. Remove Car\n3. Display Parked Cars\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter license plate: ";
                cin >> license_plate;
                lot.parkCar(license_plate);
                break;
            case 2:
                cout << "Enter license plate: ";
                cin >> license_plate;
                lot.removeCar(license_plate);
                break;
            case 3:
                lot.displayParkedCars();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

