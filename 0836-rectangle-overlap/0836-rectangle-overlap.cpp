#include <vector>

class Solution {
public:
    bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2) {
        if (rec1[0] >= rec1[2] || rec1[1] >= rec1[3] || 
            rec2[0] >= rec2[2] || rec2[1] >= rec2[3]) {
            return false;
        }

        bool xOverlap = (rec1[0] < rec2[2]) && (rec1[2] > rec2[0]);
        bool yOverlap = (rec1[1] < rec2[3]) && (rec1[3] > rec2[1]);

        return xOverlap && yOverlap;
    }
};