class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
       int left1_x = rec1[0];
       int left1_y = rec1[1];
       int right1_x = rec1[2];
       int right1_y = rec1[3]; 

       int left2_x = rec2[0];
       int left2_y = rec2[1];
       int right2_x = rec2[2];
       int right2_y = rec2[3]; 

       if(left2_x >= right1_x) return false;
       if(left1_x >= right2_x) return false;
       if(left2_y >= right1_y) return false;
       if(left1_y >= right2_y) return false;

       return true;
    }
};