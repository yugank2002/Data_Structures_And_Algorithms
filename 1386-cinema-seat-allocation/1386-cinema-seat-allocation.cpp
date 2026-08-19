class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int,set<int>>seat;
        for(auto elem:reservedSeats){
            int row = elem[0];
            int seatNo = elem[1];

            if(seatNo == 2 || seatNo == 3){
                seat[row].insert(1);
            }
            else if(seatNo == 4 || seatNo == 5){
                seat[row].insert(1);
                seat[row].insert(2);
            }
            else if(seatNo == 6 || seatNo == 7){
                seat[row].insert(2);
                seat[row].insert(3);
            }
            else if(seatNo == 8 || seatNo == 9){
                seat[row].insert(3);
                
            }

        }

        int count = 0;
        for(auto it:seat){
            if(it.second.size()==3){
                continue;
            }
            else{
                count++;
            }
        }

        count+= (n-seat.size())*2;

        return count;
    }
};