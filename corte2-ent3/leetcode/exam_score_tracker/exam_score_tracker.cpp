#include <vector>
#include <algorithm>

class ExamTracker {
private:
    std::vector<int> times;
    std::vector<long long> prefix_sums;

public:
    ExamTracker() {
        
    }
    
    void record(int time, int score) {
        times.push_back(time);

        long long current_sum = score;

        if (!prefix_sums.empty()) {
            current_sum += prefix_sums.back();
        }

        prefix_sums.push_back(current_sum);
    }
    
    long long totalScore(int startTime, int endTime) {
        if (times.empty()) {
            return 0;
        }
        
        auto left_it = std::lower_bound(
            times.begin(),
            times.end(),
            startTime
        );

        auto right_it = std::upper_bound(
            times.begin(),
            times.end(),
            endTime
        );
        
        if (left_it >= right_it) {
            return 0;
        }
        
        int l_idx = std::distance(times.begin(), left_it);
        int r_idx = std::distance(times.begin(), right_it) - 1;
        
        long long sum_right = prefix_sums[r_idx];
        long long sum_left = (l_idx == 0) ? 0 : prefix_sums[l_idx - 1];
        
        return sum_right - sum_left;
    }
};
