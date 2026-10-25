// Task Manager - intermediate C++ example
// Features: add / list / complete / delete tasks, input validation, saves to file
// Compile: g++ -std=c++17 -Wall -o task_manager task_manager.cpp

#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

struct Task {
    int id;
    std::string title;
    int priority;   // 1 = high, 2 = medium, 3 = low
    bool done;
};

class TaskManager {
public:
    explicit TaskManager(std::string file) : filename_(std::move(file)) { load(); }

    void add(const std::string& title, int priority) {
        tasks_.push_back({nextId_++, title, priority, false});
        save();
    }

    void list() const {
        if (tasks_.empty()) {
            std::cout << "No tasks yet.\n";
            return;
        }
        std::vector<Task> sorted = tasks_;
        std::sort(sorted.begin(), sorted.end(), [](const Task& a, const Task& b) {
            if (a.done != b.done) return !a.done;          // pending first
            if (a.priority != b.priority) return a.priority < b.priority;
            return a.id < b.id;
        });
        const char* labels[] = {"", "High", "Medium", "Low"};
        std::cout << "\nID  Status  Priority  Title\n";
        std::cout << "--------------------------------------\n";
        for (const auto& t : sorted) {
            std::cout << t.id << "   " << (t.done ? "[x]" : "[ ]") << "     "
                      << labels[t.priority] << "      " << t.title << "\n";
        }
    }

    bool complete(int id) {
        auto it = find(id);
        if (it == tasks_.end()) return false;
        it->done = true;
        save();
        return true;
    }

    bool remove(int id) {
        auto it = find(id);
        if (it == tasks_.end()) return false;
        tasks_.erase(it);
        save();
        return true;
    }

private:
    std::vector<Task> tasks_;
    std::string filename_;
    int nextId_ = 1;

    std::vector<Task>::iterator find(int id) {
        return std::find_if(tasks_.begin(), tasks_.end(),
                            [id](const Task& t) { return t.id == id; });
    }

    // File format: id|priority|done|title
    void save() const {
        std::ofstream out(filename_);
        if (!out) {
            std::cerr << "Warning: could not save to " << filename_ << "\n";
            return;
        }
        for (const auto& t : tasks_)
            out << t.id << '|' << t.priority << '|' << t.done << '|' << t.title << '\n';
    }

    void load() {
        std::ifstream in(filename_);
        if (!in) return; // first run: no file yet
        std::string line;
        while (std::getline(in, line)) {
            std::istringstream ss(line);
            std::string idStr, priStr, doneStr, title;
            if (!std::getline(ss, idStr, '|') || !std::getline(ss, priStr, '|') ||
                !std::getline(ss, doneStr, '|') || !std::getline(ss, title))
                continue; // skip corrupted lines
            try {
                Task t{std::stoi(idStr), title, std::stoi(priStr), doneStr == "1"};
                tasks_.push_back(t);
                nextId_ = std::max(nextId_, t.id + 1);
            } catch (const std::exception&) {
                continue;
            }
        }
    }
};

// ---------- input helpers with validation ----------

int readInt(const std::string& prompt, int lo, int hi) {
    while (true) {
        std::cout << prompt;
        int value;
        if (std::cin >> value && value >= lo && value <= hi) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        if (std::cin.eof()) std::exit(0);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Enter a number from " << lo << " to " << hi << ".\n";
    }
}

std::string readTitle(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        std::string s;
        if (!std::getline(std::cin, s)) std::exit(0);
        // trim whitespace
        s.erase(0, s.find_first_not_of(" \t"));
        s.erase(s.find_last_not_of(" \t") + 1);
        if (s.empty()) {
            std::cout << "Title cannot be empty.\n";
        } else if (s.find('|') != std::string::npos) {
            std::cout << "Title cannot contain '|'.\n";
        } else if (s.size() > 80) {
            std::cout << "Title too long (max 80 characters).\n";
        } else {
            return s;
        }
    }
}

int main() {
    TaskManager manager("tasks.txt");

    while (true) {
        std::cout << "\n=== Task Manager ===\n"
                  << "1. Add task\n"
                  << "2. List tasks\n"
                  << "3. Mark task complete\n"
                  << "4. Delete task\n"
                  << "5. Exit\n";
        int choice = readInt("Choose (1-5): ", 1, 5);

        switch (choice) {
            case 1: {
                std::string title = readTitle("Title: ");
                int pri = readInt("Priority (1=High, 2=Medium, 3=Low): ", 1, 3);
                manager.add(title, pri);
                std::cout << "Task added.\n";
                break;
            }
            case 2:
                manager.list();
                break;
            case 3: {
                int id = readInt("Task ID to complete: ", 1, 1000000);
                std::cout << (manager.complete(id) ? "Marked complete.\n" : "No task with that ID.\n");
                break;
            }
            case 4: {
                int id = readInt("Task ID to delete: ", 1, 1000000);
                std::cout << (manager.remove(id) ? "Deleted.\n" : "No task with that ID.\n");
                break;
            }
            case 5:
                std::cout << "Goodbye!\n";
                return 0;
        }
    }
}