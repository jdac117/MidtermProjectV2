#ifndef WORKOUT_H
#define WORKOUT_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>

class WorkoutTracker {
private:
    
    std::map<std::string, int> exercisePRs; 
    std::vector<std::string> weeklyLog;      

public:
    WorkoutTracker();

    void addPR(const std::string& exercise, int weight);
    void logWorkout(const std::string& exercise);
    void checkHeavyLifts() const; 
    void sortWeeklyLog();         
    void displayPRMap() const;
    void displayVectorLog() const;

    template <typename Container>
    void displayContainer(const Container& c) const {
        std::cout << "\n----------------------------------------\n";
        std::cout << "          CONTAINER CONTENTS            \n";
        std::cout << "----------------------------------------\n";
        for (const auto& item : c) {
            printItem(item);
        }
        std::cout << "----------------------------------------\n";
    }

    void printItem(const std::pair<std::string, int>& pair) const {
        std::cout << " [Exercise]: " << std::left << std::setw(15) << pair.first 
                  << " [PR]: " << pair.second << " lbs\n";
    }

    void printItem(const std::string& str) const {
        std::cout << " - " << str << "\n";
    }
};

#endif
