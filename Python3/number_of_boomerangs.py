class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        result = 0
        
        for a in points:
            dis_map = {}
            for b in points:
                x = a[0] - b[0] 
                y = a[1] - b[1]
                if (x * x + y * y) not in dis_map: dis_map[x * x + y * y] = 1
                else: dis_map[x * x + y * y] += 1
            for i, index in enumerate(dis_map):
                result += dis_map[index] * (dis_map[index] - 1)
            
        return result
