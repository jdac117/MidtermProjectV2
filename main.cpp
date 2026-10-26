#include "workout.h"

void showMenu() {
    std::cout << "\n========================================\n";
    std::cout << "      GYM WORKOUT & PR TRACKER          \n";
    std::cout << "========================================\n";
    std::cout << " 1. Add / Update Exercise PR \n";
    std::cout << " 2. View All Exercise PRs\n";
    std::cout << " 3. View Weekly Workout Log \n";
    std::cout << " 4. Check Heavy Lifts \n";
    std::cout << " 5. Sort Weekly Log \n";
    std::cout << " 6. Exit\n";
    std::cout << "========================================\n";
    std::cout << "Enter your choice (1-6): ";
}

int main() {
    WorkoutTracker tracker;
    int choice = 0;

    std::cout << "Welcome to your Gym Workout & PR Tracker!\n";

    do {
        showMenu();
        if (!(std::cin >> choice)) {
            std::cout << "\n[Error] Invalid input. Please enter a number 1-6.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                std::string name;
                int wt;
                std::cout << "Enter exercise name (e.g., Overhead Press): ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter PR weight (lbs): ";
                if (std::cin >> wt) {
                    tracker.addPR(name, wt);
                    tracker.logWorkout(name);
                } else {
                    std::cout << "[Error] Invalid weight.\n";
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 2:
                tracker.displayPRMap();
                break;
            case 3:
                tracker.displayVectorLog();
                break;
            case 4:
                tracker.checkHeavyLifts();
                break;
            case 5:
                tracker.sortWeeklyLog();
                break;
            case 6:
                std::cout << "\nExiting... Keep grinding!\n";
                break;
            default:
                std::cout << "\n[Error] Choose an option from 1 to 6.\n";
        }
    } while (choice != 6);

    return 0;
}
