#include "workout.h"

WorkoutTracker::WorkoutTracker() {
    
    exercisePRs["Bench Press"] = 185;
    exercisePRs["Squat"] = 225;
    exercisePRs["Deadlift"] = 275;

    weeklyLog.push_back("Bench Press");
    weeklyLog.push_back("Squat");
}

void WorkoutTracker::addPR(const std::string& exercise, int weight) {
    if (exercise.empty() || weight <= 0) {
        std::cout << "[Error] Invalid exercise name or weight!\n";
        return;
    }
    exercisePRs[exercise] = weight;
    std::cout << "[Success] Updated PR for " << exercise << " to " << weight << " lbs.\n";
}

void WorkoutTracker::logWorkout(const std::string& exercise) {
    if (!exercise.empty()) {
        weeklyLog.push_back(exercise);
    }
}

void WorkoutTracker::checkHeavyLifts() const {
    if (exercisePRs.empty()) {
        std::cout << "\nNo PRs recorded yet.\n";
        return;
    }

    int threshold = 200;
    std::cout << "\n--- Heavy Lifts Check (PR >= " << threshold << " lbs) ---\n";

    int heavyCount = std::count_if(exercisePRs.begin(), exercisePRs.end(), [threshold](const auto& pair) {
        return pair.second >= threshold;
    });

    std::cout << "You have " << heavyCount << " lift(s) meeting or exceeding " << threshold << " lbs!\n";
    
    for (const auto& pair : exercisePRs) {
        if (pair.second >= threshold) {
            std::cout << " * " << pair.first << " (" << pair.second << " lbs)\n";
        }
    }
    std::cout << "----------------------------------------------------\n";
}

void WorkoutTracker::sortWeeklyLog() {
    if (weeklyLog.empty()) {
        std::cout << "\nWeekly log is empty.\n";
        return;
    }
    std::sort(weeklyLog.begin(), weeklyLog.end());
    std::cout << "\n[Success] Weekly workout log sorted alphabetically!\n";
}

void WorkoutTracker::displayPRMap() const {
    displayContainer(exercisePRs);
}

void WorkoutTracker::displayVectorLog() const {
    displayContainer(weeklyLog);
}
