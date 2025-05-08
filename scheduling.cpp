#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    string id;
    int deadline, profit;
};

bool compareJobs(const Job& a, const Job& b) {
    return a.profit > b.profit;
}

int main() {
    // Predefined input
    vector<Job> jobs = {
        {"J1", 4, 50},
        {"J2", 1, 40},
        {"J3", 5, 60},
        {"J4", 3, 20}
    };

    // Sort jobs by profit in descending order
    sort(jobs.begin(), jobs.end(), compareJobs);

    int maxDeadline = 0;
    for (const Job& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    vector<bool> slots(maxDeadline, false);
    int totalProfit = 0;
    vector<string> scheduledJobs;

    for (const Job& job : jobs) {
        // Try to find a slot for the job, starting from the latest available slot
        for (int i = job.deadline - 1; i >= 0; --i) {
            if (!slots[i]) {
                slots[i] = true;
                totalProfit += job.profit;
                scheduledJobs.push_back(job.id);
                break;
            }
        }
    }

    cout << "Total profit earned: " << totalProfit << "\n";
    cout << "Scheduled jobs:\n";
    for (const string& jobId : scheduledJobs) {
        cout << jobId << "\n";
    }

    return 0;
}
