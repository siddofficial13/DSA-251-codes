#include <vector>
#include <algorithm>
#include <climits>
long dist(pair<int, int> p1, pair<int, int> p2) {
   // find distance between points p1 and p2
   long dis = ((long)((long)p1.first - p2.first) * (p1.first - p2.first)) +
              ((long)((long)p1.second - p2.second) * (p1.second - p2.second));
   return dis;
}
long findMinDist(vector<pair<int, int>> pts, int n) {
   // find minimum distance between two points in a set
   long minimum = LONG_MAX;
   for (int i = 0; i < n; ++i) {
       for (int j = i + 1; j < n; ++j) {
           minimum = min(minimum, dist(pts[i], pts[j]));
       }
   }
   return minimum;
}
bool cmp(pair<int, int> a, pair<int, int> b)
{
   return a.second < b.second;
}
long stripClose(vector<pair<int, int>> strip, long d) {
   //Sort the strip array with respect to y coordinates.
   sort(strip.begin(), strip.end(), cmp);
   //Find closest distance of two points in a strip
   long minimum = d;
   for (int i = 0; i < strip.size(); ++i) {
       for (int j = i + 1;j < strip.size(); ++j) {
           long tmp = (long)strip[j].second - strip[i].second;
           tmp *= tmp;
           if (tmp >= minimum)
           {
               break;
           }
           else
           {
               minimum = min(minimum, dist(strip[i], strip[j]));
           }
           
       }
   }
   return minimum;
}
long findClosest(vector<pair<int, int>> xSorted, int n) {
   if (n <= 3) {
       return findMinDist(xSorted, n);
   }
   int mid = n / 2;
   pair<int, int> midPoint = xSorted[mid];
   int leftIndex = 0, rightIndex = 0;
   // x sorted points in the left side
   vector<pair<int, int>> xSortedLeft(mid + 1);
   // x sorted points in the right side
   vector<pair<int, int>> xSortedRight(n - mid - 1);
   for (int i = 0; i < n; i++) {
       if (i < xSortedLeft.size()) {
           xSortedLeft[leftIndex++] = xSorted[i];
       } else {
           xSortedRight[rightIndex++] = xSorted[i];
       }
   }
   // get minimum distance of left and right part.
   long leftDist = findClosest(xSortedLeft, mid + 1);
   long rightDist = findClosest(xSortedRight, n - mid - 1);
   long distance = min(leftDist, rightDist);
   // hold points closer to the vertical line
   vector<pair<int, int>> strip;
   for (int i = 0; i < n; i++) {
       long tmp = abs((long)xSorted[i].first - midPoint.first);
       tmp *= tmp;
       if (tmp < distance) {
           strip.push_back(xSorted[i]);
       }
   }
   // find minimum using distance and closest pair in strip
   return min(distance, stripClose(strip, distance));
}
long closestPair(pair<int,int> *coordinates, int n) {
   // find distance of closest pair in a set of points
   vector<pair<int, int>> xSorted(n);
   for (int i = 0; i < n; i++) {
       xSorted[i] = coordinates[i];
   }
   // Sort coordinates with respect to x values.
   sort(xSorted.begin(), xSorted.end());
   return findClosest(xSorted, n);
}
