#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cfloat>  // for DBL_MAX

using namespace std;

vector< pair<int, int> > people;
vector<int> lights;

// Function to calculate the Euclidean distance between two points
long double distance(int x1, int y1, int x2, int y2) {
    // Calculate squared differences
    long double dx = x1 - x2;
    long double dy = y1 - y2;
    
    // Check if the squared differences are too large or invalid
    if (fabs(dx) > DBL_MAX || fabs(dy) > DBL_MAX) {
        return -1;  // Return -1 if the values are too large (indicating invalid calculation)
    }

    return sqrtl(dx * dx + dy * dy);
}

int main() {
    int n, k;
    cin >> n >> k;

    // Input the light positions (convert 1-based index to 0-based)
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        lights.push_back(x - 1);  // Convert to 0-based index
    }

    // Input the people's positions
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        people.push_back(make_pair(x, y));
    }

    long double max_d = 0;  // Variable to track the maximum of the minimum distances

    // Loop through each person and find the minimum distance to any light
    for (size_t i = 0; i < people.size(); i++) {
        long double min_d = DBL_MAX;  // Initialize with the largest possible value

        // Loop through each light and calculate the distance to the person
        for (size_t j = 0; j < lights.size(); j++) {
            // Get the coordinates of the light
            int light_x = people[lights[j]].first;
            int light_y = people[lights[j]].second;

            // Calculate the distance to the person
            long double dist = distance(light_x, light_y, people[i].first, people[i].second);

            // Update min_d to the smallest distance to any light
            min_d = min(min_d, dist);
        }

        // Track the maximum of the minimum distances
        max_d = max(max_d, min_d);
    }

    // Print the result with fixed precision (e.g., 12 digits)
    cout << fixed << setprecision(12);
    cout << max_d << endl;

    return 0;
}