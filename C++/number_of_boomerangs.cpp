class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int result = 0;
        
        for(int i = 0; i < points.size(); i++) {
            map<int, int> dis_map;
            for(int j = 0; j < points.size(); j++) {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                dis_map[x * x + y * y] ++;
            }
            for(auto it = dis_map.begin(); it != dis_map.end(); it++)
                result += it->second * (it->second - 1);
        } 
        
        return result;
    }
};
