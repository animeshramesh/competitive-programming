// Imagine a robot sitting on the upper left corner of grid with r rows and c columns. 
// The robot can only move in two directions, right and down, but certain cells are "off limits" such that the robot cannot step on them. 
//Design an algorithm to find a path for the robot from the top left to the bottom right.

findPath(char maze[][], int r, int c)
{
	bool failed[r][c];
	memset(failed, false);


	findPathDP(maze, r, c, failed);
}


bool findPathDP(maze, r, c, failed)
{
	if (r<0 || c<0 || maze[r][c-1] == 'X' || maze[r-1][c] == 'X' || failed[r][c]) return false;


	if ((r==0 && c==0) || findPath(maze, r, c-1, failed) || findPath(maze, r-1, c, failed)
	{	cout << r << " " << c;
		return true;
	}

	return false;
}
	



