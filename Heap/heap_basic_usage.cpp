#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

// Custom comparator for min-heap based on the distance from origin
struct Compare {
    bool operator()(const Point& p1, const Point& p2) {
        return (p1.x * p1.x + p1.y * p1.y) > (p2.x * p2.x + p2.y * p2.y);
    }
};

int main() {
    // Define a priority queue as a max-heap
    priority_queue<int> maxHeap;
    maxHeap.push(10);
    maxHeap.push(5);

    // Define a priority queue as a min-heap for int
    priority_queue<int, vector<int>, greater<int>> minHeapInts;  // mention all three parameters becuase we change one of the default ones (smaller<int> to greater<int>)

    // Insert elements into the min-heap
    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(15);
    minHeap.push(3);

    // Print the minimum element
    cout << "The minimum element is: " << minHeap.top() << endl;

    // Remove the minimum element
    minHeap.pop();

    // Print the new minimum element
    cout << "After popping, the new minimum element is: " << minHeap.top() << endl;

    // Insert another element
    minHeap.push(1);


    // Define a priority queue as a min-heap for custom class
    priority_queue<Point, vector<Point>, Compare> minHeap;

    minHeap.push(Point(3, 4)); // distance = 5
    minHeap.push(Point(1, 1)); // distance = sqrt(2)
    minHeap.push(Point(0, 2)); // distance = 2

    cout << "Points ordered by distance from origin: " << endl;
    while (!minHeap.empty()) {
        Point p = minHeap.top();
        minHeap.pop();
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }

    return 0;
}
