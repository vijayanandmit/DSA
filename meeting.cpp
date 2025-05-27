#include <iostream>
#include <vector>

using namespace std;

vector<int> findMeetingBuilding(const vector<int>& heights, const vector<vector<int >>& queries) {
    int n = heights.size();
    vector<int> ans;

    for (const auto& query : queries) {
        int aliceBuilding = query[0];
        int bobBuilding = query[1];
        int meetingBuilding = -1;

        for (int i = aliceBuilding; i <= bobBuilding; ++i) {
            if (heights[i] < heights[aliceBuilding] && heights[i] < heights[bobBuilding]) {
                meetingBuilding = i;
                break;
            }
        }

        ans.push_back(meetingBuilding);
    }

    return ans;
}

int main() {
    // Example usage:
    std::vector<int> heights = {5, 3, 8, 2, 6, 1, 4, 6};
    vector<vector<int> > queries = {{0, 7}, {3, 5}, {5, 2}, {3, 0}, {1, 6}};

    vector<int> result = findMeetingBuilding(heights, queries);

    // Print the result
    cout << "Meeting buildings: ";
    for (int meetingBuilding : result) {
        cout << meetingBuilding << " ";
    }

    return 0;
}
