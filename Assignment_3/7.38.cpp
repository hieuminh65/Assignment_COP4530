#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
};

bool comparePoints(const Point& p1, const Point& p2) {
    if (p1.x == p2.x)
        return p1.y < p2.y;
    return p1.x < p2.x;
}

double computeSlope(const Point& p1, const Point& p2) {
    if (p1.x == p2.x)
        return numeric_limits<double>::infinity();  // Vertical line, slope is infinity
    return static_cast<double>(p2.y - p1.y) / (p2.x - p1.x);
}

bool areCollinear(const Point& p1, const Point& p2, const Point& p3) {
    double slope1 = computeSlope(p1, p2);
    double slope2 = computeSlope(p1, p3);
    return slope1 == slope2;
}

void sortPoints(vector<Point>& points) {
    int point_size = points.size();
    for (int i = 0; i < point_size - 1; i++) {
        for (int j = 0; j < point_size - i - 1; j++) {
            if (!comparePoints(points[j], points[j + 1])) {
                swap(points[j], points[j + 1]);
            }
        }
    }
}

void CollinearPoints(const vector<Point>& points) {
    int size = points.size();
    vector<Point> sortedPoints = points;
    sortPoints(sortedPoints);

    bool foundCollinear = false;
    for (int i = 0; i < size; i++) {
        Point p1 = sortedPoints[i];

        for (int j = i + 1; j < size; j++) {
            Point p2 = sortedPoints[j];

            if (!areCollinear(p1, p2, sortedPoints[j + 1]))
                continue;

            foundCollinear = true;
            cout << "Collinear points: (" << p1.x << ", " << p1.y << "), (" << p2.x << ", " << p2.y << "), ";
            while (j + 1 < size && areCollinear(p1, p2, sortedPoints[j + 1])) {
                j++;
                cout << "(" << sortedPoints[j].x << ", " << sortedPoints[j].y << "), ";
            }
            cout << endl;
        }
    }

    if (!foundCollinear)
        cout << "No collinear points found." << endl;
}

int main(){
    int number;
    cout << "Enter the number of points: ";
    cin >> number;

    vector<Point> points(number);
    cout << "Enter the points (x, y):" << endl;
    for (int i = 0; i < number; i++) {
        cin >> points[i].x >> points[i].y;
    }
    CollinearPoints(points);

    return 0;
    
}
