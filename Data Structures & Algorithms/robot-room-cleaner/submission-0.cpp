class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    set<pair<int, int>> visited;

    void goBack(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }

    void backtrack(Robot& robot, int row, int col, int d) {
        visited.insert({row, col});
        robot.clean();
        // going clockwise : 0: 'up', 1: 'right', 2: 'down', 3: 'left'
        for (int i = 0; i < 4; i++) {
            int newD = (d + i) % 4;
            int newRow = row + directions[newD][0];
            int newCol = col + directions[newD][1];

            if (visited.find({newRow, newCol}) == visited.end() && robot.move()) {
                backtrack(robot, newRow, newCol, newD);
                goBack(robot);
            }
            robot.turnRight();
        }
    }

    void cleanRoom(Robot& robot) {
        backtrack(robot, 0, 0, 0);
    }
};
