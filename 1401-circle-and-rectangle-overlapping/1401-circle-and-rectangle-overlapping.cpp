class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closestXval = max(x1,min(xCenter,x2));
        int closestYval = max(y1,min(yCenter,y2));
        int distX = xCenter - closestXval;
        int distY = yCenter - closestYval;
        return(distX*distX + distY*distY) <= (radius*radius);
    }
};