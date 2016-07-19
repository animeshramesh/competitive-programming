//A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time. 
//Implement a method to count how many possible ways the child can run up the stairs.

int ref[n];

a[0] = 0;
a[1] = 1; // 1
a[2] = 2; // 1 + 1, 2
a[3] = 4; // 1+1+1, 2+1, 1+2, 3

for (int i = 4; i<n; i++)
	a[i] = a[i-1] + a[i-2] + a[i-3];

// n'th step => a[n-1] + 1 step
//			 => a[n-2] + 2 steps
// 			 => a[n-3] + 3 steps